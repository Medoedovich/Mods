# PARTISAN_TEAM

[Группы ИИ — сводка](../Summary.md)

Фракция: **FIA**. Состав: **5 бойцов**. Порог случайного отбора: **0.3** (не независимая вероятность появления).

Prefab: `{DB3D2D4FC5922C6A}Prefabs/Groups/INDFOR/AmbientPatrols/Group_FIA_PartisanTeam_NotSpawned.et`.

## Вооружение группы

| Оружие | Количество |
| --- | ---: |
| ПМ | 5 |
| Vz. 58 V | 2 |

## Состав бойцов

| Prefab бойца | Количество | Оружие у каждого | Тип гранаты в слоте |
| --- | ---: | --- | --- |
| Character_FIA_AC_Partisan | 2 | Vz. 58 V; ПМ | — |
| Character_FIA_AC_Partisan_Grenadier | 1 | ПМ | РГД-5 |
| Character_FIA_AC_Medic | 1 | ПМ | — |
| Character_FIA_AC_Scout | 1 | ПМ | — |

Вооружение прочитано из унаследованных CharacterWeaponSlotComponent.WeaponTemplate; повторяющиеся бойцы учитываются отдельно. Тип гранаты — шаблон CharacterGrenadeSlotComponent, а не количество гранат. Боезапас, содержимое одежды и изменения после появления здесь не суммируются; это конфигурация префабов, не измеренный боевой состав.

[Оружейные слоты, начальный оружейный инвентарь и происхождение](../Weapons.json).

[Исходные ресурсы и значения](../Groups.json).
