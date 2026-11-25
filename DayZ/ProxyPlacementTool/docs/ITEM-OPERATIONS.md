# Item operations — development version

Select a placed item and click the trash icon in **Editing**, or press **Delete**. The item leaves the world, scene list and the data used by subsequent project saves and XML exports. The command applies to selected ground items. The character and anchor retain their existing movement and replacement controls.

Delete in a text field edits text. Flight, character mode, modal dialogs, inactive application windows and active drag gestures block item deletion.

**Ctrl+Z** or **Undo** reverses creation and deletion as well as transform edits. **Ctrl+Y**, **Ctrl+Shift+Z** or **Redo** repeats them. The restored item is selected with the native Gizmo. History preserves its classname, full transform, anchor ownership and original list positions. Identical classnames remain separate instances in history.

Earlier movement and rotation actions follow the restored item through its shared history identity. A new edit after Undo clears the redo branch. The existing 100-action limit applies to the combined history. Opening a project and confirming anchor replacement clear history.

Creation and deletion history stores placement data, consistent with project files. Gameplay state such as inventory contents, attachments, damage and quantities is outside the saved placement data.

If the classname is unavailable or native recreation fails, the scene and history action are retained for retry. Existing exported files retain their last exported contents until the next export.

## Validation

Run `ProxyPlacementTool/release/Test-WorldViewport.ps1 -UndoRedo -Language Russian` in the development workspace. The loose mission includes regressions for duplicate classnames, deletion guards, text input, failed restoration, original scene order, project membership and the complete creation/move/rotate/delete undo and redo sequence.

On 18 November 2026 the Russian loose mission passed 412 native checks, including 17 item-operation checks and all 256 localization keys. The maintained editor code matches the tested mission. The successful client was retained for author review. English verification is scheduled for the next Workshop release.

For manual review, create two copies of an item, move and rotate the first, then delete it. Undo the deletion, then the preceding creation, rotation and movement actions in their recorded order. Redo the sequence. Check that the correct item is selected and returns to the same pose. Confirm Delete still edits the search or coordinate field, then save and reopen a project and export XML from the resulting scene.
