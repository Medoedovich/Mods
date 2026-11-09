# Локации и объекты в радиусе 1000 м

## Summary

Локаций с объектами: **150**. Всего именованных локаций в JSON: **170**; без объектов скрыто: **20**. Объектов справочника: **142** — **124** родителей OtherContainers и **18** баз Harbors. Игра **1.8.0.13**, мир `CTI_Campaign_HQC_Eden.ent`, ревизия `r0007`, язык `en_us`. Статус **partial**.

Радиус: **1000 м**, включительно. Расстояние по горизонтали X/Z. С локациями сопоставлены **142** объектов; без сопоставления **0**. Всего связей **1084**: один объект может находиться в радиусе нескольких подписей.

## Откуда берутся данные

| Данные | Источник |
| --- | --- |
| Локация | Именованный MapDescriptor: поле `DisplayName`, исходный ключ / текст и перевод `WidgetManager.Translate`; язык `WidgetManager.GetLanguage`. |
| Координаты локации | Мировая позиция source-объекта подписи карты, включая родительский Eden; сверена с преобразованиями родителей. |
| Объекты OtherContainers | Корневые родительские строки канонического отчёта r0006; позиции отдельных контейнеров не используются вместо позиции родителя. |
| Объекты Harbors | 18 source base из r0004, с сохранёнными собственными именами и мировыми координатами. |
| Расстояние | `sqrt((objectX-locationX)^2 + (objectZ-locationZ)^2)`; проверка ≤ радиуса выполняется до округления вывода. |

Полные данные: [Locations.json](Locations.json), [метаданные](world.json). Входы: [OtherContainers](../r0006/Supplies/OtherContainers.json), [Harbors](../r0004/Supplies/Harbors.json).

## Список локаций

| Локация | Координаты X / Y / Z, м | Объектов в радиусе |
| --- | --- | ---: |
| Airport | 4900.952 / 28.595 / 11787.412 | 12 |
| Alder Pond | 5882.488 / 78.755 / 5713.591 | 10 |
| Anchor Bay | 11415.2 / 0 / 2598.813 | 1 |
| Anchor Peninsula | 11940.234 / 20.214 / 1880.359 | 1 |
| André's Beacon | 7073.529 / 114.099 / 8391.949 | 4 |
| BEACON RIDGE | 9374.656 / 130.359 / 4436.463 | 1 |
| Bell Pit Lake | 10212.322 / 256.174 / 2590.042 | 1 |
| Bénac | 6579.375 / 151.649 / 7103.253 | 8 |
| Birchwood Bay | 4289.737 / -1.451 / 11458.627 | 12 |
| Black Lake | 9482.455 / 207.163 / 3047.666 | 4 |
| Blackrock Bay | 1450.186 / 0 / 6702.404 | 6 |
| BONFIRE HILL | 5355.778 / 134.156 / 4598.752 | 2 |
| Boulder Cape | 6709.144 / 2.914 / 9660.98 | 5 |
| CALVARY HILL | 3506.903 / 181.547 / 5815.677 | 11 |
| Camurac | 6588.583 / 5.783 / 3113.841 | 3 |
| CASTLE RIDGE | 8574.573 / 280.911 / 1837.881 | 2 |
| Charlet Bay | 4004.544 / 1.913 / 10904.662 | 7 |
| Cheval-Gin Lodge | 9922.592 / 295.967 / 2584.585 | 6 |
| Chotain | 7086.131 / 129.414 / 6012.347 | 10 |
| Coalman's Brow | 4316.667 / 69.024 / 10281.24 | 20 |
| Corsair's Cove | 11722.164 / 0 / 1715.709 | 1 |
| Courbet | 8419.339 / 12.701 / 791.855 | 1 |
| Cowbell Pond | 5328.728 / 79.215 / 6408.909 | 20 |
| Crabapple Bay | 4001.702 / -15.631 / 9618.563 | 5 |
| Crag Point | 11719.133 / 0.669 / 1393.768 | 1 |
| Durras | 8826.849 / 94.671 / 2745.832 | 4 |
| EAST RISE | 6221.419 / 188.674 / 7285.497 | 7 |
| Entre-Deux | 5766.788 / 221.968 / 7035.573 | 11 |
| Étoupe | 5390.357 / 18.654 / 10008.806 | 13 |
| factory | 4536.628 / 16.869 / 10561.202 | 15 |
| farm | 3031.509 / 121.613 / 5496.94 | 11 |
| farm | 4961.006 / 26.534 / 9994.382 | 17 |
| farm | 5133.964 / 175.846 / 7043.796 | 6 |
| farm | 6621.697 / 109.61 / 5892.322 | 7 |
| Figari | 5250.764 / 73.061 / 5337.823 | 14 |
| FISHERMAN'S BAY | 7866.501 / 31.757 / 6764.288 | 3 |
| Fleet Bay | 10365.541 / 0 / 1154.068 | 6 |
| GALLOW'S HILL | 4981.886 / 42.085 / 10370.132 | 13 |
| Gibbet Cape | 1088.792 / 25.115 / 6369.382 | 6 |
| Gillnet Pond | 7077.688 / 56.538 / 8168.655 | 4 |
| Goat Bay | 6295.246 / 0 / 3956.822 | 6 |
| Gorey | 4839.618 / 112.92 / 8094.304 | 10 |
| Gravette | 4120.761 / 35.406 / 7796.203 | 16 |
| GREEN VALLEY | 8642.072 / 158.423 / 3544.935 | 10 |
| Greenwater | 4888.491 / 89.382 / 5568.818 | 14 |
| Guillaume's Dip | 2951.552 / 76.543 / 6457.072 | 6 |
| HALCYON STRAIT | 2807.372 / 0 / 3255.536 | 2 |
| harbor | 9925.094 / 2.389 / 1525.324 | 6 |
| harbor | 1024.018 / 2.849 / 6043.247 | 6 |
| harbor | 4956.796 / 2.188 / 3875.627 | 3 |
| harbor | 4306.9 / 1.126 / 9525.709 | 13 |
| harbor | 4397.416 / 1.485 / 11098.094 | 10 |
| HEDGEHOG HILL | 5029.671 / 47.558 / 9477.439 | 17 |
| Helmsman's Sip | 5159.993 / 16.195 / 12407.198 | 5 |
| HIGHSTONE | 5014.104 / 112.726 / 8474.506 | 5 |
| HORNBEAM VALLEY | 5266.509 / 130.571 / 7527.379 | 11 |
| HUMBOLDT HILL | 2453.296 / 66.551 / 7187.762 | 1 |
| Huntsman's Heath | 2713.9 / 63.194 / 4397.361 | 6 |
| Île-aux-Saules | 2918.98 / 19.531 / 1931.78 | 5 |
| Îlot de l'Estrapade | 3397.483 / 14.231 / 1540.895 | 5 |
| industrial compound | 5043.243 / 27.099 / 10867.547 | 17 |
| industrial compound | 4537.877 / 155.721 / 6844.214 | 6 |
| industrial compound | 6463.926 / 162.215 / 6497.726 | 7 |
| Juniper Point | 4335.623 / 14.73 / 12135.454 | 9 |
| Kermovan | 6367.384 / 9.46 / 9664.13 | 5 |
| La Chalette | 8248.328 / 308.19 / 2816.393 | 4 |
| La Valette | 6736.65 / 89.29 / 5650.287 | 7 |
| Lacan's Head | 5602.718 / 54.898 / 9149.561 | 11 |
| Lacourt | 3883.534 / 102.709 / 6286.328 | 9 |
| Lamentin | 1279.669 / 37.386 / 5940.503 | 6 |
| Lancre | 11684.477 / 8.441 / 2234.58 | 1 |
| landfill | 5330.35 / 52.344 / 10903.854 | 12 |
| Laruns | 7558.336 / 82.526 / 5540.855 | 1 |
| Le Bosc | 7938.762 / 12.809 / 1469.648 | 1 |
| Le Moule | 2615.962 / 92.06 / 5378.784 | 9 |
| Les Creux | 5333.836 / 35.849 / 11372.896 | 12 |
| Levie | 7464.442 / 142.167 / 4738.911 | 18 |
| LONG HILL | 2253.977 / 133.538 / 5558.058 | 6 |
| Martin's Watch | 7890.939 / 144.738 / 1838.893 | 10 |
| Meadow Stream | 2771.111 / 60.217 / 6885.79 | 1 |
| Meaux | 4520.45 / 14.178 / 9467.977 | 13 |
| military site | 7447.122 / 7.894 / 6704.909 | 7 |
| military site | 7631.798 / 13.131 / 8141.2 | 4 |
| military site | 3901.866 / 15.249 / 8450.66 | 7 |
| military site | 4936.765 / 28.261 / 11921.946 | 11 |
| military site | 5354.837 / 43.473 / 10542.704 | 12 |
| military site | 7505.482 / 165.761 / 4283.153 | 18 |
| Mill Pond | 8858.472 / 93.238 / 2789.541 | 4 |
| Millstone Creek | 9068.726 / 76.063 / 2260.626 | 4 |
| Montfort Castle | 9315.082 / 196.166 / 1144.534 | 6 |
| Montignac | 4773.455 / 164.342 / 7094.566 | 7 |
| Moonstone Pond | 4608.405 / 48.338 / 5429.547 | 9 |
| Morton | 5135.238 / 13.126 / 4011.78 | 3 |
| Morton Bay | 5214.12 / 0 / 3397.232 | 3 |
| Morton Stream | 4524.305 / 68.202 / 4414.633 | 2 |
| MORTON VALLEY | 4535.886 / 42.575 / 4657.641 | 2 |
| NEW WOOD | 3408.399 / 135.751 / 6204.091 | 5 |
| Northern Shoals | 5422.809 / 2.334 / 12025.299 | 5 |
| Old Man's Pond | 5118.603 / 32.957 / 11342.979 | 12 |
| OLD WOOD | 3658.132 / 145.167 / 4327.679 | 1 |
| ORE RIDGE | 10740.761 / 242.011 / 2515.195 | 1 |
| Pennants Pass | 8330.602 / 233.029 / 2415.109 | 4 |
| Perelle | 9354.211 / 5.281 / 5072.686 | 1 |
| Perelle Bay | 9336.123 / 13.257 / 5490.011 | 1 |
| Periwinkle Pond | 6718.547 / 124.435 / 6792.907 | 9 |
| Pick Creek | 10402.688 / 137.163 / 2048.189 | 6 |
| PICK MOUNTAIN | 9953.314 / 315.244 / 2297.452 | 7 |
| Pinewood Lake | 4344.29 / 50.736 / 6042.279 | 14 |
| power plant | 5834.383 / 4.572 / 9786.422 | 13 |
| Provins | 5486.487 / 96.127 / 6087.398 | 14 |
| PROW PEAK | 8499.252 / 308.313 / 2303.093 | 4 |
| Quarry | 8839.531 / 221.16 / 4014.789 | 3 |
| Raccoon Rock | 5081.396 / 155.75 / 7731.555 | 11 |
| Ramtop Meadows | 5626.267 / 119.042 / 7804.42 | 5 |
| Reed Pond | 6536.234 / 78.126 / 5576.949 | 9 |
| Régina | 7205.023 / 145.19 / 2324.232 | 9 |
| Régina Stream | 7541.196 / 133.957 / 2044.858 | 10 |
| Richemont | 3540.591 / 111.071 / 5061.813 | 11 |
| Saint-Philippe | 4502.756 / 14.702 / 10771.987 | 12 |
| Saint-Philippe's Creek | 4651.603 / 13.096 / 10171.643 | 16 |
| Saint-Pierre | 9689.018 / 14.024 / 1558.482 | 6 |
| Saint-Pierre's Pass | 8020.888 / 217.707 / 4217.001 | 13 |
| SAINTE-MARIE | 8087.395 / 375.313 / 2752.023 | 8 |
| sawmill | 3069.223 / 117.068 / 5195.226 | 11 |
| sawmill | 7272.375 / 140.26 / 2541.164 | 9 |
| Schooner's End | 7891.254 / 1.227 / 8177.963 | 4 |
| Seagull Point | 5969.331 / 1.323 / 3376.714 | 1 |
| Shepherd's Pond | 3543.751 / 103.779 / 4818.029 | 10 |
| Simon's Wood | 5991.627 / 120.298 / 5198.374 | 5 |
| SIX BELLS | 7266.099 / 118.057 / 5637.435 | 1 |
| Skua Point | 9633.349 / 18.414 / 5333.328 | 1 |
| Spaniard's Bay | 3014.721 / 0 / 7920.237 | 4 |
| Spring Pond | 4670.679 / 14.527 / 10503.558 | 15 |
| SPRUCE HILL | 8736.412 / 291.354 / 4299.075 | 7 |
| Stubwood Point | 6314.119 / 3.117 / 1965.722 | 7 |
| SWELL MOUNTAIN | 8725.427 / 310.15 / 1750.159 | 2 |
| The Scythe | 7486.666 / 1.079 / 9459.886 | 1 |
| The Shallows | 9866.781 / 0 / 5726.444 | 1 |
| Thollevast | 3056.815 / 6.322 / 2131.458 | 5 |
| Tiller's Find | 3597.097 / 52.036 / 6970.91 | 2 |
| Tyrone | 4927.979 / 36.042 / 9092.888 | 17 |
| Tyrone Bay | 6093.175 / 2.474 / 9121.157 | 5 |
| TYRONE RIDGE | 4930.855 / 97.091 / 8758.914 | 9 |
| Upper Fields | 5705.467 / 85.791 / 5625.534 | 14 |
| Vernon | 9243.437 / 59.721 / 2077.243 | 10 |
| Villeneuve | 2838.686 / 86.345 / 6339.803 | 5 |
| WESTERN HEIGHTS | 7743.848 / 331.856 / 3341.014 | 12 |
| Whitewater | 10943.448 / 55.176 / 1988.266 | 2 |
| WOLF HILL | 3854.084 / 162.955 / 4344.244 | 1 |
| Wolfstone | 3792.898 / 157.733 / 4180.008 | 1 |

## Объекты по локациям

### Airport

Позиция: `4900.952 / 28.595 / 11787.412` м. Ключ / текст: `#AR-MapLocation_Airport`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| Base_Airport_FIA_01 | OtherContainers | 0 | 1500 | 0x20000000000010BD {} |
| SP_A_EveronAirport | Harbors | 42.582 | 4000 | 0x2000000000000ECE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 87.414 | 1000 | 0x2000000000003793 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 200.006 | 3000 | 0x20000000000011A9 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 201.372 | 1500 | 0x20000000000010DA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 720.584 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 724.081 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 745.763 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 757.606 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_04 | OtherContainers | 780.982 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 781.506 | 1000 | 0x20000000000037C3 {} |
| SP_T1H_StPhillipe | Harbors | 879.797 | 3500 | 0x2000000000003122 {} |

### Alder Pond

Позиция: `5882.488 / 78.755 / 5713.591` м. Ключ / текст: `#AR-MapLocation_AlderPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| E_LivingArea_S_FIA_01 | OtherContainers | 329.04 | 400 | 0x2000000000002016 {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 332.67 | 600 | 0x2000000000001AD5 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 347.731 | 3000 | 0x2000000000001220 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 349.906 | 1500 | 0x200000000000117C {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 398.421 | 400 | 0x2000000000002071 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 937.799 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 949.971 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 974.696 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 983.203 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 988.321 | 1500 | 0x200000000000164F {} |

### Anchor Bay

Позиция: `11415.2 / 0 / 2598.813` м. Ключ / текст: `#AR-MapLocation_AnchorBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Lancre | Harbors | 487.471 | 1000 | 0x20000000000000C2 {} |

### Anchor Peninsula

Позиция: `11940.234 / 20.214 / 1880.359` м. Ключ / текст: `#AR-MapLocation_AnchorPeninsula`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Lancre | Harbors | 408.59 | 1000 | 0x20000000000000C2 {} |

### André's Beacon

Позиция: `7073.529 / 114.099 / 8391.949` м. Ключ / текст: `#AR-MapLocation_AndresBeacon`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 698.952 | 3000 | 0x20000000000030BC {} |
| StartingPos21 | OtherContainers | 702.379 | 1000 | 0x20000000000016C7 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 703.74 | 2000 | 0x2000000000001E5B {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 704.96 | 1500 | 0x2000000000001685 {} |

### BEACON RIDGE

Позиция: `9374.656 / 130.359 / 4436.463` м. Ключ / текст: `#AR-MapLocation_BeaconRidge`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Perelle | Harbors | 631.257 | 3500 | 0x20000000000001C0 {} |

### Bell Pit Lake

Позиция: `10212.322 / 256.174 / 2590.042` м. Ключ / текст: `#AR-MapLocation_BellPitLake`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 985.314 | 1000 | 0x20000000000037DB {} |

### Bénac

Позиция: `6579.375 / 151.649 / 7103.253` м. Ключ / текст: `#AR-MapLocation_Benac`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 584.32 | 800 | 0x20000000000043A9 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 593.938 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 619.982 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 626.089 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 628.618 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 630.017 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 639.024 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 904.383 | 2000 | 0x2000000000004F4E {} |

### Birchwood Bay

Позиция: `4289.737 / -1.451 / 11458.627` м. Ключ / текст: `#AR-MapLocation_BirchwoodBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 263.729 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 274.638 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_04 | OtherContainers | 291.083 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_06 | OtherContainers | 302.733 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 374.644 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 387.745 | 1000 | 0x20000000000037C3 {} |
| SP_T1H_StPhillipe | Harbors | 404.358 | 3500 | 0x2000000000003122 {} |
| Base_Airport_FIA_01 | OtherContainers | 694.034 | 1500 | 0x20000000000010BD {} |
| SP_A_EveronAirport | Harbors | 734.113 | 4000 | 0x2000000000000ECE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 769.532 | 1000 | 0x2000000000003793 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 830.874 | 1500 | 0x20000000000010DA {} |
| SupplyCache_S_FIA_03 | OtherContainers | 834.891 | 3000 | 0x20000000000011A9 {} |

### Black Lake

Позиция: `9482.455 / 207.163 / 3047.666` м. Ключ / текст: `#AR-MapLocation_BlackLake`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 514.934 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 534.01 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 537.051 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 555.369 | 800 | 0x20000000000041DB {} |

### Blackrock Bay

Позиция: `1450.186 / 0 / 6702.404` м. Ключ / текст: `#AR-MapLocation_BlackrockBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 722.571 | 2000 | 0x2000000000004EEC {} |
| SupplyCache_S_FIA_04 | OtherContainers | 755.621 | 1500 | 0x2000000000001122 {} |
| SP_T2H_Lamentin | Harbors | 764.249 | unknown | 0x2000000000004DD7 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 785.293 | 2000 | 0x2000000000004EFA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 830.538 | 1000 | 0x20000000000037F3 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 844.455 | 3000 | 0x20000000000011DC {} |

### BONFIRE HILL

Позиция: `5355.778 / 134.156 / 4598.752` м. Ключ / текст: `#AR-MapLocation_BonfireHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 732.484 | 2000 | 0x2000000000004F08 {} |
| SP_T2H_Morton | Harbors | 834.848 | 3500 | 0x2000000000004D93 {} |

### Boulder Cape

Позиция: `6709.144 / 2.914 / 9660.98` м. Ключ / текст: `#AR-MapLocation_BoulderCape`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Kermovan | Harbors | 432.086 | 2500 | 0x200000000000015D {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 833.875 | 400 | 0x2000000000001FBB {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 883.71 | 2100 | 0x2000000000004987 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 912.838 | 2000 | 0x2000000000004F78 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 927.61 | 1500 | 0x200000000000116A {} |

### CALVARY HILL

Позиция: `3506.903 / 181.547 / 5815.677` м. Ключ / текст: `#AR-MapLocation_CalvaryHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| LivingArea_S_FIA_01 | OtherContainers | 24.171 | 400 | 0x20000000000007D2 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 27.374 | 2000 | 0x2000000000004F5C {} |
| SupplyCache_S_FIA_06 | OtherContainers | 33.337 | 1000 | 0x200000000000386B {} |
| FieldHospital_M_FIA_01 | OtherContainers | 38.343 | 2000 | 0x2000000000002721 {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 51.273 | 3400 | 0x2000000000001A01 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 696.218 | 900 | 0x2000000000001006 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 717.62 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 725.179 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 727.621 | 1500 | 0x2000000000001661 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 747.955 | 800 | 0x20000000000043D3 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 758.467 | 1000 | 0x2000000000003F2C {} |

### Camurac

Позиция: `6588.583 / 5.783 / 3113.841` м. Ключ / текст: `#AR-MapLocation_Camurac`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_GoatBay | Harbors | 890.355 | 2500 | 0x20000000000000DE {} |
| SupplyCache_S_FIA_01 | OtherContainers | 943.306 | 900 | 0x2000000000003D79 {} |
| LivingArea_S_FIA_01 | OtherContainers | 989.769 | 400 | 0x200000000000095F {} |

### CASTLE RIDGE

Позиция: `8574.573 / 280.911 / 1837.881` м. Ключ / текст: `#AR-MapLocation_CastleRidge`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_LeBosc | Harbors | 732.597 | 3000 | 0x20000000000000A9 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 970.98 | 800 | 0x20000000000041DB {} |

### Charlet Bay

Позиция: `4004.544 / 1.913 / 10904.662` м. Ключ / текст: `#AR-MapLocation_CharletBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T1H_StPhillipe | Harbors | 422.735 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 507.536 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_04 | OtherContainers | 522.768 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_04 | OtherContainers | 524.625 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_06 | OtherContainers | 530.057 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 540.503 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 555.051 | 1000 | 0x20000000000037AB {} |

### Cheval-Gin Lodge

Позиция: `9922.592 / 295.967 / 2584.585` м. Ключ / текст: `#AR-MapLocation_ChevalGinLodge`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 851.183 | 800 | 0x20000000000041DB {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 891.464 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 891.766 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 899.203 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 936.33 | 1000 | 0x20000000000037DB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 995.427 | 2000 | 0x2000000000004ED0 {} |

### Chotain

Позиция: `7086.131 / 129.414 / 6012.347` м. Ключ / текст: `#AR-MapLocation_Chotain`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Laruns | Harbors | 709.764 | 1500 | 0x2000000000000191 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 742.684 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 755.775 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 782.062 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 784.079 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 791.999 | 800 | 0x20000000000043A9 {} |
| SP_T2H_FishermansBay | Harbors | 810.25 | 5000 | 0x2000000000004E0B {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 814.979 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 821.735 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 855.804 | 2000 | 0x2000000000004F4E {} |

### Coalman's Brow

Позиция: `4316.667 / 69.024 / 10281.24` м. Ключ / текст: `#AR-MapLocation_CoalmansBrow`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03 | OtherContainers | 717.739 | 3000 | 0x200000000000120F {} |
| SupplyCache_S_FIA_04 | OtherContainers | 748.973 | 1500 | 0x2000000000001146 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 757.597 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 760.806 | 1500 | 0x200000000000163D {} |
| SP_T2H_Meaux | Harbors | 764.332 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 769.019 | 2000 | 0x2000000000004F40 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 771.003 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 774.435 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 774.57 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 788.798 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 789.277 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_06 | OtherContainers | 789.643 | 1000 | 0x2000000000003853 {} |
| SP_T1H_StPhillipe | Harbors | 790.648 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 825.025 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 860.425 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 866.236 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_04 | OtherContainers | 932.047 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 934.579 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 943.395 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 961.825 | 2000 | 0x2000000000004EC2 {} |

### Corsair's Cove

Позиция: `11722.164 / 0 / 1715.709` м. Ключ / текст: `#AR-MapLocation_CorsairsCove`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Lancre | Harbors | 465.202 | 1000 | 0x20000000000000C2 {} |

### Courbet

Позиция: `8419.339 / 12.701 / 791.855` м. Ключ / текст: `#AR-MapLocation_Courbet`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_LeBosc | Harbors | 829.795 | 3000 | 0x20000000000000A9 {} |

### Cowbell Pond

Позиция: `5328.728 / 79.215 / 6408.909` м. Ключ / текст: `#AR-MapLocation_CowbellPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| E_LivingArea_S_FIA_01 | OtherContainers | 511.325 | 400 | 0x2000000000002071 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 568.485 | 1500 | 0x200000000000117C {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 570.96 | 600 | 0x2000000000001AD5 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 576.889 | 3000 | 0x2000000000001220 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 638.045 | 400 | 0x2000000000002016 {} |
| LivingArea_S_FIA_01 | OtherContainers | 700.336 | 400 | 0x20000000000008A9 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 712.886 | 1000 | 0x2000000000003883 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 713.567 | 900 | 0x2000000000000F8E {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 771.957 | 800 | 0x20000000000042D7 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 793.484 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 801.928 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 820.982 | 800 | 0x2000000000004283 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 823.165 | 800 | 0x20000000000042AD {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 828.018 | 3000 | 0x2000000000003056 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 837.728 | 1500 | 0x200000000000162B {} |
| LivingArea_S_FIA_01 | OtherContainers | 845.575 | 400 | 0x2000000000000904 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 862.023 | 2000 | 0x2000000000004F6A {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 864.294 | 1000 | 0x2000000000003ECC {} |
| SupplyCache_S_FIA_04 | OtherContainers | 902.49 | 1500 | 0x2000000000001158 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 994.991 | 2000 | 0x20000000000027E0 {} |

### Crabapple Bay

Позиция: `4001.702 / -15.631 / 9618.563` м. Ключ / текст: `#AR-MapLocation_CrabappleBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04 | OtherContainers | 308.404 | 1500 | 0x2000000000001146 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 320.351 | 3000 | 0x200000000000120F {} |
| SP_T2H_Meaux | Harbors | 330.591 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 336.813 | 1000 | 0x2000000000003853 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 346.557 | 2000 | 0x2000000000004F40 {} |

### Crag Point

Позиция: `11719.133 / 0.669 / 1393.768` м. Ключ / текст: `#AR-MapLocation_CragPoint`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Lancre | Harbors | 785.13 | 1000 | 0x20000000000000C2 {} |

### Durras

Позиция: `8826.849 / 94.671 / 2745.832` м. Ключ / текст: `#AR-MapLocation_Durras`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 211.176 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 217.969 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 224.408 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 260.238 | 800 | 0x20000000000041DB {} |

### EAST RISE

Позиция: `6221.419 / 188.674 / 7285.497` м. Ключ / текст: `#AR-MapLocation_EastRise`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 802.856 | 800 | 0x20000000000043A9 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 814.069 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 819.839 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 822.631 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 829.189 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 847.842 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 856.233 | 1500 | 0x200000000000164F {} |

### Entre-Deux

Позиция: `5766.788 / 221.968 / 7035.573` м. Ключ / текст: `#AR-MapLocation_EntreDeux`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 849.569 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 855.391 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 879.314 | 800 | 0x20000000000043A9 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 885.55 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 888.782 | 3000 | 0x2000000000003078 {} |
| LivingArea_S_FIA_01 | OtherContainers | 900.489 | 400 | 0x20000000000008A9 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 911.789 | 1000 | 0x2000000000003883 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 913.959 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 925.082 | 2000 | 0x2000000000004F6A {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 927.191 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_04 | OtherContainers | 980.422 | 1500 | 0x2000000000001158 {} |

### Étoupe

Позиция: `5390.357 / 18.654 / 10008.806` м. Ключ / текст: `#AR-MapLocation_Etoupe`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 361.802 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 369.487 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 372.018 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 381.78 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 384.885 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 391.595 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 404.657 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 436.902 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 473.179 | 1500 | 0x200000000000116A {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 496.602 | 2100 | 0x2000000000004987 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 497.108 | 2000 | 0x2000000000004F78 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 545.853 | 400 | 0x2000000000001FBB {} |
| SP_T3H_Kermovan | Harbors | 959.229 | 2500 | 0x200000000000015D {} |

### factory

Позиция: `4536.628 / 16.869 / 10561.202` м. Ключ / текст: `#AR-MapLocation_Factory`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T1H_StPhillipe | Harbors | 526.424 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 565.679 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 575.037 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_04 | OtherContainers | 652.762 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_06 | OtherContainers | 655.283 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_03 | OtherContainers | 662.45 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_05 | OtherContainers | 683.141 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 739.752 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 748.719 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 780.138 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 787.191 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 791.305 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 807.381 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 815.653 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 850.579 | 3000 | 0x2000000000003067 {} |

### farm

Позиция: `3031.509 / 121.613 / 5496.94` м. Ключ / текст: `#AR-MapLocation_Farm`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 254.041 | 1500 | 0x2000000000001661 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 268.023 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 277.554 | 900 | 0x2000000000001006 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 290.747 | 1000 | 0x2000000000003F2C {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 293.467 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 316.192 | 800 | 0x20000000000043D3 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 537.396 | 2000 | 0x2000000000002721 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 546.385 | 2000 | 0x2000000000004F5C {} |
| SupplyCache_S_FIA_06 | OtherContainers | 559.168 | 1000 | 0x200000000000386B {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 578.795 | 3400 | 0x2000000000001A01 {} |
| LivingArea_S_FIA_01 | OtherContainers | 596.315 | 400 | 0x20000000000007D2 {} |

### farm

Позиция: `4961.006 / 26.534 / 9994.382` м. Ключ / текст: `#AR-MapLocation_Farm`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 58.187 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 60.411 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 73.021 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 84.578 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 84.972 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 99.811 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 121.833 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 143.479 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 774.618 | 3000 | 0x200000000000120F {} |
| SupplyCache_S_FIA_05 | OtherContainers | 792.785 | 2000 | 0x2000000000004F40 {} |
| SP_T2H_Meaux | Harbors | 802.283 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 808.146 | 1500 | 0x2000000000001146 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 819.653 | 1000 | 0x2000000000003853 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 860.483 | 1500 | 0x200000000000116A {} |
| SupplyCache_S_FIA_05 | OtherContainers | 879.777 | 2000 | 0x2000000000004F78 {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 897.794 | 2100 | 0x2000000000004987 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 947.979 | 400 | 0x2000000000001FBB {} |

### farm

Позиция: `5133.964 / 175.846 / 7043.796` м. Ключ / текст: `#AR-MapLocation_Farm`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| LivingArea_S_FIA_01 | OtherContainers | 282.524 | 400 | 0x20000000000008A9 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 291.56 | 1000 | 0x2000000000003883 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 298.804 | 2000 | 0x2000000000004F6A {} |
| SupplyCache_S_FIA_04 | OtherContainers | 354.31 | 1500 | 0x2000000000001158 {} |
| LivingArea_S_FIA_01 | OtherContainers | 367.939 | 400 | 0x2000000000000904 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 449.243 | 2000 | 0x20000000000027E0 {} |

### farm

Позиция: `6621.697 / 109.61 / 5892.322` м. Ключ / текст: `#AR-MapLocation_Farm`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 597.265 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 604.087 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 620.775 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 628.647 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 630.341 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 638.173 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 649.237 | 800 | 0x20000000000043A9 {} |

### Figari

Позиция: `5250.764 / 73.061 / 5337.823` м. Ключ / текст: `#AR-MapLocation_Figari`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 507.283 | 1000 | 0x2000000000003ECC {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 532.114 | 3000 | 0x2000000000003056 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 551.971 | 1500 | 0x200000000000162B {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 577.365 | 400 | 0x2000000000002016 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 645.964 | 3000 | 0x2000000000001220 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 658.526 | 1500 | 0x200000000000117C {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 683.22 | 800 | 0x20000000000042AD {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 686.354 | 900 | 0x2000000000000F8E {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 687.364 | 600 | 0x2000000000001AD5 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 693.939 | 800 | 0x20000000000042D7 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 694.306 | 400 | 0x2000000000002071 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 696.746 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 703.584 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 711.501 | 800 | 0x2000000000004283 {} |

### FISHERMAN'S BAY

Позиция: `7866.501 / 31.757 / 6764.288` м. Ключ / текст: `#AR-MapLocation_FishermansBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T2H_FishermansBay | Harbors | 343.721 | 5000 | 0x2000000000004E0B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 437.675 | 2000 | 0x2000000000004F4E {} |
| SP_T3H_Laruns | Harbors | 892.854 | 1500 | 0x2000000000000191 {} |

### Fleet Bay

Позиция: `10365.541 / 0 / 1154.068` м. Ключ / текст: `#AR-MapLocation_FleetBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04 | OtherContainers | 529.979 | 1500 | 0x2000000000001110 {} |
| SP_T1H_StPierre | Harbors | 545.701 | unknown | 0x2000000000003115 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 554.619 | 2000 | 0x2000000000004ED0 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 571.121 | 3000 | 0x20000000000011CB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 588.923 | 2000 | 0x2000000000004EDE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 663.573 | 1000 | 0x20000000000037DB {} |

### GALLOW'S HILL

Позиция: `4981.886 / 42.085 / 10370.132` м. Ключ / текст: `#AR-MapLocation_GallowsHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 370.175 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 383.432 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 422.801 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 427.118 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 453.301 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 462.622 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 496.826 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 503.131 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 902.482 | 1000 | 0x20000000000037C3 {} |
| SP_T1H_StPhillipe | Harbors | 912.254 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 915.924 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 987.811 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 999.261 | 1500 | 0x20000000000010EC {} |

### Gibbet Cape

Позиция: `1088.792 / 25.115 / 6369.382` м. Ключ / текст: `#AR-MapLocation_GibbetCape`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 285.381 | 2000 | 0x2000000000004EEC {} |
| SupplyCache_S_FIA_04 | OtherContainers | 312.789 | 1500 | 0x2000000000001122 {} |
| SP_T2H_Lamentin | Harbors | 321.663 | unknown | 0x2000000000004DD7 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 328.517 | 2000 | 0x2000000000004EFA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 351.013 | 1000 | 0x20000000000037F3 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 357.344 | 3000 | 0x20000000000011DC {} |

### Gillnet Pond

Позиция: `7077.688 / 56.538 / 8168.655` м. Ключ / текст: `#AR-MapLocation_GillnetPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 633.225 | 3000 | 0x20000000000030BC {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 640.114 | 2000 | 0x2000000000001E5B {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 645.318 | 1500 | 0x2000000000001685 {} |
| StartingPos21 | OtherContainers | 868.616 | 1000 | 0x20000000000016C7 {} |

### Goat Bay

Позиция: `6295.246 / 0 / 3956.822` м. Ключ / текст: `#AR-MapLocation_GoatBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_GoatBay | Harbors | 649.448 | 2500 | 0x20000000000000DE {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 783.679 | 900 | 0x2000000000000F34 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 809.898 | 800 | 0x2000000000004259 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 822.3 | 2000 | 0x2000000000001DF9 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 837.383 | 900 | 0x2000000000000F52 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 841.321 | 800 | 0x200000000000422F {} |

### Gorey

Позиция: `4839.618 / 112.92 / 8094.304` м. Ключ / текст: `#AR-MapLocation_Gorey`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 15.51 | 2000 | 0x2000000000001E23 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 56.061 | 900 | 0x2000000000000FCA {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 61.405 | 800 | 0x2000000000004355 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 63.183 | 800 | 0x200000000000437F {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 64.192 | 900 | 0x2000000000000FE8 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 917.259 | 2000 | 0x20000000000027E0 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 961.576 | 1500 | 0x2000000000001158 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 971.336 | 2000 | 0x2000000000004F6A {} |
| SupplyCache_S_FIA_04 | OtherContainers | 977.938 | 1500 | 0x2000000000001134 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 987.848 | 2000 | 0x2000000000004F16 {} |

### Gravette

Позиция: `4120.761 / 35.406 / 7796.203` м. Ключ / текст: `#AR-MapLocation_Gravette`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Gravette | Harbors | 309.533 | 1500 | 0x2000000000000144 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 655.127 | 1500 | 0x2000000000001134 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 656.579 | 2000 | 0x2000000000004F16 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 662.075 | 1000 | 0x200000000000380B {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 787.766 | 800 | 0x2000000000004355 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 793.254 | 2000 | 0x2000000000001E23 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 801.579 | 800 | 0x200000000000437F {} |
| SupplyCache_S_FIA_03 | OtherContainers | 820.893 | 3000 | 0x20000000000011ED {} |
| SP_T2H_MilitaryHospital | Harbors | 827.744 | 3000 | 0x2000000000004DDD {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 834.24 | 900 | 0x2000000000000FCA {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 836.26 | 900 | 0x2000000000000FE8 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 846.489 | 2000 | 0x20000000000027E0 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 942.459 | 1500 | 0x2000000000001158 {} |
| SP_T3H_SpaniardsBay | Harbors | 947.244 | 3000 | 0x200000000000012B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 989.427 | 2000 | 0x2000000000004F6A {} |
| LivingArea_S_FIA_01 | OtherContainers | 994.034 | 400 | 0x2000000000000904 {} |

### GREEN VALLEY

Позиция: `8642.072 / 158.423 / 3544.935` м. Ключ / текст: `#AR-MapLocation_GreenValley`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 877.714 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 881.966 | 3000 | 0x2000000000001253 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 885.605 | 1000 | 0x20000000000038CB {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 891.526 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 898.518 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 935.421 | 1500 | 0x200000000000118E {} |
| SupplyCache_S_FIA_03 | OtherContainers | 941.425 | 3000 | 0x2000000000001242 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 948.103 | 1000 | 0x20000000000038B3 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 956.53 | 2000 | 0x2000000000004F94 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 976.862 | 800 | 0x20000000000041DB {} |

### Greenwater

Позиция: `4888.491 / 89.382 / 5568.818` м. Ключ / текст: `#AR-MapLocation_Greenwater`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 107.658 | 1000 | 0x2000000000003ECC {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 147.312 | 3000 | 0x2000000000003056 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 155.276 | 1500 | 0x200000000000162B {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 276.209 | 800 | 0x20000000000042AD {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 298.719 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 302.239 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 303.902 | 800 | 0x2000000000004283 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 304.084 | 800 | 0x20000000000042D7 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 322.991 | 900 | 0x2000000000000F8E {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 726.385 | 400 | 0x2000000000002016 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 766.366 | 3000 | 0x2000000000001220 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 775.692 | 1500 | 0x200000000000117C {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 780.838 | 400 | 0x2000000000002071 {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 810.279 | 600 | 0x2000000000001AD5 {} |

### Guillaume's Dip

Позиция: `2951.552 / 76.543 / 6457.072` м. Ключ / текст: `#AR-MapLocation_GillaumesDip`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| FieldHospital_M_FIA_01 | OtherContainers | 829.615 | 2000 | 0x2000000000002721 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 854.024 | 2000 | 0x2000000000004F5C {} |
| LivingArea_S_FIA_01 | OtherContainers | 854.919 | 400 | 0x20000000000007D2 {} |
| SP_T3H_SpaniardsBay | Harbors | 865.24 | 3000 | 0x200000000000012B {} |
| SupplyCache_S_FIA_06 | OtherContainers | 876.892 | 1000 | 0x200000000000386B {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 899.643 | 3400 | 0x2000000000001A01 {} |

### HALCYON STRAIT

Позиция: `2807.372 / 0 / 3255.536` м. Ключ / текст: `#AR-MapLocation_HalcyonStrait`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_HalcyonStrait | Harbors | 548.344 | 1500 | 0x2000000000000111 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 993.035 | 3000 | 0x2000000000001231 {} |

### harbor

Позиция: `9925.094 / 2.389 / 1525.324` м. Ключ / текст: `#AR-MapLocation_Harbour`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T1H_StPierre | Harbors | 38.781 | unknown | 0x2000000000003115 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 40.336 | 2000 | 0x2000000000004EDE {} |
| SupplyCache_S_FIA_03 | OtherContainers | 48.126 | 3000 | 0x20000000000011CB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 60.747 | 1500 | 0x2000000000001110 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 122.954 | 1000 | 0x20000000000037DB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 124.961 | 2000 | 0x2000000000004ED0 {} |

### harbor

Позиция: `1024.018 / 2.849 / 6043.247` м. Ключ / текст: `#AR-MapLocation_Harbour`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 12.033 | 2000 | 0x2000000000004EFA {} |
| SP_T2H_Lamentin | Harbors | 29.228 | unknown | 0x2000000000004DD7 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 34.395 | 1500 | 0x2000000000001122 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 66.201 | 2000 | 0x2000000000004EEC {} |
| SupplyCache_S_FIA_06 | OtherContainers | 99.993 | 1000 | 0x20000000000037F3 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 147.704 | 3000 | 0x20000000000011DC {} |

### harbor

Позиция: `4956.796 / 2.188 / 3875.627` м. Ключ / текст: `#AR-MapLocation_Harbour`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T2H_Morton | Harbors | 10.644 | 3500 | 0x2000000000004D93 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 96.698 | 2000 | 0x2000000000004F08 {} |
| SP_T3H_GoatBay | Harbors | 913.005 | 2500 | 0x20000000000000DE {} |

### harbor

Позиция: `4306.9 / 1.126 / 9525.709` м. Ключ / текст: `#AR-MapLocation_Harbour`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04 | OtherContainers | 11.313 | 1500 | 0x2000000000001146 {} |
| SP_T2H_Meaux | Harbors | 12.859 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 28.062 | 2000 | 0x2000000000004F40 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 34.772 | 1000 | 0x2000000000003853 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 39.194 | 3000 | 0x200000000000120F {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 753.12 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 792.679 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 802.078 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 802.148 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 821.742 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 841.463 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 849.177 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 858.321 | 1000 | 0x2000000000003EFC {} |

### harbor

Позиция: `4397.416 / 1.485 / 11098.094` м. Ключ / текст: `#AR-MapLocation_Harbour`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T1H_StPhillipe | Harbors | 30.187 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 84.903 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 93.236 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 113.745 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_04 | OtherContainers | 113.836 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_06 | OtherContainers | 133.699 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 142.227 | 2000 | 0x2000000000004EC2 {} |
| Base_Airport_FIA_01 | OtherContainers | 853.644 | 1500 | 0x20000000000010BD {} |
| SP_A_EveronAirport | Harbors | 883.803 | 4000 | 0x2000000000000ECE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 940.554 | 1000 | 0x2000000000003793 {} |

### HEDGEHOG HILL

Позиция: `5029.671 / 47.558 / 9477.439` м. Ключ / текст: `#AR-MapLocation_HedgehogHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 392.026 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 399.673 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 431.41 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 440.888 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 467.049 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 473.041 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 511.164 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 524.655 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_05 | OtherContainers | 698.957 | 2000 | 0x2000000000004F40 {} |
| SP_T2H_Meaux | Harbors | 714.486 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 716.141 | 1000 | 0x2000000000003853 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 717.565 | 3000 | 0x200000000000120F {} |
| SupplyCache_S_FIA_04 | OtherContainers | 733.885 | 1500 | 0x2000000000001146 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 803.255 | 1500 | 0x200000000000116A {} |
| SupplyCache_S_FIA_05 | OtherContainers | 807.794 | 2000 | 0x2000000000004F78 {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 861.993 | 2100 | 0x2000000000004987 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 903.14 | 400 | 0x2000000000001FBB {} |

### Helmsman's Sip

Позиция: `5159.993 / 16.195 / 12407.198` м. Ключ / текст: `#AR-MapLocation_HelmsmansSip`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03 | OtherContainers | 477.705 | 3000 | 0x20000000000011A9 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 478.818 | 1500 | 0x20000000000010DA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 585.076 | 1000 | 0x2000000000003793 {} |
| SP_A_EveronAirport | Harbors | 651.079 | 4000 | 0x2000000000000ECE {} |
| Base_Airport_FIA_01 | OtherContainers | 671.742 | 1500 | 0x20000000000010BD {} |

### HIGHSTONE

Позиция: `5014.104 / 112.726 / 8474.506` м. Ключ / текст: `#AR-MapLocation_Highstone`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 357.265 | 900 | 0x2000000000000FE8 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 363.527 | 800 | 0x200000000000437F {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 380.735 | 900 | 0x2000000000000FCA {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 404.768 | 2000 | 0x2000000000001E23 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 457.212 | 800 | 0x2000000000004355 {} |

### HORNBEAM VALLEY

Позиция: `5266.509 / 130.571 / 7527.379` м. Ключ / текст: `#AR-MapLocation_HornbeamValley`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 583.515 | 2000 | 0x2000000000004F6A {} |
| SupplyCache_S_FIA_04 | OtherContainers | 616.931 | 1500 | 0x2000000000001158 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 648.882 | 800 | 0x2000000000004355 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 654.297 | 2000 | 0x20000000000027E0 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 695.735 | 900 | 0x2000000000000FCA {} |
| LivingArea_S_FIA_01 | OtherContainers | 698.513 | 400 | 0x2000000000000904 {} |
| LivingArea_S_FIA_01 | OtherContainers | 708.409 | 400 | 0x20000000000008A9 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 709.806 | 2000 | 0x2000000000001E23 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 710.08 | 1000 | 0x2000000000003883 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 725.546 | 900 | 0x2000000000000FE8 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 762.869 | 800 | 0x200000000000437F {} |

### HUMBOLDT HILL

Позиция: `2453.296 / 66.551 / 7187.762` м. Ключ / текст: `#AR-MapLocation_HumboldtHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_SpaniardsBay | Harbors | 922.761 | 3000 | 0x200000000000012B {} |

### Huntsman's Heath

Позиция: `2713.9 / 63.194 / 4397.361` м. Ключ / текст: `#AR-MapLocation_HuntsmansHeath`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 878.348 | 1000 | 0x2000000000003F2C {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 879.985 | 800 | 0x20000000000043D3 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 910.244 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 910.458 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 913.496 | 1500 | 0x2000000000001661 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 932.089 | 900 | 0x2000000000001006 {} |

### Île-aux-Saules

Позиция: `2918.98 / 19.531 / 1931.78` м. Ключ / текст: `#AR-MapLocation_Saules`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 235.233 | 1000 | 0x200000000000389B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 242.403 | 2000 | 0x2000000000004F86 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 265.792 | 400 | 0x20000000000020CC {} |
| SP_T3H_Thollevast | Harbors | 309.332 | 1500 | 0x20000000000001A8 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 339.205 | 3000 | 0x2000000000001231 {} |

### Îlot de l'Estrapade

Позиция: `3397.483 / 14.231 / 1540.895` м. Ключ / текст: `#AR-MapLocation_Estrapade`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Thollevast | Harbors | 651.507 | 1500 | 0x20000000000001A8 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 785.192 | 1000 | 0x200000000000389B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 796.956 | 2000 | 0x2000000000004F86 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 836.979 | 400 | 0x20000000000020CC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 908.131 | 3000 | 0x2000000000001231 {} |

### industrial compound

Позиция: `5043.243 / 27.099 / 10867.547` м. Ключ / текст: `#AR-MapLocation_Industrial`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 612.999 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 627.286 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 672.325 | 1000 | 0x20000000000037AB {} |
| SP_T1H_StPhillipe | Harbors | 679.093 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 696.795 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_05 | OtherContainers | 714.296 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 721.367 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 865.813 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 879.394 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 917.134 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 923.779 | 800 | 0x2000000000004301 {} |
| Base_Airport_FIA_01 | OtherContainers | 930.805 | 1500 | 0x20000000000010BD {} |
| SP_A_EveronAirport | Harbors | 931.15 | 4000 | 0x2000000000000ECE {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 951.651 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 959.581 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 996.534 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 998.154 | 3000 | 0x2000000000003067 {} |

### industrial compound

Позиция: `4537.877 / 155.721 / 6844.214` м. Ключ / текст: `#AR-MapLocation_Industrial`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| LivingArea_S_FIA_01 | OtherContainers | 300.709 | 400 | 0x2000000000000904 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 337.167 | 1000 | 0x2000000000003883 {} |
| LivingArea_S_FIA_01 | OtherContainers | 346.879 | 400 | 0x20000000000008A9 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 382.266 | 2000 | 0x20000000000027E0 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 384.931 | 1500 | 0x2000000000001158 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 415.403 | 2000 | 0x2000000000004F6A {} |

### industrial compound

Позиция: `6463.926 / 162.215 / 6497.726` м. Ключ / текст: `#AR-MapLocation_Industrial`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 5.241 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 30.56 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 34.174 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 35.284 | 800 | 0x20000000000043A9 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 37.21 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 48.113 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 50.796 | 3000 | 0x2000000000003089 {} |

### Juniper Point

Позиция: `4335.623 / 14.73 / 12135.454` м. Ключ / текст: `#AR-MapLocation_JuniperPoint`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04 | OtherContainers | 614.126 | 1500 | 0x20000000000010DA {} |
| SupplyCache_S_FIA_03 | OtherContainers | 621.901 | 3000 | 0x20000000000011A9 {} |
| Base_Airport_FIA_01 | OtherContainers | 663.875 | 1500 | 0x20000000000010BD {} |
| SupplyCache_S_FIA_06 | OtherContainers | 666.673 | 1000 | 0x2000000000003793 {} |
| SP_A_EveronAirport | Harbors | 697.229 | 4000 | 0x2000000000000ECE {} |
| SupplyCache_S_FIA_05 | OtherContainers | 904.349 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 927.119 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 931.96 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 934.794 | 1500 | 0x20000000000010EC {} |

### Kermovan

Позиция: `6367.384 / 9.46 / 9664.13` м. Ключ / текст: `#AR-MapLocation_Kermovan`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Kermovan | Harbors | 92.263 | 2500 | 0x200000000000015D {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 496.682 | 400 | 0x2000000000001FBB {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 546.85 | 2100 | 0x2000000000004987 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 572.082 | 2000 | 0x2000000000004F78 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 587.814 | 1500 | 0x200000000000116A {} |

### La Chalette

Позиция: `8248.328 / 308.19 / 2816.393` м. Ключ / текст: `#AR-MapLocation_LaChalette`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 792.813 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 799.944 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 803.311 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 840.26 | 800 | 0x20000000000041DB {} |

### La Valette

Позиция: `6736.65 / 89.29 / 5650.287` м. Ключ / текст: `#AR-MapLocation_LaValette`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 859.346 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 867.061 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 885.287 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 895.506 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 896.706 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 901.024 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 912.192 | 800 | 0x20000000000043A9 {} |

### Lacan's Head

Позиция: `5602.718 / 54.898 / 9149.561` м. Ключ / текст: `#AR-MapLocation_LacansHead`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 607.953 | 2000 | 0x2000000000004F78 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 626.556 | 1500 | 0x200000000000116A {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 677.688 | 2100 | 0x2000000000004987 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 683.98 | 400 | 0x2000000000001FBB {} |
| SP_T3H_Kermovan | Harbors | 836.31 | 2500 | 0x200000000000015D {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 918.941 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 958.086 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 961.825 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 978.197 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 982.7 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 988.936 | 800 | 0x2000000000004301 {} |

### Lacourt

Позиция: `3883.534 / 102.709 / 6286.328` м. Ключ / текст: `#AR-MapLocation_Lacourt`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| LivingArea_S_FIA_01 | OtherContainers | 581.031 | 400 | 0x20000000000007D2 {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 616.203 | 3400 | 0x2000000000001A01 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 625.735 | 1000 | 0x200000000000386B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 630.169 | 2000 | 0x2000000000004F5C {} |
| FieldHospital_M_FIA_01 | OtherContainers | 632.262 | 2000 | 0x2000000000002721 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 969.67 | 800 | 0x2000000000004283 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 983.023 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 992.349 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 996.163 | 800 | 0x20000000000042AD {} |

### Lamentin

Позиция: `1279.669 / 37.386 / 5940.503` м. Ключ / текст: `#AR-MapLocation_Lamentin`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 249.341 | 2000 | 0x2000000000004EEC {} |
| SP_T2H_Lamentin | Harbors | 252.075 | unknown | 0x2000000000004DD7 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 253.85 | 1500 | 0x2000000000001122 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 287.393 | 2000 | 0x2000000000004EFA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 373.647 | 1000 | 0x20000000000037F3 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 422.308 | 3000 | 0x20000000000011DC {} |

### Lancre

Позиция: `11684.477 / 8.441 / 2234.58` м. Ключ / текст: `#AR-MapLocation_Lancre`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Lancre | Harbors | 63.429 | 1000 | 0x20000000000000C2 {} |

### landfill

Позиция: `5330.35 / 52.344 / 10903.854` м. Ключ / текст: `#AR-MapLocation_Landfill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 871.994 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 885.633 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 917.611 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 945.774 | 1500 | 0x20000000000010EC {} |
| SP_T1H_StPhillipe | Harbors | 950.219 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 953.436 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_05 | OtherContainers | 958.39 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 966.9 | 1500 | 0x200000000000163D {} |
| SP_A_EveronAirport | Harbors | 970.081 | 4000 | 0x2000000000000ECE {} |
| SupplyCache_S_FIA_03 | OtherContainers | 971.258 | 3000 | 0x20000000000011BA {} |
| Base_Airport_FIA_01 | OtherContainers | 982.374 | 1500 | 0x20000000000010BD {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 998.595 | 900 | 0x2000000000000FAC {} |

### Laruns

Позиция: `7558.336 / 82.526 / 5540.855` м. Ключ / текст: `#AR-MapLocation_Laruns`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Laruns | Harbors | 402.725 | 1500 | 0x2000000000000191 {} |

### Le Bosc

Позиция: `7938.762 / 12.809 / 1469.648` м. Ключ / текст: `#AR-MapLocation_LeBosc`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_LeBosc | Harbors | 2.327 | 3000 | 0x20000000000000A9 {} |

### Le Moule

Позиция: `2615.962 / 92.06 / 5378.784` м. Ключ / текст: `#AR-MapLocation_LeMoule`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 460.745 | 1500 | 0x2000000000001661 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 470.728 | 1000 | 0x2000000000003F2C {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 482.464 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 520.025 | 800 | 0x20000000000043D3 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 524.062 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 527.032 | 900 | 0x2000000000001006 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 955.445 | 2000 | 0x2000000000002721 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 967.702 | 2000 | 0x2000000000004F5C {} |
| SupplyCache_S_FIA_06 | OtherContainers | 982.994 | 1000 | 0x200000000000386B {} |

### Les Creux

Позиция: `5333.836 / 35.849 / 11372.896` м. Ключ / текст: `#AR-MapLocation_LesCreux`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_A_EveronAirport | Harbors | 573.928 | 4000 | 0x2000000000000ECE {} |
| Base_Airport_FIA_01 | OtherContainers | 599.343 | 1500 | 0x20000000000010BD {} |
| SupplyCache_S_FIA_06 | OtherContainers | 626.366 | 1000 | 0x2000000000003793 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 727.537 | 3000 | 0x20000000000011A9 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 733.773 | 1500 | 0x20000000000010DA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 882.228 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_06 | OtherContainers | 882.674 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 891.879 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_05 | OtherContainers | 912.703 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 915.119 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 938.839 | 3000 | 0x20000000000011BA {} |
| SP_T1H_StPhillipe | Harbors | 987.633 | 3500 | 0x2000000000003122 {} |

### Levie

Позиция: `7464.442 / 142.167 / 4738.911` м. Ключ / текст: `#AR-MapLocation_Levie`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 425.275 | 1000 | 0x2000000000003823 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 430.736 | 2000 | 0x2000000000004F24 {} |
| LivingArea_S_FIA_01 | OtherContainers | 479.845 | 400 | 0x200000000000084E {} |
| SupplyCache_S_FIA_06 | OtherContainers | 485.676 | 1000 | 0x200000000000383B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 523.03 | 2000 | 0x2000000000004F32 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 529.135 | 3000 | 0x20000000000011FE {} |
| E_VehicleMaintenance_S_FIA_01 | OtherContainers | 542.783 | 400 | 0x2000000000004AD5 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 572.305 | 800 | 0x200000000000422F {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 577.234 | 900 | 0x2000000000000F52 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 596.047 | 2000 | 0x2000000000001DF9 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 599.863 | 800 | 0x2000000000004259 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 627.257 | 900 | 0x2000000000000F34 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 790.008 | 1000 | 0x20000000000038B3 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 791.787 | 2000 | 0x2000000000004F94 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 803.664 | 1500 | 0x200000000000118E {} |
| SupplyCache_S_FIA_03 | OtherContainers | 805.603 | 3000 | 0x2000000000001242 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 847.294 | 3000 | 0x2000000000001253 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 853.493 | 1000 | 0x20000000000038CB {} |

### LONG HILL

Позиция: `2253.977 / 133.538 / 5558.058` м. Ключ / текст: `#AR-MapLocation_LongHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 861.823 | 1500 | 0x2000000000001661 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 873.861 | 1000 | 0x2000000000003F2C {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 883.871 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 923.156 | 800 | 0x20000000000043D3 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 925.692 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 927.139 | 900 | 0x2000000000001006 {} |

### Martin's Watch

Позиция: `7890.939 / 144.738 / 1838.893` м. Ключ / текст: `#AR-MapLocation_MartinsWatch`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_LeBosc | Harbors | 372.329 | 3000 | 0x20000000000000A9 {} |
| E_VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 804.706 | 600 | 0x2000000000001E73 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 813.781 | 2000 | 0x200000000000289F {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 839.325 | 900 | 0x2000000000001024 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 840.51 | 3000 | 0x20000000000030AB {} |
| LivingArea_S_FIA_01 | OtherContainers | 840.967 | 400 | 0x200000000000095F {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 848.015 | 1500 | 0x2000000000001673 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 851.976 | 800 | 0x20000000000043FD {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 853.092 | 900 | 0x2000000000001042 {} |
| SupplyCache_S_FIA_01 | OtherContainers | 884.656 | 900 | 0x2000000000003D79 {} |

### Meadow Stream

Позиция: `2771.111 / 60.217 / 6885.79` м. Ключ / текст: `#AR-MapLocation_MeadowStream`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_SpaniardsBay | Harbors | 686.646 | 3000 | 0x200000000000012B {} |

### Meaux

Позиция: `4520.45 / 14.178 / 9467.977` м. Ключ / текст: `#AR-MapLocation_Meaux`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 194.01 | 2000 | 0x2000000000004F40 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 208.126 | 1000 | 0x2000000000003853 {} |
| SP_T2H_Meaux | Harbors | 209.956 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 224.502 | 3000 | 0x200000000000120F {} |
| SupplyCache_S_FIA_04 | OtherContainers | 231.759 | 1500 | 0x2000000000001146 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 609.04 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 649.958 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 654.253 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 659.923 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 685.919 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 704.131 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 720.681 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 731.906 | 1000 | 0x2000000000003EFC {} |

### military site

Позиция: `7447.122 / 7.894 / 6704.909` м. Ключ / текст: `#AR-MapLocation_Military`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T2H_FishermansBay | Harbors | 85.28 | 5000 | 0x2000000000004E0B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 92.725 | 2000 | 0x2000000000004F4E {} |
| SP_T3H_Laruns | Harbors | 894.773 | 1500 | 0x2000000000000191 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 965.876 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 977.337 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 977.93 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 979.506 | 800 | 0x20000000000043A9 {} |

### military site

Позиция: `7631.798 / 13.131 / 8141.2` м. Ключ / текст: `#AR-MapLocation_Military`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 87.513 | 3000 | 0x20000000000030BC {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 91.791 | 2000 | 0x2000000000001E5B {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 93.402 | 1500 | 0x2000000000001685 {} |
| StartingPos21 | OtherContainers | 734.918 | 1000 | 0x20000000000016C7 {} |

### military site

Позиция: `3901.866 / 15.249 / 8450.66` м. Ключ / текст: `#AR-MapLocation_Military`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 34.283 | 2000 | 0x2000000000004F16 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 34.54 | 1000 | 0x200000000000380B {} |
| SupplyCache_S_FIA_04 | OtherContainers | 35.254 | 1500 | 0x2000000000001134 {} |
| SP_T2H_MilitaryHospital | Harbors | 182.499 | 3000 | 0x2000000000004DDD {} |
| SupplyCache_S_FIA_03 | OtherContainers | 190.44 | 3000 | 0x20000000000011ED {} |
| SP_T3H_Gravette | Harbors | 722.003 | 1500 | 0x2000000000000144 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 979.416 | 800 | 0x200000000000437F {} |

### military site

Позиция: `4936.765 / 28.261 / 11921.946` м. Ключ / текст: `#AR-MapLocation_Military`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 59.066 | 1000 | 0x2000000000003793 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 61.899 | 3000 | 0x20000000000011A9 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 64.745 | 1500 | 0x20000000000010DA {} |
| SP_A_EveronAirport | Harbors | 128.805 | 4000 | 0x2000000000000ECE {} |
| Base_Airport_FIA_01 | OtherContainers | 139.219 | 1500 | 0x20000000000010BD {} |
| SupplyCache_S_FIA_06 | OtherContainers | 851.114 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 851.834 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 874.906 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 885.219 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_04 | OtherContainers | 914.298 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_06 | OtherContainers | 915.488 | 1000 | 0x20000000000037C3 {} |

### military site

Позиция: `5354.837 / 43.473 / 10542.704` м. Ключ / текст: `#AR-MapLocation_Military`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 635.476 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 648.082 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 673.898 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 688.687 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 721.036 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 721.129 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 746.827 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 769.623 | 2000 | 0x2000000000001E15 {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 895.504 | 2100 | 0x2000000000004987 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 903.285 | 1500 | 0x200000000000116A {} |
| SupplyCache_S_FIA_05 | OtherContainers | 930.247 | 2000 | 0x2000000000004F78 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 933.001 | 400 | 0x2000000000001FBB {} |

### military site

Позиция: `7505.482 / 165.761 / 4283.153` м. Ключ / текст: `#AR-MapLocation_Military`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| LivingArea_S_FIA_01 | OtherContainers | 24.317 | 400 | 0x200000000000084E {} |
| SupplyCache_S_FIA_06 | OtherContainers | 87.637 | 1000 | 0x2000000000003823 {} |
| E_VehicleMaintenance_S_FIA_01 | OtherContainers | 89.465 | 400 | 0x2000000000004AD5 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 95.098 | 2000 | 0x2000000000004F24 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 108.718 | 1000 | 0x200000000000383B {} |
| SupplyCache_S_FIA_03 | OtherContainers | 109.889 | 3000 | 0x20000000000011FE {} |
| SupplyCache_S_FIA_05 | OtherContainers | 109.912 | 2000 | 0x2000000000004F32 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 401.853 | 2000 | 0x2000000000004F94 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 408.241 | 1000 | 0x20000000000038B3 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 417.098 | 3000 | 0x2000000000001242 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 421.374 | 1500 | 0x200000000000118E {} |
| SupplyCache_S_FIA_06 | OtherContainers | 472.46 | 1000 | 0x20000000000038CB {} |
| SupplyCache_S_FIA_03 | OtherContainers | 474.12 | 3000 | 0x2000000000001253 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 585.684 | 800 | 0x200000000000422F {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 586.572 | 800 | 0x2000000000004259 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 592.167 | 900 | 0x2000000000000F52 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 610.433 | 900 | 0x2000000000000F34 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 615.044 | 2000 | 0x2000000000001DF9 {} |

### Mill Pond

Позиция: `8858.472 / 93.238 / 2789.541` м. Ключ / текст: `#AR-MapLocation_MillPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 184.719 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 192.347 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 192.922 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 248.121 | 800 | 0x20000000000041DB {} |

### Millstone Creek

Позиция: `9068.726 / 76.063 / 2260.626` м. Ключ / текст: `#AR-MapLocation_BuhrstoneCreek`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 409.006 | 800 | 0x20000000000041DB {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 481.685 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 486.505 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 507.579 | 3000 | 0x2000000000003045 {} |

### Montfort Castle

Позиция: `9315.082 / 196.166 / 1144.534` м. Ключ / текст: `#AR-MapLocation_MontfortCastle`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T1H_StPierre | Harbors | 751.28 | unknown | 0x2000000000003115 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 752.646 | 2000 | 0x2000000000004EDE {} |
| SupplyCache_S_FIA_03 | OtherContainers | 766.596 | 3000 | 0x20000000000011CB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 770.534 | 1500 | 0x2000000000001110 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 789.262 | 1000 | 0x20000000000037DB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 844.014 | 2000 | 0x2000000000004ED0 {} |

### Montignac

Позиция: `4773.455 / 164.342 / 7094.566` м. Ключ / текст: `#AR-MapLocation_Montignac`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04 | OtherContainers | 43.236 | 1500 | 0x2000000000001158 {} |
| LivingArea_S_FIA_01 | OtherContainers | 54.983 | 400 | 0x2000000000000904 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 77.77 | 2000 | 0x2000000000004F6A {} |
| FieldHospital_M_FIA_01 | OtherContainers | 112.885 | 2000 | 0x20000000000027E0 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 172.047 | 1000 | 0x2000000000003883 {} |
| LivingArea_S_FIA_01 | OtherContainers | 183.562 | 400 | 0x20000000000008A9 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 951.033 | 800 | 0x2000000000004355 {} |

### Moonstone Pond

Позиция: `4608.405 / 48.338 / 5429.547` м. Ключ / текст: `#AR-MapLocation_MoonstonePond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 360.26 | 1000 | 0x2000000000003ECC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 379.161 | 1500 | 0x200000000000162B {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 391.726 | 3000 | 0x2000000000003056 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 412.91 | 800 | 0x20000000000042AD {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 426.75 | 800 | 0x2000000000004283 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 440.409 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 445.266 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 463.712 | 800 | 0x20000000000042D7 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 514.211 | 900 | 0x2000000000000F8E {} |

### Morton

Позиция: `5135.238 / 13.126 / 4011.78` м. Ключ / текст: `#AR-MapLocation_Morton`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 130.147 | 2000 | 0x2000000000004F08 {} |
| SP_T2H_Morton | Harbors | 234.968 | 3500 | 0x2000000000004D93 {} |
| SP_T3H_GoatBay | Harbors | 821.711 | 2500 | 0x20000000000000DE {} |

### Morton Bay

Позиция: `5214.12 / 0 / 3397.232` м. Ключ / текст: `#AR-MapLocation_MortonBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T2H_Morton | Harbors | 543.326 | 3500 | 0x2000000000004D93 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 581.532 | 2000 | 0x2000000000004F08 {} |
| SP_T3H_GoatBay | Harbors | 604.438 | 2500 | 0x20000000000000DE {} |

### Morton Stream

Позиция: `4524.305 / 68.202 / 4414.633` м. Ключ / текст: `#AR-MapLocation_MortonStream`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 683.884 | 2000 | 0x2000000000004F08 {} |
| SP_T2H_Morton | Harbors | 689.203 | 3500 | 0x2000000000004D93 {} |

### MORTON VALLEY

Позиция: `4535.886 / 42.575 / 4657.641` м. Ключ / текст: `#AR-MapLocation_MortonValley`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 861.931 | 2000 | 0x2000000000004F08 {} |
| SP_T2H_Morton | Harbors | 888.144 | 3500 | 0x2000000000004D93 {} |

### NEW WOOD

Позиция: `3408.399 / 135.751 / 6204.091` м. Ключ / текст: `#AR-MapLocation_NewWood`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| LivingArea_S_FIA_01 | OtherContainers | 396.463 | 400 | 0x20000000000007D2 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 399.981 | 2000 | 0x2000000000002721 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 417.97 | 2000 | 0x2000000000004F5C {} |
| SupplyCache_S_FIA_06 | OtherContainers | 433.918 | 1000 | 0x200000000000386B {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 447.943 | 3400 | 0x2000000000001A01 {} |

### Northern Shoals

Позиция: `5422.809 / 2.334 / 12025.299` м. Ключ / текст: `#AR-MapLocation_NorthernShoals`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03 | OtherContainers | 485.831 | 3000 | 0x20000000000011A9 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 492.938 | 1500 | 0x20000000000010DA {} |
| SupplyCache_S_FIA_06 | OtherContainers | 505.226 | 1000 | 0x2000000000003793 {} |
| SP_A_EveronAirport | Harbors | 532.842 | 4000 | 0x2000000000000ECE {} |
| Base_Airport_FIA_01 | OtherContainers | 573.52 | 1500 | 0x20000000000010BD {} |

### Old Man's Pond

Позиция: `5118.603 / 32.957 / 11342.979` м. Ключ / текст: `#AR-MapLocation_OldManPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_A_EveronAirport | Harbors | 483.302 | 4000 | 0x2000000000000ECE {} |
| Base_Airport_FIA_01 | OtherContainers | 494.867 | 1500 | 0x20000000000010BD {} |
| SupplyCache_S_FIA_06 | OtherContainers | 548.812 | 1000 | 0x2000000000003793 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 665.211 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_03 | OtherContainers | 665.594 | 3000 | 0x20000000000011A9 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 668.471 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 670.167 | 1500 | 0x20000000000010DA {} |
| SupplyCache_S_FIA_04 | OtherContainers | 677.159 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_05 | OtherContainers | 695.422 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 698.111 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 721.709 | 3000 | 0x20000000000011BA {} |
| SP_T1H_StPhillipe | Harbors | 774.607 | 3500 | 0x2000000000003122 {} |

### OLD WOOD

Позиция: `3658.132 / 145.167 / 4327.679` м. Ключ / текст: `#AR-MapLocation_OldWood`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_HalcyonStrait | Harbors | 871.018 | 1500 | 0x2000000000000111 {} |

### ORE RIDGE

Позиция: `10740.761 / 242.011 / 2515.195` м. Ключ / текст: `#AR-MapLocation_OreRidge`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Lancre | Harbors | 978.506 | 1000 | 0x20000000000000C2 {} |

### Pennants Pass

Позиция: `8330.602 / 233.029 / 2415.109` м. Ключ / текст: `#AR-MapLocation_PennantsPass`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 781.052 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 785.315 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 787.316 | 800 | 0x20000000000041DB {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 801.386 | 3000 | 0x2000000000003045 {} |

### Perelle

Позиция: `9354.211 / 5.281 / 5072.686` м. Ключ / текст: `#AR-MapLocation_Perelle`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Perelle | Harbors | 26.974 | 3500 | 0x20000000000001C0 {} |

### Perelle Bay

Позиция: `9336.123 / 13.257 / 5490.011` м. Ключ / текст: `#AR-MapLocation_PerelleBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Perelle | Harbors | 424.089 | 3500 | 0x20000000000001C0 {} |

### Periwinkle Pond

Позиция: `6718.547 / 124.435 / 6792.907` м. Ключ / текст: `#AR-MapLocation_PeriwinklePond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 354.769 | 800 | 0x20000000000043A9 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 359.947 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 378.176 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 382.353 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 390.987 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 418.933 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 432.092 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 711.439 | 2000 | 0x2000000000004F4E {} |
| SP_T2H_FishermansBay | Harbors | 819.008 | 5000 | 0x2000000000004E0B {} |

### Pick Creek

Позиция: `10402.688 / 137.163 / 2048.189` м. Ключ / текст: `#AR-MapLocation_PickCreek`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 587.547 | 2000 | 0x2000000000004ED0 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 624.769 | 1000 | 0x20000000000037DB {} |
| SupplyCache_S_FIA_03 | OtherContainers | 660.31 | 3000 | 0x20000000000011CB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 669.909 | 1500 | 0x2000000000001110 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 670.149 | 2000 | 0x2000000000004EDE {} |
| SP_T1H_StPierre | Harbors | 684.096 | unknown | 0x2000000000003115 {} |

### PICK MOUNTAIN

Позиция: `9953.314 / 315.244 / 2297.452` м. Ключ / текст: `#AR-MapLocation_PickMountain`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 649.918 | 1000 | 0x20000000000037DB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 706.655 | 2000 | 0x2000000000004ED0 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 735.209 | 2000 | 0x2000000000004EDE {} |
| SupplyCache_S_FIA_03 | OtherContainers | 740.207 | 3000 | 0x20000000000011CB {} |
| SP_T1H_StPierre | Harbors | 774.109 | unknown | 0x2000000000003115 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 774.349 | 1500 | 0x2000000000001110 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 953.283 | 800 | 0x20000000000041DB {} |

### Pinewood Lake

Позиция: `4344.29 / 50.736 / 6042.279` м. Ключ / текст: `#AR-MapLocation_PinewoodLake`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 448.276 | 800 | 0x2000000000004283 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 461.824 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 471.289 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 474.795 | 800 | 0x20000000000042AD {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 482.578 | 800 | 0x20000000000042D7 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 519.818 | 900 | 0x2000000000000F8E {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 601.735 | 1500 | 0x200000000000162B {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 624.069 | 3000 | 0x2000000000003056 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 642.77 | 1000 | 0x2000000000003ECC {} |
| LivingArea_S_FIA_01 | OtherContainers | 843.783 | 400 | 0x20000000000007D2 {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 848.472 | 3400 | 0x2000000000001A01 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 871.706 | 1000 | 0x200000000000386B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 889.611 | 2000 | 0x2000000000004F5C {} |
| FieldHospital_M_FIA_01 | OtherContainers | 905.722 | 2000 | 0x2000000000002721 {} |

### power plant

Позиция: `5834.383 / 4.572 / 9786.422` м. Ключ / текст: `#AR-MapLocation_PowerPlant`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| Base_PowerPlant_FIA_01 | OtherContainers | 0 | 2100 | 0x2000000000004987 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 50.201 | 400 | 0x2000000000001FBB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 61.525 | 1500 | 0x200000000000116A {} |
| SupplyCache_S_FIA_05 | OtherContainers | 71.013 | 2000 | 0x2000000000004F78 {} |
| SP_T3H_Kermovan | Harbors | 465.428 | 2500 | 0x200000000000015D {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 807.084 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 817.718 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 831.559 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 835.346 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 840.151 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 841.537 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 848.265 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 863.786 | 2000 | 0x2000000000001E15 {} |

### Provins

Позиция: `5486.487 / 96.127 / 6087.398` м. Ключ / текст: `#AR-MapLocation_Provins`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| E_LivingArea_S_FIA_01 | OtherContainers | 153.642 | 400 | 0x2000000000002071 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 210.515 | 1500 | 0x200000000000117C {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 215.79 | 600 | 0x2000000000001AD5 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 218.76 | 3000 | 0x2000000000001220 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 281.759 | 400 | 0x2000000000002016 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 675.728 | 900 | 0x2000000000000F8E {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 714.768 | 3000 | 0x2000000000003056 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 732.98 | 1500 | 0x200000000000162B {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 734.155 | 800 | 0x20000000000042D7 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 739.996 | 1000 | 0x2000000000003ECC {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 755.13 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 765.826 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 776.101 | 800 | 0x20000000000042AD {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 786.382 | 800 | 0x2000000000004283 {} |

### PROW PEAK

Позиция: `8499.252 / 308.313 / 2303.093` м. Ключ / текст: `#AR-MapLocation_ProwPeak`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 683.049 | 800 | 0x20000000000041DB {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 697.556 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 699.992 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 720.782 | 3000 | 0x2000000000003045 {} |

### Quarry

Позиция: `8839.531 / 221.16 / 4014.789` м. Ключ / текст: `#AR-Campaign_MapLocation_Quarry`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03 | OtherContainers | 948.997 | 3000 | 0x2000000000001253 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 962.136 | 1000 | 0x20000000000038CB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 997.763 | 1500 | 0x200000000000118E {} |

### Raccoon Rock

Позиция: `5081.396 / 155.75 / 7731.555` м. Ключ / текст: `#AR-MapLocation_RaccoonRock`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 374.749 | 800 | 0x2000000000004355 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 426.539 | 900 | 0x2000000000000FCA {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 437.066 | 2000 | 0x2000000000001E23 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 456.897 | 900 | 0x2000000000000FE8 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 491.32 | 800 | 0x200000000000437F {} |
| SupplyCache_S_FIA_05 | OtherContainers | 652.563 | 2000 | 0x2000000000004F6A {} |
| FieldHospital_M_FIA_01 | OtherContainers | 660.658 | 2000 | 0x20000000000027E0 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 664.296 | 1500 | 0x2000000000001158 {} |
| LivingArea_S_FIA_01 | OtherContainers | 759.986 | 400 | 0x2000000000000904 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 816.735 | 1000 | 0x2000000000003883 {} |
| LivingArea_S_FIA_01 | OtherContainers | 819.549 | 400 | 0x20000000000008A9 {} |

### Ramtop Meadows

Позиция: `5626.267 / 119.042 / 7804.42` м. Ключ / текст: `#AR-MapLocation_RamtopMeadows`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 792.692 | 800 | 0x2000000000004355 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 796.636 | 900 | 0x2000000000000FCA {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 817.582 | 900 | 0x2000000000000FE8 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 830.03 | 2000 | 0x2000000000001E23 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 865.2 | 800 | 0x200000000000437F {} |

### Reed Pond

Позиция: `6536.234 / 78.126 / 5576.949` м. Ключ / текст: `#AR-MapLocation_ReedPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 902.176 | 1500 | 0x200000000000164F {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 906.914 | 1000 | 0x2000000000003F14 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 917.017 | 3000 | 0x2000000000003089 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 919.186 | 2000 | 0x2000000000001E31 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 921.425 | 2000 | 0x2000000000001E3F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 940.645 | 3000 | 0x2000000000003078 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 951.267 | 800 | 0x20000000000043A9 {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 977.734 | 600 | 0x2000000000001AD5 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 995.368 | 400 | 0x2000000000002016 {} |

### Régina

Позиция: `7205.023 / 145.19 / 2324.232` м. Ключ / текст: `#AR-MapLocation_Regina`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| E_VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 38.135 | 600 | 0x2000000000001E73 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 41.174 | 2000 | 0x200000000000289F {} |
| LivingArea_S_FIA_01 | OtherContainers | 47.247 | 400 | 0x200000000000095F {} |
| SupplyCache_S_FIA_01 | OtherContainers | 81.55 | 900 | 0x2000000000003D79 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 278.382 | 1500 | 0x2000000000001673 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 284.191 | 3000 | 0x20000000000030AB {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 290.213 | 900 | 0x2000000000001042 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 306.392 | 900 | 0x2000000000001024 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 307.492 | 800 | 0x20000000000043FD {} |

### Régina Stream

Позиция: `7541.196 / 133.957 / 2044.858` м. Ключ / текст: `#AR-MapLocation_ReginaStream`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| E_VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 402.921 | 600 | 0x2000000000001E73 {} |
| FieldHospital_M_FIA_01 | OtherContainers | 413.844 | 2000 | 0x200000000000289F {} |
| LivingArea_S_FIA_01 | OtherContainers | 442.668 | 400 | 0x200000000000095F {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 459.538 | 3000 | 0x20000000000030AB {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 463.718 | 900 | 0x2000000000001024 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 465.266 | 1500 | 0x2000000000001673 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 472.621 | 900 | 0x2000000000001042 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 475.648 | 800 | 0x20000000000043FD {} |
| SupplyCache_S_FIA_01 | OtherContainers | 488.604 | 900 | 0x2000000000003D79 {} |
| SP_T3H_LeBosc | Harbors | 700.295 | 3000 | 0x20000000000000A9 {} |

### Richemont

Позиция: `3540.591 / 111.071 / 5061.813` м. Ключ / текст: `#AR-MapLocation_Richemont`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 452.065 | 900 | 0x2000000000001006 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 453.483 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 458.547 | 800 | 0x20000000000043D3 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 495.226 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 507.566 | 1000 | 0x2000000000003F2C {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 517.2 | 1500 | 0x2000000000001661 {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 713.747 | 3400 | 0x2000000000001A01 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 721.499 | 1000 | 0x200000000000386B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 734.094 | 2000 | 0x2000000000004F5C {} |
| FieldHospital_M_FIA_01 | OtherContainers | 750.349 | 2000 | 0x2000000000002721 {} |
| LivingArea_S_FIA_01 | OtherContainers | 764.575 | 400 | 0x20000000000007D2 {} |

### Saint-Philippe

Позиция: `4502.756 / 14.702 / 10771.987` м. Ключ / текст: `#AR-MapLocation_StPhillipe`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T1H_StPhillipe | Harbors | 315.265 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 353.055 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 362.001 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_04 | OtherContainers | 439.273 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_06 | OtherContainers | 442.217 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_03 | OtherContainers | 449.148 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_05 | OtherContainers | 469.655 | 2000 | 0x2000000000004EC2 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 928.092 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 938.225 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 972.952 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 977.937 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 987.132 | 800 | 0x200000000000432B {} |

### Saint-Philippe's Creek

Позиция: `4651.603 / 13.096 / 10171.643` м. Ключ / текст: `#AR-MapLocation_PhilipsCreek`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 406.418 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 410.424 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 427.908 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 428.47 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 439.943 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 441.138 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 446.115 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 485.487 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 693.977 | 3000 | 0x200000000000120F {} |
| SupplyCache_S_FIA_04 | OtherContainers | 730.504 | 1500 | 0x2000000000001146 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 732.841 | 2000 | 0x2000000000004F40 {} |
| SP_T2H_Meaux | Harbors | 735.61 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 759.377 | 1000 | 0x2000000000003853 {} |
| SP_T1H_StPhillipe | Harbors | 932.575 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 967.186 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 977.383 | 1500 | 0x20000000000010FE {} |

### Saint-Pierre

Позиция: `9689.018 / 14.024 / 1558.482` м. Ключ / текст: `#AR-MapLocation_StPierre`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 250.333 | 1000 | 0x20000000000037DB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 252.122 | 2000 | 0x2000000000004EDE {} |
| SupplyCache_S_FIA_03 | OtherContainers | 272.058 | 3000 | 0x20000000000011CB {} |
| SP_T1H_StPierre | Harbors | 277.039 | unknown | 0x2000000000003115 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 298.825 | 1500 | 0x2000000000001110 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 341.848 | 2000 | 0x2000000000004ED0 {} |

### Saint-Pierre's Pass

Позиция: `8020.888 / 217.707 / 4217.001` м. Ключ / текст: `#AR-MapLocation_PetersPass`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03 | OtherContainers | 247.515 | 3000 | 0x2000000000001253 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 257.108 | 1000 | 0x20000000000038B3 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 259.314 | 1500 | 0x200000000000118E {} |
| SupplyCache_S_FIA_06 | OtherContainers | 266.619 | 1000 | 0x20000000000038CB {} |
| SupplyCache_S_FIA_03 | OtherContainers | 273.728 | 3000 | 0x2000000000001242 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 275.744 | 2000 | 0x2000000000004F94 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 411.248 | 1000 | 0x200000000000383B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 417.033 | 2000 | 0x2000000000004F32 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 420.785 | 3000 | 0x20000000000011FE {} |
| SupplyCache_S_FIA_05 | OtherContainers | 444.732 | 2000 | 0x2000000000004F24 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 455.22 | 1000 | 0x2000000000003823 {} |
| E_VehicleMaintenance_S_FIA_01 | OtherContainers | 478.422 | 400 | 0x2000000000004AD5 {} |
| LivingArea_S_FIA_01 | OtherContainers | 505.408 | 400 | 0x200000000000084E {} |

### SAINTE-MARIE

Позиция: `8087.395 / 375.313 / 2752.023` м. Ключ / текст: `#AR-MapLocation_MarysMount`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| LivingArea_S_FIA_01 | OtherContainers | 939.191 | 400 | 0x200000000000095F {} |
| FieldHospital_M_FIA_01 | OtherContainers | 940.409 | 2000 | 0x200000000000289F {} |
| SupplyCache_S_FIA_01 | OtherContainers | 941.884 | 900 | 0x2000000000003D79 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 950.647 | 800 | 0x2000000000004205 {} |
| E_VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 951.891 | 600 | 0x2000000000001E73 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 957.439 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 962.907 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 991.7 | 800 | 0x20000000000041DB {} |

### sawmill

Позиция: `3069.223 / 117.068 / 5195.226` м. Ключ / текст: `#AR-MapLocation_Sawmill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 19.093 | 1000 | 0x2000000000003F2C {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 31.38 | 800 | 0x20000000000043D3 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 37.931 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 48.929 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 50.518 | 1500 | 0x2000000000001661 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 66.797 | 900 | 0x2000000000001006 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 731.956 | 2000 | 0x2000000000004F5C {} |
| FieldHospital_M_FIA_01 | OtherContainers | 732.389 | 2000 | 0x2000000000002721 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 735.756 | 1000 | 0x200000000000386B {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 746.537 | 3400 | 0x2000000000001A01 {} |
| LivingArea_S_FIA_01 | OtherContainers | 780.571 | 400 | 0x20000000000007D2 {} |

### sawmill

Позиция: `7272.375 / 140.26 / 2541.164` м. Ключ / текст: `#AR-MapLocation_Sawmill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_01 | OtherContainers | 148.652 | 900 | 0x2000000000003D79 {} |
| LivingArea_S_FIA_01 | OtherContainers | 183.051 | 400 | 0x200000000000095F {} |
| FieldHospital_M_FIA_01 | OtherContainers | 209.036 | 2000 | 0x200000000000289F {} |
| E_VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 228.549 | 600 | 0x2000000000001E73 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 503.578 | 1500 | 0x2000000000001673 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 509.999 | 3000 | 0x20000000000030AB {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 515.152 | 900 | 0x2000000000001042 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 532.466 | 900 | 0x2000000000001024 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 532.76 | 800 | 0x20000000000043FD {} |

### Schooner's End

Позиция: `7891.254 / 1.227 / 8177.963` м. Ключ / текст: `#AR-MapLocation_SchoonersEnd`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 183.047 | 1500 | 0x2000000000001685 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 193.173 | 2000 | 0x2000000000001E5B {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 201.912 | 3000 | 0x20000000000030BC {} |
| StartingPos21 | OtherContainers | 761.402 | 1000 | 0x20000000000016C7 {} |

### Seagull Point

Позиция: `5969.331 / 1.323 / 3376.714` м. Ключ / текст: `#AR-MapLocation_SeagullPoint`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_GoatBay | Harbors | 228.206 | 2500 | 0x20000000000000DE {} |

### Shepherd's Pond

Позиция: `3543.751 / 103.779 / 4818.029` м. Ключ / текст: `#AR-MapLocation_ShepherdsPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 578.032 | 800 | 0x20000000000043D3 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 585.322 | 3000 | 0x200000000000309A {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 592.308 | 900 | 0x2000000000001006 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 625.215 | 2000 | 0x2000000000001E4D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 625.274 | 1000 | 0x2000000000003F2C {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 647.219 | 1500 | 0x2000000000001661 {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 957.542 | 3400 | 0x2000000000001A01 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 965.24 | 1000 | 0x200000000000386B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 977.611 | 2000 | 0x2000000000004F5C {} |
| FieldHospital_M_FIA_01 | OtherContainers | 993.53 | 2000 | 0x2000000000002721 {} |

### Simon's Wood

Позиция: `5991.627 / 120.298 / 5198.374` м. Ключ / текст: `#AR-MapLocation_SimonsWood`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| E_LivingArea_S_FIA_01 | OtherContainers | 749.531 | 400 | 0x2000000000002016 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 804.195 | 3000 | 0x2000000000001220 {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 809.757 | 600 | 0x2000000000001AD5 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 812.013 | 1500 | 0x200000000000117C {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 868.955 | 400 | 0x2000000000002071 {} |

### SIX BELLS

Позиция: `7266.099 / 118.057 / 5637.435` м. Ключ / текст: `#AR-MapLocation_SixBells`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Laruns | Harbors | 568.638 | 1500 | 0x2000000000000191 {} |

### Skua Point

Позиция: `9633.349 / 18.414 / 5333.328` м. Ключ / текст: `Skua Point`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Perelle | Harbors | 405.776 | 3500 | 0x20000000000001C0 {} |

### Spaniard's Bay

Позиция: `3014.721 / 0 / 7920.237` м. Ключ / текст: `#AR-MapLocation_SpaniardsBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_SpaniardsBay | Harbors | 795.677 | 3000 | 0x200000000000012B {} |
| SP_T3H_Gravette | Harbors | 824.316 | 1500 | 0x2000000000000144 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 923.547 | 3000 | 0x20000000000011ED {} |
| SP_T2H_MilitaryHospital | Harbors | 945.482 | 3000 | 0x2000000000004DDD {} |

### Spring Pond

Позиция: `4670.679 / 14.527 / 10503.558` м. Ключ / текст: `#AR-MapLocation_SpringPond`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 611.732 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 621.73 | 1500 | 0x200000000000163D {} |
| SP_T1H_StPhillipe | Harbors | 628.47 | 3500 | 0x2000000000003122 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 647.775 | 1000 | 0x20000000000037C3 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 656.332 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 659.116 | 1500 | 0x20000000000010FE {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 661.359 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 670.799 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 685.931 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 699.827 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 729.609 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 738.011 | 1000 | 0x20000000000037AB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 741.082 | 1500 | 0x20000000000010EC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 754.512 | 3000 | 0x20000000000011BA {} |
| SupplyCache_S_FIA_05 | OtherContainers | 770.712 | 2000 | 0x2000000000004EC2 {} |

### SPRUCE HILL

Позиция: `8736.412 / 291.354 / 4299.075` м. Ключ / текст: `#AR-MapLocation_SpruceHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_03 | OtherContainers | 894.99 | 3000 | 0x2000000000001253 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 911.961 | 1000 | 0x20000000000038CB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 934.306 | 1500 | 0x200000000000118E {} |
| SupplyCache_S_FIA_06 | OtherContainers | 938.848 | 1000 | 0x20000000000038B3 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 948.256 | 3000 | 0x2000000000001242 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 957.019 | 2000 | 0x2000000000004F94 {} |
| SP_T3H_Perelle | Harbors | 968.629 | 3500 | 0x20000000000001C0 {} |

### Stubwood Point

Позиция: `6314.119 / 3.117 / 1965.722` м. Ключ / текст: `#AR-MapLocation_StubwoodPoint`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 756.189 | 800 | 0x20000000000043FD {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 761.882 | 900 | 0x2000000000001042 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 767.532 | 900 | 0x2000000000001024 {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 770.997 | 1500 | 0x2000000000001673 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 774.889 | 3000 | 0x20000000000030AB {} |
| E_VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 991.259 | 600 | 0x2000000000001E73 {} |
| SupplyCache_S_FIA_01 | OtherContainers | 999.414 | 900 | 0x2000000000003D79 {} |

### SWELL MOUNTAIN

Позиция: `8725.427 / 310.15 / 1750.159` м. Ключ / текст: `#AR-MapLocation_SwellMountain`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_LeBosc | Harbors | 832.906 | 3000 | 0x20000000000000A9 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 983.863 | 800 | 0x20000000000041DB {} |

### The Scythe

Позиция: `7486.666 / 1.079 / 9459.886` м. Ключ / текст: `#AR-MapLocation_Scythe`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| StartingPos21 | OtherContainers | 593.346 | 1000 | 0x20000000000016C7 {} |

### The Shallows

Позиция: `9866.781 / 0 / 5726.444` м. Ключ / текст: `#AR-MapLocation_Shallows`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Perelle | Harbors | 852.284 | 3500 | 0x20000000000001C0 {} |

### Thollevast

Позиция: `3056.815 / 6.322 / 2131.458` м. Ключ / текст: `#AR-MapLocation_Thollevast`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Thollevast | Harbors | 89.786 | 1500 | 0x20000000000001A8 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 137.86 | 1000 | 0x200000000000389B {} |
| SupplyCache_S_FIA_05 | OtherContainers | 149.453 | 2000 | 0x2000000000004F86 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 193.452 | 400 | 0x20000000000020CC {} |
| SupplyCache_S_FIA_03 | OtherContainers | 247.648 | 3000 | 0x2000000000001231 {} |

### Tiller's Find

Позиция: `3597.097 / 52.036 / 6970.91` м. Ключ / текст: `#AR-MapLocation_TillersFind`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_SpaniardsBay | Harbors | 326.684 | 3000 | 0x200000000000012B {} |
| SP_T3H_Gravette | Harbors | 793.921 | 1500 | 0x2000000000000144 {} |

### Tyrone

Позиция: `4927.979 / 36.042 / 9092.888` м. Ключ / текст: `#AR-MapLocation_Tyrone`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_05 | OtherContainers | 729.14 | 2000 | 0x2000000000004F40 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 732.359 | 1000 | 0x2000000000003853 {} |
| SP_T2H_Meaux | Harbors | 744.294 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 768.322 | 1500 | 0x2000000000001146 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 770.989 | 3000 | 0x200000000000120F {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 781.88 | 2000 | 0x2000000000001E15 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 783.454 | 3000 | 0x2000000000003067 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 819.892 | 1000 | 0x2000000000003EE4 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 826.992 | 800 | 0x200000000000432B {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 855.683 | 800 | 0x2000000000004301 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 864.021 | 900 | 0x2000000000000FAC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 900.205 | 1500 | 0x200000000000163D {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 913.873 | 1000 | 0x2000000000003EFC {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 939.962 | 800 | 0x200000000000437F {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 951.404 | 900 | 0x2000000000000FE8 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 979.718 | 900 | 0x2000000000000FCA {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 992.197 | 2000 | 0x2000000000001E23 {} |

### Tyrone Bay

Позиция: `6093.175 / 2.474 / 9121.157` м. Ключ / текст: `#AR-MapLocation_TyroneBay`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Kermovan | Harbors | 554.107 | 2500 | 0x200000000000015D {} |
| SupplyCache_S_FIA_05 | OtherContainers | 671.975 | 2000 | 0x2000000000004F78 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 685.416 | 400 | 0x2000000000001FBB {} |
| SupplyCache_S_FIA_04 | OtherContainers | 698.912 | 1500 | 0x200000000000116A {} |
| Base_PowerPlant_FIA_01 | OtherContainers | 713.828 | 2100 | 0x2000000000004987 {} |

### TYRONE RIDGE

Позиция: `4930.855 / 97.091 / 8758.914` м. Ключ / текст: `#AR-MapLocation_TyroneRidge`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 608.89 | 800 | 0x200000000000437F {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 618.255 | 900 | 0x2000000000000FE8 {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 646.249 | 900 | 0x2000000000000FCA {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 660.035 | 2000 | 0x2000000000001E23 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 720.795 | 800 | 0x2000000000004355 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 957.993 | 1000 | 0x2000000000003853 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 962.711 | 2000 | 0x2000000000004F40 {} |
| SP_T2H_Meaux | Harbors | 975.839 | unknown | 0x2000000000004E04 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 999.565 | 1500 | 0x2000000000001146 {} |

### Upper Fields

Позиция: `5705.467 / 85.791 / 5625.534` м. Ключ / текст: `#AR-MapLocation_UpperFields`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| E_LivingArea_S_FIA_01 | OtherContainers | 235.409 | 400 | 0x2000000000002016 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 292.445 | 3000 | 0x2000000000001220 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 301.333 | 1500 | 0x200000000000117C {} |
| VehicleMaintenance_M_Conflict_USSR_01 | OtherContainers | 304.482 | 600 | 0x2000000000001AD5 {} |
| E_LivingArea_S_FIA_01 | OtherContainers | 358.705 | 400 | 0x2000000000002071 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 834.316 | 3000 | 0x2000000000003056 {} |
| SupplyCache_S_FIA_06_Campaign_HQC | OtherContainers | 835.017 | 1000 | 0x2000000000003ECC {} |
| SupplyCache_S_FIA_04_Campaign_HQC | OtherContainers | 858.328 | 1500 | 0x200000000000162B {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 903.732 | 900 | 0x2000000000000F8E {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 944.487 | 800 | 0x20000000000042D7 {} |
| SupplyCache_S_FIA_05_Campaign_HQC | OtherContainers | 958.897 | 2000 | 0x2000000000001E07 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 963.648 | 800 | 0x20000000000042AD {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 969.331 | 900 | 0x2000000000000F70 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 986.222 | 800 | 0x2000000000004283 {} |

### Vernon

Позиция: `9243.437 / 59.721 / 2077.243` м. Ключ / текст: `#AR-MapLocation_Vernon`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 615.632 | 800 | 0x20000000000041DB {} |
| SupplyCache_S_FIA_01_Campaign_HQC | OtherContainers | 693.533 | 900 | 0x2000000000000F16 {} |
| SupplyCache_S_FIA_02_Campaign_HQC | OtherContainers | 699.747 | 800 | 0x2000000000004205 {} |
| SupplyCache_S_FIA_03_Campaign_HQC | OtherContainers | 717.155 | 3000 | 0x2000000000003045 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 803.386 | 1000 | 0x20000000000037DB {} |
| SupplyCache_S_FIA_05 | OtherContainers | 867.104 | 2000 | 0x2000000000004EDE {} |
| SupplyCache_S_FIA_03 | OtherContainers | 886.204 | 3000 | 0x20000000000011CB {} |
| SP_T1H_StPierre | Harbors | 908.675 | unknown | 0x2000000000003115 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 921.787 | 2000 | 0x2000000000004ED0 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 925.986 | 1500 | 0x2000000000001110 {} |

### Villeneuve

Позиция: `2838.686 / 86.345 / 6339.803` м. Ключ / текст: `#AR-MapLocation_Villeneuf`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| FieldHospital_M_FIA_01 | OtherContainers | 824.345 | 2000 | 0x2000000000002721 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 849.654 | 2000 | 0x2000000000004F5C {} |
| LivingArea_S_FIA_01 | OtherContainers | 860.057 | 400 | 0x20000000000007D2 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 873.964 | 1000 | 0x200000000000386B {} |
| VehicleMaintenance_M_USSR_01 | OtherContainers | 899.208 | 3400 | 0x2000000000001A01 {} |

### WESTERN HEIGHTS

Позиция: `7743.848 / 331.856 / 3341.014` м. Ключ / текст: `#AR-MapLocation_WesternHeights`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SupplyCache_S_FIA_06 | OtherContainers | 664.713 | 1000 | 0x20000000000038CB {} |
| SupplyCache_S_FIA_03 | OtherContainers | 681.538 | 3000 | 0x2000000000001253 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 685.357 | 3000 | 0x2000000000001242 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 693.338 | 2000 | 0x2000000000004F94 {} |
| SupplyCache_S_FIA_04 | OtherContainers | 695.321 | 1500 | 0x200000000000118E {} |
| SupplyCache_S_FIA_06 | OtherContainers | 705.342 | 1000 | 0x20000000000038B3 {} |
| E_VehicleMaintenance_S_FIA_01 | OtherContainers | 883.975 | 400 | 0x2000000000004AD5 {} |
| SupplyCache_S_FIA_03 | OtherContainers | 898.041 | 3000 | 0x20000000000011FE {} |
| SupplyCache_S_FIA_05 | OtherContainers | 904.732 | 2000 | 0x2000000000004F32 {} |
| SupplyCache_S_FIA_06 | OtherContainers | 944.791 | 1000 | 0x200000000000383B {} |
| LivingArea_S_FIA_01 | OtherContainers | 948.402 | 400 | 0x200000000000084E {} |
| SupplyCache_S_FIA_05 | OtherContainers | 997.791 | 2000 | 0x2000000000004F24 {} |

### Whitewater

Позиция: `10943.448 / 55.176 / 1988.266` м. Ключ / текст: `#AR-MapLocation_Whitewater`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_Lancre | Harbors | 739.731 | 1000 | 0x20000000000000C2 {} |
| SupplyCache_S_FIA_05 | OtherContainers | 995.553 | 2000 | 0x2000000000004ED0 {} |

### WOLF HILL

Позиция: `3854.084 / 162.955 / 4344.244` м. Ключ / текст: `#AR-MapLocation_WolfHill`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_HalcyonStrait | Harbors | 987.218 | 1500 | 0x2000000000000111 {} |

### Wolfstone

Позиция: `3792.898 / 157.733 / 4180.008` м. Ключ / текст: `#AR-MapLocation_Wolfstone`.

| Объект | Каталог | Расстояние, м | Вместимость в конфиге, припасы | ID объекта |
| --- | --- | ---: | ---: | --- |
| SP_T3H_HalcyonStrait | Harbors | 819.875 | 1500 | 0x2000000000000111 {} |

## Без сопоставления

Все объекты выбранных каталогов входят хотя бы в один радиус.

## Ограничения

Это справочник близости к точечной подписи карты: радиус не является областью локации или доказательством принадлежности игровой базе / ресурсной сети. Несколько совпадений сохраняются; их суммы не складываются в общий запас мира. Включены только OtherContainers и Harbors; ИИ, машины, HQ-кандидаты и декорации не добавлены.

Названия и координаты подписей прочитаны заново; объекты припасов сохраняют прежние проверенные снимки и даты сбора. Пустые подписи не включены; неразрешённые переводы и позиции обозначаются явно. Source ID — предварительные editor-идентификаторы, их устойчивость между версиями ещё не подтверждена.

В Markdown показаны только локации с объектами; типы подписей, ID локаций и локации без объектов сохранены в каноническом JSON для проверки и сравнения.
