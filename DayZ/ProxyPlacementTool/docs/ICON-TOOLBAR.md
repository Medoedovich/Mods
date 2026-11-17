# Icon toolbar — 0.4.0-alpha

Version 0.4.0-alpha uses square vector icons for toolbar actions.

The five categories have localized headings centered above their icons and are separated by vertical lines:

| Category | Actions |
| --- | --- |
| Project | Save project, open project |
| History | Undo, Redo |
| Editing | Move, Rotate, Place on surface |
| View | Focus anchor, character mode, standard loot overlay, camera controls |
| Export | Selected item XML, full anchor XML |

Buttons are 40 base UI pixels square, with icons drawn using the native canvas. Move and Rotate use colored Gizmo axes and rings; the active mode has a warm underline in the [current theme](EDITOR-THEME.md). The Editing category disappears when nothing is selected, including its heading and separator. Existing action availability and hotkeys are preserved. Headings use a separate text row; groups expand to fit longer localized labels and keep their icons centered beneath the title.

With an item selected, the down-arrow icon lays its broad face flat on the ground or floor below it. It keeps the item's world X and Z and adjusts height using the model bounds. Undo and Redo restore the placement and rotation together.

Click the camera icon to open a quick reference for flight controls. Click it again to close the reference. It also closes when you return to editing the scene or start flying.

Hovering for 350 ms shows the localized action name and existing shortcut. Category names appear only on the toolbar. Hints also identify disabled actions and retain relevant details such as the standard loot source map. They disappear on pointer departure, clicking, flight, character mode, menus or modal dialogs. Visible hints block world input through their bounds.

Routine button-state refreshes preserve the hover timer and visible hint. Layout and icon drawing only repeat when the toolbar width, UI scale or visible actions change.

Categories move to the next row as whole groups, including their headings, when space is limited. Separators are hidden at the start of a row, and the world editing area follows the toolbar height.

## Validation

On 2026-11-17 the Russian unpacked mission passed **383 native checks** after adding persistent headings. The toolbar checks verify that localized labels fit above and align with their icon groups, that hidden Editing controls leave neither a heading nor a separator, and that wrapped groups retain their labels. Tooltips are checked for action/shortcut text without a repeated category. Real hover timing, unchanged-layout caching and the full editor regressions also passed. The same successful client was retained for author review; no PBO was built. Current development report: `ProxyPlacementTool/release/ICON-TOOLBAR-VALIDATION-Russian.json`.

On 2026-11-16 the Russian unpacked mission passed **353 native checks**, including **9 icon toolbar checks**. They cover canvas buttons and pointer flags, square dimensions, category separators, hidden editing actions, narrow layouts, localized shortcut hints, bounds, selection preservation and disabled-action hints. A timed regression waits 500 ms while refreshing layout every 50 ms, checking that the hint appears without forcing it and remains visible after another refresh. Existing project, history and Gizmo regressions also passed. English validation is deferred until the next Workshop release.

Run `ProxyPlacementTool/release/Test-WorldViewport.ps1 -IconToolbar -Language Russian` in the development workspace. The successful client remains open for author review.

The author confirmed that hints appear during normal mouse hover after the timer fix on 2026-11-16.

Author check: inspect the headings, icon shapes and separators, hover over the action icons, try Move/Rotate and Undo/Redo, and open a project dialog. Check that headings are centered and readable, that tooltips do not repeat them, and that whole groups wrap together when the window is narrowed.
