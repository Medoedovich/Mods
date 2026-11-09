# Группы ИИ — сводка

Мир CTI_Campaign_HQC_Eden, игра **1.8.0.13**, ревизия **r0055**. Первый раздел: фоновые патрули FIA.

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

«Всего бойцов» — суммарная численность при одной группе на каждую точку; диапазон учитывает случайный состав. Это не число одновременно активных бойцов.

Огневые точки имеют приоритет: ближайший префаб с MachineGun в имени в радиусе 50 м по X/Z. Прежняя категория сохраняется; соседство не подтверждает использование оружия. Точки с вложенными source-сущностями Waypoint (включая DefendWaypoint) выделены в Patrols независимо от прежней локации. Прежняя привязка сохранена в JSON и таблице Patrols. Наличие оборонительного Waypoint не означает движение по маршруту. Остальные назначения: подтверждённый предок CampaignRemnantsSupplyDepot, затем категории справочника припасов по прежним радиусам (склады 200 м, остальные 350 м по X/Z); для остатка — ближайший Checkpoint в 50 м. Каждая точка учитывается один раз.

### Контрольные точки

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Military Base Levie](Locations/ControlPoints/Military-Base-Levie.md) | 9 | 36 |
| [Transformer Station](Locations/ControlPoints/Transformer-Station.md) | 6 | 32 |
| [Montignac](Locations/ControlPoints/Montignac.md) | 17 | 77 |
| [Calvary Hill](Locations/ControlPoints/Calvary-Hill.md) | 1 | 5 |
| [Power Plant](Locations/ControlPoints/Power-Plant.md) | 7 | 38 |
| [Régina](Locations/ControlPoints/Regina.md) | 6 | 28 |
| [Île-aux-Saules](Locations/ControlPoints/Ile-aux-Saules.md) | 16 | 44 |

### Доки

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [LeBosc](Locations/Harbors/LeBosc.md) | 1 | 5 |
| [Lancre](Locations/Harbors/Lancre.md) | 1 | 5 |
| [GoatBay](Locations/Harbors/GoatBay.md) | 2 | 10 |
| [HalcyonStrait](Locations/Harbors/HalcyonStrait.md) | 3 | 9 |
| [Gravette](Locations/Harbors/Gravette.md) | 2 | 12 |
| [Kermovan](Locations/Harbors/Kermovan.md) | 1 | 5 |
| [Laruns](Locations/Harbors/Laruns.md) | 1 | 5 |
| [Perelle](Locations/Harbors/Perelle.md) | 1 | 5 |
| [EveronAirport](Locations/Harbors/EveronAirport.md) | 6 | 29 |
| [StPierre](Locations/Harbors/StPierre.md) | 6 | 27 |
| [StPhillipe](Locations/Harbors/StPhillipe.md) | 3 | 13 |
| [Morton](Locations/Harbors/Morton.md) | 5 | 27 |
| [Lamentin](Locations/Harbors/Lamentin.md) | 2 | 9 |
| [MilitaryHospital](Locations/Harbors/MilitaryHospital.md) | 5 | 21 |
| [Meaux](Locations/Harbors/Meaux.md) | 2 | 7 |
| [FishermansBay](Locations/Harbors/FishermansBay.md) | 3 | 12 |

### Склады припасов

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Склад - 6912.457 57.718 4482.109](Locations/SupplyDepots/Склад---6912-457-57-718-4482-109.md) | 1 | 5 |
| [Склад - 4814.289 53.445 5819.508](Locations/SupplyDepots/Склад---4814-289-53-445-5819-508.md) | 1 | 5 |
| [farm](Locations/SupplyDepots/farm.md) | 1 | 5 |
| [Gorey](Locations/SupplyDepots/Gorey.md) | 3 | 12 |
| [industrial compound](Locations/SupplyDepots/industrial-compound.md) | 1 | 5 |
| [sawmill](Locations/SupplyDepots/sawmill.md) | 1 | 5 |
| [Régina](Locations/SupplyDepots/Regina.md) | 2 | 7 |
| [military site](Locations/SupplyDepots/military-site.md) | 3 | 13 |

### Города и деревни

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Figari](Locations/Settlements/Figari-b14f1a07.md) | 2 | 10 |
| [Le Moule](Locations/Settlements/Le-Moule-7769f4e6.md) | 1 | 4 |
| [Saint-Philippe](Locations/Settlements/Saint-Philippe-f55cca85.md) | 1 | 1 |
| [Villeneuve](Locations/Settlements/Villeneuve-07696883.md) | 1 | 5 |
| [Richemont](Locations/Settlements/Richemont-5d1f9c59.md) | 1 | 5 |
| [Tyrone](Locations/Settlements/Tyrone-93ad6bb9.md) | 1 | 5 |
| [Entre-Deux](Locations/Settlements/Entre-Deux-28d66863.md) | 1 | 7 |
| [La Valette](Locations/Settlements/La-Valette-78832316.md) | 1 | 1 |
| [Étoupe](Locations/Settlements/Etoupe-0f5ee0da.md) | 1 | 7 |

### Стартовые базы

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [StartingPos12](Locations/StartingBases/StartingPos12.md) | 1 | 7 |

### Другое

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Pennants Pass](Locations/Other/Pennants-Pass-82ef1741.md) | 1 | 2 |
| [WOLF HILL](Locations/Other/WOLF-HILL-eb8ed47f.md) | 1 | 2 |
| [Saint-Pierre's Pass](Locations/Other/Saint-Pierre-s-Pass.md) | 2 | 10 |

### Checkpoint

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Checkpoint_M_USSR_01](Locations/Checkpoints/Checkpoint_M_USSR_01-02000000000002CE2.md) | 1 | 2 |

### Patrols

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Patrols](Locations/Patrols/Patrols.md) | 97 | 308–368 |

### Огневые точки

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Огневые точки](Locations/FirePoints/FirePoints.md) | 58 | 203–209 |

### Без локации

| Локация | Точек | Всего бойцов |
| --- | ---: | ---: |
| [Без локации](Locations/Ungrouped/Ungrouped.md) | 9 | 31 |

## Выбор и активация

При фиксированном типе код выбирает первую запись каталога с совпадающим m_eGroupType. При случайном выборе m_eGroupType точки игнорируется: общий порог выбирается между 0 и максимальным m_fProbabilityOfPresence, затем равновероятно выбирается один из прошедших вариантов. Значение 0.3 не означает 30% независимого появления группы. Ожидаемая численность не рассчитывается.

Для текущего снимка все точки включены, m_iRespawnPeriod=0 означает отсутствие автоматического респавна по таймеру (единица поля — секунды). Это не запрещает отдельную логику смены фракции / повторной активации. Дистанции активации и удаления сохранены для каждой точки в JSON.

[Данные, состав вариантов и происхождение](Groups.json).

Вооружение каждого варианта приведено на странице типа: сумма по группе и оружие каждого бойца. [Оружейные слоты и происхождение](Weapons.json).
