//! Selected ConflictControlPoint source settings and localized base names.
class ME_CA_ControlPointRecord
{
	string sourceId;
	string parentSourceId;
	string sourceName;
	ResourceName prefab;
	int subscene;
	string layer;
	string positionStatus;
	ref array<float> worldPositionMeters = {};
	string rawName;
	string displayName;
	string nameStatus;
	string nameMethod;
	ref array<ref ME_CA_DiagnosticComponent> components = {};
}

class ME_CA_ControlPointsReport
{
	int schemaVersion = 2;
	string kind = "conflict-control-points";
	string analyzerVersion = "control-points-0.1";
	string status = "partial";
	string selection = "ConflictControlPoint-prefab";
	string worldPath;
	string gameVersion;
	string generatedAtUTC;
	string outputPath;
	string language;
	int subsceneCount;
	int editorEntityCountBefore;
	int editorEntityCountAfter;
	int visitedSourceCount;
	int recordCount;
	int coordinateMismatchCount;
	bool editorEntityCountUnchanged;
	ref array<ref ME_CA_ReportSubscene> subscenes = {};
	ref array<string> warnings = {};
	ref array<ref ME_CA_ControlPointRecord> records = {};
}

[WorkbenchPluginAttribute(name: "Export conflict control points", description: "Read ConflictControlPoint source names, positions and selected configured supplies fields.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Reports")]
class ME_CA_ControlPointsPlugin : ME_CA_WorldDiagnosticsPlugin
{
	protected ref ME_CA_ControlPointsReport m_ControlPoints;

	override protected void ConfigureReport()
	{
		m_ControlPoints = new ME_CA_ControlPointsReport();
		WidgetManager.GetLanguage(m_ControlPoints.language);
		m_Report.analyzerVersion = "control-points-0.1";
		m_Report.warnings.Clear();
	}

	override protected bool ShouldReadField(BaseContainer container, string fieldName)
	{
		if (container.GetClassName() == "SCR_CampaignSuppliesComponent")
			return fieldName == "Enabled" || fieldName == "m_iSupplies" || fieldName == "m_iSuppliesMax";
		if (container.GetClassName() == "SCR_CampaignMilitaryBaseComponent")
			return fieldName == "Enabled" || fieldName == "m_sBaseName" || fieldName == "m_iRadius";
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
		if (prefab.Contains("/ConflictControlPoint") && prefab.EndsWith(".et"))
		{
			ME_CA_DiagnosticEntity entity = Describe(source);
			ME_CA_ControlPointRecord record = new ME_CA_ControlPointRecord();
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
				if (!component || (component.GetClassName() != "SCR_CampaignSuppliesComponent" && component.GetClassName() != "SCR_CampaignMilitaryBaseComponent"))
					continue;
				ME_CA_DiagnosticComponent selected = new ME_CA_DiagnosticComponent();
				selected.className = component.GetClassName();
				ReadFields(component, selected.fields);
				record.components.Insert(selected);
				if (selected.className == "SCR_CampaignMilitaryBaseComponent")
					component.Get("m_sBaseName", record.rawName);
			}
			record.displayName = WidgetManager.Translate(record.rawName);
			record.nameMethod = "WidgetManager.Translate";
			record.nameStatus = "resolved";
			if (record.rawName.IsEmpty() || record.displayName.IsEmpty() || record.displayName.StartsWith("#"))
			{
				record.displayName = record.sourceName;
				record.nameMethod = "source_name_fallback";
				record.nameStatus = "unknown";
			}
			m_ControlPoints.records.Insert(record);
		}
		for (int child = 0; child < source.GetNumChildren(); child++)
			Visit(IEntitySource.Cast(source.GetChild(child)), depth + 1);
	}

	override protected string GetExportStem()
	{
		return "ME_CA_ControlPoints";
	}

	override protected bool WriteReport(JsonSaveContext context)
	{
		m_ControlPoints.worldPath = m_Report.worldPath;
		m_ControlPoints.gameVersion = m_Report.gameVersion;
		m_ControlPoints.generatedAtUTC = m_Report.generatedAtUTC;
		m_ControlPoints.outputPath = m_Report.outputPath;
		m_ControlPoints.subsceneCount = m_Report.subsceneCount;
		m_ControlPoints.editorEntityCountBefore = m_Report.editorEntityCountBefore;
		m_ControlPoints.editorEntityCountAfter = m_Report.editorEntityCountAfter;
		m_ControlPoints.editorEntityCountUnchanged = m_Report.editorEntityCountUnchanged;
		m_ControlPoints.visitedSourceCount = m_Report.visitedSourceCount;
		m_ControlPoints.coordinateMismatchCount = m_Report.coordinateMismatchCount;
		m_ControlPoints.recordCount = m_ControlPoints.records.Count();
		m_Report.diagnosticEntityCount = m_ControlPoints.recordCount;
		m_ControlPoints.warnings.Copy(m_Report.warnings);
		m_ControlPoints.warnings.Insert("Configured SCR_CampaignSuppliesComponent values only; they are not a sum of physical resource containers or a runtime stock measurement.");
		m_ControlPoints.warnings.Insert("Selection uses the nearest ConflictControlPoint prefab reference; unrelated prefab inheritance variants require separate investigation.");
		for (int index = 0; index < m_ControlPoints.subsceneCount; index++)
		{
			ME_CA_ReportSubscene scene = new ME_CA_ReportSubscene();
			scene.index = index;
			scene.name = m_Api.GetWorld().GetSubSceneName(index);
			m_ControlPoints.subscenes.Insert(scene);
		}
		return context.WriteValue("", m_ControlPoints);
	}
}
