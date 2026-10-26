param([string]$Root=(Split-Path -Parent $PSScriptRoot),[string]$Game='D:\SteamLibrary\steamapps\common\DayZ',[int]$Port=2302,[switch]$Retail,[switch]$CheckOnly)
$ErrorActionPreference='Stop'
try {
$Root=[System.IO.Path]::GetFullPath($Root)
$mod=Join-Path $Root 'dist\@DayZTestRange'
$exe=Join-Path $Game 'DayZDiag_x64.exe'
if ($Retail) { $exe=Join-Path $Game 'DayZ_x64.exe' }
$profiles=Join-Path $Root 'runtime\client-profiles'
$arguments=@("`"-mod=$mod`"","`"-profiles=$profiles`"",'-connect=127.0.0.1',"-port=$Port",'-password=dtr-local','-window','-nopause','-doLogs')
. (Join-Path $PSScriptRoot 'Launch-Common.ps1')
Invoke-DTRLaunch -Root $Root -Game $Game -Exe $exe -Arguments $arguments -Role client -Port $Port -CheckOnly:$CheckOnly
} catch {
    Write-Host ("ERROR: " + $_.Exception.Message) -ForegroundColor Red
    exit 1
}
