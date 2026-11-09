<# Build a schemaVersion 2 snapshot from the targeted native source-base report.
   Prepare in exports/ first; review before adding an immutable archive revision. #>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$ReportPath,
    [Parameter(Mandatory = $true)][string]$OutputDirectory,
    [ValidatePattern('^r[0-9]{4}$')][string]$RevisionId = 'r0002',
    [Parameter(Mandatory = $true)][string]$RevisionReason,
    [string]$WorkbenchVersion
)
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$culture = [Globalization.CultureInfo]::InvariantCulture
$componentClass = 'SCR_CampaignSourceBaseComponent'
$normalizerVersion = 'supply-sources-0.2'
$output = [IO.Path]::GetFullPath($OutputDirectory)
if (Test-Path -LiteralPath $output) { throw 'Output directory already exists; choose a new snapshot revision.' }

# Hash exactly the bytes that are parsed, even if the input changes concurrently.
$inputBytes = [IO.File]::ReadAllBytes((Resolve-Path -LiteralPath $ReportPath).Path)
$sha = [Security.Cryptography.SHA256]::Create()
try { $inputHash = ([BitConverter]::ToString($sha.ComputeHash($inputBytes))).Replace('-', '') }
finally { $sha.Dispose() }
$diagnostics = ([Text.Encoding]::UTF8.GetString($inputBytes)).TrimStart([char]0xFEFF) | ConvertFrom-Json
if ($diagnostics.schemaVersion -ne 2 -or $diagnostics.kind -ne 'supply-source-bases' -or
    $diagnostics.selection -ne $componentClass -or $diagnostics.records.Count -ne $diagnostics.recordCount -or
    !$diagnostics.editorEntityCountUnchanged -or $diagnostics.editorEntityCountBefore -ne $diagnostics.editorEntityCountAfter) {
    throw 'Inconsistent targeted source-base report.'
}
if ($diagnostics.gameVersion -notmatch '^\d+(\.\d+)+$' -or
    $diagnostics.worldPath -notmatch '/(?<scenario>[A-Za-z0-9_-]+)\.ent$') {
    throw 'Missing or unsupported game version / scenario path.'
}
$scenarioKey = $Matches.scenario
$capturedAt = [DateTime]::ParseExact($diagnostics.generatedAtUTC, 'yyyy-MM-dd HH:mm:ss', $culture)
$capturedAtUTC = $capturedAt.ToString("yyyy-MM-dd'T'HH:mm:ss'Z'", $culture)
$snapshotId = "$($diagnostics.gameVersion)/$scenarioKey/$RevisionId"

function Get-RequiredField($Component, [string]$Name) {
    $fields = @($Component.fields | Where-Object name -eq $Name)
    if ($fields.Count -ne 1) {
        throw "Required field '$Name' is missing or ambiguous."
    }
    return $fields[0]
}
function Get-IntegerValue($Field) {
    if ($Field.status -ne 'resolved') { return $null }
    [long]$value = 0
    if ($Field.type -ne 'INTEGER' -or
        ![long]::TryParse($Field.value, [Globalization.NumberStyles]::Integer, $culture, [ref]$value)) {
        throw "Field '$($Field.name)' is not a resolved integer."
    }
    return $value
}
function Get-FieldOrigin($Field) {
    return [ordered]@{
        component = $componentClass
        field = $Field.name
        method = 'BaseContainer.Get'
        rawValue = $Field.value
        fieldStatus = $Field.status
        directOverride = [bool]$Field.directOverride
        resolution = $(if ($Field.status -ne 'resolved') { 'unknown' } elseif ($Field.directOverride) { 'override' } else { 'inherited_or_default' })
        definingResource = $null
        definingResourceStatus = 'unknown'
    }
}

$selected = @($diagnostics.records)
$allowedFields = @('Enabled', 'm_sBaseName', 'm_iRegularSuppliesIncomeBase', 'm_iSuppliesArrivalInterval')
$subscenes = @{}
foreach ($scene in $diagnostics.subscenes) {
    if ($subscenes.ContainsKey([int]$scene.index)) { throw 'Duplicate subscene metadata.' }
    $subscenes[[int]$scene.index] = $scene.name
}
$keys = New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal)
$records = @($selected | Sort-Object name, sourceId | ForEach-Object {
    $entity = $_
    if ($entity.fields.Count -ne $allowedFields.Count -or @($entity.fields.name | Where-Object { $_ -notin $allowedFields }).Count -ne 0) {
        throw 'Unexpected fields in targeted report.'
    }
    $key = "$($entity.subscene)/$($entity.layer)/$($entity.sourceId)"
    if (!$entity.sourceId -or !$keys.Add($key)) { throw "Missing or duplicate source key: $key" }
    $income = Get-RequiredField $entity 'm_iRegularSuppliesIncomeBase'
    $interval = Get-RequiredField $entity 'm_iSuppliesArrivalInterval'
    $amount = Get-IntegerValue $income
    $seconds = Get-IntegerValue $interval
    $amountStatus = if ($null -eq $amount -or $amount -lt 0) { 'unknown' } else { 'resolved' }
    $intervalStatus = if ($null -eq $seconds -or $seconds -le 0) { 'unknown' } else { 'resolved' }
    $enabledField = Get-RequiredField $entity 'Enabled'
    $enabled = $null
    if ($enabledField.status -eq 'resolved') {
        if ($enabledField.type -ne 'BOOLEAN' -or $enabledField.value -notin @('true', 'false')) { throw 'Invalid Enabled field.' }
        $enabled = $enabledField.value -eq 'true'
    }
    $baseNameField = Get-RequiredField $entity 'm_sBaseName'
    $baseNameKey = if ($baseNameField.status -eq 'resolved') { $baseNameField.value } else { $null }
    $sourceWorld = if ($subscenes.ContainsKey([int]$entity.subscene)) { $subscenes[[int]$entity.subscene] } else { $null }
    $sourceWorldPath = if ($sourceWorld -and $sourceWorld -match '\.ent$') { $sourceWorld } else { $null }
    $position = if ($entity.positionStatus -eq 'resolved' -and $entity.worldPositionMeters.Count -eq 3) { @($entity.worldPositionMeters) } else { $null }
    [ordered]@{
        id = $key
        source = [ordered]@{
            sourceId = $entity.sourceId
            parentSourceId = $entity.parentSourceId
            subscene = $entity.subscene
            layer = $entity.layer
            subsceneName = $sourceWorld
            worldPath = $sourceWorldPath
            worldPathStatus = $(if ($sourceWorldPath) { 'resolved' } else { 'unknown' })
            nearestPrefab = $entity.prefab
            worldPositionMeters = $position
            positionStatus = $entity.positionStatus
        }
        name = $entity.name
        enabled = $enabled
        baseNameLocalizationKey = $baseNameKey
        location = [ordered]@{ status = 'not_analyzed'; name = $null }
        supplyIncomePerCycle = $(if ($amountStatus -eq 'resolved') { $amount } else { $null })
        arrivalIntervalSeconds = $(if ($intervalStatus -eq 'resolved') { $seconds } else { $null })
        arrivalIntervalMinutes = $(if ($intervalStatus -eq 'resolved') { [decimal]$seconds / 60 } else { $null })
        valueStatus = [ordered]@{ supplyIncomePerCycle = $amountStatus; arrivalInterval = $intervalStatus }
        warnings = @(
            if ($amountStatus -ne 'resolved') { 'Supply income is unknown or requires fallback analysis; inspect provenance.rawValue.' }
            if ($intervalStatus -ne 'resolved') { 'Arrival interval is unknown or requires fallback analysis; inspect provenance.rawValue.' }
            if ($null -eq $enabled) { 'Enabled state is unknown.' }
            if ($null -eq $position) { 'World position is unresolved or mismatched.' }
            if (!$sourceWorldPath) { 'Source world path is unknown.' }
        )
        provenance = [ordered]@{
            name = [ordered]@{ field = 'entity.name'; method = 'IEntitySource.GetName'; resolution = 'source' }
            enabled = Get-FieldOrigin $enabledField
            baseNameLocalizationKey = Get-FieldOrigin $baseNameField
            supplyIncomePerCycle = Get-FieldOrigin $income
            arrivalIntervalSeconds = Get-FieldOrigin $interval
            arrivalIntervalMinutes = [ordered]@{ method = 'calculated'; expression = 'arrivalIntervalSeconds / 60'; unit = 'minutes' }
        }
    }
})
$warnings = @(
    'Only configured source-base income and intervals have been normalized; this is a partial snapshot.',
    'Source IDs are provisional editor identifiers, not verified keys across game versions.',
    'Nearest prefab is an owner reference; the exact resource defining each inherited field is unknown.',
    'Storage capacity, localized location names and runtime supply-generation conditions have not been analyzed.',
    'World resource GUID, release channel and complete loaded-addon inventory are unknown.'
)
$data = [ordered]@{
    schemaVersion = 2
    kind = 'supply-source-bases-report'
    snapshotId = $snapshotId
    status = 'partial'
    gameVersion = $diagnostics.gameVersion
    scenarioKey = $scenarioKey
    revisionId = $RevisionId
    capturedAtUTC = $capturedAtUTC
    analyzerVersion = $diagnostics.analyzerVersion
    normalizerVersion = $normalizerVersion
    inputSha256 = $inputHash
    worldMetadata = '../world.json'
    selection = $componentClass
    count = $records.Count
    units = [ordered]@{ supplyIncomePerCycle = 'supplies'; arrivalIntervalSeconds = 'seconds'; arrivalIntervalMinutes = 'minutes' }
    records = $records
    warnings = $warnings
}
$world = [ordered]@{
    schemaVersion = 2
    snapshotId = $snapshotId
    revisionId = $RevisionId
    revisionReason = $RevisionReason
    scenarioKey = $scenarioKey
    worldPath = $diagnostics.worldPath
    worldResourceGuid = $null
    worldResourceGuidStatus = 'unknown'
    gameVersion = $diagnostics.gameVersion
    gameChannel = $null
    workbenchVersion = $(if ($WorkbenchVersion) { $WorkbenchVersion } else { $null })
    workbenchVersionStatus = $(if ($WorkbenchVersion) { 'provided_by_operator' } else { 'unknown' })
    capturedAtUTC = $capturedAtUTC
    mode = 'targeted-source-bases'
    status = 'partial'
    analyzerVersion = $diagnostics.analyzerVersion
    normalizerVersion = $normalizerVersion
    input = [ordered]@{ fileName = [IO.Path]::GetFileName($ReportPath); sha256 = $inputHash; schemaVersion = $diagnostics.schemaVersion }
    subsceneCount = $diagnostics.subsceneCount
    subscenes = @($diagnostics.subscenes)
    editorEntityCountUnchanged = $diagnostics.editorEntityCountUnchanged
    sourceWarnings = @($diagnostics.warnings)
    warnings = $warnings
}
$index = [ordered]@{
    schemaVersion = 2
    kind = 'conflict-world-index'
    snapshotId = $snapshotId
    status = 'partial'
    worldMetadata = 'world.json'
    sections = [ordered]@{
        aiGroups = [ordered]@{ status = 'not_analyzed'; path = $null }
        supplies = [ordered]@{
            status = 'partial'
            sourceBases = [ordered]@{ status = 'partial'; path = 'Supplies/Harbors.json'; table = 'Supplies/Harbors.md'; count = $records.Count }
            storagePoints = [ordered]@{ status = 'not_analyzed'; path = $null }
        }
        startingBases = [ordered]@{ status = 'not_analyzed'; path = $null }
        vehicleSpawns = [ordered]@{ status = 'not_analyzed'; path = $null }
        locations = [ordered]@{ status = 'not_analyzed'; path = $null }
    }
}

function Write-NewFile([string]$Path, [string]$Content) {
    $stream = [IO.File]::Open($Path, [IO.FileMode]::CreateNew, [IO.FileAccess]::Write, [IO.FileShare]::None)
    $writer = New-Object IO.StreamWriter($stream, (New-Object Text.UTF8Encoding($false)))
    try { $writer.Write($Content.Replace("`r`n", "`n").TrimEnd() + "`n") } finally { $writer.Dispose() }
}
# Complete validation precedes writing. This tool never edits the source world or a version manifest.
$null = New-Item -ItemType Directory -Path (Join-Path $output 'Supplies')
Write-NewFile (Join-Path $output 'Supplies\Harbors.json') ($data | ConvertTo-Json -Depth 15)
Write-NewFile (Join-Path $output 'data.json') ($index | ConvertTo-Json -Depth 10)
Write-NewFile (Join-Path $output 'world.json') ($world | ConvertTo-Json -Depth 10)

# Markdown uses the saved normalized JSON, not a second extraction from diagnostics.
$saved = Get-Content -LiteralPath (Join-Path $output 'Supplies\Harbors.json') -Raw -Encoding UTF8 | ConvertFrom-Json
$harborCount = @($saved.records | Where-Object { $_.source.nearestPrefab -like '*ConflictSourceBase_T*Harbor.et' }).Count
$airfieldCount = @($saved.records | Where-Object { $_.source.nearestPrefab -like '*ConflictSourceBase_Airfield.et' }).Count
function Escape-Cell([string]$Value) { return $Value.Replace('\', '\\').Replace('|', '\|').Replace("`r", ' ').Replace("`n", ' ') }
$rows = @($saved.records | ForEach-Object {
    $minutes = if ($null -eq $_.arrivalIntervalMinutes) { 'unknown' } else { ([decimal]$_.arrivalIntervalMinutes).ToString('0.############################', $culture) }
    $amountText = if ($null -eq $_.supplyIncomePerCycle) { 'unknown' } else { [string]$_.supplyIncomePerCycle }
    '| {0} | {1} | {2} |' -f (Escape-Cell $_.name), $amountText, $minutes
})
$harbors = @'
# Базы-источники припасов

## Summary

Всего точек: **{COUNT}**.

Из них портов: **{HARBORS}**, аэропортов: **{AIRFIELDS}**.

Игра **{VERSION}**, мир `CTI_Campaign_HQC_Eden.ent`, ревизия `{REVISION}`. Снимок частичный: таблица содержит настройки пополнения баз с компонентом `SCR_CampaignSourceBaseComponent`.

## Откуда берутся данные

| Столбец | Источник |
| --- | --- |
| Название | `records[].name` целевого экспорта Workbench, полученное через `IEntitySource.GetName()` — имя editor source. Игровое название ближайшей локации пока не определено. |
| Пополнение за цикл, припасы | `SCR_CampaignSourceBaseComponent.m_iRegularSuppliesIncomeBase`, прочитанное через `BaseContainer.Get`. В JSON: `supplyIncomePerCycle`. |
| Пополнение, мин. | `SCR_CampaignSourceBaseComponent.m_iSuppliesArrivalInterval`, прочитанное через `BaseContainer.Get` в секундах; минуты = секунды / 60. В JSON сохраняются `arrivalIntervalSeconds` и `arrivalIntervalMinutes`. |

Для каждой записи сохранены source ID, слой, ближайший prefab и происхождение полей. Признак `directOverride` отличает прямое переопределение от унаследованного значения или значения по умолчанию. Точный ресурс, задающий унаследованное значение, ещё не установлен. Пополнение за цикл описывает настройку дохода; вместимость хранилища и условия работы генератора требуют отдельного анализа.

Неизвестные значения и настройки, требующие анализа fallback, выводятся как `unknown`; исходное поле сохраняется в `provenance.rawValue`. Выборка содержит настроенные источники, включая отключённые; `Enabled` сохранён в JSON и не доказывает выполнение всех условий дохода.

Источник таблицы: [Harbors.json](Harbors.json). Метаданные и ограничения: [world.json](../world.json). API компонента: [SCR_CampaignSourceBaseComponent](https://community.bistudio.com/wikidata/external-data/arma-reforger/ArmaReforgerScriptAPIPublic/interfaceSCR__CampaignSourceBaseComponent.html).

## Таблица

| Название | Пополнение за цикл, припасы | Пополнение, мин. |
| --- | --- | --- |
{ROWS}
'@
$harbors = $harbors.Replace('{COUNT}', [string]$saved.count).Replace('{HARBORS}', [string]$harborCount).Replace('{AIRFIELDS}', [string]$airfieldCount).
    Replace('{VERSION}', $saved.gameVersion).Replace('CTI_Campaign_HQC_Eden.ent', "$($saved.scenarioKey).ent").
    Replace('{REVISION}', $saved.revisionId).Replace('{ROWS}', ($rows -join "`n"))
Write-NewFile (Join-Path $output 'Supplies\Harbors.md') $harbors
$index = @'
# Припасы

Статус раздела: **partial**. Подготовлена таблица [баз-источников припасов](Supplies/Harbors.md): **{COUNT}** точек с количеством и интервалом пополнения.

Все базы с `SCR_CampaignSourceBaseComponent` включены в эту выборку. Склады, тайники, начальные припасы, вместимость и условия генерации ещё не разобраны; отсутствие их таблиц не означает отсутствие таких объектов в мире.

Данные таблицы: [Harbors.json](Supplies/Harbors.json). Индекс разделов: [data.json](data.json). Метаданные: [world.json](world.json).
'@
Write-NewFile (Join-Path $output 'Supplies.md') ($index.Replace('{COUNT}', [string]$saved.count))
Write-Output "Prepared partial snapshot $snapshotId with $($records.Count) source bases in $output"
