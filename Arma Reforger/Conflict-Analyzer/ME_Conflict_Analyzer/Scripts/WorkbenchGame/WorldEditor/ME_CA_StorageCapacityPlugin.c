//! Configured storage composition below one explicitly named source base.
class ME_CA_StorageNode
{
	string sourceId;
	string parentSourceId;
	string name;
	ResourceName prefab;
	int subscene;
	string layer;
	string positionStatus;
	ref array<float> worldPositionMeters = {};
}

//! Targeted inventory of configured SUPPLIES slots in every loaded subscene.
class ME_CA_WorldSupplyContainersReport
{
	int schemaVersion = 2;
	string kind = "world-supply-containers";
	string analyzerVersion = "world-supply-containers-0.1";
	string status = "partial";
	string selection = "SCR_ResourceComponent-SUPPLIES-and-unresolved-slots";
	string worldPath;
	string gameVersion;
	string generatedAtUTC;
	string outputPath;
	int subsceneCount;
	int editorEntityCountBefore;
	int editorEntityCountAfter;
	int visitedSourceCount;
	int inspectedResourceComponentCount;
	int filteredNonSuppliesSlotCount;
	int recordCount;
	int coordinateMismatchCount;
	bool editorEntityCountUnchanged;
	ref array<ref ME_CA_ReportSubscene> subscenes = {};
	ref array<string> warnings = {};
	ref array<ref ME_CA_StorageNode> nodes = {};
	ref array<ref ME_CA_StorageResource> resources = {};
}

[WorkbenchPluginAttribute(name: "Export world supplies containers", description: "Read configured physical supplies slots and virtual views across all loaded subscenes.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Reports")]
class ME_CA_WorldSupplyContainersPlugin : ME_CA_StorageCapacityPlugin
{
	override protected void ConfigureReport()
	{
		m_BaseSource = null;
		m_NodeIds.Clear();
		m_Capacity = new ME_CA_StorageCapacityReport();
		m_Report.warnings.Clear();
		m_Report.analyzerVersion = "world-supply-containers-0.1";
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
		// Every source is inspected once; the inherited helper does not recurse here.
		InspectStorage(source, 0, false);
		for (int child = 0; child < source.GetNumChildren(); child++)
			Visit(IEntitySource.Cast(source.GetChild(child)), depth + 1);
	}

	override protected string GetExportStem()
	{
		return "ME_CA_WorldSupplyContainers";
	}

	override protected bool WriteReport(JsonSaveContext context)
	{
		ME_CA_WorldSupplyContainersReport report = new ME_CA_WorldSupplyContainersReport();
		report.worldPath = m_Report.worldPath;
		report.gameVersion = m_Report.gameVersion;
		report.generatedAtUTC = m_Report.generatedAtUTC;
		report.outputPath = m_Report.outputPath;
		report.subsceneCount = m_Report.subsceneCount;
		report.editorEntityCountBefore = m_Report.editorEntityCountBefore;
		report.editorEntityCountAfter = m_Report.editorEntityCountAfter;
		report.editorEntityCountUnchanged = m_Report.editorEntityCountUnchanged;
		report.visitedSourceCount = m_Report.visitedSourceCount;
		report.coordinateMismatchCount = m_Report.coordinateMismatchCount;
		report.inspectedResourceComponentCount = m_Capacity.resources.Count();
		report.warnings.Copy(m_Report.warnings);
		report.warnings.Insert("Configured editor containers only; runtime spawns, grid membership and dynamic construction are not analyzed.");
		report.warnings.Insert("Physical SUPPLIES slots and virtual views are separate; previously reported slots must be excluded by verified identity.");
		report.warnings.Insert("Unknown resource types and unknown lists are retained for completeness; source IDs are provisional editor identifiers.");
		ref map<string, ref ME_CA_StorageNode> nodes = new map<string, ref ME_CA_StorageNode>();
		foreach (ME_CA_StorageNode node : m_Capacity.nodes)
			nodes.Insert(node.sourceId, node);
		ref map<string, bool> needed = new map<string, bool>();
		foreach (ME_CA_StorageResource resource : m_Capacity.resources)
		{
			array<ref ME_CA_StorageContainer> selected = {};
			foreach (ME_CA_StorageContainer slot : resource.containers)
			{
				bool confirmedOther = false;
				foreach (ME_CA_DiagnosticField field : slot.fields)
				{
					if (field.name == "m_eResourceType" && field.status == "resolved" && !field.enumLabel.IsEmpty() && field.enumLabel != "SUPPLIES")
						confirmedOther = true;
				}
				if (confirmedOther)
					report.filteredNonSuppliesSlotCount++;
				else
					selected.Insert(slot);
			}
			resource.containers.Clear();
			foreach (ME_CA_StorageContainer selectedSlot : selected)
				resource.containers.Insert(selectedSlot);
			if (resource.containers.IsEmpty() && resource.containersStatus == "resolved")
				continue;
			report.resources.Insert(resource);
			string id = resource.sourceId;
			int ancestors = 0;
			while (!id.IsEmpty() && !needed.Contains(id))
			{
				if (!nodes.Contains(id) || ancestors > 256)
				{
					Fail("container_parent_hierarchy_unavailable");
					return false;
				}
				needed.Insert(id, true);
				id = nodes.Get(id).parentSourceId;
				ancestors++;
			}
		}
		foreach (ME_CA_StorageNode selectedNode : m_Capacity.nodes)
		{
			if (needed.Contains(selectedNode.sourceId))
				report.nodes.Insert(selectedNode);
		}
		for (int index = 0; index < report.subsceneCount; index++)
		{
			ME_CA_ReportSubscene scene = new ME_CA_ReportSubscene();
			scene.index = index;
			scene.name = m_Api.GetWorld().GetSubSceneName(index);
			report.subscenes.Insert(scene);
		}
		report.recordCount = report.resources.Count();
		m_Report.diagnosticEntityCount = report.recordCount;
		return context.WriteValue("", report);
	}
}

class ME_CA_StorageResource
{
	string sourceId;
	int componentIndex;
	string componentClass;
	string containersStatus;
	bool containersDirectOverride;
	ref array<ref ME_CA_DiagnosticField> fields = {};
	ref array<ref ME_CA_StorageContainer> containers = {};
}

class ME_CA_StorageContainer
{
	int index;
	string className;
	ref array<ref ME_CA_DiagnosticField> fields = {};
}

class ME_CA_StorageCapacityReport
{
	int schemaVersion = 2;
	string kind = "source-base-storage-capacity";
	string analyzerVersion = "storage-capacity-0.1";
	string status = "partial";
	string selection = "source-base-descendant-resource-containers";
	string baseName;
	string baseSourceId;
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
	ref array<ref ME_CA_StorageNode> nodes = {};
	ref array<ref ME_CA_StorageResource> resources = {};
}

class ME_CA_StorageCapacitySection
{
	string baseName;
	string baseSourceId;
	int recordCount;
	int coordinateMismatchCount;
	ref array<string> warnings = {};
	ref array<ref ME_CA_StorageNode> nodes = {};
	ref array<ref ME_CA_StorageResource> resources = {};
}

class ME_CA_StorageCapacityBatchReport
{
	int schemaVersion = 2;
	string kind = "source-bases-storage-capacity";
	string analyzerVersion = "storage-capacity-batch-0.1";
	string status = "partial";
	string selection = "all-source-base-descendant-resource-containers";
	string worldPath;
	string gameVersion;
	string generatedAtUTC;
	string outputPath;
	int subsceneCount;
	int editorEntityCountBefore;
	int editorEntityCountAfter;
	int visitedSourceCount;
	int baseCount;
	int recordCount;
	int coordinateMismatchCount;
	bool editorEntityCountUnchanged;
	ref array<ref ME_CA_ReportSubscene> subscenes = {};
	ref array<string> warnings = {};
	ref array<ref ME_CA_StorageCapacitySection> bases = {};
}

[WorkbenchPluginAttribute(name: "Inspect source base storage capacity", description: "Read configured containers below a named source base, or all source bases with -ME_CA_AllSourceBases=1.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Reports")]
class ME_CA_StorageCapacityPlugin : ME_CA_WorldDiagnosticsPlugin
{
	protected string m_BaseName;
	protected IEntitySource m_BaseSource;
	protected int m_BaseMatches;
	protected bool m_AllBases;
	protected ref array<IEntitySource> m_BaseSources = {};
	protected ref map<string, bool> m_NodeIds = new map<string, bool>();
	protected ref ME_CA_StorageCapacityReport m_Capacity;

	override protected void ConfigureReport()
	{
		m_BaseName = "SP_A_EveronAirport";
		WorldEditor editor = Workbench.GetModule(WorldEditor);
		string allBases;
		m_AllBases = editor.GetCmdLine("-ME_CA_AllSourceBases", allBases) && allBases == "1";
		string requested;
		if (editor.GetCmdLine("-ME_CA_BaseName", requested) && !requested.IsEmpty())
			m_BaseName = requested;
		m_BaseSource = null;
		m_BaseMatches = 0;
		m_BaseSources.Clear();
		m_NodeIds.Clear();
		m_Report.analyzerVersion = "storage-capacity-0.1";
		m_Report.warnings.Clear();
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
		if (m_AllBases || source.GetName() == m_BaseName)
		{
			for (int index = 0; index < source.GetComponentCount(); index++)
			{
				IEntityComponentSource component = source.GetComponent(index);
				if (component && component.GetClassName() == "SCR_CampaignSourceBaseComponent")
				{
					m_BaseMatches++;
					m_BaseSource = source;
					m_BaseSources.Insert(source);
					break;
				}
			}
		}
		for (int child = 0; child < source.GetNumChildren(); child++)
			Visit(IEntitySource.Cast(source.GetChild(child)), depth + 1);
	}

	override protected bool ShouldReadField(BaseContainer container, string fieldName)
	{
		if (container.GetClassName() == "SCR_ResourceComponent")
			return fieldName == "Enabled" || fieldName == "m_aDisabledResourceTypes";
		return fieldName == "m_eResourceType" || fieldName == "m_eStorageType" || fieldName == "m_fResourceValueMax" || fieldName == "m_fResourceValueCurrent";
	}

	protected void AddNode(IEntitySource source)
	{
		string id = source.GetID().ToString();
		if (m_NodeIds.Contains(id))
			return;
		IEntitySource parent = IEntitySource.Cast(source.GetParent());
		if (source != m_BaseSource && parent)
			AddNode(parent);
		ME_CA_DiagnosticEntity entity = Describe(source);
		ME_CA_StorageNode node = new ME_CA_StorageNode();
		node.sourceId = entity.sourceId;
		node.parentSourceId = entity.parentSourceId;
		node.name = entity.name;
		node.prefab = entity.prefab;
		node.subscene = entity.subscene;
		node.layer = entity.layer;
		node.positionStatus = entity.positionStatus;
		node.worldPositionMeters.Copy(entity.worldPosition);
		m_Capacity.nodes.Insert(node);
		m_NodeIds.Insert(id, true);
	}

	protected void InspectStorage(IEntitySource source, int depth, bool traverseChildren = true)
	{
		if (!source || depth > 256)
		{
			m_Capacity.warnings.Insert("Storage subtree depth limit reached or source unavailable.");
			return;
		}
		for (int index = 0; index < source.GetComponentCount(); index++)
		{
			IEntityComponentSource component = source.GetComponent(index);
			if (!component || component.GetClassName() != "SCR_ResourceComponent")
				continue;
			AddNode(source);
			ME_CA_StorageResource resource = new ME_CA_StorageResource();
			resource.sourceId = source.GetID().ToString();
			resource.componentIndex = index;
			resource.componentClass = component.GetClassName();
			resource.containersDirectOverride = component.IsVariableSetDirectly("m_aContainers");
			ReadFields(component, resource.fields);
			BaseContainerList containers = component.GetObjectArray("m_aContainers");
			resource.containersStatus = "unknown";
			if (containers)
			{
				resource.containersStatus = "resolved";
				for (int item = 0; item < containers.Count(); item++)
				{
					ME_CA_StorageContainer entry = new ME_CA_StorageContainer();
					entry.index = item;
					BaseContainer config = containers.Get(item);
					if (config)
					{
						entry.className = config.GetClassName();
						ReadFields(config, entry.fields);
					}
					resource.containers.Insert(entry);
				}
			}
			m_Capacity.resources.Insert(resource);
		}
		if (traverseChildren)
		{
			for (int child = 0; child < source.GetNumChildren(); child++)
				InspectStorage(IEntitySource.Cast(source.GetChild(child)), depth + 1);
		}
	}

	override protected string GetExportStem()
	{
		return "ME_CA_StorageCapacity";
	}

	protected ME_CA_StorageCapacityReport BuildSelectedReport()
	{
		m_NodeIds.Clear();
		int mismatchesBefore = m_Report.coordinateMismatchCount;
		m_Capacity = new ME_CA_StorageCapacityReport();
		m_Capacity.baseName = m_BaseSource.GetName();
		m_Capacity.baseSourceId = m_BaseSource.GetID().ToString();
		m_Capacity.worldPath = m_Report.worldPath;
		m_Capacity.gameVersion = m_Report.gameVersion;
		m_Capacity.generatedAtUTC = m_Report.generatedAtUTC;
		m_Capacity.outputPath = m_Report.outputPath;
		m_Capacity.subsceneCount = m_Report.subsceneCount;
		m_Capacity.editorEntityCountBefore = m_Report.editorEntityCountBefore;
		m_Capacity.editorEntityCountAfter = m_Report.editorEntityCountAfter;
		m_Capacity.visitedSourceCount = m_Report.visitedSourceCount;
		m_Capacity.editorEntityCountUnchanged = m_Report.editorEntityCountUnchanged;
		m_Capacity.warnings.Copy(m_Report.warnings);
		m_Capacity.warnings.Insert("Configured physical descendant capacity only; runtime grid membership and dynamically built storage are not analyzed.");
		m_Capacity.warnings.Insert("Virtual container views must not be added to physical capacity a second time.");
		m_Capacity.warnings.Insert("Prefab references identify owners, not exact inherited field definitions; editor IDs are provisional.");
		AddNode(m_BaseSource);
		InspectStorage(m_BaseSource, 0);
		m_Capacity.coordinateMismatchCount = m_Report.coordinateMismatchCount - mismatchesBefore;
		m_Capacity.recordCount = m_Capacity.resources.Count();
		m_Report.diagnosticEntityCount = m_Capacity.recordCount;
		for (int sceneIndex = 0; sceneIndex < m_Capacity.subsceneCount; sceneIndex++)
		{
			ME_CA_ReportSubscene scene = new ME_CA_ReportSubscene();
			scene.index = sceneIndex;
			scene.name = m_Api.GetWorld().GetSubSceneName(sceneIndex);
			m_Capacity.subscenes.Insert(scene);
		}
		return m_Capacity;
	}

	override protected bool WriteReport(JsonSaveContext context)
	{
		if (!m_AllBases)
		{
			if (m_BaseMatches != 1 || !m_BaseSource)
			{
				Fail("source_base_name_missing_or_ambiguous");
				return false;
			}
			return context.WriteValue("", BuildSelectedReport());
		}
		if (m_BaseSources.IsEmpty())
		{
			Fail("no_source_bases_found");
			return false;
		}
		ME_CA_StorageCapacityBatchReport batch = new ME_CA_StorageCapacityBatchReport();
		batch.worldPath = m_Report.worldPath;
		batch.gameVersion = m_Report.gameVersion;
		batch.generatedAtUTC = m_Report.generatedAtUTC;
		batch.outputPath = m_Report.outputPath;
		batch.subsceneCount = m_Report.subsceneCount;
		batch.editorEntityCountBefore = m_Report.editorEntityCountBefore;
		batch.editorEntityCountAfter = m_Report.editorEntityCountAfter;
		batch.editorEntityCountUnchanged = m_Report.editorEntityCountUnchanged;
		batch.visitedSourceCount = m_Report.visitedSourceCount;
		batch.warnings.Copy(m_Report.warnings);
		foreach (IEntitySource baseSource : m_BaseSources)
		{
			m_BaseSource = baseSource;
			ME_CA_StorageCapacityReport selected = BuildSelectedReport();
			ME_CA_StorageCapacitySection section = new ME_CA_StorageCapacitySection();
			section.baseName = selected.baseName;
			section.baseSourceId = selected.baseSourceId;
			section.recordCount = selected.recordCount;
			section.coordinateMismatchCount = selected.coordinateMismatchCount;
			foreach (ME_CA_StorageNode node : selected.nodes)
				section.nodes.Insert(node);
			foreach (ME_CA_StorageResource resource : selected.resources)
				section.resources.Insert(resource);
			section.warnings.Copy(selected.warnings);
			batch.bases.Insert(section);
			batch.recordCount += section.recordCount;
		}
		batch.baseCount = batch.bases.Count();
		batch.coordinateMismatchCount = m_Report.coordinateMismatchCount;
		m_Report.diagnosticEntityCount = batch.recordCount;
		for (int index = 0; index < batch.subsceneCount; index++)
		{
			ME_CA_ReportSubscene scene = new ME_CA_ReportSubscene();
			scene.index = index;
			scene.name = m_Api.GetWorld().GetSubSceneName(index);
			batch.subscenes.Insert(scene);
		}
		return context.WriteValue("", batch);
	}
}
