param([string]$Root='')
$ErrorActionPreference='Stop'
if(-not $Root){$Root=Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)}
$mod=Join-Path $Root 'dist\@DayZTestRange'
foreach ($part in @('world','data','ce')) {
    $pbo=Join-Path $mod "addons\dtr_test_range_$part.pbo"
    if (-not (Test-Path -LiteralPath $pbo -PathType Leaf)) { throw "Missing built PBO: $pbo" }
}
$mission=Join-Path $Root 'server\mpmissions\empty.dayztestrange'
$missionDestination=Join-Path $mod 'mpmissions\empty.dayztestrange'
New-Item -ItemType Directory -Force -Path $missionDestination | Out-Null
Get-ChildItem -LiteralPath $mission | ForEach-Object {
    Copy-Item -LiteralPath $_.FullName -Destination $missionDestination -Recurse -Force
}
Copy-Item -LiteralPath (Join-Path $Root 'docs\MOD-SETUP.md') -Destination (Join-Path $mod 'README-SETUP.md') -Force
Copy-Item -LiteralPath (Join-Path $Root 'LICENSE.md') -Destination (Join-Path $mod 'LICENSE.md') -Force
$offlineSource=Join-Path $Root 'Missions\offline.dayztestrange'
$offlineDestination=Join-Path $mod 'Missions\offline.dayztestrange'
New-Item -ItemType Directory -Force -Path $offlineDestination | Out-Null
Get-ChildItem -LiteralPath $offlineSource | ForEach-Object {Copy-Item -LiteralPath $_.FullName -Destination $offlineDestination -Recurse -Force}
foreach($file in @('Start-Offline.cmd','Start-Offline.ps1')){
    Copy-Item -LiteralPath (Join-Path $Root ('tools\distribution\'+$file)) -Destination (Join-Path $mod $file) -Force
}
Write-Host "Release content prepared: $mod"
Write-Host 'Offline/DayZDiag release includes its mission and standalone launcher. PBO signatures are optional for this workflow.'
