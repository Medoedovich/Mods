# 1.0.0 release validation and handoff

**Published and delivery files verified:** the author released 1.0.0 on 25 November 2026. All 17 downloaded Workshop files match the package below by SHA-256. The bundled `dist` contains the same files. See the [publication record](workshop-1.0.0-publication.json) and [delivery verification](workshop-1.0.0-delivery-validation.json).

Prepared on **24 November 2026**, published manually by the author and downloaded-file verified on **25 November 2026**. This is the first stable version number; runtime support remains **DayZDiag offline on Test Range**. Sources, documentation, cover and the verified package were [published to GitHub](https://github.com/Medoedovich/Mods/commit/f703caacb3ce5261a5e4e627c8252e0f5be6c913) on 25 November. The GitHub connector confirmed the main-branch commit and all 155 file blobs, including all 17 package files. The author published the [1.0.0 Discord thread](https://discord.com/channels/452035973786632194/1575067129089228870/1575067129089228870) on 25 November, supplied publication screenshots showing the cover and pub-placement video, and confirmed posting a redirect in the retained alpha thread. The Workshop discussion link still requires a manual update by the author.

## Packaged runtime checks

Built with the official DayZ Tools Addon Builder and checked with BankRev. Both installations used the exact same PBO, launcher and bootstrap mission from paths containing spaces, without `filePatching`. The delivered launcher passed preflight under Windows PowerShell 5.1. Runtime: **DayZDiag 1.30.164289.70**.

| Runtime language | Assertion executions | Required feature assertions | Localization keys | XML files parsed |
| --- | ---: | ---: | ---: | ---: |
| Russian | 658 | 266 | 410 | 6 |
| English | 658 | 266 | 410 | 6 |

The suite covers projects, unsaved-change protection, Undo/Redo, item creation/deletion, anchor replacement, Gizmo and numeric editing, world input boundaries, camera controls, scene selection, notifications, catalog/search, item previews, standard loot volumes and XML export. It includes 24 Specific and 36 Industrial/Residential subgroup assertions. The 658 executions contain 655 distinct assertion descriptions; repeated item scenarios account for the difference. Both final native runs reached PASS and REVIEW_READY without compilation errors, VM exceptions or unsupported GUI keywords. They checked completion while retaining the client; clean shutdown is not claimed by these runs.

All **17 delivered files** match both test installations. All archive entries were independently hashed and match the same files. Current addon sources match the source snapshot used for the final build. See the [Russian report](release-1.0.0-russian.json), [English report](release-1.0.0-english.json) and [artifact record](release-1.0.0-preparation.json).

- PBO SHA-256: `AC8A616160B47BB992F220563221F4FA7F974FE439DCD4B764A584A5F61D9D2E`
- ZIP SHA-256: `EBFC30115F68B0B04416D27D5055E31A9D0C7E1222964F5E1CAD6E4569ACB6B5`

Two earlier attempts stopped at different camera-entry assertions. Failure-context logging was added to self-tests, without changing camera behavior or weakening any assertion. The final build passed the complete Russian and English suites with the game window active. The earlier logs remain under the developer validation runtimes; their precise cause was not independently established.

## Additional coverage

Before the final build, the updated unpacked Russian Catalog suite passed **365 assertions**, including 20 building/wreck/StaticObj hover-preview checks and the catalog audit. Earlier baseline Catalog/Workflow suites passed 305/340 assertions in each language. Catalog-only checks are separate from the packaged full-suite totals above. Splitting the unpacked tests avoids the standalone mission's static-buffer limit. See [building-family results](building-families-validation.json), [split regression](VALIDATION.md#split-editor-regression--24-november-2026-unreleased) and the [earlier English results](editor-regression-validation-english.json).

The author also verified physical F4 switching without a gesture and actual CE-created loot in a separate offline mission: two wheels and a hammer match the exported poses, appear in Vicinity and can be picked up. A read-only observer independently recorded all three native CE instances. These checks do not claim multiplayer coverage. See [F4 observations](MODE-SWITCH-VALIDATION.json) and [CE interactions](ce-interaction-validation.json).

Visual inspection remains with the author. Existing gallery images are from 0.4.0-alpha; the author plans to provide 1.0 screenshots later and has recorded a pub-placement video. A new [illustrated cover](../workshop/1.0.0/preview-1.0.0-v2.jpg) shows an angled wheel on the driver's seat with a Gizmo, a rifle leaning against the open door, and a Rasputin kvass can on the roof, without Alpha branding. It is 1254 × 1254, 397618 bytes, JPEG quality 90, converted without resizing from the generated PNG. See the [prompt](../workshop/1.0.0/cover-prompt-v2.txt) and [image record](../workshop/1.0.0/preview-record-v2.json). Native Gizmo drawing outside the world frame remains an optional visual improvement.

## Передача автору

1. Готовая папка для Publisher: `build/20261124-173151-520/@ProxyPlacementTool` относительно каталога проекта. Архив: `ProxyPlacementTool/release/artifacts/ProxyPlacementTool-1.0.0-20261124-173151-520.zip` относительно рабочего каталога DayZ. Точные локальные пути и хеши сохранены в [записи артефактов](release-1.0.0-preparation.json). Новое превью: `workshop/1.0.0/preview-1.0.0-v2.jpg` относительно каталога проекта.
2. Вручную обновить существующий Workshop item **3839146464**, сохранив зависимость **Test Range 3826868718**. Версия пакета — **1.0.0**, отображаемое название — **Proxy Placement Tool**. Тексты и оформление публикации остаются за автором по [правилам](../PUBLICATION.md).
3. Сверка скачанного обновления выполнена 25 ноября 2026: все 17 файлов совпали с проверенным пакетом. Записи публикации и поставляемая папка `dist` обновлены до сверенной 1.0.0; предыдущая поставка сохранена в резервной папке разработчика.
4. Объявление 1.0.0 опубликовано автором в новой теме Discord 25 ноября 2026. В старой теме alpha оставлена ссылка на новую; обложка и видео из паба видны на предоставленных автором скриншотах. Ссылка в черновике описания Workshop обновлена; её ручное сохранение на странице Workshop пока не подтверждено.

Исходники, документация, обложка и сверенная папка `dist` версии 1.0.0 опубликованы в GitHub; совпадение файлов подтверждено через коннектор. Прежняя поставка сохранена в резервной папке разработчика. Предоставленные автору тексты описания и Change Notes сохранены как черновики; публичное описание Workshop и загруженная обложка независимо не проверены. Ассистент не изменял страницы Workshop и не отправлял объявление в Discord.

## Workshop delivery — 25 November 2026

The installed content manifest is **8375434699612165101**. All 17 files, including the PBO, launcher, bootstrap mission and release manifest, match the prepared package. The PBO hash is `AC8A616160B47BB992F220563221F4FA7F974FE439DCD4B764A584A5F61D9D2E`. Runtime coverage comes from the packaged Russian/English runs above; the downloaded copy was not runtime-retested.

The initial isolated filesystem check still saw the previous 0.4.0-alpha files. Repeating the comparison directly against the host Windows filesystem confirmed the updated 1.0.0 installation and all 17 matching hashes. The host result is the delivery evidence recorded here.
