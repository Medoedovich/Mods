//! Read-only CampaignRemnantsSupplyDepot markers and selected component settings.
class ME_CA_SupplyDepotRecord
{
	string sourceId;
	string parentSourceId;
	string sourceName;
	ResourceName prefab;
	int subscene;
	string layer;
	string positionStatus;
	ref array<float> worldPositionMeters = {};
	ref array<ref ME_CA_DiagnosticComponent> components = {};
}

class ME_CA_SupplyDepotsReport
{
	int schemaVersion = 2;
	string kind = "campaign-remnants-supply-depots";
	string analyzerVersion = "supply-depots-0.1";
	string status = "partial";
	string selection = "CampaignRemnantsSupplyDepot-prefab";
	string worldPath;
	string gameVersion;
	string generatedAtUTC;
	string outputPath;
	int subsceneCount;
	int editorEntityCountBefore;
	int editorEntityCountAfter;
	int visitedSourceCount;
	int recordCount;
	int coordinateMismatchCount;
	bool editorEntityCountUnchanged;
	ref array<ref ME_CA_ReportSubscene> subscenes = {};
	ref array<string> warnings = {};
	ref array<ref ME_CA_SupplyDepotRecord> records = {};
}

[WorkbenchPluginAttribute(name: "Export campaign supply depots", description: "Read CampaignRemnantsSupplyDepot marker sources, coordinates and selected component settings.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Reports")]
class ME_CA_SupplyDepotsPlugin : ME_CA_WorldDiagnosticsPlugin
{
	protected ref ME_CA_SupplyDepotsReport m_Depots;

	override protected void ConfigureReport()
	{
		m_Depots = new ME_CA_SupplyDepotsReport();
		m_Report.analyzerVersion = "supply-depots-0.1";
		m_Report.warnings.Clear();
	}

	override protected bool ShouldReadField(BaseContainer container, string fieldName)
	{
		if (container.GetClassName() == "SCR_CampaignSuppliesComponent")
			return fieldName == "Enabled" || fieldName == "m_iSupplies" || fieldName == "m_iSuppliesMax" || fieldName == "m_fOperationalRadius" || fieldName == "m_bIsStandaloneDepot";
		if (container.GetClassName() == "SCR_MapDescriptorComponent")
			return fieldName == "DisplayName" || fieldName == "MainType" || fieldName == "UnitType";
		return false;
	}

	override protected void Visit(IEntitySource source, int depth)
	{
		if (!source || m_Visited.Contains(source))
			return;
		m_Visited.Insert(source, true);
		if (depth > 256)
		{
			m_Report.warnings.Insert("Source hierarchy depth limit reached.");
			return;
		}
		ResourceName prefab = SCR_BaseContainerTools.GetPrefabResourceName(source);
		if (prefab.EndsWith("/CampaignRemnantsSupplyDepot.et"))
		{
			ME_CA_DiagnosticEntity entity = Describe(source);
			ME_CA_SupplyDepotRecord record = new ME_CA_SupplyDepotRecord();
			record.sourceId = entity.sourceId;
			record.parentSourceId = entity.parentSourceId;
			record.sourceName = entity.name;
			record.prefab = entity.prefab;
			record.subscene = entity.subscene;
			record.layer = entity.layer;
			record.positionStatus = entity.positionStatus;
			record.worldPositionMeters.Copy(entity.worldPosition);
			for (int index = 0; index < source.GetComponentCount(); index++)
			{
				IEntityComponentSource component = source.GetComponent(index);
				if (!component || (component.GetClassName() != "SCR_CampaignSuppliesComponent" && component.GetClassName() != "SCR_MapDescriptorComponent"))
					continue;
				ME_CA_DiagnosticComponent selected = new ME_CA_DiagnosticComponent();
				selected.className = component.GetClassName();
				ReadFields(component, selected.fields);
				record.components.Insert(selected);
			}
			m_Depots.records.Insert(record);
		}
		for (int child = 0; child < source.GetNumChildren(); child++)
			Visit(IEntitySource.Cast(source.GetChild(child)), depth + 1);
	}

	override protected string GetExportStem()
	{
		return "ME_CA_SupplyDepots";
	}

	override protected bool WriteReport(JsonSaveContext context)
	{
		m_Depots.worldPath = m_Report.worldPath;
		m_Depots.gameVersion = m_Report.gameVersion;
		m_Depots.generatedAtUTC = m_Report.generatedAtUTC;
		m_Depots.outputPath = m_Report.outputPath;
		m_Depots.subsceneCount = m_Report.subsceneCount;
		m_Depots.editorEntityCountBefore = m_Report.editorEntityCountBefore;
		m_Depots.editorEntityCountAfter = m_Report.editorEntityCountAfter;
		m_Depots.editorEntityCountUnchanged = m_Report.editorEntityCountUnchanged;
		m_Depots.visitedSourceCount = m_Report.visitedSourceCount;
		m_Depots.coordinateMismatchCount = m_Report.coordinateMismatchCount;
		m_Depots.recordCount = m_Depots.records.Count();
		m_Report.diagnosticEntityCount = m_Depots.recordCount;
		m_Depots.warnings.Copy(m_Report.warnings);
		m_Depots.warnings.Insert("Configured campaign component values are separate from physical container capacity and runtime stock.");
		m_Depots.warnings.Insert("Depot markers are selected by their nearest CampaignRemnantsSupplyDepot prefab; proximity does not establish source parenting or runtime membership.");
		for (int index = 0; index < m_Depots.subsceneCount; index++)
		{
			ME_CA_ReportSubscene scene = new ME_CA_ReportSubscene();
			scene.index = index;
			scene.name = m_Api.GetWorld().GetSubSceneName(index);
			m_Depots.subscenes.Insert(scene);
		}
		return context.WriteValue("", m_Depots);
	}
}
