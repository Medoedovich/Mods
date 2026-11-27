# Loot placement examples

[Русский](README-RU.md) · [Editor instructions](../README.md)

Shared arrangements created with Proxy Placement Tool. Each example contains an exported CE XML fragment and instructions for its building/wreck class. Examples can be added independently of editor releases.

| Building/wreck classname | Layout | Items | Demonstration |
| --- | --- | ---: | --- |
| `Land_Village_Pub` | [Pub demo](Land_Village_Pub/pub-demo/README.md) | 8 | [Video](https://youtu.be/EHs8mHtc7_s) |

## Use an example

1. Open the layout's page and download its XML file. On GitHub, open the file and use **Download raw file** or save the **Raw** view as an XML file.
2. Find the matching `<group name="...">` in the target mission's `mapgroupproto.xml`.
3. If the group already has a `<dispatch>` section, merge the example's `<proxy>` entries into it. Otherwise, add the example's `<dispatch>...</dispatch>` block inside the existing group.
4. Preserve the group's attributes, standard loot containers and other settings you need. The example is a fragment, not a complete mission configuration.
5. Check the relevant `types.xml` settings and test actual CE spawning, positions, rotations, pickup actions and Vicinity in your mission. Follow the [placement checks](../README.md#placement-checks).

A prototype is defined by building classname and can affect all matching instances using that prototype. Choose the layout you want for that class. Combining layouts adds their items together; importing the same entries twice can duplicate placements.

Each example states its validation status. Editor/character previews and demonstration footage do not by themselves confirm actual CE spawning in a target mission.

## Store another layout

Create a folder under `examples/<building classname>/<layout name>/`, for example `examples/Land_Village_Pub/pub-demo/`. Use a short descriptive layout name so several arrangements for the same class can coexist.

Include:

- `dispatch.xml`: the original exported XML fragment, with its positions and rotations preserved.
- `README.md` and `README-RU.md`: building classname, description, item list, integration instructions and what was actually checked.
- Optionally, the editor's saved JSON project for reopening the scene and real screenshots or a video link. Exporting XML and saving a project are separate actions; keep both when you want an editable example.

The current pub example contains XML and a video link; an editable project and screenshots are not included.

Share your arrangements and feedback in the [DayZ Modders discussion](https://discord.com/channels/452035973786632194/1575067129089228870/1575067129089228870).
