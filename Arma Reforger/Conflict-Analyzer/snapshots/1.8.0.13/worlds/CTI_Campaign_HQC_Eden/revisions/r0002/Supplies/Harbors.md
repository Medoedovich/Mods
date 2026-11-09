# Базы-источники припасов

## Summary

Всего точек: **18**.

Из них портов: **17**, аэропортов: **1**.

Игра **1.8.0.13**, мир `CTI_Campaign_HQC_Eden.ent`, ревизия `r0002`. Снимок частичный: таблица содержит настройки пополнения баз с компонентом `SCR_CampaignSourceBaseComponent`.

## Откуда берутся данные

| Столбец | Источник |
| --- | --- |
| Название | `records[].name` целевого экспорта Workbench, полученное через `IEntitySource.GetName()` — имя editor source. Игровое название ближайшей локации пока не определено. |
| Пополнение за цикл, припасы | `SCR_CampaignSourceBaseComponent.m_iRegularSuppliesIncomeBase`, прочитанное через `BaseContainer.Get`. В JSON: `supplyIncomePerCycle`. |
| Пополнение, мин. | `SCR_CampaignSourceBaseComponent.m_iSuppliesArrivalInterval`, прочитанное через `BaseContainer.Get` в секундах; минуты = секунды / 60. В JSON сохраняются `arrivalIntervalSeconds` и `arrivalIntervalMinutes`. |

Для каждой записи сохранены source ID, слой, ближайший prefab и происхождение полей. Признак `directOverride` отличает прямое переопределение от унаследованного значения или значения по умолчанию. Точный ресурс, задающий унаследованное значение, ещё не установлен. Пополнение за цикл описывает настройку дохода; вместимость хранилища и условия работы генератора требуют отдельного анализа.

Неизвестные значения и настройки, требующие анализа fallback, выводятся как `unknown`; исходное поле сохраняется в `provenance.rawValue`. Выборка содержит настроенные источники, включая отключённые; `Enabled` сохранён в JSON и не доказывает выполнение всех условий дохода.

Источник таблицы: [Harbors.json](Harbors.json). Метаданные и ограничения: [world.json](../world.json). API компонента: [SCR_CampaignSourceBaseComponent](https://community.bistudio.com/wikidata/external-data/arma-reforger/ArmaReforgerScriptAPIPublic/interfaceSCR__CampaignSourceBaseComponent.html).

## Таблица

| Название | Пополнение за цикл, припасы | Пополнение, мин. |
| --- | --- | --- |
| SP_A_EveronAirport | 2000 | 10 |
| SP_T1H_StPhillipe | 3000 | 15 |
| SP_T1H_StPierre | 3000 | 15 |
| SP_T2H_FishermansBay | 2000 | 15 |
| SP_T2H_Lamentin | 2000 | 15 |
| SP_T2H_Meaux | 2000 | 15 |
| SP_T2H_MilitaryHospital | 2000 | 15 |
| SP_T2H_Morton | 2000 | 15 |
| SP_T3H_GoatBay | 1000 | 10 |
| SP_T3H_Gravette | 1000 | 10 |
| SP_T3H_HalcyonStrait | 1000 | 10 |
| SP_T3H_Kermovan | 1000 | 10 |
| SP_T3H_Lancre | 1000 | 10 |
| SP_T3H_Laruns | 1000 | 10 |
| SP_T3H_LeBosc | 1000 | 10 |
| SP_T3H_Perelle | 1000 | 10 |
| SP_T3H_SpaniardsBay | 1000 | 10 |
| SP_T3H_Thollevast | 1000 | 10 |
