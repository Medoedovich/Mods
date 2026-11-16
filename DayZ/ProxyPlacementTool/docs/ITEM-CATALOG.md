# Item catalog tree

The Items tab uses **Items → category → subcategory → localized item name**. It has no map branches: items are grouped by their loaded configuration and model resource paths, rather than placement on a terrain. Only populated folders are shown.

The Create panel fills the space above Scene Objects with a small gap. Additional height goes to the catalog list, without enlarging item rows. Both catalog tabs fit the available height, reserving the status area while both tabs use drag-and-drop. Window-size and toolbar-wrap changes update the layout.

Item labels use the in-game display name in the client's language. Hovering shows a native model, a **Classname** heading without a colon and the full technical name below it. The name wraps within its block; the localized name is not repeated. Names are read once from the inherited `displayName` in each item's original configuration root, without spawning models for the catalog. Missing or unresolved names fall back to the classname. Identical display names remain separate entries with their exact classnames; selection, dragging and XML never use the display label as an identifier. Items search matches both the localized name and the original classname.

- **Weapons:** rifles and SMGs, pistols, shotguns, bows and crossbows, melee, explosives, launchers, other weapons.
- **Ammunition:** rounds/projectiles, magazines, ammo boxes.
- **Attachments:** sights/scopes, muzzle attachments, weapon lights, stocks/handguards, other attachments.
- **Clothing:** backpacks, vests, tops, pants, footwear, headgear, masks, gloves, glasses, belts, other clothing.
- **Food and drinks:** food, drinks.
- **Equipment:** tools, containers, camping, cooking, crafting, gardening, medical, navigation, radios, binoculars/devices, traps, books, consumables, other equipment.
- **Vehicle parts:** wheels, doors/body panels, components/supplies, other vehicle parts.
- **Other items:** classes without a recognized group.

Click a folder or press Enter on it to expand/collapse it. Selecting a folder clears the spawn classname. Selecting a leaf stores the exact classname; creating it still requires an active anchor. Catalog navigation does not move or select existing scene items.

Items search matches a query against both the client-localized display name and classname, ignoring case and surrounding spaces and accepting partial matches. For example, Hammer is found by its Russian name «Молоток» or Hammer, while AK74 is found by «КА-74» or AK74. Each matching class appears once even if both fields match. Search covers all loaded inventory classes, reveals their ancestor folders and hides unrelated branches. There is no 100-result display limit. Search expansion is separate from normal browsing: clearing the query restores normal folder states. Both tabs retain their expanded branches when switching. StaticObj filtering applies only to Objects and remains hidden on Items.

Both catalog tabs show a magnifying-glass icon to the left of the search input. Items displays the muted **Classname / Name** placeholder; Objects retains **Classname** and its existing classname-only search. Entering text hides the placeholder and clearing the field restores it; it does not enter the query or block mouse input. The former caption above the field is removed.

The Items mouse wheel moves one row per step and preserves selection. Counts appear in the tree headings; the duplicate Found/shown counter, classname field below the list and permanent drag instruction are removed. Successful creation clears the sidebar status rather than repeating Created and a classname in both panels; errors remain visible.

The input catalog is unchanged: public (`scope = 2`) classes with models from CfgVehicles (Inventory_Base descendants), CfgWeapons and CfgMagazines. Each classname belongs to one item group, including unknown classes. CfgMagazines separates Ammunition_Base descendants from magazines. CarWheel and CarDoor inheritance identifies vehicle wheels and body panels even with custom model paths. Recognized DZ gear, characters, weapons and vehicles families, including suffixed terrain families, provide the remaining categories. Unknown weapons, clothing, optics and explosives have conservative inheritance fallbacks; other unfamiliar resources remain in Other items. This is catalog organization, not a change to CE loot categories or exported XML.

The grouping follows resource families, so a fuel canister is under **Vehicle parts → Components and supplies** (its model is `DZ/vehicles/parts/JerryCan.p3d`), Hammer under **Equipment → Tools**, and HatchbackWheel under **Vehicle parts → Wheels**. Classnames and creation behaviour are unchanged. Editor category labels support Russian/English with English fallback; item names use the game's own localization in the active client language.

## По-русски

Панель «Создание» занимает свободное место над «Объектами на сцене», оставляя небольшой зазор. Дополнительная высота отдана списку, размер строк предметов сохранён. Обе вкладки учитывают нижние элементы панели: кнопку создания объекта и область статуса. При изменении размера окна или переносе кнопок панели инструментов высота пересчитывается.

Во вкладке «Предметы» — дерево **Предметы → категория → подкатегория → игровое название**. Ветки: оружие, боеприпасы, обвесы, одежда, еда и напитки, снаряжение, запчасти и прочие предметы. Молоток (`Hammer`) находится в «Снаряжение → Инструменты», колесо (`HatchbackWheel`) — в «Запчасти → Колёса». Канистра находится в «Запчасти → Компоненты и принадлежности», поскольку её модель хранится в vehicles/parts. Пустые ветки скрыты. По картам предметы не разделяются.

Предметы подписаны игровыми названиями на языке клиента. При наведении в превью видны модель, заголовок **Classname** без двоеточия и полное техническое имя ниже. Для длинных имён включён перенос строк; игровое название не повторяется. Названия читаются из унаследованного `displayName` исходного раздела конфигурации без создания моделей всего каталога. Если название отсутствует или не переводится, показывается classname. Предметы с одинаковыми названиями сохраняют разные строки и точные классы: выбор, перетаскивание и XML используют classname. Поиск в «Предметах» проверяет и игровое название на языке клиента, и исходный classname.

Щелчок или Enter раскрывает/сворачивает папку; папка не выбирается как classname для создания. Выбор конечного элемента сохраняет его точный класс. Для создания предмета по-прежнему нужна опора. Поиск работает по полному каталогу, проверяет одновременно игровое название и classname, не учитывает регистр и крайние пробелы, поддерживает часть названия и раскрывает путь к найденному предмету. Например, подходят «Молоток» и Hammer, «КА-74» и AK74. Если запрос совпал с обоими полями, класс всё равно показывается один раз. Ограничение в 100 результатов снято. Очистка поиска восстанавливает обычное состояние веток; переключение вкладок сохраняет раскрытые категории каждого дерева.

В обеих вкладках слева от поля поиска показана лупа. В «Предметах» плейсхолдер — **Classname / Name**; в «Объектах» остаются **Classname** и прежний поиск по техническому имени. Подсказка исчезает при вводе и возвращается после очистки, не входит в запрос и не мешает щелчку по полю. Прежняя подпись над строкой убрана.

Колёсико в «Предметах» прокручивает по одной строке за шаг, сохраняя выбор. Количество элементов видно в заголовках дерева; отдельный счётчик «Найдено/показано», поле Classname под списком и постоянная инструкция перетаскивания убраны. После успешного создания надпись «Создано: …» в обеих боковых панелях не показывается; сообщения об ошибках сохранены.

Состав доступных классов сохранён. Группы определяются по конфигурации и ресурсам модели, а не по категориям CE. Колёса и кузовные детали распознаются по наследованию CarWheel/CarDoor, боеприпасы — по CfgMagazines/Ammunition_Base. Для неизвестных ресурсов предусмотрено «Прочее»; классы не отбрасываются. Фильтр StaticObj остаётся только во вкладке объектов. Навигация по каталогу не меняет сцену, настройки спавна или экспорт XML. Все подписи доступны на русском и английском.

## Localized search validation / Проверка поиска по названиям

16 ноября 2026 года: **267 технических проверок прошли** в миссии без упаковки с русским интерфейсом, включая **4 проверки поиска**: регистр и крайние пробелы, часть локализованного названия, поиск оружия по игровому имени и classname, отдельный выбор классов с одинаковым игровым названием. Прежние проверки каталогов, выделения, перетаскивания, Gizmo и XML также прошли. Визуальная проверка оставлена автору; английский интерфейс проверяется перед релизом в Workshop.

16 November 2026: **267 technical checks passed** in an unpacked Russian mission, including **4 localized-search checks** covering case and surrounding spaces, partial names, weapon display names and classnames, and separate selection of classes with shared names. Existing catalog, selection, dragging, Gizmo and XML regressions also passed. Visual review is left to the author; English runtime validation is deferred until the Workshop release.
