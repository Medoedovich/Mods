//! Read-only source inventory for the open World Editor scene.
class ME_CA_DiagnosticField
{
	string name;
	string type;
	string status = "not_exported";
	string value;
	string enumLabel;
	bool directOverride;
	ref array<string> values = {};
}

class ME_CA_DiagnosticComponent
{
	string className;
	ResourceName sourcePrefab;
	ref array<ref ME_CA_DiagnosticField> fields = {};
}

class ME_CA_DiagnosticEntity
{
	string sourceId;
	string parentSourceId;
	string name;
	string className;
	ResourceName prefab;
	int subscene;
	string layer;
	string positionStatus = "unknown";
	string calculatedPositionMethod = "source-parent-matrices";
	int parentTransformCount;
	int rotatedParentCount;
	int scaledParentCount;
	bool terrainRelativeRoot;
	float terrainHeightOffset;
	ref array<string> parentSourceIds = {};
	ref array<float> localPosition = {};
	ref array<float> worldPosition = {};
	ref array<float> calculatedWorldPosition = {};
	float worldPositionDifference;
	ref array<ref ME_CA_DiagnosticField> fields = {};
	ref array<ref ME_CA_DiagnosticComponent> components = {};
}

class ME_CA_WorldDiagnostics
{
	int schemaVersion = 1;
	string analyzerVersion = "source-diagnostics-0.1";
	string kind = "editor-source-diagnostics";
	string status = "partial";
	string gameVersion;
	string generatedAtUTC;
	string worldPath;
	string outputPath;
	int subsceneCount;
	int editorEntityCountBefore;
	int editorEntityCountAfter;
	int visitedSourceCount;
	int diagnosticEntityCount;
	int coordinateMismatchCount;
	bool editorEntityCountUnchanged;
	ref array<string> warnings = {};
	ref array<ref ME_CA_DiagnosticEntity> entities = {};
}

[WorkbenchPluginAttribute(name: "Export world source diagnostics", description: "Read the open world's Conflict source entities, component fields and coordinates into JSON.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Diagnostics")]
class ME_CA_WorldDiagnosticsPlugin : WorldEditorPlugin
{
	protected ref map<IEntitySource, bool> m_Visited = new map<IEntitySource, bool>();
	protected ref map<string, ref ME_CA_DiagnosticEntity> m_Records = new map<string, ref ME_CA_DiagnosticEntity>();
	protected ref ME_CA_WorldDiagnostics m_Report;
	protected WorldEditorAPI m_Api;

	override void RunCommandline()
	{
		WorldEditor editor = Workbench.GetModule(WorldEditor);
		string requested;
		if (!editor || !editor.GetCmdLine("-ME_CA_World", requested) || requested.IsEmpty())
		{
			Fail("commandline_world_argument_required");
			return;
		}
		PrintFormat("[ME_CA] status=LOADING world=%1", requested);
		if (!editor.SetOpenedResource(requested))
		{
			Fail("world_load_failed_or_cancelled");
			return;
		}
		string loaded;
		if (editor.GetApi())
			editor.GetApi().GetWorldPath(loaded);
		if (NormalizePath(loaded) != NormalizePath(requested))
		{
			Fail("loaded_world_does_not_match_request");
			return;
		}
		Run();
	}

	override void Run()
	{
		WorldEditor editor = Workbench.GetModule(WorldEditor);
		if (!editor || !SCR_Global.IsEditMode())
		{
			Fail("world_editor_edit_mode_required");
			return;
		}
		m_Api = editor.GetApi();
		if (!m_Api || !m_Api.GetWorld())
		{
			Fail("open_world_required");
			return;
		}
		m_Report = new ME_CA_WorldDiagnostics();
		m_Api.GetWorldPath(m_Report.worldPath);
		m_Report.gameVersion = GetGame().GetBuildVersion();
		m_Report.generatedAtUTC = SCR_DateTimeHelper.GetDateTimeUTC();
		m_Report.subsceneCount = m_Api.GetNumSubScenes();
		m_Report.editorEntityCountBefore = m_Api.GetEditorEntityCount();
		m_Report.warnings.Insert("This is a diagnostic inventory, not a complete gameplay report.");
		m_Report.warnings.Insert("Source IDs are editor identifiers; cross-session stability must be checked before using them as comparison keys.");
		m_Report.warnings.Insert("Object-valued fields are listed but not recursively exported in this prototype.");
		ConfigureReport();
		m_Visited.Clear();
		m_Records.Clear();
		PrintFormat("[ME_CA] status=SCANNING world=%1 sources=%2 subscenes=%3", m_Report.worldPath, m_Report.editorEntityCountBefore, m_Report.subsceneCount);
		for (int index = 0; index < m_Report.editorEntityCountBefore; index++)
		{
			Visit(m_Api.GetEditorEntity(index), 0);
			if (index > 0 && index % 200000 == 0)
				PrintFormat("[ME_CA] status=PROGRESS enumerated=%1 total=%2 records=%3", index, m_Report.editorEntityCountBefore, m_Records.Count());
		}
		array<string> keys = {};
		for (int keyIndex = 0; keyIndex < m_Records.Count(); keyIndex++)
			keys.Insert(m_Records.GetKey(keyIndex));
		keys.Sort();
		foreach (string key : keys)
			m_Report.entities.Insert(m_Records.Get(key));
		m_Report.visitedSourceCount = m_Visited.Count();
		m_Report.diagnosticEntityCount = m_Report.entities.Count();
		m_Report.editorEntityCountAfter = m_Api.GetEditorEntityCount();
		m_Report.editorEntityCountUnchanged = m_Report.editorEntityCountBefore == m_Report.editorEntityCountAfter;
		string currentWorld;
		m_Api.GetWorldPath(currentWorld);
		if (!m_Report.editorEntityCountUnchanged || currentWorld != m_Report.worldPath)
		{
			Fail("world_changed_during_scan");
			Cleanup();
			return;
		}
		JsonSaveContext context = new JsonSaveContext();
		context.SetMaxDecimalPlaces(6);
		string logJson;
		if (editor.GetCmdLine("-ME_CA_LogJson", logJson) && logJson == "1")
		{
			m_Report.outputPath = "console-log";
			if (!WriteReport(context))
				Fail("json_serialization_failed");
			else
			{
				string json = context.SaveToString();
				json.Replace("\r", "");
				json.Replace("\n", "");
				PrintFormat("[ME_CA_JSON_BEGIN] characters=%1", json.Length());
				// Stay below Enforce's native substring buffer limit.
				for (int offset = 0; offset < json.Length(); offset += 4096)
					Print("[ME_CA_JSON_CHUNK] " + json.Substring(offset, Math.Min(4096, json.Length() - offset)));
				Print("[ME_CA_JSON_END]");
				PrintSuccess();
			}
			Cleanup();
			return;
		}
		string output;
		if (!ChooseOutputPath(editor, output))
		{
			Fail("output_path_unavailable_or_already_exists");
			Cleanup();
			return;
		}
		m_Report.outputPath = output;
		if (!WriteReport(context) || !context.SaveToFile(output))
			Fail("json_export_failed");
		else
			PrintSuccess();
		Cleanup();
	}

	protected void Visit(IEntitySource source, int depth)
	{
		if (!source || m_Visited.Contains(source))
			return;
		m_Visited.Insert(source, true);
		if (depth > 256)
		{
			m_Report.warnings.Insert("Source hierarchy depth limit reached.");
			return;
		}
		ME_CA_DiagnosticEntity record;
		for (int index = 0; index < source.GetComponentCount(); index++)
		{
			IEntityComponentSource component = source.GetComponent(index);
			if (!component || !IsRelevant(component.GetClassName()))
				continue;
			if (!record)
				record = Describe(source);
			ME_CA_DiagnosticComponent data = new ME_CA_DiagnosticComponent();
			data.className = component.GetClassName();
			data.sourcePrefab = SCR_BaseContainerTools.GetPrefabResourceName(component);
			ReadFields(component, data.fields);
			record.components.Insert(data);
		}
		if (!record && IsRelevant(source.GetClassName()))
			record = Describe(source);
		if (record)
		{
			ReadFields(source, record.fields);
			string key = string.Format("%1/%2/%3", record.subscene, record.layer, record.sourceId);
			if (m_Records.Contains(key))
			{
				m_Report.warnings.Insert("Ambiguous source identifier: " + key);
				key = key + "/" + m_Visited.Count().ToString();
			}
			m_Records.Insert(key, record);
		}
		for (int child = 0; child < source.GetNumChildren(); child++)
			Visit(IEntitySource.Cast(source.GetChild(child)), depth + 1);
	}

	protected bool IsRelevant(string className)
	{
		return className.StartsWith("SCR_Campaign") || className.StartsWith("SCR_Ambient") || className.StartsWith("SCR_Resource") || className == "SCR_FactionAffiliationComponent" || className == "SCR_GameModeCampaign" || className == "SCR_AIGroup" || className == "SCR_CacheManagerComponent";
	}

	// Targeted reports reuse traversal and coordinate validation, not the broad DTO.
	protected void ConfigureReport() {}

	protected bool WriteReport(JsonSaveContext context)
	{
		return context.WriteValue("", m_Report);
	}

	protected bool ShouldReadField(BaseContainer container, string fieldName)
	{
		return true;
	}

	protected string GetExportStem()
	{
		return "ME_CA_WorldDiagnostics";
	}

	protected ME_CA_DiagnosticEntity Describe(IEntitySource source)
	{
		ME_CA_DiagnosticEntity record = new ME_CA_DiagnosticEntity();
		record.sourceId = source.GetID().ToString();
		record.name = source.GetName();
		record.className = source.GetClassName();
		record.prefab = SCR_BaseContainerTools.GetPrefabResourceName(source);
		record.subscene = source.GetSubScene();
		if (record.subscene >= 0 && record.subscene < m_Report.subsceneCount)
			record.layer = m_Api.GetEntitySubsceneLayer(record.subscene, source);
		IEntitySource parent = IEntitySource.Cast(source.GetParent());
		if (parent)
			record.parentSourceId = parent.GetID().ToString();
		vector local;
		bool hasLocalPosition = source.Get("coords", local);
		if (hasLocalPosition)
			AppendVector(local, record.localPosition);
		IEntity entity = m_Api.SourceToEntity(source);
		if (entity)
		{
			vector world = entity.GetOrigin();
			AppendVector(world, record.worldPosition);
			if (!hasLocalPosition)
				return record;
			vector calculated;
			if (!CalculateWorldPosition(source, local, record, calculated))
				return record;
			AppendVector(calculated, record.calculatedWorldPosition);
			record.worldPositionDifference = vector.Distance(world, calculated);
			record.positionStatus = "resolved";
			if (record.worldPositionDifference > 0.02)
			{
				record.positionStatus = "mismatch";
				m_Report.coordinateMismatchCount++;
			}
		}
		return record;
	}

	protected bool CalculateWorldPosition(IEntitySource source, vector local, ME_CA_DiagnosticEntity record, out vector position)
	{
		position = local;
		IEntitySource root = source;
		IEntitySource parent = IEntitySource.Cast(source.GetParent());
		while (parent)
		{
			if (record.parentTransformCount >= 256)
				return false;
			vector coords;
			vector angles;
			float scale;
			if (!parent.Get("coords", coords) || !parent.Get("angles", angles) || !parent.Get("scale", scale))
				return false;
			vector transform[4];
			// Editor source angles are pitch/yaw/roll; Math3D expects yaw/pitch/roll.
			Math3D.AnglesToMatrix(Vector(angles[1], angles[0], angles[2]), transform);
			transform[0] = transform[0] * scale;
			transform[1] = transform[1] * scale;
			transform[2] = transform[2] * scale;
			transform[3] = coords;
			position = position.Multiply4(transform);
			record.parentSourceIds.Insert(parent.GetID().ToString());
			record.parentTransformCount++;
			if (angles.Length() > 0.00001)
				record.rotatedParentCount++;
			if (Math.AbsFloat(scale - 1) > 0.00001)
				record.scaledParentCount++;
			root = parent;
			parent = IEntitySource.Cast(parent.GetParent());
		}
		int flags;
		if (!root.Get("Flags", flags))
			return false;
		if ((flags & EntityFlags.RELATIVE_Y) != 0)
		{
			vector rootCoords;
			if (!root.Get("coords", rootCoords))
				return false;
			record.terrainRelativeRoot = true;
			record.terrainHeightOffset = m_Api.GetWorld().GetSurfaceY(rootCoords[0], rootCoords[2]);
			position[1] = position[1] + record.terrainHeightOffset;
		}
		return true;
	}

	protected void ReadFields(BaseContainer container, array<ref ME_CA_DiagnosticField> fields)
	{
		for (int index = 0; index < container.GetNumVars(); index++)
		{
			string fieldName = container.GetVarName(index);
			if (!ShouldReadField(container, fieldName))
				continue;
			// Source event callbacks are strings in the editor schema, not configuration.
			if (IEntitySource.Cast(container))
			{
				bool standardField = fieldName == "coords" || fieldName == "angles" || fieldName == "scale" || fieldName == "Flags" || fieldName.StartsWith("m_");
				string sourceClass = container.GetClassName();
				if (!standardField && (sourceClass == "GenericEntity" || sourceClass == "StaticModelEntity" || sourceClass == "SCR_DestructibleBuildingEntity"))
					continue;
				if (fieldName.StartsWith("EOn") || fieldName.StartsWith("_WB_") || fieldName.StartsWith("Rpl") || fieldName == "components" || fieldName == "editor" || fieldName == "editorData" || fieldName == "userScript" || fieldName == "constructor" || fieldName == "destructor" || fieldName == "OnTransformResetImpl")
					continue;
			}
			ME_CA_DiagnosticField field = new ME_CA_DiagnosticField();
			field.name = fieldName;
			field.directOverride = container.IsVariableSetDirectly(field.name);
			DataVarType dataType = container.GetDataVarType(index);
			field.type = typename.EnumToString(DataVarType, dataType);
			bool resolved = false;
			switch (dataType)
			{
				case DataVarType.INTEGER:
				case DataVarType.FLAGS:
					int integer;
					resolved = container.Get(field.name, integer);
					if (resolved)
					{
						field.value = integer.ToString();
						array<string> names = {};
						array<int> values = {};
						container.GetEnumValues(index, names, values);
						int enumIndex = values.Find(integer);
						if (enumIndex >= 0 && enumIndex < names.Count())
							field.enumLabel = names[enumIndex];
					}
					break;
				case DataVarType.SCALAR:
					float scalar;
					resolved = container.Get(field.name, scalar);
					if (resolved)
						field.value = scalar.ToString();
					break;
				case DataVarType.BOOLEAN:
					bool boolean;
					resolved = container.Get(field.name, boolean);
					if (resolved)
						field.value = boolean.ToString();
					break;
				case DataVarType.STRING:
				case DataVarType.RESOURCE_NAME:
					resolved = container.Get(field.name, field.value);
					break;
				case DataVarType.VECTOR3:
					vector position;
					resolved = container.Get(field.name, position);
					if (resolved)
						field.value = string.Format("%1 %2 %3", position[0], position[1], position[2]);
					break;
				case DataVarType.STRING_ARRAY:
				case DataVarType.RESOURCE_NAME_ARRAY:
					resolved = container.Get(field.name, field.values);
					break;
				case DataVarType.INTEGER_ARRAY:
					array<int> integers = {};
					resolved = container.Get(field.name, integers);
					if (resolved)
					{
						foreach (int integerValue : integers)
							field.values.Insert(integerValue.ToString());
					}
					break;
			}
			if (resolved)
				field.status = "resolved";
			fields.Insert(field);
		}
	}

	protected void AppendVector(vector position, array<float> values)
	{
		values.Insert(position[0]);
		values.Insert(position[1]);
		values.Insert(position[2]);
	}

	protected bool ChooseOutputPath(WorldEditor editor, out string output)
	{
		string addonRoot;
		if (!Workbench.GetAbsolutePath("$ME_Conflict_Analyzer:", addonRoot))
			return false;
		addonRoot.Replace("\\", "/");
		if (addonRoot.EndsWith("/"))
			addonRoot = addonRoot.Substring(0, addonRoot.Length() - 1);
		int separator = addonRoot.LastIndexOf("/");
		if (separator < 0)
			return false;
		string folder = addonRoot.Substring(0, separator) + "/exports";
		if (!FileIO.MakeDirectory(folder))
			return false;
		string filename;
		if (editor.GetCmdLine("-ME_CA_OutputFile", filename))
		{
			if (filename.IsEmpty() || !filename.EndsWith(".json") || filename.Contains("/") || filename.Contains("\\") || filename.Contains(":") || filename.Contains(".."))
				return false;
			output = folder + "/" + filename;
			return !FileIO.FileExists(output);
		}
		int index = 1;
		while (index <= 10000)
		{
			output = string.Format("%1/%2_%3.json", folder, GetExportStem(), index);
			if (!FileIO.FileExists(output))
				return true;
			index++;
		}
		return false;
	}

	protected string NormalizePath(string path)
	{
		path.Replace("\\", "/");
		int guidEnd = path.IndexOf("}");
		if (guidEnd >= 0)
			path = path.Substring(guidEnd + 1, path.Length() - guidEnd - 1);
		int prefixEnd = path.IndexOf(":");
		if (path.StartsWith("$") && prefixEnd >= 0)
			path = path.Substring(prefixEnd + 1, path.Length() - prefixEnd - 1);
		path.ToLower();
		return path;
	}

	protected void Cleanup()
	{
		m_Visited.Clear();
		m_Records.Clear();
		m_Report = null;
		m_Api = null;
	}

	protected void Fail(string reason)
	{
		PrintFormat("[ME_CA] status=FAIL reason=%1", reason, level: LogLevel.ERROR);
	}

	protected void PrintSuccess()
	{
		PrintFormat("[ME_CA] status=SUCCESS version=%1 visited=%2 records=%3 coordinateMismatches=%4 sourceCountUnchanged=%5 output=%6", m_Report.gameVersion, m_Report.visitedSourceCount, m_Report.diagnosticEntityCount, m_Report.coordinateMismatchCount, m_Report.editorEntityCountUnchanged, m_Report.outputPath);
	}
}
