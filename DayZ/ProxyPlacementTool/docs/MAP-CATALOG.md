# Object catalog tree

Current source builds use an expandable **Objects → map → category → classname** tree in the left panel. Map branches are **ChernarusPlus**, **Livonia**, **Sakhal** and **Nasdara**; there is no Common branch. **Other** keeps classes with no recognized map association accessible. Categories come from the loaded model paths, including Residential, Industrial, Military, Underground, Wrecks, Furniture, Roads, Rail and Uncategorized. Only populated categories are shown.

Click a folder to expand/collapse it, or select it and press Enter. Click a classname to choose the object for creation. A folder never becomes a spawn classname. Existing scene objects and editor selection are unaffected by catalog navigation. Objects have no 100-result cap: collapsed branches keep the initial view short. The counter counts unique classnames, so a shared object shown under several maps is counted once.

Classname search covers the whole loaded object catalog, ignores case and surrounding spaces, reveals matching ancestors and hides unrelated branches. Search results can also be collapsed. Clearing the search restores the previous expansion state. The [Items tab](ITEM-CATALOG.md) has its own category/subcategory tree without a 100-row limit; switching tabs preserves each tree's expanded branches.

**Show StaticObj** is off whenever a new editor starts. It filters only classnames beginning with `StaticObj_` (case-insensitive). Hidden classes are excluded from search and all object/category counts; empty categories disappear. Toggling preserves expanded branches and clears a selected classname if it becomes hidden. The checkbox is hidden on Items and retains its state when switching tabs. Existing scene objects and exact manual classname entry are unaffected.

Wrecks have another level: **Ground vehicles**, **Aircraft**, **Ships and boats**, **Rail vehicles** and **Other wrecks**. Vehicles/Wheeled/Tracked resource folders share Ground vehicles. Aircraft, Ships and Trains use their matching folders. Recognized Sakhal models stored directly under Wrecks are classified by model filename (including submarines under Ships and boats); unfamiliar layouts stay in Other wrecks. Empty subcategories are hidden. Search reveals the extra level, and the parent Wrecks count includes all nested objects. StaticObj filtering applies at every level.

Ground vehicles have type folders: **Truck**, **Sedan**, **Offroad**, **Hatchback**, and **Other ground vehicles**. Known model stems drive classification: truck/V3S/Ural/ArmedUral/MTVR/Mining_HaulTruck use Truck; sed01/sed02 families use Sedan; offroad/hb01/UAZ/HMMWV/LR use Offroad; hb02 uses Hatchback. Other models (including trailers, tracked vehicles, buses and unrecognized families) remain accessible in Other ground vehicles. This is a catalog grouping; classnames and spawn behaviour stay unchanged. Search, aggregate counts, expansion state and StaticObj filtering include this level.

Residential has subcategories **Sheds**, **Office**, **Misc**, **House**, **City**, **Tenements**, **Stores**, **Medical**, **Police**, **Schools**, **FireDep**, **Bus**, **Slums**, **Platforms**, **Terraces**, and **Other residential objects**. These use the model's Residential subfolder. City collects HouseBlocks/city folders and models whose filename starts with City_ (including City_ variants otherwise stored in Medical, Stores or FireDep). Unrecognized paths go to Other. Only populated subcategories are shown; counts, search, folder expansion and StaticObj filtering cover the extra level.

## Map association and categories

1. For known static CE groups, membership comes from each official terrain's `ce/mapgrouppos.xml`. Shared classes appear under every map that uses them.
2. For classes absent from those CE files, association falls back to the model's resource family: base `DZ/structures`, `plants`, `rocks` and `water` use ChernarusPlus; `_bliss` uses Livonia, `_sakhal` uses Sakhal, `_takistan` uses Nasdara. `DZ/worlds/<terrain>` is also recognized. This fallback describes the asset family, not verified placement on a particular terrain.
3. Models from unrecognized sources stay under Other. Unrecognized category paths use Uncategorized. No loaded anchor class is discarded.

This catalog does not switch the test terrain, modify already-created objects or change exported XML. Manually entering an exact classname still uses the complete loaded catalog. It does not bypass the game's asset availability or DLC requirements.

`map-catalog-sources.json` records the four CE input hashes, counts and generated source hash. The current inputs were read from installed official DayZ terrain files. Source author: **Bohemia Interactive**. Related official repository: [DayZ Central Economy](https://github.com/BohemiaInteractive/DayZ-Central-Economy). The derived CE membership dataset follows [ADPL-SA](https://www.bohemia.net/community/licenses/arma-and-dayz-public-license-share-alike-adpl-sa).

To refresh from an extracted official `DZ/worlds` directory:

```powershell
.\tools\Update-MapCatalog.ps1 -WorldsRoot 'X:\DayZModding\DZ\worlds'
.\tools\Build.ps1 -Tools 'X:\SteamLibrary\steamapps\common\DayZ Tools'
```

The generated `IOTMapCatalog.c` is packed with the addon. Model categories and resource families are read from the client's loaded configuration at runtime. No external game XML or network request is needed while editing.

## По-русски

В левой панели — дерево **Объекты → карта → категория → classname**, без Common. Щелчок раскрывает папку, выбор classname подготавливает объект к созданию. Можно также раскрывать выбранную папку клавишей Enter. Общие здания встречаются в нескольких ветках карт. Состояние раскрытых веток сохраняется при переходе к предметам и обратно.

Поиск выполняется по полному каталогу и раскрывает путь к найденным объектам. Пустые категории не показываются; папки не выбираются как классы для создания. Ограничения в 100 объектов у дерева нет. Счётчик учитывает уникальные classnames, независимо от количества веток, где они отображаются.

Для классов из CE карты определяются по штатным статическим группам лута. Для остальных используется семейство ресурсов модели; базовые ресурсы идут в ChernarusPlus. Это принадлежность ресурса, а не доказательство его размещения на карте. Неопределённые объекты остаются в «Прочее», неизвестные категории — в «Без категории». Каталог охватывает все загруженные классы зданий/остовов, включая объекты без лута. Тестовый мир и экспорт не меняются.

Чекбокс «Показывать StaticObj» при новом запуске выключен. Он скрывает классы с префиксом StaticObj_ из дерева, поиска и счётчиков. Раскрытые ветки сохраняются, пустые категории исчезают. На вкладке предметов чекбокс скрыт; выбранное состояние сохраняется при переходе между вкладками. Уже созданные объекты остаются в сцене.


Внутри «Остовы» добавлены «Наземная техника», «Авиация», «Суда и лодки», «Железнодорожная техника» и «Прочие остовы». Распределение идёт по папкам моделей; для Сахала также учитываются известные имена моделей без подпапок. Части подлодки относятся к судам. Счётчик родительской категории включает все подкатегории, поиск раскрывает полный путь, фильтр StaticObj применяется ко всем уровням.


В «Наземная техника» добавлены «Грузовики», «Седаны», «Внедорожники», «Хэтчбеки» и «Прочая наземная техника». hb01 относится к внедорожникам, hb02 — к хэтчбекам. Неизвестные семейства, автобусы, прицепы и гусеничная техника остаются в прочем. Поиск раскрывает новый уровень, счётчики суммируют его содержимое, StaticObj фильтруется как прежде.


«Жилые здания» разбиты по семействам моделей: сараи, офисы, разное, дома, городские здания, многоквартирные дома, магазины, медицинские здания, полицейские участки, школы, пожарные части, автостанции и остановки, трущобы, платформы, террасы и прочие жилые объекты. City объединяет HouseBlocks и модели City_*. Пустые ветки скрыты; поиск раскрывает полный путь, счётчик родителя суммирует подкатегории, StaticObj по умолчанию скрыт.
