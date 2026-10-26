# Завершение карты в официальном Terrain Builder

Проект уже сохранён как `P:\dtr\test_range\source\dayztestrange.tv4p`, растры импортированы, terrain перестроен, слои сгенерированы и WRP экспортирован. Ниже описан порядок регенерации. Вместе с TV4P сохраняйте соседние V4D, V4W и каталоги проекта; один TV4P не содержит весь terrain.

## Параметры Mapframe

| Поле | Значение |
|---|---|
| Name | DayZ Test Range |
| Output root | P:\dtr\test_range |
| UTM | 31 N |
| Easting / Northing | 200000 / 0 |
| Terrain grid / cell | 256×256 / 4 м |
| Terrain size | 1024×1024 м |
| Satellite/mask | 1024×1024 px, 1 м/px |
| Tile size / desired overlap | 512×512 / 256 px |
| Texture layer | 16×16 м |
| Layers config | P:\dtr\test_range\source\layers.cfg |

При этих параметрах TB рассчитывает actual overlap=256 px, final satellite grid=64 cells (256 м), 4×4 тайла. Мир 1024 м делится на шаг тайлов без остатка; красного предупреждения о частично покрытых крайних тайлах быть не должно. Не используйте прежнее desired overlap=16 px: оно давало шаг 384 м и 3×3 тайла с частичным покрытием края. Размер heightmap остаётся 256×256 с ячейкой 4 м.

## Импорт

1. File → Save As: `P:\dtr\test_range\source\dayztestrange.tv4p`. Все соседние V4D/V4W/Cache, созданные TB, сохраняйте вместе с TV4P.
2. Для нового проекта File → Import → Terrain: `P:\dtr\test_range\source\heightmap.asc`. Это ESRI ASCII DEM 256×256, cellsize=4, XLL=200000, YLL=0. Внешняя строка/столбец = −20.000000, остальные отсчёты = 1.000000. Ровные узлы X/Z=4…1016. Высота +1 м — абсолютная, выбранная пользователем. Дробная запись обязательна для проверенной версии TB: целые значения вызвали ошибку CCommonMapImporter::ConvertDataValue и зависание. В layers/raster manager проверьте совпадение слоя с mapframe. Если ASC уже импортирован и изменился на диске, используйте контекстное меню его слоя → Refresh content from source, затем Rebuild terrain; повторный импорт не нужен.
3. File → Import → Satellite image: `P:\dtr\test_range\source\sat_lco.png`.
4. File → Import → Surface mask: `P:\dtr\test_range\source\mask_lco.png`.
5. При необходимости можно импортировать спутниковую нормаль `normal_lco.png`; поставляемая версия её не экспортирует.
6. Рядом с PNG поставляются стандартные PGW: масштаб 1 м/px, верхний левый центр пикселя (200000.5, 1023.5). Если импортируете изображения без PGW, задайте в свойствах слоя левый нижний угол Easting=200000, Northing=0 и размер 1024×1024 м. Проверьте совпадение границ слоёв с mapframe.

## Генерация и экспорт

1. Откройте Mapframe properties → Processing.
2. Проверьте layers.cfg выше, снимите `(DEBUG) Store suffix(DEBUG)`.
3. Нажмите Rebuild terrain уже с импортированной ASC. Подтвердите замену только рельефа этого нового проекта. Проверьте высоту 1 м в центре.
4. Отметьте Export satellite texture и Export surface mask. Выберите 4 materials per cell. Save RVMAT files in ASCII format должен быть отмечен. Спутниковая нормаль не обязательна.
5. Можно отметить Convert exported textures into *.paa: конвертацию выполнит официальный конвертер. Если не отмечено, подготовленные PNG преобразует Addon Builder с `-binarizeAllTextures`.
6. Generate layers. Должны появиться реальные файлы в `P:\dtr\test_range\data\layers`: 16 RVMAT, 16 спутниковых и 16 mask tiles. Не создавайте эти RVMAT вручную.
7. OK, File → Save.
8. File → Export → WRP: `P:\dtr\test_range\world\dayztestrange.wrp`.
9. Убедитесь, что Total object count = 0. Не импортируйте библиотеки или объекты Utes.
10. В корне проекта выполните `tools\Sync-WorkDrive.ps1 -Pull`, затем `tools\Build.ps1`.

Если TB предлагает автоматически создать корневой config.cpp, не заменяйте им подготовленный `world\config.cpp`. Путь worldName в поставляемой конфигурации уже соответствует указанному WRP. Корневая конфигурация для редактора может храниться отдельно, но пакуется только папка world.

## Buldozer

Для preview задайте в Tools → Preferences → Buldozer установленный `D:\SteamLibrary\steamapps\common\DayZ\DayZ_x64.exe`, параметры `-buldozer -window -nopause -mod= -profiles=P:\Buldozer -name=Buldozer`, Data directory `P:\`. В Tools → Settings → User settings также Data directory `P:\`. Дождитесь завершения Extract Game Data.

Никакие EXE, DLL или файлы в установленную игру этот проект не копирует. Официальный бинарный WRP должен получиться из TB, затем пройти Binarize; наличие экспортированного WRP ещё не заменяет проверку готового мода в игре.
