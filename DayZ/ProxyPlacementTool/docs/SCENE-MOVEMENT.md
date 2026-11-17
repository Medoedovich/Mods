# Scene object movement / Перемещение объектов сцены

## English

In 0.4.0-alpha, adding or confirming replacement of an anchor places the existing test character on the camera side, **five metres beyond the model's horizontal bounding box**, on terrain and facing the model center. The distance is measured from the model bounds. The character and equipment are retained. Item creation, cancelled/invalid replacements and moving an existing anchor do not reposition the character. Opening a project restores its saved character position. Use **F4** to inspect from the character's new position.

Validation on 17 November 2026: **383 Russian native checks** in an unpacked mission, including **7 character placement checks** covering first creation, all camera sides and the overhead fallback, equipment/camera preservation, item creation, cancelled/invalid/pending replacements, confirmed replacement and independent manual anchor movement. The successful client was left open for author review. Development report: `ProxyPlacementTool/release/CHARACTER-START-VALIDATION-Russian.json`; rerun with `Test-WorldViewport.ps1 -CharacterStart -Language Russian`. English runtime review remains deferred until release.

Select the character or a registered building/wreck in **Scene Objects** to focus the camera and enable the stock movement Gizmo. Drag an arrow or enter world X/Y/Z coordinates in the right panel, then apply them. Selection is shown in the left scene list. **F9** restores the position captured when that object was selected.

- Moving an anchor changes that anchor's world position. Loot is not automatically translated or attached to it. CE proxy coordinates are calculated from the items' current world positions relative to the moved anchor.
- Other anchors, their items and the character keep their positions when an anchor moves.
- The character can be moved before an anchor exists. Moving the character preserves its orientation and leaves loot placement unchanged. **F4** resumes character control at the new position.
- Anchors and the character support translation only. Their rotation and scale are preserved; rotation controls are disabled. Loot items retain movement, rotation and relative proxy coordinate editing.
- World-area input guards apply to these Gizmo gestures. A drag that leaves the active area is cancelled until a new mouse press.
- Anchor editing does not change loot physics modes or freeze items. Ordinary game physics continues to apply.
- CE XML contains loot proxies. The character and the anchor's editor world position are not added as proxies. Place the building/wreck itself through the target mission's normal object placement workflow.

Manual check: select and move the wreck, confirm that the wheel is not automatically moved with it, then reset with F9; select Character and move it, then use F4; select the wheel again and check that its movement and rotation still work.

Technical validation on 14 November 2026: **232 checks** with the Russian interface in an unpacked Test Range mission, including **23 movement checks**. These cover native transforms, independent entity movement, recalculated proxy coordinates, unchanged item physics modes, world coordinate input, F9, and character control after F4. Visual inspection is pending the author's check; English runtime validation is deferred until the Workshop release.

## Русский

В исходниках следующей версии при добавлении или подтверждённой замене опоры существующий персонаж переносится со стороны камеры **на пять метров за горизонтальные габариты модели**, ставится на землю и разворачивается к центру здания/остова. Расстояние считается от габаритов, а не от точки отсчёта модели. Персонаж и экипировка сохраняются. Создание предметов, отмена или ошибка замены и обычное перемещение опоры не переносят персонажа. Открытие проекта восстанавливает сохранённую позицию. **F4** возвращает управление уже на новом месте.

Выбери персонажа или зарегистрированное здание/остов в **«Объекты на сцене»**: камера направится на него, появятся штатные стрелки перемещения. Тяни стрелку или введи мировые координаты X/Y/Z справа и примени значения. Выделение показано в левом списке сцены. **F9** возвращает позицию, зафиксированную при его выделении.

- Перемещение опоры меняет мировую позицию только этой опоры. Лут автоматически не переносится и не прикрепляется к ней. Координаты CE proxy вычисляются по текущим мировым позициям предметов относительно перемещённой опоры.
- Другие опоры, их предметы и персонаж сохраняют свои позиции при перемещении здания/остова.
- Персонажа можно перемещать до создания опоры. Его ориентация и расстановка лута сохраняются. **F4** возвращает управление персонажем на новом месте.
- Для опоры и персонажа доступно перемещение. Их поворот и масштаб сохраняются; управление поворотом отключено. У предметов остаются движение, вращение и относительные координаты proxy.
- Для Gizmo действуют границы активной области мира. Выход за рамку отменяет жест до нового нажатия мыши.
- Редактирование опоры не меняет режимы физики лута и не фиксирует предметы. Обычная игровая физика продолжает действовать.
- В XML CE выгружаются прокси лута. Персонаж и мировая позиция опоры в редакторе не добавляются как прокси. Само здание/остов размещается обычными средствами целевой миссии.

Для самостоятельной проверки: выдели и перемести остов, убедись, что колесо не переносится автоматически вместе с ним, затем сбрось через F9; выбери и перемести персонажа, затем нажми F4; снова выбери колесо и проверь его движение и поворот.

Техническая проверка от 14 ноября 2026 года: **232 проверки** с русским интерфейсом в миссии Test Range без упаковки, включая **23 проверки перемещения**. Проверены штатные преобразования, независимое перемещение объектов, пересчёт координат proxy, сохранение режимов физики предметов, ввод мировых координат, F9 и возврат управления через F4. Визуальная проверка ожидает проверки автором; английский интерфейс проверяется перед релизом в Workshop.
