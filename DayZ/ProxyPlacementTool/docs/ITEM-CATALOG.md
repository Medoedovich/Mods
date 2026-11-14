# Item catalog tree

The Items tab uses **Items → category → subcategory → classname**. It has no map branches: items are grouped by their loaded configuration and model resource paths, rather than placement on a terrain. Only populated folders are shown.

- **Weapons:** rifles and SMGs, pistols, shotguns, bows and crossbows, melee, explosives, launchers, other weapons.
- **Ammunition:** rounds/projectiles, magazines, ammo boxes.
- **Attachments:** sights/scopes, muzzle attachments, weapon lights, stocks/handguards, other attachments.
- **Clothing:** backpacks, vests, tops, pants, footwear, headgear, masks, gloves, glasses, belts, other clothing.
- **Food and drinks:** food, drinks.
- **Equipment:** tools, containers, camping, cooking, crafting, gardening, medical, navigation, radios, binoculars/devices, traps, books, consumables, other equipment.
- **Vehicle parts:** wheels, doors/body panels, components/supplies, other vehicle parts.
- **Other items:** classes without a recognized group.

Click a folder or press Enter on it to expand/collapse it. Selecting a folder clears the spawn classname. Selecting a leaf fills the exact classname; creating it still requires an active anchor. Catalog navigation does not move or select existing scene items.

Classname search ignores case and surrounding spaces, searches all loaded inventory classes, reveals their ancestor folders and hides unrelated branches. There is no 100-result display limit. Search expansion is separate from normal browsing: clearing the query restores normal folder states. Both tabs retain their expanded branches when switching. StaticObj filtering applies only to Objects and remains hidden on Items.

The input catalog is unchanged: public (`scope = 2`) classes with models from CfgVehicles (Inventory_Base descendants), CfgWeapons and CfgMagazines. Each classname belongs to one item group, including unknown classes. CfgMagazines separates Ammunition_Base descendants from magazines. CarWheel and CarDoor inheritance identifies vehicle wheels and body panels even with custom model paths. Recognized DZ gear, characters, weapons and vehicles families, including suffixed terrain families, provide the remaining categories. Unknown weapons, clothing, optics and explosives have conservative inheritance fallbacks; other unfamiliar resources remain in Other items. This is catalog organization, not a change to CE loot categories or exported XML.

The grouping follows resource families, so a fuel canister is under **Vehicle parts → Components and supplies** (its model is `DZ/vehicles/parts/JerryCan.p3d`), Hammer under **Equipment → Tools**, and HatchbackWheel under **Vehicle parts → Wheels**. Classnames and creation behaviour are unchanged. Labels use the native Russian/English string table; other client languages fall back to English.

## По-русски

Во вкладке «Предметы» — дерево **Предметы → категория → подкатегория → classname**. Ветки: оружие, боеприпасы, обвесы, одежда, еда и напитки, снаряжение, запчасти и прочие предметы. Внутри, например: «Снаряжение → Инструменты → Hammer» и «Запчасти → Колёса → HatchbackWheel». Канистра находится в «Запчасти → Компоненты и принадлежности», поскольку её модель хранится в vehicles/parts. Пустые ветки скрыты. По картам предметы не разделяются.

Щелчок или Enter раскрывает/сворачивает папку; папка не выбирается как classname для создания. Выбор конечного элемента подставляет его точный класс. Для создания предмета по-прежнему нужна опора. Поиск работает по полному каталогу, не учитывает регистр и крайние пробелы, раскрывает путь к найденному предмету. Ограничение в 100 результатов снято. Очистка поиска восстанавливает обычное состояние веток; переключение вкладок сохраняет раскрытые категории каждого дерева.

Состав доступных классов сохранён. Группы определяются по конфигурации и ресурсам модели, а не по категориям CE. Колёса и кузовные детали распознаются по наследованию CarWheel/CarDoor, боеприпасы — по CfgMagazines/Ammunition_Base. Для неизвестных ресурсов предусмотрено «Прочее»; классы не отбрасываются. Фильтр StaticObj остаётся только во вкладке объектов. Навигация по каталогу не меняет сцену, настройки спавна или экспорт XML. Все подписи доступны на русском и английском.
