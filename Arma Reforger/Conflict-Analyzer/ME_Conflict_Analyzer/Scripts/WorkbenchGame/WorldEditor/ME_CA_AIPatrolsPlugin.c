[WorkbenchPluginAttribute(name: "Read nested AI waypoints", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Diagnostics")]
class ME_CA_AIPatrolsPlugin : ME_CA_WorldDiagnosticsPlugin
{
 override protected bool IsRelevant(string className)
 {
  return className.Contains("Waypoint") || className == "SCR_AmbientPatrolSpawnPointComponent";
 }
}
