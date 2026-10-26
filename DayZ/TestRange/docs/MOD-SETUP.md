# DayZ Test Range — offline setup

1. Install DayZ and start Steam normally. DayZDiag_x64.exe is the default client; install the official diagnostic executable through DayZ Tools if it is absent.
2. Open this mod's folder and double-click Start-Offline.cmd. A separate server and Community Offline Mode are not required. Workshop downloads are stored under your Steam library's steamapps/workshop/content/221100/<item-id> folder.
3. Wait for READY: offline world loaded. Close DayZ normally before starting another client.

Optional command-line arguments:

```bat
Start-Offline.cmd -Retail
Start-Offline.cmd -Game "D:\SteamLibrary\steamapps\common\DayZ"
Start-Offline.cmd -ExtraMods "D:\Mods\@MyMod;D:\Mods\@AnotherMod"
Start-Offline.cmd -CheckOnly
```

The launcher discovers Steam library folders automatically. -Game overrides discovery; -Retail selects DayZ_x64.exe. ExtraMods must contain absolute folder paths separated by semicolons. Some mods require a server and cannot work in an offline mission.

Logs and local storage are under %LOCALAPPDATA%\DayZTestRange. The launcher does not start Steam or change its settings. If Steam is missing it reports an error. If the game itself cannot locate a running Steam instance, fully exit Steam using its menu and reopen it using your ordinary desktop shortcut.

World class: dayztestrange. Size: 1024 × 1024 m. Concrete height: absolute +1 m. Flat height samples span X/Z=4…1016; the outer sample ring is −20 m, with a coastal transition of about 4 m. Sea level is 0 m with tide and vertical wave displacement disabled. The central 250 × 250 m area is X/Z=387…637 and has no markings or separate material. Player spawn is X/Z=512/512.

The included offline mission does not initialize Hive/CE, so it has no automatic infected, animals, vehicles or loot. Additional mods can change this behavior. Normal survival remains enabled. No admin tools, free camera, item spawner or AI navmesh are included.

PBOs are intentionally unsigned: signatures are not needed for this offline workflow. Windows key containers are not required. Ordinary dedicated server validation is outside this release's scope. The optional mpmissions/empty.dayztestrange folder is retained for developers who choose to make a server scenario; no retail dedicated server compatibility claim is made.

## По-русски

Запусти Steam обычным способом, открой папку мода и дважды щёлкни Start-Offline.cmd. По умолчанию запускается DayZDiag, без отдельного сервера и COM. Ключ -Retail выбирает обычный DayZ; -Game задаёт папку игры вручную; -ExtraMods подключает дополнительные моды по абсолютным путям. Некоторые моды требуют серверного контекста и в offline работать не смогут.

Журналы находятся в %LOCALAPPDATA%\DayZTestRange. Перед повторным запуском закрой предыдущий клиент. Если сам DayZ не видит запущенный Steam, полностью выйди из Steam через его меню и открой обычным ярлыком. Запускатель не запускает Steam автоматически и не меняет его настройки.

Игрок появляется в центре. Автоматическая экономика отключена комплектной миссией. Поверхность +1 м, океан 0 м, узкая подводная кромка около 4 м. Центральная зона 250×250 м не размечена. Обычные механики выживания сохранены. Подпись PBO для этого offline-сценария не требуется и в комплект не включена.
