# 0.3.0-alpha — Release candidate, 2026-11-16

Prepared locally; Workshop publication is pending author action.

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
