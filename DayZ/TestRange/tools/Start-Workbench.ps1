[CmdletBinding()]
param(
    [string]$Tools = 'D:\SteamLibrary\steamapps\common\DayZ Tools',
    [switch]$CheckOnly
)
$ErrorActionPreference = 'Stop'
try {
    $workbenchDir = Join-Path $Tools 'Bin\Workbench'
    $exe = Join-Path $workbenchDir 'WorkbenchApp.exe'
    $projectRoot = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)
    $projectFile = Join-Path $projectRoot 'DayZTestRange.gproj'
    foreach ($file in @($exe, $projectFile)) {
        if (-not (Test-Path -LiteralPath $file)) { throw "Missing Workbench input: $file" }
    }
    if (-not (Test-Path -LiteralPath 'P:\scripts')) { throw 'DayZ source data is not available on P:. Mount the WorkDrive first.' }
    if (-not (Get-Process -Name steam -ErrorAction SilentlyContinue)) {
        throw 'Start the Steam client before opening Workbench.'
    }
    Write-Host "Workbench: $exe"
    Write-Host "Project: $projectFile"
    Write-Host 'SteamAppId / SteamGameId: 221100 (child process only)'
    if ($CheckOnly) { Write-Host 'Preflight OK. CheckOnly: Workbench was not started.'; return }
    $existing = @(Get-Process -Name WorkbenchApp -ErrorAction SilentlyContinue)
    if ($existing.Count) {
        Write-Host ('Workbench is already running. PID: ' + (($existing | ForEach-Object { $_.Id }) -join ', '))
        return
    }

    # Direct launch can fail before showing a window if Steam's application
    # identity is absent. Pass the installed game's identity to this child;
    # restore the launcher's environment immediately after process creation.
    $previousAppId = [Environment]::GetEnvironmentVariable('SteamAppId', 'Process')
    $previousGameId = [Environment]::GetEnvironmentVariable('SteamGameId', 'Process')
    try {
        [Environment]::SetEnvironmentVariable('SteamAppId', '221100', 'Process')
        [Environment]::SetEnvironmentVariable('SteamGameId', '221100', 'Process')
        $process = Start-Process -FilePath $exe -ArgumentList ('"-gproj=' + $projectFile + '"') -WorkingDirectory $workbenchDir -PassThru
    } finally {
        [Environment]::SetEnvironmentVariable('SteamAppId', $previousAppId, 'Process')
        [Environment]::SetEnvironmentVariable('SteamGameId', $previousGameId, 'Process')
    }
    Start-Sleep -Seconds 3
    $process.Refresh()
    if ($process.HasExited -and $process.ExitCode -ne 0) {
        throw "Workbench exited early with code $($process.ExitCode). Inspect error_*.log in $workbenchDir"
    }
    Write-Host "Workbench process created. PID: $($process.Id)."
    Write-Host 'The interface may need a few more seconds to finish loading.'
} catch {
    Write-Host ('Workbench launch failed: ' + $_.Exception.Message) -ForegroundColor Red
    exit 1
}
