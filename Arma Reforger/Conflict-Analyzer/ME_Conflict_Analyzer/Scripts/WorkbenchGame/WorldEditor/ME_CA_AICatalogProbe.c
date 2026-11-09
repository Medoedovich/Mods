[WorkbenchPluginAttribute(name: "Read ambient AI catalog", wbModules: {"WorldEditor"}, category: "[ME] Conflict Analyzer/Diagnostics")]
class ME_CA_AICatalogProbe : WorldEditorPlugin
{
    int m_Index;
    override void RunCommandline() { Run(); }
    override void Run()
    {
        PrintFormat("[ME_CA_AI_CATALOG] BEGIN|%1", GetGame().GetBuildVersion());
        Resource resource = Resource.Load("Configs/Factions/FIA_Campaign.conf");
        if (!resource || !resource.GetResource()) { Print("[ME_CA_AI_CATALOG] ERROR|faction"); return; }
        Visit(resource.GetResource().ToBaseContainer(), 0);
        PrintFormat("[ME_CA_AI_CATALOG] COMPLETE|%1", m_Index);
    }
    void Visit(BaseContainer container, int depth)
    {
        if (!container || depth > 16) return;
        if (container.GetClassName() == "SCR_EntityCatalogEntry")
        {
            BaseContainerList data = container.GetObjectArray("m_aEntityDataList");
            if (data)
            {
                for (int d = 0; d < data.Count(); d++)
                {
                    BaseContainer ambient = data.Get(d);
                    if (ambient.GetClassName() != "SCR_EntityCatalogAmbientPatrolData") continue;
                    ResourceName prefab; int groupType; float probability; bool enabled;
                    bool ok = container.Get("m_sEntityPrefab", prefab);
                    ok = container.Get("m_bEnabled", enabled) && ok;
                    ok = ambient.Get("m_eGroupType", groupType) && ok;
                    ok = ambient.Get("m_fProbabilityOfPresence", probability) && ok;
                    Resource group = Resource.Load(prefab);
                    if (!group || !group.GetResource()) { PrintFormat("[ME_CA_AI_CATALOG] ERROR|%1", prefab); continue; }
                    BaseContainer source = group.GetResource().ToBaseContainer();
                    array<ResourceName> units = {};
                    bool immediate;
                    ok = source.Get("m_aUnitPrefabSlots", units) && ok;
                    ok = source.Get("m_bSpawnImmediately", immediate) && ok;
                    PrintFormat("[ME_CA_AI_CATALOG] ENTRY|%1|%2|%3|%4|%5|%6|%7", m_Index, groupType, probability, enabled, prefab, units.Count(), ok);
                    foreach (ResourceName unit : units) PrintFormat("[ME_CA_AI_CATALOG] UNIT|%1|%2", m_Index, unit);
                    PrintFormat("[ME_CA_AI_CATALOG] IMMEDIATE|%1|%2", m_Index, immediate);
                    m_Index++;
                }
            }
        }
        array<string> fields = {"m_aEntityCatalogs", "m_aEntityEntryList", "m_aMultiLists", "m_aEntities"};
        foreach (string field : fields)
        {
            BaseContainerList children = container.GetObjectArray(field);
            if (!children) continue;
            for (int i = 0; i < children.Count(); i++) Visit(children.Get(i), depth + 1);
        }
    }
}
