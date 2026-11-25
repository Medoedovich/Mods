# Item map branches (unreleased)

The development Items catalog has this hierarchy:

```text
Items
├─ Common
├─ ChernarusPlus
├─ Livonia
├─ Sakhal
└─ Nasdara
   └─ category → subcategory → item
```

Every populated branch retains the existing item categories and tool subcategories. Empty branches are hidden. Each visible classname appears exactly once. Explicit test classes and placeholder entries are filtered from the catalog, as described below. Global search by localized name or classname reveals the full matching path; clearing search and switching tabs preserve normal folder expansion. Hover previews, selection, drag-and-drop, projects and XML still identify items by their exact classnames. The Objects catalog is unchanged.

## Definition and sources

On editor startup, read `DZ/worlds/<world>/ce/db/types.xml` directly from the installed game. The four world folders are `chernarusplus`, `enoch`, `sakhal` and `nasdara`. There is no bundled membership snapshot to update.

- **Common:** positive `nominal` on two or more maps, or no confirmed exclusive map. This includes zero-nominal records, unknown/modded classes absent from official data, and insufficient readable sources. Common does not imply natural spawning on every map.
- **A map branch:** positive `nominal` only on that map, with valid data available for all four maps.

This is a grouping by **enabled records in the official types data**, not asset origin or a complete simulation of natural loot availability. A positive nominal is not a guarantee that an item will appear: events, CE categories, usage, tiers, limits and other mission settings can affect spawning. Zero nominal does not mean an item is unusable: crafting, attachments and scripted or special creation can still provide it. Those items remain accessible in Common. Custom server mission settings do not change this built-in catalog grouping.

For example, the installed data checked on 23 November 2026 places Hammer and ScientificBriefcase in Common, Iceaxe in Sakhal, and BrickTrowel in Nasdara. ScientificBriefcase has zero nominal on every map and is still available for placement and export. Resource paths alone cannot reliably identify origin: Iceaxe uses `DZ/gear/tools/Ice_Axe.p3d`, and ScientificBriefcase uses `DZ/gear/containers/ScientificCase.p3d`.

XML is read once during browser construction using bounded streaming fragments. Comments and split tags/numbers are handled; malformed, truncated or duplicate entries invalidate the affected map as a whole. Unreadable sources are logged. If one map is unavailable, an item known on two remaining maps can still be Common, but an item seen on just one cannot be declared exclusive. No classes are dropped because a source failed.

Subdivision of Tools at more than 30 entries applies independently within each map/Common branch. A smaller list remains flat. The catalog branch does not select the active world's terrain, the standard-loot overlay source or any CE export settings.

## Catalog cleanup

The former Unassigned branch is merged into Common. The following entries are omitted from Items and its search:

- Display names containing the explicit `$UNT$` marker, or the exact placeholder `TODO`.
- Classnames beginning with `Test_` / `Debug_`, or ending with `_Test` / `_Debug`, ignoring case.
- Known technical helpers `DoorTestCamera` and `M79DummyOptics`.

The filter does not match arbitrary occurrences of `Test`: BloodTestKit remains available. Missing or unresolved `$STR` translations alone do not hide an item; the existing classname fallback remains. Hidden classnames are retained in the resolver, and filtering does not delete existing scene items or invalidate saved projects. The runtime log lists excluded classes and reasons. No additional visibility checkbox is introduced.

## Validation

The initial six-branch version passed **143 native catalog checks in Russian** on 23 November 2026, including **18 new checks** for map-source parsing, malformed input, conservative handling of unavailable sources, all four installed files, exact item selection in each branch, collapse, empty search and complete classname coverage. All **2262** loaded inventory classes were represented once before the explicit cleanup filter was added. The four enabled-record totals matched the extracted official XML: ChernarusPlus 1115, Livonia 1039, Sakhal 1041 and Nasdara 1103 (these totals include records outside the inventory catalog).

After merging Unassigned into Common and adding the filter, **152 Russian native catalog checks passed**, including **9 new visibility checks**. The current client has **2176 visible and 86 hidden classes**, accounting for all 2262 known classes. The hidden set includes Candle, Cassette, DoorTestCamera, the test helmet/map variants and Mag_AKM_Drum_TEST. Tests confirm that BloodTestKit remains selectable, technical classnames remain resolvable and neither placeholders nor the old Unassigned folder appear in search/navigation.

The catalog-only check intentionally ends before the broader editor tests; it is not a full editor regression pass. The separate Undo/Redo check that failed earlier remains unresolved. No PBO was built. English runtime checks remain a pre-release step, and visual review is left to the author.

To review: open Items, inspect Common and the four map branches, search for Hammer / its localized name and Iceaxe, drag a result onto the scene, and clear search to check that folder expansion is restored. Check that ScientificBriefcase and BloodTestKit remain available, while DoorTestCamera and `$UNT$` entries are absent.

## По-русски

В разрабатываемой версии дерево устроено так: **Предметы → Общее / ChernarusPlus / Livonia / Sakhal / Nasdara → категории → предметы**. «Без привязки к карте» объединено с «Общим». Пустые ветки скрываются, каждый видимый classname показан один раз.

При запуске редактора читаются `types.xml` всех четырёх карт из установленной игры:

- **Общее:** ненулевой `nominal` на двух или более картах либо отсутствие подтверждённой уникальной карты. Сюда же входят записи с нулём везде, неизвестные классы модов и случаи недостаточных данных. Это не означает штатный спавн на всех картах.
- **Ветка карты:** ненулевой `nominal` только у этой карты, если все четыре файла успешно прочитаны.

Это классификация по включённым записям штатных `types.xml`. Она не определяет происхождение ресурса и не обещает фактическое появление предмета: на него влияют остальные настройки экономики, динамические события и скрипты. Вещи с нулевым nominal, включая крафтовые и специальные, остаются доступными для размещения и экспорта. Настройки конкретного пользовательского сервера не используются как источник этого дерева.

Молоток и ScientificBriefcase находятся в «Общем», Iceaxe — на Sakhal, BrickTrowel — на Nasdara. Чтение выполняется заново при запуске редактора, поэтому отдельный снимок данных для обновлений игры не нужен. Если источник недоступен, классы не исчезают и не становятся ошибочно «уникальными» для другой карты.

Из каталога и поиска скрываются названия с `$UNT$` или точным `TODO`, технические классы с префиксами `Test_` / `Debug_` и суффиксами `_Test` / `_Debug`, а также DoorTestCamera и M79DummyOptics. BloodTestKit и обычные предметы без перевода сохраняются. Старые сцены и проекты с уже созданными техническими предметами не удаляются и не блокируются. Скрытые классы и причины перечисляются в логе.

Внутри веток сохранены категории, локализованные названия, поиск по названию и classname, превью и перетаскивание. Порог разделения «Инструментов» применяется отдельно в каждой ветке. Выбор ветки каталога не меняет карту мира, источник визуализации штатного лута или экспорт.

23 ноября 2026: первоначальная версия с шестью ветками прошла **143 проверки каталога на русском**, включая **18 новых**; до добавления фильтра были показаны все **2262** класса без повторов. Это отдельный прогон каталога, а не полный набор проверок редактора. Прежнее падение проверки Undo/Redo остаётся для отдельного разбора. PBO не собирался. Проверку вида и управления проводит автор, английский интерфейс проверяется перед релизом.

После объединения веток и фильтрации прошли **152 проверки**, включая **9 новых**. В текущем клиенте показаны **2176 классов**, **86** скрыты; учтены все 2262 известных класса. Проверены доступность BloodTestKit, отсутствие тестовых вещей и `$UNT$` в поиске, сохранение разрешения скрытых classnames и отсутствие прежней ветки «Без привязки к карте».
