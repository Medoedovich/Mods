[CmdletBinding()]
param([Parameter(Mandatory)][string]$WeaponsLogPath,[Parameter(Mandatory)][string]$OutputDirectory)
$ErrorActionPreference='Stop'; Set-StrictMode -Version Latest
function Assert($condition,$message){if(!$condition){throw $message}}
function Save($path,$value){[IO.File]::WriteAllText($path,$value.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
function Label($resource){
 $name=[IO.Path]::GetFileNameWithoutExtension($resource)
 $names=@{Rifle_VZ58P='Vz. 58 P';Rifle_VZ58V='Vz. 58 V';MG_UK59_4x8='UK vz. 59 (4×8)';Handgun_PM='ПМ';Launcher_RPG75='RPG-75';Launcher_RPG7='RPG-7';Rifle_SVD_PSO='СВД (ПСО)';Grenade_RGD5='РГД-5';Smoke_RDG2='РДГ-2 (дым)'}
 if($names.ContainsKey($name)){return $names[$name]}; return $name
}
$groups=Get-Content "$OutputDirectory/AI/Groups.json" -Raw | ConvertFrom-Json
Assert (!(Test-Path "$OutputDirectory/AI/Weapons.json")) 'Weapons report exists; preserve published revisions.'
$log=Get-Content -LiteralPath $WeaponsLogPath
$markers=@($log | Where-Object {$_ -match '\[ME_CA_AI_WEAPONS\]'} | ForEach-Object {$_ -replace '^.*\[ME_CA_AI_WEAPONS\] ',''})
Assert (@($markers | Where-Object {$_ -like 'BEGIN|*'}).Count -eq 1) 'Expected one capture.'
Assert ($markers[0] -ceq "BEGIN|$($groups.gameVersion)") 'Mixed game versions.'
Assert (!@($markers | Where-Object {$_ -match '^(ERROR|INVENTORY_UNRESOLVED)\|'}).Count) 'Unresolved capture.'
$characters=[ordered]@{}
foreach($line in $markers){
 $p=$line.Split('|')
 switch($p[0]){
  CHARACTER {Assert (!$characters.Contains($p[1])) 'Duplicate character.'; $characters[$p[1]]=[ordered]@{prefab=$p[1];slots=@();initialWeaponInventory=@()}}
  SLOT {Assert ($p.Count -eq 6 -and $p[5] -ceq '1') 'Unresolved slot.'; $characters[$p[1]].slots+= [ordered]@{componentIndex=[int]$p[2];componentClass=$p[3];field='WeaponTemplate';prefab=$p[4];name=$(if($p[4]){Label $p[4]}else{$null})}}
  ITEM {if($p[3] -match 'Prefabs/Weapons/'){ $characters[$p[1]].initialWeaponInventory += [ordered]@{entryIndex=[int]$p[2];field='InitialInventoryItems[].PrefabsToSpawn[]';prefab=$p[3]}}}
 }
}
Assert ($markers[-1] -ceq "COMPLETE|$($characters.Count)") 'Incomplete capture.'
$required=@($groups.catalog.unitPrefabs | Sort-Object -Unique)
Assert ($required.Count -eq $characters.Count) 'Character coverage mismatch.'
foreach($unit in $required){Assert ($characters.Contains($unit)) "Missing $unit"; Assert ($characters[$unit].slots.Count -gt 0) 'Missing slots.'}
$variants=@()
foreach($entry in $groups.catalog){
 $weaponList=@(); $members=@()
 foreach($unit in $entry.unitPrefabs | Group-Object | Sort-Object Name){
  $character=$characters[$unit.Name]
  $weapons=@($character.slots | Where-Object {$_.componentClass -ceq 'CharacterWeaponSlotComponent' -and $_.prefab})
  $grenades=@($character.slots | Where-Object {$_.componentClass -ceq 'CharacterGrenadeSlotComponent' -and $_.prefab} | ForEach-Object name)
  $members+=[ordered]@{prefab=$unit.Name;count=$unit.Count;weapons=@($weapons | ForEach-Object prefab);grenadeSlotTemplates=$grenades}
  for($i=0;$i -lt $unit.Count;$i++){ $weaponList+=@($weapons | ForEach-Object prefab) }
 }
 $totals=@($weaponList | Group-Object | ForEach-Object {[pscustomobject][ordered]@{prefab=$_.Name;name=(Label $_.Name);count=$_.Count}} | Sort-Object @{Expression='count';Descending=$true},name)
 $variants+=[ordered]@{catalogId=$entry.id;type=$entry.type;unitCount=$entry.unitCount;members=$members;weaponTotals=$totals}
 $path="$OutputDirectory/AI/Types/$($entry.type).md"
 $page=Get-Content $path -Raw
 $table=[Collections.Generic.List[string]]::new()
 $table.Add('## Вооружение группы');$table.Add('');$table.Add('| Оружие | Количество |');$table.Add('| --- | ---: |')
 foreach($weapon in $totals){$table.Add("| $($weapon.name) | $($weapon.count) |")}
 $table.Add('');$table.Add('## Состав бойцов');$table.Add('');$table.Add('| Prefab бойца | Количество | Оружие у каждого | Тип гранаты в слоте |');$table.Add('| --- | ---: | --- | --- |')
 foreach($member in $members){
  $weapons=(@($member.weapons | ForEach-Object {Label $_}) -join '; ');if(!$weapons){$weapons='пустые оружейные слоты'}
  $grenades=$member.grenadeSlotTemplates -join '; ';if(!$grenades){$grenades='—'}
  $table.Add("| $([IO.Path]::GetFileNameWithoutExtension($member.prefab)) | $($member.count) | $weapons | $grenades |")
 }
 $table.Add('');$table.Add('Вооружение прочитано из унаследованных CharacterWeaponSlotComponent.WeaponTemplate; повторяющиеся бойцы учитываются отдельно. Тип гранаты — шаблон CharacterGrenadeSlotComponent, а не количество гранат. Боезапас, содержимое одежды и изменения после появления здесь не суммируются; это конфигурация префабов, не измеренный боевой состав.');$table.Add('');$table.Add('[Оружейные слоты, начальный оружейный инвентарь и происхождение](../Weapons.json).')
 $page=[regex]::Replace($page,'(?s)\| Prefab бойца \|.*?(?=\[Исходные ресурсы)',[System.Text.RegularExpressions.MatchEvaluator]{param($m) ($table -join "`n")+"`n`n"})
 Save $path $page
}
$report=[ordered]@{schemaVersion=1;kind='ambient-ai-character-weapons';snapshotId=$groups.snapshotId;gameVersion=$groups.gameVersion;normalizerVersion='ambient-ai-weapons-0.1';captureLogSha256=(Get-FileHash $WeaponsLogPath).Hash;captureLogLastWriteTimeUTC=(Get-Item $WeaponsLogPath).LastWriteTimeUtc.ToString('o');scope='resolved_character_weapon_and_grenade_slots_and_initial_weapon_inventory';runtimeMeasured=$false;countingRule='one_weapon_per_nonempty_CharacterWeaponSlotComponent_per_unit_slot; grenade_templates_not_counted';characters=@($characters.Values);variants=$variants}
Save "$OutputDirectory/AI/Weapons.json" ($report | ConvertTo-Json -Depth 30)
$index=Get-Content "$OutputDirectory/data.json" -Raw | ConvertFrom-Json
$index.sections.ai | Add-Member -NotePropertyName weapons -NotePropertyValue 'AI/Weapons.json'
Save "$OutputDirectory/data.json" ($index | ConvertTo-Json -Depth 20)
$summary=Get-Content "$OutputDirectory/AI/Summary.md" -Raw
Save "$OutputDirectory/AI/Summary.md" ($summary+"`nВооружение каждого варианта приведено на странице типа: сумма по группе и оружие каждого бойца. [Оружейные слоты и происхождение](Weapons.json).`n")
Write-Output "Weapons: $($characters.Count) characters; $($variants.Count) group variants."
