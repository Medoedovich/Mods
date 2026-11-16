# 0.3.0-alpha release and Workshop delivery validation

Prepared and manually published by the author on **16 November 2026**. Status: **Workshop delivery file-verified**. All 17 downloaded package files match the tested build. The local `dist/@ProxyPlacementTool` now contains the same 0.3.0-alpha package; the previous distribution was backed up.

| Check | English | Russian |
| --- | --- | --- |
| Native editor assertions | 292 passed | 292 passed |
| Explicit feature assertions | 164 passed | 164 passed |
| Native localization keys | 207 resolved, English column | 207 resolved, Russian column |
| Delivered files | 17 matched | 17 matched |
| Windows PowerShell launcher preflight | Passed | Passed |
| Separate installation with spaces in its path | Passed | Passed |
| Script compilation / VM exceptions / unsupported GUI keywords | 0 / 0 / 0 | 0 / 0 / 0 |
| Parsed XML exports | 5 | 5 |
| Client shutdown | Validated | Client retained for author review |

Tests ran in **DayZDiag 1.30.164289.70**, with Workshop Test Range **3826868718**, using the built PBO and bootstrap mission. File patching was disabled. Test profiles and mission sessions were outside the installed mod directory. Both copied installations matched the candidate file hashes; the archive's entries were checked against the same package.

Coverage includes map/item catalogs, localized name and classname search, hover model lifetime, world input boundaries, native movement/rotation, numeric fields and resets, toolbar and character mode, independent anchor/character movement, item dragging, replacement confirmation and cancellation, failure preservation, old world-entity cleanup, inventory preservation, increasing export scene IDs and CE XML output. The tests parse each exported position/angle vector and reject malformed or non-finite numbers.

## Artifacts

- Version: `0.3.0-alpha`
- Archive: `ProxyPlacementTool-0.3.0-alpha.zip`
- Archive SHA256: `3B18A2804AA40C4E67AAA1B918089C85654796525CD86A2984B5ED2FBA0CD846`
- PBO: `addons/iot_proxy_tool.pbo`, **384,583 bytes**
- PBO SHA256: `875450ECB4E301B855002BCF7025EDE66FF8C952F5879B186A5683C098AED482`
- Addon prefix: `iot\proxytool`
- Required source entries verified with official BankRev: **16**, including **12 layouts**.

The official Addon Builder used `-packonly`; no DayZ game assets, DayZDiag executable, Test Range files or runtime data were included. The package contains a portable launcher, instructions, bootstrap mission, editor PBO and hash manifest.

## Author review and publication

Visual inspection of the final release package is left to the author under the [validation workflow](VALIDATION.md). The earlier Russian font check was performed during development; it does not replace final author review.

1. In the open Russian client, drag an object from Objects, cancel replacement, then confirm it. Check that there is one anchor and the previous placed items are cleared only after confirmation.
2. Search Items by localized name and classname; hover for the model/classname, drag an item, move and rotate it, and enter numbers in the corresponding property mode.
3. Export XML and check the output. Switch to the character to inspect Take and nearby inventory, then return with F4. For a full usage reference, use the [current instructions](../package/README.en.md).
4. Capture the editor overview, an item hover preview and a placement/rotation example for the Workshop gallery.

Update the existing Workshop item **3839146464**, retaining Test Range **3826868718** as a dependency. The author prepares descriptions and release notes and performs the upload under [PUBLICATION.md](../PUBLICATION.md). The assistant has not launched Publisher, changed public pages, pushed GitHub commits or published a release.

Workshop delivery verification completed on 16 November 2026: all 17 package files, including the release manifest, match by SHA256. Steam adds its own meta.cpp. Installed content manifest: 5346954173286684114. The downloaded PBO is identical to the package tested in both languages, so another runtime was not started. Published metadata and the local distribution were updated after this comparison.

The author also manually announces each published version on Discord, including the version number, changelog, screenshots when available and a link to the Workshop item.

## Русский

Кандидат **0.3.0-alpha** подготовлен локально: по **292 проверки на русском и английском**, все **207 ключей локализации**, по **5 XML-экспортов**, **17 совпавших файлов** в каждой отдельной установке. Проверена загрузка из PBO без file patching. Английский клиент завершился штатно; русский успешно проверенный клиент оставлен открытым.

Автор вручную опубликовал **0.3.0-alpha** и добавил три скриншота в галерею. Все **17 скачанных файлов** совпали с проверенным пакетом по SHA256. Локальная папка `dist` обновлена до той же версии. Отдельный игровой прогон скачанной копии не повторялся: её PBO идентичен уже проверенному. Отсутствие сохранения проектов, Undo/Redo и удаления через меню остаётся ограничением alpha; существующий Gizmo может рисоваться за рамкой, при этом ввод ограничен активной областью.
