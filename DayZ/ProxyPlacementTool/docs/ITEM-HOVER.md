# Item hover preview / Превью при наведении

## Русский

В разделе **«Предметы»** наведи курсор на строку предмета и задержи примерно на **0,25 секунды**. Сбоку от списка появится окно с 3D-моделью, заголовком **Classname** без двоеточия и полным техническим именем ниже. Для имени выделен многострочный блок с переносом; окно стало выше, размер области модели сохранён. Игровое название видно в списке и в превью не дублируется. Щелчок не требуется. Позиция окна ограничена границами экрана.

- Наведение не меняет выбранную строку каталога, выбранный предмет сцены, его положение или Gizmo. Щелчок выбирает строку для перетаскивания; отдельная карточка под каталогом и создание модели по клику удалены.
- При быстром проходе по строкам промежуточные модели не создаются. Пока курсор остаётся на одном предмете, его модель используется повторно.
- Категории, пустое место и полоса прокрутки не показывают модель. После прокрутки определяется фактическая строка под курсором.
- Колёсико прокручивает каталог по одной строке за шаг. При прокрутке прежнее превью закрывается, затем определяется новая строка под курсором; выбор в каталоге сохраняется.
- Окно закрывается при уходе с предмета, начале перетаскивания, поиске, переключении раздела, скрытии каталога, полёте камеры, режиме персонажа, открытом игровом меню или потере фокуса приложения.
- Для просмотра опора не нужна. Создание предмета на сцене по-прежнему требует активной опоры.
- Временное окно не редактирует сцену; его видимая область исключается из ввода по миру. Чтобы создать вещь, перетаскивай строку каталога в активную область.
- Превью размещается от внешнего края боковой панели с зазором 12 базовых пикселей интерфейса. Если окно размещается слева, отступ также считается от края панели, а не от вложенного списка.

Для наведения строки предметов представлены собственными виджетами внутри штатного ScrollWidget. Проверка использует их реальные экранные координаты после прокрутки, без изменения выбора ради определения строки. Раздел «Объекты» сохраняет прежний список.

Используется штатный ItemPreviewWidget. Хранится одна временная локальная модель для наведённого предмета: без сохранения, под картой, без физического тела и с отключённой симуляцией. Она не добавляется в сцену или XML. При очистке просмотрщик сначала освобождает ссылку на модель, затем временный объект удаляется.

Исправление от 15 ноября 2026 года: всплывающий просмотрщик использует отдельный WindowWidget вместо корневой цветной панели. Окно получает конечные координаты и становится видимым до подключения модели; неизменившаяся геометрия не задаётся повторно каждый кадр. Вручную подтверждена видимая 3D-модель Hammer и SledgeHammer при наведении без смены выбранного предмета сцены.

Для самостоятельной проверки:

1. Открой «Предметы», найди Hammer. Не щёлкая, наведи курсор на SledgeHammer: появится именно кувалда, выбор останется прежним.
2. Наведи на категорию, полосу прокрутки и пустое место: окно должно исчезнуть.
3. Найди AK, прокрути список и проверь соответствие модели строке под курсором.
4. Перетащи SledgeHammer на сцену без предварительного отдельного щелчка: окно закроется, создастся кувалда.
5. Включи полёт или режим персонажа: всплывающее окно должно закрыться.

Визуальную проверку выполняет автор. Проверка английского интерфейса отложена до релиза в Workshop; при разработке используется русская миссия без упаковки в PBO.

## English

In **Items**, hover over an item row for approximately **250 ms**. A popup beside the list shows its native 3D model, a **Classname** heading without a colon and the full technical name below it, without requiring a click. The name uses a wrapping block; popup height increases while the model area keeps its size. Localized item names remain in the list and are not repeated in the popup. Hovering preserves catalog selection, scene selection, placement and Gizmo state. Clicking selects the catalog entry for dragging; the separate selected-item card and its preview creation path are removed.

The popup closes when leaving an item, starting a drag, changing the search or catalog mode, hiding the catalog, entering camera flight or character mode, opening a game menu or losing application focus. Folders, empty space and the scrollbar do not produce models. It uses the real row widget positions after scrolling and stays within screen bounds. Previewing requires no anchor; scene creation still requires one.

Item rows use native widgets inside a ScrollWidget so pointer hit testing does not need to change selection. The Objects list is unchanged. At most one temporary local hover entity is retained. It uses the native ItemPreviewWidget, remains below the map without physics or persistence, and is excluded from scene ownership and XML export. Clearing detaches the renderer before deleting the entity.

The popup is placed from the sidebar's outer edge with a 12-base-pixel gap. The left-side fallback uses the same outer-edge offset rather than the inset list bounds.

The author performs visual review. English runtime validation is deferred until the Workshop release; development checks use an unpacked Russian mission.

Rendering fix on 15 November 2026: use a standalone WindowWidget, establish its final visible bounds before binding the model, and avoid resetting unchanged geometry each tick. Targeted UI inspection confirmed visible Hammer and SledgeHammer models in the hover popup while preserving scene selection. English runtime validation remains deferred until release.

Проверка шага колёсика на штатном ScrollWidget подтвердила сдвиг на одну строку вниз и обратно без смены выбранного classname. Маршрутизацию колёсика обычной мышью проверяет автор.

Техническая проверка от 15 ноября 2026 года: **263 проверки прошли**, включая **15 проверок наведения** и соответствие локализованных названий каталога игровым именам из трёх разделов конфигурации. Проверены задержка, независимость от выбора, повторное использование модели, быстрые переходы, прокрутка, границы окна, очистка и совместимость с перетаскиванием. Вместе с ними прошли прежние проверки Gizmo, режимов, каталогов и XML. Точечная визуальная проверка отрисовки Hammer и SledgeHammer выполнена после исправления пустого окна; визуальную проверку новых подписей выполняет автор.

The native ScrollWidget check confirmed a one-row downward step and return without changing the selected classname. Real mouse-wheel event routing is left for the author to check.

Technical validation on 15 November 2026: **263 checks passed**, including **15 hover checks** and native localized catalog names across three configuration roots, in an unpacked Russian mission. Existing Gizmo, modes, catalog and XML regressions also passed. Targeted visual checks of visible Hammer and SledgeHammer models passed after the rendering fix; visual review of the new labels is left to the author.
