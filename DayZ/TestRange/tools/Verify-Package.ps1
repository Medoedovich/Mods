param([string]$Root=(Split-Path -Parent $PSScriptRoot),[string]$Tools='D:\SteamLibrary\steamapps\common\DayZ Tools')
$ErrorActionPreference='Stop'
$bank=Join-Path $Tools 'Bin\PboUtils\BankRev.exe'
$folder=Join-Path $Root 'dist\@DayZTestRange\addons'
$contents=@{}
foreach($part in @('world','data','ce')) {
    $pbo=Join-Path $folder "dtr_test_range_$part.pbo"
    if(-not(Test-Path -LiteralPath $pbo)) {throw "Missing PBO: $pbo"}
    $properties=(& $bank -p $pbo) -join "`n"
    if($LASTEXITCODE -ne 0 -or $properties -notmatch ('prefix = dtr\\test_range\\'+$part+'\\')) {throw "Incorrect PBO prefix: $pbo"}
    $contents[$part]=@(& $bank -lf $pbo | ForEach-Object {$_.ToString().Trim().ToLowerInvariant()})
    if($LASTEXITCODE -ne 0) {throw "Cannot read PBO: $pbo"}
    if($contents[$part] -notcontains "dtr\test_range\$part\config.bin") {throw "Missing compiled config in $part"}
}
if($contents.world -notcontains 'dtr\test_range\world\dayztestrange.wrp') {throw 'WRP is absent from world PBO.'}
$materials=Get-ChildItem -LiteralPath (Join-Path $Root 'src\dtr\test_range\data\layers') -Filter '*.rvmat'
if($materials.Count -ne 16) {throw 'Expected sixteen terrain material tiles for the aligned 4 x 4 samplers.'}
foreach($material in $materials) {
    $runtimeName=('dtr\test_range\data\layers\'+$material.Name).ToLowerInvariant()
    if($contents.data -notcontains $runtimeName) {throw "Missing material in PBO: $runtimeName"}
    $text=[IO.File]::ReadAllText($material.FullName)
    foreach($match in [regex]::Matches($text,'texture\s*=\s*"([^"]+)"')) {
        $reference=($match.Groups[1].Value -replace '(?i)\.png$', '.paa').ToLowerInvariant()
        if($reference.StartsWith('dtr\') -and $contents.data -notcontains $reference) {throw "Unresolved material texture: $reference"}
    }
}
Write-Host 'PASS: official BankRev confirms PBO prefixes, compiled configs, WRP, sixteen RVMAT files and all local material texture references.'
