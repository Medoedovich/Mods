# Измерение стартового боезапаса персонажей 1.8.0.13

Скопировать ME_CA_AIInventoryProbe.c в Scripts/Game отдельного временного проекта, зависящего только от базовой игры (58D0FB3206B6F859). В обычный мод этот скрипт не включать. Он создаёт 17 тестовых персонажей последовательно на 4900 29 11790, ждёт 500 мс, читает инвентарь, затем удаляет только созданного персонажа вместе с его снаряжением. Не сохраняет сцену и не изменяет исходные prefab.

Запуск ArmaReforgerSteamDiag.exe из каталога игры с отдельным -profile и параметрами:

```text
-gproj "<temporary-project>/addon.gproj" -addonsDir "<game>/addons" -profile "<temporary-profile>" -world "worlds/MP/CTI_Campaign_HQC_Eden.ent" -worldSystemsConfig "{7C9E720397CC6ACD}Configs/Systems/ConflictSystems.conf" -maxFPS 30 -forceUpdate -noFocus -CA_AI_Inventory
```

Использовать скрытый процесс, записать его PID и после COMPLETE|17 завершить только его. MissionHeader не загружается: опыт проверяет создание отдельных префабов, а не штатное появление группы через систему патрулей. Первый запуск без forceUpdate остановился после BEGIN и не использован. Принят только завершённый второй запуск без ошибок самой пробы. Общие предупреждения мира не выдаются за ошибку или подтверждение состояния инвентаря.

GetItems получает управляемые предметы; GetMuzzlesList / GetMagazine определяют вставленные магазины. Перед записью предметы объединяются по идентичности IEntity: магазин, найденный обоими способами, учитывается один раз. GetAmmoCount / GetMaxAmmoCount читаются у магазина, IsCurrentBarrelChambered — у ствола. Патроны в патронниках стрелкового оружия считаются отдельно. GetGrenadesCount сохранён как отдельное значение API; итог ручных и дымовых гранат вычисляется по уникальным предметам, а не прибавлением шаблонов CharacterGrenadeSlotComponent.

Фильтр магазинов — Prefabs/Weapons/Magazines/, гранат — Prefabs/Weapons/Grenades/. Коробки пулемёта входят в магазины. Ракеты и сигнальные средства сохранены в исходных runtime-записях Ammunition.json, но не входят в эти итоги. После завершения процесса передать console.log как InventoryRuntimeLogPath генератору New-AIGroupsReport.ps1. Полные журналы и игровые исходники не публиковать.

API сверялся с [MagazineComponent](https://community.bistudio.com/wikidata/external-data/arma-reforger/ArmaReforgerScriptAPIPublic/interfaceMagazineComponent.html), [InventoryStorageManagerComponent](https://community.bistudio.com/wikidata/external-data/arma-reforger/ArmaReforgerScriptAPIPublic/interfaceInventoryStorageManagerComponent.html), [WeaponComponent](https://community.bistudio.com/wikidata/external-data/arma-reforger/ArmaReforgerScriptAPIPublic/interfaceWeaponComponent.html). Параметр фонового обновления — [forceUpdate](https://community.bohemia.net/wiki/Arma_Reforger%3AStartup_Parameters?useskin=darkvector). Численные результаты взяты из установленной игры 1.8.0.13, а не веб-справочников.
