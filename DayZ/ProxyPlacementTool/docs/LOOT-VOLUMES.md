# Standard loot reference — 0.4.0-alpha

The cylinder icon in the toolbar's **View** group toggles standard loot points for the current building/wreck. It is an overlay while placing Proxy items. It starts off and retains its on/off preference when the anchor changes.

- A cyan dot marks each `group/container/point` position. A translucent cyan cylinder shows its declared horizontal radius (`range`) and upward height (`height`), in metres.
- Amber markers mean that `range` or `height` is absent from the source XML. Only the known center and, when available, the base ring are drawn. The tool does not invent engine defaults for missing dimensions.
- The overlay moves with the anchor, leaves placed items in place, and hides in character mode, menus and when the app loses focus. It does not create inventory entities, intercept physics rays or add rows to Scene Objects. It is excluded from exported Proxy XML and transform history.
- This is a reference to the configured CE space, not a collision validator or a guarantee that every point will spawn loot. Container rules, retracing, loot limits, point flags and the target mission's changes still affect CE behavior. Existing `dispatch/proxy` entries are outside this overlay.
- An unknown prototype is reported as unavailable reference data, rather than proof that an object has no loot. A known prototype without ordinary points is distinguished from a missing one.

The tooltip shows the source map and either the installed DayZ version or an explicit bundled-fallback label. Point counts remain in the diagnostic log rather than the UI. An object added from a map branch uses that map's prototype. Replacing the anchor retains the new branch choice after confirmation; cancelling keeps the existing source. The optional `LootMap` field is saved in project format version 1 (`0` auto, `1` ChernarusPlus, `2` Livonia, `3` Sakhal, `4` Nasdara). Earlier projects without this field remain valid. Auto uses the current official world, or the first available map in that order on Test Range. It never merges differing map definitions.

The overlay does not create, edit, delete or populate standard points. Use the official CE tools for those operations. When integrating exported Proxy fragments, retain the target mission's existing container definitions.

## Data and geometry

The runtime-source integration passed 16 Russian native checks on 2026-11-17, including a complete comparison of 53,335 points and source/fallback rendering. See [runtime behavior and validation](LOOT-SOURCES.md).

The main source is the selected map's installed `DZ/worlds/<terrain>/ce/mapgroupproto.xml`, read directly through the game's virtual filesystem. A CE XML reader validates the complete file, including nesting, attributes and numeric point geometry, before making any groups available. It handles quoted and multiline attributes, comments and processing instructions; unsupported declarations and malformed data fail validation. Parsed map datasets are cached for the current editor session and re-read in a new session, rather than on every anchor movement or frame.

If installed XML cannot be read or validated, `data/loot_volumes.txt` provides a bundled fallback. The tooltip identifies it and enabling the overlay reports a warning. If valid installed XML lacks an object, or defines it with zero ordinary points, the snapshot is not mixed in. See [source behavior and validation](LOOT-SOURCES.md).

Both sources include ordinary points from **all** container names, including shelves and weapons. Known groups without ordinary points remain distinguishable from missing groups. `dispatch`, categories, quotas and probabilities are not used to generate preview items. The bundled fallback is derived from official map prototypes, combining same-named containers without discarding points and sharing identical records by map mask.

Only the selected anchor's reference geometry is drawn. Shapes are retained and rebuilt only when visibility or the anchor transform changes. Native debug triangles and lines have depth testing, no depth writes and no physics. Geometry uses the same calibrated CE/model basis as Proxy placement: CE `(x,y,z)` becomes model `(-z,y,x)`, then the anchor transform is applied. This matches the tool's unrotated, scale-one anchor and exported CE group angle `a=90`.

`loot-volume-sources.json` records source hashes, group counts and the generated data hash. Source author: **Bohemia Interactive**. Derived CE data is distributed under [ADPL-SA](https://www.bohemia.net/community/licenses/arma-and-dayz-public-license-share-alike-adpl-sa), as with the map catalog. Related official source: [DayZ Central Economy](https://github.com/BohemiaInteractive/DayZ-Central-Economy).

Refresh the dataset from extracted game files:

```powershell
.\tools\Update-LootVolumes.ps1 -WorldsRoot 'D:\DayZModding\DZ\worlds'
```

Development source verification: `ProxyPlacementTool/release/Test-LootVolumeData.ps1` compares every point component and missing dimension to its map's source, rejects extra/duplicate records, and checks the generated hash. The current dataset matches 2,172 group records and 53,335 points across the four maps.

Native RU verification uses the unpacked Test Range mission via `Test-WorldViewport.ps1 -LootVolumes -Language Russian`. Visual review by the author and English runtime checks before the Workshop release remain separate.

On 2026-11-17 the Russian unpacked mission passed **376 native checks**, including **14 overlay checks**: default/toggled visibility, source geometry and basis conversion, anchor translation without item/export changes, context hiding and shape disposal, all four garage definitions, distinct Chernarus/Sakhal office definitions, missing dimensions/localization, and JSON source-map persistence/validation. The successful client was retained for review. No PBO was built and no release was uploaded. Development report: `ProxyPlacementTool/release/LOOT-VOLUMES-VALIDATION-Russian.json`.

Author review:

1. Toggle the cylinder icon and check that dots and translucent volumes are readable at the wreck's ordinary loot positions, while the wheel still selects and moves.
2. Move the anchor: reference shapes should follow; placed items should stay in place. Undo the movement.
3. Replace the anchor with `Land_Garage_Row_Small` from the catalog. Check the floor and shelf volumes inside. Switch to character mode and back: reference shapes should hide and return.
4. Hover over the toolbar icon to check the source map. Save and reopen a project created from a particular map branch and check that the source map remains the same. Point counts are recorded in `[PROXY LOOT VOLUMES]` diagnostic log entries.

## По-русски

Иконка цилиндра в группе «Просмотр» включает **штатные точки лута** текущей опоры. Голубые точки и цилиндры показывают координаты, радиус и высоту из официального XML. Янтарный цвет означает, что в XML не хватает размеров: полный объём для такой точки неизвестен.

Карта берётся из ветки каталога, откуда добавлено здание, и сохраняется в проекте. В подсказке кнопки указана карта-источник, число точек остаётся только в диагностическом логе. Слой следует за опорой, скрывается в режиме персонажа, не мешает выбирать предметы и не экспортируется. Он служит ориентиром при размещении Proxy; создание и редактирование штатных точек остаётся в официальном инструменте.

Основной источник — XML установленной игры, прочитанный и проверенный при первом использовании карты за сеанс. В новом сеансе файл читается заново. Если он недоступен или повреждён, используется встроенный снимок; это указано в подсказке и предупреждении. Исправный игровой XML не дополняется старыми точками из резерва. Изменения конкретной серверной миссии и сторонних карт автоматически не подгружаются. Проверку фактического спавна выполняйте в целевой миссии.
