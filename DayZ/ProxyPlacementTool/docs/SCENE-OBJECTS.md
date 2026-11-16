# Scene Objects / Объекты на сцене

## English

The compact **Scene Objects** panel occupies the bottom of the left column, below the creation catalog. It replaces the bottom item cards and their four-item pages with a native scrollable list. The center world input area now extends to the bottom margin.

The heading uses the same 21-point style as Create. Scene rows are 24 base UI pixels high, matching catalog item rows; four rows fit at once and the native scrollbar reveals the remaining entries.

- The character, editor-registered buildings/wrecks and created items are separate rows at the same level. Items follow creation order independently of their anchor ownership.
- Item and anchor rows show classnames without visible IDs or indentation. Repeated classnames remain separate entries linked to their exact game entities.
- Clicking an item selects that exact instance and shows the native movement/rotation Gizmo. If it belongs to another anchor, the editor activates and focuses that anchor.
- Clicking an anchor row activates and focuses it, clears item selection and enables the anchor's movement Gizmo. See [scene movement](SCENE-MOVEMENT.md).
- Clicking **Character** focuses the camera on the character and enables its movement Gizmo. The current anchor remains active. **F4** still switches between camera editing and character control.
- World selection and the list stay synchronized. New selections are revealed; periodic updates refresh existing rows in place to preserve manual scrolling.
- Items taken into inventory remain listed with the inventory suffix and cannot be selected for world manipulation. Catalog preview entities are never included.
- The heading is static, with no element count. The panel hides in character mode and returns with the editor. Clicking its rows does not select objects behind the panel.

Existing multi-anchor sessions are preserved. This UI change does not implement the separate single-anchor restriction or building/wreck drag workflow in TODO.

Technical validation on 14 November 2026 used an unpacked Test Range mission with the Russian interface: **209 checks**, including **22 scene-list checks**. Checks cover flat rows, plain labels, duplicate item selection, character focus without entering character control, anchor ownership, panel geometry and existing preview/drag/XML workflows. Visual inspection of this revision is pending the author's check; English runtime validation is deferred until the Workshop release under [validation rules](VALIDATION.md). No new PBO was built.

Manual checklist: verify the static heading and flat rows; select the wheel and use its native Gizmo; create two Hammer items and select each separately; click Character to focus it, then select an item again; use F4 to check that the scene panel hides and returns normally.

## Русский

Компактная панель **«Объекты на сцене»** расположена внизу левой колонки, под каталогом создания. Она заменяет нижние карточки и страницы по четыре предмета обычным списком с прокруткой. Активная область мира в центре теперь продолжается до нижнего поля экрана.

Заголовок использует тот же размер 21, что и «Создание». Высота строк — 24 базовых пикселя интерфейса, как у предметов каталога: одновременно видны четыре строки, остальные доступны прокруткой.

- Персонаж, зарегистрированные редактором здания/остовы и созданные предметы показаны отдельными строками на одном уровне. Предметы следуют в порядке создания независимо от своей опоры.
- У предметов и опор показаны classnames без видимых ID и отступов вложенности. Одинаковые classnames остаются отдельными строками, связанными с конкретными экземплярами в мире.
- Щелчок по предмету выбирает точный экземпляр и показывает штатный Gizmo движения/поворота. Если он относится к другой опоре, редактор переключается на неё и направляет камеру.
- Щелчок по опоре делает её активной, направляет камеру, снимает выделение предмета и включает Gizmo перемещения опоры. См. [перемещение объектов сцены](SCENE-MOVEMENT.md).
- Щелчок по строке **«Персонаж»** направляет на него камеру и включает его Gizmo перемещения. Текущая опора остаётся активной. **F4** по-прежнему переключает редактор и управление персонажем.
- Выбор в мире и списке синхронизирован. Новое выделение становится видимым; периодическое обновление меняет существующие строки на месте, сохраняя ручную прокрутку.
- Взятые в инвентарь предметы остаются в списке с соответствующей пометкой и недоступны для перемещения в мире. Временные модели превью каталога не включаются.
- Заголовок постоянный, без количества элементов. Панель скрывается в режиме персонажа и возвращается с редактором. Щелчки по строкам не выбирают объекты за панелью.

Поддержка существующих сеансов с несколькими опорами сохранена. Ограничение одной опорой и перетаскивание зданий/остовов остаются отдельными задачами TODO.

Техническая проверка от 14 ноября 2026 года в миссии Test Range без упаковки и с русским интерфейсом: **209 проверок**, включая **22 проверки списка сцены**. Проверены плоские строки, подписи без ID, выбор одинаковых предметов, фокусировка на персонаже без перехода к управлению им, привязка к опоре, геометрия панелей и прежние сценарии превью/перетаскивания/XML. Визуальная проверка этой редакции ожидает проверки автором; английский интерфейс проверяется перед релизом в Workshop по [правилам проверки](VALIDATION.md). Новый PBO не собирался.

Чеклист для самостоятельной проверки: постоянный заголовок и строки без вложенности; выбор колеса и работа штатного Gizmo; создание двух Hammer с выбором каждого отдельно; фокусировка по строке «Персонаж» и повторный выбор предмета; скрытие и возврат панели при переключении через F4.
