# Точки появления машин

Всего точек фонового появления техники: **181**. Это позиции спавна, не количество существующих машин. Конкретные модели выбираются из каталога фракции по фильтрам; список моделей пока не разрешён.

## По фракциям

| Фракция | Точек | Без повторного появления | Повторное появление через 10 мин |
| --- | ---: | ---: | ---: |
| [CIV](Factions/CIV.md) | 94 | 1 | 93 |
| [FIA](Factions/FIA.md) | 79 | 79 | 0 |
| [USSR](Factions/USSR.md) | 5 | 5 | 0 |
| [US](Factions/US.md) | 3 | 3 | 0 |

## По локациям

Названия и объединения взяты из справочника припасов. Склады — 200 м, остальные категории — 350 м по X/Z; ближайший якорь в первом подходящем приоритете. Это географическая привязка, не принадлежность базе. Patrols, огневые точки и Checkpoint к машинам не применяются.


### Контрольные точки

Всего точек: **21**.

| Локация | Точек |
| --- | ---: |
| [Calvary Hill](Locations/Calvary-Hill.md) | 1 |
| [Île-aux-Saules](Locations/Île-aux-Saules.md) | 2 |
| [Military Base Levie](Locations/Military-Base-Levie.md) | 3 |
| [Montignac](Locations/Montignac.md) | 4 |
| [Power Plant](Locations/Power-Plant.md) | 1 |
| [Régina](Locations/Régina-7cba712f.md) | 3 |
| [Transformer Station](Locations/Transformer-Station.md) | 7 |

### Доки

Всего точек: **47**.

| Локация | Точек |
| --- | ---: |
| [EveronAirport](Locations/EveronAirport.md) | 5 |
| [FishermansBay](Locations/FishermansBay.md) | 2 |
| [Gravette](Locations/Gravette-8ca16d84.md) | 2 |
| [Kermovan](Locations/Kermovan.md) | 3 |
| [Lamentin](Locations/Lamentin.md) | 6 |
| [Meaux](Locations/Meaux.md) | 5 |
| [MilitaryHospital](Locations/MilitaryHospital.md) | 2 |
| [Morton](Locations/Morton.md) | 6 |
| [StPhillipe](Locations/StPhillipe.md) | 1 |
| [StPierre](Locations/StPierre.md) | 15 |

### Склады припасов

Всего точек: **11**.

| Локация | Точек |
| --- | ---: |
| [Склад - 4814.289 53.445 5819.508](Locations/Склад---4814-289-53-445-5819-508.md) | 1 |
| [Склад - 6912.457 57.718 4482.109](Locations/Склад---6912-457-57-718-4482-109.md) | 1 |
| [Durras](Locations/Durras-001dec38.md) | 2 |
| [farm](Locations/farm.md) | 1 |
| [Gorey](Locations/Gorey-6c1d3229.md) | 1 |
| [industrial compound](Locations/industrial-compound-80f0ca11.md) | 1 |
| [Régina](Locations/Régina-e90f1cea.md) | 2 |
| [sawmill](Locations/sawmill-36739edc.md) | 2 |

### Стартовые базы

Всего точек: **2**.

| Локация | Точек |
| --- | ---: |
| [StartingPos07](Locations/StartingPos07.md) | 2 |

### Города и деревни

Всего точек: **58**.

| Локация | Точек |
| --- | ---: |
| [Bénac](Locations/Bénac.md) | 2 |
| [Camurac](Locations/Camurac.md) | 2 |
| [Chotain](Locations/Chotain.md) | 3 |
| [Durras](Locations/Durras-de1c79e3.md) | 4 |
| [Entre-Deux](Locations/Entre-Deux.md) | 6 |
| [Étoupe](Locations/Étoupe.md) | 3 |
| [Figari](Locations/Figari.md) | 5 |
| [Gorey](Locations/Gorey-e918a2fb.md) | 1 |
| [Gravette](Locations/Gravette-9807aaa0.md) | 2 |
| [La Valette](Locations/La-Valette.md) | 2 |
| [Laruns](Locations/Laruns.md) | 4 |
| [Le Moule](Locations/Le-Moule.md) | 3 |
| [Levie](Locations/Levie.md) | 4 |
| [Richemont](Locations/Richemont.md) | 3 |
| [Saint-Philippe](Locations/Saint-Philippe.md) | 2 |
| [Tyrone](Locations/Tyrone.md) | 4 |
| [Vernon](Locations/Vernon.md) | 5 |
| [Villeneuve](Locations/Villeneuve.md) | 3 |

### Другое

Всего точек: **11**.

| Локация | Точек |
| --- | ---: |
| [GALLOW'S HILL](Locations/GALLOW-S-HILL.md) | 1 |
| [industrial compound](Locations/industrial-compound-07672585.md) | 1 |
| [LONG HILL](Locations/LONG-HILL.md) | 1 |
| [military site](Locations/military-site.md) | 1 |
| [Quarry](Locations/Quarry.md) | 1 |
| [Saint-Pierre's Pass](Locations/Saint-Pierre-s-Pass.md) | 3 |
| [sawmill](Locations/sawmill-be6eb1e2.md) | 1 |
| [SIX BELLS](Locations/SIX-BELLS.md) | 2 |

### Без локации

Всего точек: **31**.

| Локация | Точек |
| --- | ---: |
| [Без локации](Locations/Без-локации.md) | 31 |

## Откуда данные и как работает появление

Позиция — worldPosition сущности с SCR_AmbientVehicleSpawnPointComponent; фракция — SCR_FactionAffiliationComponent → faction affiliation. Время — m_iRespawnPeriod, секунды / 60; 0 отключает повторное появление. Фильтры — m_aIncludedEditableEntityLabels, m_aExcludedEditableEntityLabels и m_bRequireAllIncludedLabels. Имена меток прочитаны из EEditableEntityLabel установленной игры 1.8.0.13.

В Update компонент получает VEHICLE-каталог фракции, вызывает GetFullFilteredEntityListWithLabels и выбирает случайный элемент. Таймер повторного появления не означает гарантированный спавн строго каждые 10 минут: система учитывает состояние машины, близость игроков, флаг SpawnVehicles и доступное место. SpawnVehicle дополнительно проверяет свободную позицию. Фактический спавн здесь не измерялся.

[Канонические данные](SpawnPoints.json).
