# Notifications and scene list — 0.4.0-alpha

Version 0.4.0-alpha shows action results in a notification widget. Action names and hotkeys appear in toolbar hover hints. The instructions document keyboard controls.

## Notifications

One independent widget at the bottom of the world editing area displays the latest message:

| Type | Accent | Dismissal |
| --- | --- | --- |
| Success | Green | After 4 seconds or with × |
| Warning | Amber | After 6 seconds or with × |
| Error | Red | With ×, a corrective action or a subsequent message; no automatic timeout |

Project save/open and item/full-anchor XML export report success here. Cancelled placement and picked-up items use warnings. Numeric, creation, project and XML failures use errors. Ordinary selection and live numeric editing do not create success notifications. A routine valid edit clears an error while preserving an active success message.

Closing a notification preserves scene selection and placement. Its visible bounds block world clicks, and character mode hides it. The previous catalog footer no longer repeats export results, and the properties footer no longer repeats Gizmo instructions.

## Scene Objects

The scene list grows to **10 visible rows** when enough height is available. Shorter windows show fewer rows while retaining the existing font size and space for the catalog. The list remains below the catalog with the same width and lower screen margin. Selection, creation order, character/anchor entries and scrolling are unchanged.

## Validation

On 2026-11-17 the Russian unpacked mission passed **362 native checks**, including **7 notification/scene-height checks**, the existing **4 error checks**, and **23 project checks**. Coverage includes footer removal, distinct message accents, selection preservation, dismissal and timers, input blocking, project/XML success messages and scene-list sizing. English validation remains deferred until the next Workshop release.

Run `ProxyPlacementTool/release/Test-WorldViewport.ps1 -Notifications -Language Russian` in the development workspace. The successful client remains open for author review.

Author check: select an item and inspect the shorter properties panel; export XML and check the green notification; save/open a project; add several items and check the larger Scene Objects list. Cancelling a catalog drop should show an amber warning. Invalid numeric input should show a red error.
