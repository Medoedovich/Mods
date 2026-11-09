# Вместимость вложенных хранилищ

Команда `Reports → Inspect source base storage capacity` читает выбранную по имени базу с `SCR_CampaignSourceBaseComponent`, её вложенные ресурсные компоненты и необходимые связи родителей. По умолчанию исследуется `SP_A_EveronAirport`; другое имя передаётся через `-ME_CA_BaseName`. Отсутствующее или неоднозначное имя вызывает отказ, без сохранения мира.

## Проверенный результат

В HQC Everon **1.8.0.13** под аэропортом найдены две композиции:

| Хранилище (prefab) | Подпись, указанная пользователем | Состав | Вместимость, припасы |
| --- | --- | --- | ---: |
| SupplyCache_S_FIA_03 | SupplyCache_S_FIA_03_3 | 3 × 1000, контейнеры 20 ft | 3000 |
| SupplyCache_S_FIA_06 | SupplyCache_S_FIA_06_4 | 2 × 500, контейнеры 10 ft | 1000 |

Итого: **5 физических контейнеров, 4000 припасов**. Состав не выводится из имени prefab или его размера: числа прочитаны из конфигов каждого вложенного контейнера. Значения относятся к установленной версии ресурсов; подписи с суффиксами экземпляров переданы пользователем. `IEntitySource.GetName()` у этих композиций пуст, поэтому генерируемый отчёт использует имя файла prefab и source ID, не придумывая суффикс.

Полный результат: [r0003 / StorageCapacity.md](../snapshots/1.8.0.13/worlds/CTI_Campaign_HQC_Eden/revisions/r0003/Supplies/StorageCapacity.md), [канонический JSON](../snapshots/1.8.0.13/worlds/CTI_Campaign_HQC_Eden/revisions/r0003/Supplies/StorageCapacity.json). Это отдельная частичная ревизия одной базы; доход источников здесь не пересобирается.

## Алгоритм

1. Найти ровно одну source base по точному имени. Обходить обе subscene и prefab-детей; не исключать Eden по номеру.
2. Под этой базой прочитать `SCR_ResourceComponent.m_aContainers` через `BaseContainer.GetObjectArray`. Сохранить родительскую иерархию нужных объектов, состояние компонента и отключённых типов ресурсов.
3. Отделить физический `SCR_ResourceContainer` с `m_eResourceType=SUPPLIES` от виртуального `SCR_ResourceContainerVirtual`. Другой / неизвестный тип не включать в подтверждённую сумму; сохранить причину и предупредить о неполноте.
4. Для каждого физического слота прочитать `m_fResourceValueMax` — вместимость, `m_fResourceValueCurrent` — начальное количество в конфиге. Учитывать унаследованные значения и локальный override. Начальное количество не подменяет вместимость или состояние в игровой сессии.
5. Группировать физические контейнеры по непосредственному дочернему объекту выбранной базы; для аэропорта это два SupplyCache. Сохранять каждый контейнер отдельно, включая разную вместимость внутри одной композиции.
6. Суммировать уникальные слоты `(sourceId, componentIndex, containerIndex)`. Две виртуальные записи аэропорта сохраняются для проверки, но повторно не складываются с физическими контейнерами. Компоненты без контейнеров, в том числе на базе и указателях, не увеличивают число хранилищ.
7. При неизвестной вместимости оставить запись, вывести итог `unknown` и отдельный известный подытог. Нельзя заменить неизвестное нулём. Неизвестный список контейнеров или класс также делает общую вместимость неизвестной.
8. Сохранить `Supplies/StorageCapacity.json`, затем построить Markdown именно из сохранённого JSON. `data.json` содержит индекс, `world.json` — метаданные. Предыдущие ревизии сохранять.

Классы и поля сверены с локальным API Workbench 1.8.0.13 и официальной документацией [SCR_ResourceContainer](https://community.bistudio.com/wikidata/external-data/arma-reforger/ArmaReforgerScriptAPIPublic/interfaceSCR__ResourceContainer.html).

## CLI

К проверенным параметрам проекта и `-addonsDir` из [SOURCE_DIAGNOSTICS.md](SOURCE_DIAGNOSTICS.md) добавить:

```text
-wbModule=WorldEditor -run -exitAfterInit -plugin=ME_CA_StorageCapacityPlugin -ME_CA_World=worlds/MP/CTI_Campaign_HQC_Eden.ent -ME_CA_BaseName=SP_A_EveronAirport -ME_CA_LogJson=1
```

После завершения именно этого процесса собрать JSON в существующий игнорируемый `exports/`. Выходные пути должны быть свободны:

```powershell
.\tools\Convert-DiagnosticsLog.ps1 `
  -LogPath '<console.log этого запуска>' `
  -OutputPath .\exports\HQC_Eden_Airport_Storage_1.8.0.13.json `
  -ReportKind StorageCapacity

.\tools\New-StorageCapacityReport.ps1 `
  -ReportPath .\exports\HQC_Eden_Airport_Storage_1.8.0.13.json `
  -OutputDirectory .\exports\HQC_Eden_Airport_Storage_r0003 `
  -RevisionId r0003 `
  -RevisionReason 'Inspect nested physical storage composition for SP_A_EveronAirport' `
  -WorkbenchVersion 1.8.0.13
```

Извлечение проверяет целостность журналов, вид отчёта и счётчики. Скрипт подготовки проверяет дубликаты, ссылки родителей, классы, поля и числовые значения до создания каталога; оба отказываются перезаписывать результат. Прямой FileIO-путь из меню остаётся непроверенным интерактивно.

## Охват и оставшаяся работа

Подтверждена вместимость настроенных физических контейнеров **в иерархии одной базы**. Это ещё не полная доступная вместимость базы во время игры: runtime-связи ресурсной сети, соседние контейнеры вне иерархии, динамические постройки и состояние при запуске предстоит изучить. Отключённые объекты сохраняются как конфигурация, состояние указано в JSON.

Обход всех source base реализован в r0004. Нужно проверить принадлежность отдельно расположенных хранилищ игровой системе, точные ресурсы наследования и подписи экземпляров редактора. Иерархия `Supply Depots → Harbors / Anothers` остаётся ближайшей задачей; `r0003` добавляет исследование вместимости в существующую структуру. Проверки — [VALIDATION.md](VALIDATION.md).

## Все source base — r0004

Для пакетного чтения вместо `-ME_CA_BaseName` передать `-ME_CA_AllSourceBases=1`. Это один обход мира и явное чтение контейнеров всех 18 баз с тем же фильтром. Извлечь журнал с `-ReportKind StorageCapacityBatch` в свободный JSON, затем:

```powershell
.\tools\New-AllSourceCapacityReport.ps1 `
  -CapacityReportPath .\exports\HQC_Eden_AllSourceStorage_1.8.0.13.json `
  -SourceBasesReportPath .\snapshots\1.8.0.13\worlds\CTI_Campaign_HQC_Eden\revisions\r0002\Supplies\Harbors.json `
  -OutputDirectory .\exports\HQC_Eden_AllSourceStorage_r0004 `
  -RevisionId r0004 `
  -RevisionReason 'Analyze descendant storage for all source bases and add capacity column' `
  -WorkbenchVersion 1.8.0.13
```

Скрипт соединяет два проверяемых входа одной версии по source ID, имени, prefab, subscene и слою, сохраняя отдельные время чтения и SHA-256. Доход и интервалы не пересчитываются заново. Каждый физический слот должен принадлежать одной базе; дубликаты отклоняются. JSON `Harbors` содержит агрегат и ссылку на состав в `StorageCapacity.json`, общий `data.json` остаётся индексом.

Найдено 22 группы хранилищ, 49 физических контейнеров и 22 виртуальных представления. У 15 баз подтверждена вместимость вложенных контейнеров; известный подытог — 40500 припасов. У `SP_T1H_StPierre`, `SP_T2H_Lamentin`, `SP_T2H_Meaux` в дочерней иерархии физических контейнеров нет. Широкая диагностика той же версии показывает отдельно расположенные контейнеры рядом; их принадлежность этим базам не подтверждена. Столбец показывает unknown, не 0. Сумма всех баз также unknown; 40500 — лишь известный подытог.

[Таблица r0004](../snapshots/1.8.0.13/worlds/CTI_Campaign_HQC_Eden/revisions/r0004/Supplies/Harbors.md) и [состав](../snapshots/1.8.0.13/worlds/CTI_Campaign_HQC_Eden/revisions/r0004/Supplies/StorageCapacity.md). По просьбе пользователя корневой `Supplies/Harbors.md` — актуальное Markdown-представление этой ревизии с относительными ссылками на её канонические данные. Исторический r0001 сохранён отдельно; перенос ревизии и обновление манифеста пока ручные. Несколько CLI-процессов Workbench запускать последовательно: запуски в одну секунду могут записать общий каталог журнала.

## Контейнеры вне предыдущего отчёта

[OtherContainers / r0005](OTHER_CONTAINERS.md) содержит 568 остальных физических контейнеров с вместимостью и начальным запасом в конфиге. Он исключает прежние 49 физических контейнеров баз, сохраняя их r0004 без изменений. Связь отдельно расположенных складов с базами пока не установлена; unknown в Harbors остаётся.
