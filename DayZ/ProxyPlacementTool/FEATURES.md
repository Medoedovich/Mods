# Proxy Placement Tool features

This page describes the published **0.4.0-alpha**. See the [changelog](CHANGELOG.md) for changes in each version.

## Create and place loot

1. Drag a building or wreck from **Objects** into the scene. It becomes the anchor for all item coordinates.
2. Find an item by its game name or classname, check its 3D preview, then drag it into the world editing area.
3. Select the item in the world or in **Scene Objects**. Use **Move (F7)**, **Rotate (F8)** or the position and Roll/Pitch/Yaw fields. Use **Place on surface** to lay it flat on the ground or floor directly below it while keeping X and Z.
4. Use **Standard loot points** to see the existing spawn volumes around the anchor. Press **F4** to check visibility, the Take action and Nearby inventory with the test character.
5. Save the scene as a project, or export the item or whole anchor as CE `dispatch` XML for integration into the target mission.

- **Catalogs.** Objects are organized by ChernarusPlus, Livonia, Sakhal and Nasdara, with categories and a StaticObj filter. Items have categories, localized names and classname search. The 3D hover preview shows the exact classname. Both tabs scroll two rows per wheel step. [Objects](docs/MAP-CATALOG.md) · [Items](docs/ITEM-CATALOG.md)
- **Scene and properties.** One active anchor per scene, with confirmation before replacement. The scene list includes the anchor, character and items. Drag with the native Gizmo or edit numbers directly. Each field has its own reset, and F9 restores the selection's full starting transform. [Scene objects](docs/SCENE-OBJECTS.md) · [Properties](docs/COMPACT-PROPERTIES.md)
- **Camera.** Hold RMB over the scene to fly. Use WASD and the mouse, Q to rise and Z to descend. The mouse wheel changes the 0.1–16× speed multiplier, shown briefly below the crosshair. Left Shift/Ctrl speed up and left Alt slows down. The camera icon in **View** opens a quick reference. [Camera controls](docs/CAMERA-CONTROLS.md)
- **Projects and history.** Save and reopen JSON scenes containing the anchor, placed items, character and camera. The editor validates a project before replacing the scene and keeps the previous file on overwrite. Undo and Redo group a complete Gizmo drag or field edit into one transform action. [Projects](docs/PROJECTS.md) · [Undo/Redo](docs/UNDO-REDO.md)
- **Loot reference and export.** The overlay uses the installed game's `mapgroupproto.xml` when available and labels the bundled fallback. The overlay stays out of the exported XML. Use **F10** to export the selected item and its anchor, or **Anchor XML** for the entire anchor. [Loot sources](docs/LOOT-SOURCES.md) · [CE integration](README.md#export-and-scope)
- **Editor interface.** Localized English and Russian labels, toolbar groups with tooltips, and success/warning/error notifications. The live world stays inside the editing area, with the blurred landscape behind the panels. The editor runs offline in DayZDiag on Test Range. [Theme](docs/EDITOR-THEME.md) · [Toolbar](docs/ICON-TOOLBAR.md) · [Notifications](docs/NOTIFICATIONS.md)

## Возможности редактора

В списке описан кандидат **0.4.0-alpha**. Опубликованные версии указаны в [журнале изменений](CHANGELOG.md).

1. Перетащи здание или остов из **«Объектов»** в сцену. Опора задаёт систему координат для предметов.
2. Найди предмет по игровому названию или classname, посмотри 3D-превью и перетащи его в активную область.
3. Выбери предмет в мире или в списке **«Объекты на сцене»**. Используй **F7** для перемещения, **F8** для поворота или поля координат и углов для точной настройки. Кнопка **«Положить на поверхность»** укладывает предмет плашмя на землю или пол под ним с сохранением X и Z.
4. Включи **«Штатные точки лута»**, чтобы видеть их объёмы. Нажми **F4**, чтобы проверить расположение предмета, действие «Взять» и раздел «Поблизости» от лица персонажа.
5. Сохрани сцену как проект или экспортируй предмет либо всю опору в CE `dispatch` XML для целевой миссии.

- **Каталоги.** Объекты сгруппированы по картам и категориям. StaticObj включаются отдельным флажком. У предметов есть категории, локализованные названия и поиск по classname. Точный класс показан в 3D-превью. Обе вкладки прокручиваются на две строки за шаг колёсика.
- **Сцена и свойства.** Одна активная опора с подтверждением замены. В списке сцены видны опора, персонаж и предметы. Координаты и углы применяются сразу после корректного ввода. У каждого поля есть сброс. **F9** возвращает всю позу к моменту выделения.
- **Камера.** Удерживай ПКМ над сценой для полёта. **WASD** — движение, мышь — обзор, **Q** — подъём, **Z** — спуск. Колёсико меняет множитель от 0,1× до 16× и на короткое время показывает его под прицелом. Левые Shift/Ctrl ускоряют полёт, левый Alt замедляет. Иконка камеры в разделе **«Просмотр»** открывает подсказку.
- **Проекты и история.** JSON хранит опору, предметы, персонажа и камеру. При перезаписи сохраняется предыдущий файл. Undo и Redo восстанавливают положение и поворот за одно действие.
- **Штатный лут и экспорт.** Объёмы берутся из установленной игры или из встроенного снимка с указанием источника. **F10** экспортирует выбранный предмет и его опору. Готовый XML подключается к экономике целевой миссии.
- **Интерфейс.** Русские и английские подписи, группы инструментов, подсказки и уведомления. Игровой мир виден в области редактирования, за панелями — размытый пейзаж. Редактор запускается офлайн в DayZDiag на Test Range.
