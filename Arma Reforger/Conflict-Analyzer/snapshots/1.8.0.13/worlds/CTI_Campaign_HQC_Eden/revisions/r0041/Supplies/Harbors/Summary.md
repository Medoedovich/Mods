# Доки

[Общая сводка](../Summary.md)

Игра **1.8.0.13**, мир `CTI_Campaign_HQC_Eden`, ревизия `r0041`.

Начальных припасов по конфигам: **40500 + неизвестно**. Итог учитывает каждый объект один раз.

## Радиус поиска хранилищ и пополнение

В установленной игре **1.8.0.13** базовый префаб `Prefabs/Systems/MilitaryBase/ConflictSourceBase.et` задаёт **100 м** в поле `SCR_ResourceComponent → m_aGenerators → SCR_ResourceGenerator → m_fStorageRange`. Прочитанные `ConflictSourceBase_T1Harbor.et` и `ConflictSourceBase_T2Harbor.et` наследуют этот префаб и не переопределяют это поле. Это настройка генератора ресурсов; одноимённое по величине `m_iRadius` компонента базы — другое поле.

`SCR_CampaignSourceBaseComponent` наследует механизм пополнения от `SCR_CampaignMilitaryBaseComponent`: таймер вызывает `AddRegularSupplyPackage`, затем `AddSupplies` обращается к генератору SUPPLIES. `SCR_ResourceGenerator.RequestGeneration` вызывает `RequestAvailability`, которая обновляет список контейнеров через `ResourceGrid.UpdateInteractor`. `GetResourceGridRange` генератора возвращает `m_fStorageRange`.

Ресурсная сеть ищет контейнеры поблизости и проверяет `CanInteractWith`, `IsInRange` и признак изоляции. Поэтому хранилище **не обязано быть дочерним объектом дока**, чтобы участвовать в пополнении. Вместе с тем одной близости недостаточно: действуют условия подключения, свободная вместимость и условия работы базы. Результаты наблюдения подключения показаны отдельно на страницах доков; факт пополнения за цикл этим не измеряется.

### Как читать список в справочнике

- Проверяются отдельно все физические и виртуальные SUPPLIES-контейнеры. Расстояние по X/Y/Z считается от сущности дока до позиции каждого контейнера; 100 м включительно, до округления. Корень композиции больше не служит фильтром, исключающим вложенные ящики.
- Расстояние до корня сохранено для сравнения. Вышедшие за радиус соседи внутри выбранной композиции показаны как диагностика: расхождение с корнем — повод проверить расположение, а не автоматически доказанная ошибка мира.
- Игровой IsInRange проверяет пересечение сферы с AABB сущности (GetBounds), поэтому результат может отличаться от расстояния до её позиции. Изоляция, CanInteractWith и IsInteractorLinked показываются отдельными колонками при наличии runtime-измерения; иначе — «не измерено».
- Виртуальные представления хранилищ показаны отдельно от физических ящиков и не добавляются к суммам. Категории, исходные запасы и принадлежность по source-иерархии не изменяются. Динамически созданные объекты, отсутствующие в editor source, остаются в runtime-отчёте без придуманной привязки.


У StPierre, Lamentin и Meaux «неизвестно» означает отсутствие подтверждённых вложенных хранилищ в используемом отчёте, а не нулевой запас и не доказанную остановку пополнения. Припасы отдельно стоящих соседей уже учтены в других категориях.

## Начальные припасы по докам

| Название | Припасов изначально |
| --- | ---: |
| [SP_A_EveronAirport](SP_A_EveronAirport.md) | 4000 |
| [SP_T1H_StPhillipe](SP_T1H_StPhillipe.md) | 3500 |
| [SP_T1H_StPierre](SP_T1H_StPierre.md) | неизвестно |
| [SP_T2H_FishermansBay](SP_T2H_FishermansBay.md) | 5000 |
| [SP_T2H_Lamentin](SP_T2H_Lamentin.md) | неизвестно |
| [SP_T2H_Meaux](SP_T2H_Meaux.md) | неизвестно |
| [SP_T2H_MilitaryHospital](SP_T2H_MilitaryHospital.md) | 3000 |
| [SP_T2H_Morton](SP_T2H_Morton.md) | 3500 |
| [SP_T3H_GoatBay](SP_T3H_GoatBay.md) | 2500 |
| [SP_T3H_Gravette](SP_T3H_Gravette.md) | 1500 |
| [SP_T3H_HalcyonStrait](SP_T3H_HalcyonStrait.md) | 1500 |
| [SP_T3H_Kermovan](SP_T3H_Kermovan.md) | 2500 |
| [SP_T3H_Lancre](SP_T3H_Lancre.md) | 1000 |
| [SP_T3H_Laruns](SP_T3H_Laruns.md) | 1500 |
| [SP_T3H_LeBosc](SP_T3H_LeBosc.md) | 3000 |
| [SP_T3H_Perelle](SP_T3H_Perelle.md) | 3500 |
| [SP_T3H_SpaniardsBay](SP_T3H_SpaniardsBay.md) | 3000 |
| [SP_T3H_Thollevast](SP_T3H_Thollevast.md) | 1500 |

[Состав расчёта и неизвестные значения](../Summary.json).
