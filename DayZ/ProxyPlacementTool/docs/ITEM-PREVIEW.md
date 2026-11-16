# Item previews / Превью предметов

## English

Item previews are shown only in the [hover popup](ITEM-HOVER.md). Hover over an Items catalog row for approximately 250 ms to see its native 3D model, a Classname heading and a separate wrapping technical-name block. The localized name is shown only in the catalog list.

Clicking selects the catalog entry for dragging. It does not create a separate preview model or show a card below the catalog. The catalog panel uses the available height above Scene Objects, with the extra space given to the list. At most one temporary preview entity is retained, owned by the hover popup.

Technical validation on 15 November 2026: **263 checks passed** in an unpacked Russian mission. Catalog names match native entity display names for a canister, wheel, firearm, ammunition and clothing across CfgVehicles, CfgWeapons and CfgMagazines; exact classnames are preserved for dragging. Hover coverage also checks model/view, isolation, cleanup, scrolling and selection. English runtime validation is deferred until the Workshop release.

## Русский

Превью предметов показывается только во [всплывающем окне при наведении](ITEM-HOVER.md). Наведи курсор на строку в «Предметах» примерно на 250 мс, чтобы увидеть 3D-модель, заголовок Classname без двоеточия и многострочный блок технического имени под ним. Игровое название остаётся только в списке каталога.

Щелчок выбирает строку каталога для перетаскивания. Он не создаёт отдельную модель превью и не показывает карточку под списком. Панель каталога занимает доступную высоту над списком сцены; дополнительное место отдано каталогу. Хранится не более одной временной модели — для окна наведения.

Техническая проверка от 15 ноября 2026 года: **263 проверки прошли** с русским интерфейсом в миссии без упаковки. Названия в каталоге совпали с игровыми именами канистры, колеса, оружия, патронов и одежды из CfgVehicles, CfgWeapons и CfgMagazines; перетаскивание сохранило точные classnames. Проверены также модели и виды превью, изоляция, очистка, прокрутка и выделение. Английский интерфейс проверяется перед релизом в Workshop.
