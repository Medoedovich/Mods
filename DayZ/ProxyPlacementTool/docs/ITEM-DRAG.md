# Drag items from the catalog / Перетаскивание предметов из каталога

## English

Create or select an anchor, open **Items**, then drag an actual classname row from the catalog onto a surface inside the world editing frame. Release the left mouse button to create and select the item there. A floating label shows the classname and whether the current drop target is valid.

- A normal click selects a catalog entry; it does not create an item. Category rows and the scrollbar are not spawn sources.
- Releasing outside the world area or over the sky cancels creation. Surface picking reaches up to 100 metres from the camera.
- The model bounds offset the new item from its contact surface. Use the stock Gizmo or precise fields to adjust the result.
- Repeated drops create separate items, including repeated copies of one classname. There is no tool-imposed scene item count limit.
- Each new item belongs to the active anchor, appears in the created-item tray and is included in its CE XML export.
- While dragging a catalog item, the previously selected item remains selected and its Gizmo is suspended. Cancelling restores it; a successful drop selects the new item.
- Switching to flight or character mode, opening a game menu or losing application focus cancels the catalog drag.

The item creation button and permanent drag hint are removed; documenting the drag workflow in the tool instructions is tracked in TODO. Buildings and wrecks also use drag-and-drop, with confirmation before replacing the single anchor; see [anchor placement](ANCHOR-DRAG.md). Item models are shown by the [hover preview](ITEM-PREVIEW.md); the drag label remains textual.

Validation on 14 November 2026: **177 scripted checks per language** in Russian and English, including **24 item drag checks**, using an unpacked Test Range mission. Native UI dragging created repeated Hammer items and cancelled a drop over the panel without increasing the scene count. The author confirmed that dragging a previously unselected SledgeHammer row creates and selects SledgeHammer. No new PBO was built.

## Русский

Создайте или выберите опору, откройте «Предметы» и перетащите строку с конкретным classname из каталога на поверхность внутри рамки редактирования мира. Отпустите левую кнопку мыши — предмет создастся в этом месте и будет выбран. Подпись рядом с курсором показывает classname и допустимость создания в текущей точке.

- Обычный щелчок только выбирает запись каталога. Папки категорий и полоса прокрутки не создают предметы.
- Отпускание за рамкой или над небом отменяет создание. Поверхность ищется на расстоянии до 100 метров от камеры.
- Положение учитывает границы модели, чтобы предмет не оказался внутри поверхности. Дальше его можно двигать и вращать штатным Gizmo или числовыми полями.
- Повторные перетаскивания создают отдельные предметы, включая копии одного classname. Ограничение количества предметов в сцене инструментом не вводится.
- Каждый новый предмет привязывается к активной опоре, появляется в нижнем списке и включается в её экспорт CE XML.
- При переносе записи каталога предыдущий предмет сохраняет выделение, а его Gizmo временно отключается. Отмена возвращает ручки; успешное создание выбирает новый предмет.
- Переход к полёту или персонажу, открытие игрового меню и потеря фокуса приложения отменяют перенос из каталога.

Кнопка создания предмета и постоянная подсказка перетаскивания убраны; описание переноса в инструкции по инструменту внесено в TODO. Здания и остовы также создаются перетаскиванием, с подтверждением замены единственной опоры: [подробнее](ANCHOR-DRAG.md). Модель предмета показывает [превью при наведении](ITEM-PREVIEW.md); подпись при перетаскивании остаётся текстовой.

Проверка от 14 ноября 2026 года: **по 177 программных проверок на русском и английском**, включая **24 проверки перетаскивания предметов**, в обычной миссии Test Range без упаковки. В интерфейсе проверены повторные переносы Hammer и отмена при отпускании на панели без увеличения количества предметов. Автор подтвердил, что перенос ранее не выбранной строки SledgeHammer создаёт и выбирает именно SledgeHammer. Новый PBO не собирался.
