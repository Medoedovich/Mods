<# Normalize source bases from native diagnostics and generate a partial report.
   Prepare in exports/ first; review before adding an immutable archive revision. #>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$DiagnosticsPath,
    [Parameter(Mandatory = $true)][string]$OutputDirectory,
    [ValidatePattern('^r[0-9]{4}$')][string]$RevisionId = 'r0001',
    [string]$WorkbenchVersion
)
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$culture = [Globalization.CultureInfo]::InvariantCulture
$componentClass = 'SCR_CampaignSourceBaseComponent'
$normalizerVersion = 'supply-sources-0.1'
$output = [IO.Path]::GetFullPath($OutputDirectory)
if (Test-Path -LiteralPath $output) { throw 'Output directory already exists; choose a new snapshot revision.' }

# Hash exactly the bytes that are parsed, even if the input changes concurrently.
$inputBytes = [IO.File]::ReadAllBytes((Resolve-Path -LiteralPath $DiagnosticsPath).Path)
$sha = [Security.Cryptography.SHA256]::Create()
try { $inputHash = ([BitConverter]::ToString($sha.ComputeHash($inputBytes))).Replace('-', '') }
finally { $sha.Dispose() }
$diagnostics = ([Text.Encoding]::UTF8.GetString($inputBytes)).TrimStart([char]0xFEFF) | ConvertFrom-Json
if ($diagnostics.schemaVersion -ne 1 -or $diagnostics.kind -ne 'editor-source-diagnostics' -or
    $diagnostics.entities.Count -ne $diagnostics.diagnosticEntityCount -or
    !$diagnostics.editorEntityCountUnchanged) { throw 'Inconsistent native diagnostic report.' }
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
    if ($fields.Count -ne 1 -or $fields[0].status -ne 'resolved') {
        throw "Required field '$Name' is missing, ambiguous or unresolved."
    }
    return $fields[0]
}
function Get-IntegerValue($Field) {
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
        directOverride = [bool]$Field.directOverride
        resolution = $(if ($Field.directOverride) { 'override' } else { 'inherited_or_default' })
        definingResource = $null
        definingResourceStatus = 'unknown'
    }
}

$selected = @($diagnostics.entities | Where-Object { @($_.components | Where-Object className -eq $componentClass).Count -gt 0 })
$keys = New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal)
$records = @($selected | Sort-Object name, sourceId | ForEach-Object {
    $entity = $_
    $components = @($entity.components | Where-Object className -eq $componentClass)
    if ($components.Count -ne 1) { throw 'Ambiguous source-base component.' }
    $key = "$($entity.subscene)/$($entity.layer)/$($entity.sourceId)"
    if (!$entity.sourceId -or !$keys.Add($key)) { throw "Missing or duplicate source key: $key" }
    if ($entity.positionStatus -ne 'resolved' -or $entity.worldPosition.Count -ne 3) {
        throw "Unresolved world position: $key"
    }
    $income = Get-RequiredField $components[0] 'm_iRegularSuppliesIncomeBase'
    $interval = Get-RequiredField $components[0] 'm_iSuppliesArrivalInterval'
    $amount = Get-IntegerValue $income
    $seconds = Get-IntegerValue $interval
    if ($amount -lt 0 -or $seconds -le 0) { throw "Fallback / disabled income settings require separate analysis: $key" }
    $baseNames = @($components[0].fields | Where-Object { $_.name -eq 'm_sBaseName' -and $_.status -eq 'resolved' })
    $baseNameKey = if ($baseNames.Count -eq 1) { $baseNames[0].value } else { $null }
    [ordered]@{
        id = $key
        source = [ordered]@{
            sourceId = $entity.sourceId
            parentSourceId = $entity.parentSourceId
            parentSourceIds = @($entity.parentSourceIds)
            subscene = $entity.subscene
            layer = $entity.layer
            className = $entity.className
            nearestPrefab = $entity.prefab
            worldPositionMeters = @($entity.worldPosition)
        }
        name = $entity.name
        baseNameLocalizationKey = $baseNameKey
        location = [ordered]@{ status = 'not_analyzed'; name = $null }
        supplyIncomePerCycle = $amount
        arrivalIntervalSeconds = $seconds
        arrivalIntervalMinutes = ([decimal]$seconds / 60)
        provenance = [ordered]@{
            name = [ordered]@{ field = 'entity.name'; method = 'IEntitySource.GetName'; resolution = 'source' }
            baseNameLocalizationKey = $(if ($baseNames.Count -eq 1) { Get-FieldOrigin $baseNames[0] } else { $null })
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
    schemaVersion = 1
    kind = 'conflict-world-snapshot'
    snapshotId = $snapshotId
    status = 'partial'
    gameVersion = $diagnostics.gameVersion
    scenarioKey = $scenarioKey
    revisionId = $RevisionId
    capturedAtUTC = $capturedAtUTC
    diagnosticAnalyzerVersion = $diagnostics.analyzerVersion
    normalizerVersion = $normalizerVersion
    inputSha256 = $inputHash
    aiGroups = [ordered]@{ status = 'not_analyzed'; records = $null }
    supplies = [ordered]@{
        status = 'partial'
        sourceBases = [ordered]@{
            status = 'extracted'
            selection = "entities with $componentClass"
            count = $records.Count
            units = [ordered]@{ supplyIncomePerCycle = 'supplies'; arrivalIntervalSeconds = 'seconds'; arrivalIntervalMinutes = 'minutes' }
            records = $records
        }
        storagePoints = [ordered]@{ status = 'not_analyzed'; records = $null }
    }
    startingBases = [ordered]@{ status = 'not_analyzed'; records = $null }
    vehicleSpawns = [ordered]@{ status = 'not_analyzed'; records = $null }
    warnings = $warnings
}
$world = [ordered]@{
    schemaVersion = 1
    snapshotId = $snapshotId
    revisionId = $RevisionId
    revisionReason = 'Initial partial source-base snapshot'
    scenarioKey = $scenarioKey
    worldPath = $diagnostics.worldPath
    worldResourceGuid = $null
    worldResourceGuidStatus = 'unknown'
    gameVersion = $diagnostics.gameVersion
    gameChannel = $null
    workbenchVersion = $(if ($WorkbenchVersion) { $WorkbenchVersion } else { $null })
    workbenchVersionStatus = $(if ($WorkbenchVersion) { 'provided_by_operator' } else { 'unknown' })
    capturedAtUTC = $capturedAtUTC
    mode = 'editor-source-diagnostics-log'
    status = 'partial'
    diagnosticAnalyzerVersion = $diagnostics.analyzerVersion
    normalizerVersion = $normalizerVersion
    input = [ordered]@{ fileName = [IO.Path]::GetFileName($DiagnosticsPath); sha256 = $inputHash; schemaVersion = $diagnostics.schemaVersion }
    subsceneCount = $diagnostics.subsceneCount
    editorEntityCountUnchanged = $diagnostics.editorEntityCountUnchanged
    diagnosticWarnings = @($diagnostics.warnings)
    warnings = $warnings
}

function Write-NewFile([string]$Path, [string]$Content) {
    $stream = [IO.File]::Open($Path, [IO.FileMode]::CreateNew, [IO.FileAccess]::Write, [IO.FileShare]::None)
    $writer = New-Object IO.StreamWriter($stream, (New-Object Text.UTF8Encoding($false)))
    try { $writer.Write($Content.Replace("`r`n", "`n").TrimEnd() + "`n") } finally { $writer.Dispose() }
}
# Complete validation precedes writing. This tool never edits the source world or a version manifest.
$null = New-Item -ItemType Directory -Path (Join-Path $output 'Supplies')
Write-NewFile (Join-Path $output 'data.json') ($data | ConvertTo-Json -Depth 15)
Write-NewFile (Join-Path $output 'world.json') ($world | ConvertTo-Json -Depth 10)

# Markdown uses the saved normalized JSON, not a second extraction from diagnostics.
$saved = Get-Content -LiteralPath (Join-Path $output 'data.json') -Raw -Encoding UTF8 | ConvertFrom-Json
$harborCount = @($saved.supplies.sourceBases.records | Where-Object { $_.source.nearestPrefab -like '*ConflictSourceBase_T*Harbor.et' }).Count
$airfieldCount = @($saved.supplies.sourceBases.records | Where-Object { $_.source.nearestPrefab -like '*ConflictSourceBase_Airfield.et' }).Count
function Escape-Cell([string]$Value) { return $Value.Replace('\', '\\').Replace('|', '\|').Replace("`r", ' ').Replace("`n", ' ') }
$rows = @($saved.supplies.sourceBases.records | ForEach-Object {
    $minutes = ([decimal]$_.arrivalIntervalMinutes).ToString('0.############################', $culture)
    '| {0} | {1} | {2} |' -f (Escape-Cell $_.name), $_.supplyIncomePerCycle, $minutes
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
| Название | `entities[].name` нативной диагностики, полученное через `IEntitySource.GetName()` — имя editor source. Игровое название ближайшей локации пока не определено. |
| Пополнение за цикл, припасы | `SCR_CampaignSourceBaseComponent.m_iRegularSuppliesIncomeBase`, прочитанное через `BaseContainer.Get`. В JSON: `supplyIncomePerCycle`. |
| Пополнение, мин. | `SCR_CampaignSourceBaseComponent.m_iSuppliesArrivalInterval`, прочитанное через `BaseContainer.Get` в секундах; минуты = секунды / 60. В JSON сохраняются `arrivalIntervalSeconds` и `arrivalIntervalMinutes`. |

Для каждой записи сохранены source ID, слой, ближайший prefab и происхождение полей. Признак `directOverride` отличает прямое переопределение от унаследованного значения или значения по умолчанию. Точный ресурс, задающий унаследованное значение, ещё не установлен. Пополнение за цикл описывает настройку дохода; вместимость хранилища и условия работы генератора требуют отдельного анализа.

Источник таблицы: [data.json](../data.json). Метаданные и ограничения: [world.json](../world.json). API компонента: [SCR_CampaignSourceBaseComponent](https://community.bistudio.com/wikidata/external-data/arma-reforger/ArmaReforgerScriptAPIPublic/interfaceSCR__CampaignSourceBaseComponent.html).

## Таблица

| Название | Пополнение за цикл, припасы | Пополнение, мин. |
| --- | --- | --- |
{ROWS}
'@
$harbors = $harbors.Replace('{COUNT}', [string]$saved.supplies.sourceBases.count).Replace('{HARBORS}', [string]$harborCount).Replace('{AIRFIELDS}', [string]$airfieldCount).
    Replace('{VERSION}', $saved.gameVersion).Replace('CTI_Campaign_HQC_Eden.ent', "$($saved.scenarioKey).ent").
    Replace('{REVISION}', $saved.revisionId).Replace('{ROWS}', ($rows -join "`n"))
Write-NewFile (Join-Path $output 'Supplies\Harbors.md') $harbors
$index = @'
# Припасы

Статус раздела: **partial**. Подготовлена таблица [баз-источников припасов](Supplies/Harbors.md): **{COUNT}** точек с количеством и интервалом пополнения.

Все базы с `SCR_CampaignSourceBaseComponent` включены в эту выборку. Склады, тайники, начальные припасы, вместимость и условия генерации ещё не разобраны; отсутствие их таблиц не означает отсутствие таких объектов в мире.

Данные: [data.json](data.json). Метаданные: [world.json](world.json).
'@
Write-NewFile (Join-Path $output 'Supplies.md') ($index.Replace('{COUNT}', [string]$saved.supplies.sourceBases.count))
Write-Output "Prepared partial snapshot $snapshotId with $($records.Count) source bases in $output"
