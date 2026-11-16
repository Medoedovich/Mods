# Building and wreck placement / Размещение зданий и остовов

## English

Drag a building or wreck from **Objects** into the framed world editing area and release it over a surface. Clicking a catalog entry only selects it. Folders, the scrollbar, drops outside the area and drops over the sky do not create an anchor. The Create building / wreck button has been removed.

The editor keeps **one anchor** for relative proxy coordinates. If the scene is empty, the drop creates it immediately. Otherwise, a modal shows the current and new classnames and offers **Replace** or **Cancel**. Escape also cancels. While the dialog is open, scene manipulation and other creation actions are blocked.

- **Cancel:** keep the anchor, items, selection and Gizmo unchanged.
- **Replace:** create and validate the new anchor first, then remove the old anchor and its tracked world items. Start an empty layout with the new anchor selected for movement.
- **Creation or validation failure:** keep the old layout and show an error.
- The character, equipment, picked-up items and existing XML exports remain. Export the layout before replacing it if it is needed later; project save/load and undo are not available yet.

Anchors retain zero rotation and scale one for the current CE calibration. Ground placement preserves the drop's X/Z coordinates. Scene identifiers increase throughout the editor session, preventing a replacement from reusing an earlier scene's XML filename. Ordinary anchor movement continues to leave its items in place.

Items still support repeated drag-and-drop creation without a quantity limit. Native Gizmo editing and XML exports are unchanged.

Technical validation uses the unpacked Russian Test Range mission. English interface validation is deferred until the Workshop release. Manual checks: drag an unselected object row, cancel a replacement, then confirm one and check the scene list. Visual review is performed by the author on request.

## Русский

Перетащи здание или остов из раздела **«Объекты»** в область мира внутри рамки и отпусти над поверхностью. Обычный щелчок только выбирает строку каталога. Папки, полоса прокрутки, отпускание за рамкой и над небом не создают опору. Кнопка «Создать здание / остов» удалена.

В редакторе остаётся **одна опора**, относительно которой вычисляются координаты Proxy. В пустой сцене она создаётся сразу. Если опора уже есть, появится окно с текущим и новым classname и кнопками **«Заменить» / «Отмена»**. Escape также отменяет замену. Пока окно открыто, редактирование сцены и создание других сущностей заблокированы.

- **Отмена:** опора, предметы, выделение и Gizmo сохраняются.
- **Заменить:** сначала создаётся и проверяется новая опора, затем удаляются старая опора и её отслеживаемые предметы в мире. Новая раскладка пустая, опора выбрана для перемещения.
- **Ошибка создания или проверки:** старая раскладка сохраняется, показывается сообщение об ошибке.
- Персонаж, его экипировка, подобранные предметы и уже выгруженные XML сохраняются. Если раскладка ещё нужна, перед заменой выгрузи XML: сохранения проекта и отмены действий пока нет.

У опоры сохраняются нулевые углы и масштаб 1 для текущего вычисления CE-координат. При установке на землю сохраняются X/Z точки отпускания. Номера сцен растут в пределах сеанса, поэтому замена не перезаписывает XML предыдущей сцены с тем же типом опоры. Обычное перемещение опоры по-прежнему оставляет предметы на прежних местах.

Предметы можно создавать перетаскиванием многократно, без ограничения количества. Сохраняются штатный Gizmo и экспорт XML.

Техническая проверка выполняется на русском в распакованной миссии Test Range. Английский интерфейс проверяется перед релизом в Workshop. Для ручной проверки: перенеси ранее не выбранную строку объекта, отмени замену, затем подтверди её и проверь список сцены. Визуальная проверка — автором по требованию.

## Validation / Проверки

16 November 2026: **292 native scripted checks passed**, including **21 anchor drag and replacement checks**, using `Test-WorldViewport.ps1 -AnchorDrag -Language Russian`. The same successful client remains open for author review. No PBO was built; the published version is unchanged.

16 ноября 2026: пройдены **292 программные проверки в игре**, из них **21 — перетаскивание и замена опоры**. Успешно проверенный клиент оставлен открытым для автора. PBO не собирался, опубликованная версия не менялась.
