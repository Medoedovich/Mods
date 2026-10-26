[CmdletBinding()]
param(
    [string]$Root = (Split-Path -Parent $PSScriptRoot),
    [string]$WorkDrive = 'P:\',
    [string]$Tools = 'D:\SteamLibrary\steamapps\common\DayZ Tools',
    [switch]$AssetsOnly
)
$ErrorActionPreference = 'Stop'
$terrain = Join-Path $WorkDrive 'dtr\test_range'
$output = Join-Path $Root 'dist\@DayZTestRange\addons'
$logs = Join-Path $Root 'logs'
$buildId = Get-Date -Format 'yyyyMMdd-HHmmss-fff'
$temp = Join-Path $Root "build\binarized\$buildId"
$builder = Join-Path $Tools 'Bin\AddonBuilder\AddonBuilder.exe'
foreach ($p in @($builder, (Join-Path $terrain 'world\config.cpp'), (Join-Path $WorkDrive 'DZ\surfaces\data\terrain\cp_concrete1.rvmat'))) {
    if (-not (Test-Path -LiteralPath $p)) { throw "Missing required input: $p" }
}
if (-not $AssetsOnly) {
    foreach ($p in @((Join-Path $terrain 'world\dayztestrange.wrp'), (Join-Path $terrain 'data\layers'))) {
        if (-not (Test-Path -LiteralPath $p)) { throw "Terrain Builder must generate this file/folder first: $p. See docs/TERRAIN-BUILDER.md" }
    }
    if (-not (Get-ChildItem -LiteralPath (Join-Path $terrain 'data\layers') -Filter '*.rvmat')) { throw 'No generated terrain layer materials.' }
}
New-Item -ItemType Directory -Force -Path $output,$logs,$temp | Out-Null
$parts = @('data','ce')
if (-not $AssetsOnly) { $parts += 'world' }
foreach ($part in $parts) {
    $source = Join-Path $terrain $part
    if ($part -eq 'data') {
        # Keep TB's generated files intact. Package a copy with final runtime
        # texture extensions; the official Binarize converts the PNGs to PAA.
        $stagedData = Join-Path $terrain "_build\$buildId\data"
        New-Item -ItemType Directory -Force -Path $stagedData | Out-Null
        Get-ChildItem -LiteralPath $source | ForEach-Object {
            Copy-Item -LiteralPath $_.FullName -Destination $stagedData -Recurse -Force
        }
        Get-ChildItem -LiteralPath $stagedData -Filter '*.rvmat' -Recurse | ForEach-Object {
            $material = [IO.File]::ReadAllText($_.FullName)
            $material = $material -replace '(?i)\.png"', '.paa"'
            [IO.File]::WriteAllText($_.FullName, $material, [Text.Encoding]::ASCII)
        }
        $source = $stagedData
    }
    $argsList = @($source,$output,"-prefix=dtr\test_range\$part","-project=$WorkDrive","-temp=$temp","-toolsDirectory=$Tools", "-include=$(Join-Path $PSScriptRoot 'include.txt')",'-binarizeAllTextures','-binarizeFullLogs')
    $buildOutput = & $builder @argsList 2>&1
    $buildExitCode = $LASTEXITCODE
    $buildOutput | Tee-Object -FilePath (Join-Path $logs "build-$part.log")
    if ($buildExitCode -ne 0 -or ($buildOutput -match '\[ERROR\]')) { throw "Addon Builder failed for $part, exit $buildExitCode; inspect logs." }
    $pbo = Join-Path $output "$part.pbo"
    if (-not (Test-Path -LiteralPath $pbo)) { throw "Addon Builder returned without $pbo" }
    Move-Item -LiteralPath $pbo -Destination (Join-Path $output "dtr_test_range_$part.pbo") -Force
}
Copy-Item -LiteralPath (Join-Path $Root 'mod.cpp') -Destination (Split-Path -Parent $output) -Force
if ($AssetsOnly) {
    Write-Warning 'Only data and CE PBOs built. This is NOT a playable terrain mod until world WRP is exported and full Build.ps1 succeeds.'
} else {
    & (Join-Path $PSScriptRoot 'Sync-WorkDrive.ps1') -Root $Root -WorkDrive $WorkDrive -Pull
    & (Join-Path $PSScriptRoot 'Validate.ps1') -Root $Root -WorkDrive $WorkDrive -RequireWorld
    & (Join-Path $PSScriptRoot 'Verify-Package.ps1') -Root $Root -Tools $Tools
    & (Join-Path $PSScriptRoot 'Prepare-Release.ps1') -Root $Root
    Write-Host "Built mod: $(Split-Path -Parent $output)"
}
