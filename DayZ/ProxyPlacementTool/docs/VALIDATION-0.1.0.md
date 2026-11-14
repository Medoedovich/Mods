# Alpha 0.1.0 validation

Historical record for the original release. Paths and source/distribution statements below describe the project at that publication; the current source and staged package are covered by [the current validation report](VALIDATION.md).

Published on **2026-11-13** by **Medoedovich**. Runtime: **DayZDiag 1.30.164289.70**, offline Test Range workflow.

Workshop: [Proxy Placement Tool — Alpha](https://steamcommunity.com/sharedfiles/filedetails/?id=3839146464), **Public**. Required item: [Test Range](https://steamcommunity.com/sharedfiles/filedetails/?id=3826868718). The public item page was opened in a signed-out browser; its description, subscription button and required item were visible.

## Tested package

- Built with official Addon Builder; BankRev verified the `iot\proxytool` prefix and eight entries: config, native stringtable, Mission script and five GUI layouts.
- Installed copies in paths containing spaces ran without file patching or access to the original development mission.
- English and Russian profiles passed **51 editor checks per language**. All **64 localization keys** resolved in the correct language, including formatted status messages.
- The downloaded Workshop installation passed **51 checks** in Russian, automatically discovered DayZDiag and the installed Test Range, and produced independent XML exports for a garage (two proxies) and a wreck (one proxy).
- All **17 delivered files** matched the validated package by SHA256. Steam Publisher added its own service metadata separately.
- The tested runs had **0 editor compilation errors, 0 VM exceptions and 0 unsupported GUI keyword messages**. These counts do not claim that every base-game or terrain log is empty.

Published PBO: `dist/@ProxyPlacementTool/addons/iot_proxy_tool.pbo`, **126898 bytes**.

```text
SHA256 7180A4E91B6B23D580E384F452497E47BEEBEDD4D24966070C6B1002F951280F
```

`dist/@ProxyPlacementTool/release-manifest.json` records the hashes of the delivered files. The addon source under `src/iot/proxytool` is the source used for this published PBO. A rebuild may have a different PBO byte hash because of packing metadata; compare source content and perform runtime checks before updating Workshop.

## Scope

The editor checks cover selection, anchor/item catalogs, transforms, precise input, native Gizmo integration, camera multiplier, UI modes, localization and XML export. Earlier loose-mission experiments verified CE placement, including a tilted canister and items at a wreck. **CE spawning was not repeated after packaging**: the packaged regression suite checks the editor and exported data, not the target economy's item availability or spawning behavior.

Retail DayZ, dedicated servers, multiplayer, arbitrary third-party classes and rotated/scaled anchors were not validated. Project save/load, delete UI and undo/redo are deferred. XML must be integrated and tested with the target mission's CE configuration, including `types.xml`.

The cover is an AI-generated illustration, not a game screenshot. Raw logs, runtime storage, local paths, old prototypes and backups are excluded from this publication.

## GitHub publication checks

The standalone repository build script was exercised with Windows PowerShell 5.1 in preparation mode and with PowerShell 7 for a complete official Addon Builder/BankRev build. All eight addon source files match the source of the published alpha. The checked-in distribution retains the original tested PBO and all 17 manifest-verified files; the check build is kept outside the publication. Its launcher passed `-CheckOnly` with automatic discovery of DayZDiag and the Workshop Test Range.

