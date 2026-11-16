# Editor toolbar / Панель инструментов

## Русский

Верхняя панель собирает общие действия редактора:

- **Движение · F7** и **Поворот · F8** переключают штатный Gizmo. Без выделения обе кнопки скрыты. Для персонажа и опоры доступно только перемещение.
- **Полёт · F1** включает полёт камеры из панели, сохраняя выделение предмета. В полёте подпись меняется на **Курсор · F1**; F1 возвращает курсор. Кнопка доступна и без выделения.
- **Показать опору** наводит камеру на активное здание/остов, сохраняя выделение предмета.
- **Персонаж · F4** включает проверку сцены от лица персонажа. F4 возвращает редактор.
- **XML предмета · F10** выполняет прежний экспорт выбранного предмета и всей его опоры.
- **XML всей опоры** сохраняет все предметы активной опоры на земле, без необходимости выделять один из них.

Без опоры её показ и экспорт недоступны. XML выбранного предмета недоступен, когда выбраны персонаж или опора либо выделение снято. Клавиши F7/F8/F4/F10 сохраняют прежнее назначение.

Кнопки перенесены из боковых панелей. В каталоге осталась кнопка создания здания/остова; в свойствах — поля трансформации, индивидуальный сброс и сворачиваемая тонкая настройка. Панель свойств и тонкая настройка показывают только позицию в «Движении» или только углы в «Повороте».

Панель занимает верхнюю строку и переносит кнопки на следующую строку при недостаточной ширине. Боковые панели и рамка мира располагаются ниже неё. Обычные клики по панели сохраняют выделение и не выбирают предметы сквозь интерфейс. Полёт с панели включает отдельная кнопка; для клавиши F1 сохраняется прежнее условие начала полёта из области мира. В режиме персонажа панель скрыта вместе с остальным редактором. Подсказки про F4 в панели свойств убраны; кнопка режима персонажа остаётся на панели инструментов.

Для самостоятельной проверки: выбери колесо и переключи Движение/Поворот; включи «Полёт · F1» и верни курсор по F1, проверив сохранение выделения; нажми «Показать опору» и проверь сохранение выделения; выгрузи оба XML; перейди в режим персонажа и вернись по F4. Проверь читаемость кнопок и отсутствие наложений на боковые панели. Визуальную проверку выполняет автор, английский интерфейс проверяется перед релизом в Workshop.

## English

The top toolbar contains Move (F7), Rotate (F8), Fly/Cursor (F1), Focus anchor, Character (F4), Item XML (F10) and Full anchor XML. Manipulation buttons are hidden without a selection; characters and anchors support movement only. Anchor actions require an active anchor, and item export requires a selected loot item. The camera button also works without a selection and changes its label to the available next action.

Item XML preserves the existing F10 behavior: export the selected item and its full anchor. Full anchor XML exports all loose items belonging to the active anchor without requiring an item selection. Anchor focus preserves selection and placement. The existing keyboard shortcuts remain available.

General actions are removed from the sidebars. The catalog retains building/wreck creation, while properties retain transformation inputs, individual resets and Fine adjustments. Properties and Fine adjustments show only position in Move mode or angles in Rotate mode.

Buttons wrap when the available width is insufficient. Sidebars and the world editing area sit below the toolbar. Ordinary toolbar input preserves selection and cannot edit the world. The dedicated camera button explicitly starts flight from the toolbar; the F1 key retains its requirement to start flight from the world editing area. Character mode hides the toolbar; returning to the editor restores it. F4 hints are removed from Object Properties, while the Character toolbar button remains.

Development validation uses an unpacked Russian Test Range mission. The author performs visual review; English runtime validation is deferred until the Workshop release.

Техническая проверка от 14 ноября 2026 года: **255 проверки прошли**, включая **8 проверок панели инструментов**. Проверены переключение штатного Gizmo и подсветка активного режима, границы ввода, сохранение выделения при использовании панели, экспорт обоих XML и скрытие/возврат интерфейса в режиме персонажа. Сцена запускалась без PBO; визуальная проверка ожидает автора.

Technical validation on 14 November 2026: **255 checks passed**, including **8 toolbar checks**, in an unpacked Russian mission. These cover native Gizmo mode and its active indicator, input bounds, selection preservation, both XML actions and hiding/restoring editor panels in character mode. Visual review is pending the author.
