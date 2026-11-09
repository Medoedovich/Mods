//! Explicit source-base report; unrelated entities and fields are never serialized.
class ME_CA_ReportSubscene
{
	int index;
	string name;
}

class ME_CA_SupplySourceRecord
{
	string sourceId;
	string parentSourceId;
	string name;
	ResourceName prefab;
	int subscene;
	string layer;
	string positionStatus;
	ref array<float> worldPositionMeters = {};
	ref array<ref ME_CA_DiagnosticField> fields = {};
}

class ME_CA_SupplySourcesReport
{
	int schemaVersion = 2;
	string kind = "supply-source-bases";
	string analyzerVersion = "supply-source-bases-0.1";
	string status = "partial";
	string selection = "SCR_CampaignSourceBaseComponent";
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
	ref array<ref ME_CA_SupplySourceRecord> records = {};
}

[WorkbenchPluginAttribute(name: "Export supply source bases", description: "Read only source-base names, positions, enabled state and replenishment fields into a separate JSON report.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Reports")]
class ME_CA_SupplySourcesPlugin : ME_CA_WorldDiagnosticsPlugin
{
	override protected bool IsRelevant(string className)
	{
		return className == "SCR_CampaignSourceBaseComponent";
	}

	override protected bool ShouldReadField(BaseContainer container, string fieldName)
	{
		if (container.GetClassName() != "SCR_CampaignSourceBaseComponent")
			return false;
		return fieldName == "Enabled" || fieldName == "m_sBaseName" || fieldName == "m_iRegularSuppliesIncomeBase" || fieldName == "m_iSuppliesArrivalInterval";
	}

	override protected void ConfigureReport()
	{
		m_Report.analyzerVersion = "supply-source-bases-0.1";
		m_Report.warnings.Clear();
		m_Report.warnings.Insert("Only configured source-base settings are exported; capacity and runtime income conditions are not analyzed.");
		m_Report.warnings.Insert("Source IDs are provisional editor identifiers; cross-version identity is not verified.");
		m_Report.warnings.Insert("Nearest prefab is an owner reference; exact defining resources and localized location names are not resolved.");
	}

	override protected string GetExportStem()
	{
		return "ME_CA_SupplySources";
	}

	override protected bool WriteReport(JsonSaveContext context)
	{
		ME_CA_SupplySourcesReport report = new ME_CA_SupplySourcesReport();
		report.worldPath = m_Report.worldPath;
		report.gameVersion = m_Report.gameVersion;
		report.generatedAtUTC = m_Report.generatedAtUTC;
		report.outputPath = m_Report.outputPath;
		report.subsceneCount = m_Report.subsceneCount;
		report.editorEntityCountBefore = m_Report.editorEntityCountBefore;
		report.editorEntityCountAfter = m_Report.editorEntityCountAfter;
		report.visitedSourceCount = m_Report.visitedSourceCount;
		report.coordinateMismatchCount = m_Report.coordinateMismatchCount;
		report.editorEntityCountUnchanged = m_Report.editorEntityCountUnchanged;
		report.warnings.Copy(m_Report.warnings);
		for (int index = 0; index < report.subsceneCount; index++)
		{
			ME_CA_ReportSubscene scene = new ME_CA_ReportSubscene();
			scene.index = index;
			scene.name = m_Api.GetWorld().GetSubSceneName(index);
			report.subscenes.Insert(scene);
		}
		foreach (ME_CA_DiagnosticEntity entity : m_Report.entities)
		{
			ME_CA_SupplySourceRecord record = new ME_CA_SupplySourceRecord();
			record.sourceId = entity.sourceId;
			record.parentSourceId = entity.parentSourceId;
			record.name = entity.name;
			record.prefab = entity.prefab;
			record.subscene = entity.subscene;
			record.layer = entity.layer;
			record.positionStatus = entity.positionStatus;
			record.worldPositionMeters.Copy(entity.worldPosition);
			foreach (ME_CA_DiagnosticComponent component : entity.components)
			{
				foreach (ME_CA_DiagnosticField field : component.fields)
					record.fields.Insert(field);
			}
			report.records.Insert(record);
		}
		report.recordCount = report.records.Count();
		return context.WriteValue("", report);
	}
}
