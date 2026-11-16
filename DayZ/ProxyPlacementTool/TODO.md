# TODO

- [ ] Добавить подкатегории для категорий предметов, содержащих **более 30 элементов**. Разбивать по смыслу также уже существующие подкатегории, если их конечный список предметов превышает этот порог. Сохранить поиск по всему каталогу, счётчики, доступность всех classnames и русские/английские подписи.

  **English:** Add meaningful subcategories wherever an item category or existing subcategory contains more than 30 item entries. Preserve global search, counts, complete classname coverage and Russian/English labels.

- [ ] Создать `FEATURES.md` с описанием основных и второстепенных возможностей редактора. Например: индикатор множителя скорости камеры под прицелом, который появляется при изменении скорости колесом мыши.

  **English:** Create `FEATURES.md` documenting both major and smaller editor features, including the camera speed multiplier indicator shown below the crosshair when the mouse wheel changes speed.

- [x] Сделать отдельную активную зону для редактирования мира в интерфейсе редактора. [Реализованное поведение и проверки](docs/WORLD-VIEWPORT.md).

  **English:** Add a dedicated world editing viewport to the editor interface. See [implemented behavior and validation](docs/WORLD-VIEWPORT.md).

- [x] Искать предметы одновременно по игровому названию на языке клиента и classname, без учёта регистра и крайних пробелов, в том числе по части названия. Например: «Молоток» и `Hammer`, «КА-74» и `AK74`. Предметы с одинаковыми названиями сохраняют отдельные строки и точные классы. Плейсхолдер «Предметов» — `Classname / Name`. [Поведение и проверки](docs/ITEM-CATALOG.md).

  **English:** Search Items by either the client-localized display name or classname, accepting partial queries and ignoring case and surrounding spaces. Preserve separate rows and exact identities for classes with shared names. The Items placeholder is `Classname / Name`. See [behavior and validation](docs/ITEM-CATALOG.md).

- [ ] **Опционально:** проверить поиск по названиям на остальных языках, поддерживаемых игрой, и при необходимости доработать обработку текста, сохраняя поиск по classname. Английский интерфейс проверять перед релизом в Workshop.

  **English:** **Optional:** validate name search in the other game languages and adjust text handling if needed, while preserving classname search. Check the English interface before the Workshop release.

- [ ] Добавить режим редактирования Proxy: включён по умолчанию, с отдельной кнопкой на панели инструментов.

  **English:** Add a Proxy editing mode, enabled by default, with a dedicated toolbar button.

- [ ] Добавить режим заполнения здания по его стандартным точкам лута, с отдельной кнопкой включения на панели инструментов.

  **English:** Add a mode for filling a building at its standard loot points, activated by a dedicated toolbar button.

- [ ] Реализовать сохранение и открытие проекта.

  **English:** Implement saving and opening projects.

- [ ] **Опционально:** разделить каталог «Предметы» по картам: ChernarusPlus, Livonia, Sakhal и Nasdara. Продумать выделение общих для нескольких карт предметов в раздел **Common**. Сохранить категории, подкатегории и поиск по всему каталогу.

  **English:** **Optional:** organize the Items catalog by map: ChernarusPlus, Livonia, Sakhal and Nasdara. Consider a **Common** section for items shared across maps. Preserve categories, subcategories and global catalog search.

- [ ] Пересмотреть описание в Workshop и описание изменений. Убрать из описания Workshop дублирующие название и строку автора/версии (`Proxy Placement Tool — Alpha`, `By Medoedovich · 0.2.0-alpha`). В описании изменений оставить английский текст и ссылку на GitHub вместо полного русского перевода. Окончательный текст и публикацию автор выполняет вручную по `PUBLICATION.md`.

  **English:** Review the Workshop description and release notes. Remove redundant title and author/version lines from the Workshop description (`Proxy Placement Tool — Alpha`, `By Medoedovich · 0.2.0-alpha`). Keep release notes in English with a GitHub link instead of a full Russian translation. The author handles final copy and publishing manually under `PUBLICATION.md`.

- [x] Добавить в галерею Workshop реальные скриншоты инструмента. Автор вручную загрузил три изображения 16 ноября 2026: общий вид с каталогом и превью, размещение предмета под углом и проверка персонажем. Оригиналы и JPEG-копии: [скриншоты 0.3.0-alpha](docs/screenshots/0.3.0-alpha/).

  **English:** Add real tool screenshots to the Workshop gallery. The author manually uploaded three images on 16 November 2026: the editor overview with catalog and hover preview, angled item placement, and character inspection. Originals and JPEG upload copies: [0.3.0-alpha screenshots](docs/screenshots/0.3.0-alpha/).

- [ ] Ограничить отрисовку штатного Gizmo активной областью мира: его ручки не должны оставаться поверх панелей и внешних полей при выходе за рамку. Сохранять выбранный предмет и запрет возобновления отменённого перетаскивания. Это отдельная визуальная доработка; основная работа активной области от неё не зависит.

  **English:** Restrict native Gizmo rendering to the world editing area so handles do not remain over panels or outer margins beyond the frame. Preserve item selection and cancellation of a drag on boundary exit. This is a separate visual improvement and does not block the main world input workflow.

- [x] **Первый этап:** добавить создание предметов перетаскиванием из каталога в активную область мира. Создавать предмет в точке отпускания; за пределами области отменять создание. Не ограничивать количество предметов в сцене, сохраняя их привязку к активной опоре. Кнопка создания предмета убрана. [Поведение и проверки](docs/ITEM-DRAG.md).

  **English:** **First stage:** create items by dragging catalog entries into the world editing area. Spawn at the drop point and cancel outside the area. Do not limit the number of scene items; keep their association with the active anchor. The item creation button is removed. See [behavior and validation](docs/ITEM-DRAG.md).

- [x] **Второй этап:** добавить создание зданий и остовов перетаскиванием из каталога в активную область мира. После внедрения убрать кнопку «Создать здание / остов». Перед созданием проверять, нет ли в сцене уже созданного редактором здания или остова: предусмотреть одну активную опору, относительно которой вычисляются координаты предметов, и не создавать вторую без решения о смене опоры. Реализовано окно «Заменить / Отмена» с сохранением старой сцены при ошибке. [Поведение и проверки](docs/ANCHOR-DRAG.md).

  **English:** **Second stage:** create buildings and wrecks by dragging them from the catalog into the world editing area, then remove the Create building / wreck button. Before spawning, check for an existing editor-created building or wreck in the scene. Use one active anchor for relative item coordinates and require an anchor-change decision before creating another. Implemented Replace / Cancel confirmation and preservation of the old scene on failure. See [behavior and validation](docs/ANCHOR-DRAG.md).

- [x] **Следующий релиз:** после реализации и проверки перетаскивания зданий/остовов с ограничением одной опорой на сцене подготовить новую версию для Steam Workshop со всеми накопленными изменениями. Перед релизом проверить английский интерфейс. Публикацию автор выполняет вручную по [правилам публикации](PUBLICATION.md).

  **English:** **Next release:** after implementing and validating building/wreck drag-and-drop with one scene anchor, prepare a new Steam Workshop version containing the accumulated changes. Validate the English interface before release. The author publishes manually under the [publication rules](PUBLICATION.md). Candidate 0.3.0-alpha prepared and validated locally: [report](docs/VALIDATION-0.3.0.md). Publication remains pending.

- [x] В описании проекта и следующего обновления упомянуть источник вдохновения для интерфейса: «Дизайн интерфейса вдохновлён World Editor из Arma Reforger».

  **English:** Mention the interface design inspiration in the project description and next update: “Interface design inspired by the World Editor in Arma Reforger.”

- [x] Показывать 3D-превью предмета в каталоге «Предметы» до переноса на сцену: во всплывающем окне при наведении. Нижняя карточка и создание превью по клику удалены. [Поведение и проверки](docs/ITEM-PREVIEW.md).

  **English:** Show a native 3D hover preview for Items catalog entries before dragging them into the scene. Remove the lower card and click-preview creation path. See [behavior and validation](docs/ITEM-PREVIEW.md).

- [ ] Добавить превью зданий и остовов при выделении соответствующего элемента в каталоге «Объекты».

  **English:** Add previews of selected buildings and wrecks in the Objects catalog.

- [ ] Добавить автоматический поворот камеры, когда перемещаемый предмет приближается к краю активной области. Согласовать поведение с отменой перетаскивания при выходе за рамку.

  **English:** Automatically rotate the camera when a dragged item approaches an edge of the world editing area. Coordinate this behavior with drag cancellation when leaving the frame.

- [x] Переработать окно сцены: компактный плоский список «Объекты на сцене» слева под каталогом показывает персонажа, здание/остов и предметы. Щелчок по предмету выбирает точный экземпляр и включает штатный Gizmo; строки опоры и персонажа фокусируют камеру. [Поведение и проверки](docs/SCENE-OBJECTS.md).

  **English:** Rework the scene list as a compact flat Scene Objects panel below the left catalog, showing the character, anchors and items. Clicking an item selects the exact native Gizmo target; anchor and character rows focus the camera. See [behavior and validation](docs/SCENE-OBJECTS.md).

- [x] Разделить отображение здания/остова и предметов в разделе «Объекты на сцене»: убрать совместную иерархию «опора → её предметы». В этом режиме планируется только одно здание/остов на сцене, поэтому такая группировка не требуется.

  **English:** Separate the building/wreck and item entries in Scene Objects, removing the anchor-to-items hierarchy. This mode is planned to contain only one building/wreck, so grouping items under their anchor is unnecessary.

- [x] Убрать подсчёт и отображение количества элементов в разделе «Объекты на сцене».

  **English:** Remove the element count from Scene Objects.

- [x] Убрать отображаемые ID из раздела «Объекты на сцене». Сохранить возможность выбирать точный экземпляр предмета, в том числе при одинаковых classnames.

  **English:** Remove visible IDs from Scene Objects while preserving selection of the exact item instance, including duplicate classnames.

- [x] Показывать персонажа в разделе «Объекты на сцене» как отдельный элемент сцены.

  **English:** Include the character as a separate scene entry in Scene Objects.

- [x] Добавить перемещение выбранного персонажа или здания/остова штатным Gizmo и вводом мировых координат. Сброс позиции — F9; F4 возвращает управление персонажем на новом месте. Лут автоматически не переносить, его физику при перемещении опоры не менять. [Поведение и проверки](docs/SCENE-MOVEMENT.md).

  **English:** Move the selected character or building/wreck using the native Gizmo and world coordinate fields. F9 resets position; F4 resumes character control at the edited position. Do not automatically move loot or change its physics when moving an anchor. See [behavior and validation](docs/SCENE-MOVEMENT.md).

- [x] Переработать правую боковую панель: позиция X/Y/Z и углы Roll/Pitch/Yaw показаны отдельными строками с цветными подписями, числовыми значениями и сбросом рядом. Видны только параметры активного режима. Значения отображаются с пятью знаками после точки. Названия сущности/опоры и подписи систем координат справа убраны; выделение видно в левом списке сцены. Шаги, кнопки `−/+` и пробное размещение на земле скрыты в сворачиваемой «Тонкой настройке». [Поведение и проверки](docs/COMPACT-PROPERTIES.md).

  **English:** Redesign the right sidebar with separate X/Y/Z and fully named Roll/Pitch/Yaw rows placing colored labels, values and reset icons beside each other, showing only the active mode, using five decimal places. Omit entity/anchor names and coordinate-space captions on the right; selection is visible in the left scene list. Put steps, minus/plus controls and test ground placement in collapsible Fine adjustments. See [behavior and validation](docs/COMPACT-PROPERTIES.md).

- [x] Добавить верхнюю панель инструментов: перенести в неё Движение/Поворот, переключение полёта/курсора F1, показ опоры, режим персонажа и экспорт XML выбранного предмета/всей опоры. Убрать дубли кнопок из боковых панелей и учитывать панель в границах активной области мира. [Поведение и проверки](docs/TOOLBAR.md).

  **English:** Add a top toolbar for Move/Rotate, Fly/Cursor (F1), anchor focus, character mode and selected-item/full-anchor XML export. Remove duplicate sidebar actions and account for the toolbar in the world editing bounds. See [behavior and validation](docs/TOOLBAR.md).

- [ ] **Опционально:** в режиме добавления Proxy задать границы создания предметов вокруг здания/остова, чтобы исключить размещение слишком далеко от опоры. Рассмотреть допустимую область по границам самой модели с отступом примерно **10 метров**.

  **English:** **Optional:** limit item creation in Proxy placement mode to an area around the building/wreck so items cannot be spawned excessively far from their anchor. Consider using the model bounds with an approximately **10-metre** margin.

- [x] **Опционально:** показывать превью предмета при наведении курсора на его строку в каталоге во временном всплывающем окне сбоку от списка. Задержка 250 мс; выбор в каталоге и сцене сохраняется, при перетаскивании окно закрывается. [Поведение и проверки](docs/ITEM-HOVER.md).

  **English:** **Optional:** show an item preview in a temporary popup beside the catalog when hovering over its entry. Use a 250 ms delay, preserve catalog and scene selection, and close on drag. See [behavior and validation](docs/ITEM-HOVER.md).

- [x] Локализовать названия предметов в каталоге: показывать игровые названия на языке клиента, как уже сделано для категорий. В превью показывать заголовок `Classname` и техническое имя отдельной строкой ниже. Выбор, перетаскивание и XML сохраняют точный classname; при отсутствии игрового названия показывается classname. [Поведение](docs/ITEM-CATALOG.md).

  **English:** Show client-localized item names in the catalog and a Classname heading and the technical name below it in the hover popup. Keep exact classnames for selection, dragging and XML; fall back to the classname when a display name is unavailable. See [behavior](docs/ITEM-CATALOG.md).

- [ ] **Опционально:** добавить выделение нескольких сущностей в активной области мира и их совместное перемещение. Группу для переноса пользователь формирует явным выделением.

  **English:** **Optional:** support selecting multiple entities in the active world editing area and moving them together. The user explicitly selects the entities that form the movement group.

- [ ] **Опционально:** дать возможность вращать не только предметы, но и здания/остовы и персонажей.

  **English:** **Optional:** support rotating buildings/wrecks and characters in addition to items.

- [x] Улучшить читаемость панели свойств: цветные подложки букв X/Y/Z и названий Roll/Pitch/Yaw, более крупные числа и отдельная иконка сброса каждого значения. Убрать «Применить числа»: корректный ввод применяется сразу; незавершённый или недопустимый ввод не меняет последнюю корректную позу. Сброс одного значения возвращает его к состоянию при выделении, остальные компоненты сохраняются; F9 сбрасывает всю позу. [Поведение и проверки](docs/COMPACT-PROPERTIES.md).

  **English:** Improve property readability with colored X/Y/Z and Roll/Pitch/Yaw label backgrounds, larger numeric fields and individual reset icons. Remove Apply values: valid edits apply immediately, while incomplete or invalid input leaves the last valid pose intact. Each reset restores its component to the selection baseline and preserves the other components; F9 resets the full pose. See [behavior and validation](docs/COMPACT-PROPERTIES.md).

- [x] Показывать в панели свойств только параметры активного режима: в режиме «Движение» — позицию X/Y/Z, в режиме «Поворот» — углы Roll/Pitch/Yaw.

  **English:** Show only the active mode's properties: X/Y/Z position in Move mode, and Roll/Pitch/Yaw angles in Rotate mode.

- [x] В панели свойств показывать числовое значение каждой координаты рядом с её цветной подписью X/Y/Z, на одной строке, вместо размещения значения под подписью.

  **English:** Place each position value beside its colored X/Y/Z label on the same line, rather than below the label.

- [x] В строках Roll/Pitch/Yaw придвинуть иконки сброса ближе к числовым значениям, убрав большой промежуток между значением и кнопкой.

  **English:** Move the Roll/Pitch/Yaw reset icons closer to their numeric values, removing the large gap between each value and its button.

- [ ] Активировать управление камерой по умолчанию при нажатии на активную область мира. После внедрения убрать отдельную кнопку переключения камеры с панели инструментов. В инструкции описать управление камерой и назначение кнопок.

  **English:** Activate camera controls by default when clicking the active world editing area. Once implemented, remove the dedicated camera toggle button from the toolbar. Document camera controls and key bindings in the instructions.

- [ ] **Опционально:** сделать разделы интерфейса полупрозрачными, ориентируясь на оформление Battlefield 1.

  **English:** **Optional:** make interface sections semi-transparent, taking visual inspiration from Battlefield 1.

- [ ] **Опционально:** добавить для кнопок Move и Rotate иконки в виде соответствующих Gizmo: стрелок перемещения и колец вращения.

  **English:** **Optional:** add Gizmo-style icons to Move and Rotate: translation arrows and rotation rings.

- [x] Добавить в инструкцию по инструменту создание предметов перетаскиванием: «Перетащи предмет в область мира». Описать перенос строки из каталога на поверхность внутри активной области, необходимость опоры и отмену при отпускании за границами области. Постоянная подсказка убрана из панели.

  **English:** Add item drag-and-drop creation to the tool instructions: “Drag an item into the world area”. Explain dragging a catalog entry onto a surface inside the active area, the anchor requirement and cancellation outside the area. The persistent sidebar hint is removed.

- [x] Размещать всплывающее превью чуть правее боковой панели, с видимым зазором от её внешнего края. Отступ — 12 базовых пикселей интерфейса; при размещении слева используется тот же отступ. [Поведение и проверки](docs/ITEM-HOVER.md).

  **English:** Position the hover preview from the sidebar's outer edge with a 12-base-pixel gap; use the same gap for the left-side fallback. See [behavior and validation](docs/ITEM-HOVER.md).

- [x] Выводить сообщения об ошибках в отдельном виджете: заголовок «Ошибка», многострочный текст и кнопка ×, с сохранением выделения и защитой от кликов по миру под уведомлением. [Поведение и проверки](docs/ERROR-NOTIFICATIONS.md).

  **English:** Display errors in a dedicated notification with a heading, wrapped text and close button, preserving selection and blocking world clicks through the notice. See [behavior and validation](docs/ERROR-NOTIFICATIONS.md).

- [ ] Развить отдельный виджет уведомлений для ошибок, сообщений об успехе и предупреждений. Использовать существующий виджет ошибок как основу и визуально различать три типа сообщений.

  **English:** Extend the dedicated notification widget to support errors, success messages and warnings. Build on the existing error widget and visually distinguish the three message types.

- [ ] **Опционально:** изменять координаты и углы перетаскиванием мыши по числовому полю, как у слайдера. Сохранить возможность точного ввода с клавиатуры.

  **English:** **Optional:** adjust coordinate and angle values by dragging over the numeric input like a slider, while retaining precise keyboard entry.

- [ ] Добавить Undo и Redo — отмену и повтор действий в редакторе.

  **English:** Add Undo and Redo for editor actions.

- [ ] Обеспечить управление высотой камеры в режиме полёта: **Q — поднимать камеру, Z — опускать**.

  **English:** Ensure vertical camera controls in flight mode: **Q moves the camera up, Z moves it down**.
