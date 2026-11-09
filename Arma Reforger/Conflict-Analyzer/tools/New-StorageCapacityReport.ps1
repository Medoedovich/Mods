<# Normalize physical container composition below one selected source base.
   Virtual views retain provenance but never contribute to physical capacity. #>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$ReportPath,
    [Parameter(Mandatory = $true)][string]$OutputDirectory,
    [ValidatePattern('^r[0-9]{4}$')][string]$RevisionId = 'r0003',
    [Parameter(Mandatory = $true)][string]$RevisionReason,
    [string]$WorkbenchVersion
)
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$culture = [Globalization.CultureInfo]::InvariantCulture
$output = [IO.Path]::GetFullPath($OutputDirectory)
if (Test-Path -LiteralPath $output) { throw 'Output directory already exists; choose a new revision.' }
$inputBytes = [IO.File]::ReadAllBytes((Resolve-Path -LiteralPath $ReportPath).Path)
$sha = [Security.Cryptography.SHA256]::Create()
try { $inputHash = ([BitConverter]::ToString($sha.ComputeHash($inputBytes))).Replace('-', '') }
finally { $sha.Dispose() }
$native = ([Text.Encoding]::UTF8.GetString($inputBytes)).TrimStart([char]0xFEFF) | ConvertFrom-Json
if ($native.schemaVersion -ne 2 -or $native.kind -ne 'source-base-storage-capacity' -or
    $native.selection -ne 'source-base-descendant-resource-containers' -or
    !$native.editorEntityCountUnchanged -or $native.editorEntityCountBefore -ne $native.editorEntityCountAfter -or
    $native.resources.Count -ne $native.recordCount -or !$native.baseName -or !$native.baseSourceId) {
    throw 'Inconsistent targeted storage report.'
}
if ($native.gameVersion -notmatch '^\d+(\.\d+)+$' -or
    $native.worldPath -notmatch '/(?<scenario>[A-Za-z0-9_-]+)\.ent$') { throw 'Unsupported version / world path.' }
$scenarioKey = $Matches.scenario
$snapshotId = "$($native.gameVersion)/$scenarioKey/$RevisionId"
$capturedAtUTC = [DateTime]::ParseExact($native.generatedAtUTC, 'yyyy-MM-dd HH:mm:ss', $culture).ToString("yyyy-MM-dd'T'HH:mm:ss'Z'", $culture)
$nodes = @{}
foreach ($node in $native.nodes) {
    if (!$node.sourceId -or $nodes.ContainsKey($node.sourceId)) { throw 'Missing or duplicate source ID.' }
    $nodes[$node.sourceId] = $node
}
if (!$nodes.ContainsKey($native.baseSourceId) -or $nodes[$native.baseSourceId].name -cne $native.baseName) { throw 'Base node mismatch.' }
function Get-PathNodes([string]$Id) {
    $path = [Collections.Generic.List[object]]::new()
    $seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    while ($true) {
        if (!$nodes.ContainsKey($Id) -or !$seen.Add($Id) -or $seen.Count -gt 257) { throw 'Missing, cyclic or excessive hierarchy.' }
        $node = $nodes[$Id]
        $path.Insert(0, $node)
        if ($Id -eq $native.baseSourceId) { break }
        $Id = $node.parentSourceId
    }
    return $path.ToArray()
}
function Get-Label($Node) {
    if ($Node.name) { return $Node.name }
    if ($Node.prefab) { return [IO.Path]::GetFileNameWithoutExtension(($Node.prefab -replace '\\', '/')) }
    return $Node.sourceId
}
function Get-Field($Owner, [string]$Name) {
    $found = @($Owner.fields | Where-Object name -eq $Name)
    if ($found.Count -ne 1) { throw "Missing or ambiguous field: $Name" }
    return $found[0]
}
function Get-Number($Field) {
    [double]$number = 0
    if ($Field.status -ne 'resolved' -or $Field.type -notin @('SCALAR', 'INTEGER') -or
        ![double]::TryParse($Field.value, [Globalization.NumberStyles]::Float, $culture, [ref]$number) -or
        [double]::IsNaN($number) -or [double]::IsInfinity($number) -or $number -lt 0) { return $null }
    return $number
}
function Get-Origin($Field, [string]$Path) {
    return [ordered]@{
        fieldPath = $Path; field = $Field.name; method = 'BaseContainer.Get'
        rawValue = $Field.value; rawType = $Field.type; fieldStatus = $Field.status
        directOverride = [bool]$Field.directOverride
        resolution = $(if ($Field.status -ne 'resolved') { 'unknown' } elseif ($Field.directOverride) { 'override' } else { 'inherited_or_default' })
        definingResource = $null; definingResourceStatus = 'unknown'
    }
}
$records = [Collections.Generic.List[object]]::new()
$virtualViews = [Collections.Generic.List[object]]::new()
$excluded = [Collections.Generic.List[object]]::new()
$warnings = [Collections.Generic.List[string]]::new()
foreach ($warning in $native.warnings) { $warnings.Add($warning) }
$keys = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
$componentKeys = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
$incompleteGroups = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
$allowedFields = @('m_eResourceType', 'm_eStorageType', 'm_fResourceValueMax', 'm_fResourceValueCurrent')
foreach ($resource in ($native.resources | Sort-Object sourceId, componentIndex)) {
    $componentKey = "$($resource.sourceId)/$($resource.componentIndex)"
    if (!$componentKeys.Add($componentKey) -or $resource.componentClass -ne 'SCR_ResourceComponent') { throw 'Duplicate or unexpected resource component.' }
    $pathNodes = @(Get-PathNodes $resource.sourceId)
    $node = $pathNodes[-1]
    $group = if ($pathNodes.Count -gt 1) { $pathNodes[1] } else { $pathNodes[0] }
    $enabledField = Get-Field $resource 'Enabled'
    $enabled = if ($enabledField.status -eq 'resolved' -and $enabledField.value -in @('true', 'false')) { $enabledField.value -eq 'true' } else { $null }
    $disabledField = Get-Field $resource 'm_aDisabledResourceTypes'
    $suppliesEnabled = if ($disabledField.status -eq 'resolved') { '0' -notin @($disabledField.values) } else { $null }
    if ($resource.containersStatus -ne 'resolved') {
        $warnings.Add("Unknown container list: $componentKey")
        $null = $incompleteGroups.Add($group.sourceId)
    }
    foreach ($container in ($resource.containers | Sort-Object index)) {
        $key = "$componentKey/$($container.index)"
        if (!$keys.Add($key)) { throw 'Duplicate container slot.' }
        if ($container.fields.Count -ne 4 -or @($container.fields.name | Where-Object { $_ -notin $allowedFields }).Count -gt 0) { throw 'Unexpected container fields.' }
        $type = Get-Field $container 'm_eResourceType'
        $storage = Get-Field $container 'm_eStorageType'
        $max = Get-Field $container 'm_fResourceValueMax'
        $initial = Get-Field $container 'm_fResourceValueCurrent'
        $capacity = Get-Number $max
        $initialValue = Get-Number $initial
        $item = [ordered]@{
            id = $key; groupSourceId = $group.sourceId
            sourceId = $node.sourceId; parentSourceId = $node.parentSourceId
            sourceName = $node.name; label = (Get-Label $node); labelMethod = $(if ($node.name) { 'source_name' } else { 'prefab_filename_or_id' })
            prefab = $node.prefab; subscene = $node.subscene; layer = $node.layer
            positionStatus = $node.positionStatus; worldPositionMeters = @($node.worldPositionMeters)
            componentIndex = $resource.componentIndex; containerIndex = $container.index; containerClass = $container.className
            resourceType = $(if ($type.status -eq 'resolved') { $type.enumLabel } else { 'unknown' })
            storageType = $(if ($storage.status -eq 'resolved') { $storage.enumLabel } else { 'unknown' })
            componentEnabled = $enabled; suppliesEnabled = $suppliesEnabled
            capacitySupplies = $capacity; capacityStatus = $(if ($null -eq $capacity) { 'unknown' } else { 'resolved' })
            configuredInitialSupplies = $initialValue
            hierarchySourceIds = @($pathNodes.sourceId)
            provenance = [ordered]@{
                capacity = (Get-Origin $max "SCR_ResourceComponent.m_aContainers[$($container.index)].m_fResourceValueMax")
                configuredInitial = (Get-Origin $initial "SCR_ResourceComponent.m_aContainers[$($container.index)].m_fResourceValueCurrent")
                resourceType = (Get-Origin $type "SCR_ResourceComponent.m_aContainers[$($container.index)].m_eResourceType")
                storageType = (Get-Origin $storage "SCR_ResourceComponent.m_aContainers[$($container.index)].m_eStorageType")
                componentEnabled = (Get-Origin $enabledField 'SCR_ResourceComponent.Enabled')
                disabledTypes = [ordered]@{ field = $disabledField.name; values = @($disabledField.values); fieldStatus = $disabledField.status; directOverride = $disabledField.directOverride }
                containersDirectOverride = $resource.containersDirectOverride
            }
        }
        if ($type.status -ne 'resolved' -or $type.type -ne 'INTEGER' -or $type.value -ne '0' -or $type.enumLabel -ne 'SUPPLIES') {
            $item['excludedReason'] = 'not_confirmed_supplies'
            $excluded.Add([pscustomobject]$item)
            if ($type.status -ne 'resolved' -or !$type.enumLabel) {
                $warnings.Add("Unknown resource type: $key")
                $null = $incompleteGroups.Add($group.sourceId)
            }
        } elseif ($container.className -eq 'SCR_ResourceContainerVirtual') {
            $item['excludedReason'] = 'virtual_view_of_physical_storage'
            $virtualViews.Add([pscustomobject]$item)
        } elseif ($container.className -eq 'SCR_ResourceContainer') {
            $records.Add([pscustomobject]$item)
            if ($null -eq $capacity) { $warnings.Add("Unknown physical capacity: $key") }
        } else {
            $item['excludedReason'] = 'unresolved_container_class'
            $excluded.Add([pscustomobject]$item)
            $warnings.Add("Unknown container class: $key")
            $null = $incompleteGroups.Add($group.sourceId)
        }
    }
}
$groupRecords = @($records | Group-Object groupSourceId | Sort-Object Name | ForEach-Object {
    $members = @($_.Group | Sort-Object id)
    $known = @($members | Where-Object capacityStatus -eq 'resolved')
    $subtotal = [double]0
    foreach ($member in $known) { $subtotal += $member.capacitySupplies }
    $complete = $known.Count -eq $members.Count -and !$incompleteGroups.Contains($_.Name)
    [ordered]@{
        sourceId = $_.Name; parentSourceId = $nodes[$_.Name].parentSourceId
        sourceName = $nodes[$_.Name].name; label = (Get-Label $nodes[$_.Name]); prefab = $nodes[$_.Name].prefab
        physicalContainerCount = $members.Count
        capacitySupplies = $(if ($complete) { $subtotal } else { $null })
        knownCapacitySubtotalSupplies = $subtotal; capacityStatus = $(if ($complete) { 'resolved' } else { 'unknown' })
        containerIds = @($members.id)
    }
})
$knownTotal = [double]0
foreach ($item in $records) { if ($item.capacityStatus -eq 'resolved') { $knownTotal += $item.capacitySupplies } }
$completeCapacity = @($records | Where-Object capacityStatus -ne 'resolved').Count -eq 0 -and
    @($warnings | Where-Object { $_ -like 'Unknown *' -or $_ -like '*depth limit*' }).Count -eq 0
$report = [ordered]@{
    schemaVersion = 2; kind = 'source-base-storage-capacity-report'; status = 'partial'
    snapshotId = $snapshotId; baseName = $native.baseName; baseSourceId = $native.baseSourceId
    scope = 'configured_physical_supplies_containers_below_selected_base'
    unit = 'supplies'; sourceReportSha256 = $inputHash
    summary = [ordered]@{
        storageGroupCount = $groupRecords.Count; physicalContainerCount = $records.Count
        virtualViewCount = $virtualViews.Count; inspectedResourceComponentCount = $native.recordCount
        capacitySupplies = $(if ($completeCapacity) { $knownTotal } else { $null })
        knownCapacitySubtotalSupplies = $knownTotal; capacityStatus = $(if ($completeCapacity) { 'resolved' } else { 'unknown' })
    }
    storageGroups = $groupRecords; containers = @($records.ToArray()); virtualViews = @($virtualViews.ToArray())
    excludedContainers = @($excluded.ToArray()); warnings = @($warnings.ToArray())
}
$world = [ordered]@{
    schemaVersion = 2; snapshotId = $snapshotId; revisionId = $RevisionId; revisionReason = $RevisionReason
    status = 'partial'; gameVersion = $native.gameVersion; gameChannel = $null; gameChannelStatus = 'unknown'
    scenarioKey = $scenarioKey; worldPath = $native.worldPath; worldGuid = $null; worldGuidStatus = 'unknown'
    capturedAtUTC = $capturedAtUTC; workbenchVersion = $WorkbenchVersion
    workbenchVersionStatus = $(if ($WorkbenchVersion) { 'provided_by_operator' } else { 'unknown' })
    analyzerVersion = $native.analyzerVersion; normalizerVersion = 'storage-capacity-0.1'; sourceReportSha256 = $inputHash
    addons = [ordered]@{ inventoryStatus = 'unknown'; completeLoadedInventory = $null }
    selectedBaseName = $native.baseName; subscenes = @($native.subscenes)
    identityStatus = 'provisional_editor_ids'; warnings = @($warnings.ToArray())
}
$index = [ordered]@{
    schemaVersion = 2; kind = 'conflict-world-index'; snapshotId = $snapshotId; status = 'partial'
    sections = [ordered]@{
        storageCapacity = [ordered]@{ status = 'partial'; scope = 'one_selected_source_base'; analyzedBaseCount = 1; reportData = 'Supplies/StorageCapacity.json'; report = 'Supplies/StorageCapacity.md' }
        sourceBaseIncome = [ordered]@{ status = 'not_analyzed'; reportData = $null }
        aiGroups = [ordered]@{ status = 'not_analyzed'; reportData = $null }
        startingBases = [ordered]@{ status = 'not_analyzed'; reportData = $null }
        vehicleSpawns = [ordered]@{ status = 'not_analyzed'; reportData = $null }
        locations = [ordered]@{ status = 'not_analyzed'; reportData = $null }
    }
}
# Every check above happens before creating the output directory.
$null = New-Item -ItemType Directory -Path (Join-Path $output 'Supplies')
function Write-Json([string]$RelativePath, $Value) {
    [IO.File]::WriteAllText((Join-Path $output $RelativePath), (($Value | ConvertTo-Json -Depth 40) + "`n"), [Text.UTF8Encoding]::new($false))
}
Write-Json 'world.json' $world
Write-Json 'data.json' $index
Write-Json 'Supplies/StorageCapacity.json' $report
# Generate the human-readable table from the saved canonical JSON.
$saved = Get-Content -LiteralPath (Join-Path $output 'Supplies/StorageCapacity.json') -Raw | ConvertFrom-Json
function Format-Number($Number) { if ($null -eq $Number) { return 'unknown' }; return ([double]$Number).ToString('0.######', $culture) }
function Escape-Cell($Value) { return ([string]$Value).Replace('|', '\|').Replace("`r", ' ').Replace("`n", ' ') }
$lines = [Collections.Generic.List[string]]::new()
$lines.Add("# Вместимость хранилищ — $($saved.baseName)")
$lines.Add(''); $lines.Add('## Summary'); $lines.Add('')
$lines.Add("Версия игры: **$($native.gameVersion)**. Проверена одна база; весь снимок имеет статус **partial**.")
$lines.Add('')
$lines.Add("Хранилищ: **$($saved.summary.storageGroupCount)**. Физических контейнеров: **$($saved.summary.physicalContainerCount)**. Суммарная настроенная вместимость: **$(Format-Number $saved.summary.capacitySupplies) припасов**.")
$lines.Add(''); $lines.Add('## Откуда берутся данные'); $lines.Add('')
$lines.Add('- Связь база → хранилище → контейнер: родительская иерархия `IEntitySource`, включая вложенные prefab.')
$lines.Add('- Состав: `SCR_ResourceComponent.m_aContainers`; учитываются физические `SCR_ResourceContainer` с `m_eResourceType=SUPPLIES`.')
$lines.Add('- Вместимость: `m_fResourceValueMax`. Начальное количество: `m_fResourceValueCurrent`, отдельное поле конфигурации.')
$lines.Add('- Сумма: вместимости уникальных слотов `(sourceId, componentIndex, containerIndex)`. Виртуальные `SCR_ResourceContainerVirtual` не прибавляются повторно.')
$lines.Add('- Название: source name; если пусто — имя файла prefab. Автоматические подписи редактора с суффиксом экземпляра этим API не получены.')
$lines.Add(''); $lines.Add('## Хранилища и состав'); $lines.Add('')
$lines.Add('| Хранилище | Состав, припасы | Контейнеров | Вместимость, припасы |')
$lines.Add('| --- | --- | ---: | ---: |')
foreach ($group in $saved.storageGroups) {
    $members = @($saved.containers | Where-Object groupSourceId -eq $group.sourceId)
    $composition = @($members | Group-Object capacitySupplies | Sort-Object { if (!$_.Name) { [double]::PositiveInfinity } else { [double]$_.Name } } -Descending | ForEach-Object { "$($_.Count) × $(Format-Number $_.Group[0].capacitySupplies)" }) -join ' + '
    $lines.Add("| $(Escape-Cell $group.label) | $composition | $($group.physicalContainerCount) | $(Format-Number $group.capacitySupplies) |")
}
$lines.Add(''); $lines.Add('## Физические контейнеры'); $lines.Add('')
$lines.Add('| Хранилище | Контейнер (prefab) | Source ID / компонент / слот | Вместимость, припасы | Начальные припасы в конфиге |')
$lines.Add('| --- | --- | --- | ---: | ---: |')
foreach ($container in $saved.containers) {
    $group = @($saved.storageGroups | Where-Object sourceId -eq $container.groupSourceId)[0]
    $lines.Add("| $(Escape-Cell $group.label) | $(Escape-Cell $container.label) | $(Escape-Cell $container.id) | $(Format-Number $container.capacitySupplies) | $(Format-Number $container.configuredInitialSupplies) |")
}
$lines.Add(''); $lines.Add('## Ограничения'); $lines.Add('')
$lines.Add("Виртуальных представлений исключено из суммы: **$($saved.summary.virtualViewCount)**. Компоненты базы и указателей без физических контейнеров не являются дополнительными хранилищами.")
$lines.Add('')
$lines.Add('Это вместимость заданных в мире физических контейнеров под выбранной базой. Динамически построенные склады, соседние объекты вне этой иерархии, runtime-связи ресурсной сети и изменение состояния при запуске не исследованы. Отключённые контейнеры сохраняются как конфигурация, их состояние указано в JSON.')
$lines.Add('')
$lines.Add('Значения могут наследоваться или быть заданы по умолчанию. Точный ресурс определения поля пока unknown; ближайший prefab не подменяет его. JSON сохраняет исходные поля и признаки override.')
$lines.Add(''); $lines.Add('Данные: [StorageCapacity.json](StorageCapacity.json).')
[IO.File]::WriteAllText((Join-Path $output 'Supplies/StorageCapacity.md'), (($lines -join "`n") + "`n"), [Text.UTF8Encoding]::new($false))
$suppliesIndex = "# Припасы`n`nРевизия ``$RevisionId``: исследована вместимость одной базы ``$($native.baseName)``. Статус **partial**.`n`n- [Хранилища и состав контейнеров](Supplies/StorageCapacity.md).`n- [Машиночитаемые данные](Supplies/StorageCapacity.json).`n`nДоход source base в этой ревизии не пересобирался; предыдущая проверенная выборка находится в ``r0002``. Полная иерархия ``Supply Depots → Harbors / Anothers`` остаётся ближайшей задачей TODO.`n"
[IO.File]::WriteAllText((Join-Path $output 'Supplies.md'), $suppliesIndex, [Text.UTF8Encoding]::new($false))
[pscustomobject]@{ OutputDirectory = $output; Base = $native.baseName; Groups = $groupRecords.Count; PhysicalContainers = $records.Count; CapacitySupplies = $report.summary.capacitySupplies; SourceSha256 = $inputHash }
