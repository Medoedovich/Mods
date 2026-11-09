//! Configured named map descriptors; positions use the shared editor validation.
class ME_CA_NamedLocation
{
	string sourceId;
	string parentSourceId;
	string sourceName;
	ResourceName prefab;
	int subscene;
	string layer;
	int componentIndex;
	string componentClass;
	string rawName;
	string displayName;
	string nameStatus;
	string nameMethod;
	string positionStatus;
	ref array<float> worldPositionMeters = {};
	ref array<ref ME_CA_DiagnosticField> fields = {};
}

class ME_CA_NamedLocationsReport
{
	int schemaVersion = 2;
	string kind = "named-world-locations";
	string analyzerVersion = "named-locations-0.1";
	string status = "partial";
	string selection = "named-map-descriptor-DisplayName";
	string worldPath;
	string gameVersion;
	string generatedAtUTC;
	string outputPath;
	string language;
	int subsceneCount;
	int editorEntityCountBefore;
	int editorEntityCountAfter;
	int visitedSourceCount;
	int inspectedDescriptorCount;
	int unnamedDescriptorCount;
	int recordCount;
	int coordinateMismatchCount;
	bool editorEntityCountUnchanged;
	ref array<ref ME_CA_ReportSubscene> subscenes = {};
	ref array<string> warnings = {};
	ref array<ref ME_CA_NamedLocation> locations = {};
}

[WorkbenchPluginAttribute(name: "Export named world locations", description: "Read named map descriptor positions and localized labels across all loaded subscenes.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Reports")]
class ME_CA_LocationsPlugin : ME_CA_WorldDiagnosticsPlugin
{
	protected ref ME_CA_NamedLocationsReport m_Locations;

	override protected void ConfigureReport()
	{
		m_Locations = new ME_CA_NamedLocationsReport();
		WidgetManager.GetLanguage(m_Locations.language);
		m_Report.warnings.Clear();
		m_Report.analyzerVersion = "named-locations-0.1";
	}

	override protected bool ShouldReadField(BaseContainer container, string fieldName)
	{
		return fieldName == "DisplayName" || fieldName == "MainType" || fieldName == "UnitType";
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
		for (int index = 0; index < source.GetComponentCount(); index++)
		{
			IEntityComponentSource component = source.GetComponent(index);
			if (!component || !component.GetClassName().Contains("MapDescriptor"))
				continue;
			m_Locations.inspectedDescriptorCount++;
			string rawName;
			if (!component.Get("DisplayName", rawName) || rawName.IsEmpty())
			{
				m_Locations.unnamedDescriptorCount++;
				continue;
			}
			ME_CA_DiagnosticEntity entity = Describe(source);
			ME_CA_NamedLocation record = new ME_CA_NamedLocation();
			record.sourceId = entity.sourceId;
			record.parentSourceId = entity.parentSourceId;
			record.sourceName = entity.name;
			record.prefab = entity.prefab;
			record.subscene = entity.subscene;
			record.layer = entity.layer;
			record.componentIndex = index;
			record.componentClass = component.GetClassName();
			record.rawName = rawName;
			record.displayName = WidgetManager.Translate(rawName);
			record.nameMethod = "literal";
			record.nameStatus = "resolved";
			if (rawName.StartsWith("#"))
			{
				record.nameMethod = "WidgetManager.Translate";
				if (record.displayName.IsEmpty() || record.displayName == rawName || record.displayName.StartsWith("#"))
					record.nameStatus = "unknown";
			}
			record.positionStatus = entity.positionStatus;
			record.worldPositionMeters.Copy(entity.worldPosition);
			ReadFields(component, record.fields);
			m_Locations.locations.Insert(record);
		}
		for (int child = 0; child < source.GetNumChildren(); child++)
			Visit(IEntitySource.Cast(source.GetChild(child)), depth + 1);
	}

	override protected string GetExportStem()
	{
		return "ME_CA_NamedLocations";
	}

	override protected bool WriteReport(JsonSaveContext context)
	{
		m_Locations.worldPath = m_Report.worldPath;
		m_Locations.gameVersion = m_Report.gameVersion;
		m_Locations.generatedAtUTC = m_Report.generatedAtUTC;
		m_Locations.outputPath = m_Report.outputPath;
		m_Locations.subsceneCount = m_Report.subsceneCount;
		m_Locations.editorEntityCountBefore = m_Report.editorEntityCountBefore;
		m_Locations.editorEntityCountAfter = m_Report.editorEntityCountAfter;
		m_Locations.editorEntityCountUnchanged = m_Report.editorEntityCountUnchanged;
		m_Locations.visitedSourceCount = m_Report.visitedSourceCount;
		m_Locations.coordinateMismatchCount = m_Report.coordinateMismatchCount;
		m_Locations.recordCount = m_Locations.locations.Count();
		m_Report.diagnosticEntityCount = m_Locations.recordCount;
		m_Locations.warnings.Copy(m_Report.warnings);
		m_Locations.warnings.Insert("Named configured map descriptors only; runtime label changes and unnamed descriptors are not included.");
		m_Locations.warnings.Insert("Nearby objects within a radius do not prove gameplay base or resource-grid ownership.");
		m_Locations.warnings.Insert("Source IDs are provisional editor identifiers; localization uses the current Workbench language.");
		for (int index = 0; index < m_Locations.subsceneCount; index++)
		{
			ME_CA_ReportSubscene scene = new ME_CA_ReportSubscene();
			scene.index = index;
			scene.name = m_Api.GetWorld().GetSubSceneName(index);
			m_Locations.subscenes.Insert(scene);
		}
		return context.WriteValue("", m_Locations);
	}
}
