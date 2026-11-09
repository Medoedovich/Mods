# Стартовые позиции главных баз

Каталог: [сводка](../snapshots/1.8.0.13/worlds/CTI_Campaign_HQC_Eden/Supplies/StartingBases/Summary.md).

Отбор выполняется по разрешённому m_bCanBeHQ=true, а не по имени StartingPos. В исследованном мире 8 совпадений, все ConflictBase_MOB.et. Фракция назначается после SelectHQs; источники и координаты кандидатов не доказывают выбранную сторону.

## Источники

- Диагностика мира: только координаты, идентификаторы, нужные поля military base / legacy supplies и GameMode. Исходный широкий дамп не копируется в Git.
- ContainerDetails.json r0044: физические слоты, подтверждённые source-предки, вместимость / начальный запас.
- HQC_Eden_CommandPostStorage_1.8.0.13.json: варианты US и USSR; 1000 относится к создаваемой композиции, не к всей сети базы.
- Код установленной игры: SCR_GameModeCampaign.InitalBaseSetup, SCR_CampaignMilitaryBaseComponent.OnAllBasesInitialized / GetSuppliesIncomeAmount / GetSuppliesArrivalTimer / CalculateSupplyRegenerationAmount / AddRegularSupplyPackage / GetSuppliesMax. Пути и SHA файлов сохранены в JSON; исходники игры не публикуются.

Базовое пополнение берётся из m_iRegularSuppliesIncomeBase при отключённой авторегенерации. Интервал — m_iSuppliesArrivalInterval / 60. При запасе ниже 100 действует quick replenishment (множитель 2); итог ограничен свободным местом. Значения таблицы — базовые, не гарантированная добавка каждого цикла.

m_iHQStartingSupplies=1000 — целевое значение GameMode, которое может переопределить mission header. Это не вместимость и не измеренный стартовый запас. Legacy m_iSupplies/m_iSuppliesMax=3000 сохранены только как доказательство прочитанных полей и исключены из физического подсчёта.

## Повторная сборка

Запустить tools/New-StartingBasesReport.ps1 с параметрами DiagnosticsPath, ContainerDetailsPath, CommandPostStoragePath, GameCodeDirectory, OutputDirectory и RevisionId. GameCodeDirectory должен содержать проверенные ресурсы той же версии: scripts/Game/GameMode/SCR_GameModeCampaign.c, scripts/Game/Components/Locations/SCR_CampaignMilitaryBaseComponent.c, Configs/Factions/US_Campaign.conf, Configs/Factions/USSR_Campaign.conf, Missions/23_Campaign_HQC_Everon.conf. Выходной каталог должен быть новым; опубликованные ревизии не перезаписывать.

Для общего New-SupplyPriorityReport.ps1 передавать -StartingBasesReportPath с каноническим Supplies/StartingBases.json. Каталог копируется с сохранением исходной ревизии и включается в навигацию без прибавления к запасу. В текущую общую сводку каталог включается функцией AddStartingBasesSummary из tools/StartingBasesSummary.ps1; ссылки на JSON корневых представлений ведут в revisions/r0045.

Полная runtime-вместимость, фактические фракции и цикл пополнения остаются отдельной задачей. Восемь кандидатов нельзя суммировать как восемь действующих HQ. StartingPos21 уже имеет два физических контейнера на 1000 суммарно, учтённых в Other; каталог кандидатов повторно их не начисляет.

## Учёт StartingPos21 — r0046

r0046 переносит единственную запись существующих хранилищ StartingPos21 (1000 припасов, 2 физических контейнера) из other в starting_bases. Другое — 11500; стартовые позиции — 1000; общий запас 231200 и все 180 записей сохранены. Текущая страница Other/StartingPos21.md удалена, каноническая страница — StartingBases/StartingPos21.md. Динамические HQ кандидатов не прибавляются. Source-граф и старые ревизии сохранены; новое распределение учёта находится в Summary.json, sourceCategory сохраняет происхождение.
