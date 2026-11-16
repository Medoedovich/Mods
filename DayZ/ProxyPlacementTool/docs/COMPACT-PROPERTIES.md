# Object Properties / Свойства объекта

## English

The right panel shows the properties of the active native Gizmo mode. Entity and anchor names remain in the left scene list. Loot uses CE coordinates relative to its anchor; characters and anchors use world position.

- **Move / F7:** three X/Y/Z rows. Each row places the colored axis label, numeric field and reset icon beside one another. Rotation fields are hidden.
- **Rotate / F8:** three Roll/Pitch/Yaw rows in the existing CE `rpy` order. Field widths follow the longest displayed value in each mode; reset icons form a column four base UI pixels after the fields. Long values expand the fields within the panel. Position fields are hidden.
- Characters and anchors support Move only; their rotation remains a separate optional TODO task.
- Labels keep their red, green and blue backgrounds. Numeric fields use Metron22 and five decimal places.
- **Fine adjustments** is collapsed initially and follows the same mode. Move shows the movement step and position minus/plus controls, with test ground placement for loot. Rotate shows only the angle step and rotation minus/plus controls. Switching modes preserves the section's open state and does not move the entity.
- Valid numeric edits apply immediately. Both decimal points and commas work. The active field is not reformatted while typing. Incomplete or out-of-range input keeps the last valid pose; leaving an invalid field restores its displayed value.
- Each reset restores only its component to the value at selection. F9 retains the full position/pose reset.
- General actions are on the [top toolbar](TOOLBAR.md). F1 and F4 hints are not repeated in Object Properties.
- F7/F8 keyboard hints use three lines: arrow keys, PgUp/PgDn, and Shift for finer steps. Rotation hints name Roll/Pitch/Yaw. The status area wraps text; selecting a character or anchor no longer shows the redundant world-coordinate movement hint.
- Numeric errors use the separate [error notification](ERROR-NOTIFICATIONS.md), while control hints remain in the properties panel. Correcting a value clears the previous error.

The proxy conversion, XML formatting and input limits remain unchanged. Moving an anchor changes only the anchor, with ordinary loot physics. Color labels identify the displayed CE components; they do not change coordinate conversion or native Gizmo axes.

Technical validation on 15 November 2026: **263 checks**, including **18 properties checks**, passed with the Russian interface in an unpacked Test Range mission. Checks cover row alignment and reset spacing, mode-specific fields and fine controls, toolbar and F7/F8 switching without pose changes, live input, individual resets, independent character/anchor movement, catalogs and XML. Visual review is left to the author; English runtime validation is deferred until the Workshop release. No PBO was built.

Manual checklist:

1. Select the wheel in Move: inspect the three X/Y/Z rows with values beside their labels and no rotation fields.
2. Switch to Rotate using the toolbar, F7 and F8: only the active mode's fields should appear; inspect the nearby angle reset icons.
3. Open Fine adjustments and switch modes: only the relevant controls should remain, and the wheel should keep its pose.
4. Edit values and reset one component: other components should remain unchanged. F9 should restore the full pose.
5. Select Character and the wreck: only position editing should be available, and moving the wreck should leave loot in place.

## Русский

Справа показаны свойства активного режима штатного Gizmo. Названия сущности и опоры остаются в левом списке сцены. Для лута используются относительные координаты CE, для персонажа и опоры — мировая позиция.

- **Движение / F7:** три строки X/Y/Z. В каждой рядом расположены цветная подпись оси, числовое значение и иконка сброса. Углы скрыты.
- **Поворот / F8:** три строки Roll/Pitch/Yaw в прежнем порядке CE `rpy`. Ширина полей подстраивается под самое длинное отображаемое значение в текущем режиме. Иконки сброса выровнены в колонку через четыре базовых пикселя интерфейса после полей; для длинных значений поля расширяются в пределах панели. Координаты скрыты.
- Для персонажа и опоры доступно только перемещение; их вращение остаётся отдельным опциональным пунктом TODO.
- Сохранены красные, зелёные и синие подложки подписей, шрифт чисел Metron22 и пять знаков после точки.
- **«Тонкая настройка»** изначально свёрнута и также зависит от режима. В «Движении» видны шаг перемещения и кнопки минус/плюс координат, для лута — пробное размещение на земле. В «Повороте» видны только шаг углов и кнопки их изменения. Переключение режима сохраняет состояние секции и не меняет позу сущности.
- Корректные числа применяются сразу. Поддерживаются точка и запятая; активное поле не переформатируется при наборе. Незавершённое число или выход за пределы сохраняют последнюю корректную позу; при уходе из недопустимого поля отображение возвращается к корректному значению.
- Каждый сброс возвращает только свою компоненту к значению на момент выделения. F9 сбрасывает всю позицию/позу.
- Общие действия находятся на [верхней панели инструментов](TOOLBAR.md). Подсказки про F1 и F4 в свойствах не повторяются. Успешное создание предмета не оставляет надпись «Создано: …»; сообщения об ошибках сохранены.
- Подсказки клавиш F7/F8 разбиты на три строки: стрелки, PgUp/PgDn и Shift для точного шага. Углы подписаны Roll/Pitch/Yaw. Для текста статуса включён перенос; при выборе персонажа или опоры повторная подсказка про мировые координаты больше не показывается.
- Ошибки чисел показываются в отдельном [уведомлении об ошибках](ERROR-NOTIFICATIONS.md), подсказки управления остаются в панели свойств. Исправление значения очищает прежнюю ошибку.

Расчёт proxy, формат XML и допустимые пределы чисел сохранены. Перемещение опоры меняет только опору, с обычной физикой лута. Цветные подписи обозначают отображаемые компоненты CE и не меняют преобразование координат или оси штатного Gizmo.

Техническая проверка от 15 ноября 2026 года: **263 проверки**, включая **18 проверок панели свойств**, прошли с русским интерфейсом в миссии Test Range без упаковки. Проверены выравнивание строк и близость сброса, поля и тонкая настройка активного режима, переключение кнопками и F7/F8 без изменения позы, ввод на лету, отдельные сбросы, независимое перемещение персонажа/опоры, каталоги и XML. Визуальная проверка оставлена автору; английский интерфейс проверяется перед релизом в Workshop. PBO не собирался.

Для самостоятельной проверки:

1. Выбери колесо в «Движении»: проверь три строки X/Y/Z со значениями рядом с подписями и отсутствие углов.
2. Переключи режим кнопками и F7/F8: должны появляться только нужные поля; посмотри на близость сброса к значениям углов.
3. Раскрой «Тонкую настройку» и смени режим: остаются только соответствующие действия, колесо сохраняет позу.
4. Измени значения и сбрось одну компоненту: остальные сохраняются. F9 восстанавливает всю позу.
5. Выбери персонажа и остов: доступны только координаты; перемещение остова не переносит лут.
