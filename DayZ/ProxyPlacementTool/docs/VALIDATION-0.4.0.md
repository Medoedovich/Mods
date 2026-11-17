# 0.4.0-alpha release validation

Built and tested on 17 November 2026 with DayZDiag 1.30.164289.70 and Test Range. The candidate has 17 package files. Both validation installs used the same PBO and launcher as the archive, from paths containing spaces and without file patching.

| Runtime language | Editor checks | Localization keys | XML files checked |
| --- | ---: | ---: | ---: |
| Russian | 395 | 255 | 6 |
| English | 395 | 255 | 6 |

Both tests confirmed two rows per wheel step in **Objects** and **Items**, with the same entry selected after scrolling down and back up. They also exercised project save/open, transform history, surface placement, the camera help and the standard loot overlay.

Both packages loaded the bundled backdrop texture. The viewport checks verified the layer order, alignment when the editor opening was resized, and visibility when switching into and out of character mode. The landscape was also observed in the developer mission at 3432 × 1440.

Both runs check that the hover popup uses the native preview layer between the backdrop and the toolbar hints. The Russian developer scene also confirmed visible 3D rendering of SledgeHammer with the landscape enabled and catalog switching by mouse.

The Russian test verified shutdown. The English test left the successful client available for the author's visual review and used the script log to verify completion while the engine RPT was still buffered.

- PBO SHA-256 `874BB3248ED0CBD605E0FD550DFB898E29D6D0764CE69E75B9349291B23F1ED9`
- ZIP SHA-256 `E35BFA1E81DD47931797A6ECDDA59747727ED853C7A827E62140616F65643FF6`

The author can use the open English client to check the toolbar and camera help, verify both catalog scroll speeds with a mouse, and capture the updated editor with standard loot volumes and an angled item.

## Workshop delivery

The author reported publication on 17 November 2026. All 17 downloaded Workshop package files match the validated 0.4.0-alpha candidate by SHA-256. The installed content manifest is `7294150487483844695`, and the PBO hash matches the value above. Runtime coverage comes from the packaged Russian and English tests described above.

The author supplied two screenshots, with JPEG copies prepared for Workshop under [screenshots/0.4.0-alpha/workshop](screenshots/0.4.0-alpha/workshop/). Saving the description is recorded from the author's confirmation. Public page text and gallery contents await independent verification. The repository's bundled `dist` contains the same 17 package files as the validated build and Workshop download. See [publication rules](../PUBLICATION.md).
