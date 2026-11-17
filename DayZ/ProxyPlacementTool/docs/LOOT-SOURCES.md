# Loot reference sources — 0.4.0-alpha

## Current behavior

The editor now prefers the selected map's **installed game XML**. It validates and caches a complete map dataset once per editor session; a new session clears the cache and reads the installed files again. This follows the installed game version without requiring a regenerated bundled dataset after each DayZ update.

If a game XML file is unavailable or fails validation, the editor uses the bundled reference for that map and identifies it as a fallback. Enabling fallback geometry reports a localized warning. Valid game XML remains authoritative: absent groups and known zero-point groups are not supplemented with old snapshot points. Map variants remain separate. Source details show the map and either the installed DayZ version or the bundled-fallback label; point counts remain in the diagnostic log.

The reader processes short file fragments, maintaining state across tags, comments and processing instructions split between fragments. Native string replacement is used only on bounded tag fragments: this client's replacement operation truncates megabyte strings. Processing the full buffer through repeated string searches also caused long stalls, so the runtime path reads file lines and bounded fragments instead. The first parse in the validated run took approximately 0.4–0.6 seconds per map; repeated source requests reuse the parsed cache. Files over 10 MB and tags over 4 KB are rejected in favor of fallback data.

Validation on **2026-11-17**: **16 Russian native checks** passed, including comparison of **all 53,335 installed points** and all known groups against the verified baseline. Checks cover position/radius/height/container values, cache reuse, multiline/quoted attributes, comments, scientific numbers, missing dimensions, split fragment boundaries, malformed input, updated/removed/empty groups, unavailable/corrupt files, unavailable backup, rendered geometry/source details and cleanup. The same successful client was retained for author review. No PBO or publication was performed; English runtime checks remain deferred until release.

Development command: `ProxyPlacementTool/release/Test-RuntimeLootSources.ps1`. Current report: `ProxyPlacementTool/release/RUNTIME-LOOT-SOURCES-VALIDATION-Russian.json`. Full UI input regressions are separate; this native source regression does not require mouse input or window focus.

## Confirmed direct game-file access

On **2026-11-17**, an unpacked Test Range mission running **DayZDiag 1.30.164289.70** successfully read all four installed official terrain prototypes through the native script file API:

| Map | Virtual file path | Groups | Container points |
| --- | --- | ---: | ---: |
| ChernarusPlus | `DZ\worlds\chernarusplus\ce\mapgroupproto.xml` | 436 | 11,074 |
| Livonia | `DZ\worlds\enoch\ce\mapgroupproto.xml` | 456 | 11,304 |
| Sakhal | `DZ\worlds\sakhal\ce\mapgroupproto.xml` | 525 | 13,888 |
| Nasdara | `DZ\worlds\nasdara\ce\mapgroupproto.xml` | 755 | 17,069 |

This was a read test, not just a file-existence test. Native `OpenFile` and `ReadFile` captured the complete XML into the test profile; PowerShell then parsed the XML and calculated SHA-256. All four captures matched the extracted official source files used to generate the existing reference dataset, byte for byte. A readable loose-mission control and a rejected nonexistent-file control also passed. Installed PBO headers independently confirmed the virtual prefixes and presence of `mapgroupproto.xml` entries.

The initial read probe was independent of mouse input and application focus. It built no PBO, changed no installed game files, and performed no publication. The installed-file access it confirmed is now used by the runtime reader described above.

Development probe: `ProxyPlacementTool/release/Probe-InstalledLootXml.ps1`. It injects `release/installed_loot_probe.c` into a disposable unpacked mission through `Test-WorldViewport.ps1 -Preview -Demo -InstalledLootProbe`. Result: `ProxyPlacementTool/release/INSTALLED-LOOT-PROBE-VALIDATION-Russian.json`. The native report and captured XML remain inside that run's profile. A complete editor input regression is separate from this source-read probe.

## Loading order and future imports

1. The corresponding installed game's official prototype, when readable and valid.
2. The bundled snapshot as a clearly identified fallback.

Available DLC/data packages may differ between installations, so the fallback remains relevant. A future explicitly connected mission XML dataset should take priority over both of these sources. User-facing XML import has not been implemented in this change.

A user-supplied complete map dataset should replace the reference for that map, rather than silently unioning points with vanilla data. Otherwise points deliberately removed from a mission could return in the overlay. A future data-source dialog should identify the selected source and its version/date; projects should retain their source association. User import and this dialog are proposals, not current functionality.

The installed official prototype describes vanilla data. A server mission's edits and additional prototype files require the user's mission dataset; reading the installed game cannot infer them.

## По-русски

Проверка подтвердила: штатные XML четырёх карт читаются прямо из игровых архивов через API DayZDiag. Содержимое всех файлов полностью совпало с исходниками нашего встроенного набора.

Теперь основной источник визуализации — XML установленной игры. Он проверяется и кэшируется для карты один раз за сеанс. При недоступном или повреждённом файле включается встроенный резерв с понятной подписью и предупреждением. Исправные игровые файлы не дополняются старыми точками.

Пройдены 16 проверок RU и полная сверка 53 335 точек. Миссия оставлена открытой для авторской визуальной проверки. Для изменённых серверных миссий понадобится отдельная функция подключения своих XML — она остаётся следующей задачей.
