<# Combine verified source-base income with a fresh all-base container inventory.
   Preserve the exact capture time and hash of each input; do not guess ownership. #>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$CapacityReportPath,
    [Parameter(Mandatory = $true)][string]$SourceBasesReportPath,
    [Parameter(Mandatory = $true)][string]$OutputDirectory,
    [ValidatePattern('^r[0-9]{4}$')][string]$RevisionId = 'r0004',
    [Parameter(Mandatory = $true)][string]$RevisionReason,
    [string]$WorkbenchVersion
)
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$culture = [Globalization.CultureInfo]::InvariantCulture
$output = [IO.Path]::GetFullPath($OutputDirectory)
if (Test-Path -LiteralPath $output) { throw 'Output directory already exists; choose a new revision.' }
function Read-Input([string]$Path) {
    $bytes = [IO.File]::ReadAllBytes((Resolve-Path -LiteralPath $Path).Path)
    $sha = [Security.Cryptography.SHA256]::Create()
    try { $hash = ([BitConverter]::ToString($sha.ComputeHash($bytes))).Replace('-', '') }
    finally { $sha.Dispose() }
    [pscustomobject]@{ hash = $hash; value = ([Text.Encoding]::UTF8.GetString($bytes)).TrimStart([char]0xFEFF) | ConvertFrom-Json }
}
$capacityInput = Read-Input $CapacityReportPath
$incomeInput = Read-Input $SourceBasesReportPath
$native = $capacityInput.value
$income = $incomeInput.value
$originalIncomeOrigin = [ordered]@{ snapshotId = $income.snapshotId; reportSha256 = $incomeInput.hash; capturedAtUTC = $income.capturedAtUTC }
if ($native.schemaVersion -ne 2 -or $native.kind -ne 'source-bases-storage-capacity' -or
    $native.selection -ne 'all-source-base-descendant-resource-containers' -or
    $native.baseCount -le 0 -or $native.bases.Count -ne $native.baseCount -or
    ($native.bases | Measure-Object recordCount -Sum).Sum -ne $native.recordCount -or
    !$native.editorEntityCountUnchanged -or $native.editorEntityCountBefore -ne $native.editorEntityCountAfter) { throw 'Invalid native batch inventory.' }
if ($income.schemaVersion -ne 2 -or $income.kind -ne 'supply-source-bases-report' -or
    $income.count -ne $income.records.Count -or $income.count -ne $native.baseCount -or
    $income.gameVersion -ne $native.gameVersion -or $native.worldPath -notmatch '/(?<scenario>[A-Za-z0-9_-]+)\.ent$' -or
    $income.scenarioKey -ne $Matches.scenario) { throw 'Incompatible income and storage inputs.' }
$scenarioKey = $income.scenarioKey
$snapshotId = "$($native.gameVersion)/$scenarioKey/$RevisionId"
$capturedAtUTC = [DateTime]::ParseExact($native.generatedAtUTC, 'yyyy-MM-dd HH:mm:ss', $culture).ToString("yyyy-MM-dd'T'HH:mm:ss'Z'", $culture)
$sourceRecords = @{}
foreach ($record in $income.records) {
    if (!$record.source.sourceId -or $sourceRecords.ContainsKey($record.source.sourceId)) { throw 'Missing or ambiguous source-base ID.' }
    $sourceRecords[$record.source.sourceId] = $record
}
$baseIds = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach ($base in $native.bases) {
    if (!$baseIds.Add($base.baseSourceId) -or !$sourceRecords.ContainsKey($base.baseSourceId) -or
        $base.resources.Count -ne $base.recordCount) { throw 'Missing, duplicate or unmatched base.' }
    $record = $sourceRecords[$base.baseSourceId]
    $rootNodes = @($base.nodes | Where-Object sourceId -eq $base.baseSourceId)
    if ($rootNodes.Count -ne 1 -or $base.baseName -cne $record.name -or
        $rootNodes[0].prefab -cne $record.source.nearestPrefab -or
        $rootNodes[0].subscene -ne $record.source.subscene -or $rootNodes[0].layer -cne $record.source.layer) { throw 'Base origin changed or could not be matched.' }
}
$singleBuilder = Join-Path $PSScriptRoot 'New-StorageCapacityReport.ps1'
if (!(Test-Path -LiteralPath $singleBuilder)) { throw 'Single-base normalizer is required beside this tool.' }
$scratchRoot = [IO.Path]::GetFullPath([IO.Path]::GetTempPath()).TrimEnd([IO.Path]::DirectorySeparatorChar)
$scratchName = 'ME_CA_AllCapacity_' + [Guid]::NewGuid().ToString('N')
$scratch = [IO.Path]::GetFullPath((Join-Path $scratchRoot $scratchName))
if (!$scratch.StartsWith($scratchRoot + [IO.Path]::DirectorySeparatorChar, [StringComparison]::OrdinalIgnoreCase)) { throw 'Invalid scratch directory.' }
$null = New-Item -ItemType Directory -Path $scratch
try {
    $bases = [Collections.Generic.List[object]]::new()
    $slots = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $baseIndex = 0
    foreach ($base in ($native.bases | Sort-Object baseName, baseSourceId)) {
        $wrapped = [ordered]@{
            schemaVersion = 2; kind = 'source-base-storage-capacity'; selection = 'source-base-descendant-resource-containers'
            analyzerVersion = $native.analyzerVersion; status = 'partial'
            worldPath = $native.worldPath; gameVersion = $native.gameVersion; generatedAtUTC = $native.generatedAtUTC
            editorEntityCountBefore = $native.editorEntityCountBefore; editorEntityCountAfter = $native.editorEntityCountAfter
            editorEntityCountUnchanged = $native.editorEntityCountUnchanged; subscenes = $native.subscenes
            baseName = $base.baseName; baseSourceId = $base.baseSourceId; recordCount = $base.recordCount
            nodes = $base.nodes; resources = $base.resources; warnings = @($native.warnings) + @($base.warnings)
        }
        $sectionInput = Join-Path $scratch "$baseIndex.json"
        [IO.File]::WriteAllText($sectionInput, ($wrapped | ConvertTo-Json -Depth 40), [Text.UTF8Encoding]::new($false))
        $sectionOutput = Join-Path $scratch "$baseIndex"
        & $singleBuilder -ReportPath $sectionInput -OutputDirectory $sectionOutput -RevisionId $RevisionId -RevisionReason $RevisionReason -WorkbenchVersion $WorkbenchVersion | Out-Null
        $normalized = Get-Content -LiteralPath (Join-Path $sectionOutput 'Supplies/StorageCapacity.json') -Raw | ConvertFrom-Json
        $normalized.sourceReportSha256 = $capacityInput.hash
        $normalized | Add-Member -NotePropertyName inputOrigin -NotePropertyValue 'section_of_native_all_source_bases_inventory'
        foreach ($item in @($normalized.containers) + @($normalized.virtualViews) + @($normalized.excludedContainers)) {
            if (!$slots.Add($item.id)) { throw 'A container slot belongs to more than one base; ownership needs resolution.' }
        }
        # Empty descendant inventory proves only that this hierarchy has no physical storage.
        # Detached caches and grid links can still exist, so do not report zero base capacity.
        if ($normalized.summary.physicalContainerCount -eq 0) {
            $normalized.summary.capacitySupplies = $null
            $normalized.summary.capacityStatus = 'unknown'
            $normalized.warnings += 'Unknown base capacity: no physical descendant containers; detached storage ownership remains unresolved.'
        }
        $record = $sourceRecords[$base.baseSourceId]
        $record | Add-Member -NotePropertyName storage -NotePropertyValue ([ordered]@{
            scope = 'configured_physical_descendant_storage'; unit = 'supplies'
            capacitySupplies = $normalized.summary.capacitySupplies; capacityStatus = $normalized.summary.capacityStatus
            knownCapacitySubtotalSupplies = $normalized.summary.knownCapacitySubtotalSupplies
            storageGroupCount = $normalized.summary.storageGroupCount; physicalContainerCount = $normalized.summary.physicalContainerCount
            detailsFile = 'StorageCapacity.json'; detailsBaseSourceId = $base.baseSourceId
            capturedAtUTC = $capturedAtUTC; sourceReportSha256 = $capacityInput.hash
        })
        $bases.Add($normalized)
        $baseIndex++
    }
    $knownBases = @($bases | Where-Object { $_.summary.capacityStatus -eq 'resolved' })
    $unknownBases = @($bases | Where-Object { $_.summary.capacityStatus -ne 'resolved' })
    $physicalCount = ($bases | ForEach-Object { $_.summary.physicalContainerCount } | Measure-Object -Sum).Sum
    $groupCount = ($bases | ForEach-Object { $_.summary.storageGroupCount } | Measure-Object -Sum).Sum
    $virtualCount = ($bases | ForEach-Object { $_.summary.virtualViewCount } | Measure-Object -Sum).Sum
    $knownSubtotal = ($bases | ForEach-Object { $_.summary.knownCapacitySubtotalSupplies } | Measure-Object -Sum).Sum
    $storage = [ordered]@{
        schemaVersion = 2; kind = 'source-bases-storage-capacity-report'; snapshotId = $snapshotId; status = 'partial'
        gameVersion = $native.gameVersion; scenarioKey = $scenarioKey; capturedAtUTC = $capturedAtUTC
        analyzerVersion = $native.analyzerVersion; normalizerVersion = 'all-source-capacity-0.1'; sourceReportSha256 = $capacityInput.hash
        scope = 'configured_physical_descendant_storage_of_all_source_bases'; count = $bases.Count
        summary = [ordered]@{
            analyzedBaseCount = $bases.Count; knownCapacityBaseCount = $knownBases.Count; unknownCapacityBaseCount = $unknownBases.Count
            storageGroupCount = $groupCount; physicalContainerCount = $physicalCount; virtualViewCount = $virtualCount
            capacitySupplies = $(if ($unknownBases.Count -eq 0) { $knownSubtotal } else { $null })
            capacityStatus = $(if ($unknownBases.Count -eq 0) { 'resolved' } else { 'unknown' }); knownCapacitySubtotalSupplies = $knownSubtotal
        }
        bases = @($bases.ToArray())
        warnings = @('Configured descendant capacity is not a verified complete runtime grid capacity.', 'Detached nearby storage is not assigned by distance alone.')
    }
    $income.snapshotId = $snapshotId; $income.revisionId = $RevisionId
    $income.normalizerVersion = 'source-bases-with-capacity-0.1'
    # Save the original income capture separately from the newly read capacity capture.
    $income | Add-Member -NotePropertyName incomeOrigin -NotePropertyValue $originalIncomeOrigin
    $income | Add-Member -NotePropertyName storageCapturedAtUTC -NotePropertyValue $capturedAtUTC
    $income.units | Add-Member -NotePropertyName storageCapacitySupplies -NotePropertyValue 'supplies'
    $income.warnings = @('Income values retain their verified earlier capture; capacity was read in a new Workbench run of the same game version.', 'Capacity counts physical descendant containers; virtual views are excluded. Detached cache ownership and runtime grid membership remain unresolved.')
    $world = [ordered]@{
        schemaVersion = 2; snapshotId = $snapshotId; revisionId = $RevisionId; revisionReason = $RevisionReason; status = 'partial'
        gameVersion = $native.gameVersion; scenarioKey = $scenarioKey; worldPath = $native.worldPath
        worldResourceGuid = $null; worldResourceGuidStatus = 'unknown'; gameChannel = $null
        capturedAtUTC = $capturedAtUTC; workbenchVersion = $WorkbenchVersion; workbenchVersionStatus = $(if ($WorkbenchVersion) { 'provided_by_operator' } else { 'unknown' })
        analyzerVersion = $native.analyzerVersion; normalizerVersion = 'all-source-capacity-0.1'; subscenes = $native.subscenes
        editorEntityCountUnchanged = $native.editorEntityCountUnchanged
        identityStatus = 'provisional_editor_ids'; addons = [ordered]@{ inventoryStatus = 'unknown'; completeLoadedInventory = $null }
        inputs = [ordered]@{ capacity = [ordered]@{ sha256 = $capacityInput.hash; kind = $native.kind; capturedAtUTC = $capturedAtUTC }; income = $income.incomeOrigin }
        warnings = $income.warnings
    }
    $index = [ordered]@{
        schemaVersion = 2; kind = 'conflict-world-index'; snapshotId = $snapshotId; status = 'partial'; worldMetadata = 'world.json'
        sections = [ordered]@{
            supplies = [ordered]@{ status = 'partial'; sourceBases = [ordered]@{ count = $income.count; path = 'Supplies/Harbors.json'; table = 'Supplies/Harbors.md' }; storageCapacity = [ordered]@{ path = 'Supplies/StorageCapacity.json'; table = 'Supplies/StorageCapacity.md'; analyzedBaseCount = $bases.Count } }
            aiGroups = [ordered]@{ status = 'not_analyzed'; path = $null }; startingBases = [ordered]@{ status = 'not_analyzed'; path = $null }
            vehicleSpawns = [ordered]@{ status = 'not_analyzed'; path = $null }; locations = [ordered]@{ status = 'not_analyzed'; path = $null }
        }
    }
    $null = New-Item -ItemType Directory -Path (Join-Path $output 'Supplies')
    function Write-Json([string]$Path, $Value) { [IO.File]::WriteAllText((Join-Path $output $Path), (($Value | ConvertTo-Json -Depth 50) + "`n"), [Text.UTF8Encoding]::new($false)) }
    Write-Json 'world.json' $world; Write-Json 'data.json' $index
    Write-Json 'Supplies/Harbors.json' $income; Write-Json 'Supplies/StorageCapacity.json' $storage
    function Number($Value) { if ($null -eq $Value) { return 'unknown' }; return ([double]$Value).ToString('0.######', $culture) }
    $saved = Get-Content -LiteralPath (Join-Path $output 'Supplies/Harbors.json') -Raw | ConvertFrom-Json
    $lines = [Collections.Generic.List[string]]::new()
    $lines.Add('# Базы-источники припасов'); $lines.Add(''); $lines.Add('## Summary'); $lines.Add('')
    $lines.Add("Всего точек: **$($saved.count)**. Игра **$($saved.gameVersion)**, мир ``$scenarioKey.ent``, ревизия ``$RevisionId``. Статус **partial**.")
    $harborCount = @($saved.records | Where-Object { $_.source.nearestPrefab -like '*ConflictSourceBase_T*Harbor.et' }).Count
    $airfieldCount = @($saved.records | Where-Object { $_.source.nearestPrefab -like '*ConflictSourceBase_Airfield.et' }).Count
    $lines.Add(''); $lines.Add("Из них портов: **$harborCount**, аэропортов: **$airfieldCount**.")
    $lines.Add(''); $lines.Add("Вместимость вложенных хранилищ определена у **$($knownBases.Count)** точек; у **$($unknownBases.Count)** — ``unknown``. Найдено **$physicalCount** физических контейнеров; известный подытог — **$(Number $knownSubtotal) припасов**.")
    $lines.Add(''); $lines.Add('## Откуда берутся данные'); $lines.Add('')
    $lines.Add('| Столбец | Источник |'); $lines.Add('| --- | --- |')
    $lines.Add('| Название | `IEntitySource.GetName()` — имя source; игровое название ближайшей локации пока не определено. |')
    $lines.Add('| Пополнение за цикл, припасы | `SCR_CampaignSourceBaseComponent.m_iRegularSuppliesIncomeBase`, из проверенного отчёта r0002. |')
    $lines.Add('| Пополнение, мин. | `m_iSuppliesArrivalInterval`, исходные секунды / 60. |')
    $lines.Add('| Вместимость хранилищ, припасы | Сумма `SCR_ResourceComponent.m_aContainers[].m_fResourceValueMax` физических SUPPLIES-контейнеров в дочерней иерархии базы. `SCR_ResourceContainerVirtual` повторно не прибавляются. |')
    $lines.Add(''); $lines.Add('Доход и вместимость — разные величины. Начальное количество `m_fResourceValueCurrent` сохранено отдельно в подробном JSON. Данные о доходе и вместимости имеют отдельные время чтения и SHA-256.')
    $lines.Add(''); $lines.Add('## Таблица'); $lines.Add('')
    $lines.Add('| Название | Пополнение за цикл, припасы | Пополнение, мин. | Вместимость хранилищ, припасы |')
    $lines.Add('| --- | ---: | ---: | ---: |')
    foreach ($record in ($saved.records | Sort-Object name)) { $lines.Add("| $($record.name) | $(Number $record.supplyIncomePerCycle) | $(Number $record.arrivalIntervalMinutes) | $(Number $record.storage.capacitySupplies) |") }
    $lines.Add(''); $lines.Add('## Ограничения'); $lines.Add('')
    $lines.Add('Вместимость относится к физическим контейнерам, вложенным под source base. Соседние отдельно расположенные хранилища не приписываются базе только по расстоянию. Runtime-сеть и динамические постройки ещё не проверены.')
    $lines.Add(''); $lines.Add('Если вложенных физических контейнеров не найдено, вместимость базы показывается как `unknown`: это не доказательство отсутствия связанных хранилищ. Source ID и ближайший prefab сохраняются; точный ресурс определения унаследованных полей пока unknown.')
    $lines.Add(''); $lines.Add('Источники: [Harbors.json](Harbors.json), [состав хранилищ и контейнеров](StorageCapacity.md), [StorageCapacity.json](StorageCapacity.json), [метаданные](../world.json).')
    [IO.File]::WriteAllText((Join-Path $output 'Supplies/Harbors.md'), (($lines -join "`n") + "`n"), [Text.UTF8Encoding]::new($false))
    $savedStorage = Get-Content -LiteralPath (Join-Path $output 'Supplies/StorageCapacity.json') -Raw | ConvertFrom-Json
    $detail = [Collections.Generic.List[string]]::new()
    $detail.Add('# Вместимость всех баз-источников'); $detail.Add('')
    $detail.Add('Каждый физический контейнер сохранён отдельной записью в [StorageCapacity.json](StorageCapacity.json). Виртуальные представления исключены из сумм; начальные припасы отделены от вместимости. Связь с базой здесь определяется дочерней иерархией, без назначения по близости.'); $detail.Add('')
    foreach ($base in $savedStorage.bases) {
        $detail.Add("## $($base.baseName)"); $detail.Add('')
        $detail.Add("Вместимость: **$(Number $base.summary.capacitySupplies)** припасов. Хранилищ: **$($base.summary.storageGroupCount)**, физических контейнеров: **$($base.summary.physicalContainerCount)**.")
        $detail.Add('')
        if ($base.summary.physicalContainerCount -eq 0) { $detail.Add('Вложенные физические контейнеры не найдены; принадлежность отдельно расположенных хранилищ не разрешена. Вместимость базы unknown.'); $detail.Add(''); continue }
        $detail.Add('| Хранилище | Контейнер (prefab) | Source ID / компонент / слот | Вместимость | Начальные припасы в конфиге |')
        $detail.Add('| --- | --- | --- | ---: | ---: |')
        foreach ($item in $base.containers) { $group = @($base.storageGroups | Where-Object sourceId -eq $item.groupSourceId)[0]; $detail.Add("| $($group.label) | $($item.label) | $($item.id) | $(Number $item.capacitySupplies) | $(Number $item.configuredInitialSupplies) |") }
        $detail.Add('')
    }
    [IO.File]::WriteAllText((Join-Path $output 'Supplies/StorageCapacity.md'), (($detail -join "`n").TrimEnd([char]13, [char]10) + "`n"), [Text.UTF8Encoding]::new($false))
    [IO.File]::WriteAllText((Join-Path $output 'Supplies.md'), "# Припасы`n`nРевизия ``$RevisionId``: [$($income.count) баз-источников с вместимостью](Supplies/Harbors.md) и [состав контейнеров](Supplies/StorageCapacity.md). Частичный результат: отдельно расположенные хранилища и runtime-связи требуют проверки.`n", [Text.UTF8Encoding]::new($false))
    [pscustomobject]@{ OutputDirectory = $output; Bases = $bases.Count; KnownCapacityBases = $knownBases.Count; UnknownCapacityBases = $unknownBases.Count; PhysicalContainers = $physicalCount; KnownSubtotalSupplies = $knownSubtotal }
} finally {
    # Delete only the exact newly created helper directory inside the verified temp root.
    $resolvedScratch = [IO.Path]::GetFullPath($scratch)
    if ($resolvedScratch.StartsWith($scratchRoot + [IO.Path]::DirectorySeparatorChar, [StringComparison]::OrdinalIgnoreCase) -and [IO.Path]::GetFileName($resolvedScratch) -ceq $scratchName) {
        Remove-Item -LiteralPath $resolvedScratch -Recurse -Force
    }
}
