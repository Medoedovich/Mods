# Доки

[Общая сводка](../Summary.md)

Игра **1.8.0.13**, мир `CTI_Campaign_HQC_Eden`, ревизия `r0039`.

Начальных припасов по конфигам: **40500 + неизвестно**. Итог учитывает каждый объект один раз.

## Радиус поиска хранилищ и пополнение

В установленной игре **1.8.0.13** базовый префаб `Prefabs/Systems/MilitaryBase/ConflictSourceBase.et` задаёт **100 м** в поле `SCR_ResourceComponent → m_aGenerators → SCR_ResourceGenerator → m_fStorageRange`. Прочитанные `ConflictSourceBase_T1Harbor.et` и `ConflictSourceBase_T2Harbor.et` наследуют этот префаб и не переопределяют это поле. Это настройка генератора ресурсов; одноимённое по величине `m_iRadius` компонента базы — другое поле.

`SCR_CampaignSourceBaseComponent` наследует механизм пополнения от `SCR_CampaignMilitaryBaseComponent`: таймер вызывает `AddRegularSupplyPackage`, затем `AddSupplies` обращается к генератору SUPPLIES. `SCR_ResourceGenerator.RequestGeneration` вызывает `RequestAvailability`, которая обновляет список контейнеров через `ResourceGrid.UpdateInteractor`. `GetResourceGridRange` генератора возвращает `m_fStorageRange`.

Ресурсная сеть ищет контейнеры поблизости и проверяет `CanInteractWith`, `IsInRange` и признак изоляции. Поэтому хранилище **не обязано быть дочерним объектом дока**, чтобы участвовать в пополнении. Вместе с тем одной близости недостаточно: действуют условия подключения, свободная вместимость и условия работы базы. Подключение конкретных контейнеров и пополнение трёх доков с неизвестным запасом в игровой сессии пока не проверены.

### Как читать список в справочнике

- **До 100 м включительно** — отдельно стоящие хранилища, корни которых попадают в эту дистанцию от дока. Это кандидаты для проверки, а не подтверждённый список пополняемых контейнеров.
- Хранилища дальше **100 м** не включаются в список дока.
- Дистанция в этих списках считается по **X/Y/Z до корня хранилища**, до округления. Игровая сеть работает с ресурсными контейнерами, поэтому результат может отличаться; настройки экземпляров мира отдельно не разрешались.
- **100 м — максимальная дистанция отбора для доков**. Категории объектов сохранены; найденные соседи не прибавляются повторно к сумме дока. Колонка «Где уже учтено» ведёт к их текущей группе.

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
