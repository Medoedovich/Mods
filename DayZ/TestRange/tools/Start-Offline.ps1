param(
    [string]$Root=(Split-Path -Parent $PSScriptRoot),
    [string]$Game='D:\SteamLibrary\steamapps\common\DayZ',
    [string]$ExtraMods='',
    [switch]$Diag,
    [switch]$Retail,
    [switch]$CheckOnly
)
$ErrorActionPreference='Stop'
try {
if ($Diag -and $Retail) {throw 'Choose either -Diag or -Retail, not both.'}
$Root=[IO.Path]::GetFullPath($Root)
$mission=Join-Path $Root 'Missions\offline.dayztestrange'
$exe=Join-Path $Game 'DayZDiag_x64.exe'
if ($Retail) { $exe=Join-Path $Game 'DayZ_x64.exe' }
foreach($inputFile in @('init.c','db\economy.xml','cfgplayerspawnpoints.xml')) {
    if (-not (Test-Path -LiteralPath (Join-Path $mission $inputFile) -PathType Leaf)) { throw "Offline mission input missing: $inputFile" }
}
$profiles=Join-Path $Root 'runtime\offline-profiles'
$storage=Join-Path $Root 'runtime\offline-storage'
$mods=Join-Path $Root 'dist\@DayZTestRange'
if ($ExtraMods) {
    foreach($extraMod in $ExtraMods.Split(';')) {
        if (-not [IO.Path]::IsPathRooted($extraMod) -or -not (Test-Path -LiteralPath $extraMod -PathType Container)) {throw "ExtraMods requires existing absolute mod directory paths: $extraMod"}
    }
    $mods += ';'+$ExtraMods
}
New-Item -ItemType Directory -Force -Path $profiles,$storage | Out-Null
$arguments=@("`"-mod=$mods`"", "`"-mission=$mission`"", "`"-profiles=$profiles`"", "`"-storage=$storage`"",'-window','-nopause','-nosplash','-doLogs')
. (Join-Path $PSScriptRoot 'Launch-Common.ps1')
Invoke-DTRLaunch -Root $Root -Game $Game -Exe $exe -Arguments $arguments -Role offline -CheckOnly:$CheckOnly
} catch {
    Write-Host ("ERROR: " + $_.Exception.Message) -ForegroundColor Red
    exit 1
}
