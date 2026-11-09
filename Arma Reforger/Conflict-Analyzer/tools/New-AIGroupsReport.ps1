[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$DiagnosticsPath,
    [Parameter(Mandatory)][string]$CatalogLogPath,
    [Parameter(Mandatory)][string]$LocationsPath,
    [Parameter(Mandatory)][string]$SourceCodeDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [string]$RevisionId='r0057',
    [string]$WeaponsLogPath,
    [string]$InventoryRuntimeLogPath,
    [string]$WaypointDiagnosticsPath,
    [string]$SupplyRevisionPath
)
function FormatUnitRange($minimum,$maximum){if($minimum -eq $maximum){return (Num $minimum)};return ((Num $minimum)+'–'+(Num $maximum))}
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$culture=[Globalization.CultureInfo]::InvariantCulture
function Assert($ok,$message){if(!$ok){throw $message}}
function ReadJson($path){Get-Content -LiteralPath $path -Raw | ConvertFrom-Json}
function Hash($path){(Get-FileHash -LiteralPath $path).Hash}
function Num($n){([double]$n).ToString('0.###',$culture)}
function Pos($v){(@($v | ForEach-Object {([double]$_).ToString('0.000',$culture)}) -join ' ')}
function Field($fields,$name){$v=@($fields | Where-Object name -ceq $name);Assert ($v.Count -eq 1 -and $v[0].status -ceq 'resolved') "Unresolved field $name";$v[0]}
function Save($rel,$text){$p=Join-Path $OutputDirectory $rel;New-Item -ItemType Directory (Split-Path $p) -Force | Out-Null;[IO.File]::WriteAllText($p,$text.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
function Json($rel,$value){Save $rel ($value | ConvertTo-Json -Depth 55)}
Assert (!(Test-Path -LiteralPath $OutputDirectory)) 'Output exists; preserve published revisions.'
$diag=ReadJson $DiagnosticsPath;$locations=ReadJson $LocationsPath;$log=Get-Content -LiteralPath $CatalogLogPath
$begin=@($log | Select-String '\[ME_CA_AI_CATALOG\] BEGIN\|');$end=@($log | Select-String '\[ME_CA_AI_CATALOG\] COMPLETE\|')
Assert ($begin.Count -eq 1 -and $end.Count -eq 1 -and !($log -match '\[ME_CA_AI_CATALOG\] ERROR\|')) 'Incomplete catalog capture.'
$version=($begin[0].Line -split '\|')[-1];Assert ($version -ceq $diag.gameVersion -and $version -ceq $locations.gameVersion) 'Mixed game versions.'
$typeNames=@('TEAM_SENTRY','TEAM_MG','TEAM_AT','FIRETEAM','SQUAD_RIFLE','TEAM_SNIPER','TEAM_MG_ELITE','PARTISAN_SNIPER','PARTISAN_TEAM')
$catalog=@();$units=@{}
foreach($line in $log){
    if($line -match '\[ME_CA_AI_CATALOG\] ENTRY\|(.+)$'){
        $v=$Matches[1].Split('|');Assert ($v.Count -eq 7 -and $v[6] -ceq '1') 'Unresolved catalog entry.'
        $type=[int]$v[1];Assert ($type -ge 0 -and $type -lt $typeNames.Count) 'Unknown group type.'
        $catalog+=[pscustomobject][ordered]@{id=[int]$v[0];faction='FIA';typeId=$type;type=$typeNames[$type];selectionThreshold=[double]::Parse($v[2],$culture);enabled=($v[3] -ceq '1');prefab=$v[4];unitCount=[int]$v[5];fieldReadSucceeded=($v[6] -ceq '1');unitPrefabs=@();spawnImmediately=$null}
    }
    if($line -match '\[ME_CA_AI_CATALOG\] UNIT\|(\d+)\|(.+)$'){$id=[int]$Matches[1];if(!$units.ContainsKey($id)){$units[$id]=@()};$units[$id]+=$Matches[2]}
}
Assert ($catalog.Count -eq [int](($end[0].Line -split '\|')[-1])) 'Catalog count mismatch.'
foreach($entry in $catalog){Assert ($units.ContainsKey($entry.id) -and $units[$entry.id].Count -eq $entry.unitCount) 'Unit slot count mismatch.';$entry.unitPrefabs=$units[$entry.id];$immediate=@($log | Select-String ('\[ME_CA_AI_CATALOG\] IMMEDIATE\|'+$entry.id+'\|'));Assert ($immediate.Count -eq 1) 'Missing spawn mode.';$entry.spawnImmediately=(($immediate[0].Line -split '\|')[-1] -ceq '1');Assert (!$entry.spawnImmediately -and $entry.enabled) 'Unsupported disabled/immediate ambient catalog variant.'}
$sourceCode=@();foreach($rel in @('scripts/Game/Components/Locations/SCR_AmbientPatrolSpawnPointComponent.c','scripts/Game/Systems/SCR_AmbientPatrolSystem.c')){$path=Join-Path $SourceCodeDirectory $rel;Assert (Test-Path $path) 'Missing installed code evidence.';$sourceCode+=@{resource=$rel;sha256=(Hash $path)}}
$records=@();$allowed=@('Name City','Name Town','Name Village','Name Settlement','Name Island','Name Hill','Name Generic')
foreach($entity in $diag.entities){
    $components=@($entity.components | Where-Object className -ceq 'SCR_AmbientPatrolSpawnPointComponent');if(!$components.Count){continue};Assert ($components.Count -eq 1) 'Multiple spawn components.'
    $fields=$components[0].fields;$factionComponent=@($entity.components | Where-Object className -ceq 'SCR_FactionAffiliationComponent');Assert ($factionComponent.Count -eq 1) 'Missing faction.'
    $faction=Field $factionComponent[0].fields 'faction affiliation';Assert ($faction.value -ceq 'FIA') 'Faction not covered by catalog probe.'
    $type=Field $fields 'm_eGroupType';$random=Field $fields 'm_bPickRandomGroupType';$enabled=Field $fields 'Enabled';Assert ($entity.positionStatus -ceq 'resolved') 'Unknown spawn position.'
    $options=if($random.value -ceq 'true'){@($catalog | Where-Object {$_.selectionThreshold -gt 0})}else{@($catalog | Where-Object typeId -eq ([int]$type.value) | Select-Object -First 1)}
    Assert ($options.Count -gt 0) 'Unresolved group prefab.'
    $candidates=@();foreach($location in $locations.locations){
        if($location.descriptorType -cnotin $allowed -or $location.positionStatus -cne 'resolved'){continue}
        $distance=[Math]::Sqrt([Math]::Pow($entity.worldPosition[0]-$location.worldPositionMeters[0],2)+[Math]::Pow($entity.worldPosition[2]-$location.worldPositionMeters[2],2))
        if($distance -le 350){$candidates+=[pscustomobject]@{locationId=$location.id;name=$location.name;type=$location.descriptorType;worldPositionMeters=$location.worldPositionMeters;distanceMeters=$distance;tier=$(if($location.descriptorType -ceq 'Name Generic'){1}else{0})}}
    }
    $ordered=@($candidates | Sort-Object tier,distanceMeters,locationId);$selected=$null;if($ordered.Count){$selected=$ordered[0]}
    $wanted=@('Enabled','m_eGroupType','m_bPickRandomGroupType','m_iSpawnDistanceOverride','m_iDespawnDistanceOverride','m_iRespawnPeriod','m_eImportance','m_sDefaultWaypointPrefab','m_sCycleWaypointPrefab');$evidence=@();foreach($name in $wanted){$evidence+=Field $fields $name}
    $records+=[pscustomobject][ordered]@{id=$entity.sourceId;sourceName=$entity.name;name=$(if($entity.name){$entity.name}else{'Patrol_'+($entity.sourceId -replace '[^0-9A-Fa-f]','')});prefab=$entity.prefab;parentSourceId=$entity.parentSourceId;subscene=$entity.subscene;layer=$entity.layer;worldPositionMeters=$entity.worldPosition;faction=$faction.value;enabled=($enabled.value -ceq 'true');selectionMode=$(if($random.value -ceq 'true'){'random'}else{'fixed_type'});configuredType=$type.enumLabel;configuredTypeIgnored=($random.value -ceq 'true');catalogOptionIds=@($options | ForEach-Object {$_.id});configuredGroupSlots=1;unitCountMin=($options | Measure-Object unitCount -Minimum).Minimum;unitCountMax=($options | Measure-Object unitCount -Maximum).Maximum;spawnDistanceOverride=[int](Field $fields 'm_iSpawnDistanceOverride').value;despawnDistanceOverride=[int](Field $fields 'm_iDespawnDistanceOverride').value;respawnPeriodRaw=[int](Field $fields 'm_iRespawnPeriod').value;location=$selected;locationCandidates=$ordered;ownershipEstablished=$false;fieldEvidence=$evidence;factionEvidence=$faction}
}
Assert ($records.Count -eq @($records.id | Sort-Object -Unique).Count) 'Duplicate spawn IDs.'
$enabled=@($records | Where-Object enabled);$fixed=@($records | Where-Object selectionMode -ceq fixed_type);$random=@($records | Where-Object selectionMode -ceq random)
$minimum=($enabled | Measure-Object unitCountMin -Sum).Sum;$maximum=($enabled | Measure-Object unitCountMax -Sum).Sum
$summary=[ordered]@{spawnPointCount=$records.Count;enabledSpawnPointCount=$enabled.Count;fixedTypePointCount=$fixed.Count;randomTypePointCount=$random.Count;catalogVariantCount=$catalog.Count;configuredGroupSlots=$enabled.Count;conditionalOneGroupPerEnabledPointUnitMin=$minimum;conditionalOneGroupPerEnabledPointUnitMax=$maximum;runtimeSpawnedGroupCount=$null;runtimeUnitCount=$null;placedGroupsInDiagnostics=@($diag.entities | Where-Object className -ceq 'SCR_AIGroup').Count;otherSpawnMechanismsStatus='not_analyzed'}
$report=[ordered]@{schemaVersion=1;kind='ambient-ai-groups';status='partial';snapshotId="$version/CTI_Campaign_HQC_Eden/$RevisionId";gameVersion=$version;scenarioKey='CTI_Campaign_HQC_Eden';normalizerVersion='ambient-ai-groups-0.1';sourceCapturedAtUTC=$diag.generatedAtUTC;catalogLogSha256=(Hash $CatalogLogPath);catalogLogLastWriteTimeUTC=(Get-Item -LiteralPath $CatalogLogPath).LastWriteTimeUtc.ToString('o');catalogLogTimestampNote='Native Workbench log; catalog captured separately from world source inventory.';diagnosticsSha256=(Hash $DiagnosticsPath);locationsSha256=(Hash $LocationsPath);codeEvidence=$sourceCode;scope='ambient_patrol_spawnpoint_components_and_FIA_catalog';matchingRule='nearest_within_350m_XZ_primary_settlements_islands_hills_then_generic_excluding_water_names';randomSelectionRule='draw_uniform_threshold_0_to_max_then_uniform_among_entries_at_or_above_threshold';runtimeMeasured=$false;summary=$summary;catalog=$catalog;records=$records}
Json 'AI/Groups.json' $report
$lines=[Collections.Generic.List[string]]::new();$lines.Add('# Группы ИИ — сводка');$lines.Add('');$lines.Add("Мир CTI_Campaign_HQC_Eden, игра **$version**, ревизия **$RevisionId**. Первый раздел: фоновые патрули FIA.");$lines.Add('');$lines.Add("Точек: **$($records.Count)**; фиксированный тип: **$($fixed.Count)**; случайный тип: **$($random.Count)**; вариантов каталога: **$($catalog.Count)**.");$lines.Add('');$lines.Add("Если каждая включённая точка создаст одну группу: **$(FormatUnitRange $minimum $maximum) бойцов**. Это условный состав конфигурации, не число одновременно активных ИИ. Реальное появление зависит от игроков, дистанций, паузы, состояния точки и игрового бюджета; фактическое число не измерено.");$lines.Add('');$lines.Add('В исходной диагностике нет размещённых SCR_AIGroup. Это не полный аудит всех механизмов ИИ: защитники баз, динамическое создание и другие системы пока не разобраны.');$lines.Add('');$lines.Add('## Типы групп');$lines.Add('');$lines.Add('| Тип | Точек с фиксированным типом | Бойцов в группе | Всего бойцов фиксированных групп |');$lines.Add('| --- | ---: | ---: | ---: |')
$typeRows=@()
foreach($entry in $catalog){$count=@($fixed | Where-Object configuredType -ceq $entry.type).Count;$typeRows+=[pscustomobject]@{count=$count;name=$entry.type;line="| [$($entry.type)](Types/$($entry.type).md) | $count | $($entry.unitCount) | $($count*$entry.unitCount) |"}}
$typeRows+=[pscustomobject]@{count=$random.Count;name='Случайный тип';line="| Случайный тип | $($random.Count) | 1–7 | не прибавлять все варианты одновременно |"}
foreach($row in $typeRows | Sort-Object @{Expression='count';Descending=$true},name){$lines.Add($row.line)};$lines.Add('')
$lines.Add('## Объекты по локациям');$lines.Add('');$lines.Add('«Всего бойцов» — суммарная численность по всем точкам локации при создании одной группы на каждой точке. Диапазон учитывает случайный выбор состава. Это не число одновременно активных бойцов в игре.');$lines.Add('');$lines.Add('Назначение — ближайшая подходящая подпись в радиусе 350 м по X/Z: города, деревни, поселения, острова и холмы имеют приоритет над Name Generic. Пруды, реки и озёра исключены. Это географическая подсказка, не подтверждение родства сущностей. Каждая точка находится в одном списке; остальные — «Без локации».');$lines.Add('');$lines.Add('| Локация | Точек | Всего бойцов |');$lines.Add('| --- | ---: | ---: |')
$groups=@($records | Group-Object {if($_.location){$_.location.locationId}else{'unassigned'}} | Sort-Object Name)
foreach($group in $groups){$first=$group.Group[0];$label='Без локации';$file='Ungrouped';$coords='';if($first.location){$label=$first.location.name;$file='Location_'+($first.location.locationId -replace '[^0-9A-Fa-f]','');$coords=' — '+(Pos $first.location.worldPositionMeters)};$min=($group.Group | Measure-Object unitCountMin -Sum).Sum;$max=($group.Group | Measure-Object unitCountMax -Sum).Sum;$lines.Add("| [$label](Locations/$file.md) | $($group.Count) | $(FormatUnitRange $min $max) |")
    $page=[Collections.Generic.List[string]]::new();$page.Add("# $label$coords");$page.Add('');$page.Add('[Группы ИИ — сводка](../Summary.md)');$page.Add('');$page.Add('Координаты относятся к точке спавна. Расстояние — до подписи по X/Z. Число бойцов условно, при создании одной группы на точку; это не измеренное число активных ИИ.');$page.Add('');$page.Add('| Точка | Выбор / тип | Бойцов | Координаты X Y Z, м | До локации, м |');$page.Add('| --- | --- | ---: | --- | ---: |')
    foreach($record in $group.Group | Sort-Object id){$type=if($record.selectionMode -ceq 'random'){"Случайный: $($record.catalogOptionIds.Count) вариантов"}else{$record.configuredType};$distance=if($record.location){Num $record.location.distanceMeters}else{'—'};$page.Add("| $($record.name) | $type | $(FormatUnitRange $record.unitCountMin $record.unitCountMax) | $(Pos $record.worldPositionMeters) | $distance |")};$page.Add('');$page.Add('[Исходные поля и все допустимые варианты](../Groups.json).');Save "AI/Locations/$file.md" ($page -join "`n")
}
$lines.Add('');$lines.Add('## Выбор и активация');$lines.Add('');$lines.Add('При фиксированном типе код выбирает первую запись каталога с совпадающим m_eGroupType. При случайном выборе m_eGroupType точки игнорируется: общий порог выбирается между 0 и максимальным m_fProbabilityOfPresence, затем равновероятно выбирается один из прошедших вариантов. Значение 0.3 не означает 30% независимого появления группы. Ожидаемая численность не рассчитывается.');$lines.Add('');$lines.Add('Для текущего снимка все точки включены, m_iRespawnPeriod=0 означает отсутствие автоматического респавна по таймеру (единица поля — секунды). Это не запрещает отдельную логику смены фракции / повторной активации. Дистанции активации и удаления сохранены для каждой точки в JSON.');$lines.Add('');$lines.Add('[Данные, состав вариантов и происхождение](Groups.json).');Save 'AI/Summary.md' ($lines -join "`n")
foreach($entry in $catalog){$page=[Collections.Generic.List[string]]::new();$page.Add("# $($entry.type)");$page.Add('');$page.Add('[Группы ИИ — сводка](../Summary.md)');$page.Add('');$page.Add("Фракция: **FIA**. Состав: **$($entry.unitCount) бойцов**. Порог случайного отбора: **$(Num $entry.selectionThreshold)** (не независимая вероятность появления).");$page.Add('');$page.Add("Prefab: ``$($entry.prefab)``.");$page.Add('');$page.Add('| Prefab бойца | Количество |');$page.Add('| --- | ---: |');foreach($unit in $entry.unitPrefabs | Group-Object | Sort-Object Name){$page.Add("| $([IO.Path]::GetFileNameWithoutExtension($unit.Name)) | $($unit.Count) |")};$page.Add('');$page.Add('Состав прочитан через унаследованное m_aUnitPrefabSlots в Workbench; повторяющиеся слоты считаются отдельными бойцами. Вооружение не выводится из имени персонажа.');$page.Add('');$page.Add('[Исходные ресурсы и значения](../Groups.json).');Save "AI/Types/$($entry.type).md" ($page -join "`n")}
Json 'data.json' ([ordered]@{schemaVersion=3;snapshotId=$report.snapshotId;status='partial';sections=@{ai=@{data='AI/Groups.json';summary='AI/Summary.md';status='partial'};supplies=@{data='../r0046/data.json';status='unchanged'}}})
Json 'world.json' ([ordered]@{schemaVersion=3;snapshotId=$report.snapshotId;revisionId=$RevisionId;gameVersion=$version;scenarioKey='CTI_Campaign_HQC_Eden';normalizerVersion=$report.normalizerVersion;status='partial';summary=$summary;worldPath=$diag.worldPath;sourceCapturedAtUTC=$diag.generatedAtUTC})
Write-Output ($summary | ConvertTo-Json -Compress)

if ($WeaponsLogPath) { & (Join-Path $PSScriptRoot 'Add-AIWeaponsReport.ps1') -WeaponsLogPath $WeaponsLogPath -OutputDirectory $OutputDirectory }

if ($WeaponsLogPath) { & (Join-Path $PSScriptRoot 'Add-AIMedicalReport.ps1') -InventoryLogPath $WeaponsLogPath -OutputDirectory $OutputDirectory }

if ($InventoryRuntimeLogPath) { & (Join-Path $PSScriptRoot 'Add-AIAmmunitionReport.ps1') -InventoryRuntimeLogPath $InventoryRuntimeLogPath -OutputDirectory $OutputDirectory }

if ($SupplyRevisionPath) { & (Join-Path $PSScriptRoot 'Set-AISupplyLocations.ps1') -SupplyRevisionPath $SupplyRevisionPath -OutputDirectory $OutputDirectory -DiagnosticsPath $DiagnosticsPath }

if ($SupplyRevisionPath) { & (Join-Path $PSScriptRoot 'Set-AICheckpointLocations.ps1') -DiagnosticsPath $DiagnosticsPath -OutputDirectory $OutputDirectory -RadiusMeters 50 }

if ($WaypointDiagnosticsPath) { & (Join-Path $PSScriptRoot 'Set-AIPatrolCategory.ps1') -WaypointDiagnosticsPath $WaypointDiagnosticsPath -OutputDirectory $OutputDirectory }

if ($SupplyRevisionPath) { & (Join-Path $PSScriptRoot 'Set-AIFirePoints.ps1') -DiagnosticsPath $DiagnosticsPath -OutputDirectory $OutputDirectory }

if ($SupplyRevisionPath) { & (Join-Path $PSScriptRoot 'Set-AIAdditionalLocations.ps1') -DiagnosticsPath $DiagnosticsPath -LocationsPath $LocationsPath -OutputDirectory $OutputDirectory }
