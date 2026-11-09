[CmdletBinding()]
param([Parameter(Mandatory)][string]$InventoryLogPath,[Parameter(Mandatory)][string]$OutputDirectory)
$ErrorActionPreference='Stop'; Set-StrictMode -Version Latest
function Assert($ok,$message){if(!$ok){throw $message}}
function Save($path,$text){[IO.File]::WriteAllText($path,$text.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
$groups=Get-Content "$OutputDirectory/AI/Groups.json" -Raw | ConvertFrom-Json
Assert (!(Test-Path "$OutputDirectory/AI/Medical.json")) 'Medical report already exists.'
$log=Get-Content $InventoryLogPath
$lines=@($log | Where-Object {$_ -match '\[ME_CA_AI_WEAPONS\]'} | ForEach-Object {$_ -replace '^.*\[ME_CA_AI_WEAPONS\] ',''})
Assert (@($lines | Where-Object {$_ -like 'BEGIN|*'}).Count -eq 1) 'Expected one capture.'
Assert ($lines[0] -ceq "BEGIN|$($groups.gameVersion)") 'Mixed versions.'
Assert (!@($lines | Where-Object {$_ -match '^(ERROR|INVENTORY_UNRESOLVED)\|'}).Count) 'Incomplete inventory.'
$characters=[ordered]@{}
foreach($line in $lines){
 $p=$line.Split('|')
 if($p[0] -ceq 'CHARACTER'){
  Assert (!$characters.Contains($p[1])) 'Duplicate character.'
  $characters[$p[1]]=[ordered]@{prefab=$p[1];morphine=0;bandages=0;tourniquets=0;items=@()}
 }
 if($p[0] -ceq 'ITEM'){
  $kind=switch -Regex ($p[3]){
   '/Medicine/MorphineInjection_01/MorphineInjection_01\.et$' {'morphine';break}
   '/Medicine/FieldDressing_01/FieldDressing_(USSR|US)_01\.et$' {'bandages';break}
   '/Medicine/Tourniquet_01/Tourniquet_(USSR|US)_01\.et$' {'tourniquets';break}
   default {$null}
  }
  if($kind){$characters[$p[1]][$kind]++;$characters[$p[1]].items+= [ordered]@{entryIndex=[int]$p[2];kind=$kind;prefab=$p[3];field='SCR_InventoryStorageManagerComponent.InitialInventoryItems[].PrefabsToSpawn[]'}}
 }
}
Assert ($lines[-1] -ceq "COMPLETE|$($characters.Count)") 'Incomplete capture.'
$required=@($groups.catalog.unitPrefabs | Sort-Object -Unique)
Assert ($required.Count -eq $characters.Count) 'Coverage mismatch.'
foreach($prefab in $required){Assert ($characters.Contains($prefab)) "Missing $prefab"}
$variants=@()
foreach($entry in $groups.catalog){
 $members=@();$total=[ordered]@{morphine=0;bandages=0;tourniquets=0}
 foreach($unit in $entry.unitPrefabs | Group-Object | Sort-Object Name){
  $c=$characters[$unit.Name]
  $members+=[ordered]@{prefab=$unit.Name;unitCount=$unit.Count;morphinePerUnit=$c.morphine;bandagesPerUnit=$c.bandages;tourniquetsPerUnit=$c.tourniquets}
  foreach($key in @('morphine','bandages','tourniquets')){$total[$key]+=$c[$key]*$unit.Count}
 }
 $variants+=[ordered]@{type=$entry.type;catalogId=$entry.id;totals=$total;members=$members}
 $pagePath="$OutputDirectory/AI/Types/$($entry.type).md"
 $page=Get-Content $pagePath -Raw
 $intro='**Цель справочника:** проверять состав и снаряжение группы, в том числе количество морфия, бинтов и жгутов, и находить бойцов, у которых они отсутствуют в начальном инвентаре конфигурации.'
 $page=$page.Replace("# $($entry.type)","# $($entry.type)`n`n$intro")
 $table=[Collections.Generic.List[string]]::new()
 $table.Add('## Медицинское снаряжение');$table.Add('')
 $table.Add("Всего на группу по спискам начального инвентаря: **морфий — $($total.morphine), бинты — $($total.bandages), жгуты — $($total.tourniquets)**.")
 $table.Add('');$table.Add('Количество в строке — на одного бойца; в итоге повторяющиеся бойцы учтены отдельно. **0** означает отсутствие предмета в прочитанном InitialInventoryItems, а не проверенное отсутствие у созданного персонажа. Содержимое префабов одежды и рюкзаков и изменения во время игры не исследованы.');$table.Add('')
 $table.Add('| Prefab бойца | Бойцов | Морфий на бойца | Бинты на бойца | Жгуты на бойца |');$table.Add('| --- | ---: | ---: | ---: | ---: |')
 foreach($member in $members){$table.Add("| $([IO.Path]::GetFileNameWithoutExtension($member.prefab)) | $($member.unitCount) | $($member.morphinePerUnit) | $($member.bandagesPerUnit) | $($member.tourniquetsPerUnit) |")}
 $table.Add('');$table.Add('[Исходные медицинские предметы и подсчёт](../Medical.json).')
 Save $pagePath ($page+"`n"+($table -join "`n"))
}
$report=[ordered]@{schemaVersion=1;kind='ambient-ai-initial-medical-items';snapshotId=$groups.snapshotId;gameVersion=$groups.gameVersion;normalizerVersion='ambient-ai-medical-0.1';captureLogSha256=(Get-FileHash $InventoryLogPath).Hash;captureLogLastWriteTimeUTC=(Get-Item $InventoryLogPath).LastWriteTimeUtc.ToString('o');source='reused_complete_inherited_character_inventory_capture';scope='matching_morphine_field_dressing_tourniquet_entries_in_InitialInventoryItems_PrefabsToSpawn';runtimeMeasured=$false;nestedEquipmentInventoryInspected=$false;countingRule='one_per_resource_occurrence_in_resolved_array; multiply_by_character_slots_in_group';characters=@($characters.Values);variants=$variants}
Save "$OutputDirectory/AI/Medical.json" ($report | ConvertTo-Json -Depth 30)
$index=Get-Content "$OutputDirectory/data.json" -Raw | ConvertFrom-Json
$index.sections.ai | Add-Member -NotePropertyName medical -NotePropertyValue 'AI/Medical.json'
Save "$OutputDirectory/data.json" ($index | ConvertTo-Json -Depth 20)
Write-Output "Medical: $($characters.Count) characters; $($variants.Count) variants."
