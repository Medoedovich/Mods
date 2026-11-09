# Группы ИИ — сводка

Мир CTI_Campaign_HQC_Eden, игра **1.8.0.13**, ревизия **r0051**. Первый раздел: фоновые патрули FIA.

Точек: **299**; фиксированный тип: **288**; случайный тип: **11**; вариантов каталога: **9**.

Если каждая включённая точка создаст одну группу: **1128–1194 бойцов**. Это условный состав конфигурации, не число одновременно активных ИИ. Реальное появление зависит от игроков, дистанций, паузы, состояния точки и игрового бюджета; фактическое число не измерено.

В исходной диагностике нет размещённых SCR_AIGroup. Это не полный аудит всех механизмов ИИ: защитники баз, динамическое создание и другие системы пока не разобраны.

## Типы групп

| Тип | Точек с фиксированным типом | Бойцов в группе | Всего бойцов фиксированных групп |
| --- | ---: | ---: | ---: |
| [FIRETEAM](Types/FIRETEAM.md) | 115 | 5 | 575 |
| [TEAM_SENTRY](Types/TEAM_SENTRY.md) | 74 | 2 | 148 |
| [TEAM_AT](Types/TEAM_AT.md) | 25 | 4 | 100 |
| [SQUAD_RIFLE](Types/SQUAD_RIFLE.md) | 23 | 7 | 161 |
| [PARTISAN_TEAM](Types/PARTISAN_TEAM.md) | 14 | 5 | 70 |
| [TEAM_MG](Types/TEAM_MG.md) | 12 | 2 | 24 |
| Случайный тип | 11 | 1–7 | не прибавлять все варианты одновременно |
| [PARTISAN_SNIPER](Types/PARTISAN_SNIPER.md) | 11 | 1 | 11 |
| [TEAM_MG_ELITE](Types/TEAM_MG_ELITE.md) | 7 | 2 | 14 |
| [TEAM_SNIPER](Types/TEAM_SNIPER.md) | 7 | 2 | 14 |

## Объекты по локациям

Названия, категории и объединения взяты из справочника припасов. Сначала склады (200 м от маркера), затем контрольные точки, доки, кандидаты HQ, города и другие локации (350 м по X/Z). Внутри первого подходящего этапа выбирается ближайший якорь; при равенстве — ID. Для объединённых локаций сохранены исходные подписи и позиции. Каталог включает допустимые локации без припасов; в таблицах показаны только группы с точками ИИ.

Каждая точка учитывается один раз. Это географическое распределение, не source-родство, игровое подчинение базе или проверка ResourceGrid. Расстояние в подробной таблице — до выбранного якоря; все кандидаты и прежняя привязка сохранены в JSON.

### Контрольные точки

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [Calvary Hill](Locations/ControlPoints/Calvary-Hill.md) | 15 | 54–54 |
| [Île-aux-Saules](Locations/ControlPoints/Ile-aux-Saules.md) | 16 | 44–44 |
| [Military Base Levie](Locations/ControlPoints/Military-Base-Levie.md) | 16 | 56–56 |
| [Montignac](Locations/ControlPoints/Montignac.md) | 21 | 93–93 |
| [Power Plant](Locations/ControlPoints/Power-Plant.md) | 11 | 55–55 |
| [Régina](Locations/ControlPoints/Regina.md) | 9 | 37–37 |
| [Transformer Station](Locations/ControlPoints/Transformer-Station.md) | 10 | 43–43 |

### Доки

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [EveronAirport](Locations/Harbors/EveronAirport.md) | 9 | 38–38 |
| [FishermansBay](Locations/Harbors/FishermansBay.md) | 5 | 14–20 |
| [GoatBay](Locations/Harbors/GoatBay.md) | 2 | 10–10 |
| [Gravette](Locations/Harbors/Gravette.md) | 4 | 19–19 |
| [HalcyonStrait](Locations/Harbors/HalcyonStrait.md) | 3 | 9–9 |
| [Kermovan](Locations/Harbors/Kermovan.md) | 3 | 12–12 |
| [Lamentin](Locations/Harbors/Lamentin.md) | 7 | 29–29 |
| [Lancre](Locations/Harbors/Lancre.md) | 3 | 9–9 |
| [Laruns](Locations/Harbors/Laruns.md) | 1 | 5–5 |
| [LeBosc](Locations/Harbors/LeBosc.md) | 2 | 10–10 |
| [Meaux](Locations/Harbors/Meaux.md) | 7 | 30–30 |
| [MilitaryHospital](Locations/Harbors/MilitaryHospital.md) | 6 | 23–23 |
| [Morton](Locations/Harbors/Morton.md) | 6 | 32–32 |
| [Perelle](Locations/Harbors/Perelle.md) | 2 | 7–7 |
| [SpaniardsBay](Locations/Harbors/SpaniardsBay.md) | 1 | 5–5 |
| [StPhillipe](Locations/Harbors/StPhillipe.md) | 7 | 29–29 |
| [StPierre](Locations/Harbors/StPierre.md) | 9 | 36–36 |

### Склады

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [Склад - 4814.289 53.445 5819.508](Locations/SupplyDepots/Склад---4814-289-53-445-5819-508.md) | 1 | 5–5 |
| [Склад - 6912.457 57.718 4482.109](Locations/SupplyDepots/Склад---6912-457-57-718-4482-109.md) | 1 | 5–5 |
| [Durras](Locations/SupplyDepots/Durras.md) | 2 | 6–12 |
| [farm](Locations/SupplyDepots/farm.md) | 3 | 9–9 |
| [Gorey](Locations/SupplyDepots/Gorey.md) | 3 | 12–12 |
| [industrial compound](Locations/SupplyDepots/industrial-compound.md) | 1 | 5–5 |
| [military site](Locations/SupplyDepots/military-site.md) | 3 | 13–13 |
| [Régina](Locations/SupplyDepots/Regina.md) | 4 | 11–11 |
| [sawmill](Locations/SupplyDepots/sawmill.md) | 2 | 7–7 |

### Города

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [Bénac](Locations/Settlements/Benac-b8dca6e1.md) | 2 | 5–11 |
| [Chotain](Locations/Settlements/Chotain-a6cceded.md) | 1 | 5–5 |
| [Durras](Locations/Settlements/Durras-de1c79e3.md) | 2 | 4–4 |
| [Entre-Deux](Locations/Settlements/Entre-Deux-28d66863.md) | 5 | 17–17 |
| [Étoupe](Locations/Settlements/Etoupe-0f5ee0da.md) | 2 | 9–9 |
| [Figari](Locations/Settlements/Figari-b14f1a07.md) | 3 | 14–14 |
| [Gorey](Locations/Settlements/Gorey-e918a2fb.md) | 2 | 5–11 |
| [Gravette](Locations/Settlements/Gravette-9807aaa0.md) | 1 | 5–5 |
| [La Valette](Locations/Settlements/La-Valette-78832316.md) | 1 | 1–1 |
| [Laruns](Locations/Settlements/Laruns-a95ff7dd.md) | 1 | 5–5 |
| [Le Moule](Locations/Settlements/Le-Moule-7769f4e6.md) | 3 | 11–11 |
| [Richemont](Locations/Settlements/Richemont-5d1f9c59.md) | 4 | 21–21 |
| [Saint-Philippe](Locations/Settlements/Saint-Philippe-f55cca85.md) | 1 | 1–1 |
| [Tyrone](Locations/Settlements/Tyrone-93ad6bb9.md) | 3 | 14–14 |
| [Vernon](Locations/Settlements/Vernon-740a9f7d.md) | 5 | 15–15 |
| [Villeneuve](Locations/Settlements/Villeneuve-07696883.md) | 2 | 10–10 |

### Стартовые позиции главных баз

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [StartingPos12](Locations/StartingBases/StartingPos12.md) | 1 | 7–7 |
| [StartingPos14](Locations/StartingBases/StartingPos14.md) | 1 | 5–5 |

### Другое

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [farm](Locations/Other/farm-1b13b783.md) | 1 | 1–7 |
| [farm](Locations/Other/farm-bb70859b.md) | 1 | 5–5 |
| [GALLOW'S HILL](Locations/Other/GALLOW-S-HILL-08a1f1ec.md) | 1 | 4–4 |
| [HEDGEHOG HILL](Locations/Other/HEDGEHOG-HILL-8576b4dd.md) | 2 | 6–12 |
| [Huntsman's Heath](Locations/Other/Huntsman-s-Heath-ad26d22f.md) | 1 | 2–2 |
| [industrial compound](Locations/Other/industrial-compound-07672585.md) | 1 | 4–4 |
| [Lacan's Head](Locations/Other/Lacan-s-Head-8343b4b9.md) | 1 | 1–1 |
| [LONG HILL](Locations/Other/LONG-HILL-957657a1.md) | 1 | 7–7 |
| [Pennants Pass](Locations/Other/Pennants-Pass-82ef1741.md) | 1 | 2–2 |
| [Saint-Pierre's Pass](Locations/Other/Saint-Pierre-s-Pass.md) | 7 | 21–27 |
| [SAINTE-MARGUERITE](Locations/Other/SAINTE-MARGUERITE-c0c088e7.md) | 1 | 2–2 |
| [sawmill](Locations/Other/sawmill-be6eb1e2.md) | 1 | 2–2 |
| [WOLF HILL](Locations/Other/WOLF-HILL-eb8ed47f.md) | 1 | 2–2 |

### Без локации

| Локация | Точек | Бойцов при одной группе на точку |
| --- | ---: | ---: |
| [Без локации](Locations/Ungrouped/Ungrouped.md) | 44 | 143–167 |

## Выбор и активация

При фиксированном типе код выбирает первую запись каталога с совпадающим m_eGroupType. При случайном выборе m_eGroupType точки игнорируется: общий порог выбирается между 0 и максимальным m_fProbabilityOfPresence, затем равновероятно выбирается один из прошедших вариантов. Значение 0.3 не означает 30% независимого появления группы. Ожидаемая численность не рассчитывается.

Для текущего снимка все точки включены, m_iRespawnPeriod=0 означает отсутствие автоматического респавна по таймеру (единица поля — секунды). Это не запрещает отдельную логику смены фракции / повторной активации. Дистанции активации и удаления сохранены для каждой точки в JSON.

[Данные, состав вариантов и происхождение](Groups.json).

Вооружение каждого варианта приведено на странице типа: сумма по группе и оружие каждого бойца. [Оружейные слоты и происхождение](Weapons.json).
