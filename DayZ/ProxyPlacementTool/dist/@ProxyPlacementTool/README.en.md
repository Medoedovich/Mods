# Proxy Placement Tool — Alpha

By **Medoedovich**, version **0.2.0-alpha**.

An offline authoring tool for positioning items relative to buildings and wrecks, then exporting CE `dispatch` XML. **DayZDiag only.** Tested with DayZDiag **1.30.164289.70**.

**Alpha: projects cannot be saved or reopened yet. Export the XML you need before exiting. Each launch starts an empty scene; exported XML files remain available.**

## Start

1. Install DayZ and DayZ Tools; prepare a matching `DayZDiag_x64.exe` in the game installation directory. Start Steam.
2. Subscribe to this tool and [Test Range](https://steamcommunity.com/sharedfiles/filedetails/?id=3826868718), then wait for both downloads.
3. Open the installed tool folder under `steamapps\workshop\content\221100\<this tool's ID>` and run `Start-Editor.cmd`.
4. Close any existing DayZ client first. The launcher discovers Steam libraries, DayZDiag and Test Range automatically.

Explicit paths are supported:

```bat
Start-Editor.cmd -Game "X:\SteamLibrary\steamapps\common\DayZ" -TestRange "X:\SteamLibrary\steamapps\workshop\content\221100\3826868718"
Start-Editor.cmd -ExtraMods "X:\Mods\@One;X:\Mods\@Two"
```

`-CheckOnly` checks paths without writing files or starting the game. `-RuntimeRoot` selects a different data folder. The retail client, dedicated servers and multiplayer are not supported in this alpha. Enabling the mod in the regular DayZ Launcher alone does not open the editor; use the offline launcher above.

## Work

The editor follows the DayZDiag client language: Russian or English. Other client languages use English.

- Left: open **Objects → map → category**, select a classname and create an anchor. Residential buildings and wrecks have further subcategories. The camera frames the created anchor automatically.
- **Show StaticObj** is off by default. Enable it to include StaticObj classes in the object tree and search.
- Switch to **Items → category → subcategory**, select an item and create it beside the active anchor. Categories include weapons, ammunition, attachments, clothing, food/drinks, equipment, vehicle parts and Other.
- Select an item in the world or in the bottom tray. **F7** shows native translation handles; **F8** shows rotation rings. The right panel provides exact coordinates and angles.
- Click empty space to deselect. **F9** restores the item to its pose at selection time.
- **F4** switches to character mode for take-action and nearby-inventory checks. Close inventory and press F4 to return.
- Create additional anchors without restarting. The right anchor selector switches between them; bottom cards select exact item instances across anchors. Use ‹/› for more cards.
- **Export anchor XML** exports all ground items associated with the current anchor. **F10** exports the selected item and the full anchor together.

**F1** toggles cursor/flight. Fly with WASD, Q/Z and mouse; the wheel adjusts the 0.1–16 speed multiplier. Shift/Ctrl temporarily accelerate, Alt slows down. **F11** toggles world-coordinate diagnostics.

Search covers the complete loaded catalog, ignores case and surrounding spaces and reveals matching folders. There is no 100-result limit. Folder expansion is preserved when switching tabs; folders do not select a spawn classname. You can also enter an exact classname in the lower field. Catalogs use loaded configs, including additional mods; individual third-party classes may need separate testing.

The character HUD is hidden in editor mode and restored in character mode. The test character starts dressed and wearing boots.

## Export

Default output:

```text
%LOCALAPPDATA%\ProxyPlacementTool\profiles\ProxyPlacement\<anchor classname>\<UTC session>_scene_<number>.xml
```

Exporting the same anchor again within a session updates its file. Other anchors and sessions use separate files. Items held or stored in inventory are omitted until placed on the ground. `selection.xml` and `<item classname>.proxy.xml` additionally contain the most recently exported selection.

Merge the exported `dispatch` into the appropriate group in the target mission's `mapgroupproto.xml`; preserve any standard containers/settings you still need. Final CE spawning also depends on the building instance, registered group positions and economy settings such as `types.xml`. The editor does not install XML on a server. Its preview spawns items by script; the target economy must spawn them from `dispatch`.

Per-instance export files help authoring, but a CE prototype identified by one classname generally affects all instances of that class. Do not blindly add duplicate groups with the same name.

The `profiles` folder contains logs. `sessions` contains temporary bootstrap mission copies, **not saved projects**. The launcher does not write to the Workshop installation folder.

## Alpha limits

- No project save/load, delete UI or undo/redo yet. F9 only resets the current selection.
- Anchors use zero orientation and scale 1. Rotating the anchor itself is unsupported; transforms were calibrated for CE group `rpy="0 0 0" a="90"`.
- Export requires integration and testing in the target CE mission.
- Offline Test Range workflow, Russian/English UI, DayZDiag only; no retail or multiplayer support is claimed.

For bug reports, include the DayZDiag version, anchor/item classnames, reproduction steps, relevant RPT/script log lines and exported XML when applicable.
