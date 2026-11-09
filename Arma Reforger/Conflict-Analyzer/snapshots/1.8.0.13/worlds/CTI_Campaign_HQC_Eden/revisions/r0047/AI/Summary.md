# Группы ИИ — сводка

Мир CTI_Campaign_HQC_Eden, игра **1.8.0.13**, ревизия **r0047**. Первый раздел: фоновые патрули FIA.

Точек: **299**; фиксированный тип: **288**; случайный тип: **11**; вариантов каталога: **9**.

Если каждая включённая точка создаст одну группу: **1128–1194 бойцов**. Это условный состав конфигурации, не число одновременно активных ИИ. Реальное появление зависит от игроков, дистанций, паузы, состояния точки и игрового бюджета; фактическое число не измерено.

В исходной диагностике нет размещённых SCR_AIGroup. Это не полный аудит всех механизмов ИИ: защитники баз, динамическое создание и другие системы пока не разобраны.

## Типы групп

| Тип | Точек с фиксированным типом | Бойцов в группе | Всего бойцов фиксированных групп |
| --- | ---: | ---: | ---: |
| [TEAM_SENTRY](Types/TEAM_SENTRY.md) | 74 | 2 | 148 |
| [TEAM_MG](Types/TEAM_MG.md) | 12 | 2 | 24 |
| [TEAM_AT](Types/TEAM_AT.md) | 25 | 4 | 100 |
| [FIRETEAM](Types/FIRETEAM.md) | 115 | 5 | 575 |
| [SQUAD_RIFLE](Types/SQUAD_RIFLE.md) | 23 | 7 | 161 |
| [TEAM_SNIPER](Types/TEAM_SNIPER.md) | 7 | 2 | 14 |
| [TEAM_MG_ELITE](Types/TEAM_MG_ELITE.md) | 7 | 2 | 14 |
| [PARTISAN_SNIPER](Types/PARTISAN_SNIPER.md) | 11 | 1 | 11 |
| [PARTISAN_TEAM](Types/PARTISAN_TEAM.md) | 14 | 5 | 70 |
| Случайный тип | 11 | 1–7 | не прибавлять все варианты одновременно |

## Объекты по локациям

Назначение — ближайшая подходящая подпись в радиусе 350 м по X/Z: города, деревни, поселения, острова и холмы имеют приоритет над Name Generic. Пруды, реки и озёра исключены. Это географическая подсказка, не подтверждение родства сущностей. Каждая точка находится в одном списке; остальные — «Без локации».

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [Gravette](Locations/Location_00000000000004B0B1.md) | 5 | 24–24 |
| [Pennants Pass](Locations/Location_00000000000004EAD1.md) | 1 | 2–2 |
| [Huntsman's Heath](Locations/Location_000000000000070851.md) | 1 | 2–2 |
| [Perelle](Locations/Location_0000000000001042F1.md) | 2 | 7–7 |
| [LONG HILL](Locations/Location_000000000000119831.md) | 2 | 9–9 |
| [harbor](Locations/Location_000000000000119851.md) | 1 | 5–5 |
| [sawmill](Locations/Location_000000000000159FF1.md) | 2 | 7–7 |
| [Les Creux](Locations/Location_00000000000015A0B1.md) | 1 | 7–7 |
| [Morton](Locations/Location_0000000000003A6671.md) | 6 | 32–32 |
| [SAINTE-MARGUERITE](Locations/Location_000000000000407691.md) | 1 | 2–2 |
| [Laruns](Locations/Location_000000000000409B61.md) | 1 | 5–5 |
| [Saint-Pierre](Locations/Location_00000000000056AB61.md) | 8 | 31–31 |
| [Île-aux-Saules](Locations/Location_0000000000005C1FD1.md) | 10 | 32–32 |
| [Gorey](Locations/Location_0000000000005C3B51.md) | 5 | 17–23 |
| [Montignac](Locations/Location_000000000000672FD1.md) | 21 | 93–93 |
| [CALVARY HILL](Locations/Location_0000000000006E9461.md) | 15 | 54–54 |
| [Chotain](Locations/Location_000000000000723F81.md) | 1 | 5–5 |
| [power plant](Locations/Location_000000000000729BC1.md) | 10 | 50–50 |
| [military site](Locations/Location_000000000000856111.md) | 5 | 14–20 |
| [Meaux](Locations/Location_000000000000884D41.md) | 7 | 30–30 |
| [Lamentin](Locations/Location_0000000000008BE1C1.md) | 6 | 28–28 |
| [Provins](Locations/Location_000000000000933591.md) | 10 | 43–43 |
| [Lacan's Head](Locations/Location_00000000000096B321.md) | 1 | 1–1 |
| [military site](Locations/Location_00000000000096FE71.md) | 3 | 13–13 |
| [sawmill](Locations/Location_000000000000A44AF1.md) | 1 | 2–2 |
| [farm](Locations/Location_000000000000A45731.md) | 1 | 1–7 |
| [WOLF HILL](Locations/Location_000000000000ABDD31.md) | 1 | 2–2 |
| [Figari](Locations/Location_000000000000AF6261.md) | 3 | 14–14 |
| [Kermovan](Locations/Location_000000000000B06E51.md) | 3 | 12–12 |
| [military site](Locations/Location_000000000000B0C4D1.md) | 6 | 23–23 |
| [Le Moule](Locations/Location_000000000000B7BCF1.md) | 2 | 9–9 |
| [Saint-Philippe](Locations/Location_000000000000B7C251.md) | 7 | 28–28 |
| [Villeneuve](Locations/Location_000000000000BE72A1.md) | 2 | 10–10 |
| [farm](Locations/Location_000000000000BEEFC1.md) | 3 | 12–12 |
| [military site](Locations/Location_000000000000C39251.md) | 2 | 10–10 |
| [Lancre](Locations/Location_000000000000C5DA41.md) | 3 | 9–9 |
| [Richemont](Locations/Location_000000000000D1C911.md) | 4 | 21–21 |
| [Le Bosc](Locations/Location_000000000000D1C921.md) | 2 | 10–10 |
| [Bénac](Locations/Location_000000000000F42CC1.md) | 2 | 5–11 |
| [Airport](Locations/Location_000000000000F4D491.md) | 7 | 28–28 |
| [Tyrone](Locations/Location_0000000000010856A1.md) | 3 | 14–14 |
| [military site](Locations/Location_0000000000010856B1.md) | 15 | 54–54 |
| [harbor](Locations/Location_00000000000124BAA1.md) | 1 | 2–2 |
| [Entre-Deux](Locations/Location_00000000000126C2A1.md) | 3 | 9–9 |
| [La Valette](Locations/Location_0000000000012DC911.md) | 1 | 1–1 |
| [Saint-Pierre's Pass](Locations/Location_0000000000012DD011.md) | 8 | 23–29 |
| [Durras](Locations/Location_00000000000139C501.md) | 3 | 9–9 |
| [industrial compound](Locations/Location_0000000000013AB971.md) | 1 | 5–5 |
| [Vernon](Locations/Location_0000000000013AB991.md) | 5 | 15–15 |
| [Étoupe](Locations/Location_0000000000013AC461.md) | 3 | 14–14 |
| [Régina](Locations/Location_0000000000013D0861.md) | 13 | 48–48 |
| [GALLOW'S HILL](Locations/Location_000000000001417C81.md) | 3 | 10–10 |
| [HEDGEHOG HILL](Locations/Location_000000000001417C91.md) | 2 | 6–12 |
| [POACHER'S HILL](Locations/Location_00000000000143A031.md) | 2 | 8–8 |
| [Без локации](Locations/Ungrouped.md) | 62 | 201–231 |

## Выбор и активация

При фиксированном типе код выбирает первую запись каталога с совпадающим m_eGroupType. При случайном выборе m_eGroupType точки игнорируется: общий порог выбирается между 0 и максимальным m_fProbabilityOfPresence, затем равновероятно выбирается один из прошедших вариантов. Значение 0.3 не означает 30% независимого появления группы. Ожидаемая численность не рассчитывается.

Для текущего снимка все точки включены, m_iRespawnPeriod=0 означает отсутствие автоматического респавна по таймеру (единица поля — секунды). Это не запрещает отдельную логику смены фракции / повторной активации. Дистанции активации и удаления сохранены для каждой точки в JSON.

[Данные, состав вариантов и происхождение](Groups.json).
