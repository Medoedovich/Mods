class CfgPatches
{
    class DTR_World
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Surfaces", "DTR_Data", "DTR_CE"};
        author = "DayZ Test Range";
    };
};
class CfgWorlds
{
    class CAWorld;
    class dayztestrange: CAWorld
    {
        description = "DayZ Test Range";
        worldName = "dtr\test_range\world\dayztestrange.wrp";
        worldSize = 1024;
        centerPosition[] = {512,512,1};
        ceFiles = "dtr\test_range\ce";
        longitude = 30;
        latitude = -45;
        startTime = "12:00";
        startDate = "15/6/2026";
        // Standard DayZ sky resources, as used by the vanilla Chernarus world.
        // These are renderer resources; no terrain scenery objects are placed.
        spaceObject = "DZ\Data\data\milkyway.p3d";
        spaceObjectRotationPreOffset[] = {0,0,0};
        spaceObjectRotationOffset[] = {0,0,0};
        spaceTexture0 = "DZ\Data\data\milkyway_left_co.paa";
        spaceTexture1 = "DZ\Data\data\milkyway_right_co.paa";
        atmosphereObject = "DZ\Data\data\atmosphere.p3d";
        atmosphereTexture = "DZ\worlds\chernarusplus\data\Sky_Stage01_Clear_sky.paa";
        farCloudObject = "DZ\Data\data\obloha.p3d";
        farCloudObjectRotationAxis[] = {0,1,0};
        farCloudObjectRotationSpeed = 3;
        cloudObject = "DZ\Data\data\cloudObject.p3d";
        cloudObjectRotationAxis[] = {0,1,0};
        cloudObjectRotationSpeed = 9;
        horizonObject = "DZ\Data\data\horizont.p3d";
        horizonObjectRotationAxis[] = {0,1,0};
        horizonObjectRotationSpeed = 0;
        cutscenes[] = {"DTRMenu"};
        clutterGrid = 1;
        clutterDist = 0;
        noDetailDist = 65;
        fullDetailDist = 10;
        class Clutter {};
        class Names
        {
            class TestArea
            {
                name = "Test Range 250 x 250 m";
                position[] = {512,512};
                type = "NameLocal";
                radiusA = 125;
                radiusB = 125;
            };
        };
        class UsedTerrainMaterials
        {
            material1 = "DZ\surfaces\data\terrain\cp_concrete1.rvmat";
        };
        midDetailTexture = "dtr\test_range\data\dtr_middlesat_mco.paa";
        terrainNormalTexture = "dtr\test_range\data\dtr_global_nohq.paa";
        // Keep the absolute +1 m test floor clear of tide and wave displacement.
        MaxTide = 0;
        MaxWave = 0;
        class OutsideTerrain
        {
            satellite = "dtr\test_range\data\dtr_outside_co.paa";
            enableTerrainSynth = 0;
            class Layers
            {
                class Layer0
                {
                    nopx = "DZ\surfaces\data\terrain\cp_concrete1_nopx.paa";
                    texture = "DZ\surfaces\data\terrain\cp_concrete1_ca.paa";
                };
            };
        };
        class Grid
        {
            offsetX = 0;
            offsetY = 0;
            class Zoom1
            {
                zoomMax = 0.5;
                format = "XY";
                formatX = "000";
                formatY = "000";
                stepX = 100;
                stepY = 100;
            };
            class Zoom2: Zoom1
            {
                zoomMax = 1e30;
                stepX = 1000;
                stepY = 1000;
            };
        };
        // Valid inert metadata; drawTaxiway is disabled and no airport exists.
        ilsPosition[] = {0,0};
        ilsDirection[] = {0,0,1};
        ilsTaxiOff[] = {};
        ilsTaxiIn[] = {};
        drawTaxiway = 0;
        class SecondaryAirports {};
        class Ambient {};
        class Sounds { sounds[] = {}; };
    };
};
class CfgWorldList { class dayztestrange {}; };
class CfgCharacterScenes
{
    class dayztestrange
    {
        class loc1
        {
            target[] = {512,512,2.5};
            position[] = {516,508,1.1};
            fov = 0.5236;
            date[] = {2026,6,15,12,0};
            overcast = 0;
            rain = 0;
            fog = 0;
        };
    };
};
class CfgMissions
{
    class Cutscenes
    {
        class DTRMenu { directory = "\intro.dayztestrange"; };
    };
};
