# Начальные припасы

Игра **1.8.0.13**, мир `CTI_Campaign_HQC_Eden`, ревизия `r0043`.

## Всего припасов изначально

**231200** — известная сумма по конфигам хранилищ.

| Категория | Припасов изначально |
| --- | ---: |
| [Контрольные точки](ControlPoints/Summary.md) | 48100 |
| [Доки](Harbors/Summary.md) | 95500 |
| [Склады](SupplyDepots/Summary.md) | 75100 |
| [Города](Settlements/Summary.md) | 0 |
| [Другое](Other/Summary.md) | 12500 |

«Доки» включают собственные хранилища и связанные группы потенциального расширения. «Города» включают оставшиеся отдельно учтённые города, деревни и поселения. «Другое» — остальные локации и нераспознанные хранилища. Повторные ссылки на один родительский объект не суммируются.

## [Контрольные точки](ControlPoints/Summary.md)

| Название | Припасов изначально |
| --- | ---: |
| [Calvary Hill](ControlPoints/Calvary-Hill.md) | 8800 |
| [Île-aux-Saules](ControlPoints/Ile-aux-Saules.md) | 6400 |
| [Military Base Levie](ControlPoints/Military-Base-Levie.md) | 9800 |
| [Montignac](ControlPoints/Montignac.md) | 7300 |
| [Power Plant](ControlPoints/Power-Plant.md) | 6000 |
| [Régina](ControlPoints/Regina.md) | 3900 |
| [Transformer Station](ControlPoints/Transformer-Station.md) | 5900 |

## [Доки](Harbors/Summary.md)

| Название | Припасов изначально |
| --- | ---: |
| [EveronAirport](Harbors/EveronAirport.md) | 11000 |
| [StPhillipe](Harbors/StPhillipe.md) | 13500 |
| [StPierre](Harbors/StPierre.md) | 9500 |
| [FishermansBay](Harbors/FishermansBay.md) | 7000 |
| [Lamentin](Harbors/Lamentin.md) | 9500 |
| [Meaux](Harbors/Meaux.md) | 7500 |
| [MilitaryHospital](Harbors/MilitaryHospital.md) | 10500 |
| [Morton](Harbors/Morton.md) | 5500 |
| [GoatBay](Harbors/GoatBay.md) | 2500 |
| [Gravette](Harbors/Gravette.md) | 1500 |
| [HalcyonStrait](Harbors/HalcyonStrait.md) | 1500 |
| [Kermovan](Harbors/Kermovan.md) | 2500 |
| [Lancre](Harbors/Lancre.md) | 1000 |
| [Laruns](Harbors/Laruns.md) | 1500 |
| [LeBosc](Harbors/LeBosc.md) | 3000 |
| [Perelle](Harbors/Perelle.md) | 3500 |
| [SpaniardsBay](Harbors/SpaniardsBay.md) | 3000 |
| [Thollevast](Harbors/Thollevast.md) | 1500 |

## [Склады](SupplyDepots/Summary.md)

| Название | Припасов изначально |
| --- | ---: |
| [Durras](SupplyDepots/Durras.md) | 5500 |
| [Склад - 6912.457 57.718 4482.109](SupplyDepots/Склад---6912-457-57-718-4482-109.md) | 5400 |
| [Склад - 4814.289 53.445 5819.508](SupplyDepots/Склад---4814-289-53-445-5819-508.md) | 11700 |
| [farm](SupplyDepots/farm.md) | 11000 |
| [Gorey](SupplyDepots/Gorey.md) | 5400 |
| [industrial compound](SupplyDepots/industrial-compound.md) | 13300 |
| [sawmill](SupplyDepots/sawmill.md) | 9200 |
| [Régina](SupplyDepots/Regina.md) | 7100 |
| [military site](SupplyDepots/military-site.md) | 6500 |

## [Города](Settlements/Summary.md)

| Название | Припасов изначально |
| --- | ---: |

Отдельно учитываемых хранилищ в этой категории нет.

## [Другое](Other/Summary.md)

| Название | Припасов изначально |
| --- | ---: |
| [Saint-Pierre's Pass](Other/Saint-Pierre-s-Pass.md) | 11500 |
| [StartingPos21](Other/StartingPos21.md) | 1000 |

Один объект может встречаться у нескольких локаций внутри категории. Строки таблиц показывают состав каждой группы, поэтому их суммы могут пересекаться; общий итог и таблица категорий выше учитывают каждый объект один раз.

Использованы configuredInitialSupplies у родительских хранилищ, m_fResourceValueCurrent физических контейнеров доков и начальное значение после действия префаба командного пункта. Вместимость, доход за цикл, виртуальные контейнеры и агрегаты общей сети базы в сумму не прибавляются. Это сводка настроенных запасов, а не измерение всего мира после запуска миссии.

[Состав расчёта и источники](Summary.json) · [Подробные таблицы](OtherContainers.md).
