# Conflict Analyzer — Workshop draft (English)

Internal note: unpublished draft. Source diagnostics are implemented; the complete gameplay report is still planned. Summary and Description blocks use plain text for copying into Workshop. Update the English and Russian versions together after verification.

## Summary

Workbench helper for investigating a Conflict world. The first prototype exports partial source diagnostics; complete AI, supply, starting base and vehicle reports are still in development.

## Description

Conflict Analyzer helps scenario authors investigate the configuration of a Conflict world. It is being developed into a tool for collecting readable reports without maintaining all the tables by hand.

Current status
• A World Editor diagnostic command reads selected source entities, component fields, layers, prefab references and world positions into partial JSON.
• Tested on CTI_Campaign_HQC_Eden.ent in Arma Reforger / Workbench 1.8.0.13.
• A repository-side converter builds a partial archived report of 18 supply source bases from the diagnostic JSON, with configured income per cycle, intervals in minutes and field provenance.
• A separate source-base command now exports only the selected component and four fields. Its report builder writes Harbors.json beside the generated table; the shared data.json is a section index.
• Added a selected-base storage inspection command. On Everon airport it resolves two storage compositions and five physical containers, totaling 4000 configured supplies capacity; virtual views are excluded from the sum. The subsequent batch covers all 18 source bases; runtime grid membership remains unverified.
• Added a storage-capacity column for all 18 source bases: 49 unique physical containers, 15 resolved descendant capacities and three unknown ownership cases. Income retains its earlier verified capture; nearby detached caches are not assigned by distance.
• Added a targeted world supplies inventory and OtherContainers report: 568 additional physical slots in 129 groups, 190700 configured capacity. Previously reported base containers are excluded after identity checks; 129 other virtual views remain separate. Detached cache ownership and runtime spawning remain unverified.
• OtherContainers now groups 568 physical slots into 124 root-parent rows, retaining individual records and separate prefab instances in JSON.
• CampaignRemnantsSupplyDepot markers receive named locations within 350 m first; storage within 100 m of a marker is then reserved before later stages. Counts: 49 under depots, 35 under control points, 13 under settlements, 23 under other locations and four unrecognized; source values are preserved.
• Locations shows 45 groups: seven control points, 18 Harbors, nine depots, four settlements and seven other locations. All 170 original named labels remain in JSON.
• Locations supports manual world-group review; four objects remain in the final Unrecognized category. Location/object coordinates and distances are preserved.
• Six categories cover supply depots, control points, Harbors, settlements, other locations and unrecognized objects. Depot priority restores five storage parents / 31 containers / 7100 capacity at Regina; proximity remains distinct from source hierarchy.
• Complete gameplay reports and version comparison are not implemented yet. This is an unpublished prototype.

• Provins and its five objects are linked to Transformer Station by explicit user instruction; the rule is limited to the exact pair, scenario and game version.

• Container tables now show combined capacity / initial values before composition; source IDs and separate container counts remain in JSON.

• Harbors now uses one 18-row table: capacity and physical composition next to the name, then replenishment interval / amount and coordinates. Repeated base headings and source notes are removed; unknown values are preserved.

• Supply depots are displayed under named locations: settlements within 350 m first, then the nearest other permitted label. Seven markers are located and two remain explicitly unlocated; location names and source values are preserved; container assignments use the new depot-first priority and 100 m radius.

• Current table and heading coordinates use three decimal places, with X Y Z separated by spaces for pasting into Workbench; JSON and geographic calculations retain the original precision.

• Supply depots use the location heading without a redundant depot subheading or marker coordinates; location/object coordinates and container lists are preserved. Full marker positions remain in JSON.

• Depot marker component settings are hidden in Markdown and retained in JSON; their gameplay effect is deferred for later investigation. Physical container tables, capacity/composition and grouping are unchanged.

• Each control point presents command-post storage and other storage in one table. Command-post initial supplies are 0 after its prefab action; later campaign initialization of the base resource grid is a separate stage and has not been measured.
• Seven control points now show command-post storage capacity 1000 and both compositions: 5 × 200 or 5 × 166 + 1 × 170. Workbench verifies FIA=5 / US=6 / USSR=6 physical slots, excluding the virtual representative; composition is calculated from installed code, with the runtime grid unmeasured.

Planned features
• AI spawn points, group types, faction, group composition and soldier counts, with random options and presence probabilities shown separately.
• Supply points and storage counts, initial supplies, capacity, replenishment amount and interval.
• Starting HQ candidates, their locations, starting supplies and supply generation settings.
• Vehicle spawn points, locations, allowed vehicle options and available spawn or respawn settings.
• A readable report with data sources and warnings for incomplete information.

Current diagnostic use
1. Open the addon project in Arma Reforger Workbench.
2. Open a saved Conflict world in World Editor.
3. Run Export world source diagnostics under [ME] Conflict Analyzer / Diagnostics. The repository also documents a verified CLI route through the Workbench log.

Diagnostics read the current editor state and do not save the source world. File export uses a separate directory; direct FileIO export still needs an interactive check.

Limitations
• Reading only the .ent file is not sufficient: related layers, parent worlds, prefabs and configuration resources must be resolved.
• Configured candidates and maximum possible counts do not guarantee what will spawn in a particular game session.
• Values depend on the world and game version. Missing resources must be reported as unknown rather than zero.
• Complete object-valued configurations and faction catalogs remain unresolved; the selected-base storage command reads only its required container settings. Found components are not gameplay totals or soldier counts.
• Runtime diagnostics and an in-game interface are outside the initial proposed scope.

Research update (Unreleased): a separate HQC Everon 1.8.0.13 runtime experiment observed 0 / 1000 supplies in all seven initial FIA command-post storages. The native mission-header run yielded one sample; a direct-world run yielded three stable samples. US / USSR remain unmeasured in gameplay. This is documented research, not an implemented runtime export command.

Unreleased: supply-depot storage matching now uses 200 m; HQC Everon r0034 assigns three previously ungrouped storage parents to one depot. Other depot memberships are unchanged.

Unreleased: separate configured initial-supplies summary by control points, docks, depots, towns and other objects. Deduplicates repeated location links and explicitly retains unknown dock storage; the known subtotal is 231200 in HQC Everon r0035.

Unreleased: five supply category folders now contain category summaries and 46 individual detail pages, linked from the overall summary. Existing configured totals and grouping are preserved.

Unreleased: all 46 detail pages now expose physical supply containers and their world coordinates. Existing totals are preserved; unknown dock storage and unmeasured runtime command-post container positions remain explicit.

Unreleased: harbor pages list detached storage within 100 m and between 100 and 200 m, with links to existing groups. This is a proximity overlay; categories, totals and runtime uncertainty are preserved.

Unreleased: harbor neighbor collection is limited to 100 m. More distant neighbors are excluded; existing categories and totals are preserved.

Unreleased / r0040: inspect individual physical and virtual harbor containers, compare storage-root positions, and display observed runtime range / isolation / interaction / link checks. Categories and supply totals are unchanged.

Unreleased / r0041: name generic harbor location pages after nearby dock source names and add reciprocal navigation links; storage assignments and totals remain unchanged.


Unreleased: StPhillipe combines dock storage and potential expansion storage in one page with an initial-supplies summary.


Unreleased: unified named pages for all 18 harbors, initial-supply summaries and linked potential-expansion groups where available; unknown values and accounting preserved.


Unreleased: include matching settlement and user-confirmed military-site groups on harbor pages; deduplicate shared storage roots and totals across location labels.

Unreleased / r0042: harbor summaries include associated expansion storage in the Harbors accounting category; original category provenance is retained and the world total is unchanged.

Unreleased / r0043: remove synthetic unknown stock for harbors without descendant storage; catalogued configured initial supplies remain 231200.

Unreleased / r0044: harbor storage groups use measured interaction eligibility, including ancestor virtual representations; actual refill is not confirmed.

Unreleased / r0045: eight starting HQ candidates, command-post capacity and configured refill amounts/intervals. Full runtime network capacity and refill remain unmeasured; candidate totals are not added to world stock.

Unreleased / r0046: existing StartingPos21 storage is accounted under starting bases, without double counting.

Unreleased / r0047: ambient FIA patrol catalog — 299 spawn points, 9 resolved group variants, location pages and conditional unit counts. Other AI mechanisms remain outside this first report.

The FIA ambient group reference now includes configured weapons per group and per character for all nine types, resolved from 1.8.0.13 prefabs. Runtime equipment and ammunition totals are not measured.
