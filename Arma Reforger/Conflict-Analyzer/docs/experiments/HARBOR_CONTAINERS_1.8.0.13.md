# Проверка контейнеров доков — 1.8.0.13

Отдельная read-only сессия CTI_Campaign_HQC_Eden со штатным MissionHeader `{0220741028718E7F}Missions/23_Campaign_HQC_Everon.conf`. Проба завершена с COMPLETE; 18 инициализированных доков в замерах на 30-й и 45-й секундах от OnGameStart. Для представления выбран второй замер. Полные результаты: [JSON](HARBOR_CONTAINERS_1.8.0.13.json).

Проба читает генератор DEFAULT/SUPPLIES каждого дока и ресурсные контейнеры поблизости. Радиус QueryEntitiesBySphere 300 м нужен только для диагностического поиска, игровой GetResourceGridRange у всех 18 генераторов равен 100 м. Она не вызывает RequestGeneration, UpdateInteractor, RegisterContainer или сохранение мира.

Для каждого слота записаны координаты, физический/виртуальный вид, IsInRange, IsIsolated, CanInteractWith и IsInteractorLinked. IsInRange в установленном SCR_ResourceContainer.c использует `Math3D.IntersectionSphereAABB(origin - m_Owner.GetOrigin(), range, mins, maxs)` с GetBounds сущности. Поэтому это не только проверка расстояния до её точки.

Сопоставление с editor source: точный ID сущности, вид контейнера и индекс слота; при отсутствии точного ID — уникальный prefab, вид, индекс и позиция в пределах 0.03 м. Неоднозначность останавливает генератор. При точном ID изменение координат не скрывается: сдвиг сохраняется отдельно. Пустой runtime prefab у вложенного объекта не заменяется придуманным значением. Динамические и иные несопоставленные записи остаются в JSON.

В этой сессии связь с генератором не наблюдалась. Это не ошибка подключения: проба не заставляет генератор обновлять очередь, а периодическое пополнение не измерялось. Физические ящики могут быть изолированы из-за инкапсуляции, тогда взаимодействие возможно через виртуальное представление. Запасы виртуальных представлений не добавляются повторно к физическим.

## Повторение

Исходник [ME_CA_HarborProbe.c](../../tools/experiments/ME_CA_HarborProbe.c) — диагностическая модификация только для отдельного тестового addon, не часть рабочего addon. Создать отдельный проект с GUID B8F6E397105D4C2A и зависимостью 58D0FB3206B6F859, положить исходник в Scripts/Game и использовать отдельный профиль. Запуск ArmaReforgerSteamDiag.exe с `-gproj`, `-addonsDir`, `-profile`, `-world worlds/MP/CTI_Campaign_HQC_Eden.ent`, `-worldSystemsConfig {7C9E720397CC6ACD}Configs/Systems/ConflictSystems.conf`, `-ME_CA_NativeScenario`. Требуется работающий Steam. Дождаться обоих SAMPLE_END и COMPLETE без script errors; не считать неполную пробу результатом. Скрипт не завершает игру автоматически.

В сборке справочника передать `-HarborRuntimeReportPath docs/experiments/HARBOR_CONTAINERS_1.8.0.13.json`. Без параметра геометрическая проверка сохраняется, поля игровых проверок явно «не измерено».

Исходные логи, профиль и извлечённый код игры в Git не входят; SHA-256 лога и пробника сохранены в JSON. Это наблюдение одной версии и сессии, не гарантия поведения после захвата базы или обновления игры.

После завершения тестовой сессии преобразовать лог командой tools/experiments/Convert-HarborRuntimeLog.ps1 с параметрами -LogPath, -LaunchMetadataPath и -OutputPath. LaunchMetadataPath — JSON с полем StartedUTC, записанным при запуске соответствующего процесса. Конвертер проверяет COMPLETE, версию, штатный MissionHeader, отсутствие script errors, два замера по 18 доков и полные тройки SLOT/CHECK/PREFAB. Затем передать результат генератору через HarborRuntimeReportPath.
