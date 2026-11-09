# Точки появления машин

Всего точек фонового появления техники: **181**. Это позиции спавна, не количество существующих машин. Конкретные модели выбираются из каталога фракции по фильтрам; список моделей пока не разрешён.

## По фракциям

| Фракция | Точек | Повторное появление через 10 мин | Без повторного появления |
| --- | ---: | ---: | ---: |
| [CIV](Factions/CIV.md) | 94 | 93 | 1 |
| [FIA](Factions/FIA.md) | 79 | 0 | 79 |
| [USSR](Factions/USSR.md) | 5 | 0 | 5 |
| [US](Factions/US.md) | 3 | 0 | 3 |

## По локациям

Названия и объединения взяты из справочника припасов. Склады — 200 м, остальные категории — 350 м по X/Z; ближайший якорь в первом подходящем приоритете. Это географическая привязка, не принадлежность базе. Patrols, огневые точки и Checkpoint к машинам не применяются.


### Контрольные точки

Всего точек: **21**.

| Локация | Точек |
| --- | ---: |
| [Calvary Hill](Locations/Location-4.md) | 1 |
| [Île-aux-Saules](Locations/Location-7.md) | 2 |
| [Military Base Levie](Locations/Location-1.md) | 3 |
| [Montignac](Locations/Location-3.md) | 4 |
| [Power Plant](Locations/Location-5.md) | 1 |
| [Régina](Locations/Location-6.md) | 3 |
| [Transformer Station](Locations/Location-2.md) | 7 |

### Доки

Всего точек: **47**.

| Локация | Точек |
| --- | ---: |
| [EveronAirport](Locations/Location-10.md) | 5 |
| [FishermansBay](Locations/Location-17.md) | 2 |
| [Gravette](Locations/Location-8.md) | 2 |
| [Kermovan](Locations/Location-9.md) | 3 |
| [Lamentin](Locations/Location-14.md) | 6 |
| [Meaux](Locations/Location-16.md) | 5 |
| [MilitaryHospital](Locations/Location-15.md) | 2 |
| [Morton](Locations/Location-13.md) | 6 |
| [StPhillipe](Locations/Location-12.md) | 1 |
| [StPierre](Locations/Location-11.md) | 15 |

### Склады припасов

Всего точек: **11**.

| Локация | Точек |
| --- | ---: |
| [Склад - 4814.289 53.445 5819.508](Locations/Location-47.md) | 1 |
| [Склад - 6912.457 57.718 4482.109](Locations/Location-46.md) | 1 |
| [Durras](Locations/Location-45.md) | 2 |
| [farm](Locations/Location-48.md) | 1 |
| [Gorey](Locations/Location-49.md) | 1 |
| [industrial compound](Locations/Location-50.md) | 1 |
| [Régina](Locations/Location-52.md) | 2 |
| [sawmill](Locations/Location-51.md) | 2 |

### Стартовые базы

Всего точек: **2**.

| Локация | Точек |
| --- | ---: |
| [StartingPos07](Locations/Location-44.md) | 2 |

### Города и деревни

Всего точек: **58**.

| Локация | Точек |
| --- | ---: |
| [Bénac](Locations/Location-34.md) | 2 |
| [Camurac](Locations/Location-20.md) | 2 |
| [Chotain](Locations/Location-26.md) | 3 |
| [Durras](Locations/Location-39.md) | 4 |
| [Entre-Deux](Locations/Location-36.md) | 6 |
| [Étoupe](Locations/Location-41.md) | 3 |
| [Figari](Locations/Location-28.md) | 5 |
| [Gorey](Locations/Location-24.md) | 1 |
| [Gravette](Locations/Location-18.md) | 2 |
| [La Valette](Locations/Location-37.md) | 2 |
| [Laruns](Locations/Location-23.md) | 4 |
| [Le Moule](Locations/Location-29.md) | 3 |
| [Levie](Locations/Location-22.md) | 4 |
| [Richemont](Locations/Location-33.md) | 3 |
| [Saint-Philippe](Locations/Location-30.md) | 2 |
| [Tyrone](Locations/Location-35.md) | 4 |
| [Vernon](Locations/Location-40.md) | 5 |
| [Villeneuve](Locations/Location-31.md) | 3 |

### Другое

Всего точек: **11**.

| Локация | Точек |
| --- | ---: |
| [GALLOW'S HILL](Locations/Location-43.md) | 1 |
| [industrial compound](Locations/Location-19.md) | 1 |
| [LONG HILL](Locations/Location-21.md) | 1 |
| [military site](Locations/Location-32.md) | 1 |
| [Quarry](Locations/Location-25.md) | 1 |
| [Saint-Pierre's Pass](Locations/Location-38.md) | 3 |
| [sawmill](Locations/Location-27.md) | 1 |
| [SIX BELLS](Locations/Location-42.md) | 2 |

### Без локации

Всего точек: **31**.

| Локация | Точек |
| --- | ---: |
| [Без локации](Locations/Location-53.md) | 31 |

## Откуда данные и как работает появление

Позиция — worldPosition сущности с SCR_AmbientVehicleSpawnPointComponent; фракция — SCR_FactionAffiliationComponent → faction affiliation. Время — m_iRespawnPeriod, секунды / 60; 0 отключает повторное появление. Фильтры — m_aIncludedEditableEntityLabels, m_aExcludedEditableEntityLabels и m_bRequireAllIncludedLabels. Имена меток прочитаны из EEditableEntityLabel установленной игры 1.8.0.13.

В Update компонент получает VEHICLE-каталог фракции, вызывает GetFullFilteredEntityListWithLabels и выбирает случайный элемент. Таймер повторного появления не означает гарантированный спавн строго каждые 10 минут: система учитывает состояние машины, близость игроков, флаг SpawnVehicles и доступное место. SpawnVehicle дополнительно проверяет свободную позицию. Фактический спавн здесь не измерялся.

[Канонические данные](SpawnPoints.json).
