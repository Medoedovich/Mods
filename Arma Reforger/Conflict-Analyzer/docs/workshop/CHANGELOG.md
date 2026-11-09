# Conflict Analyzer — Workshop changelog draft

Служебная заметка: публикации нет. Английский блок предназначен для Workshop, русский — для сверки. Номер выпуска и дату публикации добавить после фактического выпуска. Unreleased означает подготовку, а не опубликованную версию.

## Unreleased

### English — draft text

• Added an initial addon project depending on the base Arma Reforger game.
• Added README, a development checklist, repository ignore rules and project guidelines.
• Added draft Workshop descriptions in English and Russian.
• Defined planned analysis of AI groups, supply points, starting bases and vehicle spawn points.
• Added a World Editor source diagnostic plugin and checked JSON extraction from the Workbench log.
• Verified source inventory and world coordinates on HQC Everon in game / Workbench 1.8.0.13.
• Added a partial versioned snapshot and generated Harbors report for 18 supply source bases, preserving raw seconds and displaying intervals in minutes.
• Added a targeted source-base export and schemaVersion 2 revision with separate Harbors.json and a shared section index; broad diagnostics remain a separate command.
• Added selected-base physical storage composition and capacity export, verified on SP_A_EveronAirport: 3 × 1000 + 2 × 500 = 4000; virtual containers are retained separately and excluded from totals.
• Extended configured storage inspection to all 18 source bases and added the Harbors capacity column. Archived the original r0001 before updating the current table; three detached-storage ownership cases remain unknown.
• Added a targeted world supplies-container command and separate OtherContainers JSON / Markdown, excluding verified base slots and virtual views from physical totals.
• OtherContainers now groups 568 physical slots into 124 root-parent rows, retaining individual records and separate prefab instances in JSON.
• Added named map locations and lists of OtherContainers / Harbors objects within a 1000 m horizontal radius: 170 labels, 142 objects. Overlapping matches retain distances and do not imply gameplay ownership.
• Simplified Locations Markdown to 150 populated location lists; descriptor types, location IDs and all 170 source labels remain in JSON.
• Locations now supports manual world-group review with location positions in headings and object positions / distances in each list; supply and identifier columns remain in JSON.
• Reduced the default location radius from 1000 to 500 m in r0009: 348 links, 76 populated locations and seven unmatched objects retained; previous published revisions are preserved.
• Excluded ponds, rivers, streams and lakes from matching by descriptor type in r0010: 24 excluded labels, 288 links and 16 unmatched objects; all original labels and objects remain in JSON.
• r0011 groups objects only around settlements within 300 m: 47 matched objects and a separate UngroupedObjects list of 95 remaining objects with world positions; geographic fallback is not performed.
• r0012 adds Name Generic as a second matching stage for objects outside settlement groups, using the same 300 m radius: 63 additional objects grouped, 32 remaining, and all 47 previous settlement assignments preserved.
• r0013 adds Name Island with equal settlement priority within 300 m: three previously ungrouped objects matched to Île-aux-Saules, 29 remain; earlier settlement and Generic assignments are preserved.
• r0014 adds Name Hill to the first stage within 300 m: five previously ungrouped objects matched to CALVARY HILL, 24 remain; previous settlement, island and Generic assignments are preserved.
• r0015 increases both matching-stage radii from 300 to 350 m: five additional objects grouped, two move from Generic to settlements, and one receives another Generic link. There are 31 populated groups and 19 ungrouped objects; earlier revisions and source data are preserved.
• r0016 combines grouped and ungrouped objects in one Locations report, with the ungrouped category at the end; matching data and earlier revisions are preserved.
• r0017 adds separate location-grouped OtherContainers and Harbors views using existing Locations links, preserving supply values, unknown capacities and earlier snapshots.
• r0018 combines supply tables into OtherContainers with Harbors as the final category; all values, locations, separate JSON catalogs and earlier revisions are preserved.
• r0019 adds targeted control-point settings and source-hierarchy-first classification, followed by settlement and other map locations; remaining objects are explicit.
• r0020 merges six corresponding map groups into control points (35 parents, including all five CALVARY HILL objects), preserving original proximity evidence and physical supply values.
• r0021 links Provins and its five objects to Transformer Station by an explicit version/scenario/source rule; values and prior grouping are preserved.
• r0022 simplifies parent supply tables: capacity / initial values precede composition; Source ID and container-count columns are hidden, with complete data retained in JSON.
• r0023 adds nine CampaignRemnantsSupplyDepot markers after Harbors and groups 47 remaining parents within 350 m; control-point/Harbor assignments and source values are preserved, with one unrecognized object left.
• r0024 consolidates Harbors into one table with physical capacity / composition before replenishment settings; source values, unknowns and grouping are preserved.
• r0025 groups depot markers under named locations within 350 m with settlement priority; seven markers are located and two remain unlocated, preserving all original containers and values.
• r0026 rounds displayed coordinates to three decimal places for Workbench; canonical positions, distances, groups and previous revisions are unchanged.
• r0027 removes redundant depot subheadings and keeps all nine marker positions in tables under location headings; settings, container lists and JSON values are preserved.
• r0028 hides depot marker coordinates in Markdown; location/object coordinates, settings, container lists and canonical positions are preserved.
• r0029 removes depot component settings from Markdown, preserves their source values in JSON and defers gameplay investigation to optional TODO work. Physical storage and grouping are unchanged.
• r0030 locates supply depots first and reserves storage within 100 m before control-point/map classification; all nine depots have 49 parents / 266 containers / 69600 capacity, including Regina 5 / 31 / 7100. Marker-location matching remains 350 m; four parents remain unrecognized.
• Documented the source of 1000-capacity command-post storage in local game 1.8.0.13 resources (FIA / US / USSR encapsulator actions). Analyzer support and runtime-grid validation remain planned; existing snapshots are unchanged.
• r0032 combines command-post storage and other control-point storage in a single table per control point; initial command-post supplies remain unknown.
• r0031 adds a verified command-post prefab catalog and shows capacity 1000 with five-/six-container compositions at all seven control points. Source values and classification are preserved; composition is calculated from configured actions, not a runtime measurement.
• r0033 resolves command-post initial supplies as 0 after the prefab action, separately from later campaign grid initialization; all seven storage rows show 1000 / 0.
• Complete gameplay reports and version comparison remain in development; diagnostics are marked partial.

### Русский — перевод для сверки

• Добавлен начальный addon-проект с зависимостью от базовой Arma Reforger.
• Добавлены README, план разработки, правила исключений Git и памятка проекта.
• Подготовлены черновики описаний Workshop на английском и русском языках.
• Запланирован анализ групп ИИ, точек с припасами, стартовых баз и точек появления машин.
• Добавлены плагин диагностики source в World Editor и проверяемая сборка JSON из журнала Workbench.
• Инвентаризация источников и мировые координаты проверены на HQC Everon в игре / Workbench 1.8.0.13.
• Добавлены частичный снимок по версии игры и генерируемый отчёт Harbors для 18 баз-источников припасов; исходные секунды сохранены, интервал отображается в минутах.
• Добавлены целевой экспорт баз-источников и ревизия schemaVersion 2 с отдельным Harbors.json и общим индексом разделов; широкая диагностика остаётся отдельной командой.
• Добавлен экспорт состава физических хранилищ и вместимости выбранной базы, проверенный на SP_A_EveronAirport: 3 × 1000 + 2 × 500 = 4000; виртуальные контейнеры сохраняются отдельно и исключаются из итогов.
• Обход настроенных хранилищ расширен на все 18 баз-источников, в Harbors добавлен столбец вместимости. Перед обновлением актуальной таблицы сохранён исходный r0001; три случая принадлежности отдельных складов остаются unknown.
• Добавлены целевая команда контейнеров мира и отдельные OtherContainers JSON / Markdown; проверенные слоты баз и виртуальные представления исключены из физического итога.
• OtherContainers теперь группирует 568 физических слотов в 124 строки корневых родителей; индивидуальные записи и разные экземпляры prefab сохранены в JSON.
• Добавлены именованные локации и списки объектов OtherContainers / Harbors в горизонтальном радиусе 1000 м: 170 подписей, 142 объекта. Перекрывающиеся совпадения сохраняют расстояния и не означают игровую принадлежность.
• Locations Markdown упрощён до 150 списков локаций с объектами; типы, ID локаций и все 170 исходных подписей сохранены в JSON.
• Locations оформлен для ручной сверки групп мира: позиции локаций в заголовках, позиции объектов и расстояния в списках; данные припасов и идентификаторы сохранены в JSON.
• В r0009 радиус локаций по умолчанию уменьшен с 1000 до 500 м: 348 связей, 76 локаций с объектами; семь объектов без совпадений сохранены. Предыдущие опубликованные ревизии сохранены.
• В r0010 пруды, реки, ручьи и озёра исключены из сопоставления по типу подписи: 24 исключённые локации, 288 связей, 16 объектов без совпадений; все исходные подписи и объекты сохранены в JSON.
• r0011 собирает объекты только у населённых пунктов в радиусе 300 м: 47 сгруппированных объектов и отдельный UngroupedObjects со списком 95 оставшихся и их координатами; автоматического назначения другим локациям нет.
• r0012 добавляет Name Generic вторым этапом для остатка после населённых пунктов в том же радиусе 300 м: ещё 63 объекта сгруппированы, 32 остались, все 47 прежних назначений у населённых пунктов сохранены.
• r0013 добавляет Name Island наравне с населёнными пунктами в радиусе 300 м: три объекта из остатка отнесены к Île-aux-Saules, осталось 29; прежние назначения населённых пунктов / Generic сохранены.
• r0014 добавляет Name Hill в первый этап в радиусе 300 м: пять объектов из остатка отнесены к CALVARY HILL, осталось 24; прежние назначения населённых пунктов / островов / Generic сохранены.
• r0015 повышает радиус обоих этапов с 300 до 350 м: ещё пять объектов сгруппированы, два переходят от Generic к населённым пунктам, один получает дополнительную связь Generic. 31 непустая группа и 19 объектов без группы; прежние ревизии и исходные данные сохранены.
• r0016 объединяет группы и объекты без группы в одном Locations, с категорией без группы в конце; данные сопоставления и прежние ревизии сохранены.
• r0017 добавляет отдельные представления OtherContainers и Harbors по готовым связям Locations; значения припасов, неизвестные вместимости и прежние снимки сохранены.
• r0018 объединяет таблицы припасов в OtherContainers, Harbors идёт последней категорией; значения, локации, раздельные JSON-каталоги и прежние ревизии сохранены.
• r0019 добавляет целевые настройки КП и приоритет подтверждённой source-иерархии, затем населённых пунктов / остальных подписей; нераспознанные показаны явно.
• r0020 объединяет шесть соответствующих групп карты с КП (35 родителей, включая все пять CALVARY HILL), сохраняя исходные связи близости и физические значения припасов.
• r0021 связывает Provins и его пять объектов с Transformer Station по явному правилу версии / сценария / источников; значения и прежние группы сохранены.
• r0022 упрощает таблицы родителей с припасами: вместимость / начальные припасы перед составом, Source ID и счётчик контейнеров скрыты, полные данные остаются в JSON.
• r0023 добавляет 9 CampaignRemnantsSupplyDepot после Harbors и 47 родителей в 350 м; КП / Harbors и исходные значения сохранены, нераспознанным остался один объект.
• r0024 объединяет Harbors в одну таблицу: вместимость / состав перед пополнением; исходные значения, unknown и распределение сохранены.
• r0025 группирует маркеры складов по именованным локациям в 350 м с приоритетом поселений: 7 связаны, 2 без привязки, исходные контейнеры / значения сохранены.
• r0026 округляет координаты в таблицах и заголовках до трёх знаков после точки для Workbench; исходные позиции, расстояния, группы и прежние ревизии сохранены.
• r0027 убирает повторные подзаголовки складов и сохраняет позиции всех 9 маркеров в таблицах под локациями; настройки, списки контейнеров и JSON-значения прежние.
• r0028 убирает координаты маркеров складов из Markdown; позиции локаций / объектов, настройки, списки и канонические координаты сохранены.
• r0029 убирает настройки компонентов складских маркеров из Markdown, сохраняет исходные значения в JSON и откладывает исследование в опциональный TODO. Физические хранилища и группировка прежние.
• r0030 сначала определяет локации складов и собирает хранилища в 100 м до КП / map этапов: все 9 складов, 49 родителей / 266 контейнеров / 69600 вместимости, Régina — 5 / 31 / 7100. Привязка маркеров к локациям остаётся 350 м; четыре родителя нераспознаны.
• Найден и описан источник вместимости 1000 у хранилища командного пункта в локальных ресурсах 1.8.0.13: encapsulator actions FIA / US / USSR. Поддержка анализатором и runtime-проверка остаются планом; снимки прежние.
• r0032 объединяет командный пункт и остальные хранилища каждой КП в одну таблицу; начальные припасы командного пункта явно неизвестны.
• r0031 добавляет проверенный каталог prefab командного пункта и строки 1000 / состава для 5 и 6 контейнеров у всех 7 КП. Исходные значения и группировка прежние; состав рассчитан по действию, а не измерен в игре.
• r0033 подтверждает начальный запас командного пункта 0 после действия префаба, отдельно от поздней инициализации сети базы; у всех семи КП — 1000 / 0.
• Полные игровые отчёты и сравнение версий ещё разрабатываются; диагностика помечена partial.

### Runtime research — Unreleased / исследование

English: recorded per-session initial FIA command-post storage and base-grid supplies for HQC Everon 1.8.0.13, including the incomplete repeat series in the native scenario. No new runtime export feature is released.

Русский: сохранены измерения стартовых хранилищ КП FIA и общих сетей баз HQC Everon 1.8.0.13 с привязкой к сессиям и явным ограничением повторных проб штатного сценария. Новая функция runtime-экспорта не выпускается.

Unreleased / r0034: increase depot storage radius to 200 m; three additional parents at one depot. Радиус складов увеличен до 200 м, у одного склада добавлены три родителя.

Unreleased / r0035: add a separate deduplicated initial-supplies summary with explicit unknowns. Добавлена отдельная сводка начальных припасов без повторного учёта объектов, с явными неизвестными значениями.

Unreleased / r0036: category folders, summaries and linked per-group detail pages. Папки категорий, сводки и связанные страницы отдельных групп.

Unreleased / r0037: physical container locations on every detail page. Координаты физических контейнеров на каждой подробной странице.

Unreleased / r0038: harbor neighbor distance bands without reclassification. Списки соседних хранилищ доков по расстоянию без смены категорий.

Unreleased / r0039: limit harbor neighbors to 100 m without reclassification. Ограничение соседей доков 100 метрами без смены категорий.

Unreleased / r0040: per-container harbor inspection and runtime connection diagnostics. Проверка контейнеров доков и диагностика подключения в игровой сессии.

Unreleased / r0041: named harbor location pages / именованные страницы локаций доков.

Unreleased / r0042: align supply accounting with consolidated harbor pages / категории сводки приведены к объединённым страницам доков.

Unreleased / r0043: remove synthetic harbor unknown stock / убран искусственный неизвестный запас доков.

Unreleased / r0044: partition harbor storage by measured eligibility / состав доков по игровым проверкам.

Unreleased / r0045: starting HQ candidate catalog / каталог стартовых позиций главных баз.

Unreleased / r0046: move StartingPos21 stock from Other to Starting Bases.

Unreleased / r0047: ambient AI groups / первый каталог фоновых групп ИИ.

r0048: add inherited weapon-slot evidence for 17 FIA character prefabs and weapon tables for all 9 ambient group types; preserve patrol counts and historical revisions.

r0049: add configured morphine, bandage and tourniquet counts per character and group to all nine AI type pages, with explicit zero counts and source scope.


r0050: add measured prototype ammunition, magazine and grenade counts for all nine AI group types; separate spare/loaded magazines and chambered rounds.

r0051: regroup AI patrol spawn points using the supply location catalog and saved location merges; unique proximity assignment with explicit unmatched points.
