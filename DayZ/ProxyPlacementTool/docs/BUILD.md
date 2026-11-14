# Build from source / Сборка из исходников

## English

Use Windows PowerShell 5.1 or PowerShell 7, with the official **DayZ Tools** installed. Run commands from the `DayZ/ProxyPlacementTool` directory. Use a PowerShell session configured to run your local scripts.

```powershell
# Prepare source and the package template without invoking DayZ Tools.
.\tools\Build.ps1 -PrepareOnly

# Build with official Addon Builder, then inspect the PBO with BankRev.
.\tools\Build.ps1 -Tools 'X:\SteamLibrary\steamapps\common\DayZ Tools'
```

Each call creates a separate `build/<timestamp>` directory and prints the output paths. A complete build contains `@ProxyPlacementTool`, including the launcher, mission, editor PBO and file-hash manifest. `build/latest.json` identifies the latest result and whether it was only prepared or built. The checked-in `dist` package is not overwritten.

The source prefix is **`iot\proxytool`**. The script uses `-packonly`; it does not binarize or redistribute DayZ assets. The official `AddonBuilder.exe` and `BankRev.exe` paths are resolved relative to the supplied `-Tools` folder. BankRev verifies the prefix and every required source entry.

Edit the addon under `src/iot/proxytool`. `scripts/5_Mission/IOTProxyTool.c` is the assembled, readable editor script; it includes localization helpers, catalogs, UI handling, native Gizmo integration and editor self-tests. `IOTMapCatalog.c` contains the generated [map membership data](MAP-CATALOG.md). The [item catalog](ITEM-CATALOG.md) reads loaded item configurations at runtime. `stringtable.csv` is the native 167-key RU/EN table. Keep fallback language columns populated when editing it. The five `gui/*.layout` files use its `#STR_IOT_` keys.

Edit the launcher or bootstrap mission under `package`. To run a new build, close the existing DayZ client, install Test Range, then run **Start-Editor.cmd** from that build's `@ProxyPlacementTool` directory. Runtime data is outside the mod directory. The packed script and GUI resources must load without `-filePatching`.

The launcher accepts `-SelfTest -ExpectedLanguage English` or `-SelfTest -ExpectedLanguage Russian` for editor regression checks. The expected language must match the actual client language. Use `-RuntimeRoot` to isolate test profiles. These switches are for development; ordinary editing starts without them. A successful run records `[PROXY TOOL V2 SELFTEST] PASS:` in the profile RPT. See [validation scope](VALIDATION.md); it is still necessary to test exported settings in the target CE mission.

For Workshop updates, use the existing item **3839146464**, preserve the required **Test Range 3826868718**, and verify the downloaded package. `workshop/item.json` records the published item and original PBO hash. Building creates a local package; it does not upload anything or update that record automatically.

## Русский

Нужны Windows PowerShell 5.1 или PowerShell 7 и официальные **DayZ Tools**. Выполняйте команды из `DayZ/ProxyPlacementTool` в сеансе PowerShell, настроенном на запуск локальных скриптов:

```powershell
.\tools\Build.ps1 -PrepareOnly
.\tools\Build.ps1 -Tools 'X:\SteamLibrary\steamapps\common\DayZ Tools'
```

Первый вариант готовит исходники и шаблон без запуска DayZ Tools. Второй собирает PBO официальным Addon Builder и проверяет его BankRev. Каждый запуск создаёт отдельный `build/<время>`; пути выводятся в консоль, последний результат записывается в `build/latest.json`. Готовая папка `@ProxyPlacementTool` содержит launcher, миссию, PBO и манифест хешей. Версия в `dist` не перезаписывается.

Префикс addon — **`iot\proxytool`**. Используется `-packonly`, без обработки и распространения игровых ресурсов. Параметр `-Tools` указывает каталог DayZ Tools, внутри которого скрипт находит AddonBuilder и BankRev. Проверяются префикс PBO и все необходимые файлы.

Исходники addon находятся в `src/iot/proxytool`. `scripts/5_Mission/IOTProxyTool.c` — объединённый читаемый скрипт редактора: локализация, каталоги, интерфейс, штатный Gizmo и проверки. `IOTMapCatalog.c` содержит сгенерированные [данные фильтра карт](MAP-CATALOG.md). [Каталог предметов](ITEM-CATALOG.md) читает загруженную конфигурацию при запуске. `stringtable.csv` содержит 167 ключей RU/EN; при изменении сохраняйте английские значения в остальных языковых столбцах. Пять layout-файлов в `gui` используют ключи `#STR_IOT_`.

Launcher и стартовая миссия находятся в `package`. Для проверки новой сборки закройте текущий клиент DayZ, установите Test Range и запустите **Start-Editor.cmd** из новой папки `@ProxyPlacementTool`. Данные сеанса хранятся отдельно от мода. Скрипт и интерфейс должны загружаться из PBO без `-filePatching`.

Для проверок есть параметры launcher `-SelfTest -ExpectedLanguage English` и `-SelfTest -ExpectedLanguage Russian`; язык должен совпадать с фактическим языком клиента. `-RuntimeRoot` позволяет отделить тестовый профиль. При обычном редактировании эти параметры не нужны. Успешный прогон оставляет `[PROXY TOOL V2 SELFTEST] PASS:` в RPT. [Границы проверки](VALIDATION.md): экспортированные настройки дополнительно проверяются в целевой CE-миссии.

Обновления Workshop загружайте в существующий item **3839146464**, сохраняя зависимость **Test Range 3826868718**, затем проверяйте скачанный пакет. `workshop/item.json` описывает текущую публикацию и хеш исходного PBO. Скрипт сборки ничего не публикует и не меняет эту запись автоматически.

