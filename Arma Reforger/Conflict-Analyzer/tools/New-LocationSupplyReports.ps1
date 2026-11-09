<# Build separate supply views from verified catalogs and an existing Locations snapshot.
   Preserve its links; never infer new ownership or sum repeated location rows. #>
[CmdletBinding()]
param(
    [Parameter(Mandatory=$true)][string]$LocationsReportPath,
    [Parameter(Mandatory=$true)][string]$OtherContainersReportPath,
    [Parameter(Mandatory=$true)][string]$HarborsReportPath,
    [Parameter(Mandatory=$true)][string]$OutputDirectory,
    [ValidatePattern('^r[0-9]{4}$')][string]$RevisionId='r0018',
    [Parameter(Mandatory=$true)][string]$RevisionReason
)
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
$culture=[Globalization.CultureInfo]::InvariantCulture
function Assert($condition,$message){if(!$condition){throw $message}}
function ReadInput($path){$full=(Resolve-Path -LiteralPath $path).Path;[pscustomobject]@{hash=(Get-FileHash -LiteralPath $full -Algorithm SHA256).Hash;value=(Get-Content -LiteralPath $full -Raw -Encoding utf8 | ConvertFrom-Json)}}
function Same($left,$right){($left | ConvertTo-Json -Depth 40 -Compress) -ceq ($right | ConvertTo-Json -Depth 40 -Compress)}
$output=[IO.Path]::GetFullPath($OutputDirectory)
Assert (!(Test-Path -LiteralPath $output)) 'Output directory already exists; choose a new revision.'
$locationInput=ReadInput $LocationsReportPath; $otherInput=ReadInput $OtherContainersReportPath; $harborInput=ReadInput $HarborsReportPath
$locationWorldInput=ReadInput (Join-Path (Split-Path -Parent ([IO.Path]::GetFullPath($LocationsReportPath))) 'world.json')
$locations=$locationInput.value; $other=$otherInput.value; $harbors=$harborInput.value; $locationWorld=$locationWorldInput.value
Assert ($locations.schemaVersion -eq 2 -and $locations.kind -ceq 'location-radius-catalog' -and $locations.objects.Count -eq $locations.summary.objectCount -and $locations.locations.Count -eq $locations.summary.locationCount) 'Invalid location catalog.'
Assert ($other.schemaVersion -eq 2 -and $other.kind -ceq 'other-supply-containers-report' -and $other.grouping -ceq 'root_source_ancestor' -and $other.storageGroups.Count -eq $other.summary.storageGroupCount) 'Invalid root-parent supply catalog.'
Assert ($harbors.schemaVersion -eq 2 -and $harbors.kind -ceq 'supply-source-bases-report' -and $harbors.records.Count -eq $harbors.count) 'Invalid supply-source catalog.'
foreach($source in @($other,$harbors,$locationWorld)){Assert ($source.gameVersion -ceq $locations.gameVersion -and $source.scenarioKey -ceq $locations.scenarioKey) 'Game version or scenario mismatch.'}
Assert ($locationWorld.snapshotId -ceq $locations.snapshotId) 'Location metadata mismatch.'
Assert ($otherInput.hash -ceq $locations.inputs.otherContainers.sha256 -and $other.snapshotId -ceq $locations.inputs.otherContainers.snapshotId -and $harborInput.hash -ceq $locations.inputs.harbors.sha256 -and $harbors.snapshotId -ceq $locations.inputs.harbors.snapshotId) 'Supply inputs differ from those used for Locations.'
Assert ($locations.radiusMeters -gt 0 -and $locations.distanceMethod -ceq 'horizontal_euclidean_XZ') 'Unsupported location distance policy.'
$version=$locations.gameVersion; $scenario=$locations.scenarioKey
$snapshotId="$version/$scenario/$RevisionId"; $normalizer='location-grouped-supplies-0.2'
function RevisionPath($source,$file){Assert ($source.snapshotId -match "^$([regex]::Escape($version))/$([regex]::Escape($scenario))/(r[0-9]{4})$") 'Invalid snapshot identity.';"../$($Matches[1])/$file"}
$locationPath=RevisionPath $locations 'Locations.json'; $locationWorldPath=RevisionPath $locations 'world.json'
$otherPath=RevisionPath $other 'Supplies/OtherContainers.json'; $harborPath=RevisionPath $harbors 'Supplies/Harbors.json'
$catalog=@{}; $sourceIds=@{}
foreach($obj in $locations.objects){Assert (!$catalog.ContainsKey($obj.id) -and !$sourceIds.ContainsKey($obj.sourceId)) 'Duplicate catalog object.';$catalog[$obj.id]=$obj;$sourceIds[$obj.sourceId]=$obj.id}
$allMatched=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
$locationIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
$allLinks=0
foreach($loc in $locations.locations){
    Assert ($locationIds.Add($loc.id) -and $loc.nearbyObjects.Count -eq $loc.nearbyObjectCount) 'Duplicate location or inconsistent link count.'
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($link in $loc.nearbyObjects){
        Assert ($catalog.ContainsKey($link.objectId) -and $seen.Add($link.objectId) -and $loc.matchingEligible -and $link.selectionTier -ceq $loc.matchingTier -and !$link.ownershipEstablished -and $link.method -ceq 'horizontal_radius_proximity' -and $link.distanceMeters -ge 0 -and $link.distanceMeters -le $locations.radiusMeters) 'Invalid existing location link.'
        $null=$allMatched.Add($link.objectId);$allLinks++
    }
}
$allRemaining=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach($remaining in $locations.unassignedObjects){Assert ($catalog.ContainsKey($remaining.objectId) -and $allRemaining.Add($remaining.objectId) -and !$allMatched.Contains($remaining.objectId)) 'Invalid remaining object.'}
Assert ($allMatched.Count+$allRemaining.Count -eq $catalog.Count -and $allMatched.Count -eq $locations.summary.associatedObjectCount -and $allRemaining.Count -eq $locations.summary.unassignedObjectCount -and $allLinks -eq $locations.summary.associationCount) 'Incomplete location partition.'
$warnings=@('Groups reproduce the verified Locations snapshot without additional matching.','Proximity to a map label does not establish editor parenting, base ownership or resource-grid membership.','The same object can appear at multiple locations in its selected tier; supply totals count unique source objects once.','Physical-container details and field provenance remain in the original supply snapshots.','Source data retains its original capture times; no new Workbench read was performed.')
$inputs=[ordered]@{
    locations=[ordered]@{snapshotId=$locations.snapshotId;path=$locationPath;sha256=$locationInput.hash;capturedAtUTC=$locations.capturedAtUTC;normalizerVersion=$locations.normalizerVersion}
    locationWorld=[ordered]@{path=$locationWorldPath;sha256=$locationWorldInput.hash}
    otherContainers=[ordered]@{snapshotId=$other.snapshotId;path=$otherPath;sha256=$otherInput.hash;capturedAtUTC=$other.capturedAtUTC}
    harbors=[ordered]@{snapshotId=$harbors.snapshotId;path=$harborPath;sha256=$harborInput.hash;capturedAtUTC=$harbors.capturedAtUTC;storageCapturedAtUTC=$harbors.storageCapturedAtUTC}
}
$reports=@{}
foreach($type in @('OtherContainers','Harbors')){
    $category=$(if($type -ceq 'OtherContainers'){'other_supply_parent'}else{'supply_source_base'})
    $sourceRecords=$(if($type -ceq 'OtherContainers'){@($other.storageGroups)}else{@($harbors.records)})
    $records=[Collections.Generic.List[object]]::new();$ids=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($source in $sourceRecords){
        $sourceId=$(if($type -ceq 'OtherContainers'){$source.sourceId}else{$source.source.sourceId})
        $id="$category/$sourceId"
        Assert ($catalog.ContainsKey($id) -and $ids.Add($id)) 'Supply object missing or duplicated in Locations.'
        $obj=$catalog[$id]
        $position=$(if($type -ceq 'OtherContainers'){@($source.worldPositionMeters)}else{@($source.source.worldPositionMeters)})
        $positionStatus=$(if($type -ceq 'OtherContainers'){$source.positionStatus}else{$source.source.positionStatus})
        $name=$(if($type -ceq 'OtherContainers'){$source.label}else{$source.name})
        Assert ($obj.name -ceq $name -and (Same @($obj.worldPositionMeters) @($position)) -and $obj.positionStatus -ceq $positionStatus) 'Supply name or position differs from Locations.'
        $row=[ordered]@{objectId=$id;sourceId=$sourceId;name=$name;worldPositionMeters=$position;positionStatus=$positionStatus;sourceReport=('../'+$(if($type -ceq 'OtherContainers'){$otherPath}else{$harborPath}));sourceRecordId=$sourceId}
        if($type -ceq 'OtherContainers'){
            foreach($field in @('nestedStorageGroupCount','physicalContainerCount','capacityComposition','capacitySupplies','capacityStatus','knownCapacitySubtotalSupplies','configuredInitialSupplies','configuredInitialStatus','knownConfiguredInitialSubtotalSupplies')){$row[$field]=$source.$field}
        }else{
            Assert ($source.valueStatus.arrivalInterval -ne 'resolved' -or ($null -ne $source.arrivalIntervalSeconds -and $null -ne $source.arrivalIntervalMinutes -and [Math]::Abs($source.arrivalIntervalMinutes-$source.arrivalIntervalSeconds/60.0) -lt 0.00000001)) 'Minute conversion differs from source seconds.'
            $row.supplyIncomePerCycle=$source.supplyIncomePerCycle;$row.arrivalIntervalSeconds=$source.arrivalIntervalSeconds;$row.arrivalIntervalMinutes=$source.arrivalIntervalMinutes;$row.valueStatus=$source.valueStatus
            $row.capacitySupplies=$source.storage.capacitySupplies;$row.capacityStatus=$source.storage.capacityStatus;$row.knownCapacitySubtotalSupplies=$source.storage.knownCapacitySubtotalSupplies
            $row.physicalContainerCount=$source.storage.physicalContainerCount;$row.nestedStorageGroupCount=$source.storage.storageGroupCount
        }
        Assert (Same $obj.configuredCapacitySupplies $row.capacitySupplies) 'Supply capacity differs from Locations.'
        $records.Add([pscustomobject]$row)
    }
    Assert (@($locations.objects | Where-Object category -ceq $category).Count -eq $ids.Count) 'Supply category incomplete.'
    $groups=@(foreach($loc in $locations.locations){$links=@($loc.nearbyObjects | Where-Object {$ids.Contains($_.objectId)});if($links.Count){[ordered]@{locationId=$loc.id;name=$loc.name;nameStatus=$loc.nameStatus;rawName=$loc.rawName;worldPositionMeters=@($loc.worldPositionMeters);positionStatus=$loc.positionStatus;matchingTier=$loc.matchingTier;nearbyObjects=$links}}})
    $remaining=@($locations.unassignedObjects | Where-Object {$ids.Contains($_.objectId)})
    $matched=@($groups | ForEach-Object {$_.nearbyObjects} | ForEach-Object {$_.objectId} | Sort-Object -Unique)
    $sourceSummary=$(if($type -ceq 'OtherContainers'){$other.summary}else{[ordered]@{sourceBaseCount=$harbors.count;harborCount=@($harbors.records | Where-Object {$_.source.nearestPrefab -like '*ConflictSourceBase_T*Harbor.et'}).Count;airfieldCount=@($harbors.records | Where-Object {$_.source.nearestPrefab -like '*ConflictSourceBase_Airfield.et'}).Count;resolvedCapacityBaseCount=@($harbors.records | Where-Object {$_.storage.capacityStatus -ceq 'resolved'}).Count;unknownCapacityBaseCount=@($harbors.records | Where-Object {$_.storage.capacityStatus -cne 'resolved'}).Count;physicalContainerCount=($harbors.records.storage | Measure-Object physicalContainerCount -Sum).Sum;knownCapacitySubtotalSupplies=($harbors.records.storage | Measure-Object knownCapacitySubtotalSupplies -Sum).Sum}})
    $viewInputs=[ordered]@{locations=[ordered]@{snapshotId=$locations.snapshotId;path=('../'+$locationPath);sha256=$locationInput.hash;capturedAtUTC=$locations.capturedAtUTC};supplies=[ordered]@{snapshotId=$(if($type -ceq 'OtherContainers'){$other.snapshotId}else{$harbors.snapshotId});path=('../'+$(if($type -ceq 'OtherContainers'){$otherPath}else{$harborPath}));sha256=$(if($type -ceq 'OtherContainers'){$otherInput.hash}else{$harborInput.hash});capturedAtUTC=$(if($type -ceq 'OtherContainers'){$other.capturedAtUTC}else{$harbors.capturedAtUTC})}}
    if($type -ceq 'Harbors'){$viewInputs.supplies.storageCapturedAtUTC=$harbors.storageCapturedAtUTC}
    $reports[$type]=[ordered]@{schemaVersion=2;kind='location-grouped-supply-view';report=$type;category=$category;snapshotId=$snapshotId;status='partial';gameVersion=$version;scenarioKey=$scenario;normalizerVersion=$normalizer;worldMetadata='../world.json';inputs=$viewInputs;radiusMeters=$locations.radiusMeters;distanceMethod=$locations.distanceMethod;matchingPolicy=$locations.matchingPolicy;matchingPriority=$locations.matchingPriority;summary=[ordered]@{objectCount=$records.Count;groupedObjectCount=$matched.Count;ungroupedObjectCount=$remaining.Count;locationCount=$groups.Count;associationCount=@($groups | ForEach-Object {$_.nearbyObjects}).Count};sourceSummary=$sourceSummary;records=@($records.ToArray());locations=$groups;unassignedObjects=$remaining;warnings=$warnings}
    if($type -ceq 'OtherContainers'){$reports[$type].previousStorage=$other.previousStorage}
}
Assert ($reports.OtherContainers.summary.objectCount+$reports.Harbors.summary.objectCount -eq $catalog.Count) 'Unsupported extra object category.'
$world=[ordered]@{schemaVersion=2;snapshotId=$snapshotId;revisionId=$RevisionId;revisionReason=$RevisionReason;status='partial';gameVersion=$version;scenarioKey=$scenario;worldPath=$locationWorld.worldPath;capturedAtUTC=$locations.capturedAtUTC;captureTimeMeaning='Inherited location capture time; supply captures are retained separately in inputs';normalizerVersion=$normalizer;analyzerVersion=$locations.analyzerVersion;inputs=$inputs;radiusMeters=$locations.radiusMeters;matchingPolicy=$locations.matchingPolicy;matchingPriority=$locations.matchingPriority;locationFilter=$locations.locationFilter;warnings=$warnings}
$index=[ordered]@{schemaVersion=2;kind='conflict-world-index';snapshotId=$snapshotId;status='partial';worldMetadata='world.json';sections=[ordered]@{supplies=[ordered]@{status='partial';sourceBases=[ordered]@{path='Supplies/Harbors.json';table='Supplies/OtherContainers.md#harbors';ungroupedSection='Supplies/OtherContainers.md#harbors-без-группы';summary=$reports.Harbors.summary};otherContainers=[ordered]@{path='Supplies/OtherContainers.json';table='Supplies/OtherContainers.md';ungroupedSection='Supplies/OtherContainers.md#othercontainers-без-группы';summary=$reports.OtherContainers.summary}};locations=[ordered]@{status='previous_verified_revision';path=$locationPath;table=(RevisionPath $locations 'Locations.md')};aiGroups=[ordered]@{status='not_analyzed'};startingBases=[ordered]@{status='not_analyzed'};vehicleSpawns=[ordered]@{status='not_analyzed'}}}
$null=New-Item -ItemType Directory -Path (Join-Path $output 'Supplies')
function WriteJson($path,$value){[IO.File]::WriteAllText((Join-Path $output $path),($value | ConvertTo-Json -Depth 40)+"`n",[Text.UTF8Encoding]::new($false))}
WriteJson 'world.json' $world;WriteJson 'data.json' $index
foreach($type in @('OtherContainers','Harbors')){WriteJson "Supplies/$type.json" $reports[$type]}
function Number($value){if($null -eq $value){return 'unknown'};([double]$value).ToString('0.######',$culture)}
function Distance($value){([double]$value).ToString('0.###',$culture)}
function Text($value){([string]$value).Replace('|','\|').Replace("`r",' ').Replace("`n",' ').Trim()}
function Position($value,$status){if($status -cne 'resolved' -or @($value).Count -ne 3){return 'unknown'};@($value | ForEach-Object {Number $_}) -join ' '}
function Value($value,$status){if($status -cne 'resolved'){return 'unknown'};Number $value}
$documents=[Collections.Generic.List[string]]::new()
$documents.Add('# Припасы по локациям')
$documents.Add('Сначала — [OtherContainers](#othercontainers), в конце — [Harbors](#harbors). Каждый каталог сохраняет свои значения, списки локаций и объекты без группы; повторные связи не увеличивают итоги.')
foreach($type in @('OtherContainers','Harbors')){
    $saved=Get-Content -LiteralPath (Join-Path $output "Supplies/$type.json") -Raw -Encoding utf8 | ConvertFrom-Json
    $lookup=@{};foreach($record in $saved.records){$lookup[$record.objectId]=$record}
    $lines=[Collections.Generic.List[string]]::new()
    $lines.Add("## $type");$lines.Add('');$lines.Add('### Summary');$lines.Add('')
    $lines.Add("Всего объектов: **$($saved.summary.objectCount)**. По локациям сгруппированы **$($saved.summary.groupedObjectCount)**, без группы — **$($saved.summary.ungroupedObjectCount)**. Локаций с объектами этого каталога: **$($saved.summary.locationCount)**; связей — **$($saved.summary.associationCount)**. Радиус **$(Number $saved.radiusMeters) м** по X/Z. Игра **$version**, мир ``$scenario.ent``, ревизия ``$RevisionId``. Статус **partial**.")
    if($type -ceq 'OtherContainers'){
        $s=$saved.sourceSummary
        $lines.Add('');$lines.Add("Корневых родителей: **$($s.storageGroupCount)**, вложенных хранилищ / объектов: **$($s.nestedStorageGroupCount)**, физических контейнеров: **$($s.physicalContainerCount)**. Вместимость: **$(Value $s.capacitySupplies $s.capacityStatus) припасов**; известный подытог **$(Number $s.knownCapacitySubtotalSupplies)**. Неопределённых слотов: **$($s.unresolvedSlotCount)**, списков: **$($s.unknownContainerListCount)**.")
        $lines.Add('');$lines.Add("Исключены **$($saved.previousStorage.excludedPhysicalSlotCount)** физических контейнеров ранее проверенных баз. Виртуальных представлений: **$($s.virtualViewCount)**; они не суммируются.")
    }else{
        $s=$saved.sourceSummary
        $lines.Add('');$lines.Add("Портов: **$($s.harborCount)**, аэропортов: **$($s.airfieldCount)**. Вместимость определена у **$($s.resolvedCapacityBaseCount)** баз, у **$($s.unknownCapacityBaseCount)** — ``unknown``. Физических контейнеров: **$(Number $s.physicalContainerCount)**; известный подытог — **$(Number $s.knownCapacitySubtotalSupplies) припасов**.")
    }
    $lines.Add('');$lines.Add('Итоги относятся к уникальным объектам исходного каталога. Объект может повторяться у нескольких локаций одного этапа; повторные строки не прибавляются к общему количеству или вместимости.');$lines.Add('');$lines.Add('### Откуда берутся данные');$lines.Add('')
    $lines.Add('| Данные | Источник |');$lines.Add('| --- | --- |')
    $lines.Add('| Локация и её координаты | Именованные MapDescriptor-подписи из проверенного Locations: DisplayName / перевод и мировая позиция. Заголовок раздела содержит имя и X Y Z подписи. |')
    $lines.Add('| Группировка и расстояние | Готовые связи Locations по ID объекта. Населённые пункты, острова и холмы имеют равный приоритет; Name Generic используется только для остатка. Новые совпадения не вычисляются. |')
    $lines.Add('| Координаты объекта | Собственная мировая позиция корневого родителя OtherContainers либо source base Harbors; X Y Z разделены пробелами. |')
    if($type -ceq 'OtherContainers'){
        $lines.Add('| Родитель / Source ID | Source name либо имя prefab корневого source-родителя; разные экземпляры разделяются по ID. |')
        $lines.Add('| Контейнеров / состав / вместимость | Число уникальных физических SUPPLIES-слотов, состав по m_fResourceValueMax и их сумма из исходного OtherContainers. |')
        $lines.Add('| Начальные припасы в конфиге | Сумма m_fResourceValueCurrent; фактический запас игровой сессии не измерялся. |')
    }else{
        $lines.Add('| Название | Имя source через IEntitySource.GetName(); название локации отдельно указано в заголовке группы. |')
        $lines.Add('| Пополнение за цикл, припасы | SCR_CampaignSourceBaseComponent.m_iRegularSuppliesIncomeBase из исходного Harbors. |')
        $lines.Add('| Пополнение, мин. | m_iSuppliesArrivalInterval: исходные секунды / 60, без усечения. |')
        $lines.Add('| Вместимость хранилищ, припасы | Сумма m_fResourceValueMax физических SUPPLIES-контейнеров в дочерней иерархии source base. Виртуальные представления исключены; неизвестная принадлежность остаётся unknown. |')
    }
    $lines.Add('');$lines.Add("Данные представления: [$type.json]($type.json), [метаданные](../world.json). Исходные значения и подробный состав: [исходный каталог]($($saved.inputs.supplies.path)). Группировка: [Locations]($($saved.inputs.locations.path.Replace('Locations.json','Locations.md'))), [Locations.json]($($saved.inputs.locations.path)). [Объекты без группы](#$($type.ToLowerInvariant())-без-группы).")
    $lines.Add('');$lines.Add('### Ограничения');$lines.Add('')
    $lines.Add('Это географические списки для ручной сверки. Близость к подписи не подтверждает родительскую группу в редакторе, принадлежность базе или ресурсной сети. Значения вместимости и начального запаса относятся к конфигу; runtime, динамические постройки и условия дохода пока не проверены. Unknown сохраняется, новый запуск Workbench не выполнялся.')
    $lines.Add('');$lines.Add('### Объекты по локациям');$lines.Add('')
    function AddTable($items,$withDistance){
        if($type -ceq 'OtherContainers'){$columns='| Родитель | Контейнеров | Состав, припасы | Вместимость, припасы | Начальные припасы в конфиге | Координаты X Y Z, м | Source ID |';$separator='| --- | ---: | --- | ---: | ---: | --- | --- |'}else{$columns='| Название | Пополнение за цикл, припасы | Пополнение, мин. | Вместимость хранилищ, припасы | Координаты X Y Z, м |';$separator='| --- | ---: | ---: | ---: | --- |'}
        if($withDistance){$columns=$columns+' Расстояние, м |';$separator=$separator+' ---: |'}
        $lines.Add($columns);$lines.Add($separator)
        foreach($entry in $items){
            $item=$lookup[$entry.objectId]
            if($type -ceq 'OtherContainers'){$composition=@($item.capacityComposition | ForEach-Object {"$($_.containerCount) × $(Number $_.capacitySupplies)"}) -join ' + ';if(!$composition){$composition='unknown'};$row="| $(Text $item.name) | $($item.physicalContainerCount) | $composition | $(Value $item.capacitySupplies $item.capacityStatus) | $(Value $item.configuredInitialSupplies $item.configuredInitialStatus) | $(Position $item.worldPositionMeters $item.positionStatus) | $(Text $item.sourceId) |"}else{$row="| $(Text $item.name) | $(Value $item.supplyIncomePerCycle $item.valueStatus.supplyIncomePerCycle) | $(Value $item.arrivalIntervalMinutes $item.valueStatus.arrivalInterval) | $(Value $item.capacitySupplies $item.capacityStatus) | $(Position $item.worldPositionMeters $item.positionStatus) |"}
            if($withDistance){$row=$row+" $(Distance $entry.distanceMeters) |"}
            $lines.Add($row)
        }
        $lines.Add('')
    }
    foreach($group in $saved.locations){$name=$(if($group.nameStatus -ceq 'resolved'){$group.name}else{$group.rawName+' (unknown)'});$lines.Add("#### $(Text $name) - $(Position $group.worldPositionMeters $group.positionStatus)");$lines.Add('');AddTable $group.nearbyObjects $true}
    $lines.Add("### $type без группы");$lines.Add('');$lines.Add("Без группы: **$($saved.summary.ungroupedObjectCount)**. Просмотреть эти объекты и вручную определить их связь с локациями или группами мира.");$lines.Add('')
    if($saved.unassignedObjects.Count){$remaining=@($saved.unassignedObjects | Sort-Object @{e={$lookup[$_.objectId].name}},objectId);AddTable $remaining $false}else{$lines.Add('Все объекты этого каталога вошли в списки локаций.');$lines.Add('')}
    $documents.Add(($lines -join "`n").TrimEnd([char]13,[char]10))
}
[IO.File]::WriteAllText((Join-Path $output 'Supplies/OtherContainers.md'),($documents -join "`n`n")+"`n",[Text.UTF8Encoding]::new($false))
[IO.File]::WriteAllText((Join-Path $output 'Supplies.md'),"# Припасы по локациям`n`nРевизия ``$RevisionId``: единый отчёт [OtherContainers](Supplies/OtherContainers.md#othercontainers), в самом конце — [Harbors](Supplies/OtherContainers.md#harbors). В каждом разделе собственные группы и объекты без группы. Полный справочник: [Locations]($($index.sections.locations.table)).`n`nДанные: [индекс](data.json), [метаданные](world.json).`n",[Text.UTF8Encoding]::new($false))
[pscustomobject]@{OutputDirectory=$output;OtherContainers=$reports.OtherContainers.summary;Harbors=$reports.Harbors.summary}
