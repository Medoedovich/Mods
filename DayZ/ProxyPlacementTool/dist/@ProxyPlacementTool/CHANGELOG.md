# 0.4.0-alpha release candidate

- Restore 3D models in catalog hover previews with the blurred backdrop enabled.
- Scroll two rows per mouse-wheel step in both catalog tabs while preserving the selected entry.
- Add a Camera controls button to the View toolbar. Click it to keep a quick reference for flight, movement, height and speed controls open in the editor.
- Add a Place on surface button to the Editing toolbar. Lay the selected item flat on the ground or floor directly beneath it, keeping X/Z and using model bounds for height. Undo and Redo restore the position and orientation together.
- Draw toolbar hints above the editor background and previews. Highlight the standard loot icon only while its overlay is enabled. Hide the editor while the game's Esc menu is open and restore the current selection on return.
- Restyle the editor with translucent panels, white text, subtle dividers and warm active accents. The bundled blurred landscape fills the margins and follows the editing rectangle as the layout changes. F4 restores the full character view. See [editor theme](docs/EDITOR-THEME.md).
- Load standard loot points directly from the installed game's mapgroupproto.xml for the selected map, validate and cache each dataset for the editor session, and show the installed game version in source details. Use the bundled snapshot only when game XML is unavailable or invalid, with an explicit source label and warning. Valid prototypes remain authoritative for removed groups and zero-point groups.
- Show only the source map in the standard loot tooltip details; retain point counts in the diagnostic log.
- Fix the Redo icon curve so it mirrors Undo horizontally and joins its arrowhead consistently.
- Show localized category headings centered above toolbar icon groups. Size groups to fit their headings and wrap labels with their icons; hide the Editing heading together with its controls. Tooltips retain only action names, shortcuts and relevant details.
- When adding or confirming replacement of a building/wreck, place the existing test character on the camera side, five metres outside the model bounds, standing on terrain and facing the model center. Preserve equipment. Item creation, cancelled/failed replacements, manual anchor movement and project loading retain their existing character-placement behavior.
- Add a read-only standard loot overlay: toggle point centers and translucent `range`/`height` volumes for the anchor, using bundled official prototypes from all four maps. Preserve the catalog source map in projects; keep differing map definitions separate, mark unspecified dimensions in amber, and exclude reference shapes from selection and Proxy export. See [standard loot reference](docs/LOOT-VOLUMES.md).
- Unify errors, success messages and warnings in a colored notification widget. Report project save/open and XML export results there, remove permanent sidebar hints/result footers, and expand Scene Objects to up to 10 visible rows while preserving font size and catalog space. See [notifications and scene list](docs/NOTIFICATIONS.md).
- Fix toolbar hints failing to appear because routine button refreshes reset the hover delay. Preserve hover state until layout changes and add a regression using real elapsed time.
- Replace toolbar text buttons with scalable vector icons grouped into Project, History, Editing, View and Export. Add category separators and delayed localized action/shortcut hints, preserve active mode indicators and wrap complete groups on narrow windows. See [icon toolbar](docs/ICON-TOOLBAR.md).
- Localize missing-file, read, JSON parsing and write errors in project dialogs and notifications. Keep native file/serializer diagnostics in the RPT log.
- Add JSON placement projects with Save/Open toolbar dialogs, a saved-file list and overwrite/scene replacement confirmation. Restore the anchor, item positions/rotations, character position and camera state; preserve inventory and existing XML. Keep the previous save as a backup and validate all candidate entities before replacing the scene. See [projects](docs/PROJECTS.md).
- Add scene-wide Undo/Redo for item transforms, anchor/character movement, numeric edits, fine adjustments and resets. Group complete Gizmo drags and numeric field edits; retain 100 actions. Add toolbar buttons and Ctrl+Z / Ctrl+Y / Ctrl+Shift+Z shortcuts, preserving normal text editing in focused inputs. Creation/deletion and gameplay actions remain outside transform history. See [Undo/Redo](docs/UNDO-REDO.md).
- Bind camera height directly to Q (up) and Z (down) while RMB is held. Movement follows the world vertical and does not depend on Bulldozer input bindings; holding both keys cancels vertical motion.
- Replace the F1 camera toggle with RMB hold inside the world editing area. Release restores the cursor and native Gizmo while preserving selection. Block capture during catalog/world dragging and require a fresh press after menu, focus, viewport or character-mode interruption. Remove the Fly/Cursor toolbar button. See [camera controls](docs/CAMERA-CONTROLS.md).

# 0.3.0-alpha — 2026-11-16

Published manually by the author. All 17 downloaded Workshop files match the package tested in Russian and English.

- Add a framed world editing area between the panels. Restrict world selection, Gizmo gestures and entering camera flight to this area; cancel a drag on boundary exit and preserve selection when using panels.
- Create items, buildings and wrecks by dragging catalog rows onto surfaces in the editing area. Normal clicks, folders and invalid drops do not create entities. Remove the creation buttons.
- Keep one building/wreck anchor. Replacing it requires Replace / Cancel confirmation. Validate the new object before deleting the old layout; preserve the character, inventory and exported XML. Keep the drop X/Z and use increasing scene IDs to avoid reusing prior export filenames.
- Show native 3D item previews beside hovered catalog rows. Display the full classname below its heading; keep a visible gap from the sidebar and release temporary models when leaving, dragging or changing modes.
- Display localized item names and search by either name or classname, accepting partial text and ignoring letter case and surrounding spaces. Preserve separate classes with shared names. Keep Objects search by classname.
- Replace bottom cards with a compact flat Scene Objects list below the catalog. Show the character, anchor and items without IDs or an element counter; select exact item instances and enlarge scene-entry text.
- Move the selected anchor or character using the native Gizmo or world position fields. Anchor movement leaves items in place. Rotation remains available for items only.
- Add a toolbar for Move/Rotate, Fly/Cursor, anchor focus, character mode and item/full-anchor XML export. Highlight the active Gizmo mode and wrap actions on narrow windows.
- Rework Object Properties with mode-specific Position or Roll/Pitch/Yaw rows, colored axis labels, larger inputs, five decimal places, immediate valid edits and individual reset icons. Keep optional fine controls collapsible; F9 resets the full selection baseline.
- Extend the catalog above Scene Objects, add a search icon and placeholder, scroll one row per wheel step, and remove duplicate counters, class fields, creation notices and keyboard hints. Wrap remaining movement/rotation help.
- Display validation, creation and export errors in a separate dismissible notification, preserving selection and blocking world clicks through the notice.
- Allow a packaged self-test to retain its successful client with the developer launcher switch KeepOpenAfterTest.

Interface design inspired by the World Editor in Arma Reforger.

Alpha limits remain: no project save/load, Undo/Redo or delete UI; anchors use zero rotation and scale one. The native Gizmo may draw outside the world frame, while input remains restricted. Exported CE settings still require integration and testing in the target mission.

# 0.2.0-alpha — 2026-11-14

- Browse Items in a category/subcategory tree with global classname search, independent expansion state and no 100-result cap. Includes weapons, ammunition, attachments, clothing, food/drinks, equipment, vehicle parts and Other fallbacks; all labels support Russian and English.

- Split Residential into model-family subcategories including Sheds, Office, Misc, House, City, Stores, Medical and Other; nested search, counts and StaticObj filtering include them.

- Group ground-vehicle wrecks into Truck, Sedan, Offroad, Hatchback and Other ground vehicles; nested search and counters retain all objects.

- Split Wrecks into Ground vehicles, Aircraft, Ships and boats, Rail vehicles and Other wrecks; search, counters and StaticObj filtering include the nested level.

- Hide StaticObj classes by default; an Objects-tab checkbox restores them and refreshes search, categories and counters.

- Browse all loaded objects in an expandable map/category tree without Common; search reveals matching paths and preserves normal expansion state. Categories follow model paths, with resource-family and Other/Uncategorized fallbacks.

- Hide the character HUD in editor mode and restore its previous visibility in character mode.
- Equip the test character with a grey T-shirt, cargo trousers and black hiking boots.

# 0.1.0-alpha

First alpha release by Medoedovich.

- Offline authoring on Test Range using DayZDiag.
- Runtime building, wreck and inventory-item catalogs with classname search.
- Native movement/rotation Gizmo and precise position/angle fields.
- Bottom item list with paging and selection across anchors.
- Tool-controlled camera flight and speed multiplier indicator.
- Character mode to inspect take actions and nearby inventory.
- Separate CE `group/dispatch` XML exports for each anchor instance.
- Portable launcher; packaged editor scripts and layouts.

- Automatic Russian/English menus, hints, item-card labels and status messages; other client languages use English.

Known alpha limits: no project saving/loading, no undo/redo or delete UI, unrotated scale-one anchors only, no multiplayer or retail-client support. The editor preview is scripted; XML must be integrated with the target mission's CE configuration.
