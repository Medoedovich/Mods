[WorkbenchPluginAttribute(name: "Read ambient vehicle rules and labels", description: "Read selected installed resource source files without opening or saving a world.", wbModules: { "WorldEditor" }, category: "[ME] Conflict Analyzer/Diagnostics")]
class ME_CA_VehicleSourceProbe : WorldEditorPlugin
{
    override void RunCommandline()
    {
        Run();
    }

    override void Run()
    {
        PrintFormat("[ME_CA_AI_READ] BEGIN game=%1", GetGame().GetBuildVersion());
        array<string> paths = {"scripts/Game/Components/Locations/SCR_AmbientVehicleSpawnPointComponent.c","scripts/Game/Systems/SCR_AmbientVehicleSystem.c","scripts/Game/Enums/EEditableEntityLabel.c"};
        foreach (string path : paths)
        {
            FileHandle file = FileIO.OpenFile(path, FileMode.READ);
            if (!file)
            {
                PrintFormat("[ME_CA_AI_READ] UNAVAILABLE %1", path);
                continue;
            }
            PrintFormat("[ME_CA_AI_READ] FILE %1 bytes=%2", path, file.GetLength());
            string line;
            int lineNumber;
            while (file.ReadLine(line) >= 0 && lineNumber < 10000)
            {
                lineNumber++;
                if (line.Length() > 2000)
                {
                    PrintFormat("[ME_CA_AI_READ] NON_TEXT_OR_LONG_LINE %1:%2", path, lineNumber);
                    break;
                }
                PrintFormat("[ME_CA_AI_READ] LINE %1:%2 %3", path, lineNumber, line);
            }
            file.Close();
        }
        array<int> labels = {12,21,26,36,37,39,50,51,52,53,54}; foreach (int label : labels) PrintFormat("[ME_CA_LABEL] %1|%2", label, typename.EnumToString(EEditableEntityLabel, label)); Print("[ME_CA_AI_READ] COMPLETE");
    }
}
