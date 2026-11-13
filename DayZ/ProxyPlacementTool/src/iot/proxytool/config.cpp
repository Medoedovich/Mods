class CfgPatches
{
    class IOT_ProxyPlacementTool
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Scripts"};
    };
};

class CfgMods
{
    class IOT_ProxyPlacementTool
    {
        dir = "ProxyPlacementTool";
        name = "Proxy Placement Tool - Alpha";
        author = "Medoedovich";
        version = "0.1.0-alpha";
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        class defs
        {
            class missionScriptModule
            {
                value = "";
                files[] = {"iot/proxytool/scripts/5_Mission"};
            };
        };
    };
};
