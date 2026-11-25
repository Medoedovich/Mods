# Item catalog tree

The development Items tab uses **Items → Common / map → category → subcategory → localized item name**. Map membership comes from enabled records in the installed game's official `types.xml`; Common also includes items without a confirmed exclusive map. Categories still follow loaded configuration and model resource paths. Each visible classname appears once and only populated folders are shown. Explicit test classes and $UNT$ / TODO placeholders are hidden from this catalog and its search. See [map definitions, filtering and validation](ITEM-MAPS.md). This hierarchy is unreleased; 0.4.0-alpha has no item map branches.

The Create panel fills the space above Scene Objects with a small gap. Additional height goes to the catalog list, without enlarging item rows. Both catalog tabs fit the available height, reserving the status area while both tabs use drag-and-drop. Window-size and toolbar-wrap changes update the layout.

Item labels use the in-game display name in the client's language. Hovering shows a native model, a **Classname** heading without a colon and the full technical name below it. The name wraps within its block; the localized name is not repeated. Names are read once from the inherited `displayName` in each item's original configuration root, without spawning models for the catalog. Missing or unresolved names fall back to the classname. Identical display names remain separate entries with their exact classnames; selection, dragging and XML never use the display label as an identifier. Items search matches both the localized name and the original classname.

- **Weapons:** rifles and SMGs (large lists gain cartridge folders), pistols, shotguns, bows and crossbows, melee, explosives, launchers, other weapons.
- **Ammunition:** rounds/projectiles, magazines (large lists gain cartridge folders), ammo boxes.
- **Attachments:** sights/scopes, muzzle attachments, weapon lights, stocks/handguards, other attachments.
- **Clothing:** backpacks, vests, tops, pants, footwear, headgear, masks, gloves, glasses, belts, other clothing. Large lists gain localized model-family folders containing their variants; single-member families remain direct rows.
- **Food and drinks:** food, drinks.
- **Equipment:** tools, containers, camping (large lists gain purpose-based folders), cooking, crafting, gardening, medical, navigation, radios, binoculars/devices, traps, books, consumables, other equipment.
- **Vehicle parts:** wheels, doors/body panels, components/supplies, other vehicle parts.
- **Other items:** classes without a recognized group.

Click a folder or press Enter on it to expand/collapse it. Selecting a folder clears the spawn classname. Selecting a leaf stores the exact classname; creating it still requires an active anchor. Catalog navigation does not move or select existing scene items.

Items search matches a query against both the client-localized display name and classname, ignoring case and surrounding spaces and accepting partial matches. For example, Hammer is found by its Russian name «Молоток» or Hammer, while AK74 is found by «КА-74» or AK74. Each matching class appears once even if both fields match. Search covers all visible inventory classes, reveals their ancestor folders and hides unrelated branches. There is no 100-result display limit. Search expansion is separate from normal browsing: clearing the query restores normal folder states. Both tabs retain their expanded branches when switching. StaticObj filtering applies only to Objects and remains hidden on Items.

Both catalog tabs show a magnifying-glass icon to the left of the search input. Items displays the muted **Classname / Name** placeholder; Objects retains **Classname** and its existing classname-only search. Entering text hides the placeholder and clearing the field restores it; it does not enter the query or block mouse input. The former caption above the field is removed.

Both catalog tabs scroll two rows per wheel step and preserve the current selection in 0.4.0-alpha. Counts appear in the tree headings; the duplicate Found/shown counter, classname field below the list and permanent drag instruction are removed. Successful creation clears the sidebar status rather than repeating Created and a classname in both panels; errors remain visible.

The input registry is unchanged: public (`scope = 2`) classes with models from CfgVehicles (Inventory_Base descendants), CfgWeapons and CfgMagazines. Each visible classname belongs to one item group, including unknown classes. Technical and placeholder classes are retained for resolving existing scenes/projects but omitted from catalog rows. CfgMagazines separates Ammunition_Base descendants from magazines. CarWheel and CarDoor inheritance identifies vehicle wheels and body panels even with custom model paths. Recognized DZ gear, characters, weapons and vehicles families, including suffixed terrain families, provide the remaining categories. Unknown weapons, clothing, optics and explosives have conservative inheritance fallbacks; other unfamiliar resources remain in Other items. This is catalog organization, not a change to CE loot categories or exported XML.

Within each map branch, categories follow resource families, so a fuel canister is under **Vehicle parts → Components and supplies** (its model is `DZ/vehicles/parts/JerryCan.p3d`), Hammer under **Equipment → Tools**, and HatchbackWheel under **Vehicle parts → Wheels**. Larger tool lists gain the subcategories described below. Classnames and creation behaviour are unchanged. Editor category labels support Russian/English with English fallback; item names use the game's own localization in the active client language.

## По-русски

Панель «Создание» занимает свободное место над «Объектами на сцене», оставляя небольшой зазор. Дополнительная высота отдана списку, размер строк предметов сохранён. Обе вкладки учитывают нижние элементы панели: кнопку создания объекта и область статуса. При изменении размера окна или переносе кнопок панели инструментов высота пересчитывается.

В разрабатываемой версии «Предметов» — дерево **Предметы → Общее / карта → категория → подкатегория → игровое название**. Предметы без подтверждённой уникальной карты объединены с «Общим». Принадлежность определяется по включённым записям штатных `types.xml` установленной игры; внутри сохранены оружие, боеприпасы, обвесы, одежда, еда и напитки, снаряжение, запчасти и прочие предметы. Молоток (`Hammer`) находится в «Общее → Снаряжение → Инструменты», колесо (`HatchbackWheel`) — в «Общее → Запчасти → Колёса». У больших веток инструментов есть дополнительный уровень. Пустые ветки и явные тестовые записи скрыты. [Правила и фильтры](ITEM-MAPS.md). В опубликованной 0.4.0-alpha этого уровня карт ещё нет.

Предметы подписаны игровыми названиями на языке клиента. При наведении в превью видны модель, заголовок **Classname** без двоеточия и полное техническое имя ниже. Для длинных имён включён перенос строк; игровое название не повторяется. Названия читаются из унаследованного `displayName` исходного раздела конфигурации без создания моделей всего каталога. Если название отсутствует или не переводится, показывается classname. Предметы с одинаковыми названиями сохраняют разные строки и точные классы: выбор, перетаскивание и XML используют classname. Поиск в «Предметах» проверяет и игровое название на языке клиента, и исходный classname.

Щелчок или Enter раскрывает/сворачивает папку; папка не выбирается как classname для создания. Выбор конечного элемента сохраняет его точный класс. Для создания предмета по-прежнему нужна опора. Поиск работает по полному каталогу, проверяет одновременно игровое название и classname, не учитывает регистр и крайние пробелы, поддерживает часть названия и раскрывает путь к найденному предмету. Например, подходят «Молоток» и Hammer, «КА-74» и AK74. Если запрос совпал с обоими полями, класс всё равно показывается один раз. Ограничение в 100 результатов снято. Очистка поиска восстанавливает обычное состояние веток; переключение вкладок сохраняет раскрытые категории каждого дерева.

В обеих вкладках слева от поля поиска показана лупа. В «Предметах» плейсхолдер — **Classname / Name**; в «Объектах» остаются **Classname** и прежний поиск по техническому имени. Подсказка исчезает при вводе и возвращается после очистки, не входит в запрос и не мешает щелчку по полю. Прежняя подпись над строкой убрана.

Колёсико в «Предметах» прокручивает по одной строке за шаг, сохраняя выбор. Количество элементов видно в заголовках дерева; отдельный счётчик «Найдено/показано», поле Classname под списком и постоянная инструкция перетаскивания убраны. После успешного создания надпись «Создано: …» в обеих боковых панелях не показывается; сообщения об ошибках сохранены.

Состав доступных классов сохранён. Группы определяются по конфигурации и ресурсам модели, а не по категориям CE. Колёса и кузовные детали распознаются по наследованию CarWheel/CarDoor, боеприпасы — по CfgMagazines/Ammunition_Base. Для неизвестных ресурсов предусмотрено «Прочее»; классы не отбрасываются. Фильтр StaticObj остаётся только во вкладке объектов. Навигация по каталогу не меняет сцену, настройки спавна или экспорт XML. Все подписи доступны на русском и английском.

## Localized search validation / Проверка поиска по названиям

16 ноября 2026 года: **267 технических проверок прошли** в миссии без упаковки с русским интерфейсом, включая **4 проверки поиска**: регистр и крайние пробелы, часть локализованного названия, поиск оружия по игровому имени и classname, отдельный выбор классов с одинаковым игровым названием. Прежние проверки каталогов, выделения, перетаскивания, Gizmo и XML также прошли. Визуальная проверка оставлена автору; английский интерфейс проверяется перед релизом в Workshop.

16 November 2026: **267 technical checks passed** in an unpacked Russian mission, including **4 localized-search checks** covering case and surrounding spaces, partial names, weapon display names and classnames, and separate selection of classes with shared names. Existing catalog, selection, dragging, Gizmo and XML regressions also passed. Visual review is left to the author; English runtime validation is deferred until the Workshop release.

## Tool subcategories (unreleased)

The first stage of subdividing large item lists applies only to **Equipment → Tools** within each map/Common branch. When that branch's visible Tools list contains more than 30 classes, it gains these populated folders:

- **Construction:** Hammer, SledgeHammer, Shovel and related tools.
- **Hand tools:** Pliers, Screwdriver, Wrench and related tools.
- **Cutting and sawing:** Hacksaw, HandSaw and knives whose models already belong to Tools.
- **Repair kits and supplies:** SewingKit, WeaponCleaningKit, Blowtorch and related supplies.
- **Other tools:** remaining tool classes, including unfamiliar models.

With 30 or fewer tools, the existing flat list is retained. The threshold uses the complete loaded Tools group, not the current search results. This does not impose a maximum of 30 entries per new subgroup; other oversized branches will be reviewed separately.

Subdivision happens after the existing resource-based classification, so items in Consumables, Melee or other branches do not move into Tools merely because of their names. Known classnames or model filenames identify the new subgroups. Renamed mod classes using a known tool model follow that subgroup; unknown tool models remain accessible in Other tools. Every classname still belongs to one leaf group.

Search reveals all matching ancestor folders through the additional level. Clearing the query restores normal expansion state, and switching tabs preserves it. Display labels remain localized; selection, dragging, hover previews, projects and XML continue using exact classnames. Other branches keep their current hierarchy.

23 November 2026: all **14 new native catalog checks passed** in the Russian loose mission: exact tool selection through search, ancestor visibility, nested collapse, model aliases and unknown-tool fallback. Existing item coverage, localized search and expansion-state checks also passed. The full regression run later stopped at `creation Undo and Redo follow the saved scene baseline`; this result does not establish a clean full-suite pass and needs separate investigation. A normal preview mission was then opened for author review. No PBO was packed. English runtime validation remains a pre-release step.

### По-русски

Первый этап касается только ветки **«Снаряжение → Инструменты»** внутри каждой карты и «Общего». Если у неё больше 30 видимых предметов, появляются непустые подкатегории:

- **Строительство:** Hammer, SledgeHammer, Shovel и другие строительные инструменты.
- **Слесарные инструменты:** Pliers, Screwdriver, Wrench и похожие инструменты.
- **Резка и пиление:** Hacksaw, HandSaw и ножи, уже относящиеся к ветке инструментов.
- **Ремонтные наборы и средства:** SewingKit, WeaponCleaningKit, Blowtorch и другие средства ремонта.
- **Прочие инструменты:** остальные классы этой ветки, включая неизвестные модели.

При 30 предметах или меньше остаётся прежний плоский список. Порог определяется по всей ветке до поиска. Это первый этап: ограничение в 30 элементов внутри каждой новой подкатегории пока не гарантируется, остальные крупные ветки будут разбираться отдельно.

Предметы из других разделов не переносятся в «Инструменты». Класс или знакомая модель определяют новую подкатегорию только внутри прежней ветки Tools. Классы модов с известной моделью получают ту же подкатегорию; неизвестные инструменты остаются в «Прочих». Поиск по игровому имени и classname раскрывает весь путь через новый уровень; очистка поиска возвращает обычное состояние дерева. Точные classnames сохраняются для выделения, перетаскивания, превью, проектов и XML.

23 ноября 2026: в миссии без упаковки PBO на русском прошли **14 новых проверок дерева**: выбор точного класса через поиск с раскрытием предков, сворачивание вложенных веток, известные модели и неизвестные инструменты. Прежние проверки полноты каталога, поиска по локализованным названиям и состояния раскрытия тоже прошли. Позже общий прогон остановился на `creation Undo and Redo follow the saved scene baseline`; полный набор нельзя считать прошедшим, нужна отдельная проверка этого случая. Для автора запущена обычная миссия с остовом и колесом. Проверить «Снаряжение → Инструменты», поиск «Молоток» / `Hammer`, перетаскивание и сохранение раскрытых веток после очистки поиска и переключения вкладок. Английский интерфейс проверяется перед релизом.

## Weapon and magazine subgroups (unreleased)

Two more large lists are subdivided independently inside each map/Common branch. A list of **more than 30 visible entries** gains populated subfolders; smaller lists remain flat.

- **Rifles and SMGs → cartridge.** For example, AK74 uses 5.45x39 mm, AK101 uses 5.56x45 mm, and AKM/SKS use 7.62x39 mm. Read inherited `chamberableFrom[]`, including explicit muzzle sections. Regular, tracer and 9x39 AP variants share their cartridge folder. SKS/Mosin clips and speedloaders are resolved through their `ammoItems[]` rather than being mistaken for a new cartridge. The known stock cartridge designations have explicit aliases; unknown custom cartridges go to Other calibers, and multiple known cartridges go to Multiple calibers. The numeric `CfgAmmo.caliber` penetration coefficient is not used as a cartridge name.
- **Magazines → cartridge.** Read inherited `CfgMagazines ammoItems[]` and resolve their accepted rounds using the same cartridge identities as weapons. Regular, tracer and AP variants of one cartridge share a folder; capacity, color and compatible weapon sets do not split it. For example, FAMAS, AUG and STANAG magazines share 5.56x45 mm, while 7.62x39 mm and 7.62x54 mm R remain separate. Each magazine appears once. Unknown or missing cartridge data goes to Other calibers; multiple known cartridges go to Multiple calibers. The folder identifies the cartridge; actual weapon compatibility continues to be handled by the game.

Magazine grouping does not require a matching visible weapon class. Standard-caliber modded weapons and magazines can participate through their configuration; unknown/custom ammo remains accessible via the explicit fallback. Dynamic folder keys use technical cartridge identities, while unit labels use the client language. The former compatible-weapon grouping and its index are removed.

Global name/classname search reveals the extra folders, retains exact class selection and preserves normal expansion state after clearing the query or switching tabs. Grouping does not alter CE categories, item transforms, project records or XML. Each visible classname remains in exactly one leaf group. Clothing families are described in the next section.

23 November 2026: **180 native catalog checks passed in Russian**, including **28 weapon/magazine checks** covering cartridge aliases, nine real weapon configurations, SKS/Mosin clip handling, fourteen magazine/clip selections, cosmetic variants, merging magazines for different weapons by cartridge, keeping distinct 7.62 cartridges separate, independent collapse and complete coverage. All **2176 visible classes** remain; the **86 intentionally hidden classes** are unchanged. This is the catalog-only regression run, not a full editor regression. The successful client remains open with the wreck and wheel. No PBO was built; English runtime checks remain a pre-release step.

### По-русски

Внутри каждой карты и «Общего» списки **более 30 видимых предметов** получают новые группы:

- **Винтовки и пистолеты-пулемёты → калибр.** Примеры: 5.45x39 мм, 5.56x45 мм, 7.62x39 мм, .308 Win. Обычные и трассирующие патроны не разделяются на разные калибры. Данные берутся из конфигурации подходящих патронов; для обойм СКС/Мосина и ускорителей заряжания учитывается их содержимое. Неизвестные калибры не угадываются и остаются в «Прочих калибрах».
- **Магазины → калибр.** Калибр определяется по списку подходящих патронов `ammoItems[]`. Каждый магазин показан **один раз**; вместимость, цвет и набор подходящего оружия не создают отдельных групп. Например, магазины FAMAS, AUG и STANAG находятся в 5.56x45 мм. Неизвестные случаи остаются в «Прочих калибрах». Группа обозначает патрон; совместимость с конкретным оружием остаётся игровой.

Небольшие списки остаются плоскими. Поиск, превью, точные classnames, выбор и перетаскивание сохранены. Карты, фильтрация тестовых вещей и состав предметов не меняются. Группировка одежды описана ниже.

23 ноября 2026: прошли **180 проверок каталога**, включая **28 проверок оружия и магазинов**; сохранены все **2176 видимых предметов** без повторов. Проверены 14 магазинов и обойм, в том числе объединение разных оружейных систем по одному патрону и разделение 7.62x39 / 7.62x54. Это отдельная проверка каталога, английская проверка оставлена до релиза. Редактор оставлен открытым с остовом и колесом, PBO не собирался. Для ручной проверки открыть большие ветки оружия и магазинов в «Общем», проверить подписи групп, найти `AK74`, `SKS` и `Mag_STANAG_30Rnd`, затем перетащить найденный предмет на сцену.

## Clothing model families (unreleased)

Inside each map/Common branch, a clothing category containing **more than 30 visible items** gains folders for garment families with multiple members. For example:

```text
Clothing
├─ Gloves → Leather gloves → individual variants
├─ Headgear → Ballistic helmet → individual variants
├─ Pants → Capri pants → individual variants
└─ Footwear → Athletic shoes → individual variants
```

The same rule applies to the remaining clothing categories. In the current installed data it also subdivides large Backpack, Vest, Top and Mask lists. A family with just one member in that map branch remains directly in its category. Subfolders and their expanded contents appear before the parent's direct item rows throughout the Items tree, including search results. Categories of 30 items or fewer stay flat; an empty category or folder is not drawn. The threshold is based on the complete branch, not the search result size. This does not guarantee that every resulting family or category has at most 30 rows; other large lists remain planned work.

Families follow the inherited `CfgVehicles` class and normalized ground-model path. Variants ascend through parents using the same model, stopping at the nearest `ColorBase` or before generic Clothing/Inventory bases. A `ColorBase` without its own model can still collect its seasonal variants. Separate color-base families remain separate even when they reuse a model: USMCPants and OMKPants are not merged. A class with missing or unknown family information remains available as its own family. The algorithm does not merge unrelated garments merely because their translated labels match.

Folder captions use the family class's inherited game `displayName` in the client's language, falling back to a visible member's name if unavailable. The technical family classname supplies the stable folder identity. Individual item labels, classnames, hover models and drag targets remain unchanged. As before, variants with identical game names remain distinct item rows; the hover preview identifies the exact classname.

Name/classname search reveals all ancestor folders and exact variant rows. Family folders can collapse independently without becoming a selected spawn class; changing search restores matching paths, and normal expansion states survive clearing the query or switching tabs. Projects and XML keep exact item identities and do not store these presentation groups. The catalog input and map rules are unchanged: this change adds no filter based on types presence, positive nominal or the crafted flag.

23 November 2026: **205 native catalog checks passed in Russian**, including **25 new clothing checks** covering sixteen real variants across eight clothing sections, all four requested large categories, separation of families sharing a model, unknown configuration, single-item rows, localized search, collapse and complete coverage. All **2176 visible items** and the existing **86 hidden classes** are accounted for. The catalog-only run is not a full editor regression; the earlier unrelated Undo/Redo failure remains outside this task. The first client launch ended before mission loading; the successful retry compiled and completed all catalog checks. No PBO was packed. English runtime checks remain a pre-release step, and visual review is left to the author.

### По-русски

Крупные категории одежды теперь разбиваются по семействам вещей: **«Перчатки → Кожаные перчатки»**, **«Головные уборы → Баллистический шлем»**, **«Штаны → Брюки капри»**, **«Обувь → Спортивные ботинки»**. Внутри остаются отдельные цветовые варианты. Правило также применяется к остальным категориям одежды, если в них больше 30 предметов.

Порог считается отдельно внутри карты и «Общего». При 30 вещах или меньше список остаётся прежним. Семейство с единственной вещью показывается прямой строкой, без папки ради одного предмета. Во всём дереве «Предметов», включая поиск, сначала идут подкатегории и их раскрытое содержимое, затем вещи непосредственно из родительской категории. Семейства определяются по конфигурации наследования и модели, а подписываются игровыми названиями на языке клиента. Разные семейства не склеиваются только из-за общей модели или одинакового перевода. Неизвестные классы сохраняются.

Поиск по игровому имени и classname раскрывает весь путь; каждый вариант выбирается отдельно и сохраняет свой classname для превью, перетаскивания, проекта и XML. Новых ограничений по наличию записи в `types.xml`, nominal или crafted не добавлено.

23 ноября 2026: прошли **205 проверок каталога**, включая **25 новых для одежды**. Сохранены все **2176 видимых предметов**, прежние 86 скрытых классов учтены. Это отдельная проверка каталога, не полный прогон редактора. Редактор оставлен открытым с остовом и колесом, PBO не собирался. Для ручной проверки открыть «Общее → Одежда», посмотреть четыре указанные ветки, найти `Breeches_Pink` / «Брюки капри» и перетащить нужный вариант в сцену. Английский интерфейс проверяется перед релизом.

## Camping subgroups (unreleased)

Camping lists exceeding 30 visible items split independently in each map/Common branch. Resolve purpose by configured inheritance and known model filenames, only for items already classified in Camping. Keep unfamiliar items in Other camping items and hide empty folders. Tent containers are classified as shelters before generic storage; flagpoles are classified with flags before generic structures. ShelterKit retains its shelter purpose despite reusing a watchtower-kit model. Other catalog branches are unchanged.

The current **70 Common camping items** are distributed as follows:

| Group / Подгруппа | Items / Предметов | Examples |
|---|---:|---|
| Палатки и укрытия / Tents and shelters | 15 | CarTent, MediumTent, ShelterKit |
| Хранение / Storage | 5 | SeaChest, WoodenCrate, AnniversaryBox |
| Строительство / Construction | 9 | FenceKit, BarbedWire, CamoNet, WoodenLog |
| Замки / Locks | 4 | CombinationLock, CombinationLock4, DigitalCodeLock |
| Электропитание / Power supply | 3 | PowerGenerator, BatteryCharger, CableReel |
| Освещение / Lighting | 2 | Spotlight, XmasLights |
| Флаги и флагштоки / Flags and flagpoles | 32 | Flag_DayZ, TerritoryFlag, TerritoryFlagKit |

The unknown-item fallback is currently empty in Common. A list of 30 or fewer Camping items remains flat. All classes retain one map branch and one leaf group; global name/classname search reveals the new levels, and folder-first display is preserved. Grouping does not change scenes, projects, CE settings or XML.

23 November 2026: **234 Russian native catalog checks passed**: the existing 205 checks, **28 camping checks** and the audit export check. Cases include 23 real camping classes, inheritance precedence, a renamed-model alias, unknown-resource fallback, collapse, localized search and complete item coverage. The successful client is retained for author review. No PBO was built. This is a catalog-only run; English runtime validation remains a pre-release step.

По-русски: «Лагерь» разбит по назначению, с тем же порогом более 30 предметов. Неизвестные вещи не пропадают, а получают «Прочие лагерные предметы». Для проверки открыть «Общее → Снаряжение → Лагерь», посмотреть папки, найти канатную катушку (`CableReel`) и перетащить её на сцену. Состав каталога сохранён: **2176 видимых и 86 ранее скрытых классов**.

## Remaining subdivision candidates

Historical snapshot before the expanded subdivisions below. All recommendations except Books have since been implemented. The linked machine-readable report now describes the final catalog.

Snapshot: **23 November 2026**, installed game data, Russian client, all **2176 visible classnames** after the Camping split. The developer catalog-only run exported the actual post-grouping inventory; counts do not approximate model directories or types.xml. See the [machine-readable snapshot](catalog-subdivision-audit.json).

There are **11 lists with more than 30 direct items**. All are currently in Common. A direct list can coexist with child folders. Counting immediate populated folders as rows finds **two additional crowded clothing levels**. Descendants inside a closed child folder are not counted as immediate rows. Suggestions below are future work; no additional groups or visibility rules were applied outside Camping.

| Раздел в «Общем» | Прямых вещей | Папок | Предлагаемая разбивка |
|---|---:|---:|---|
| Запчасти → Двери и кузовные детали | 168 | 0 | Модель машины → двери / капот / багажник → варианты |
| Снаряжение → Книги | 144 | 0 | Автор или алфавитные диапазоны; не угадывать жанр |
| Еда и напитки → Еда | 108 | 0 | Консервы, мясо, рыба, овощи/фрукты, грибы, сухие продукты и сладости |
| Одежда → Головные уборы | 28 | 35 | Шлемы, шапки, кепки/панамы, капюшоны/повязки, аксессуары шлемов → семейства |
| Обвесы → Приклады и цевья | 54 | 0 | Приклады, цевья, маскировка; далее семейства оружия или моделей |
| Снаряжение → Расходники | 53 | 0 | Материалы строительства, шкуры/кожа, газ, свет/питание, рыболовные расходники |
| Одежда → Верхняя одежда | 14 | 29 | Куртки, рубашки/футболки, свитеры, форма, броня/защита; повязки отдельно |
| Верхняя одежда → Нарукавная повязка | 41 | 0 | Однотонные, с символикой; при необходимости символику делить дальше |
| Прочие предметы | 36 | 0 | Сначала пересмотреть 34 модели голов персонажей; оставшиеся два класса — отдельно по смыслу |
| Инструменты → Прочие инструменты | 35 | 0 | Рыбалка, свет/обогрев, ключи/наручники, таймеры/канцелярия; служебные классы пересмотреть |
| Боеприпасы → Патроны и снаряды | 34 | 0 | Патроны по калибрам, 40-мм гранаты, сигнальные ракеты, болты |
| Снаряжение → Контейнеры | 32 | 0 | Бочки, защитные ящики/футляры, сумки, подарки и мягкие игрушки |
| Лагерь → Флаги и флагштоки | 32 | 0 | Флаги и флагштоки/наборы; при необходимости флаги делить по символике |

**Priority:** vehicle body parts, food, attachments and consumables offer the clearest useful split. Books are also large, but retaining them was already agreed and most source files are under an uninformative `Automatic` directory, so resource-based genre guesses are inappropriate. Author or alphabetical grouping is more defensible.

The cleanup audit found technical classes missed by the earlier name-based filter: the Other list contains 34 character heads plus PowerGeneratorStatic and StorageBox_Wooden; Other tools includes Raycaster, UndergroundBreadcrumbHandle and UndergroundTriggerHandle. This report does not hide them. Reconsidering visibility is a separate decision from subdividing gameplay items.

По-русски: анализ учитывает не только количество вещей, но и количество строк с закрытыми подпапками. Поэтому в головных уборах остаётся **63 строки** (28 вещей + 35 папок), в верхней одежде — **43** (14 + 29). Самые полезные следующие шаги — кузовные детали по машинам, еда по типу, приклады/цевья и расходники. Книги и дополнительные служебные вещи сейчас не удаляются и не скрываются.

## Expanded subdivisions (unreleased)

Implemented all recommendations from the snapshot except Books, as requested by the author:

| Section | New structure |
|---|---|
| Vehicle body parts | Ada / Olga / Gunter / Sarka / M3S / M1025 → doors, hoods or trunks → exact variants |
| Food | Canned food (opened/unopened), meat, fish, carcasses, vegetables, fruit, mushrooms, dry food, snacks and bait |
| Stocks and handguards | Stocks / handguards → weapon family; camouflage separately |
| Consumables | Building materials, pelts/leather, gas, lighting/power, fishing, fire starting, textiles and Other |
| Headgear | Helmets, helmet accessories, warm hats, caps/berets, hats/headbands, hoods/wraps and Other → model families |
| Tops | Jackets/coats, shirts, sweaters, uniforms, protective clothing, improvised clothing, armbands and Other → model families |
| Armbands | Plain colors, places, animals, organizations and other designs |
| Other tools | Fishing, keys/restraints, clocks/writing, lighting/power, detonators, technical items and Other |
| Loose ammunition | Cartridges by caliber, 40 mm grenades, flares and bolts |
| Containers | Barrels, cases, bags, gifts, toys and Other |
| Flags and flagpoles | Flagpoles/kits and flags → design groups |
| Other items | Character heads → male/female/other; devices and storage separately |

Apply the >30 threshold independently within each map/Common branch. Smaller map-specific lists remain flat. Empty folders are hidden; subfolders precede direct item rows. Unknown resources retain a fallback. This changes catalog presentation only: exact classnames, localized names, global search, map membership, projects and XML remain available. No new types.xml/nominal/crafted or technical-item visibility filters were added. All 144 Books keep their original category, names and membership.

По-русски: реализованы все согласованные разделы, кроме книг. Например: **«Запчасти → Двери и кузовные детали → Ada 4x4 → Двери»**, **«Еда → Консервы → Открытые / Закрытые»**, **«Головные уборы → Шлемы → Баллистический шлем»**. Служебные вещи собраны в подгруппы, а не скрыты. Для ручной проверки открыть эти ветки, найти нужную вещь по имени или classname, навести для превью и перетащить конкретный вариант на сцену.

23 November 2026: **285 Russian native catalog checks passed**, including 51 new checks for the expanded groups. The actual before/after CSV comparison confirms all **2176 visible classnames**, localized item names, map membership and all **144 unchanged Books**; the prior 86 hidden classes remain accounted for. Only Books still exceed 30 immediate rows or direct items. See the [final audit](catalog-subdivision-audit.json). The editor is retained with a wreck and wheel for author review. This was a catalog-only run, not the full editor suite; no PBO was built and English runtime testing remains a pre-release step.

The loose-mission builder loads translations from JSON and separates ordinary, Catalog and Full test builds. Ordinary launches omit embedded regression suites; Catalog builds retain all catalog checks and explicit failing stubs for excluded suites. This avoids exhausting the standalone mission compiler's static buffer while keeping editor functionality intact. The packaged addon continues to use its native stringtable.
