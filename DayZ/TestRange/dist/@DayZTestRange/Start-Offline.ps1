param([string]$Game='', [string]$ExtraMods='', [string]$ModRoot='', [switch]$Retail, [switch]$Diag, [switch]$CheckOnly)
$ErrorActionPreference='Stop'
try {
    if($Diag -and $Retail){throw 'Choose either -Diag or -Retail, not both.'}
    if(-not $ModRoot){$ModRoot=Split-Path -Parent $MyInvocation.MyCommand.Path}
    $ModRoot=[IO.Path]::GetFullPath($ModRoot)
    foreach($name in @('world','data','ce')){
        if(-not(Test-Path -LiteralPath (Join-Path $ModRoot "addons\dtr_test_range_$name.pbo") -PathType Leaf)){throw "Required terrain PBO missing: $name"}
    }
    $mission=Join-Path $ModRoot 'Missions\offline.dayztestrange'
    if(-not(Test-Path -LiteralPath (Join-Path $mission 'init.c'))){throw 'Offline mission is missing from this mod package.'}
    if(-not $Game){
        $candidates=New-Object 'System.Collections.Generic.List[string]'
        $parent=[IO.DirectoryInfo]$ModRoot
        while($parent){
            if($parent.Name -ieq 'steamapps'){$candidates.Add((Join-Path $parent.FullName 'common\DayZ'))}
            $parent=$parent.Parent
        }
        $steamRoots=New-Object 'System.Collections.Generic.List[string]'
        $steam=Get-ItemProperty -LiteralPath 'HKCU:\Software\Valve\Steam' -ErrorAction SilentlyContinue
        if($steam.SteamPath){$steamRoots.Add($steam.SteamPath)}
        foreach($runningSteam in @(Get-Process -Name steam -ErrorAction SilentlyContinue)){
            if($runningSteam.Path){$steamRoots.Add((Split-Path -Parent $runningSteam.Path))}
        }
        if(${env:ProgramFiles(x86)}){$steamRoots.Add((Join-Path ${env:ProgramFiles(x86)} 'Steam'))}
        foreach($steamRoot in @($steamRoots | Select-Object -Unique)){
            $candidates.Add((Join-Path $steamRoot 'steamapps\common\DayZ'))
            foreach($relative in @('steamapps\libraryfolders.vdf','config\libraryfolders.vdf')){
                $libraries=Join-Path $steamRoot $relative
                if(Test-Path -LiteralPath $libraries){
                    foreach($line in Get-Content -LiteralPath $libraries){
                        if($line -match '^\s*"path"\s+"([^"]+)"'){$library=$Matches[1].Replace('\\','\');$candidates.Add((Join-Path $library 'steamapps\common\DayZ'))}
                    }
                }
            }
        }
        $Game=$candidates | Select-Object -Unique | Where-Object {Test-Path -LiteralPath (Join-Path $_ 'DayZ_x64.exe')} | Select-Object -First 1
    }
    if(-not $Game -or -not(Test-Path -LiteralPath $Game -PathType Container)){throw 'DayZ installation was not found. Run Start-Offline.cmd -Game "full path to DayZ".'}
    $Game=(Resolve-Path -LiteralPath $Game).Path
    $exe=Join-Path $Game $(if($Retail){'DayZ_x64.exe'}else{'DayZDiag_x64.exe'})
    if(-not(Test-Path -LiteralPath $exe -PathType Leaf)){throw "Client executable missing: $exe. Use -Retail for the ordinary client."}
    $mods=$ModRoot
    if($ExtraMods){
        foreach($entry in $ExtraMods.Split(';')){if(-not[IO.Path]::IsPathRooted($entry) -or -not(Test-Path -LiteralPath $entry -PathType Container)){throw "ExtraMods requires existing absolute paths: $entry"}}
        $mods+=';'+$ExtraMods
    }
    Write-Host 'DayZ Test Range - standalone offline mission'
    Write-Host "Client: $exe"
    Write-Host "Mod: $ModRoot"
    if($CheckOnly){Write-Host 'Preflight OK. No application was started.';exit 0}
    if(-not(Get-Process -Name steam -ErrorAction SilentlyContinue)){throw 'Steam is not running.'}
    $clients=@(Get-CimInstance Win32_Process -Filter "Name='DayZDiag_x64.exe' OR Name='DayZ_x64.exe'" | Where-Object {$_.CommandLine -notmatch '(?i)(?:^|\s)-server(?:\s|$)'})
    if($clients.Count){throw "A DayZ client is already running (PID $(($clients.ProcessId)-join ', ')). Close it before starting another client."}
    $runtime=Join-Path ([Environment]::GetFolderPath('LocalApplicationData')) 'DayZTestRange'
    $profiles=Join-Path $runtime 'offline-profiles'
    $storage=Join-Path $runtime 'offline-storage'
    New-Item -ItemType Directory -Force -Path $profiles,$storage | Out-Null
    $launcherLog=Join-Path $runtime 'last-launch.txt'
    Set-Content -LiteralPath $launcherLog -Value ('Starting: '+(Get-Date).ToString('o')) -Encoding UTF8
    $start=New-Object Diagnostics.ProcessStartInfo
    $start.FileName=$exe
    $start.UseShellExecute=$false
    $start.WorkingDirectory=$Game
    $start.EnvironmentVariables['SteamAppId']='221100'
    $start.EnvironmentVariables['SteamGameId']='221100'
    $start.Arguments=@(('"-mod='+$mods+'"'),('"-mission='+$mission+'"'),('"-profiles='+$profiles+'"'),('"-storage='+$storage+'"'),'-window','-nopause','-nosplash','-doLogs') -join ' '
    $startedAt=Get-Date
    $process=[Diagnostics.Process]::Start($start)
    $handle=$process.Handle
    Write-Host "Client PID: $($process.Id). Waiting for the offline world..."
    Write-Host "Game logs: $profiles"
    Add-Content -LiteralPath $launcherLog -Value ('PID: '+$process.Id)
    $deadline=(Get-Date).AddSeconds(60)
    do {
        Start-Sleep -Milliseconds 500
        $process.Refresh()
        if($process.HasExited){throw "DayZ exited during startup (code $($process.ExitCode)). See $profiles"}
        $fresh=@(Get-ChildItem -LiteralPath $profiles -Filter 'script_*.log' -File | Where-Object {$_.CreationTime -ge $startedAt.AddSeconds(-1)})
        $loaded=@($fresh | Where-Object {Select-String -LiteralPath $_.FullName -SimpleMatch '[DTR OFFLINE] World loaded; size=1024' -Quiet})
        if($loaded.Count){Add-Content -LiteralPath $launcherLog -Value ('READY: '+(Get-Date).ToString('o'));Write-Host 'READY: offline world loaded.';exit 0}
    }while((Get-Date)-lt $deadline)
    Write-Warning "The client is still running, but world loading is unconfirmed. Inspect $profiles before starting another client."
    Add-Content -LiteralPath $launcherLog -Value ('Readiness timeout: '+(Get-Date).ToString('o'))
}catch{
    Write-Host ('ERROR: '+$_.Exception.Message) -ForegroundColor Red
    exit 1
}
