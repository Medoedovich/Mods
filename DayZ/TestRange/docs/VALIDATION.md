# Validation and known limitations

The original release was built and tested on Windows with DayZ 1.30.164200.56 on 24–25 October 2026. The native terrain project, runtime scripts and built PBOs in this repository are copied from that release. Published descriptions and repository documentation are maintained separately from the binary terrain.

- Official Terrain Builder exported a genuine 256 × 256 terrain at 4 m spacing and reported zero placed objects. Official Addon Builder/Binarize/CfgConvert produced the world, data and CE PBOs. BankRev checked package contents and prefixes.
- The main offline mission loaded in both diagnostic and ordinary clients. The ready-to-run package was also downloaded through Steam Workshop and launched from the subscribed mod folder, with the launcher reporting `READY: offline world loaded.` and exiting with code 0. No separate server was required for that workflow.
- A 600-second observer audit recorded eleven samples, one per minute including the start, with one player and zero automatic infected, animals, vehicles and ground items. A deliberately created SodaCan_Cola was detected and deleted before observation to check the detector.
- Main terrain elevation is +1 m. The approved −20 m outer sample ring produces the narrow coastal transition. Ocean tide and vertical wave displacement are disabled. Central spawn and dry concrete were checked in game.
- The four gallery JPGs are actual game captures of this build. The cover is generated promotional artwork, not a gameplay screenshot.

The matching build hashes are in [artifacts.json](artifacts.json). Existing binaries have not been regenerated for the GitHub publication.

On 26 October 2026, the prepared `DayZ/TestRange` checkout passed the existing `Validate.ps1 -RequireWorld` check using the installed vanilla resource tree. The standalone launcher also passed `-CheckOnly` for both diagnostic and ordinary clients from its new directory. No game process was started by these publication checks. All terrain source, mission, runtime script and PBO bytes were compared with the tested release and matched.

## Limits of these checks

There is no AI navmesh, custom admin menu, item spawner or free camera. Normal survival mechanics remain enabled. Additional mods can initialize their own spawning or require a server context. Offline testing does not establish replication/RPC correctness or ordinary dedicated server compatibility.

Inherited CAWorld Weather/Overcast warnings and diagnostic cleanup warnings remain. Stock Chernarus comparison was used when reviewing the logs; map sky and ILS configuration warnings were corrected before release. This is not a claim of a warning-free runtime. A complete day/night cycle and arbitrary weather changes were not separately validated.

PBO signatures are intentionally omitted for the offline workflow. No private signing keys are distributed. Original local runtime profiles, crash dumps, machine-specific launcher logs and publication screenshots are not part of this source repository.
