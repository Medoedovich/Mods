# Validation / Проверки

- [0.4.0-alpha: release package and Workshop delivery](VALIDATION-0.4.0.md) — 395 checks per language, 255 localization keys, 17 matching downloaded files; published and file-verified, 2026-11-17.
- [0.3.0-alpha: release package and Workshop delivery](VALIDATION-0.3.0.md) — 292 checks per language, 207 localization keys, 17 matching downloaded files; published and file-verified, 2026-11-16.

- [0.2.0-alpha: package, installed copies and Workshop delivery](VALIDATION-0.2.0.md) — published 2026-11-14.
- [0.1.0-alpha: original publication record](VALIDATION-0.1.0.md) — historical release, 2026-11-13.

Опубликованная версия: **0.4.0-alpha**. Релизный пакет прошёл по 395 проверок на русском и английском, разрешены 255 ключей локализации. Все 17 скачанных Workshop-файлов совпали с проверенной сборкой по SHA-256.

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
