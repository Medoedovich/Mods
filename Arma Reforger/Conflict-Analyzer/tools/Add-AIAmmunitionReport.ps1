[CmdletBinding()]
param([Parameter(Mandatory)][string]$InventoryRuntimeLogPath,[Parameter(Mandatory)][string]$OutputDirectory)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
function Assert($ok,$text){if(!$ok){throw $text}}
function Save($p,$s){[IO.File]::WriteAllText($p,$s.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
function Name($p){$n=[IO.Path]::GetFileNameWithoutExtension($p);$names=@{Magazine_762x39_Vz58_30rnd_Last_5Tracer='Vz. 58, последние 5 трассирующие';Magazine_762x39_Vz58_30rnd_Tracer='Vz. 58, трассирующие';Magazine_762x54_SVD_10rnd_Sniper='СВД, снайперские';Magazine_762x54_SVD_10rnd_7BZ3API='СВД, 7БЗ3';Magazine_9x18_PM_8rnd_Ball='ПМ';Box_762x54_UK59_50rnd_4Ball_1Tracer='UK vz. 59, 4 обычных / 1 трассирующий';Grenade_RGD5='РГД-5';Smoke_RDG2='РДГ-2 (дым)'};if($names.ContainsKey($n)){return $names[$n]};return $n}
$groups=Get-Content "$OutputDirectory/AI/Groups.json" -Raw | ConvertFrom-Json
Assert (!(Test-Path "$OutputDirectory/AI/Ammunition.json")) 'Output exists.'
$lines=@(Get-Content $InventoryRuntimeLogPath | Where-Object {$_ -match '\[ME_CA_AI_INV\]'} | ForEach-Object {$_ -replace '^.*\[ME_CA_AI_INV\] ',''})
Assert ($lines[0] -ceq "BEGIN|$($groups.gameVersion)") 'Wrong version.'
Assert (@($lines | Where-Object {$_ -like 'BEGIN|*'}).Count -eq 1) 'Multiple captures.'
Assert (!@($lines | Where-Object {$_ -like 'ERROR|*'}).Count) 'Failed character capture.'
$characters=[ordered]@{}
foreach($prefab in @($groups.catalog.unitPrefabs | Sort-Object -Unique)){$characters[$prefab]=[ordered]@{prefab=$prefab;items=@();muzzles=@();captured=$false;grenadeApiCount=$null}}
foreach($line in $lines){$p=$line.Split('|');if($p[0] -in @('ITEM','MUZZLE','CHARACTER')){Assert ($characters.Contains($p[1])) 'Unknown character';$c=$characters[$p[1]];switch($p[0]){
 ITEM {$c.items += [pscustomobject][ordered]@{prefab=$p[2];loaded=($p[3] -ceq '1' -or $p[3] -ceq 'true');rounds=[int]$p[4];capacity=[int]$p[5]}}
 MUZZLE {$c.muzzles += [pscustomobject][ordered]@{weaponPrefab=$p[2];ammoCount=[int]$p[3];chambered=($p[4] -ceq '1' -or $p[4] -ceq 'true')}}
 CHARACTER {Assert (!$c.captured) 'Duplicate character';$c.captured=$true;$c.grenadeApiCount=[int]$p[2]}
}}}
Assert ($lines[-1] -ceq "COMPLETE|$($characters.Count)") 'Incomplete capture.'
foreach($c in $characters.Values){Assert $c.captured 'Missing character';$c.magazines=@($c.items | Where-Object {$_.prefab -match '/Magazines/'});$c.grenades=@($c.items | Where-Object {$_.prefab -match '/Grenades/'});foreach($mag in $c.magazines){Assert ($mag.rounds -ge 0 -and $mag.rounds -le $mag.capacity) 'Invalid magazine count'};$c.magazineCount=$c.magazines.Count;$c.roundsInMagazines=[int](($c.magazines | Measure-Object rounds -Sum).Sum);$c.chamberedRounds=@($c.muzzles | Where-Object {$_.chambered -and $_.weaponPrefab -match '/(Rifles|MachineGuns|Handguns)/'}).Count;$c.grenadeCount=$c.grenades.Count}
$variants=@()
foreach($entry in $groups.catalog){
 $allMags=@();$allGrenades=@();$members=@();$chambers=0
 foreach($unit in $entry.unitPrefabs | Group-Object | Sort-Object Name){$c=$characters[$unit.Name];$members+=[ordered]@{prefab=$unit.Name;count=$unit.Count;magazinesPerUnit=$c.magazineCount;roundsInMagazinesPerUnit=$c.roundsInMagazines;chamberedRoundsPerUnit=$c.chamberedRounds;grenadesPerUnit=$c.grenadeCount};for($i=0;$i -lt $unit.Count;$i++){$allMags+=$c.magazines;$allGrenades+=$c.grenades;$chambers+=$c.chamberedRounds}}
 $rows=@($allMags | Group-Object prefab,loaded,rounds,capacity | ForEach-Object {$first=$_.Group[0];[pscustomobject][ordered]@{prefab=$first.prefab;loaded=$first.loaded;roundsPerMagazine=$first.rounds;capacity=$first.capacity;count=$_.Count;totalRounds=$first.rounds*$_.Count}} | Sort-Object prefab,loaded,roundsPerMagazine)
 $grenades=@($allGrenades | Group-Object prefab | ForEach-Object {[ordered]@{prefab=$_.Name;count=$_.Count}})
 $totalRounds=[int](($allMags | Measure-Object rounds -Sum).Sum)
 $variants+=[ordered]@{type=$entry.type;magazineCount=$allMags.Count;roundsInMagazines=$totalRounds;chamberedRounds=$chambers;grenadeCount=$allGrenades.Count;magazines=$rows;grenades=$grenades;members=$members}
 $text=[Collections.Generic.List[string]]::new();$text.Add('## Магазины, патроны и гранаты');$text.Add('');$text.Add("Всего на группу: **$($allMags.Count) магазинов / коробок, $totalRounds патронов в них; отдельно $chambers в патронниках. Гранат — $($allGrenades.Count)** (осколочные и дымовые вместе).")
 $text.Add('');$text.Add('Измерено у отдельных тестовых персонажей через 0.5 с после создания в игре 1.8.0.13. Магазины в оружии включены один раз; патроны в патронниках вынесены отдельно. Это опыт со стартовым снаряжением префабов, не аудит действующих патрулей миссии. Сигнальные средства и выстрелы RPG не входят в число ручных гранат или патронов стрелкового оружия.');$text.Add('')
 $text.Add('| Магазин / коробка | Где | Количество | Патронов в каждом / вместимость | Всего патронов |');$text.Add('| --- | --- | ---: | ---: | ---: |')
 foreach($row in $rows){$where=if($row.loaded){'в оружии'}else{'запас'};$text.Add("| $(Name $row.prefab) | $where | $($row.count) | $($row.roundsPerMagazine) / $($row.capacity) | $($row.totalRounds) |")}
 $text.Add('');$text.Add('| Граната | Всего в группе |');$text.Add('| --- | ---: |');foreach($grenade in $grenades){$text.Add("| $(Name $grenade.prefab) | $($grenade.count) |")};if(!$grenades.Count){$text.Add('| Нет | 0 |')}
 $text.Add('');$text.Add('Количество ниже — на одного бойца.');$text.Add('');$text.Add('| Prefab бойца | Бойцов | Магазинов / коробок | Патронов в магазинах | В патронниках | Гранат |');$text.Add('| --- | ---: | ---: | ---: | ---: | ---: |')
 foreach($member in $members){$text.Add("| $([IO.Path]::GetFileNameWithoutExtension($member.prefab)) | $($member.count) | $($member.magazinesPerUnit) | $($member.roundsInMagazinesPerUnit) | $($member.chamberedRoundsPerUnit) | $($member.grenadesPerUnit) |")}
 $text.Add('');$text.Add('[Измеренные предметы, магазины и расчёты](../Ammunition.json).')
 $path="$OutputDirectory/AI/Types/$($entry.type).md";$page=Get-Content $path -Raw
 $page=$page.Replace('количество морфия, бинтов и жгутов','количество морфия, бинтов, жгутов, магазинов, патронов и гранат')
 Save $path ($page+"`n"+($text -join "`n"))
}
$report=[ordered]@{schemaVersion=1;kind='ai-prototype-ammunition-measurement';snapshotId=$groups.snapshotId;gameVersion=$groups.gameVersion;normalizerVersion='ai-ammunition-0.1';captureLogSha256=(Get-FileHash $InventoryRuntimeLogPath).Hash;captureLogLastWriteTimeUTC=(Get-Item $InventoryRuntimeLogPath).LastWriteTimeUtc.ToString('o');runtimeMeasured=$true;scope='isolated_spawned_character_prototypes_500ms_after_spawn_not_live_patrols';deduplication='unique_entity_identity; loaded_magazines_added_only_if_absent';characters=@($characters.Values);variants=$variants}
Save "$OutputDirectory/AI/Ammunition.json" ($report | ConvertTo-Json -Depth 30)
$index=Get-Content "$OutputDirectory/data.json" -Raw | ConvertFrom-Json;$index.sections.ai | Add-Member -NotePropertyName ammunition -NotePropertyValue 'AI/Ammunition.json';Save "$OutputDirectory/data.json" ($index | ConvertTo-Json -Depth 20)
Write-Output "Ammunition: $($characters.Count) characters; $($variants.Count) variants."
