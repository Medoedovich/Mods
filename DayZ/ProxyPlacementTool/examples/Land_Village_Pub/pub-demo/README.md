# Pub demo

[Русский](README-RU.md) · [All examples](../../README.md)

By **Medoedovich**. Building classname: **`Land_Village_Pub`**. Contains **8 proxy placements** from the pub demonstration recorded while preparing Proxy Placement Tool 1.0.0.

- [XML fragment](dispatch.xml)
- [In-game demonstration](https://youtu.be/EHs8mHtc7_s)

## Items

| Classname | Placements |
| --- | ---: |
| `Izh18Shotgun` | 1 |
| `Broom` | 1 |
| `HuntingKnife` | 1 |
| `Repeater` | 1 |
| `Ammo_357` | 1 |
| `CowboyHat_black` | 1 |
| `SodaCan_Kvass` | 1 |
| `WoodAxe` | 1 |

## Integration

Find `<group name="Land_Village_Pub">` in the target mission's `mapgroupproto.xml`. Add the attached `<proxy>` entries to its existing `<dispatch>`, or insert the attached `<dispatch>...</dispatch>` block if the group has none. Preserve its existing attributes, standard loot containers and other required settings.

The XML includes a `<prototype>`/`<group>` wrapper to identify the target class. Merge the dispatch content into your existing prototype; this file is not a replacement for the complete `mapgroupproto.xml`. The layout is class-based and can affect all instances of this pub using that prototype.

Check your `types.xml` settings and verify actual CE spawning and accessibility in the target mission. See [general example instructions](../../README.md#use-an-example).

## Provenance and validation

- Original export: `2026-11-24_13-54-46UTC_scene_2.xml`, last saved on 24 November 2026 at 17:19 Moscow time.
- The published XML preserves the original export's bytes, including all positions and rotations.
- SHA-256: `5AD9514F6C6092C4FCEDBFF74D51C5ED1875162DC385487DA2FB89476CAD1E10`.
- XML parsing confirms one `Land_Village_Pub` group and eight proxy entries. The author shared the layout in the community discussion on 27 November 2026.
- This specific layout is documented by the editor/in-game demonstration. A separate CE validation of this pub layout is not recorded here; test it in your target mission.
- No editable JSON project or still screenshots are included with this example.
