# Undo / Redo — 0.4.0-alpha

Version 0.4.0-alpha includes transform history for the scene.

## Controls

- **Ctrl+Z** or **Undo** on the toolbar: undo the latest completed edit.
- **Ctrl+Y**, **Ctrl+Shift+Z** or **Redo**: restore the last undone edit.
- Shortcuts leave focused text fields to their normal text editing behavior. Click outside the field or use the toolbar to undo a world transform.
- Unavailable actions are disabled on the toolbar. Flight, character mode, replacement confirmation and active catalog/Gizmo drags block history actions.

## Recorded changes

History covers item movement and rotation, anchor and character movement, numeric property edits, fine adjustment buttons, individual component resets, F9 reset, and the fine panel's ground placement action.

A complete Gizmo drag is one action, including when it stops at the viewport boundary or loses application focus. Live typing in a numeric field is grouped until the field is finished, loses focus or another action begins. Incomplete text leaves the last valid pose, which can still be undone. Holding a fine adjustment button is one action.

History is shared across selections. Undo/Redo selects the affected entity and refreshes its properties and native Gizmo. Anchor movement still leaves items in place. Character history restores position without changing orientation.

The most recent **100 completed edits** are retained in memory. A new transform edit after Undo clears the redo branch; unchanged transforms do not add entries. Switching between the editor and character mode preserves history. Entries for removed entities and items currently in inventory are discarded when replaying history, so Undo does not move inventory contents.

Confirming anchor replacement clears history after validating the replacement. Cancelling replacement preserves it. Entity creation, deletion, anchor replacement, inventory actions and ordinary character gameplay are outside transform history. History is not saved across editor restarts.

## Validation

Run `ProxyPlacementTool/release/Test-WorldViewport.ps1 -UndoRedo -Language Russian` from the development workspace. It uses an unpacked mission and leaves the successful client open for author review.

On 2026-11-16 the Russian mission passed **323 native checks**, including **21 Undo/Redo checks**. The suite covers grouped Gizmo and numeric edits, incomplete text, fine adjustment holds, rotation, resets, ground placement, boundary cancellation, selection changes, independent anchor/character movement, mode restrictions, invalid targets, the 100-action bound, and clearing history on confirmed replacement. English validation is deferred until the next Workshop release.

The author confirmed Undo/Redo operation in game on 2026-11-16. Manual review checklist:

1. Drag the wheel through several positions, release it and press Ctrl+Z: the entire drag should be undone. Ctrl+Y should restore it. Repeat with rotation and the toolbar buttons.
2. Type a coordinate, finish the field and click Undo. The complete field edit should be undone. Ctrl+Z while typing should retain normal text editing behavior.
3. Move one item, select another and undo: the affected item should become selected. Move the anchor and undo: the items should stay in place.
4. Undo a move, then make a different move: Redo should become unavailable.
