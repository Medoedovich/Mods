# Alpha 0.2.0 validation

Published on **2026-11-14** by **Medoedovich** for **DayZDiag 1.30.164289.70**, offline Test Range workflow. The existing public Workshop item is [3839146464](https://steamcommunity.com/sharedfiles/filedetails/?id=3839146464); [Test Range](https://steamcommunity.com/sharedfiles/filedetails/?id=3826868718) remains required. The [0.1.0 publication record](VALIDATION-0.1.0.md) is historical.

## Final candidate

- Built with official Addon Builder. BankRev verified the `iot\proxytool` prefix and nine required entries: config, native stringtable, two Mission scripts (editor and generated map catalog), and five layouts.
- Separate installation copies in paths containing spaces passed the Windows PowerShell launcher preflight, then **136 editor checks per language** in Russian and English, without file patching. All **167 localization keys** resolved in the expected language.
- Catalog checks cover map/category trees, StaticObj filtering, nested wreck types, item categories, complete inventory coverage, searching more than 100 results, expansion state and exact classname selection. The test installation loaded **2262 inventory classes**; each belongs to one item group.
- Existing regressions cover native Gizmo, precise transforms, camera speed multiplier, cursor/flight/character modes, selection and bottom tray, character clothing/boots, HUD visibility and XML exports.
- Both runs produced independent wreck and garage XML exports, with one and two proxies respectively. XML vectors were parsed and checked for three finite values.
- The final runs had **0 editor compilation errors, 0 Virtual Machine Exceptions and 0 unsupported GUI keyword messages**. Stock Diag/Test Range startup diagnostics remain; these counts do not claim that every engine/terrain log is empty.

Published PBO: `dist/@ProxyPlacementTool/addons/iot_proxy_tool.pbo`, **228963 bytes**.

```text
SHA256 7C58624E693439E772F3166DD6F375A782ACA243377B840AE5D80FB8C468A18C
```

The ready package contains **17 files**, including `release-manifest.json`, which records the other 16 delivered files. The staged distribution and archive are checked against that manifest. Source and package versions are **0.2.0-alpha**. Raw logs, runtime storage, checkpoints, private keys and game executables are excluded from the package and repository publication set.

## Workshop delivery and scope

Official DayZ Publisher reported successful publication to the existing public item. Steam content manifest: **8907751712909589628**. The signed-out public page returned HTTP 200 and showed version 0.2.0-alpha, the new category descriptions, the Test Range dependency and the existing discussion/source/contact links. The combined English/Russian description is 7785 UTF-8 bytes and was verified in full within Publisher's 8000-byte limit.

After Steam refreshed the subscription, the downloaded installation independently passed **136 checks in Russian and 136 in English**. All **17 delivered files** matched the prepared release by SHA256; Steam's own service metadata is separate. Both runs exported a garage with two proxies and a wreck with one proxy. These runs used the Workshop installations of both the tool and Test Range, without the original development mission or file patching.

The final package tests validate the editor and its exported data. CE spawning was not repeated for this update; item availability and the target mission's `types.xml` and group configuration still require testing in that mission. Map/resource-family categories describe catalog organization, not guaranteed placement on every terrain.

Retail DayZ, dedicated servers, multiplayer, arbitrary third-party classes and rotated/scaled anchors were not validated. Project save/load, delete UI and undo/redo remain deferred. Further subdivision of item folders with more than 30 entries is recorded in [TODO](../TODO.md).

The repository distribution uses the same validated PBO and package. The cover remains an AI-generated illustration, not a game screenshot.

## По-русски

Версия **0.2.0-alpha** опубликована 14 ноября 2026 года. Отдельные копии установки в папках с пробелами и скачанная Workshop-копия прошли по **136 проверок на русском и английском**, включая **167 ключей локализации**. Проверены каталог из 2262 предметов без потерь и дублей, деревья объектов и предметов, поиск без ограничения в 100 результатов, фильтр StaticObj, штатный Gizmo, режимы интерфейса и отдельные XML для гаража и остова. Ошибок компиляции редактора, VM-исключений и неподдерживаемых GUI-ключей в итоговых прогонах нет; штатные диагностические сообщения движка остаются.

Все 17 файлов, доставленных через Workshop, совпали с подготовленным пакетом; служебные метаданные Steam учитываются отдельно. На публичной странице проверены версия, новые категории, зависимость Test Range и ссылки сообщества. В репозитории используется тот же PBO. Повторный спавн через CE, обычный клиент, сервер, мультиплеер, произвольные модовые классы и повёрнутые/масштабированные опоры в эту проверку не входили.
