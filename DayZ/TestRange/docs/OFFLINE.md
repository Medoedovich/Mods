# Offline testing

The recommended launcher is `dist/@DayZTestRange/Start-Offline.cmd`. It ships with its own mission, discovers Steam libraries and does not depend on WorkDrive or the source checkout's directory name. Steam must already be running. DayZDiag is the default; `-Retail` selects DayZ_x64.exe.

From the mod folder:

```powershell
.\Start-Offline.cmd -CheckOnly
.\Start-Offline.cmd -Retail
.\Start-Offline.cmd -Game "D:\SteamLibrary\steamapps\common\DayZ"
.\Start-Offline.cmd -ExtraMods "D:\Mods\@Example;D:\Mods\@Another"
```

`-CheckOnly` validates paths and inputs without starting an application. Extra mods must be existing absolute directories separated by semicolons. Close the previous client before launching another. Successful startup is confirmed by a fresh mission log entry and `READY: offline world loaded.` The presence of a process alone is not treated as proof of a loaded world.

The standalone launcher keeps profiles, logs and local storage under `%LOCALAPPDATA%\DayZTestRange`. It does not autostart Steam, probe Steam API readiness or edit the game installation. If the game cannot locate a running Steam instance, fully exit Steam through its menu and reopen it using your normal Windows shortcut.

## Mission behavior

The mission creates the player in `MissionGameplay.OnInit()` after `super.OnInit()`, using X/Z=512/512 and terrain height +0.1 m. Hive/CE is not initialized. Economy XML additionally disables automatic population. Normal survival behavior remains active. Other mods can change this setup.

Offline testing does not cover network replication, RPC or persistence on a dedicated server. The optional `Start-Test-Server.cmd`, `Start-Test-Client.cmd` and `server/` files are retained for development; retail dedicated server compatibility was not validated for this release. Their sample passwords are local development defaults, not production credentials.

The project's top-level `Start-Offline.cmd` is a source-development helper. Its `-Game` default is an example Windows Steam path and can be overridden; it stores runtime files under this project. Use the standalone launcher above for automatic game discovery and portable distribution.

No COM, custom admin menu, spawner, God mode, free camera or AI navmesh is included. Built-in diagnostics are available when using DayZDiag. Validation and known limitations are recorded in [VALIDATION.md](VALIDATION.md).
