param(
    [string]$Root=(Split-Path -Parent $PSScriptRoot),
    [string]$Game='D:\SteamLibrary\steamapps\common\DayZ',
    [string]$ServerExe='',
    [int]$Port=2302,
    [switch]$CheckOnly,
    [switch]$Detached
)
$ErrorActionPreference='Stop'
try {
$Root=[System.IO.Path]::GetFullPath($Root)
$mod=Join-Path $Root 'dist\@DayZTestRange'
if (-not $ServerExe) { $ServerExe=Join-Path $Game 'DayZDiag_x64.exe' }
$diag=([System.IO.Path]::GetFileName($ServerExe) -ieq 'DayZDiag_x64.exe')
$profiles=Join-Path $Root 'runtime\server-profiles'
$storage=Join-Path $Root 'runtime\storage'
$arguments=@("`"-config=$(Join-Path $Root 'server\config\serverDZ.cfg')`"", "`"-mission=$(Join-Path $Root 'server\mpmissions\empty.dayztestrange')`"", "`"-mod=$mod`"", "`"-profiles=$profiles`"", "`"-storage=$storage`"", "-port=$Port",'-doLogs','-adminLog','-limitFPS=60')
if ($diag) { $arguments += '-server' }
. (Join-Path $PSScriptRoot 'Launch-Common.ps1')
$serverProcess = Invoke-DTRLaunch -Root $Root -Game $Game -Exe $ServerExe -Arguments $arguments -Role server -Port $Port -CheckOnly:$CheckOnly -PassThru -HiddenWindow:$Detached
if (-not $CheckOnly) {
    if ($Detached) { Write-Host 'Server is running with its window hidden. Use Stop-Test-Server.cmd to stop it.' }
    else { Write-Host 'Server is running in its native DayZ Console window. Close that window with X, or use Stop-Test-Server.cmd.' }
}
} catch {
    Write-Host ("ERROR: " + $_.Exception.Message) -ForegroundColor Red
    exit 1
}
