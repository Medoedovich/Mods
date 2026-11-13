[CmdletBinding()]
param([string]$Tools = '', [switch]$PrepareOnly)
$ErrorActionPreference = 'Stop'
$taskProject = Split-Path -Parent $PSScriptRoot
$taskSource = Join-Path $taskProject 'src\iot\proxytool'
$taskVersion = '0.1.0-alpha'
$taskBuildRoot = Join-Path $taskProject ('build\'+(Get-Date -Format 'yyyyMMdd-HHmmss-fff'))
$taskAddon = Join-Path $taskBuildRoot 'iot_proxy_tool'
$taskPackage = Join-Path $taskBuildRoot '@ProxyPlacementTool'
$taskRequired = @('config.cpp','stringtable.csv','scripts\5_Mission\IOTProxyTool.c','gui\proxy_tool.layout','gui\scene_browser.layout','gui\scene_items.layout','gui\player_mode.layout','gui\camera_speed.layout')
foreach ($taskName in $taskRequired) {
    if (-not (Test-Path -LiteralPath (Join-Path $taskSource $taskName) -PathType Leaf)) { throw ('Missing source: '+$taskName) }
}
if (-not $PrepareOnly) {
    if (-not $Tools) { throw 'Pass -Tools with the DayZ Tools installation folder, or use -PrepareOnly.' }
    $Tools = (Resolve-Path -LiteralPath $Tools).Path
    $taskBuilder = Join-Path $Tools 'Bin\AddonBuilder\AddonBuilder.exe'
    $taskBank = Join-Path $Tools 'Bin\PboUtils\BankRev.exe'
    foreach ($taskTool in @($taskBuilder,$taskBank)) {
        if (-not (Test-Path -LiteralPath $taskTool -PathType Leaf)) { throw ('Official tool not found: '+$taskTool) }
    }
}
if (Test-Path -LiteralPath $taskBuildRoot) { throw 'Build output already exists; start a new build.' }
foreach ($taskDirectory in @($taskAddon,$taskPackage,(Join-Path $taskPackage 'addons'))) { [IO.Directory]::CreateDirectory($taskDirectory) | Out-Null }
Get-ChildItem -LiteralPath $taskSource -Force | Copy-Item -Destination $taskAddon -Recurse
Get-ChildItem -LiteralPath (Join-Path $taskProject 'package') -Force | Copy-Item -Destination $taskPackage -Recurse
$taskRecord = [ordered]@{Version=$taskVersion;Status='PREPARED';AddonSource=$taskAddon;Package=$taskPackage;BuiltAt=(Get-Date -Format o)}
if (-not $PrepareOnly) {
    $taskInclude = Join-Path $taskBuildRoot 'include.txt'
    [IO.File]::WriteAllText($taskInclude,'*.c;*.cpp;*.layout;*.csv',[Text.Encoding]::ASCII)
    $taskTemp = Join-Path $taskBuildRoot 'temp'
    [IO.Directory]::CreateDirectory($taskTemp) | Out-Null
    $taskOutput = & $taskBuilder $taskAddon (Join-Path $taskPackage 'addons') '-packonly' '-prefix=iot\proxytool' ('-project='+$taskBuildRoot) ('-temp='+$taskTemp) ('-include='+$taskInclude) ('-toolsDirectory='+$Tools) 2>&1
    $taskExit = $LASTEXITCODE
    $taskOutput | Set-Content -LiteralPath (Join-Path $taskBuildRoot 'addon-builder.log') -Encoding UTF8
    if ($taskExit -ne 0 -or ($taskOutput -match '\[ERROR\]')) { throw ('Addon Builder failed. Inspect '+(Join-Path $taskBuildRoot 'addon-builder.log')) }
    $taskPbo = Join-Path $taskPackage 'addons\iot_proxy_tool.pbo'
    if (-not (Test-Path -LiteralPath $taskPbo -PathType Leaf)) { throw 'No PBO was produced.' }
    $taskProperties = (& $taskBank -p $taskPbo) -join "`n"
    if ($LASTEXITCODE -ne 0 -or $taskProperties -notmatch 'prefix = iot\\proxytool\\') { throw 'Incorrect PBO prefix.' }
    $taskEntries = @(& $taskBank -lf $taskPbo | ForEach-Object { $_.ToString().Trim().ToLowerInvariant() })
    if ($LASTEXITCODE -ne 0) { throw 'BankRev could not inspect the PBO.' }
    foreach ($taskName in $taskRequired) {
        if ($taskEntries -notcontains ('iot\proxytool\'+$taskName.ToLowerInvariant())) { throw ('PBO entry missing: '+$taskName) }
    }
    $taskFiles = @(Get-ChildItem -LiteralPath $taskPackage -Recurse -File | ForEach-Object {
        [pscustomobject]@{Path=$_.FullName.Substring($taskPackage.Length+1).Replace('\','/');Bytes=$_.Length;SHA256=(Get-FileHash -LiteralPath $_.FullName).Hash}
    })
    [ordered]@{Name='Proxy Placement Tool - Alpha';Author='Medoedovich';Version=$taskVersion;Runtime='DayZDiag offline';RequiredWorkshopItems=@('3826868718');EditorLanguages=@('Russian','English');Files=$taskFiles} | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath (Join-Path $taskPackage 'release-manifest.json') -Encoding UTF8
    $taskRecord.Status = 'BUILT'
    $taskRecord.PBO = [ordered]@{Bytes=(Get-Item -LiteralPath $taskPbo).Length;SHA256=(Get-FileHash -LiteralPath $taskPbo).Hash}
}
$taskRecord | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath (Join-Path $taskProject 'build\latest.json') -Encoding UTF8
$taskRecord | ConvertTo-Json -Depth 6
