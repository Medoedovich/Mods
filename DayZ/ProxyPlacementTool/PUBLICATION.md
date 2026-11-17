# Правила публикации / Publication rules

## Русский

Автор и ответственный за публикации — **Medoedovich**.

- Тексты описаний, объявлений и заметок об обновлении автор оформляет и размещает вручную.
- Загрузку и обновление мода в Steam Workshop, публикацию релизов и объявлений автор выполняет вручную. Ассистент не запускает Publisher и не изменяет публичные страницы в рамках обычной подготовки версии.
- После публикации каждой новой версии автор вручную сообщает о релизе в Discord: указывает номер версии, прикладывает список изменений и скриншоты, если они есть. В сообщение добавляется ссылка на мод в Workshop.
- Ассистент готовит код, сборку, технические проверки и документацию проекта. Подготовка публикационного текста возможна по отдельной явной просьбе автора; готовый текст сам по себе не означает разрешения на публикацию.
- После ручной публикации автор присылает результат: ссылку, версию и при необходимости опубликованный текст. Ассистент использует эти данные для обновления записей проекта; подготовленный материал не считается опубликованным заранее.
- Изменения исходников и документации в GitHub выполняются по запросу автора. Это не даёт разрешения загружать мод в Workshop, создавать GitHub Release или публиковать объявления.
- При обычной разработке технические проверки выполняются на русском; английская версия проверяется перед релизом в Workshop. Визуальная проверка ассистентом — только по запросу автора; для самостоятельной проверки автор получает короткий чеклист. См. [порядок проверок](docs/VALIDATION.md).

Для следующего ручного обновления описания подготовлен [текст в Steam BBCode](workshop/description-next.bbcode.txt): сначала ссылка на [русское описание и инструкцию](README-RU.md), затем английский текст без отдельного русского раздела. Это черновик; окончательный текст и его размещение остаются за автором.

`workshop/item.json` фиксирует опубликованную версию 0.4.0-alpha и совпадение всех 17 скачанных файлов с проверенной сборкой. Сохранение описания отмечено по подтверждению автора от 17 ноября 2026 года. `workshop/description-combined.bbcode.txt` остаётся историческим снимком описания 0.2.0-alpha; текущая редакция описания отдельно не сверена. Черновик следующего текста не считается точной копией опубликованного описания.

## English

**Medoedovich** owns publication and release communication.

- The author manually prepares and posts descriptions, announcements and release notes.
- The author manually uploads and updates the Steam Workshop item and publishes releases and announcements. The assistant does not operate Publisher or edit public pages during routine release preparation.
- After publishing each new version, the author manually announces the release on Discord, including the version number, changelog and screenshots when available, plus a link to the Workshop item.
- The assistant prepares code, builds, technical validation and project documentation. Publication copy may be drafted when explicitly requested; a prepared draft does not authorize posting it.
- After publishing, the author sends the result: a link, version and, when needed, the posted text. The assistant uses that result to update project records. Prepared material must not be recorded as already published.
- Source and documentation changes may be committed to GitHub at the author's request. This does not authorize a Workshop upload, a GitHub Release or a public announcement.
- Routine technical checks use Russian; check English before a Workshop release. The assistant performs visual inspection only at the author's request and provides a short checklist for the author's own inspection. See the [validation workflow](docs/VALIDATION.md).

The [next Workshop description draft](workshop/description-next.bbcode.txt) begins with a link to the Russian description and instructions, followed by English copy without a separate Russian section. The author controls the final text and posts it manually.

`workshop/item.json` records the published 0.4.0-alpha version and SHA-256 verification of all 17 downloaded package files. Saving the description is recorded from the author's confirmation on 17 November 2026. `workshop/description-combined.bbcode.txt` remains the historical 0.2.0-alpha description snapshot; the current description has not been independently checked. A draft must not be treated as an exact published-text snapshot.
