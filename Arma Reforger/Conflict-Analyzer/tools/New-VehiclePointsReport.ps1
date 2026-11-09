[CmdletBinding()]
param([Parameter(Mandatory)][string]$DiagnosticsPath,[Parameter(Mandatory)][string]$NativeLogPath,[Parameter(Mandatory)][string]$AILocationsPath,[Parameter(Mandatory)][string]$OutputDirectory,[string]$RevisionId='r0082')
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
function Assert($b,$s){if(!$b){throw $s}}
function Save($p,$t){$p=Join-Path $OutputDirectory $p;New-Item (Split-Path $p) -ItemType Directory -Force|Out-Null;[IO.File]::WriteAllText($p,$t.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
function Json($p,$o){Save $p ($o|ConvertTo-Json -Depth 70)}
function Pos($v){(@($v|ForEach-Object {([double]$_).ToString('0.000',[Globalization.CultureInfo]::InvariantCulture)}) -join ' ')}
function Field($fs,$name){$f=@($fs|Where-Object name -ceq $name);Assert ($f.Count -eq 1 -and $f[0].status -ceq 'resolved') "Missing $name";return $f[0]}
Assert (!(Test-Path $OutputDirectory)) 'Output exists'
$d=Get-Content $DiagnosticsPath -Raw|ConvertFrom-Json;$ai=Get-Content $AILocationsPath -Raw|ConvertFrom-Json;$log=Get-Content $NativeLogPath
Assert ($ai.gameVersion -ceq $d.gameVersion) 'Version mismatch'
Assert (@($log|Where-Object {$_ -match '\[ME_CA_AI_READ\] COMPLETE'}).Count -eq 1) 'Incomplete native read'
Assert (@($log|Where-Object {$_ -match ('BEGIN game='+[regex]::Escape($d.gameVersion))}).Count -eq 1) 'Native version mismatch'
$labels=@{};foreach($line in $log){if($line -match '\[ME_CA_LABEL\] (\d+)\|(.+)$'){$labels[$Matches[1]]=$Matches[2]}}
$ranks=@{supply_depots=0;control_points=1;harbors=2;starting_bases=3;settlements=4;other=5}
$checkpointTargets=@($d.entities|Where-Object prefab -match '/[^/]*(Barricade|Checkpoint)[^/]*\.et$'|ForEach-Object {Assert ($_.positionStatus -ceq 'resolved') 'Unresolved checkpoint';[pscustomobject]@{id=$_.sourceId;prefab=$_.prefab;name=[IO.Path]::GetFileNameWithoutExtension($_.prefab);position=$_.worldPosition}})
$records=@(foreach($e in $d.entities){$c=@($e.components|Where-Object className -ceq 'SCR_AmbientVehicleSpawnPointComponent');if(!$c.Count){continue};Assert ($c.Count -eq 1 -and $e.positionStatus -ceq 'resolved') 'Invalid point';$fs=$c[0].fields;$f=@($e.components|Where-Object className -ceq 'SCR_FactionAffiliationComponent');Assert ($f.Count -eq 1) 'Missing faction'
 $included=@((Field $fs 'm_aIncludedEditableEntityLabels').values|ForEach-Object {Assert ($labels.ContainsKey($_)) 'Unknown label';[pscustomobject]@{id=[int]$_;name=$labels[$_]}})
 $excluded=@((Field $fs 'm_aExcludedEditableEntityLabels').values|ForEach-Object {Assert ($labels.ContainsKey($_)) 'Unknown label';[pscustomobject]@{id=[int]$_;name=$labels[$_]}})
 $candidates=@(@(foreach($t in $ai.supplyLocationEvidence.destinations){foreach($anchor in $t.anchors){$dist=[math]::Sqrt([math]::Pow($e.worldPosition[0]-$anchor.position[0],2)+[math]::Pow($e.worldPosition[2]-$anchor.position[2],2));if($dist -le $anchor.radiusMeters){[pscustomobject]@{id=$t.id;name=$t.name;category=$t.category;tier=$ranks[$t.category];distanceMeters=$dist;anchorId=$anchor.sourceId;anchorPosition=$anchor.position;radiusMeters=$anchor.radiusMeters}}}})|Sort-Object tier,distanceMeters,id,anchorId)
 $location=$null;if($candidates.Count){$location=$candidates[0]}
 $previousLocation=$location
 $checkpointCandidates=@(@(foreach($target in $checkpointTargets){$dist=[math]::Sqrt([math]::Pow($e.worldPosition[0]-$target.position[0],2)+[math]::Pow($e.worldPosition[2]-$target.position[2],2));if($dist -le 50){[pscustomobject]@{id='checkpoint/'+$target.id;name=$target.name;category='checkpoints';tier=-1;distanceMeters=$dist;anchorId=$target.id;anchorPosition=$target.position;radiusMeters=50;prefab=$target.prefab;method='nearest_Barricade_or_Checkpoint_XZ';ownershipEstablished=$false}}})|Sort-Object distanceMeters,id)
 if($checkpointCandidates.Count){$location=$checkpointCandidates[0]}
 [pscustomobject][ordered]@{id=$e.sourceId;name=if($e.name){$e.name}else{'Vehicle_'+($e.sourceId -replace '[^0-9A-Fa-f]','')};sourceName=$e.name;parentSourceId=$e.parentSourceId;prefab=$e.prefab;subscene=$e.subscene;layer=$e.layer;worldPositionMeters=$e.worldPosition;faction=(Field $f[0].fields 'faction affiliation').value;enabled=(Field $fs 'Enabled').value -eq 'true';respawnPeriodSeconds=[int](Field $fs 'm_iRespawnPeriod').value;requireAllIncludedLabels=(Field $fs 'm_bRequireAllIncludedLabels').value -eq 'true';stopDespawnOnInteraction=(Field $fs 'm_bStopDespawnOnInteraction').value -eq 'true';saveOnDespawn=(Field $fs 'm_bSaveOnDespawn').value -eq 'true';includedLabels=$included;excludedLabels=$excluded;location=$location;previousLocation=$previousLocation;checkpointCandidates=$checkpointCandidates;locationCandidates=$candidates;fieldEvidence=$fs;vehicleCandidatesStatus='not_resolved';runtimeSpawnStatus='not_measured';ownershipEstablished=$false}
})
Assert (@($records.id|Sort-Object -Unique).Count -eq $records.Count) 'Duplicate IDs'
$snapshot="1.8.0.13/CTI_Campaign_HQC_Eden/$RevisionId"
$report=[ordered]@{schemaVersion=3;kind='ambient-vehicle-spawn-points';status='partial';snapshotId=$snapshot;gameVersion=$d.gameVersion;worldPath=$d.worldPath;sourceCapturedAtUTC=$d.generatedAtUTC;diagnosticsSha256=(Get-FileHash $DiagnosticsPath).Hash;nativeLogSha256=(Get-FileHash $NativeLogPath).Hash;locationCatalogSha256=(Get-FileHash $AILocationsPath).Hash;checkpointEvidence=@{targets=$checkpointTargets;radiusMeters=50;distanceMetric='XZ';scope='all vehicle points; overrides geographic supply location';selection='nearest then source ID';ownershipEstablished=$false};locationPolicy='Barricade/Checkpoint within 50m XZ first; geographic supply catalog anchors; depots 200m then CP,harbors,HQ,settlements,other 350m XZ; nearest in first tier; preserve previous supply location';normalizerVersion='ambient-vehicles-0.2';labels=$labels;pointCount=$records.Count;records=$records;limitations=@('Concrete vehicle catalog candidates not yet resolved','No runtime spawning performed','Other spawn mechanisms and placed vehicles not included')}
Json 'Vehicles/SpawnPoints.json' $report
$summary=[Collections.Generic.List[string]]::new();$summary.Add('# Точки появления машин');$summary.Add('');$summary.Add("Точки фонового появления техники — это позиции спавна, не количество существующих машин. Конкретные модели выбираются из каталога фракции по фильтрам; список моделей пока не разрешён.");$summary.Add('');$summary.Add('## По фракциям');$summary.Add('');$summary.Add('| Фракция | Точек | Без повторного появления | Повторное появление через 10 мин |');$summary.Add('| --- | ---: | ---: | ---: |')
foreach($g in $records|Group-Object faction|Sort-Object Count -Descending){$summary.Add("| [$($g.Name)](Factions/$($g.Name).md) | $($g.Count) | $(@($g.Group|Where-Object respawnPeriodSeconds -eq 0).Count) | $(@($g.Group|Where-Object respawnPeriodSeconds -eq 600).Count) |")}
$summary.Add("| **Всего** | **$($records.Count)** | **$(@($records|Where-Object respawnPeriodSeconds -eq 0).Count)** | **$(@($records|Where-Object respawnPeriodSeconds -eq 600).Count)** |")
$summary.Add('');$summary.Add('## По категориям локаций');$summary.Add('');$summary.Add('Названия и объединения взяты из справочника припасов. Склады — 200 м, остальные категории — 350 м по X/Z; ближайший якорь в первом подходящем приоритете. Это географическая привязка, не принадлежность базе. Привязка к ближайшему префабу Barricade или Checkpoint в 50 м по X/Z имеет приоритет над этими категориями. При равенстве расстояний — ID. Прежние локации и все кандидаты сохранены в JSON. Patrols и огневые точки к машинам не применяются.');$summary.Add('')
function RawPage($rows,$name,$withSummary=$false){$lines=[Collections.Generic.List[string]]::new();$lines.Add("# $name");$lines.Add('');$lines.Add('[Сводка](../Summary.md)');$lines.Add('');if($withSummary){$lines.Add('## Summary');$lines.Add('');$lines.Add("Указано количество позиций появления, не фактически созданных машин.");$lines.Add('');$lines.Add('| Фракция | Точек появления |');$lines.Add('| --- | ---: |');foreach($faction in @('CIV','FIA','US','USSR')){$n=@($rows|Where-Object faction -ceq $faction).Count;if($n){$lines.Add("| $faction | $n |")}};$lines.Add("| **Всего** | **$(@($rows).Count)** |");$lines.Add('');$lines.Add('## Точки');$lines.Add('')};if($withSummary){$lines.Add('| Фракция | Координаты X Y Z, м | Повторное появление, мин | Включённые метки | Режим | Исключённые метки |');$lines.Add('| --- | --- | ---: | --- | --- | --- |')}else{$lines.Add('| Точка | Фракция | Координаты X Y Z, м | Локация | Повторное появление, мин | Включённые метки | Режим | Исключённые метки |');$lines.Add('| --- | --- | --- | --- | ---: | --- | --- | --- |');};foreach($p in $rows|Sort-Object id){$loc='Без локации';if($p.location){$loc=$p.location.name};$period='Нет';if($p.respawnPeriodSeconds -gt 0){$period=($p.respawnPeriodSeconds/60).ToString([Globalization.CultureInfo]::InvariantCulture)};$inc=@($p.includedLabels|ForEach-Object name) -join ', ';$exc=@($p.excludedLabels|ForEach-Object name) -join ', ';$mode=if($p.requireAllIncludedLabels){'Все'}else{'Любая'};if($withSummary){$lines.Add("| $($p.faction) | $(Pos $p.worldPositionMeters) | $period | $inc | $mode | $exc |")}else{$lines.Add("| $($p.name) | $($p.faction) | $(Pos $p.worldPositionMeters) | $loc | $period | $inc | $mode | $exc |")}};$lines.Add('');$lines.Add('[Полные поля и источники](../SpawnPoints.json).');$lines -join "`n"}
$modeExplanation='**Режим** задаёт проверку включённых меток (m_bRequireAllIncludedLabels): **«Любая»** — достаточно хотя бы одной из перечисленных меток; **«Все»** — нужны все перечисленные метки одновременно. При пустом списке включённых меток этот фильтр не ограничивает выбор. Исключённые метки применяются в обоих режимах. Это фильтр допустимой техники, не режим повторного появления.'
function ModeTables($rows,$name,$compact,$groupByFaction=$false){
 $parts=[Collections.Generic.List[string]]::new()
 foreach($all in @($false,$true)){
  $subset=@($rows|Where-Object {$_.requireAllIncludedLabels -eq $all});$label=if($all){'Все'}else{'Любая'}
  if(!$subset.Count){continue};$parts.Add("### Режим «$label» — $($subset.Count)");$parts.Add('')

  if($groupByFaction){
   foreach($faction in @('CIV','FIA','US','USSR')){
    $members=@($subset|Where-Object faction -ceq $faction);if(!$members.Count){continue}
    $parts.Add("#### $faction — $($members.Count)");$parts.Add('')
    $raw=RawPage $members $name $true
    $table=[regex]::Match($raw,'(?s)\| Фракция \| Координаты.*?(?=\r?\n\r?\n\[Полные)').Value;Assert ([bool]$table) 'Missing faction table'
    foreach($line in $table -split '\r?\n'){$cells=$line.Split('|');Assert ($cells.Count -eq 8) 'Unexpected columns';$parts.Add('|'+(($cells[@(2,3,4,6)]) -join '|')+'|')}
    $parts.Add('')
   }
   continue
  }
  $raw=RawPage $subset $name $compact
  $pattern=if($compact){'(?s)\| Фракция \| Координаты.*?(?=\r?\n\r?\n\[Полные)'}else{'(?s)\| Точка \|.*?(?=\r?\n\r?\n\[Полные)'}
  $table=[regex]::Match($raw,$pattern).Value;Assert ([bool]$table) 'Missing mode table';$parts.Add($table);$parts.Add('')
 }
 $parts -join "`n"
}

$categories=[ordered]@{control_points='Контрольные точки';harbors='Доки';supply_depots='Склады припасов';starting_bases='Стартовые базы';settlements='Города и деревни';checkpoints='Блокпосты';other='Другое';unassigned='Без локации'}
function FactionLocationTables($rows,$name,$hidePeriod=$false){
 $parts=[Collections.Generic.List[string]]::new()
 foreach($all in @($false,$true)){
  $subset=@($rows|Where-Object {$_.requireAllIncludedLabels -eq $all});$label=if($all){'Все'}else{'Любая'}
  if(!$subset.Count){continue};$parts.Add("### Режим «$label» — $($subset.Count)");$parts.Add('')

  foreach($category in $categories.Keys){
   $categoryRows=@($subset|Where-Object {if($category -eq 'unassigned'){!$_.location}else{$_.location -and $_.location.category -eq $category}})
   if(!$categoryRows.Count){continue}
   $parts.Add("#### $($categories[$category]) — $($categoryRows.Count)");$parts.Add('')
   $groups=@($categoryRows|Group-Object {if($_.location){$_.location.id}else{'unassigned'}}|Sort-Object @{Expression={if($_.Group[0].location){$_.Group[0].location.name}else{'Без локации'}}},Name)
   if($category -eq 'checkpoints'){
    $parts.Add('Блокпостами считаем точки появления машин в пределах 50 м по X/Z от ближайшего префаба, содержащего Barricade или Checkpoint в имени файла. При совпадении расстояний выбирается ID. Это географическая привязка, не подтверждение принадлежности машины объекту; прежние локации и кандидаты сохранены в JSON.');$parts.Add('')
    $groups=@([pscustomobject]@{Group=$categoryRows;Count=$categoryRows.Count})
   }
  foreach($group in $groups){
   $loc='Без локации';if($group.Group[0].location){$loc=$group.Group[0].location.name}
   if($category -notin @('checkpoints','unassigned')){$parts.Add("##### $loc — $($group.Count)");$parts.Add('')}
   $raw=RawPage $group.Group $name $false
   $table=[regex]::Match($raw,'(?s)\| Точка \|.*?(?=\r?\n\r?\n\[Полные)').Value;Assert ([bool]$table) 'Missing faction table'
   foreach($line in $table -split '\r?\n'){
    if(!$line.StartsWith('|')){continue}
    $cells=$line.Split('|');Assert ($cells.Count -eq 10) 'Unexpected faction columns'
    if($hidePeriod){$parts.Add('|'+(($cells[@(3,6,8)]) -join '|')+'|')}else{$parts.Add('|'+(($cells[@(3,5,6,8)]) -join '|')+'|')}
   }
   $parts.Add('')
  }
  }
 }
 $parts -join "`n"
}
function Page($rows,$name,$withSummary=$false,$groupByFaction=$false){
 $raw=RawPage $rows $name $withSummary
 $pattern=if($withSummary){'(?s)\| Фракция \| Координаты.*?(?=\r?\n\r?\n\[Полные)'}else{'(?s)\| Точка \|.*?(?=\r?\n\r?\n\[Полные)'}
 $replacement=$modeExplanation+"`n`n"+(ModeTables $rows $name $withSummary $groupByFaction)
 [regex]::Replace($raw,$pattern,[Text.RegularExpressions.MatchEvaluator]{param($m)$replacement})
}
foreach($g in $records|Group-Object faction){
 $lines=[Collections.Generic.List[string]]::new();$lines.Add("# $($g.Name)");$lines.Add('');$lines.Add('[Сводка](../Summary.md)');$lines.Add('');$lines.Add("Всего точек: **$($g.Count)**.");$lines.Add('');$lines.Add('> **Для проверки:** в начале показаны точки с m_iRespawnPeriod = 0 — повторное появление отключено. Это может быть намеренной настройкой; само по себе значение не доказывает ошибку.');$lines.Add('')
 $lines.Add($modeExplanation);$lines.Add('');foreach($repeat in @($false,$true)){$rows=@($g.Group|Where-Object {($_.respawnPeriodSeconds -gt 0) -eq $repeat});if(!$rows.Count){continue};$periods=@($rows|ForEach-Object respawnPeriodSeconds|Sort-Object -Unique);$hidePeriod=!$repeat -or $periods.Count -eq 1;$title=if($repeat){'С повторным появлением'}else{'Без повторного появления'};if($repeat -and $periods.Count -eq 1){$minutes=([double]$periods[0]/60).ToString('0.###',[Globalization.CultureInfo]::InvariantCulture);$title+=' (раз в '+$minutes+' минут)'};$lines.Add("## $title — $($rows.Count)");$lines.Add('');if($rows.Count){if($repeat){$lines.Add('| Категория локаций | Точек с повторным появлением |');$lines.Add('| --- | ---: |');foreach($category in $categories.Keys){$count=@($rows|Where-Object {if($category -eq 'unassigned'){!$_.location}else{$_.location -and $_.location.category -eq $category}}).Count;if($count){$lines.Add("| $($categories[$category]) | $count |")}};$lines.Add("| **Всего** | **$($rows.Count)** |");$lines.Add('')};$lines.Add((FactionLocationTables $rows $g.Name $hidePeriod))}else{$lines.Add('Таких точек нет.')};$lines.Add('')}
 $lines.Add('[Полные поля и источники](../SpawnPoints.json).');Save "Vehicles/Factions/$($g.Name).md" ($lines -join "`n")
}
function LocationStem($name){$s=[regex]::Replace($name,'[^\p{L}\p{Nd}_-]+','-').Trim('-');if(!$s){$s='Unnamed'};if($s -match '^(CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9])$'){$s='Location-'+$s};return $s}
$locationRows=@();$groups=@($records|Group-Object {if($_.location -and $_.location.category -eq 'checkpoints'){'all-checkpoints'}elseif($_.location){$_.location.id}else{'unassigned'}}|Sort-Object Name);$stemCounts=@{}
foreach($group in $groups){$label='Без локации';if($group.Group[0].location){$label=$group.Group[0].location.name};if($group.Name -eq 'all-checkpoints'){$label='Блокпосты'};$stem=LocationStem $label;if(!$stemCounts.ContainsKey($stem)){$stemCounts[$stem]=0};$stemCounts[$stem]++}
foreach($g in $groups){$name='Без локации';$category='unassigned';if($g.Group[0].location){$name=$g.Group[0].location.name;$category=$g.Group[0].location.category};if($g.Name -eq 'all-checkpoints'){$name='Блокпосты'};$stem=LocationStem $name;if($stemCounts[$stem] -gt 1){$sha=[Security.Cryptography.SHA256]::Create();try{$suffix=([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($g.Name)))).Replace('-','').Substring(0,8).ToLowerInvariant()}finally{$sha.Dispose()};$stem+='-'+$suffix};$file=$stem+'.md';$locationRows+=[pscustomobject]@{name=$name;category=$category;file=$file;count=$g.Count;records=$g.Group}; $page=Page $g.Group $name $true ($g.Name -eq 'all-checkpoints');$page=(@($page -split '\r?\n'|ForEach-Object {$cells=$_.Split('|');if($_.StartsWith('|') -and $cells.Count -eq 8){'|'+(($cells[@(1,2,3,4,6)]) -join '|')+'|'}else{$_}}) -join "`n");if($g.Name -eq 'all-checkpoints'){$page=$page.Replace('## Точки','Блокпостами считаются точки машин в пределах 50 м по X/Z от ближайшего префаба Barricade или Checkpoint. Это географическая привязка; отдельные объекты и кандидаты сохранены в JSON.'+"`n`n"+'## Точки')};}

$summary.Add('| Категория | Точек |');$summary.Add('| --- | ---: |')
foreach($category in $categories.Keys){
 $rows=@($locationRows|Where-Object category -ceq $category|Sort-Object name,file);if(!$rows.Count){continue}
 $total=($rows|Measure-Object count -Sum).Sum;$categoryFile=(LocationStem $categories[$category])+'.md'
 $summary.Add("| [$($categories[$category])](Categories/$categoryFile) | $total |")
 $page=[Collections.Generic.List[string]]::new();$page.Add("# $($categories[$category])");$page.Add('');$page.Add('[Сводка машин](../Summary.md)');$page.Add('');$page.Add('| Локация | Точек |');$page.Add('| --- | ---: |')
 foreach($row in $rows){$page.Add("| $($row.name) | $($row.count) |")}
 $page.Add("| **Всего** | **$total** |")
  $page.Add('');if($category -eq 'checkpoints'){$page.Add('Блокпостами считаются точки машин в пределах 50 м по X/Z от ближайшего префаба Barricade или Checkpoint. Это географическая привязка; исходные объекты и кандидаты сохранены в JSON.');$page.Add('')};$page.Add($modeExplanation);$page.Add('')
  foreach($row in $rows){
   if($category -notin @('checkpoints','unassigned')){$page.Add("## $($row.name) — $($row.count)");$page.Add('')}
   $tables=ModeTables $row.records $row.name $true ($category -eq 'checkpoints')
   foreach($line in $tables -split '\r?\n'){$cells=$line.Split('|');if($line.StartsWith('|') -and $cells.Count -eq 8){$page.Add('|'+(($cells[@(1,2,3,4,6)]) -join '|')+'|')}else{$page.Add($line)}}
   $page.Add('')
  }
  $page.Add('[Полные поля и источники](../SpawnPoints.json).')
 Save "Vehicles/Categories/$categoryFile" ($page -join "`n")
}
$summary.Add("| **Всего** | **$($records.Count)** |")
$summary.Add('');$summary.Add('## Откуда данные и как работает появление');$summary.Add('');$summary.Add('Позиция — worldPosition сущности с SCR_AmbientVehicleSpawnPointComponent; фракция — SCR_FactionAffiliationComponent → faction affiliation. Время — m_iRespawnPeriod, секунды / 60; 0 отключает повторное появление. Фильтры — m_aIncludedEditableEntityLabels, m_aExcludedEditableEntityLabels и m_bRequireAllIncludedLabels. Имена меток прочитаны из EEditableEntityLabel установленной игры 1.8.0.13.');$summary.Add('');$summary.Add('В Update компонент получает VEHICLE-каталог фракции, вызывает GetFullFilteredEntityListWithLabels и выбирает случайный элемент. Таймер повторного появления не означает гарантированный спавн строго каждые 10 минут: система учитывает состояние машины, близость игроков, флаг SpawnVehicles и доступное место. SpawnVehicle дополнительно проверяет свободную позицию. Фактический спавн здесь не измерялся.');$summary.Add('');$summary.Add('[Канонические данные](SpawnPoints.json).');Save 'Vehicles/Summary.md' ($summary -join "`n")
Json 'world.json' ([ordered]@{schemaVersion=3;snapshotId=$snapshot;revisionId=$RevisionId;gameVersion=$d.gameVersion;worldPath=$d.worldPath;normalizerVersion='ambient-vehicles-0.2';status='partial';sourceCapturedAtUTC=$d.generatedAtUTC})
Json 'data.json' ([ordered]@{schemaVersion=3;snapshotId=$snapshot;status='partial';sections=@{vehicles=@{data='Vehicles/SpawnPoints.json';summary='Vehicles/Summary.md';status='partial'};ai=@{data='../r0057/AI/Groups.json';status='unchanged'};supplies=@{data='../r0046/data.json';status='unchanged'}}})
"Vehicle points: $($records.Count)"
