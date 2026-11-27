# Proxy Placement Tool

[Steam Workshop](https://steamcommunity.com/sharedfiles/filedetails/?id=3839146464) · [Русский](README-RU.md) · [Build from source](docs/BUILD.md) · [Validation](docs/VALIDATION.md) · [Publication rules](PUBLICATION.md)

By **Medoedovich** · **1.0.0** · **DayZDiag offline only**

![Editor overview with loot volumes, rotation controls and item hover preview](docs/screenshots/0.4.0-alpha/workshop/01-editor-overview.jpg)

An offline authoring tool for placing items relative to buildings and wrecks, then exporting CE `dispatch` XML. Select an item, use the native Gizmo or enter exact coordinates and angles, inspect its take action and nearby inventory in character mode, and export the result.

Use **Save project** to keep an editable scene and **Open project** to resume it after starting the editor. Export CE XML separately for the target mission.

**1.0.0 was published manually by the author on 25 November 2026.** All 17 downloaded Workshop files match the tested package by SHA-256. The package includes Specific/Industrial subgroups and City/House families and passed 658 native checks in each of Russian and English, resolving 410 localization keys. See the [release record](docs/VALIDATION-1.0.0.md) and [new illustrated cover](workshop/1.0.0/preview-1.0.0-v2.jpg).

[Editor features](FEATURES.md) · [Placement examples](examples/README.md)

## Start

Requirements: Windows, DayZ, Steam running, DayZ Tools and a matching `DayZDiag_x64.exe` prepared in the game directory. The tool supports offline DayZDiag editing; the ordinary DayZ client, servers and multiplayer are unsupported.

1. Subscribe to [Proxy Placement Tool](https://steamcommunity.com/sharedfiles/filedetails/?id=3839146464) and [Test Range](https://steamcommunity.com/sharedfiles/filedetails/?id=3826868718), and wait for both downloads.
2. Close any running DayZ client.
3. Open `steamapps/workshop/content/221100/3839146464` in the Steam library and run **Start-Editor.cmd**. The launcher automatically finds DayZDiag and the installed Test Range.

The tested **1.0.0** build is included in [`dist/@ProxyPlacementTool`](dist/@ProxyPlacementTool/); all 17 files match the verified Workshop download. Run **Start-Editor.cmd** after installing Test Range. Keep the launcher, PBO and `Missions` directory together. Enabling the mod in the regular DayZ Launcher alone does not open the editor.

`Start-Editor.cmd -CheckOnly` checks installation paths without writing files or starting the game. The launcher also accepts `-Game`, `-TestRange`, `-ExtraMods` and `-RuntimeRoot`; see the [current English instructions](package/README.en.md).

## Placement workflow

1. **Add an anchor.** Choose a map and building/wreck in Objects, then drag it into the scene.
2. **Show standard loot points.** Enable the cylinder icon in View. Account for the displayed volumes when choosing places for new proxies. This is a reference overlay; it does not spawn items at standard points.
3. **Place items and check access.** Drag items from the catalog and adjust their positions and rotations. Use **F4 / Character** to inspect the placement against the checks below, then return to the editor.
4. **Save the project and export XML.** The project keeps the scene editable. **Anchor XML** exports the placed items for CE integration; saving a project and exporting XML are separate actions.
5. **Integrate the export into the target mission.** Merge `dispatch` into the appropriate `mapgroupproto.xml` group, preserving standard containers and other settings you need. Check the economy configuration, including `types.xml`. See [Export and scope](#export-and-scope) for paths and limitations.
6. **Verify actual spawning.** Run the mission with CE and compare the spawned items' positions, rotations and accessibility with the editor. A separate DayZDiag offline mission with the relevant XML is sufficient for a control test. The economy must create the tested loot: **F4 in the editor checks the scripted preview and does not verify CE spawning**.

An initial control run confirms the export works with the chosen mission configuration. Repeat the check particularly for a new item classname, a steep angle, a tight shelf or placement inside a wreck.

### Placement checks

- **Position and rotation:** after CE creates the item, it occupies the intended place and retains the chosen orientation.
- **Intersections:** there is no unwanted clipping into walls, floors, furniture or other items. Account for standard loot volumes and possible nearby ordinary loot.
- **Take action:** approaching the item offers the action and allows the item to be picked up in its usual way.
- **Vicinity:** the item appears in the open inventory's Vicinity panel when the character is nearby.

The editor checks preview geometry and accessibility. After integrating the XML, apply the same checks to items created by CE in the target mission.

## Work

- In **Objects**, open a map/category or search by classname. Drag an actual building/wreck row onto a surface inside the world frame. The editor creates and frames the anchor; a normal click only selects a catalog entry.
- The scene has **one anchor**. Dropping another opens **Replace / Cancel**; Escape cancels. Confirming removes the old anchor and its placed world items after validating the replacement. The character, inventory and existing XML exports remain. Export any layout you need before replacing it.
- **Show StaticObj** is off by default. Residential buildings and wrecks have further subcategories; both catalog trees preserve folder expansion.
- Open **Items**, search by the localized name or classname, then drag an item onto a surface in the world frame. Hover over a row for its 3D preview and full classname. Repeated drops create separate instances without a quantity limit. Drops outside the frame or over the sky cancel creation.
- Select an item by clicking its model or its row in **Scene Objects**, below the catalog. Click empty world space to deselect. **F7 / Move** shows translation arrows; **F8 / Rotate** shows rotation rings. A drag stops when it leaves the world area and requires a new press to continue.
- **Object Properties** shows Position in Move mode and Roll/Pitch/Yaw in Rotate mode. Valid numeric edits apply immediately. Each reset icon restores one component to its value at selection time; **F9** restores the full selection. Expand **Fine adjustments** for step controls.
- Select the character or anchor in Scene Objects to move that entity with the native Gizmo or world position fields. Moving the anchor leaves items in place. Item coordinates are relative to the anchor; character and anchor positions are world coordinates. Only items can rotate.
- Hold **RMB** over the scene to fly and release it to return to the cursor. WASD moves, Q rises and Z descends. The mouse wheel changes the 0.1–16× speed multiplier shown briefly below the crosshair. The camera icon in **View** lists all flight controls.
- **Place on surface** lays the selected item flat on the ground or floor below it while preserving X and Z. Use **Undo** and **Redo**, or **Ctrl+Z / Ctrl+Y**, to restore transforms and item creation/deletion.
- Use the **standard loot overlay** to see existing spawn points and their volumes. The editor reads the installed game's `mapgroupproto.xml` and labels a bundled fallback when needed.
- **F4 / Character** switches to the dressed test character for take-action and nearby-inventory checks. Close inventory and press F4 to return. Character HUD is hidden while editing.
- The toolbar also focuses the anchor and exports XML. **Item XML / F10** exports the selected item and the full anchor; **Anchor XML** exports all associated ground items. **F11** toggles diagnostics. Errors appear in a separate dismissible notification.

Search accepts partial queries, ignores letter case and surrounding spaces, and reveals matching branches without a 100-result cap. Objects uses classnames; Items accepts both client-localized names and classnames. Distinct classes with the same displayed name remain separate rows. Catalogs use loaded configurations, including additional mods; individual third-party classes may need separate testing.

Interface design inspired by the World Editor in Arma Reforger.

## Export and scope

Default output: `%LOCALAPPDATA%\ProxyPlacementTool\profiles\ProxyPlacement\<anchor classname>\<UTC session>_scene_<number>.xml`.

Merge the exported `dispatch` into the appropriate group in the target mission's `mapgroupproto.xml`. Preserve standard containers that you still need, configure the target economy, including `types.xml`, and test the result in CE. The editor preview creates items by script; the target economy performs the final loot spawning. An export does not deploy settings to a server.

Per-instance export files help authoring; a prototype keyed by one building classname generally affects all instances of that class. Do not blindly add duplicate groups with the same name. Items held or stored in inventory are omitted until placed on the ground.

Saved JSON projects are under `%LOCALAPPDATA%\ProxyPlacementTool\profiles\ProxyPlacement\Projects`. They store the anchor, item positions and rotations, character position and camera state. See [project files](docs/PROJECTS.md).

Anchors use zero orientation and scale 1. Placement was calibrated for CE groups with `rpy="0 0 0" a="90"`. Undo and Redo cover transforms and item creation/deletion. The editor runs offline in DayZDiag on Test Range.

## Screenshots

Item placement and rotation relative to an anchor:

![Angled item placement](docs/screenshots/0.4.0-alpha/workshop/02-angled-placement.jpg)

[Original PNG screenshots and JPEG copies](docs/screenshots/0.4.0-alpha/README.md). The [0.3.0-alpha gallery](docs/screenshots/0.3.0-alpha/README.md) includes character-mode inspection.

## Source and build

| Path | Purpose |
| --- | --- |
| `src/iot/proxytool` | Scripts, configuration, stringtable, map catalog and UI layouts. |
| `package` | Portable launcher, mod information, instructions and bootstrap mission template. |
| `dist/@ProxyPlacementTool` | Published 1.0.0 package; all 17 files match the verified Workshop download. |
| `tools/Build.ps1` | Build a new isolated package with official Addon Builder and check it with BankRev. |
| `docs` | Build instructions, validation results and published PBO hash. |
| `workshop` | Published description snapshots, item metadata, the next description draft and generated cover illustration. |

See [build instructions](docs/BUILD.md). The addon prefix remains `iot\proxytool`; the `IOT_` identifiers are retained for compatibility with the published build. Source changes must be packed into a new PBO to take effect. The packaged mission contains only the bootstrap; editor logic and UI resources are loaded from the PBO without file patching.

The cover is a generated illustration, not an in-game screenshot. DayZ game files, DayZDiag and Test Range are not bundled with this project; Test Range is a [separate project](https://steamcommunity.com/sharedfiles/filedetails/?id=3826868718) and Workshop dependency.

## Validation and reports

The **1.0.0** package passed **658 checks per language**, resolved **410 localization keys**, and produced six validated XML exports per run. All **17 package files** match both tested installations, the archive, the downloaded Workshop copy and the bundled distribution. The downloaded copy was compared by hashes rather than repeating the runtime suites. See [1.0.0 validation](docs/VALIDATION-1.0.0.md).

The **0.4.0-alpha** release package passed **395 checks per language**, resolved **255 native localization keys**, and validated **17 delivered files** in separate Russian and English PBO installations. SHA-256 comparison confirmed that all 17 downloaded Workshop files match that tested package. See [release validation](docs/VALIDATION-0.4.0.md).

Published version **0.2.0-alpha** passed **136 checks per language** in Russian and English, both in separate local installations and in the downloaded Workshop copy. All **167 localization keys** resolved, and all **17 delivered files** matched the prepared package. See [validation details](docs/VALIDATION.md).

For bugs, include the DayZDiag version, anchor/item classnames, reproduction steps, relevant RPT/script log lines and exported XML. Use [GitHub issues](https://github.com/Medoedovich/Mods/issues), the [DayZ Modders discussion](https://discord.com/channels/452035973786632194/1575067129089228870/1575067129089228870) or [Workshop comments](https://steamcommunity.com/sharedfiles/filedetails/?id=3839146464). Discord: **medoedovich**.

