# Unsaved projects — development version

The **Project** toolbar heading shows an asterisk when the scene differs from its saved state. Comparison covers the anchor, ordered ground-item placements, source loot map and character position. Undo, Redo and item restoration are compared with the same baseline. A successful save or project open establishes a new baseline.

Project files also retain the camera position, orientation and speed. These navigation settings are captured during saving. The unsaved marker follows scene contents.

Before opening another project, confirming an anchor replacement or leaving through the in-game Esc menu, the editor offers three choices.

- **Save** opens the existing project save dialog. The requested action continues after saving succeeds. Existing files retain their overwrite confirmation and backup behavior.
- **Don't save** continues with the requested action.
- **Cancel**, Escape or cancelling the save dialog returns to the current scene and cancels the pending action.

Invalid names and failed writes keep the current scene and pending action available. The dialog blocks editing, history replay and item deletion. Anchor replacement checks that the original anchor still exists before committing.

The exit guard handles the mission-abort path used by the in-game menu. Closing the operating-system window or forcibly terminating DayZ bypasses this script-level dialog.

## Validation

On 18 November 2026 the Russian loose mission passed **425 native checks**, including **13 unsaved-project checks**, with all **260 localization keys** available. Coverage includes changes followed by Undo and Redo, return to saved contents after deletion, camera navigation, modal input guards, cancellation, failed save validation, save-before-open, discard-before-open and pending anchor replacement. Exit protection is tested through its request handler with cancellation.

The successful client remains open for author review. Check the Project asterisk after moving an item and after Undo. Try opening another project or replacing the anchor, exercise all three choices, and check that cancelling Save As preserves the scene. Check the exit prompt through Esc. English runtime verification is scheduled for the next Workshop release.
