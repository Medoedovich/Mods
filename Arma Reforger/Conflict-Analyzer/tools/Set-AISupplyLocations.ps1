[CmdletBinding()]
param([Parameter(Mandatory)][string]$SupplyRevisionPath,[Parameter(Mandatory)][string]$OutputDirectory,[Parameter(Mandatory)][string]$DiagnosticsPath)
function FormatUnitRange($minimum,$maximum){if($minimum -eq $maximum){return (Num $minimum)};return ((Num $minimum)+'–'+(Num $maximum))}
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
function Assert($ok,$s){if(!$ok){throw $s}}
function Save($p,$s){New-Item (Split-Path $p) -ItemType Directory -Force | Out-Null;[IO.File]::WriteAllText($p,$s.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
function Pos($p){(@($p | ForEach-Object {([double]$_).ToString('0.000',[Globalization.CultureInfo]::InvariantCulture)}) -join ' ')}
function Num($n){([double]$n).ToString('0.###',[Globalization.CultureInfo]::InvariantCulture)}
$ai=Get-Content "$OutputDirectory/AI/Groups.json" -Raw | ConvertFrom-Json
$locations=Get-Content "$SupplyRevisionPath/Locations.json" -Raw | ConvertFrom-Json
$summary=Get-Content "$SupplyRevisionPath/Supplies/Summary.json" -Raw | ConvertFrom-Json
$bases=Get-Content "$SupplyRevisionPath/Supplies/StartingBases.json" -Raw | ConvertFrom-Json
Assert ($ai.gameVersion -ceq $locations.gameVersion -and $ai.gameVersion -ceq $bases.gameVersion) 'Mixed versions.'
Assert ($ai.scenarioKey -ceq $locations.scenarioKey) 'Mixed worlds.'
$folders=@{control_points='ControlPoints';harbors='Harbors';supply_depots='SupplyDepots';settlements='Settlements';starting_bases='StartingBases';other='Other';unassigned='Ungrouped'}
$labels=@{control_points='Контрольные точки';harbors='Доки';supply_depots='Склады';settlements='Города';starting_bases='Стартовые позиции главных баз';other='Другое';unassigned='Без локации'}
$ranks=@{supply_depots=0;control_points=1;harbors=2;starting_bases=3;settlements=4;other=5}
$redirect=@{}
foreach($merge in $locations.mapGroupMerges){$redirect[$merge.sourceGroupId]=$merge.targetGroupId}
foreach($transfer in $summary.harborLocationTransfers){$redirect[$transfer.groupId]=$transfer.dockGroupId}
$diag=Get-Content $DiagnosticsPath -Raw | ConvertFrom-Json
Assert ($ai.diagnosticsSha256 -ceq (Get-FileHash $DiagnosticsPath).Hash) 'Different source capture.'
$entities=@{};foreach($entity in $diag.entities){$entities[$entity.sourceId]=$entity}
$targets=[ordered]@{}
foreach($group in $locations.groups){
 if($redirect.ContainsKey($group.id)){continue}
 $page=@($summary.detailPages | Where-Object id -ceq $group.id)
 $name=$group.name;$path=$null
 if($page.Count){$name=$page[0].name;$path=$page[0].path}
 if(!$path){$slug=[regex]::Replace($name.Normalize([Text.NormalizationForm]::FormD),'\p{Mn}','');$slug=[regex]::Replace($slug,'[^\p{L}\p{Nd}_-]+','-').Trim('-');$suffix=([Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($group.id)))).Substring(0,8).ToLowerInvariant();$path=$folders[$group.category]+"/$slug-$suffix.md"}
 $targets[$group.id]=[ordered]@{id=$group.id;name=$name;category=$group.category;worldPositionMeters=$group.worldPositionMeters;path=$path;anchors=@()}
}
foreach($group in $locations.groups){
 $id=$group.id;if($redirect.ContainsKey($id)){$id=$redirect[$id]}
 Assert ($targets.Contains($id)) "Unknown redirect $id"
 if($group.positionStatus -cne 'resolved'){continue}
 $radius=if($group.category -ceq 'supply_depots'){200}else{350}
 $targets[$id].anchors += [ordered]@{sourceId=$group.id;position=$group.worldPositionMeters;radiusMeters=$radius;kind='supply_catalog_group_anchor'}
}
# Merged control-point labels can be absent from the retained group list.
foreach($merge in $locations.mapGroupMerges){$t=$targets[$merge.targetGroupId];if(!@($t.anchors | Where-Object sourceId -ceq $merge.sourceGroupId).Count){$t.anchors += [ordered]@{sourceId=$merge.sourceGroupId;position=$merge.worldPositionMeters;radiusMeters=350;kind='merged_control_point_map_label'}}}
foreach($base in $bases.records){$id='starting-base/'+$base.sourceId;$targets[$id]=[ordered]@{id=$id;name=$base.name;category='starting_bases';worldPositionMeters=$base.worldPositionMeters;path="StartingBases/$($base.name).md";anchors=@([ordered]@{sourceId=$base.sourceId;position=$base.worldPositionMeters;radiusMeters=350;kind='HQ_candidate'})}}
foreach($record in $ai.records){
 $record | Add-Member -NotePropertyName originalMapLocation -NotePropertyValue $record.location
 $record | Add-Member -NotePropertyName originalMapLocationCandidates -NotePropertyValue $record.locationCandidates
 $candidates=@()
 foreach($target in $targets.Values){foreach($anchor in $target.anchors){$d=[Math]::Sqrt([Math]::Pow($record.worldPositionMeters[0]-$anchor.position[0],2)+[Math]::Pow($record.worldPositionMeters[2]-$anchor.position[2],2));if($d -le $anchor.radiusMeters){$candidates += [pscustomobject]@{locationId=$target.id;name=$target.name;category=$target.category;path=$target.path;worldPositionMeters=$target.worldPositionMeters;distanceMeters=$d;distanceOriginId=$anchor.sourceId;distanceOriginPosition=$anchor.position;radiusMeters=$anchor.radiusMeters;tier=$ranks[$target.category]}}}}
 $parent=$record.parentSourceId;$chain=@();$seen=[Collections.Generic.HashSet[string]]::new()
 while($parent){
  Assert ($seen.Add($parent)) 'Source parent cycle.'
  Assert ($entities.ContainsKey($parent)) "Missing ancestor $parent"
  $ancestor=$entities[$parent];$chain+=$parent
  if($ancestor.prefab -match '/CampaignRemnantsSupplyDepot\.et$'){
   $id='supply-depot/'+$parent
   Assert ($targets.Contains($id)) "Missing depot destination $id"
   $target=$targets[$id]
   $distance=[Math]::Sqrt([Math]::Pow($record.worldPositionMeters[0]-$ancestor.worldPosition[0],2)+[Math]::Pow($record.worldPositionMeters[2]-$ancestor.worldPosition[2],2))
   $candidates+=[pscustomobject]@{locationId=$id;name=$target.name;category='supply_depots';path=$target.path;worldPositionMeters=$target.worldPositionMeters;distanceMeters=$distance;distanceOriginId=$parent;distanceOriginPosition=$ancestor.worldPosition;radiusMeters=$null;tier=-1;method='confirmed_source_ancestor';sourceParentEstablished=$true;sourceAncestorChain=$chain}
   break
  }
  $parent=$ancestor.parentSourceId
 }
 $ordered=@($candidates | Sort-Object tier,distanceMeters,locationId,distanceOriginId)
 $record.locationCandidates=$ordered;$record.location=$null;if($ordered.Count){$record.location=$ordered[0]}
}
$ai.matchingRule='confirmed_CampaignRemnantsSupplyDepot_ancestor_first_without_radius; supply_catalog_destinations_and_merges; depots_200m_then_control_points_harbors_HQ_settlements_other_350m_XZ; nearest_in_first_tier_then_ids; unique_assignment_not_ownership'
$ai.normalizerVersion='ambient-ai-groups-0.4'
$ai | Add-Member -NotePropertyName supplyLocationEvidence -NotePropertyValue ([ordered]@{snapshotId=$locations.snapshotId;locationsSha256=(Get-FileHash "$SupplyRevisionPath/Locations.json").Hash;summarySha256=(Get-FileHash "$SupplyRevisionPath/Supplies/Summary.json").Hash;startingBasesSha256=(Get-FileHash "$SupplyRevisionPath/Supplies/StartingBases.json").Hash;destinations=@($targets.Values);note='Uses all retained named catalog locations including those without supplies; source ancestry to CampaignRemnantsSupplyDepot takes priority; resource-grid eligibility is not applied to AI.'})
Save "$OutputDirectory/AI/Groups.json" ($ai | ConvertTo-Json -Depth 70)
# Delete only generated location pages in the caller-selected new output, not historical revisions.
$locationRoot=[IO.Path]::GetFullPath("$OutputDirectory/AI/Locations")
$outputRoot=[IO.Path]::GetFullPath($OutputDirectory).TrimEnd('\','/')+[IO.Path]::DirectorySeparatorChar
Assert ($locationRoot.StartsWith($outputRoot,[StringComparison]::OrdinalIgnoreCase)) 'Invalid output location directory'
foreach($file in Get-ChildItem $locationRoot -Recurse -File -Filter '*.md'){Remove-Item -LiteralPath $file.FullName}
$section=[Collections.Generic.List[string]]::new();$section.Add('## Объекты по локациям');$section.Add('');$section.Add('«Всего бойцов» — суммарная численность по всем точкам локации при создании одной группы на каждой точке. Диапазон учитывает случайный выбор состава. Это не число одновременно активных бойцов в игре.');$section.Add('');$section.Add('Названия, категории и объединения взяты из справочника припасов. Сначала подтверждённый предок CampaignRemnantsSupplyDepot без ограничения расстояния. Для остальных — склады (200 м от маркера), затем контрольные точки, доки, кандидаты HQ, города и другие локации (350 м по X/Z). Внутри первого подходящего этапа выбирается ближайший якорь; при равенстве — ID. Для объединённых локаций сохранены исходные подписи и позиции. Каталог включает допустимые локации без припасов; в таблицах показаны только группы с точками ИИ.');$section.Add('');$section.Add('Каждая точка учитывается один раз. Родство подтверждается только для явно сохранённой цепочки предков склада. Остальное — географическое распределение, не игровое подчинение базе или проверка ResourceGrid. Расстояние в подробной таблице — до выбранного якоря; все кандидаты и прежняя привязка сохранены в JSON.');$section.Add('')
$counts=@()
foreach($category in @('control_points','harbors','supply_depots','settlements','starting_bases','other','unassigned')){
 $groups=@($ai.records | Where-Object {if($category -ceq 'unassigned'){!$_.location}else{$_.location -and $_.location.category -ceq $category}} | Group-Object {if($_.location){$_.location.locationId}else{'unassigned'}} | Sort-Object {if($_.Group[0].location){$_.Group[0].location.name}else{'Без локации'}},Name)
 if(!$groups.Count){continue}
 $section.Add("### $($labels[$category])");$section.Add('');$section.Add('| Локация | Точек | Всего бойцов |');$section.Add('| --- | ---: | ---: |')
 foreach($group in $groups){
  $name='Без локации';$path='Ungrouped/Ungrouped.md';$position='';if($category -cne 'unassigned'){$t=$targets[$group.Name];$name=$t.name;$path=$t.path;$position=' — '+(Pos $t.worldPositionMeters)}
  $min=($group.Group | Measure-Object unitCountMin -Sum).Sum;$max=($group.Group | Measure-Object unitCountMax -Sum).Sum
  $section.Add("| [$name](Locations/$path) | $($group.Count) | $(FormatUnitRange $min $max) |")
  $counts+=[ordered]@{id=$group.Name;category=$category;name=$name;path="Locations/$path";pointCount=$group.Count}
  $page=[Collections.Generic.List[string]]::new();$page.Add("# $name$position");$page.Add('');$page.Add('[Группы ИИ — сводка](../../Summary.md)');$page.Add('');$page.Add('Распределение по каталогу припасов: подтверждённый предок CampaignRemnantsSupplyDepot имеет приоритет без ограничения расстояния; остальные точки назначены по близости. Расстояние считается до выбранного якоря (координаты указаны отдельно), который может отличаться от позиции в заголовке объединённой группы. Число бойцов условное, при одной группе на точку.');$page.Add('');$page.Add('| Точка | Выбор / тип | Бойцов | Координаты X Y Z, м | Якорь X Y Z, м | До якоря, м |');$page.Add('| --- | --- | ---: | --- | --- | ---: |')
  foreach($record in $group.Group | Sort-Object id){$type=if($record.selectionMode -ceq 'random'){'Случайный тип'}else{$record.configuredType};$distance='—';$anchor='—';if($record.location){$distance=Num $record.location.distanceMeters;$anchor=Pos $record.location.distanceOriginPosition};$page.Add("| $($record.name) | $type | $(FormatUnitRange $record.unitCountMin $record.unitCountMax) | $(Pos $record.worldPositionMeters) | $anchor | $distance |")};$page.Add('');$page.Add('[Привязки, исходные точки и происхождение](../../Groups.json).');Save "$OutputDirectory/AI/Locations/$path" ($page -join "`n")
 }
 $section.Add('')
}
$summaryPath="$OutputDirectory/AI/Summary.md";$text=Get-Content $summaryPath -Raw
$text=[regex]::Replace($text,'(?s)## Объекты по локациям.*?(?=## Выбор и активация)',[Text.RegularExpressions.MatchEvaluator]{param($m)($section -join "`n")+"`n"})
Save $summaryPath $text
$world=Get-Content "$OutputDirectory/world.json" -Raw | ConvertFrom-Json;$world.normalizerVersion=$ai.normalizerVersion;Save "$OutputDirectory/world.json" ($world | ConvertTo-Json -Depth 30)
$counts | ForEach-Object {[pscustomobject]$_} | Group-Object category | Select-Object Name,Count | Format-Table
