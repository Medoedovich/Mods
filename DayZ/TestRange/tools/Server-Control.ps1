# Server identity checks and clean shutdown. Windows PowerShell 5.1.
function Get-DTRServer {
    param([string]$Root)
    $stateFile = Join-Path $Root 'runtime\server-launch.json'
    if (-not (Test-Path -LiteralPath $stateFile)) { return }
    $state = Get-Content -LiteralPath $stateFile -Raw | ConvertFrom-Json
    $info = Get-CimInstance Win32_Process -Filter ("ProcessId={0}" -f [int]$state.processId) -ErrorAction SilentlyContinue
    if (-not $info) { return }
    if ($info.ExecutablePath -ine $state.executable -or
        ($info.CommandLine -notmatch '(?i)(?:^|\s)-server(?:\s|$)' -and
        [IO.Path]::GetFileName($info.ExecutablePath) -ine 'DayZServer_x64.exe') -or
        -not $info.CommandLine.ToLowerInvariant().Contains(([string]$state.profiles).ToLowerInvariant())) {
        throw 'Recorded PID no longer matches this project server. No process was changed.'
    }
    if ([Math]::Abs(($info.CreationDate.ToUniversalTime() - ([datetime]$state.startedAt).ToUniversalTime()).TotalSeconds) -gt 5) {
        throw 'Recorded PID creation time differs. No process was changed.'
    }
    [pscustomobject]@{ Info=$info; State=$state; StateFile=$stateFile }
}

function Stop-DTRServer {
    param([string]$Root, [switch]$Force, [int]$TimeoutSeconds=15)
    $server = Get-DTRServer -Root $Root
    if (-not $server) { Write-Host 'Server is already stopped.'; return }
    $serverId = [int]$server.Info.ProcessId
    Write-Host "Requesting clean server shutdown: PID $serverId"
    $commandFile = Join-Path $server.State.profiles 'dtr-server-command.txt'
    [IO.File]::WriteAllText($commandFile, 'shutdown', [Text.Encoding]::ASCII)
    $deadline = (Get-Date).AddSeconds($TimeoutSeconds)
    do {
        if (-not (Get-DTRServer -Root $Root)) { break }
        Start-Sleep -Milliseconds 250
    } while ((Get-Date) -lt $deadline)
    $stillRunning = Get-DTRServer -Root $Root
    if ($stillRunning) {
        if (-not $Force) { throw "Server did not acknowledge shutdown. Retry Stop-Test-Server.cmd -Force to terminate this verified project PID ($serverId)." }
        Write-Warning "Clean shutdown timed out. Terminating verified project server PID $serverId."
        Stop-Process -Id $serverId -ErrorAction Stop
        Wait-Process -Id $serverId -Timeout 5 -ErrorAction SilentlyContinue
        if (Get-DTRServer -Root $Root) { throw "Verified server PID $serverId is still present after termination was requested." }
    }
    $server.State.status = 'stopped'
    $server.State | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath $server.StateFile -Encoding UTF8
    Write-Host 'Server stopped.'
}

