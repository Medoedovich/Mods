# Validation / Проверки

- [1.0.0: release package and Workshop delivery](VALIDATION-1.0.0.md) — 658 assertions per language, 410 localization keys and all 17 matching downloaded files; published and delivery-file verified on 2026-11-25.

- [0.4.0-alpha: release package and Workshop delivery](VALIDATION-0.4.0.md) — 395 checks per language, 255 localization keys, 17 matching downloaded files; published and file-verified, 2026-11-17.
- [0.3.0-alpha: release package and Workshop delivery](VALIDATION-0.3.0.md) — 292 checks per language, 207 localization keys, 17 matching downloaded files; published and file-verified, 2026-11-16.

- [0.2.0-alpha: package, installed copies and Workshop delivery](VALIDATION-0.2.0.md) — published 2026-11-14.
- [0.1.0-alpha: original publication record](VALIDATION-0.1.0.md) — historical release, 2026-11-13.

**1.0.0 опубликована и сверена 25 ноября 2026.** Пакет прошёл по 658 проверок на русском и английском, проверены 410 ключей локализации. Все 17 скачанных Workshop-файлов совпали с проверенной сборкой по SHA-256; локальный `dist` содержит те же файлы. Скачанную копию повторно в игре не запускали, так как её файлы совпадают с пакетами, прошедшими игровые проверки.

## Split editor regression — 24 November 2026 (unreleased)

The current unpacked Russian editor passed two isolated native suites: **305 catalog checks** and **340 scene-workflow checks**. Catalog coverage includes all map branches, visibility filters, subdivisions, localized/classname search and item/object previews. Workflow coverage includes 25 Undo/Redo checks, 17 item-operation checks, 23 project checks, 13 unsaved-change checks, 21 anchor-drag checks and 24 item-drag checks, alongside Gizmo/viewport boundaries, numeric editing, notifications, reference loot volumes, camera, character mode and XML export. Exported XML files were parsed after the native run. See [recorded results](editor-regression-validation.json).

The two suites share startup/localization/viewport checks; their counts are assertion executions, not a sum of unique test cases. No production editor code changed during this run. Splitting tests avoids the standalone mission's static-buffer limit while retaining each suite's checks; excluded methods fail explicitly if called. The Workflow validator does not claim localized search coverage, which is required separately from the Catalog result.

The native Workflow suite reached PASS and left its client running. The launcher initially expected catalog-only assertions in that same log; its report validation was corrected for the split scopes and repeated against the original successful logs using `-ValidateOnly`, without restarting the editor or re-executing passed tests. This validates an existing completed native run and never creates a synthetic PASS.

По-русски: **24 ноября 2026 технический прогон пройден**: 305 проверок каталога и 340 проверок работы со сценой. Проверены сохранение/открытие, резервная копия проекта, защита несохранённых изменений, Undo/Redo, создание/удаление, перемещение/повороты, режимы, XML и остальные существующие сценарии. Общие стартовые проверки повторяются в обеих частях. Исходники самого редактора при этом не менялись; доработаны разделение наборов и проверка отчётов. Последний успешный клиент оставлен открытым. На этом этапе PBO ещё не собирался. Позднее 24 ноября завершены английский прогон и обе проверки PBO: по 598 проверок на каждом языке. Итог — [готовый пакет 1.0.0](VALIDATION-1.0.0.md).

## CE pickup and Vicinity — 24 November 2026 (unreleased)

An isolated DayZDiag offline mission loaded the existing `Land_Garage_Row_Small` export containing two HatchbackWheel proxies (one angled) and Hammer. All tested items were absent before Hive initialization and were created by CE. All three positions matched the export with zero error and matching orientation bases. The fixture also filled all 64 standard garage points with 34 distinct types, at most two instances per type. Maximum-density quotas and relaxed regional/usage filters are specific to this fixture and do not describe ordinary live-mission distribution.

The author opened the inventory near each proxy and picked it up through normal gameplay controls, confirming the Take action and Vicinity display for all three. An optional read-only observer tracked the original CE instances: it recorded each in `VicinityItemManager.GetVicinityItems()` while the inventory UI was open and then in the player's hierarchy. It neither spawned nor moved loot. All three observation pairs passed. See [recorded results](ce-interaction-validation.json).

Developer runner: `ProxyPlacementTool/release/Test-CEExport.ps1 -Action Offline -Export <export.xml> -AnchorPosition <position> -FillStandardPoints -StandardRepeatLimit 2 -ReviewInteractions`. It prepares a separate mission, observes placement and leaves the client running. The `ce-result.json` report covers CE placement; `ce-interactions.json` separately records the author-driven inventory observations. No PBO is built. This does not add an in-editor test button and does not validate multiplayer.

По-русски: **24 ноября 2026 закрыты проверки «Взять» и «Поблизости»** для обоих колёс и молотка, созданных CE по экспорту. Автор подтвердил действия обычным управлением, а наблюдатель зарегистрировал все три исходных предмета в штатном списке «Поблизости» и у персонажа. Координаты и углы совпали с экспортом; 64 штатные точки гаража тоже заполнены. Офлайн-миссия оставлена открытой.

## Порядок проверок при разработке

- При обычной разработке выполнять необходимые технические проверки только с русским интерфейсом. Английскую версию проверять перед релизом в Steam Workshop.
- После успешных технических проверок оставлять тот же клиент открытым для проверки автором. Не закрывать его ради отдельного повторного запуска превью. Локальный `Test-WorldViewport.ps1` по умолчанию сохраняет работающий редактор и его тестовую сцену; для пакетных прогонов с завершением процесса использовать `-CloseAfterTest`. В отчёте различать успешные проверки и проверку завершения клиента: при оставленном окне завершение не проверяется.
- Текущую сцену не перезапускать только ради повторной проверки уже загруженного поведения. Если изменения требуют перезапуска миссии, предварительно учитывать несохранённое размещение.
- Визуальную проверку ассистент проводит только по отдельному запросу автора. Не запускать её автоматически после изменений.
- Для самостоятельной проверки автором давать короткий список действий и ожидаемых результатов: что нажать, на что посмотреть и какое поведение считать правильным.
- В отчёте различать выполненные технические проверки и визуальные проверки, оставленные автору. Визуальная проверка не считается выполненной до фактического просмотра или подтверждения автора.

## Development validation workflow

- During ordinary development, run the necessary technical checks with the Russian interface only. Check the English version before a Steam Workshop release.
- After successful technical checks, leave the same client open for the author's review instead of closing it and launching a separate preview. The local `Test-WorldViewport.ps1` keeps its editor and test scene running by default; use `-CloseAfterTest` for batches that require process termination. Reports distinguish successful checks from shutdown validation, which is not performed when the client remains open.
- Do not restart the current scene merely to recheck behavior already loaded. When changes require a mission restart, account for unsaved placement first.
- The assistant performs visual inspection only when the author explicitly requests it; do not start it automatically after changes.
- For the author's own inspection, provide a short checklist of actions and expected results: what to click, what to look for and what correct behavior looks like.
- Reports distinguish completed technical checks from visual checks left to the author. Do not record visual inspection as completed before actually inspecting it or receiving the author's confirmation.
