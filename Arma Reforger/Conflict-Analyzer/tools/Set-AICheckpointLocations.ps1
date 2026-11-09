[CmdletBinding()]
param([Parameter(Mandatory)][string]$DiagnosticsPath,[Parameter(Mandatory)][string]$OutputDirectory,[double]$RadiusMeters=50)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
function Assert($ok,$message){if(!$ok){throw $message}}
function Save($p,$s){New-Item (Split-Path $p) -ItemType Directory -Force | Out-Null;[IO.File]::WriteAllText($p,$s.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
function Num($n){([double]$n).ToString('0.###',[Globalization.CultureInfo]::InvariantCulture)}
function Pos($p){(@($p | ForEach-Object {([double]$_).ToString('0.000',[Globalization.CultureInfo]::InvariantCulture)}) -join ' ')}
function Range($min,$max){if($min -eq $max){return (Num $min)};return "$(Num $min)–$(Num $max)"}
$ai=Get-Content "$OutputDirectory/AI/Groups.json" -Raw | ConvertFrom-Json
$diag=Get-Content $DiagnosticsPath -Raw | ConvertFrom-Json
Assert ($RadiusMeters -gt 0) 'Invalid radius.'
Assert ($ai.gameVersion -ceq $diag.gameVersion -and $ai.diagnosticsSha256 -ceq (Get-FileHash $DiagnosticsPath).Hash) 'Different world capture.'
Assert ($ai.PSObject.Properties.Name -contains 'supplyLocationEvidence') 'Apply supply locations first.'
Assert ($ai.PSObject.Properties.Name -notcontains 'checkpointLocationEvidence') 'Checkpoint grouping already applied.'
$checkpoints=@($diag.entities | Where-Object {$_.prefab -match '/Checkpoint[^/]*\.et$'} | ForEach-Object {[pscustomobject][ordered]@{sourceId=$_.sourceId;name=$_.name;prefab=$_.prefab;worldPositionMeters=$_.worldPosition;positionStatus=$_.positionStatus;parentSourceId=$_.parentSourceId;subscene=$_.subscene;layer=$_.layer}})
$unassigned=@($ai.records | Where-Object {!$_.location})
foreach($point in $unassigned){
 $candidates=@(@(foreach($cp in $checkpoints){
  if($cp.positionStatus -cne 'resolved'){continue}
  $d=[Math]::Sqrt([Math]::Pow($point.worldPositionMeters[0]-$cp.worldPositionMeters[0],2)+[Math]::Pow($point.worldPositionMeters[2]-$cp.worldPositionMeters[2],2))
  if($d -le $RadiusMeters){$prefabName=[IO.Path]::GetFileNameWithoutExtension($cp.prefab);$id='checkpoint/'+$cp.sourceId;$suffix=($cp.sourceId -replace '[^0-9A-Fa-f]','');[pscustomobject][ordered]@{locationId=$id;name=$prefabName;category='checkpoints';path="Checkpoints/$prefabName-$suffix.md";worldPositionMeters=$cp.worldPositionMeters;distanceMeters=$d;distanceOriginId=$cp.sourceId;distanceOriginPosition=$cp.worldPositionMeters;radiusMeters=$RadiusMeters;tier=6;prefab=$cp.prefab}}
 }) | Sort-Object distanceMeters,locationId)
 $point.locationCandidates=$candidates
 if($candidates.Count){$point.location=$candidates[0]}
}
$assigned=@($unassigned | Where-Object location);$remaining=@($unassigned | Where-Object {!$_.location})
$ai | Add-Member -NotePropertyName checkpointLocationEvidence -NotePropertyValue ([ordered]@{diagnosticsSha256=(Get-FileHash $DiagnosticsPath).Hash;sourceCapturedAtUTC=$diag.generatedAtUTC;selector='prefab_filename_Checkpoint*.et';radiusMeters=$RadiusMeters;distanceMetric='XZ';scope='only_points_without_supply_location';selection='nearest_then_source_id';ownershipEstablished=$false;inputPointIds=@($unassigned.id);assignedPointCount=$assigned.Count;remainingUnassignedPointCount=$remaining.Count;checkpoints=$checkpoints})
$ai.matchingRule+='; fallback_unassigned_only_nearest_Checkpoint_within_'+(Num $RadiusMeters)+'m_XZ'
$ai.normalizerVersion='ambient-ai-groups-0.4'
Save "$OutputDirectory/AI/Groups.json" ($ai | ConvertTo-Json -Depth 70)
function WritePage($records,$name,$path,$position){
 $page=[Collections.Generic.List[string]]::new();$title=$name;if($position){$title+=' — '+(Pos $position)}
 $page.Add("# $title");$page.Add('');$page.Add('[Группы ИИ — сводка](../../Summary.md)');$page.Add('');$page.Add("Checkpoint подбирается только для ранее нераспределённых точек: ближайший префаб в радиусе $(Num $RadiusMeters) м по X/Z, при равенстве — ID. Название взято из имени префаба, экземпляры различаются координатами. Это географическая привязка, не подтверждение подчинения или source-родства.");$page.Add('');$page.Add('| Точка | Выбор / тип | Бойцов | Координаты X Y Z, м | Якорь X Y Z, м | До якоря, м |');$page.Add('| --- | --- | ---: | --- | --- | ---: |')
 foreach($p in $records | Sort-Object id){$type=if($p.selectionMode -ceq 'random'){'Случайный тип'}else{$p.configuredType};$anchor='—';$distance='—';if($p.location){$anchor=Pos $p.location.distanceOriginPosition;$distance=Num $p.location.distanceMeters};$page.Add("| $($p.name) | $type | $(Range $p.unitCountMin $p.unitCountMax) | $(Pos $p.worldPositionMeters) | $anchor | $distance |")}
 $page.Add('');$page.Add('[Исходные точки, Checkpoint и кандидаты](../../Groups.json).');Save "$OutputDirectory/AI/Locations/$path" ($page -join "`n")
}
$section=[Collections.Generic.List[string]]::new();$section.Add('### Checkpoint');$section.Add('');$section.Add("Ранее нераспределённые точки рядом с префабами Checkpoint: радиус **$(Num $RadiusMeters) м по X/Z**. Остальные локации сохранены.");$section.Add('');$section.Add('| Локация | Точек | Всего бойцов |');$section.Add('| --- | ---: | ---: |')
foreach($group in $assigned | Group-Object {$_.location.locationId} | Sort-Object Name){$loc=$group.Group[0].location;$label=$loc.name+' — '+(Pos $loc.worldPositionMeters);$min=($group.Group | Measure-Object unitCountMin -Sum).Sum;$max=($group.Group | Measure-Object unitCountMax -Sum).Sum;$section.Add("| [$label](Locations/$($loc.path)) | $($group.Count) | $(Range $min $max) |");WritePage $group.Group $loc.name $loc.path $loc.worldPositionMeters}
$section.Add('');$section.Add('### Без локации');$section.Add('');$section.Add('| Локация | Точек | Всего бойцов |');$section.Add('| --- | ---: | ---: |')
$min=($remaining | Measure-Object unitCountMin -Sum).Sum;$max=($remaining | Measure-Object unitCountMax -Sum).Sum
$section.Add("| [Без локации](Locations/Ungrouped/Ungrouped.md) | $($remaining.Count) | $(Range $min $max) |");$section.Add('')
WritePage $remaining 'Без локации' 'Ungrouped/Ungrouped.md' $null
$path="$OutputDirectory/AI/Summary.md";$text=Get-Content $path -Raw
Assert ($text -match '### Без локации') 'Unassigned summary not found.'
$text=[regex]::Replace($text,'(?s)### Без локации.*?(?=## Выбор и активация)',[Text.RegularExpressions.MatchEvaluator]{param($m)($section -join "`n")+"`n"});Save $path $text
$world=Get-Content "$OutputDirectory/world.json" -Raw | ConvertFrom-Json;$world.normalizerVersion=$ai.normalizerVersion;Save "$OutputDirectory/world.json" ($world | ConvertTo-Json -Depth 30)
"Checkpoint: $($assigned.Count) assigned, $($remaining.Count) unassigned."
