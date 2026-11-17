# Editor theme — 0.4.0-alpha

The editor uses translucent blue-gray panels over a blurred landscape. White text, subtle separators and warm active accents distinguish controls. Hover previews and dialogs use denser surfaces so their contents remain readable over the scene. Axis and notification colors retain their meaning.

The catalog scrollbar has a slim neutral thumb. Its pointer-transparent visual layer follows the original ScrollWidget; native scrolling and scrollbar input remain in charge. The StaticObj checkbox also retains native state/input, with a simple drawn outline and check mark.

## World editing area

The bundled landscape is clipped into four strips around the active world rectangle. Each strip resizes with its margin. The center shows the live world and uses the engine's normal camera projection and screen rays. A charcoal matte fills the margins if the texture cannot load and covers the entire world when the layout has no usable rectangle.

The background ignores pointer input and sits below the interactive panels and their tooltips. F4 and the game's pause menu hide it with the rest of the editor. Returning to the editor restores it.

The styles have tool-specific names (`IOT_*`) and are loaded before creating editor widgets. The stylesheet, mask layout and landscape texture are included in loose missions and the addon.

## Validation

On 17 November 2026 the Russian unpacked DayZDiag mission passed **19 native integration checks**. They verify scoped style loading, opaque pointer-transparent masks and exact screen coverage, panel movement/resizing, unusable-layout recovery, the StaticObj checkbox, item search, native scrollbar tracking and character/editor transitions without scene loss. Scrollbar checks wait for the next native layout pass. English runtime validation is deferred until Workshop release.

The packaged release candidate checks loading, layer order, exact coverage and recovery after viewport and character-mode transitions. See [validation for 0.4.0-alpha](VALIDATION-0.4.0.md).

Development command: `ProxyPlacementTool/release/Test-EditorTheme.ps1`. Machine-readable result: [editor-theme-validation.json](editor-theme-validation.json).

Author review:

1. Inspect Objects, Items, Scene Objects and Object Properties: text should remain readable; rows, fields and scrollbars should use neutral backgrounds.
2. Hover over an item and toolbar icons, then open Save/Open and a replacement dialog. Compare the popup surfaces and dividers with the panels.
3. Move the camera and change the window size: world scenery should remain visible only inside the active rectangle, with no exposed strips around it.
4. Try Gizmo movement/rotation, catalog dragging and the scrollbar. Press F4 and return: character mode should have no opaque editor masks.

## Русский

Под полупрозрачными панелями отображается размытый пейзаж. Четыре полосы фона повторяют границы рабочей области при изменении размеров. F4 и меню Esc убирают фон вместе с панелями редактора.

19 технических проверок пройдены. Внешний вид, работу мышью и отображение штатного Gizmo у границы проверяет автор. Английская версия проверяется перед релизом в Workshop.
