[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$DiagnosticsPath,
    [Parameter(Mandatory)][string]$ContainerDetailsPath,
    [Parameter(Mandatory)][string]$CommandPostStoragePath,
    [Parameter(Mandatory)][string]$GameCodeDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [string]$RevisionId='r0045'
)
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
function Assert($ok,$message){if(!$ok){throw $message}}
function InputData($path){[ordered]@{sha256=(Get-FileHash -LiteralPath $path).Hash;data=(Get-Content -LiteralPath $path -Raw | ConvertFrom-Json)}}
function Field($fields,$name){$f=@($fields | Where-Object name -ceq $name);Assert ($f.Count -eq 1 -and $f[0].status -ceq 'resolved') "Unresolved field $name";return $f[0]}
function N($v){([double]$v).ToString('0.###',[Globalization.CultureInfo]::InvariantCulture)}
function Pos($v){(@($v | ForEach-Object {([double]$_).ToString('0.000',[Globalization.CultureInfo]::InvariantCulture)}) -join ' ')}
function Save($rel,$text){$p=Join-Path $OutputDirectory $rel;New-Item -ItemType Directory (Split-Path $p) -Force | Out-Null;[IO.File]::WriteAllText($p,$text.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))}
Assert (!(Test-Path -LiteralPath $OutputDirectory)) 'Output exists; use a new revision.'
$diag=InputData $DiagnosticsPath;$physical=InputData $ContainerDetailsPath;$cp=InputData $CommandPostStoragePath
Assert ($diag.data.gameVersion -ceq $cp.data.gameVersion) 'Game version mismatch.'
Assert ($physical.data.snapshotId.StartsWith($diag.data.gameVersion+'/')) 'Container version mismatch.'
$gm=@($diag.data.entities | Where-Object className -ceq 'SCR_GameModeCampaign');Assert ($gm.Count -eq 1) 'Ambiguous game mode.';$gm=$gm[0]
$modeFields=@('m_bSuppliesAutoRegenerationEnabled','m_iHQStartingSupplies','m_iQuickSuppliesReplenishThreshold','m_fQuickSuppliesReplenishMultiplier','m_iRegularSuppliesIncome','m_iSuppliesArrivalInterval')
$mode=[ordered]@{};foreach($name in $modeFields){$mode[$name]=Field $gm.fields $name}
Assert ($mode.m_bSuppliesAutoRegenerationEnabled.value -ceq 'false') 'Auto regeneration requires different effective income rule.'
$variants=@($cp.data.records | Where-Object {$_.variantId -match 'US'});Assert ($variants.Count -eq 2) 'Expected US and USSR HQ variants.'
foreach($v in $variants){Assert ($v.capacityStatus -ceq 'resolved' -and $v.capacitySupplies -eq 1000) 'HQ capacity evidence changed.'}
$codeEvidence=@();foreach($rel in @('scripts/Game/GameMode/SCR_GameModeCampaign.c','scripts/Game/Components/Locations/SCR_CampaignMilitaryBaseComponent.c','Configs/Factions/US_Campaign.conf','Configs/Factions/USSR_Campaign.conf','Missions/23_Campaign_HQC_Everon.conf')){$path=Join-Path $GameCodeDirectory $rel;Assert (Test-Path $path) "Missing evidence $rel";$codeEvidence+=@{resource=$rel;sha256=(Get-FileHash $path).Hash}}
$header=Get-Content (Join-Path $GameCodeDirectory 'Missions/23_Campaign_HQC_Everon.conf') -Raw
Assert ($header -match 'm_bSuppliesAutoRegenerationEnabled 0') 'Mission regeneration override changed.'
$records=@()
foreach($entity in $diag.data.entities){
    $components=@($entity.components | Where-Object className -ceq 'SCR_CampaignMilitaryBaseComponent')
    if(!$components.Count){continue};Assert ($components.Count -eq 1) 'Multiple military base components.'
    $component=$components[0];$can=@($component.fields | Where-Object name -ceq 'm_bCanBeHQ')
    if(!$can.Count -or $can[0].status -cne 'resolved' -or $can[0].value -cne 'true'){continue}
    Assert ($entity.prefab.EndsWith('/ConflictBase_MOB.et')) 'Unexpected HQ candidate prefab; review capacity applicability.'
    Assert ($entity.positionStatus -ceq 'resolved') 'Unknown HQ coordinates.'
    $income=Field $component.fields 'm_iRegularSuppliesIncomeBase';$interval=Field $component.fields 'm_iSuppliesArrivalInterval';$disable=Field $component.fields 'm_bDisableWhenUnusedAsHQ';$type=Field $component.fields 'm_eType'
    Assert ($type.enumLabel -ceq 'BASE' -and [double]$income.value -ge 0 -and [double]$interval.value -gt 0) 'HQ rule requires review.'
    $supplies=@($entity.components | Where-Object className -ceq 'SCR_CampaignSuppliesComponent');Assert ($supplies.Count -eq 1) 'Missing legacy supplies component.'
    $slots=@($physical.data.records | Where-Object {$entity.sourceId -cin $_.ancestorSourceIds})
    $capacity=0.0;$initial=0.0;foreach($slot in $slots){Assert ($slot.capacityStatus -ceq 'resolved' -and $slot.configuredInitialStatus -ceq 'resolved') 'Unknown descendant supplies';$capacity+=$slot.capacitySupplies;$initial+=$slot.configuredInitialSupplies}
    $records+= [ordered]@{sourceId=$entity.sourceId;name=$entity.name;prefab=$entity.prefab;worldPositionMeters=$entity.worldPosition;subscene=$entity.subscene;layer=$entity.layer;selectionStatus='candidate_not_runtime_selected';factionStatus='assigned_at_runtime';canBeHQ=$true;disableWhenUnusedAsHQ=($disable.value -ceq 'true');commandPostCapacitySupplies=1000;commandPostCapacityScope='spawned_SERVICE_HQ_composition_US_or_USSR';runtimeNetworkCapacitySupplies=$null;runtimeNetworkCapacityStatus='not_measured';configuredHQStartingTarget=[double]$mode.m_iHQStartingSupplies.value;startingTargetScope='gamemode_default_subject_to_mission_header_override_not_measured_stock';incomePerCycle=[double]$income.value;arrivalIntervalSeconds=[double]$interval.value;arrivalIntervalMinutes=([double]$interval.value/60);incomeScope='base_income_when_selected_HQ_and_auto_regeneration_disabled_before_quick_replenishment_and_free_capacity';staticDescendantCapacity=$capacity;staticDescendantInitialSupplies=$initial;physicalSlots=$slots;fieldEvidence=@($can[0],$disable,$type,$income,$interval);legacyComponentEvidence=@((Field $supplies[0].fields 'm_iSupplies'),(Field $supplies[0].fields 'm_iSuppliesMax'))}
}
Assert ($records.Count -gt 0) 'No HQ candidates.'
$records=@($records | Sort-Object name)
$report=[ordered]@{schemaVersion=1;kind='starting-base-candidates';normalizerVersion='starting-bases-0.1';snapshotId="$($diag.data.gameVersion)/CTI_Campaign_HQC_Eden/$RevisionId";gameVersion=$diag.data.gameVersion;worldPath=$diag.data.worldPath;status='partial';runtimeMeasured=$false;capturedAtUTC=$diag.data.generatedAtUTC;generatedAtUTC=[DateTime]::UtcNow.ToString('o');candidateCount=$records.Count;accounting='non_additive_candidate_catalog_existing_static_slots_remain_in_original_supply_accounting';sources=@{diagnosticsSha256=$diag.sha256;containerDetailsSha256=$physical.sha256;containerSnapshotId=$physical.data.snapshotId;commandPostStorageSha256=$cp.sha256};codeEvidence=$codeEvidence;gameModeFields=$mode;commandPostVariants=$variants;records=$records}
Save 'Supplies/StartingBases.json' ($report | ConvertTo-Json -Depth 60)
$intro='Это возможные позиции главных баз, а не одновременно действующие HQ. SelectHQs выбирает позиции, SetHQFactions назначает стороны. Неиспользованные кандидаты отключаются при m_bDisableWhenUnusedAsHQ=true. Конкретная сторона и выбранные позиции в этом отчёте не измерены.'
$capacityNote='Вместимость КП — 1000 припасов у создаваемой композиции SERVICE_HQ (варианты US / USSR), подтверждено каталогом префабов. Полная вместимость сети базы не измерена: GetSuppliesMax() использует ResourceConsumer.GetAggregatedMaxResourceValue(). Поле SCR_CampaignSuppliesComponent.m_iSuppliesMax=3000 не подставляется вместо неё.'
$incomeNote="Базовое пополнение действует после выбора позиции как HQ при отключённой авторегенерации (в исходном мире и заголовке HQC она отключена). m_iRegularSuppliesIncomeBase — припасы за цикл; m_iSuppliesArrivalInterval / 60 — минуты. При запасе ниже $(N $mode.m_iQuickSuppliesReplenishThreshold.value) используется ускоренное пополнение с множителем $(N $mode.m_fQuickSuppliesReplenishMultiplier.value), ограниченное порогом и свободной вместимостью. Поэтому фактическая добавка может отличаться от базовой. Лимит количества циклов в рассмотренном алгоритме не задан; это периодическое пополнение, а не фиксированное число поставок."
$sum=[Collections.Generic.List[string]]::new();$sum.Add('# Стартовые позиции главных баз');$sum.Add('');$sum.Add('[Все категории](../Summary.md)');$sum.Add('');$sum.Add("Игра **$($diag.data.gameVersion)**; кандидатов **$($records.Count)**; ревизия **$RevisionId**.");$sum.Add('');$sum.Add($intro);$sum.Add('');$sum.Add($capacityNote);$sum.Add('');$sum.Add($incomeNote);$sum.Add('');$sum.Add('Сумма кандидатов не прибавляется к мировому запасу. Уже размещённые контейнеры сохраняют прежний учёт; динамический запас выбранных HQ нельзя умножать на количество кандидатов.');$sum.Add('')
$sum.Add('| Позиция | Вместимость КП, припасы | Базовое пополнение за цикл, припасы | Пополнение, мин. | Координаты X Y Z, м |');$sum.Add('| --- | ---: | ---: | ---: | --- |')
foreach($record in $records){
    $sum.Add("| [$($record.name)]($($record.name).md) | 1000 | $(N $record.incomePerCycle) | $(N $record.arrivalIntervalMinutes) | $(Pos $record.worldPositionMeters) |")
    $lines=[Collections.Generic.List[string]]::new();$lines.Add("# $($record.name)");$lines.Add('');$lines.Add('[Стартовые позиции — сводка](Summary.md) · [Все категории](../Summary.md)');$lines.Add('');$lines.Add($intro);$lines.Add('');$lines.Add("Координаты X Y Z: **$(Pos $record.worldPositionMeters)**.");$lines.Add('');$lines.Add('| Вместимость КП, припасы | Полная вместимость сети | Базовое пополнение за цикл, припасы | Пополнение, мин. |');$lines.Add('| ---: | --- | ---: | ---: |');$lines.Add("| 1000 | не измерена | $(N $record.incomePerCycle) | $(N $record.arrivalIntervalMinutes) |");$lines.Add('');$lines.Add($capacityNote);$lines.Add('');$lines.Add($incomeNote);$lines.Add('');$lines.Add("Целевой стартовый запас HQ по умолчанию GameMode: **$(N $record.configuredHQStartingTarget)**. Заголовок миссии может переопределить его; это целевой запас общей сети, не добавка к каждому ящику и не измерение после инициализации.");$lines.Add('');$lines.Add('## Уже размещённые вложенные контейнеры');$lines.Add('');$lines.Add("Вместимость / начальные припасы по конфигам: **$(N $record.staticDescendantCapacity) / $(N $record.staticDescendantInitialSupplies)**. Создаваемый при запуске командный пункт сюда не входит.");$lines.Add('')
    if($record.physicalSlots.Count){$lines.Add('| Контейнер | Вместимость / Изначально | Координаты X Y Z, м |');$lines.Add('| --- | ---: | --- |');foreach($slot in $record.physicalSlots){$lines.Add("| $($slot.name) | $(N $slot.capacitySupplies) / $(N $slot.configuredInitialSupplies) | $(Pos $slot.worldPositionMeters) |")};$lines.Add('');$lines.Add('Эти физические слоты уже входят в мировой каталог. Повторно не прибавляются.')}else{$lines.Add('В исходной редакторской иерархии вложенных физических контейнеров не найдено. Это не нулевая вместимость будущего HQ.')}
    $lines.Add('');$lines.Add('[Поля, исходные значения и происхождение](../StartingBases.json).');Save "Supplies/StartingBases/$($record.name).md" ($lines -join "`n")
}
$sum.Add('');$sum.Add('[Поля и происхождение данных](../StartingBases.json).');Save 'Supplies/StartingBases/Summary.md' ($sum -join "`n")
Save 'data.json' ([ordered]@{schemaVersion=3;snapshotId=$report.snapshotId;status='partial';kind='starting-base-candidates-index';sections=@{startingBases=@{status='partial';data='Supplies/StartingBases.json';summary='Supplies/StartingBases/Summary.md';pages=@($records | ForEach-Object {"Supplies/StartingBases/$($_.name).md"})};supplies=@{accountingData='../r0044/Supplies/Summary.json';note='Existing physical stock accounting unchanged; candidates are not additive.'}}} | ConvertTo-Json -Depth 12)
Save 'world.json' ([ordered]@{schemaVersion=3;snapshotId=$report.snapshotId;revisionId=$RevisionId;gameVersion=$report.gameVersion;scenarioKey='CTI_Campaign_HQC_Eden';worldPath=$report.worldPath;status='partial';normalizerVersion=$report.normalizerVersion;scope='starting_HQ_candidates_only';sources=$report.sources;codeEvidence=$codeEvidence} | ConvertTo-Json -Depth 12)
Write-Output "Generated $($records.Count) HQ candidate pages; existing supply totals unchanged."
