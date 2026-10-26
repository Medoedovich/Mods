[CmdletBinding()]
param([string]$Root='',[string]$WorkDrive='P:\',[switch]$RequireWorld)
$ErrorActionPreference='Stop'
if (-not $Root) { $Root=Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path) }
$terrain=Join-Path $Root 'src\dtr\test_range'
$worldConfig=Get-Content -LiteralPath (Join-Path $terrain 'world\config.cpp') -Raw
foreach($field in @('MaxTide','MaxWave')) {
    if ($worldConfig -notmatch ("(?m)^\s*"+$field+"\s*=\s*0\s*;")) {throw "Expected $field = 0 for the +1 m test floor."}
}
$asc=Get-Content -LiteralPath (Join-Path $terrain 'source\heightmap.asc')
if (($asc[0..5] -join '|') -ne 'ncols 256|nrows 256|xllcorner 200000|yllcorner 0|cellsize 4|NODATA_value -9999') { throw 'Heightmap georeferencing differs from specification.' }
if ($asc.Count -ne 262) { throw 'Expected 256 height rows.' }
for ($rowIndex=0; $rowIndex -lt 256; $rowIndex++) {
    $values=$asc[$rowIndex+6].Split(' ',[StringSplitOptions]::RemoveEmptyEntries)
    if ($values.Count -ne 256) { throw "Invalid height sample count in row $rowIndex" }
    for ($column=0; $column -lt 256; $column++) {
        $expected=if ($rowIndex -eq 0 -or $rowIndex -eq 255 -or $column -eq 0 -or $column -eq 255) {-20} else {1}
        if ([double]::Parse($values[$column],[Globalization.CultureInfo]::InvariantCulture) -ne $expected) { throw "Invalid coastal height at row $rowIndex column $column; expected $expected m." }
    }
}
Add-Type -AssemblyName System.Drawing
foreach($file in @('sat_lco.png','mask_lco.png','normal_lco.png')) {
    $bitmap=[Drawing.Bitmap]::FromFile((Join-Path $terrain "source\$file"))
    try {
        if ($bitmap.Width -ne 1024 -or $bitmap.Height -ne 1024) { throw "Invalid raster dimensions: $file" }
        if ($file -eq 'mask_lco.png') {
            for($y=0;$y -lt 1024;$y++) {for($x=0;$x -lt 1024;$x++) {
                $p=$bitmap.GetPixel($x,$y)
                if ($p.R -ne 255 -or $p.G -ne 0 -or $p.B -ne 255) {throw 'Surface mask must contain one exact RGB color.'}
            }}
        }
    } finally { $bitmap.Dispose() }
}
foreach($area in @('src\dtr\test_range\ce','server\mpmissions\empty.dayztestrange','Missions\offline.dayztestrange')) {
    $folder=Join-Path $Root $area
    foreach($file in Get-ChildItem -LiteralPath $folder -Filter '*.xml' -Recurse) {
        [xml]$document=Get-Content -LiteralPath $file.FullName -Raw
    }
    [xml]$economy=Get-Content -LiteralPath (Join-Path $folder 'db\economy.xml') -Raw
    foreach($node in $economy.economy.ChildNodes | Where-Object {$_.Name -ne 'player'}) {
        foreach($attr in @('init','load','respawn','save')) {if ($node.GetAttribute($attr) -ne '0') {throw "Enabled spawner $($node.Name) in $folder"}}
    }
    [xml]$events=Get-Content -LiteralPath (Join-Path $folder 'db\events.xml') -Raw
    [xml]$types=Get-Content -LiteralPath (Join-Path $folder 'db\types.xml') -Raw
    if ($events.SelectNodes('/events/event').Count -or $types.SelectNodes('/types/type').Count) {throw 'Expected empty event and loot definitions.'}
    [xml]$spawns=Get-Content -LiteralPath (Join-Path $folder 'cfgplayerspawnpoints.xml') -Raw
    foreach($pos in $spawns.SelectNodes('//pos')) {if($pos.x -ne '512' -or $pos.z -ne '512') {throw 'Spawn point differs from center.'}}
}
foreach($p in @('DZ\surfaces\data\terrain\cp_concrete1.rvmat','DZ\surfaces\data\terrain\cp_concrete1_nopx.paa','DZ\surfaces\data\terrain\cp_concrete1_ca.paa')) {
    if(-not (Test-Path -LiteralPath (Join-Path $WorkDrive $p))) {throw "Missing vanilla resource $p"}
}
if ($RequireWorld) {
    foreach ($p in @('world\dayztestrange.wrp','source\dayztestrange.tv4p','data\layers')) {
        if(-not (Test-Path -LiteralPath (Join-Path $terrain $p))) {throw "Missing official Terrain Builder output: $p"}
    }
    $pboFolder=Join-Path $Root 'dist\@DayZTestRange\addons'
    foreach($name in @('world','data','ce')) {
        $pbo=Join-Path $pboFolder "dtr_test_range_$name.pbo"
        if(-not(Test-Path -LiteralPath $pbo)) {throw "Missing built PBO: $pbo"}
    }
}
Write-Host 'PASS: 1024 m world, flat 1 m interior with approved -20 m edge ring, one surface, XML, center spawn, disabled spawners, vanilla paths.'
if(-not $RequireWorld) {Write-Warning 'This is a source validation only. WRP and in-game behavior are not validated.'}
