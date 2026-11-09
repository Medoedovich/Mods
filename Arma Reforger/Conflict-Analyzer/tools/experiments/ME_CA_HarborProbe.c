// Read-only observations: no grid update, generation, registration or scene save.
modded class SCR_GameModeCampaign
{
    protected int m_ME_HarborTicks;
    protected SCR_ResourceGenerator m_ME_HarborGenerator;
    protected string m_ME_HarborName;
    protected int m_ME_HarborSample;

    override void OnGameStart()
    {
        super.OnGameStart();
        if (!GetGame().InPlayMode() || !IsMaster()) return;
        if (!GetGame().GetMissionHeader() && System.IsCLIParam("ME_CA_NativeScenario"))
        {
            GetGame().GetCallqueue().CallLater(ME_HarborLaunch, 500, false);
            return;
        }
        PrintFormat("[ME_HARBOR] BEGIN game=%1 header=%2", GetGame().GetBuildVersion(), GetGame().GetMissionHeader() != null);
        GetGame().GetCallqueue().CallLater(ME_HarborTick, 1000, true);
    }
    protected void ME_HarborLaunch()
    {
        GetGame().PlayGameConfig("{0220741028718E7F}Missions/23_Campaign_HQC_Everon.conf", "B8F6E397105D4C2A");
    }
    protected void ME_HarborTick()
    {
        m_ME_HarborTicks++;
        if (m_ME_HarborTicks != 30 && m_ME_HarborTicks != 45) return;
        m_ME_HarborSample = m_ME_HarborTicks;
        array<SCR_CampaignMilitaryBaseComponent> bases = {};
        GetBaseManager().GetBases(bases);
        foreach (SCR_CampaignMilitaryBaseComponent base : bases)
        {
            if (!SCR_CampaignSourceBaseComponent.Cast(base)) continue;
            m_ME_HarborName = base.GetOwner().GetName();
            SCR_ResourceComponent resource = SCR_ResourceComponent.FindResourceComponent(base.GetOwner());
            m_ME_HarborGenerator = resource.GetGenerator(EResourceGeneratorID.DEFAULT, EResourceType.SUPPLIES);
            if (!m_ME_HarborGenerator) continue;
            vector pos = m_ME_HarborGenerator.GetOwnerOrigin();
            PrintFormat("[ME_HARBOR] BASE sample=%1 name=%2 x=%3 y=%4 z=%5 range=%6 isolated=%7 initialized=%8", m_ME_HarborSample, m_ME_HarborName, pos[0], pos[1], pos[2], m_ME_HarborGenerator.GetResourceGridRange(), m_ME_HarborGenerator.IsIsolated(), base.IsInitialized());
            GetGame().GetWorld().QueryEntitiesBySphere(pos, 300, ME_HarborEntity, null, EQueryEntitiesFlags.ALL);
        }
        PrintFormat("[ME_HARBOR] SAMPLE_END sample=%1", m_ME_HarborSample);
        if (m_ME_HarborTicks == 45)
        {
            Print("[ME_HARBOR] COMPLETE");
            GetGame().GetCallqueue().Remove(ME_HarborTick);
        }
    }
    protected bool ME_HarborEntity(IEntity entity)
    {
        SCR_ResourceComponent resource = SCR_ResourceComponent.FindResourceComponent(entity);
        if (!resource) return true;
        array<SCR_ResourceContainer> containers = resource.GetContainers();
        if (!containers) return true;
        foreach (int index, SCR_ResourceContainer container : containers)
        {
            if (container.GetResourceType() != EResourceType.SUPPLIES) continue;
            vector pos = entity.GetOrigin();
            int x = Math.Round(pos[0] * 1000);
            int y = Math.Round(pos[1] * 1000);
            int z = Math.Round(pos[2] * 1000);
            bool virtualSlot = SCR_ResourceContainerVirtual.Cast(container) != null;
            PrintFormat("[ME_HARBOR] SLOT sample=%1 harbor=%2 entity=%3 index=%4 virtual=%5 xMm=%6 yMm=%7 zMm=%8", m_ME_HarborSample, m_ME_HarborName, entity.GetID(), index, virtualSlot, x, y, z);
            PrintFormat("[ME_HARBOR] CHECK sample=%1 harbor=%2 entity=%3 index=%4 isolated=%5 allowed=%6 inRange=%7 linked=%8", m_ME_HarborSample, m_ME_HarborName, entity.GetID(), index, container.IsIsolated(), m_ME_HarborGenerator.CanInteractWith(container), container.IsInRange(m_ME_HarborGenerator.GetOwnerOrigin(), m_ME_HarborGenerator.GetResourceGridRange()), container.IsInteractorLinked(m_ME_HarborGenerator));
            PrintFormat("[ME_HARBOR] PREFAB sample=%1 harbor=%2 entity=%3 index=%4 path=%5", m_ME_HarborSample, m_ME_HarborName, entity.GetID(), index, entity.GetPrefabData().GetPrefabName());
        }
        return true;
    }
}
