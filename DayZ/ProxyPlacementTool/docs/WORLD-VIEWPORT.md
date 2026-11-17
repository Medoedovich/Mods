# World editing area / Область редактирования мира

Current development update: an [opaque outside mask and shared panel theme](EDITOR-THEME.md) now hide the world outside this input rectangle and follow its live bounds. F4 hides the mask for character inspection. Camera controls now use **held RMB** inside the rectangle; the historical F1 references below describe the earlier implementation.

Обновление разработки: [непрозрачный фон и единое оформление](EDITOR-THEME.md) закрывают мир за рабочей областью и следуют за её границами. F4 скрывает фон для проверки персонажем. Камера теперь управляется при **удержании ПКМ** внутри области; упоминания F1 ниже относятся к прежнему варианту.

## English

The editor outlines a world input area between the left catalog/scene-list column and the precise settings panel, extending to the bottom margin. The former bottom tray is now a compact [Scene Objects list](SCENE-OBJECTS.md) in the left column. Bounds follow the actual panel geometry and UI scaling. Empty margins outside that rectangle are excluded as well as the panels themselves.

- Click an item or empty space inside the area to select or deselect it. Clicking menus or outside margins preserves the selection.
- Native Gizmo transforms apply inside the area. Leaving it cancels the current drag at the last accepted placement; release the mouse and start a new drag to continue. Returning while still holding the button does not resume the cancelled drag.
- Move the cursor into the area before pressing **F1** to enter camera flight. **F1** always returns to cursor mode. Flight, mouse look and the wheel multiplier pause while the application is inactive or a game menu is open.
- Keyboard nudges require the cursor inside the area and no focused text field. Numeric controls on the right and selection in the left scene list remain available.
- **F4** hides the area along with the editor panels and restores character controls. Returning to the editor restores the area. If panels overlap and leave no usable rectangle, world input is disabled until enough space is available.

The frame defines an input boundary. Camera projection, screen rays and the native Gizmo continue to use the engine's normal full-screen coordinates; the world is not rendered to a separate camera texture.

Known visual issue reported during manual review: native Gizmo handles can still be drawn outside the frame, including over panels. Rendering bounds are tracked separately in [TODO](../TODO.md); the report states that the issue does not affect the main workflow.

Development validation on 14 November 2026 used an unpacked Test Range mission: **153 scripted checks per language** in Russian and English, including **17 checks for the world input area**. The checks cover layout changes, overlapping panels, transform guards, cancelled gestures, mode switching and the existing catalogs/selection/XML workflows. Actual mouse dragging with the native handles is a separate manual check. No new PBO was built for this change.

## Русский

Рамка обозначает область ввода для мира между левой колонкой каталога/списка сцены и панелью точной настройки, до нижнего поля экрана. Прежний нижний список заменён компактной панелью [«Объекты на сцене»](SCENE-OBJECTS.md) слева. Границы следуют за фактическим положением и размером панелей с учётом масштаба интерфейса. Пустые поля за пределами прямоугольника также исключены из редактирования.

- Внутри области щелчок выбирает предмет или снимает выделение при нажатии на пустое место. Нажатие на меню и внешние поля сохраняет выделение.
- Штатный Gizmo изменяет положение и поворот внутри области. Выход за границу отменяет текущее перетаскивание в последнем принятом положении. Для продолжения нужно отпустить кнопку и начать новый жест; возвращение с зажатой кнопкой не возобновляет отменённый жест.
- Для полёта наведите курсор в область мира и нажмите **F1**. Вернуться к курсору через **F1** можно всегда. При потере фокуса приложения или открытом игровом меню полёт, обзор мышью и изменение множителя скорости приостанавливаются.
- Сдвиги с клавиатуры работают, когда курсор внутри области и текстовое поле не имеет фокуса. Числовые настройки справа и выбор в левом списке сцены остаются доступны.
- **F4** скрывает область вместе с панелями редактора и возвращает управление персонажем. При возвращении в редактор область восстанавливается. Если панели перекрылись и места для области не осталось, ввод для мира отключается до восстановления свободного места.

Рамка ограничивает ввод. Проекция камеры, экранные лучи и штатный Gizmo сохраняют обычные экранные координаты движка; отдельная текстура камеры для мира не создаётся.

При ручной проверке обнаружена отдельная визуальная проблема: ручки штатного Gizmo могут оставаться за рамкой, в том числе поверх панелей. Ограничение отрисовки записано в [TODO](../TODO.md). По отзыву автора, проблема не влияет на основную работу.

Проверка разработки от 14 ноября 2026 года выполнена в обычной миссии Test Range без упаковки: **по 153 программные проверки на русском и английском**, включая **17 проверок области ввода**. Проверены изменение геометрии и перекрытие панелей, ограничения преобразований, отмена жеста, переключение режимов и прежние сценарии каталогов, выделения и экспорта XML. Перетаскивание штатных ручек обычной мышью проверяется отдельно вручную. Новый PBO для этого изменения не собирался.
Toolbar integration / Панель инструментов: the top edge also follows the live bottom edge of the toolbar, including wrapped rows. Ordinary toolbar clicks preserve selection and cannot edit the world; its dedicated Fly/Cursor button explicitly switches the camera mode. Верхняя граница учитывает высоту панели инструментов и перенос кнопок на следующую строку; клики по панели сохраняют выделение и не редактируют мир. See / Подробнее: [TOOLBAR.md](TOOLBAR.md).
