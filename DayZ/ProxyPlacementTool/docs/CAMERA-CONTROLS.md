# Camera controls — 0.4.0-alpha

Hold the right mouse button over the scene to control the camera. Available in 0.4.0-alpha.

- Hold the right mouse button inside the world editing area to fly. Use WASD to move, **Q to rise, Z to descend**, and the mouse to look around. Height follows the world vertical regardless of view direction. These editor keys do not depend on Bulldozer bindings; holding Q and Z together cancels vertical movement.
- Release the right mouse button to restore the cursor and native Gizmo. The selected entity and its position remain unchanged.
- While flying, the wheel changes the speed multiplier from 0.1 to 16. The indicator appears below the central reticle. Shift/Ctrl temporarily multiply movement speed by 10; Alt multiplies it by 0.1.
- Pressing RMB over a panel and moving into the world does not start flight. Release and press again inside the world area. Catalog dragging and left-button world gestures take priority over camera capture.
- Opening a menu, losing application focus, hiding the world viewport or entering character mode stops flight. Releasing and pressing RMB again is required before flight can resume.
- Captured flight continues while RMB is held even if the hidden cursor leaves the world rectangle. The boundary controls where capture begins, rather than limiting mouse look after capture.
- F1 no longer toggles camera mode, and the dedicated Fly/Cursor toolbar button is removed. F4 still switches between the editor and normal character controls.

## Local validation

Run `ProxyPlacementTool/release/Test-WorldViewport.ps1 -HoldCamera -Language Russian` from the development workspace. It builds an unpacked mission and leaves a successful test client open for author review. It does not build a PBO.

The native regression suite checks capture/release, panel entry rejection, left-button and catalog drag conflicts, selection and Gizmo preservation, context cancellation, viewport recovery, character mode, and the existing speed multiplier behavior. Physical mouse capture and focus transitions also require an author check.

On 2026-11-16 the Russian unpacked mission passed all 302 native checks, including 12 dedicated camera-hold checks. The suite passed again after changing Q/Z height input, and the author confirmed Q/Z operation in game. This confirmation covers the height controls; the remaining mouse capture and focus-transition checklist is separate. English validation is deferred until the next Workshop release.

## Author check

1. Hold RMB over the world and try WASD, Q to rise, Z to descend, mouse look and the wheel. Look up/down and check that Q/Z still move vertically. Holding both keys should stop vertical movement. Release RMB: the cursor and selected entity's Gizmo should return, and Q/Z should no longer move the camera.
2. Drag the entity with the left mouse button. Pressing RMB during that gesture should not start flight. Check the same behavior while dragging an item from the catalog.
3. Press RMB over a panel and move into the world without releasing: the camera should remain stationary.
4. During flight, open Escape or switch to another application. On return, flight should remain stopped until RMB is released and pressed again.
5. Switch to the character with F4, check normal movement and RMB behavior, then return to the editor.
