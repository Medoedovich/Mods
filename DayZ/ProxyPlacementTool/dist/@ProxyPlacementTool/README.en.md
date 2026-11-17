# Proxy Placement Tool — Alpha

By **Medoedovich**, version **0.4.0-alpha**.

An offline authoring tool for positioning items relative to buildings and wrecks, then exporting CE `dispatch` XML. **DayZDiag only.** Tested with DayZDiag **1.30.164289.70**.

Use **Save project** to keep an editable scene and **Open project** to resume it after starting the editor. Export the CE XML separately for the target mission.

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

- In **Objects**, open a map/category or search by classname. Drag an actual building/wreck row onto a surface inside the world frame. The editor creates and frames the anchor; a normal click only selects a catalog entry.
- The scene has **one anchor**. Dropping another opens **Replace / Cancel**; Escape cancels. Confirming removes the old anchor and its placed world items after validating the replacement. The character, inventory and existing XML exports remain. Export any layout you need before replacing it.
- **Show StaticObj** is off by default. Residential buildings and wrecks have further subcategories; both catalog trees preserve folder expansion.
- Open **Items**, search by the localized name or classname, then drag an item onto a surface in the world frame. Hover over a row for its 3D preview and full classname. Repeated drops create separate instances without a quantity limit. Drops outside the frame or over the sky cancel creation.
- Select an item by clicking its model or its row in **Scene Objects**, below the catalog. Click empty world space to deselect. **F7 / Move** shows translation arrows; **F8 / Rotate** shows rotation rings. A drag stops when it leaves the world area and requires a new press to continue.
- **Object Properties** shows Position in Move mode and Roll/Pitch/Yaw in Rotate mode. Valid numeric edits apply immediately. Each reset icon restores one component to its value at selection time; **F9** restores the full selection. Expand **Fine adjustments** for step controls.
- Select the character or anchor in Scene Objects to move that entity with the native Gizmo or world position fields. Moving the anchor leaves items in place. Item coordinates are relative to the anchor; character and anchor positions are world coordinates. Only items can rotate.
- Hold **RMB** over the scene to fly and release it to return to the cursor. WASD moves, Q rises and Z descends. The mouse wheel changes the 0.1–16× speed multiplier shown briefly below the crosshair. The camera icon in **View** lists all flight controls.
- **Place on surface** lays the selected item flat on the ground or floor below it while preserving X and Z. Use **Undo** and **Redo** to restore or repeat completed transform edits.
- Use the **standard loot overlay** to see existing spawn volumes and avoid placing proxies in the same space.
- **F4 / Character** switches to the dressed test character for take-action and nearby-inventory checks. Close inventory and press F4 to return. Character HUD is hidden while editing.
- The toolbar also focuses the anchor and exports XML. **Item XML / F10** exports the selected item and the full anchor; **Anchor XML** exports all associated ground items. **F11** toggles diagnostics. Errors appear in a separate dismissible notification.

Search accepts partial queries, ignores letter case and surrounding spaces, and reveals matching branches without a 100-result cap. Objects uses classnames; Items accepts both client-localized names and classnames. Distinct classes with the same displayed name remain separate rows. Catalogs use loaded configurations, including additional mods; individual third-party classes may need separate testing.

Interface design inspired by the World Editor in Arma Reforger.

## Export

Default output:

```text
%LOCALAPPDATA%\ProxyPlacementTool\profiles\ProxyPlacement\<anchor classname>\<UTC session>_scene_<number>.xml
```

Exporting the same anchor again within a session updates its file. Other anchors and sessions use separate files. Items held or stored in inventory are omitted until placed on the ground. `selection.xml` and `<item classname>.proxy.xml` additionally contain the most recently exported selection.

Merge the exported `dispatch` into the appropriate group in the target mission's `mapgroupproto.xml`; preserve any standard containers/settings you still need. Final CE spawning also depends on the building instance, registered group positions and economy settings such as `types.xml`. The editor does not install XML on a server. Its preview spawns items by script; the target economy must spawn them from `dispatch`.

Per-instance export files help authoring, but a CE prototype identified by one classname generally affects all instances of that class. Do not blindly add duplicate groups with the same name.

The `profiles` folder contains logs and saved JSON projects under `ProxyPlacement\Projects`. The `sessions` folder contains startup mission copies.

## Alpha limits

- Undo and Redo cover transforms. Entity creation and removal stay outside the transform history.
- Anchors use zero orientation and scale 1. Rotating the anchor itself is unsupported; transforms were calibrated for CE group `rpy="0 0 0" a="90"`.
- Export requires integration and testing in the target CE mission.
- Offline Test Range workflow, Russian/English UI, DayZDiag only; no retail or multiplayer support is claimed.

For bug reports, include the DayZDiag version, anchor/item classnames, reproduction steps, relevant RPT/script log lines and exported XML when applicable.
