function Invoke-DTRLaunch {
    param(
        [string]$Root,
        [string]$Game,
        [string]$Exe,
        [string[]]$Arguments,
        [ValidateSet('server','client','offline')][string]$Role,
        [int]$Port,
        [switch]$CheckOnly,
        [switch]$PassThru,
        [switch]$HiddenWindow,
        [string]$WorkingDirectory
    )
    $ErrorActionPreference='Stop'
    $Root=(Resolve-Path -LiteralPath $Root).Path
    $runtime=Join-Path $Root 'runtime'
    $launchLogs=Join-Path $runtime 'launch-logs'
    New-Item -ItemType Directory -Force -Path $launchLogs | Out-Null
    $stamp=Get-Date -Format 'yyyyMMdd-HHmmss-fff'
    $log=Join-Path $launchLogs ("{0}-{1}.log" -f $Role,$stamp)
    $transcribing=$false
    try {
        Start-Transcript -LiteralPath $log -Force | Out-Null
        $transcribing=$true
        if ($Role -ne 'server' -and -not $CheckOnly -and -not (Get-Process -Name steam -ErrorAction SilentlyContinue)) {
            throw 'Steam is not running.'
        }
        Write-Host "DayZ Test Range: $Role"
        Write-Host "PowerShell: $($PSVersionTable.PSVersion)"
        $currentIdentity=[Security.Principal.WindowsIdentity]::GetCurrent()
        $launcherElevated=([Security.Principal.WindowsPrincipal]$currentIdentity).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
        $currentIdentity.Dispose()
        Write-Host "Launcher context: PID $PID; 64-bit=$([Environment]::Is64BitProcess); elevated=$launcherElevated"
        Write-Host "Project: $Root"
        Write-Host "Launcher log: $log"
        foreach ($required in @(
            $Exe,
            (Join-Path $Root 'dist\@DayZTestRange\addons\dtr_test_range_world.pbo'),
            (Join-Path $Root 'dist\@DayZTestRange\addons\dtr_test_range_data.pbo'),
            (Join-Path $Root 'dist\@DayZTestRange\addons\dtr_test_range_ce.pbo'),
            (Join-Path $Root 'server\config\serverDZ.cfg'),
            (Join-Path $Root 'server\mpmissions\empty.dayztestrange\init.c')
        )) {
            if (-not (Test-Path -LiteralPath $required -PathType Leaf)) {
                throw "Required file missing: $required"
            }
        }
        if (-not (Test-Path -LiteralPath $Game -PathType Container)) {
            throw "Game folder missing: $Game"
        }
        if (-not $WorkingDirectory) { $WorkingDirectory=$Game }
        if (-not (Test-Path -LiteralPath $WorkingDirectory -PathType Container)) {throw "Working directory missing: $WorkingDirectory"}
        $profiles=Join-Path $runtime "$Role-profiles"
        $storage=Join-Path $runtime 'storage'
        New-Item -ItemType Directory -Force -Path $profiles,$storage | Out-Null
        Write-Host "Executable: $Exe"
        Write-Host "Working directory: $WorkingDirectory"
        Write-Host "Arguments: $($Arguments -join ' ')"
        Write-Host "Game logs: $profiles"
        if ($CheckOnly) {
            Write-Host 'Preflight OK. CheckOnly: game process was not started.'
            return
        }
        $pidFile=Join-Path $runtime "$Role.pid"
        # A previous launch may have failed before recording its actual process,
        # or the user may have started the client manually. Inspect real roles.
        $liveGames = @(Get-CimInstance Win32_Process -Filter "Name='DayZDiag_x64.exe' OR Name='DayZ_x64.exe' OR Name='DayZServer_x64.exe'" | Where-Object {
            $_.ExecutablePath -and ([IO.Path]::GetDirectoryName($_.ExecutablePath) -ieq $Game.TrimEnd('\'))
        })
        if ($Role -ne 'server') {
            $clients = @($liveGames | Where-Object {
                $_.Name -ine 'DayZServer_x64.exe' -and $_.CommandLine -notmatch '(?i)(?:^|\s)-server(?:\s|$)'
            })
            if ($clients.Count) { throw "A DayZ client is already running (PID $(($clients.ProcessId) -join ', ')). Close it before starting another client. The server is separate." }
        } else {
            $sameProjectServers=@($liveGames | Where-Object {
                ($_.Name -ieq 'DayZServer_x64.exe' -or $_.CommandLine -match '(?i)(?:^|\s)-server(?:\s|$)') -and
                $_.CommandLine.ToLowerInvariant().Contains($profiles.ToLowerInvariant())
            })
            if ($sameProjectServers.Count) { throw "This project server is already running (PID $(($sameProjectServers.ProcessId) -join ', ')). Use Stop-Test-Server.cmd before restarting it." }
            $listeners=[System.Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties().GetActiveUdpListeners()
            if (@($listeners | Where-Object Port -eq $Port).Count) { throw "UDP port $Port is already occupied. Stop the existing server before starting another one." }
            [IO.File]::WriteAllText((Join-Path $profiles 'dtr-server-command.txt'), '', [Text.Encoding]::ASCII)
        }
        $start=New-Object System.Diagnostics.ProcessStartInfo
        $start.FileName=$Exe
        $start.Arguments=$Arguments -join ' '
        $start.WorkingDirectory=$WorkingDirectory
        $start.UseShellExecute=$false
        # Pass a concrete child environment; do not change and restore the
        # launcher's environment around an operating-system shell launch.
        if ($Role -ne 'server') {
            $start.EnvironmentVariables['SteamAppId']='221100'
            $start.EnvironmentVariables['SteamGameId']='221100'
        }
        $start.WindowStyle=if ($HiddenWindow) {[Diagnostics.ProcessWindowStyle]::Hidden} else {[Diagnostics.ProcessWindowStyle]::Normal}
        $gameProcess=[Diagnostics.Process]::Start($start)
        # Acquire the handle before early exit so PS 5.1 can read ExitCode.
        $processHandle=$gameProcess.Handle
        $gameProcess.Id | Set-Content -LiteralPath $pidFile
        $record=[ordered]@{
            startedAt=($gameProcess.StartTime.ToString('o'))
            executable=$Exe
            workingDirectory=$WorkingDirectory
            arguments=$Arguments
            processId=$gameProcess.Id
            launcherLog=$log
            profiles=$profiles
            status='process-created'
            windowMode=$(if($HiddenWindow){'hidden'}else{'native'})
            launchMethod='direct-process'
            launcherProcessId=$PID
            launcherIs64Bit=[Environment]::Is64BitProcess
            launcherElevated=$launcherElevated
        }
        $statusFile=Join-Path $runtime "$Role-launch.json"
        $record | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath $statusFile -Encoding UTF8
        Write-Host "Process created: PID $($gameProcess.Id). Waiting for startup..."
        $waitSeconds=if ($Role -in @('server','offline')) {60} else {10}
        $startupDeadline=(Get-Date).AddSeconds($waitSeconds)
        $record.status='running-unverified'
        do {
            Start-Sleep -Milliseconds 500
            $gameProcess.Refresh()
            if ($gameProcess.HasExited) {
                $record.status='exited'
                $record.exitCode=$gameProcess.ExitCode
                $record | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath $statusFile -Encoding UTF8
                throw "DayZ exited during startup (exit code $($gameProcess.ExitCode), PID $($gameProcess.Id)). See $profiles and $launchLogs."
            }
            if ($Role -eq 'server') {
                $endpoints=@(Get-NetUDPEndpoint -LocalPort $Port -ErrorAction SilentlyContinue | Where-Object OwningProcess -eq $gameProcess.Id)
                if ($endpoints.Count) {
                    $record.status='running-udp-port-present'
                    Write-Host "READY: this server (PID $($gameProcess.Id)) owns UDP port $Port." -ForegroundColor Green
                    break
                }
            } elseif ($Role -eq 'offline') {
                # An engine error dialog also has a window handle. Only a fresh
                # mission log confirms that the offline world actually loaded.
                $missionLogs=@(Get-ChildItem -LiteralPath $profiles -Filter 'script_*.log' -File -ErrorAction SilentlyContinue | Where-Object {
                    $_.CreationTime -ge $gameProcess.StartTime.AddSeconds(-1)
                })
                $loadedLogs=@($missionLogs | Where-Object {
                    Select-String -LiteralPath $_.FullName -SimpleMatch '[DTR OFFLINE] World loaded; size=1024' -Quiet
                })
                if ($loadedLogs.Count) {
                    $record.status='running-world-loaded'
                    Write-Host 'READY: offline world loaded.' -ForegroundColor Green
                    break
                }
            } elseif ($gameProcess.MainWindowHandle -ne [IntPtr]::Zero) {
                $record.status='running-window-present'
                Write-Host 'Client window is present. Wait for connection and world loading.'
                break
            }
        } while ((Get-Date) -lt $startupDeadline)
        if ($record.status -eq 'running-unverified') {
            Write-Warning "PID $($gameProcess.Id) is alive, but startup readiness is not yet confirmed. Inspect $profiles; do not start a duplicate."
        }
        $record | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath $statusFile -Encoding UTF8
        if ($Role -eq 'offline') { Write-Host 'Offline mission: no separate server process or connection is used.' }
        else { Write-Host 'Local connection password: dtr-local' }
        if ($PassThru) { return $gameProcess }
    } catch {
        $detailLog=[IO.Path]::ChangeExtension($log,'error.txt')
        ($_ | Format-List * -Force | Out-String) | Set-Content -LiteralPath $detailLog -Encoding UTF8
        throw
    } finally {
        if ($transcribing) { Stop-Transcript | Out-Null }
    }
}
