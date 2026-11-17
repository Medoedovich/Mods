# Projects — 0.4.0-alpha

Save and open placement projects through **Save project** and **Open project** on the toolbar. Available in 0.4.0-alpha.

## Save and open

1. Click **Save project**, enter a name without `.json`, then save. Selecting a name from the list fills the name field. Saving an existing name requires a second confirmation.
2. Click **Open project**, select a saved name and open it. Replacing an existing scene requires confirmation. **Cancel** or Escape leaves the scene unchanged.
3. Continue editing and exporting CE XML after opening. Undo/Redo starts with an empty history for the newly opened project.

Files are stored in **`$profile:ProxyPlacement/Projects/<name>.json`**. The previous contents of an overwritten file remain in `<name>.json.bak`. Files can be copied between editor profiles; opening requires the same world and available object classes. The normal editor launcher uses its persistent profile. The development validation launcher carries project files forward when it creates a new test profile.

## Stored state

Format version 1 records the world name, the single anchor's class and position, each placed item's class, world position and orientation, character position, camera position/orientation and camera speed multiplier. Duplicate item classes remain separate entries. Empty scenes can also be saved and opened.

The optional `LootMap` field retains the source map for the [standard loot overlay](LOOT-VOLUMES.md). Older version-1 files without it use automatic selection. Reference shapes are never serialized as scene objects.

Character inventory and equipment remain unchanged when opening. Gameplay state such as item cargo, attachments and damage is outside the placement data. Existing XML exports remain on disk. Undo/Redo history stays in the current session and is cleared when another project is opened.

Opening validates the format version, world, numeric ranges and class availability. All new native entities are created and checked before the old scene is removed. A failure leaves the existing scene intact. Loaded items remain frozen until selected for normal editing or released by character mode, preserving their restored placement before inspection.

Missing-file, read, JSON parsing and write failures use localized editor messages. Native file and serializer diagnostics remain in the RPT log.

## Validation

On 2026-11-16 the Russian unpacked mission passed **344 native checks**, including **21 project checks**. These cover JSON persistence, duplicate classes, overwrite backups, filename validation, confirmation and cancellation, unsupported versions, world/class mismatches, malformed JSON, failed candidate creation, restored poses, camera/character state, equipment preservation, export, Gizmo editing and empty scenes. Localization regressions verify missing-file messages, localized error notifications and JSON parser diagnostics being kept out of user-facing text.

Run `ProxyPlacementTool/release/Test-WorldViewport.ps1 -Projects -Language Russian` in the development workspace. The successful client is left open for author review. English validation is deferred until the next Workshop release.

Author check:

1. Move and rotate a wheel, save under a new name, then move it elsewhere.
2. Open the saved project, confirm scene replacement and check the wheel's position and angle.
3. Save the same name again and check the overwrite confirmation. Try selecting a saved name from the list and cancelling the dialog.
4. After a restart with the same profile, open the project again and verify placement and character interactions.
