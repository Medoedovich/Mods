# Unreleased

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
