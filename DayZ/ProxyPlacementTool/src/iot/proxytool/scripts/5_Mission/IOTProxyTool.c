// Generated from localization/strings.json. Uses the client's native language.
class IOTL
{
    static string T(string key)
    {
        return Widget.TranslateString("#STR_IOT_" + key);
    }

    static string F(string key, string first = "", string second = "", string third = "")
    {
        return string.Format(T(key),first,second,third);
    }

    static array<string> Keys()
    {
        array<string> keys = {"LOCALE","TITLE","ITEM","ANCHOR","MOVE","ROTATE","POSITION","MOVE_STEP_DEFAULT","ROTATION","ANGLE_STEP_DEFAULT","APPLY","CHARACTER","RESET","GROUND","SELECT_HINT","HELP","CREATE_TITLE","BUILDINGS","ITEMS","ITEM_GROUP_WEAPONS","ITEM_GROUP_WEAPONS_FIREARMS","ITEM_GROUP_WEAPONS_PISTOLS","ITEM_GROUP_WEAPONS_SHOTGUNS","ITEM_GROUP_WEAPONS_ARCHERY","ITEM_GROUP_WEAPONS_MELEE","ITEM_GROUP_WEAPONS_EXPLOSIVES","ITEM_GROUP_WEAPONS_LAUNCHERS","ITEM_GROUP_WEAPONS_OTHER","ITEM_GROUP_AMMO","ITEM_GROUP_AMMO_ROUNDS","ITEM_GROUP_AMMO_MAGAZINES","ITEM_GROUP_AMMO_BOXES","ITEM_GROUP_ATTACHMENTS","ITEM_GROUP_ATTACHMENTS_OPTICS","ITEM_GROUP_ATTACHMENTS_MUZZLE","ITEM_GROUP_ATTACHMENTS_LIGHT","ITEM_GROUP_ATTACHMENTS_SUPPORT","ITEM_GROUP_ATTACHMENTS_OTHER","ITEM_GROUP_CLOTHING","ITEM_GROUP_CLOTHING_BACKPACKS","ITEM_GROUP_CLOTHING_VESTS","ITEM_GROUP_CLOTHING_TOPS","ITEM_GROUP_CLOTHING_PANTS","ITEM_GROUP_CLOTHING_SHOES","ITEM_GROUP_CLOTHING_HEADGEAR","ITEM_GROUP_CLOTHING_MASKS","ITEM_GROUP_CLOTHING_GLOVES","ITEM_GROUP_CLOTHING_GLASSES","ITEM_GROUP_CLOTHING_BELTS","ITEM_GROUP_CLOTHING_OTHER","ITEM_GROUP_FOOD_DRINKS","ITEM_GROUP_FOOD_DRINKS_FOOD","ITEM_GROUP_FOOD_DRINKS_DRINKS","ITEM_GROUP_GEAR","ITEM_GROUP_GEAR_TOOLS","ITEM_GROUP_GEAR_CONTAINERS","ITEM_GROUP_GEAR_CAMPING","ITEM_GROUP_GEAR_COOKING","ITEM_GROUP_GEAR_CRAFTING","ITEM_GROUP_GEAR_CULTIVATION","ITEM_GROUP_GEAR_MEDICAL","ITEM_GROUP_GEAR_NAVIGATION","ITEM_GROUP_GEAR_RADIO","ITEM_GROUP_GEAR_OPTICS","ITEM_GROUP_GEAR_TRAPS","ITEM_GROUP_GEAR_BOOKS","ITEM_GROUP_GEAR_CONSUMABLES","ITEM_GROUP_GEAR_OTHER","ITEM_GROUP_VEHICLE_PARTS","ITEM_GROUP_VEHICLE_PARTS_WHEELS","ITEM_GROUP_VEHICLE_PARTS_BODY","ITEM_GROUP_VEHICLE_PARTS_COMPONENTS","ITEM_GROUP_VEHICLE_PARTS_OTHER","ITEM_GROUP_OTHER","SHOW_STATICOBJ","OTHER_OBJECTS","OBJECT_TREE_HINT","CATEGORY_RESIDENTIAL","RESIDENTIAL_SUB_SHEDS","RESIDENTIAL_SUB_OFFICE","RESIDENTIAL_SUB_MISC","RESIDENTIAL_SUB_HOUSE","RESIDENTIAL_SUB_CITY","RESIDENTIAL_SUB_TENEMENTS","RESIDENTIAL_SUB_STORES","RESIDENTIAL_SUB_MEDICAL","RESIDENTIAL_SUB_POLICE","RESIDENTIAL_SUB_SCHOOLS","RESIDENTIAL_SUB_FIREDEP","RESIDENTIAL_SUB_BUS","RESIDENTIAL_SUB_SLUMS","RESIDENTIAL_SUB_PLATFORMS","RESIDENTIAL_SUB_TERRACES","RESIDENTIAL_SUB_OTHER","CATEGORY_INDUSTRIAL","CATEGORY_MILITARY","CATEGORY_UNDERGROUND","CATEGORY_WRECKS","WRECK_SUB_VEHICLES","WRECK_SUB_AIRCRAFT","WRECK_SUB_SHIPS","WRECK_SUB_TRAINS","WRECK_SUB_OTHER","VEHICLE_TYPE_TRUCK","VEHICLE_TYPE_SEDAN","VEHICLE_TYPE_OFFROAD","VEHICLE_TYPE_HATCHBACK","VEHICLE_TYPE_OTHER","CATEGORY_FURNITURE","CATEGORY_ROADS","CATEGORY_RAIL","CATEGORY_WALLS","CATEGORY_SIGNS","CATEGORY_RUINS","CATEGORY_SPECIFIC","CATEGORY_PROPS","CATEGORY_BUILDING_PARTS","CATEGORY_VEGETATION","CATEGORY_ROCKS","CATEGORY_WATER","CATEGORY_TERRAIN","CATEGORY_UNCATEGORIZED","SEARCH","CLASSNAME","CREATE_ANCHOR","CREATE_ITEM","FOCUS_ANCHOR","EXPORT_ANCHOR","ITEM_MODE_HINT","ANCHOR_MODE_HINT","FOUND","UNKNOWN_CLASS","ANCHOR_REQUIRED","SPAWN_FAILED","NOT_INVENTORY_ITEM","NOT_ANCHOR","CREATED","ANCHOR_TRANSFORM_LIMIT","GIZMO_HINT","DESELECT_HINT","NO_ITEM","NO_ANCHOR","START_HINT","GIZMO_ON","GIZMO_OFF","INVALID_NUMBER","NUMBER_LIMIT","POSE_APPLIED","GROUNDED","POSE_RESET","ANCHOR_XML_FAILED","ANCHOR_XML_SAVED","XML_FAILED","MOVE_STEP","ANGLE_STEP","MOVE_KEYS","ROTATE_KEYS","ITEM_PICKED_UP","WORLD_POSITION","WORLD_ORIENTATION","TRAY_TITLE","TRAY_TITLE_EMPTY","TRAY_EMPTY","TRAY_OWNER","TRAY_SELECTED","TRAY_INVENTORY","CHARACTER_HINT"};
        return keys;
    }
}
class IOTSceneEntry
{
    Object Anchor;
    int Id;
    ref array<ItemBase> Items = new array<ItemBase>;
}

class IOTCatalogAsset
{
    static array<string> ModelParts(string model)
    {
        model.ToLower();
        model.Replace("\\","/");
        array<string> raw = new array<string>;
        array<string> parts = new array<string>;
        model.Split("/",raw);
        foreach (string part : raw) { if (part != "") parts.Insert(part); }
        return parts;
    }

    // Resource families are a fallback when CE has no recorded placement.
    static int FamilyMask(string model)
    {
        array<string> parts = ModelParts(model);
        if (parts.Count() < 2 || parts[0] != "dz") return 0;
        string family = parts[1];
        if (family.IndexOf("_bliss") >= 0) return 2;
        if (family.IndexOf("_sakhal") >= 0) return 4;
        if (family.IndexOf("_takistan") >= 0) return 8;
        if (family == "worlds" && parts.Count() > 2)
        {
            if (parts[2] == "chernarusplus") return 1;
            if (parts[2] == "enoch") return 2;
            if (parts[2] == "sakhal") return 4;
            if (parts[2] == "nasdara") return 8;
        }
        if (family == "structures" || family == "plants" || family == "rocks" || family == "water") return 1;
        return 0;
    }

    static string Category(string model)
    {
        array<string> parts = ModelParts(model);
        if (parts.Count() < 3 || parts[0] != "dz") return "UNCATEGORIZED";
        string family = parts[1];
        if (family.IndexOf("plants") == 0) return "VEGETATION";
        if (family.IndexOf("rocks") == 0) return "ROCKS";
        if (family.IndexOf("water") == 0) return "WATER";
        if (family == "worlds") return "TERRAIN";
        if (family.IndexOf("structures") != 0) return "UNCATEGORIZED";
        string category = parts[2];
        if (category == "residential") return "RESIDENTIAL";
        if (category == "industrial") return "INDUSTRIAL";
        if (category == "military") return "MILITARY";
        if (category == "underground") return "UNDERGROUND";
        if (category == "wrecks") return "WRECKS";
        if (category == "furniture") return "FURNITURE";
        if (category == "roads") return "ROADS";
        if (category == "rail") return "RAIL";
        if (category == "walls") return "WALLS";
        if (category == "signs") return "SIGNS";
        if (category == "ruins") return "RUINS";
        if (category == "specific") return "SPECIFIC";
        if (category == "props") return "PROPS";
        if (category == "proxy_buildingparts") return "BUILDING_PARTS";
        return "UNCATEGORIZED";
    }

    static string ResidentialSubcategory(string model)
    {
        if (Category(model) != "RESIDENTIAL") return "OTHER";
        array<string> parts = ModelParts(model);
        if (parts.Count() < 5) return "OTHER";
        string folder = parts[3];
        string filename = parts[parts.Count() - 1];
        if (filename.IndexOf("city_") == 0 || folder == "city" || folder == "houseblocks") return "CITY";
        if (folder == "sheds" || folder == "shed") return "SHEDS";
        if (folder == "offices" || folder == "office") return "OFFICE";
        if (folder == "misc") return "MISC";
        if (folder == "houses" || folder == "house") return "HOUSE";
        if (folder == "tenements") return "TENEMENTS";
        if (folder == "stores") return "STORES";
        if (folder == "medical") return "MEDICAL";
        if (folder == "police") return "POLICE";
        if (folder == "schools") return "SCHOOLS";
        if (folder == "firedep") return "FIREDEP";
        if (folder == "bus") return "BUS";
        if (folder == "slums") return "SLUMS";
        if (folder == "platforms") return "PLATFORMS";
        if (folder == "terraces") return "TERRACES";
        return "OTHER";
    }

    static string ResidentialLabel(string subcategory)
    {
        string key = "RESIDENTIAL_SUB_" + subcategory;
        return IOTL.T(key);
    }

    static string WreckSubcategory(string model)
    {
        if (Category(model) != "WRECKS") return "OTHER";
        array<string> parts = ModelParts(model);
        if (parts.Count() > 4)
        {
            string folder = parts[3];
            if (folder == "vehicles" || folder == "wheeled" || folder == "tracked") return "VEHICLES";
            if (folder == "aircraft") return "AIRCRAFT";
            if (folder == "ships") return "SHIPS";
            if (folder == "trains") return "TRAINS";
        }
        // Sakhal also stores wreck models directly in its wrecks directory.
        if (parts.Count() == 4 && parts[1] == "structures_sakhal")
        {
            string filename = parts[3];
            if (filename.IndexOf("boat_") == 0 || filename.IndexOf("ship_") == 0 || filename.IndexOf("submarine_") == 0 || filename.IndexOf("patrolboat_") == 0) return "SHIPS";
            if (filename.IndexOf("static_an2") == 0 || filename.IndexOf("static_mi8") == 0 || filename.IndexOf("wreck_mi8") == 0) return "AIRCRAFT";
            if (filename.IndexOf("wreck_sed") == 0) return "VEHICLES";
        }
        return "OTHER";
    }

    static string VehicleSubcategory(string model)
    {
        if (WreckSubcategory(model) != "VEHICLES") return "OTHER";
        array<string> parts = ModelParts(model);
        string filename = parts[parts.Count() - 1];
        if (filename.IndexOf("wreck_truck") == 0 || filename.IndexOf("wreck_v3s") == 0 || filename.IndexOf("wreck_ural") == 0 || filename.IndexOf("wreck_armedural") == 0 || filename.IndexOf("wreck_mtvr") == 0 || filename.IndexOf("wreck_mining_haultruck") == 0) return "TRUCK";
        if (filename.IndexOf("wreck_sed") == 0) return "SEDAN";
        if (filename.IndexOf("wreck_offroad") == 0 || filename.IndexOf("wreck_hb01") == 0 || filename.IndexOf("wreck_uaz") == 0 || filename.IndexOf("wreck_hmmwv") == 0 || filename.IndexOf("wreck_lr_") == 0) return "OFFROAD";
        if (filename.IndexOf("wreck_hb02") == 0) return "HATCHBACK";
        return "OTHER";
    }

    static string VehicleLabel(string vehicleType)
    {
        string key = "VEHICLE_TYPE_" + vehicleType;
        return IOTL.T(key);
    }

    static string WreckLabel(string subcategory)
    {
        string key = "WRECK_SUB_" + subcategory;
        return IOTL.T(key);
    }

    static string CategoryLabel(string category)
    {
        string key = "CATEGORY_" + category;
        return IOTL.T(key);
    }
}

class IOTItemCatalog
{
    static array<string> Categories()
    {
        array<string> categories = {"WEAPONS","AMMO","ATTACHMENTS","CLOTHING","FOOD_DRINKS","GEAR","VEHICLE_PARTS","OTHER"};
        return categories;
    }

    static array<string> Paths()
    {
        array<string> paths = {
            "WEAPONS/FIREARMS","WEAPONS/PISTOLS","WEAPONS/SHOTGUNS","WEAPONS/ARCHERY","WEAPONS/MELEE","WEAPONS/EXPLOSIVES","WEAPONS/LAUNCHERS","WEAPONS/OTHER",
            "AMMO/ROUNDS","AMMO/MAGAZINES","AMMO/BOXES",
            "ATTACHMENTS/OPTICS","ATTACHMENTS/MUZZLE","ATTACHMENTS/LIGHT","ATTACHMENTS/SUPPORT","ATTACHMENTS/OTHER",
            "CLOTHING/BACKPACKS","CLOTHING/VESTS","CLOTHING/TOPS","CLOTHING/PANTS","CLOTHING/SHOES","CLOTHING/HEADGEAR","CLOTHING/MASKS","CLOTHING/GLOVES","CLOTHING/GLASSES","CLOTHING/BELTS","CLOTHING/OTHER",
            "FOOD_DRINKS/FOOD","FOOD_DRINKS/DRINKS",
            "GEAR/TOOLS","GEAR/CONTAINERS","GEAR/CAMPING","GEAR/COOKING","GEAR/CRAFTING","GEAR/CULTIVATION","GEAR/MEDICAL","GEAR/NAVIGATION","GEAR/RADIO","GEAR/OPTICS","GEAR/TRAPS","GEAR/BOOKS","GEAR/CONSUMABLES","GEAR/OTHER",
            "VEHICLE_PARTS/WHEELS","VEHICLE_PARTS/BODY","VEHICLE_PARTS/COMPONENTS","VEHICLE_PARTS/OTHER","OTHER"
        };
        return paths;
    }

    static string Label(string path)
    {
        path.Replace("/","_");
        string key = "ITEM_GROUP_"+path;
        return IOTL.T(key);
    }

    // Each loaded item has one group. Unknown resources remain accessible in Other.
    static string Group(string name, string model, string root)
    {
        if (root == "CfgMagazines")
        {
            if (GetGame().IsKindOf(name,"Ammunition_Base")) return "AMMO/ROUNDS";
            return "AMMO/MAGAZINES";
        }
        if (GetGame().IsKindOf(name,"CarWheel")) return "VEHICLE_PARTS/WHEELS";
        if (GetGame().IsKindOf(name,"CarDoor")) return "VEHICLE_PARTS/BODY";

        array<string> parts = IOTCatalogAsset.ModelParts(model);
        array<string> knownPaths = Paths();
        if (parts.Count() >= 4 && parts[0] == "dz")
        {
            string family = parts[1];
            string folder = parts[2];
            if (family.IndexOf("characters") == 0)
            {
                string clothingPath = "CLOTHING/"+folder;
                clothingPath.ToUpper();
                if (knownPaths.Find(clothingPath) >= 0) return clothingPath;
                if (GetGame().IsKindOf(name,"Clothing_Base")) return "CLOTHING/OTHER";
            }
            if (family.IndexOf("gear") == 0)
            {
                if (folder == "food") return "FOOD_DRINKS/FOOD";
                if (folder == "drinks") return "FOOD_DRINKS/DRINKS";
                string gearPath = "GEAR/"+folder;
                gearPath.ToUpper();
                if (knownPaths.Find(gearPath) >= 0) return gearPath;
                return "GEAR/OTHER";
            }
            if (family.IndexOf("vehicles") == 0)
            {
                if (folder == "parts") return "VEHICLE_PARTS/COMPONENTS";
                return "VEHICLE_PARTS/OTHER";
            }
            if (family.IndexOf("weapons") == 0)
            {
                if (folder == "ammunition") return "AMMO/BOXES";
                if (folder == "projectiles") return "AMMO/ROUNDS";
                if (folder == "attachments")
                {
                    if (parts.Count() > 4)
                    {
                        string attachmentPath = "ATTACHMENTS/"+parts[3];
                        attachmentPath.ToUpper();
                        if (knownPaths.Find(attachmentPath) >= 0) return attachmentPath;
                    }
                    return "ATTACHMENTS/OTHER";
                }
                string weaponPath = "WEAPONS/"+folder;
                weaponPath.ToUpper();
                if (knownPaths.Find(weaponPath) >= 0) return weaponPath;
                return "WEAPONS/OTHER";
            }
        }
        if (root == "CfgWeapons") return "WEAPONS/OTHER";
        if (GetGame().IsKindOf(name,"Clothing_Base")) return "CLOTHING/OTHER";
        if (GetGame().IsKindOf(name,"ItemOptics")) return "ATTACHMENTS/OPTICS";
        if (GetGame().IsKindOf(name,"ExplosivesBase")) return "WEAPONS/EXPLOSIVES";
        return "OTHER";
    }
}

class IOTCatalogGroup
{
    int Map;
    string Category;
    ref array<string> Classes = new array<string>;
}

class IOTCatalogRow
{
    string Key;
    string ClassName;
}

class IOTSceneBrowser : ScriptedWidgetEventHandler
{
    protected IOTProxyTool m_Tool;
    protected Widget m_Root;
    protected EditBoxWidget m_Search;
    protected EditBoxWidget m_ClassName;
    protected TextListboxWidget m_Results;
    protected TextWidget m_Count;
    protected MultilineTextWidget m_Status;
    protected CheckBoxWidget m_ShowStatic;
    protected bool m_ShowStaticObjects;
    protected int m_MatchCount;
    protected bool m_ItemsMode;
    protected bool m_Updating;
    protected string m_LastQuery;
    protected string m_SelectedKey;
    protected ref map<string,int> m_MapMasks = new map<string,int>;
    protected ref map<string,ref IOTCatalogGroup> m_Groups = new map<string,ref IOTCatalogGroup>;
    protected ref map<string,ref IOTCatalogGroup> m_ItemGroups = new map<string,ref IOTCatalogGroup>;
    protected ref map<string,bool> m_Expanded = new map<string,bool>;
    protected ref map<string,bool> m_SearchClosed = new map<string,bool>;
    protected ref array<ref IOTCatalogRow> m_Rows = new array<ref IOTCatalogRow>;
    protected ref array<string> m_AnchorClasses = new array<string>;
    protected ref array<string> m_ItemClasses = new array<string>;
    protected ref array<string> m_Filtered = new array<string>;
    protected ref array<string> m_Categories = {"RESIDENTIAL","INDUSTRIAL","MILITARY","UNDERGROUND","WRECKS","FURNITURE","ROADS","RAIL","WALLS","SIGNS","RUINS","SPECIFIC","PROPS","BUILDING_PARTS","VEGETATION","ROCKS","WATER","TERRAIN","UNCATEGORIZED"};
    protected ref array<string> m_WreckSubcategories = {"VEHICLES","AIRCRAFT","SHIPS","TRAINS","OTHER"};
    protected ref array<string> m_VehicleTypes = {"TRUCK","SEDAN","OFFROAD","HATCHBACK","OTHER"};
    protected ref array<string> m_ResidentialSubcategories = {"SHEDS","OFFICE","MISC","HOUSE","CITY","TENEMENTS","STORES","MEDICAL","POLICE","SCHOOLS","FIREDEP","BUS","SLUMS","PLATFORMS","TERRACES","OTHER"};

    void IOTSceneBrowser(IOTProxyTool tool)
    {
        m_Tool = tool;
        m_Root = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\scene_browser.layout");
        m_Search = EditBoxWidget.Cast(m_Root.FindAnyWidget("SceneSearch"));
        m_ClassName = EditBoxWidget.Cast(m_Root.FindAnyWidget("SceneClass"));
        m_Results = TextListboxWidget.Cast(m_Root.FindAnyWidget("SceneResults"));
        m_Count = TextWidget.Cast(m_Root.FindAnyWidget("SceneCount"));
        m_Status = MultilineTextWidget.Cast(m_Root.FindAnyWidget("SceneStatus"));
        m_ShowStatic = CheckBoxWidget.Cast(m_Root.FindAnyWidget("SceneShowStatic"));
        m_ShowStatic.SetChecked(false);
        m_Expanded.Set("objects",true);
        m_Expanded.Set("items",true);
        IOTMapCatalog.Populate(m_MapMasks);
        LoadCatalog();
        m_Root.SetHandler(this);
        SetMode(false);
    }

    void ~IOTSceneBrowser() { if (m_Root) m_Root.Unlink(); }

    static string MapKey(int mapIndex) { return "map:"+mapIndex.ToString(); }

    static string MapLabel(int mapIndex)
    {
        if (mapIndex == 1) return "ChernarusPlus";
        if (mapIndex == 2) return "Livonia";
        if (mapIndex == 3) return "Sakhal";
        if (mapIndex == 4) return "Nasdara";
        return IOTL.T("OTHER_OBJECTS");
    }

    protected void AddAnchor(string name, string model)
    {
        m_AnchorClasses.Insert(name);
        string lower = name;
        lower.ToLower();
        int mask = m_MapMasks.Get(lower);
        if (mask == 0) mask = IOTCatalogAsset.FamilyMask(model);
        string category = IOTCatalogAsset.Category(model);
        string subcategory;
        if (category == "WRECKS") subcategory = IOTCatalogAsset.WreckSubcategory(model);
        if (category == "RESIDENTIAL") subcategory = IOTCatalogAsset.ResidentialSubcategory(model);
        string vehicleType;
        if (subcategory == "VEHICLES") vehicleType = IOTCatalogAsset.VehicleSubcategory(model);
        for (int mapIndex = 1; mapIndex <= 5; mapIndex++)
        {
            if (mapIndex == 5 && mask != 0) continue;
            int mapBit = 1 << (mapIndex - 1);
            int belongs = mask & mapBit;
            if (mapIndex < 5 && belongs == 0) continue;
            string key = MapKey(mapIndex)+"/"+category;
            if (subcategory != "") key += "/"+subcategory;
            if (vehicleType != "") key += "/"+vehicleType;
            IOTCatalogGroup group = m_Groups.Get(key);
            if (!group)
            {
                group = new IOTCatalogGroup;
                group.Map = mapIndex;
                group.Category = category;
                m_Groups.Insert(key,group);
            }
            group.Classes.Insert(name);
        }
    }

    protected void AddItem(string name, string model, string root)
    {
        if (m_ItemClasses.Find(name) >= 0) return;
        m_ItemClasses.Insert(name);
        string path = IOTItemCatalog.Group(name,model,root);
        string key = "items/"+path;
        IOTCatalogGroup group = m_ItemGroups.Get(key);
        if (!group)
        {
            array<string> parts = new array<string>;
            path.Split("/",parts);
            group = new IOTCatalogGroup;
            group.Category = parts[0];
            m_ItemGroups.Insert(key,group);
        }
        group.Classes.Insert(name);
    }

    protected void LoadCatalog()
    {
        array<string> roots = {"CfgVehicles","CfgWeapons","CfgMagazines"};
        foreach (string root : roots)
        {
            int count = GetGame().ConfigGetChildrenCount(root);
            for (int i = 0; i < count; i++)
            {
                string name,model;
                GetGame().ConfigGetChildName(root,i,name);
                string path = root + " " + name;
                GetGame().ConfigGetText(path + " model",model);
                if (model == "") continue;
                string lower = name;
                lower.ToLower();
                if (root == "CfgVehicles" && (lower.IndexOf("land_") == 0 || lower.IndexOf("staticobj_") == 0)) AddAnchor(name,model);
                if (GetGame().ConfigGetInt(path + " scope") != 2) continue;
                if (root == "CfgVehicles" && !GetGame().IsKindOf(name,"Inventory_Base")) continue;
                AddItem(name,model,root);
            }
        }
        m_AnchorClasses.Sort();
        m_ItemClasses.Sort();
        foreach (string groupKey, IOTCatalogGroup group : m_Groups) group.Classes.Sort();
        foreach (string itemKey, IOTCatalogGroup itemGroup : m_ItemGroups) itemGroup.Classes.Sort();
        PrintToRPT("[PROXY CATALOG] Anchors="+m_AnchorClasses.Count().ToString()+" items="+m_ItemClasses.Count().ToString());
    }

    int CatalogCount(bool items)
    {
        if (items) return m_ItemClasses.Count();
        return m_AnchorClasses.Count();
    }

    int BranchCount(int mapIndex)
    {
        int count;
        foreach (string key, IOTCatalogGroup group : m_Groups)
        {
            if (group.Map != mapIndex) continue;
            foreach (string name : group.Classes) { if (AnchorVisible(name)) count++; }
        }
        return count;
    }

    bool CatalogCovered()
    {
        map<string,bool> names = new map<string,bool>;
        foreach (string key, IOTCatalogGroup group : m_Groups)
        {
            foreach (string name : group.Classes) names.Set(name,true);
        }
        return names.Count() == m_AnchorClasses.Count();
    }

    bool ItemCatalogCovered()
    {
        map<string,bool> names = new map<string,bool>;
        int count;
        foreach (string key, IOTCatalogGroup group : m_ItemGroups)
        {
            foreach (string name : group.Classes) { names.Set(name,true); count++; }
        }
        return names.Count() == m_ItemClasses.Count() && count == m_ItemClasses.Count();
    }

    string ResolveClass(string value, bool items)
    {
        value.TrimInPlace();
        value.ToLower();
        array<string> source = m_AnchorClasses;
        if (items) source = m_ItemClasses;
        foreach (string name : source)
        {
            string lower = name;
            lower.ToLower();
            if (lower == value) return name;
        }
        return "";
    }

    void SetMode(bool items)
    {
        m_ItemsMode = items;
        m_Updating = true;
        m_ShowStatic.Show(!items);
        m_Search.SetText("");
        m_ClassName.SetText("");
        m_SelectedKey = "";
        ButtonWidget.Cast(m_Root.FindAnyWidget("SceneAnchorsMode")).SetState(!items);
        ButtonWidget.Cast(m_Root.FindAnyWidget("SceneItemsMode")).SetState(items);
        ButtonWidget button = ButtonWidget.Cast(m_Root.FindAnyWidget("SceneCreate"));
        if (items) button.SetText(IOTL.T("CREATE_ITEM"));
        else button.SetText(IOTL.T("CREATE_ANCHOR"));
        m_Updating = false;
        Filter();
        if (items) SetStatus(IOTL.T("ITEM_MODE_HINT"));
        else SetStatus(IOTL.T("OBJECT_TREE_HINT"));
    }

    protected bool MatchesQuery(string name, string query)
    {
        if (query == "") return true;
        name.ToLower();
        return name.IndexOf(query) >= 0;
    }

    protected bool AnchorVisible(string name)
    {
        if (m_ShowStaticObjects) return true;
        name.ToLower();
        return name.IndexOf("staticobj_") != 0;
    }

    void SetShowStaticObjects(bool visible)
    {
        if (m_ShowStaticObjects == visible) return;
        m_ShowStaticObjects = visible;
        m_Updating = true;
        m_ShowStatic.SetChecked(visible);
        m_Updating = false;
        Filter();
    }

    bool ShowStaticObjects() { return m_ShowStaticObjects; }
    bool StaticControlVisible() { return m_ShowStatic.IsVisible(); }

    protected bool FolderOpen(string key)
    {
        if (m_LastQuery != "") return !m_SearchClosed.Get(key);
        return m_Expanded.Get(key);
    }

    protected void AddRow(string key, string label, string classname = "")
    {
        IOTCatalogRow row = new IOTCatalogRow;
        row.Key = key;
        row.ClassName = classname;
        m_Rows.Insert(row);
        m_Results.AddItem(label,null,0);
        if (classname != "" && m_Filtered.Find(classname) < 0) m_Filtered.Insert(classname);
    }

    protected void AddFolder(string key, string label, int count, string indent)
    {
        string marker = "[+] ";
        if (FolderOpen(key)) marker = "[-] ";
        AddRow(key,indent+marker+label+" ("+count.ToString()+")");
    }

    protected void BuildTree(string query)
    {
        map<string,ref array<string>> matches = new map<string,ref array<string>>;
        map<string,int> categoryCounts = new map<string,int>;
        foreach (string key, IOTCatalogGroup group : m_Groups)
        {
            array<string> found = new array<string>;
            foreach (string name : group.Classes) { if (AnchorVisible(name) && MatchesQuery(name,query)) found.Insert(name); }
            matches.Insert(key,found);
            string parentKey = MapKey(group.Map)+"/"+group.Category;
            categoryCounts.Set(parentKey,categoryCounts.Get(parentKey)+found.Count());
        }
        foreach (string anchor : m_AnchorClasses) { if (AnchorVisible(anchor) && MatchesQuery(anchor,query)) m_MatchCount++; }
        AddFolder("objects",IOTL.T("BUILDINGS"),m_MatchCount,"");
        if (!FolderOpen("objects")) return;
        for (int mapIndex = 1; mapIndex <= 5; mapIndex++)
        {
            int mapCount = 0;
            foreach (string category : m_Categories)
            {
                mapCount += categoryCounts.Get(MapKey(mapIndex)+"/"+category);
            }
            if (query != "" && mapCount == 0) continue;
            string mapKey = MapKey(mapIndex);
            AddFolder(mapKey,MapLabel(mapIndex),mapCount,"  ");
            if (!FolderOpen(mapKey)) continue;
            foreach (string cat : m_Categories)
            {
                string categoryKey = mapKey+"/"+cat;
                int categoryCount = categoryCounts.Get(categoryKey);
                if (categoryCount == 0) continue;
                AddFolder(categoryKey,IOTCatalogAsset.CategoryLabel(cat),categoryCount,"    ");
                if (!FolderOpen(categoryKey)) continue;
                if (cat == "RESIDENTIAL")
                {
                    BuildResidentialRows(categoryKey,matches);
                    continue;
                }
                if (cat == "WRECKS")
                {
                    BuildWreckRows(categoryKey,matches);
                    continue;
                }
                array<string> classes = matches.Get(categoryKey);
                foreach (string classname : classes) AddRow(categoryKey+"/"+classname,"        "+classname,classname);
            }
        }
    }

    protected void BuildItemTree(string query)
    {
        map<string,ref array<string>> matches = new map<string,ref array<string>>;
        map<string,int> categoryCounts = new map<string,int>;
        foreach (string key, IOTCatalogGroup group : m_ItemGroups)
        {
            array<string> found = new array<string>;
            foreach (string name : group.Classes) { if (MatchesQuery(name,query)) found.Insert(name); }
            matches.Insert(key,found);
            categoryCounts.Set(group.Category,categoryCounts.Get(group.Category)+found.Count());
            m_MatchCount += found.Count();
        }
        AddFolder("items",IOTL.T("ITEMS"),m_MatchCount,"");
        if (!FolderOpen("items")) return;
        array<string> categories = IOTItemCatalog.Categories();
        array<string> paths = IOTItemCatalog.Paths();
        foreach (string category : categories)
        {
            int count = categoryCounts.Get(category);
            if (count == 0) continue;
            string categoryKey = "items/"+category;
            AddFolder(categoryKey,IOTItemCatalog.Label(category),count,"  ");
            if (!FolderOpen(categoryKey)) continue;
            foreach (string path : paths)
            {
                string keyPath = "items/"+path;
                if (keyPath != categoryKey && path.IndexOf(category+"/") != 0) continue;
                array<string> classes = matches.Get(keyPath);
                if (!classes || classes.Count() == 0) continue;
                string indent = "      ";
                if (keyPath != categoryKey)
                {
                    AddFolder(keyPath,IOTItemCatalog.Label(path),classes.Count(),"    ");
                    if (!FolderOpen(keyPath)) continue;
                    indent = "        ";
                }
                foreach (string classname : classes) AddRow(keyPath+"/"+classname,indent+classname,classname);
            }
        }
    }

    protected void BuildResidentialRows(string parentKey, map<string,ref array<string>> matches)
    {
        foreach (string subcategory : m_ResidentialSubcategories)
        {
            string key = parentKey+"/"+subcategory;
            array<string> classes = matches.Get(key);
            if (!classes || classes.Count() == 0) continue;
            AddFolder(key,IOTCatalogAsset.ResidentialLabel(subcategory),classes.Count(),"      ");
            if (!FolderOpen(key)) continue;
            foreach (string classname : classes) AddRow(key+"/"+classname,"          "+classname,classname);
        }
    }

    protected void BuildWreckRows(string categoryKey, map<string,ref array<string>> matches)
    {
        foreach (string subcategory : m_WreckSubcategories)
        {
            string key = categoryKey+"/"+subcategory;
            array<string> classes = matches.Get(key);
            int count = 0;
            if (subcategory == "VEHICLES")
            {
                foreach (string vehicleType : m_VehicleTypes)
                {
                    array<string> vehicles = matches.Get(key+"/"+vehicleType);
                    if (vehicles) count += vehicles.Count();
                }
            }
            else if (classes) count = classes.Count();
            if (count == 0) continue;
            AddFolder(key,IOTCatalogAsset.WreckLabel(subcategory),count,"      ");
            if (!FolderOpen(key)) continue;
            if (subcategory == "VEHICLES")
            {
                BuildVehicleRows(key,matches);
                continue;
            }
            foreach (string classname : classes) AddRow(key+"/"+classname,"          "+classname,classname);
        }
    }

    protected void BuildVehicleRows(string parentKey, map<string,ref array<string>> matches)
    {
        foreach (string vehicleType : m_VehicleTypes)
        {
            string key = parentKey+"/"+vehicleType;
            array<string> classes = matches.Get(key);
            if (!classes || classes.Count() == 0) continue;
            AddFolder(key,IOTCatalogAsset.VehicleLabel(vehicleType),classes.Count(),"        ");
            if (!FolderOpen(key)) continue;
            foreach (string classname : classes) AddRow(key+"/"+classname,"            "+classname,classname);
        }
    }

    protected void Filter()
    {
        m_Updating = true;
        string query = m_Search.GetText();
        query.TrimInPlace();
        query.ToLower();
        if (query != m_LastQuery)
        {
            m_SearchClosed.Clear();
            m_SelectedKey = "";
        }
        m_LastQuery = query;
        m_Results.ClearItems();
        m_Filtered.Clear();
        m_Rows.Clear();
        m_MatchCount = 0;
        if (m_ItemsMode) BuildItemTree(query);
        else BuildTree(query);
        m_Count.SetText(IOTL.F("FOUND",m_MatchCount.ToString(),m_Filtered.Count().ToString()));
        int selected = RowIndex(m_SelectedKey);
        if (selected < 0 && query != "")
        {
            for (int i = 0; i < m_Rows.Count(); i++)
            {
                if (m_Rows[i].ClassName != "") { selected = i; break; }
            }
        }
        if (selected < 0 && m_Rows.Count() > 0) selected = 0;
        m_ClassName.SetText("");
        if (selected >= 0) { m_Results.SelectRow(selected); SelectRow(selected); }
        m_Updating = false;
        UpdateButtons();
    }

    protected void SelectRow(int row)
    {
        if (row < 0 || row >= m_Rows.Count()) return;
        m_SelectedKey = m_Rows[row].Key;
        m_ClassName.SetText(m_Rows[row].ClassName);
    }

    int RowIndex(string key)
    {
        for (int i = 0; i < m_Rows.Count(); i++) { if (m_Rows[i].Key == key) return i; }
        return -1;
    }

    bool ActivateRow(string key)
    {
        int row = RowIndex(key);
        if (row < 0) return false;
        m_Updating = true;
        m_Results.SelectRow(row);
        SelectRow(row);
        m_Updating = false;
        if (m_Rows[row].ClassName == "")
        {
            if (m_LastQuery != "") m_SearchClosed.Set(key,FolderOpen(key));
            else m_Expanded.Set(key,!FolderOpen(key));
            Filter();
        }
        UpdateButtons();
        return true;
    }

    int MatchCount() { return m_MatchCount; }
    int ShownCount() { return m_Filtered.Count(); }
    int RowCount() { return m_Rows.Count(); }
    string FirstClass() { return m_ClassName.GetText(); }

    void Search(string query)
    {
        m_Updating = true;
        m_Search.SetText(query);
        m_Updating = false;
        Filter();
    }

    void UpdateButtons()
    {
        bool anchor = m_Tool.HasAnchor();
        m_Root.FindAnyWidget("SceneCreate").Enable(m_ClassName.GetText() != "" && (!m_ItemsMode || anchor));
        m_Root.FindAnyWidget("SceneFocus").Enable(anchor);
        m_Root.FindAnyWidget("SceneExport").Enable(anchor);
    }

    void SetStatus(string value) { m_Status.SetText(value); }
    void Show(bool visible) { m_Root.Show(visible); }
    bool IsVisible() { return m_Root.IsVisible(); }

    bool Contains(vector point)
    {
        if (!m_Root.IsVisible()) return false;
        float x,y,width,height;
        m_Root.GetScreenPos(x,y);
        m_Root.GetScreenSize(width,height);
        return point[0] >= x && point[0] <= x+width && point[1] >= y && point[1] <= y+height;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_ShowStatic) { SetShowStaticObjects(m_ShowStatic.IsChecked()); return true; }
        if (w == m_Results)
        {
            int row = m_Results.GetSelectedRow();
            if (row >= 0 && row < m_Rows.Count()) return ActivateRow(m_Rows[row].Key);
        }
        string name = w.GetName();
        if (name == "SceneAnchorsMode") { SetMode(false); return true; }
        if (name == "SceneItemsMode") { SetMode(true); return true; }
        if (name == "SceneFocus") { m_Tool.FocusAnchor(); return true; }
        if (name == "SceneExport") { m_Tool.ExportAnchor(); return true; }
        if (name == "SceneCreate")
        {
            string classname = ResolveClass(m_ClassName.GetText(),m_ItemsMode);
            if (classname == "") { SetStatus(IOTL.T("UNKNOWN_CLASS")); return true; }
            m_Tool.SpawnSceneClass(classname,m_ItemsMode);
            UpdateButtons();
            return true;
        }
        return false;
    }

    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        if (m_Updating) return false;
        if (w == m_ShowStatic) { SetShowStaticObjects(m_ShowStatic.IsChecked()); return true; }
        if (w == m_Search) { Filter(); return true; }
        if (w == m_ClassName) { UpdateButtons(); return true; }
        if (w == m_Results) { SelectRow(m_Results.GetSelectedRow()); UpdateButtons(); return true; }
        return false;
    }

    override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn)
    {
        if (m_Updating || w != m_Results) return false;
        SelectRow(row);
        UpdateButtons();
        return true;
    }

    override bool OnKeyDown(Widget w, int x, int y, int key)
    {
        if (w != m_Results || key != KeyCode.KC_RETURN) return false;
        int row = m_Results.GetSelectedRow();
        if (row >= 0 && row < m_Rows.Count()) return ActivateRow(m_Rows[row].Key);
        return false;
    }
}

// Bottom tray contains only items created by the tool, across all anchors.
class IOTSceneItems : ScriptedWidgetEventHandler
{
    protected IOTProxyTool m_Tool;
    protected Widget m_Root;
    protected TextWidget m_Title;
    protected TextWidget m_PageLabel;
    protected ref array<ButtonWidget> m_Buttons = new array<ButtonWidget>;
    protected ref array<TextWidget> m_Names = new array<TextWidget>;
    protected ref array<TextWidget> m_Owners = new array<TextWidget>;
    protected ref array<ItemBase> m_Items = new array<ItemBase>;
    protected ItemBase m_Selected;
    protected int m_Page;

    void IOTSceneItems(IOTProxyTool tool)
    {
        m_Tool = tool;
        m_Root = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\scene_items.layout");
        m_Title = TextWidget.Cast(m_Root.FindAnyWidget("CreatedTitle"));
        m_PageLabel = TextWidget.Cast(m_Root.FindAnyWidget("CreatedPage"));
        for (int slot = 0; slot < 4; slot++)
        {
            m_Buttons.Insert(ButtonWidget.Cast(m_Root.FindAnyWidget("CreatedItem" + slot.ToString())));
            m_Names.Insert(TextWidget.Cast(m_Root.FindAnyWidget("CreatedName" + slot.ToString())));
            m_Owners.Insert(TextWidget.Cast(m_Root.FindAnyWidget("CreatedOwner" + slot.ToString())));
        }
        m_Root.SetHandler(this);
        m_Root.SetSort(1000);
        Position();
        Render();
    }

    void ~IOTSceneItems()
    {
        if (m_Root) m_Root.Unlink();
    }

    Widget Root() { return m_Root; }
    int Count() { return m_Items.Count(); }
    int Page() { return m_Page; }
    bool IsVisible() { return m_Root.IsVisible(); }
    void Show(bool visible) { m_Root.Show(visible); }

    void Position()
    {
        int width,height;
        GetScreenSize(width,height);
        float trayWidth,trayHeight;
        m_Root.GetScreenSize(trayWidth,trayHeight);
        m_Root.SetScreenPos(Math.Max(12,(width - trayWidth) * 0.5),Math.Max(12,height - trayHeight - 54));
    }

    bool Contains(vector point)
    {
        if (!m_Root.IsVisible()) return false;
        float x,y,width,height;
        m_Root.GetScreenPos(x,y);
        m_Root.GetScreenSize(width,height);
        return point[0] >= x && point[0] <= x+width && point[1] >= y && point[1] <= y+height;
    }

    void Refresh(array<ItemBase> created, ItemBase selected, bool reveal = false)
    {
        m_Items.Clear();
        foreach (ItemBase item : created)
            if (item && !item.IsHologram()) m_Items.Insert(item);
        m_Selected = selected;
        int index = m_Items.Find(selected);
        if (reveal && index >= 0) m_Page = index / 4;
        Render();
    }

    protected void Render()
    {
        int pages = (m_Items.Count() + 3) / 4;
        if (pages < 1) pages = 1;
        if (m_Page >= pages) m_Page = pages - 1;
        if (m_Page < 0) m_Page = 0;
        m_Title.SetText(IOTL.F("TRAY_TITLE",m_Items.Count().ToString()));
        m_PageLabel.SetText((m_Page+1).ToString() + " / " + pages.ToString());
        m_Root.FindAnyWidget("CreatedPrev").Enable(m_Page > 0);
        m_Root.FindAnyWidget("CreatedNext").Enable(m_Page+1 < pages);
        m_Root.FindAnyWidget("CreatedEmpty").Show(m_Items.Count() == 0);
        for (int slot = 0; slot < 4; slot++)
        {
            int index = m_Page*4 + slot;
            bool exists = index < m_Items.Count();
            m_Buttons[slot].Show(exists);
            if (!exists) continue;
            ItemBase item = m_Items[index];
            m_Buttons[slot].SetState(item == m_Selected);
            m_Buttons[slot].Enable(!item.GetHierarchyParent());
            m_Names[slot].SetText(item.GetType());
            if (item == m_Selected) m_Names[slot].SetColor(ARGB(255,30,115,175));
            else m_Names[slot].SetColor(ARGB(255,255,255,255));
            string owner = IOTL.F("TRAY_OWNER",(index+1).ToString(),m_Tool.ItemAnchorId(item).ToString());
            if (item == m_Selected) owner = owner + IOTL.T("TRAY_SELECTED");
            if (item.GetHierarchyParent()) owner = owner + IOTL.T("TRAY_INVENTORY");
            m_Owners[slot].SetText(owner);
            if (item == m_Selected) m_Owners[slot].SetColor(ARGB(255,35,45,55));
            else m_Owners[slot].SetColor(ARGB(255,255,255,255));
        }
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w.GetName() == "CreatedPrev") { m_Page--; Render(); return true; }
        if (w.GetName() == "CreatedNext") { m_Page++; Render(); return true; }
        for (int slot = 0; slot < 4; slot++)
        {
            if (w != m_Buttons[slot]) continue;
            int index = m_Page*4 + slot;
            if (index < m_Items.Count()) m_Tool.SelectCreatedItem(m_Items[index]);
            return true;
        }
        return false;
    }
}

// Offline proxy authoring: existing world items, native Gizmo, precise controls.
// CE export remains calibrated for an unrotated, scale-one anchor / group a=90.
class IOTProxyTool : ScriptedWidgetEventHandler
{
    protected Object m_Anchor;
    protected ref IOTSceneBrowser m_Browser;
    protected ref IOTSceneItems m_CreatedTray;
    protected ref array<ItemBase> m_CreatedItems = new array<ItemBase>;
    protected int m_TrayRefreshTime;
    protected ref array<ref IOTSceneEntry> m_Scenes = new array<ref IOTSceneEntry>;
    protected IOTSceneEntry m_ActiveScene;
    protected string m_RunTag;
    protected ItemBase m_Item;
    protected vector m_Original[4];
    protected bool m_WasSimulationDisabled;
    protected bool m_Editing;
    protected bool m_Pointer;
    protected bool m_Booted;
    protected bool m_PlayerMode;
    protected bool m_PlayerWasDisabled;
    protected bool m_PlayerHudHidden;
    protected bool m_PlayerHudWasVisible;
    protected bool m_HasCameraPose;
    protected vector m_CameraPose[4];
    protected TextWidget m_ModeHint;
    protected Widget m_SpeedRoot;
    protected TextWidget m_SpeedValue;
    protected float m_CameraMultiplier = 1;
    protected int m_SpeedHintUntil;
    protected int m_SkipLookFrames;
    protected bool m_MouseWasDown;
    protected bool m_ClickPending;
    protected bool m_ClickReleased;
    protected bool m_NativeGesture;
    protected int m_ReleaseTime;
    protected vector m_ClickStart;
    protected vector m_ClickEnd;
    protected bool m_ShowDebug;
    protected bool m_GizmoEnabled = true;
    protected bool m_RotateMode;
    protected bool m_DirtyInputs;
    protected bool m_UpdatingUI;
    protected bool m_SelfTest;
    protected int m_Attempts;
    protected int m_MoveStepIndex = 1;
    protected int m_AngleStepIndex = 1;
    protected Widget m_Root;
    protected float m_PanelScale = 1;
    protected TextWidget m_ItemLabel;
    protected TextWidget m_AnchorLabel;
    protected TextWidget m_Status;
    protected TextWidget m_Debug;
    protected XComboBoxWidget m_ItemsList;
    protected XComboBoxWidget m_AnchorsList;
    protected ref array<EditBoxWidget> m_PosFields = new array<EditBoxWidget>;
    protected ref array<EditBoxWidget> m_RotFields = new array<EditBoxWidget>;
    protected ref array<Widget> m_DetailWidgets = new array<Widget>;
    protected ref array<vector> m_DetailPositions = new array<vector>;
    protected ref array<ItemBase> m_Items = new array<ItemBase>;
    protected ref array<Object> m_Anchors = new array<Object>;
    protected Widget m_HeldButton;
    protected int m_HoldStart;
    protected int m_LastRepeat;
    protected Widget m_SuppressClick;
    protected vector m_LastPos;
    protected vector m_LastAngles;

    void IOTProxyTool()
    {
        string argument;
        m_SelfTest = GetGame().CommandlineGetParam("proxyToolSelfTest", argument);
        string path = "iot\\proxytool\\gui\\proxy_tool.layout";
        m_Root = GetGame().GetWorkspace().CreateWidgets(path);
        if (!m_Root)
        {
            PrintToRPT("[PROXY TOOL V2] FAIL: cannot open panel " + path);
            return;
        }
        float initialWidth,initialHeight;
        m_Root.GetScreenSize(initialWidth,initialHeight);
        m_PanelScale = initialWidth / 400;
        m_Root.SetHandler(this);
        m_ModeHint = TextWidget.Cast(GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\player_mode.layout"));
        m_ModeHint.SetOutline(1);
        m_ModeHint.SetShadow(2);
        m_ModeHint.Show(false);
        m_SpeedRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\camera_speed.layout");
        m_SpeedValue = TextWidget.Cast(m_SpeedRoot);
        m_SpeedValue.SetFlags(WidgetFlags.CENTER | WidgetFlags.VCENTER);
        m_SpeedValue.SetBold(true);
        m_SpeedValue.SetShadow(2,ARGB(255,0,0,0),0.8,0,1);
        m_SpeedRoot.Show(false);
        m_ItemLabel = TextWidget.Cast(m_Root.FindAnyWidget("ItemLabel"));
        m_AnchorLabel = TextWidget.Cast(m_Root.FindAnyWidget("AnchorLabel"));
        m_Status = TextWidget.Cast(m_Root.FindAnyWidget("Status"));
        m_Debug = TextWidget.Cast(m_Root.FindAnyWidget("Debug"));
        m_Debug.Show(false);
        m_ItemsList = XComboBoxWidget.Cast(m_Root.FindAnyWidget("ItemList"));
        m_AnchorsList = XComboBoxWidget.Cast(m_Root.FindAnyWidget("AnchorList"));
        for (int i = 0; i < 3; i++)
        {
            m_PosFields.Insert(EditBoxWidget.Cast(m_Root.FindAnyWidget("Pos" + i.ToString())));
            m_RotFields.Insert(EditBoxWidget.Cast(m_Root.FindAnyWidget("Rot" + i.ToString())));
        }
        Widget child = m_Root.GetChildren();
        while (child)
        {
            float x,y;
            child.GetPos(x,y);
            if (y + 0.5 >= 204*m_PanelScale)
            {
                m_DetailWidgets.Insert(child);
                m_DetailPositions.Insert(Vector(x,y,0));
            }
            child = child.GetSibling();
        }
        SelectionControls(false);
        int year,month,day,hour,minute,second;
        GetYearMonthDayUTC(year,month,day);
        GetHourMinuteSecondUTC(hour,minute,second);
        m_RunTag = year.ToString()+"-"+month.ToString()+"-"+day.ToString()+"_"+hour.ToString()+"-"+minute.ToString()+"-"+second.ToString()+"UTC";
        m_Browser = new IOTSceneBrowser(this);
        m_CreatedTray = new IOTSceneItems(this);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Tick, 50, true);
        PrintToRPT("[PROXY TOOL V2] Panel loaded. Click item/empty space; F1 cursor/flight; F4 player/editor; F7/F8 move/rotate; F10 export.");
    }

    void ~IOTProxyTool()
    {
        if (GetGame()) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(Tick);
        SetPlayerHudHidden(false);
        if (m_ModeHint) m_ModeHint.Unlink();
        if (m_SpeedRoot) m_SpeedRoot.Unlink();
        m_Browser = null;
        m_CreatedTray = null;
        if (m_Root) m_Root.Unlink();
    }

    protected void Status(string message)
    {
        if (m_Status) m_Status.SetText(message);
    }

    protected void ButtonText(string name, string text)
    {
        ButtonWidget button = ButtonWidget.Cast(m_Root.FindAnyWidget(name));
        if (button) button.SetText(text);
    }

    protected float Clean(float value)
    {
        if (Math.AbsFloat(value) < 0.00001) return 0;
        return Math.Round(value * 1000000) / 1000000;
    }

    protected string Numbers(vector value)
    {
        return Clean(value[0]).ToString() + " " + Clean(value[1]).ToString() + " " + Clean(value[2]).ToString();
    }

    vector ProxyPosition()
    {
        return ItemProxyPosition(m_Item);
    }

    vector ItemProxyPosition(ItemBase item)
    {
        vector modelPosition = m_Anchor.WorldToModel(item.GetPosition());
        return Vector(modelPosition[2], modelPosition[1], -modelPosition[0]);
    }

    vector ProxyAngles()
    {
        return ItemProxyAngles(m_Item);
    }

    vector ItemProxyAngles(ItemBase item)
    {
        vector anchorMatrix[4];
        vector itemMatrix[4];
        vector relative[4];
        m_Anchor.GetTransform(anchorMatrix);
        item.GetTransform(itemMatrix);
        Math3D.MatrixInvMultiply4(anchorMatrix, itemMatrix, relative);
        float middle = Math.Asin(Math.Clamp(-relative[0][2], -1, 1));
        float first;
        float third;
        if (Math.AbsFloat(Math.Cos(middle)) > 0.00001)
        {
            first = Math.Atan2(relative[1][2], relative[2][2]);
            third = Math.Atan2(relative[0][1], relative[0][0]);
        }
        else
        {
            first = Math.Atan2(-relative[2][1], relative[1][1]);
        }
        return Vector(Clean(first * Math.RAD2DEG), Clean(middle * Math.RAD2DEG), Clean(third * Math.RAD2DEG));
    }

    // Inverse of the measured CE matrix decomposition; no game-YPR guessing.
    void SetProxyPose(vector position, vector angles)
    {
        if (!m_Item || !m_Anchor) return;
        float x = angles[0] * Math.DEG2RAD;
        float y = angles[1] * Math.DEG2RAD;
        float z = angles[2] * Math.DEG2RAD;
        float cx = Math.Cos(x);
        float sx = Math.Sin(x);
        float cy = Math.Cos(y);
        float sy = Math.Sin(y);
        float cz = Math.Cos(z);
        float sz = Math.Sin(z);
        vector localMatrix[4];
        localMatrix[0] = Vector(cz * cy, sz * cy, -sy);
        localMatrix[1] = Vector(cz * sy * sx - sz * cx, sz * sy * sx + cz * cx, cy * sx);
        localMatrix[2] = Vector(cz * sy * cx + sz * sx, sz * sy * cx - cz * sx, cy * cx);
        localMatrix[3] = Vector(-position[2], position[1], position[0]);
        vector anchorMatrix[4];
        vector worldMatrix[4];
        m_Anchor.GetTransform(anchorMatrix);
        Math3D.MatrixMultiply4(anchorMatrix, localMatrix, worldMatrix);
        m_Item.SetTransform(worldMatrix);
        m_DirtyInputs = false;
        SyncFields();
    }

    protected bool ValidAnchor(Object candidate)
    {
        if (!candidate || ItemBase.Cast(candidate)) return false;
        string name = candidate.GetType();
        return name.IndexOf("Land_") == 0 || name.IndexOf("StaticObj_") == 0;
    }

    bool HasAnchor() { return m_Anchor != null; }

    protected IOTSceneEntry RegisterAnchor(Object anchor)
    {
        foreach (IOTSceneEntry existing : m_Scenes)
            if (existing.Anchor == anchor) return existing;
        IOTSceneEntry scene = new IOTSceneEntry;
        scene.Anchor = anchor;
        scene.Id = m_Scenes.Count() + 1;
        m_Scenes.Insert(scene);
        return scene;
    }

    protected IOTSceneEntry ItemScene(ItemBase item)
    {
        foreach (IOTSceneEntry scene : m_Scenes)
            if (scene.Items.Find(item) >= 0) return scene;
        return null;
    }

    int ItemAnchorId(ItemBase item)
    {
        IOTSceneEntry scene = ItemScene(item);
        if (scene) return scene.Id;
        return 0;
    }

    protected void RefreshCreatedItems(bool reveal = false)
    {
        if (m_CreatedTray) m_CreatedTray.Refresh(m_CreatedItems,m_Item,reveal);
    }

    bool SelectCreatedItem(ItemBase item)
    {
        if (m_PlayerMode || m_CreatedItems.Find(item) < 0) return false;
        IOTSceneEntry owner = ItemScene(item);
        bool changedAnchor = owner && owner.Anchor != m_Anchor;
        if (!SelectItem(item)) return false;
        if (changedAnchor) FocusAnchor();
        RefreshObjects();
        return true;
    }

    protected void SceneStatus(string value)
    {
        Status(value);
        if (m_Browser) m_Browser.SetStatus(value);
    }

    protected void SeparateAnchor(Object created)
    {
        vector bounds[2];
        vector otherBounds[2];
        created.ClippingInfo(bounds);
        vector minimum = bounds[0];
        vector maximum = bounds[1];
        for (int attempt = 0; attempt <= m_Scenes.Count(); attempt++)
        {
            bool clear = true;
            foreach (IOTSceneEntry scene : m_Scenes)
            {
                if (!scene.Anchor || scene.Anchor == created) continue;
                scene.Anchor.ClippingInfo(otherBounds);
                vector otherMinimum = otherBounds[0];
                vector otherMaximum = otherBounds[1];
                vector position = created.GetPosition();
                vector other = scene.Anchor.GetPosition();
                bool overlapX = position[0]+minimum[0] < other[0]+otherMaximum[0]+8 && position[0]+maximum[0] > other[0]+otherMinimum[0] - 8;
                bool overlapZ = position[2]+minimum[2] < other[2]+otherMaximum[2]+8 && position[2]+maximum[2] > other[2]+otherMinimum[2] - 8;
                if (!overlapX || !overlapZ) continue;
                position[0] = other[0]+otherMaximum[0] - minimum[0] + 8;
                position[1] = GetGame().SurfaceY(position[0],position[2]);
                created.SetPosition(position);
                created.PlaceOnSurface();
                created.SetOrientation("0 0 0");
                clear = false;
                break;
            }
            if (clear) return;
        }
    }

    void FocusAnchor()
    {
        if (!m_Anchor || m_PlayerMode) return;
        vector bounds[2];
        m_Anchor.ClippingInfo(bounds);
        vector center = m_Anchor.ModelToWorld((bounds[0]+bounds[1])*0.5);
        float radius = Math.Max((bounds[1]-bounds[0]).Length()*0.5,2);
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        camera.SetPosition(center+Vector(radius*1.7,radius*1.1,-radius*2.6));
        camera.LookAt(center);
        SetPointer(true);
    }

    bool SpawnSceneClass(string classname, bool itemMode)
    {
        if (m_PlayerMode) return false;
        classname = m_Browser.ResolveClass(classname,itemMode);
        if (classname == "") { SceneStatus(IOTL.T("UNKNOWN_CLASS")); return false; }
        if (itemMode && !m_Anchor) { SceneStatus(IOTL.T("ANCHOR_REQUIRED")); return false; }
        vector direction = GetGame().GetCurrentCameraDirection();
        direction[1] = 0;
        if (direction.Length() < 0.01) direction = "0 0 1";
        direction.Normalize();
        vector position = GetGame().GetCurrentCameraPosition() + direction*15;
        if (itemMode)
        {
            vector anchorBounds[2];
            m_Anchor.ClippingInfo(anchorBounds);
            int index = m_ActiveScene.Items.Count();
            int row = index / 6;
            int column = index - row*6;
            position = m_Anchor.GetPosition()+Vector(anchorBounds[1][0]+1.5+column*0.7,0,anchorBounds[0][2] - 2 - row*0.7);
        }
        position[1] = GetGame().SurfaceY(position[0],position[2]) + 0.1;
        int flags = ECE_SETUP | ECE_CREATEPHYSICS | ECE_UPDATEPATHGRAPH | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOSURFACEALIGN;
        Object created = GetGame().CreateObjectEx(classname,position,flags,RF_IGNORE);
        if (!created) { SceneStatus(IOTL.F("SPAWN_FAILED",classname)); return false; }
        created.SetOrientation("0 0 0");
        created.SetScale(1);
        created.PlaceOnSurface();
        created.SetOrientation("0 0 0");
        if (itemMode)
        {
            ItemBase item = ItemBase.Cast(created);
            if (!item)
            {
                GetGame().ObjectDelete(created);
                SceneStatus(IOTL.T("NOT_INVENTORY_ITEM"));
                return false;
            }
            // PlaceOnSurface may use the item's configured resting rotation.
            // Recompute ground contact after restoring the editor's zero rotation.
            vector itemBounds[2];
            item.ClippingInfo(itemBounds);
            position = item.GetPosition();
            position[1] = GetGame().SurfaceY(position[0],position[2]) - itemBounds[0][1] + 0.02;
            item.SetPosition(position);
            item.DisableSimulation(false);
            m_ActiveScene.Items.Insert(item);
            m_CreatedItems.Insert(item);
            SelectItem(item);
        }
        else
        {
            if (!ValidAnchor(created))
            {
                GetGame().ObjectDelete(created);
                SceneStatus(IOTL.T("NOT_ANCHOR"));
                return false;
            }
            SeparateAnchor(created);
            SetAnchor(created);
            FocusAnchor();
        }
        RefreshObjects();
        m_Browser.UpdateButtons();
        SceneStatus(IOTL.F("CREATED",classname));
        PrintToRPT("[PROXY SCENE] Created " + classname + " at " + created.GetPosition().ToString(false));
        return true;
    }

    bool SetAnchor(Object candidate)
    {
        if (!candidate)
        {
            DeselectItem();
            m_Anchor = null;
            m_ActiveScene = null;
            if (m_Browser) m_Browser.UpdateButtons();
            return true;
        }
        if (!ValidAnchor(candidate)) return false;
        if (candidate.GetOrientation().Length() > 0.001 || Math.AbsFloat(candidate.GetScale() - 1) > 0.0001)
        {
            Status(IOTL.T("ANCHOR_TRANSFORM_LIMIT"));
            return false;
        }
        if (candidate != m_Anchor) DeselectItem();
        m_Anchor = candidate;
        m_ActiveScene = RegisterAnchor(candidate);
        if (m_Browser) m_Browser.UpdateButtons();
        if (m_Item) m_DirtyInputs = false;
        SyncFields();
        return true;
    }

    bool SelectItem(ItemBase item)
    {
        if (m_PlayerMode || !item || item.GetHierarchyParent() || item.IsHologram()) return false;
        IOTSceneEntry owner = ItemScene(item);
        if (owner && owner.Anchor != m_Anchor) SetAnchor(owner.Anchor);
        if (!m_Anchor) { SceneStatus(IOTL.T("ANCHOR_REQUIRED")); return false; }
        if (!owner && m_ActiveScene.Items.Find(item) < 0) m_ActiveScene.Items.Insert(item);
        if (item == m_Item && m_Editing) return true;
        if (m_Item && m_Editing)
        {
            GetGizmoApi().DeselectTracker(this);
            m_Item.DisableSimulation(m_WasSimulationDisabled);
        }
        m_Item = item;
        vector initial[4];
        m_Item.GetTransform(initial);
        copyarray(m_Original, initial);
        m_WasSimulationDisabled = m_Item.GetIsSimulationDisabled();
        m_Item.DisableSimulation(true);
        m_Editing = true;
        m_DirtyInputs = false;
        UpdateGizmo();
        SelectionControls(true);
        SyncFields();
        PrintToRPT("[PROXY SELECTION] Selected " + m_Item.GetType());
        RefreshCreatedItems(true);
        Status(IOTL.T("GIZMO_HINT"));
        return true;
    }

    protected void SelectionControls(bool enabled)
    {
        m_Root.FindAnyWidget("MoveMode").Show(enabled);
        m_Root.FindAnyWidget("RotateMode").Show(enabled);
        float offset = -44*m_PanelScale;
        if (enabled) offset = 0;
        for (int detail = 0; detail < m_DetailWidgets.Count(); detail++)
        {
            vector position = m_DetailPositions[detail];
            m_DetailWidgets[detail].SetPos(position[0],position[1]+offset);
        }
        ResizePanel();
        array<string> names = {"MoveMode","RotateMode","MoveStep","AngleStep","ApplyValues","Reset","Export","Ground"};
        foreach (string name : names)
        {
            Widget control = m_Root.FindAnyWidget(name);
            if (control) control.Enable(enabled);
        }
        for (int axis = 0; axis < 3; axis++)
        {
            m_PosFields[axis].Enable(enabled);
            m_RotFields[axis].Enable(enabled);
            m_Root.FindAnyWidget("PosMinus"+axis.ToString()).Enable(enabled);
            m_Root.FindAnyWidget("PosPlus"+axis.ToString()).Enable(enabled);
            m_Root.FindAnyWidget("RotMinus"+axis.ToString()).Enable(enabled);
            m_Root.FindAnyWidget("RotPlus"+axis.ToString()).Enable(enabled);
        }
    }

    protected void ResizePanel()
    {
        float height = 650;
        if (m_ShowDebug) height = 730;
        if (!m_Item) height = height - 44;
        m_Root.SetScreenSize(400*m_PanelScale,height*m_PanelScale);
    }

    void DeselectItem()
    {
        GetGizmoApi().DeselectTracker(this);
        if (m_Item && m_Editing)
        {
            m_Item.DisableSimulation(m_WasSimulationDisabled);
            PrintToRPT("[PROXY SELECTION] Cleared " + m_Item.GetType() + "; restored simulation disabled=" + m_WasSimulationDisabled.ToString());
        }
        m_Item = null;
        m_Editing = false;
        m_DirtyInputs = false;
        m_HeldButton = null;
        m_UpdatingUI = true;
        for (int axis = 0; axis < 3; axis++)
        {
            m_PosFields[axis].SetText("");
            m_RotFields[axis].SetText("");
        }
        if (m_ItemsList.GetNumItems() > 0) m_ItemsList.SetCurrentItem(0);
        m_UpdatingUI = false;
        SelectionControls(false);
        RefreshCreatedItems();
        Status(IOTL.T("DESELECT_HINT"));
    }

    void RefreshObjects()
    {
        vector center;
        if (GetGame().GetPlayer()) center = GetGame().GetPlayer().GetPosition();
        if (m_Anchor) center = m_Anchor.GetPosition();
        float radius = 25;
        if (m_Anchor)
        {
            vector bounds[2];
            radius = Math.Clamp(m_Anchor.ClippingInfo(bounds)+20,25,300);
        }
        array<Object> objects = new array<Object>;
        array<CargoBase> cargo = new array<CargoBase>;
        GetGame().GetObjectsAtPosition3D(center, radius, objects, cargo);
        m_Items.Clear();
        m_Anchors.Clear();
        m_UpdatingUI = true;
        m_ItemsList.ClearAll();
        m_ItemsList.AddItem(IOTL.T("NO_ITEM"));
        m_ItemsList.SetCurrentItem(0);
        m_AnchorsList.ClearAll();
        m_AnchorsList.AddItem(IOTL.T("NO_ANCHOR"));
        m_AnchorsList.SetCurrentItem(0);
        foreach (IOTSceneEntry scene : m_Scenes)
        {
            if (!scene.Anchor) continue;
            int sceneIndex = m_Anchors.Insert(scene.Anchor);
            m_AnchorsList.AddItem(scene.Anchor.GetType()+" · "+scene.Id.ToString());
            if (scene.Anchor == m_Anchor) m_AnchorsList.SetCurrentItem(sceneIndex+1);
        }
        if (m_ActiveScene)
        {
            foreach (ItemBase tracked : m_ActiveScene.Items)
            {
                if (!tracked || tracked.GetHierarchyParent() || tracked.IsHologram()) continue;
                int trackedIndex = m_Items.Insert(tracked);
                m_ItemsList.AddItem(tracked.GetType());
                if (tracked == m_Item) m_ItemsList.SetCurrentItem(trackedIndex+1);
            }
        }
        foreach (Object candidate : objects)
        {
            ItemBase loose = ItemBase.Cast(candidate);
            if (loose && !loose.GetHierarchyParent() && !loose.IsHologram())
            {
                if (m_Items.Find(loose) >= 0) continue;
                IOTSceneEntry owner = ItemScene(loose);
                if (owner && owner != m_ActiveScene) continue;
                int itemIndex = m_Items.Insert(loose);
                m_ItemsList.AddItem(loose.GetType());
                if (loose == m_Item) m_ItemsList.SetCurrentItem(itemIndex + 1);
            }
            else if (ValidAnchor(candidate))
            {
                if (m_Anchors.Find(candidate) >= 0) continue;
                int anchorIndex = m_Anchors.Insert(candidate);
                m_AnchorsList.AddItem(candidate.GetType());
                if (candidate == m_Anchor) m_AnchorsList.SetCurrentItem(anchorIndex+1);
            }
        }
        m_UpdatingUI = false;
        RefreshCreatedItems();
    }

    protected bool Boot()
    {
        if (!GetGame().GetPlayer() || !m_Browser || !m_CreatedTray) return false;
        RefreshObjects();
        DeselectItem();
        EnterEditor();
        SceneStatus(IOTL.T("START_HINT"));
        PrintToRPT("[PROXY TOOL V2] Editor ready: camera active, no item selected; loose items=" + m_Items.Count().ToString());
        return true;
    }

    protected bool PanelPoint(vector point)
    {
        if (m_Browser && m_Browser.Contains(point)) return true;
        if (m_CreatedTray && m_CreatedTray.Contains(point)) return true;
        if (!m_Root.IsVisible()) return false;
        float x,y,width,height;
        m_Root.GetScreenPos(x,y);
        m_Root.GetScreenSize(width,height);
        return point[0] >= x && point[0] <= x+width && point[1] >= y && point[1] <= y+height;
    }

    vector PointerRay(vector point)
    {
        return GetGame().GetWorldDirectionFromScreen(Vector(point[0],point[1],0)).Normalized();
    }

    Object PointerObject(vector point)
    {
        vector from = GetGame().GetCurrentCameraPosition();
        vector to = from + PointerRay(point)*100;
        vector hit,normal;
        int component;
        set<Object> results = new set<Object>;
        if (DayZPhysics.RaycastRV(from,to,hit,normal,component,results,null,GetGame().GetPlayer(),true))
        {
            foreach (Object candidate : results) return candidate;
        }
        return null;
    }

    void PickPoint(vector point)
    {
        if (m_PlayerMode) return;
        ItemBase item = ItemBase.Cast(PointerObject(point));
        if (!SelectItem(item)) DeselectItem();
        RefreshObjects();
    }

    void MousePress(int button)
    {
        if (button != MouseState.LEFT || !m_Booted || m_PlayerMode || !m_Pointer || m_ClickPending || !GetGame().IsAppActive() || GetGame().GetUIManager().GetMenu()) return;
        int x,y;
        GetMousePos(x,y);
        vector point = Vector(x,y,0);
        if (PanelPoint(point)) return;
        m_ClickStart = point;
        m_ClickPending = true;
        m_ClickReleased = false;
        m_NativeGesture = false;
    }

    void MouseRelease(int button)
    {
        if (button != MouseState.LEFT || !m_ClickPending || m_ClickReleased) return;
        int x,y;
        GetMousePos(x,y);
        m_ClickEnd = Vector(x,y,0);
        m_ClickReleased = true;
        m_ReleaseTime = GetGame().GetTime();
    }

    protected string CameraMultiplierText()
    {
        int tenths = Math.Floor(m_CameraMultiplier * 10 + 0.5);
        if (tenths >= 160) return "16x";
        int whole = tenths / 10;
        int fraction = tenths % 10;
        return whole.ToString() + "." + fraction.ToString() + "x";
    }

    protected void PositionCameraMultiplier()
    {
        int width,height;
        GetScreenSize(width,height);
        m_SpeedRoot.SetPos(width * 0.5 - 100,height * 0.5 + 18);
    }

    protected void ShowCameraMultiplier()
    {
        m_SpeedValue.SetText(CameraMultiplierText());
        PositionCameraMultiplier();
        m_SpeedHintUntil = GetGame().GetTime() + 2000;
        m_SpeedRoot.Show(!m_PlayerMode && !m_Pointer);
    }

    void ChangeCameraSpeed(int steps)
    {
        m_CameraMultiplier = Math.Clamp(m_CameraMultiplier * Math.Pow(1.25,steps),0.1,16);
        ShowCameraMultiplier();
        PrintToRPT("[PROXY CAMERA] Multiplier=" + m_CameraMultiplier.ToString() + " display=" + CameraMultiplierText());
    }

    // The tool owns flight translation and look, so the displayed coefficient
    // is the same value used for movement, including while stationary.
    protected void MoveFlightCamera(float timeslice, float forward, float side, float vertical, float yaw, float pitch, float boost)
    {
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        vector angles = camera.GetOrientation();
        angles[0] = angles[0] - Math.RAD2DEG * yaw * timeslice;
        angles[1] = Math.Clamp(angles[1] - Math.RAD2DEG * pitch * timeslice,-89,89);
        camera.SetOrientation(angles);
        vector direction = camera.GetDirection().Normalized();
        vector right = (vector.Up * direction).Normalized();
        vector movement = direction * forward + right * side + vector.Up * vertical;
        if (movement.Length() > 1) movement.Normalize();
        camera.SetPosition(camera.GetPosition() + movement * (5.0 * m_CameraMultiplier * boost * timeslice));
    }

    protected void UpdateFlightCamera(float timeslice)
    {
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        // Freeze the native controller, keeping its camera and the native Gizmo.
        if (camera && camera.IsActive() && !m_PlayerMode) camera.SetFreezed(true);
        bool flying = m_Booted && !m_PlayerMode && !m_Pointer && camera && camera.IsActive() && GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu();
        if (!flying)
        {
            m_SpeedRoot.Show(false);
            return;
        }
        Input input = GetGame().GetInput();
        // These existing mouse-wheel actions respect the player's input bindings.
        if (input.LocalPress("UAZoomInOptics")) ChangeCameraSpeed(1);
        if (input.LocalPress("UAZoomOutOptics")) ChangeCameraSpeed(-1);
        m_SpeedRoot.Show(GetGame().GetTime() < m_SpeedHintUntil);
        if (m_SpeedRoot.IsVisible()) PositionCameraMultiplier();
        if (timeslice <= 0 || timeslice > 0.25) return;
        float forward = input.LocalValue("UAMoveForward") - input.LocalValue("UAMoveBack");
        float side = input.LocalValue("UAMoveRight") - input.LocalValue("UAMoveLeft");
        float vertical = input.LocalValue("UABuldMoveUp") - input.LocalValue("UABuldMoveDown");
        float yaw = input.LocalValue("UAAimLeft") - input.LocalValue("UAAimRight");
        float pitch = input.LocalValue("UAAimDown") - input.LocalValue("UAAimUp");
        if (m_SkipLookFrames > 0)
        {
            m_SkipLookFrames--;
            yaw = 0;
            pitch = 0;
        }
        float boost = 1;
        if (KeyState(KeyCode.KC_LSHIFT) || KeyState(KeyCode.KC_RSHIFT) || KeyState(KeyCode.KC_LCONTROL) || KeyState(KeyCode.KC_RCONTROL)) boost = 10;
        if (KeyState(KeyCode.KC_LMENU) || KeyState(KeyCode.KC_RMENU)) boost = boost * 0.1;
        MoveFlightCamera(timeslice,forward,side,vertical,yaw,pitch,boost);
    }

    void FrameUpdate(float timeslice)
    {
        // MissionGameplay can update HUD visibility while menus open or close.
        if (m_Booted && !m_PlayerMode) SetPlayerHudHidden(true);
        UpdateFlightCamera(timeslice);
        if (!m_Booted || m_PlayerMode || !GetGame().IsAppActive() || GetGame().GetUIManager().GetMenu())
        {
            m_ClickPending = false;
            m_MouseWasDown = false;
            return;
        }
        if (m_Pointer)
        {
            int x,y;
            GetMousePos(x,y);
            bool panel = PanelPoint(Vector(x,y,0));
            if (panel && GetGame().GetInput().HasGameFocus()) GetGame().GetInput().ChangeGameFocus(1);
            else if (!panel && !GetGame().GetInput().HasGameFocus()) GetGame().GetInput().ResetGameFocus();
        }
        bool down = (GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK) != 0;
        if (down && !m_MouseWasDown) MousePress(MouseState.LEFT);
        if (!down && m_MouseWasDown) MouseRelease(MouseState.LEFT);
        m_MouseWasDown = down;
        if (m_ClickPending && m_ClickReleased && GetGame().GetTime() - m_ReleaseTime >= 35)
        {
            bool select = !m_NativeGesture && vector.Distance(m_ClickStart,m_ClickEnd) < 5;
            vector point = m_ClickEnd;
            m_ClickPending = false;
            if (select) PickPoint(point);
        }
    }

    protected Widget PlayerHudRoot()
    {
        if (!GetGame() || !GetGame().GetMission()) return null;
        IngameHud hud = IngameHud.Cast(GetGame().GetMission().GetHud());
        if (!hud) return null;
        return hud.GetHudPanelWidget();
    }

    protected void SetPlayerHudHidden(bool hidden)
    {
        Widget hudRoot = PlayerHudRoot();
        if (!hudRoot) return;
        if (hidden)
        {
            if (!m_PlayerHudHidden)
            {
                m_PlayerHudWasVisible = hudRoot.IsVisible();
                m_PlayerHudHidden = true;
            }
            if (hudRoot.IsVisible()) hudRoot.Show(false);
        }
        else if (m_PlayerHudHidden)
        {
            hudRoot.Show(m_PlayerHudWasVisible);
            m_PlayerHudHidden = false;
        }
    }

    void EnterEditor()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player)
        {
            m_PlayerWasDisabled = player.GetIsSimulationDisabled();
            player.DisableSimulation(true);
        }
        m_PlayerMode = false;
        SetPlayerHudHidden(true);
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        if (camera)
        {
            camera.SetActive(true);
            if (m_HasCameraPose) camera.SetTransform(m_CameraPose);
            else if (player)
            {
                camera.SetPosition(player.GetPosition()+"0 2 -1.5");
                camera.LookAt(player.GetPosition()+"0.2 0.3 3");
            }
        }
        m_Root.Show(true);
        m_Browser.Show(true);
        m_CreatedTray.Position();
        m_CreatedTray.Show(true);
        m_ModeHint.Show(false);
        SetPointer(true);
        RefreshObjects();
        DeselectItem();
    }

    void EnterPlayer()
    {
        if (m_PlayerMode) return;
        DeselectItem();
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        if (camera)
        {
            vector pose[4];
            camera.GetTransform(pose);
            copyarray(m_CameraPose,pose);
            m_HasCameraPose = true;
            camera.SetFreezed(false);
            camera.SetActive(false);
        }
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player) player.DisableSimulation(m_PlayerWasDisabled);
        m_PlayerMode = true;
        m_Pointer = false;
        m_ClickPending = false;
        m_Root.Show(false);
        m_Browser.Show(false);
        m_CreatedTray.Show(false);
        m_ModeHint.Show(true);
        m_SpeedRoot.Show(false);
        SetPlayerHudHidden(false);
        m_SpeedHintUntil = 0;
        SetFocus(null);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor(false);
        PrintToRPT("[PROXY MODES] Player: camera off, gizmo off, ordinary gameplay input restored.");
    }

    void SetPointer(bool pointer)
    {
        if (m_PlayerMode) return;
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        if (camera && !camera.IsActive()) camera.SetActive(true);
        if (pointer)
        {
            GetGame().GetInput().ResetGameFocus();
            GetGame().GetUIManager().ShowUICursor(true);
        }
        else
        {
            GetGame().GetInput().ResetGameFocus();
            GetGame().GetUIManager().ShowUICursor(false);
            SetFocus(null);
        }
        if (camera) camera.SetFreezed(true);
        m_Pointer = pointer;
        m_HeldButton = null;
        m_ClickPending = false;
        m_SkipLookFrames = 2;
        if (pointer) m_SpeedRoot.Show(false);
        else ShowCameraMultiplier();
    }

    protected void UpdateGizmo()
    {
        GizmoApi api = GetGizmoApi();
        if (!api) return;
        api.DeselectTracker(this);
        if (!m_PlayerMode && m_GizmoEnabled && m_Item && m_Editing)
        {
            api.SelectUser(this);
            if (m_RotateMode) api.SetTransformMode(GizmoTransformMode.ROTATE);
            else api.SetTransformMode(GizmoTransformMode.MOVE);
            api.SetSpaceMode(GizmoSpaceMode.WORLD);
        }
        if (m_GizmoEnabled) ButtonText("Gizmo", IOTL.T("GIZMO_ON"));
        else ButtonText("Gizmo", IOTL.T("GIZMO_OFF"));
        ButtonWidget moveButton = ButtonWidget.Cast(m_Root.FindAnyWidget("MoveMode"));
        ButtonWidget rotateButton = ButtonWidget.Cast(m_Root.FindAnyWidget("RotateMode"));
        if (moveButton) moveButton.SetState(!m_RotateMode);
        if (rotateButton) rotateButton.SetState(m_RotateMode);
    }

    bool Gizmo_IsSupported() { return m_Editing && m_Item != null; }
    bool Gizmo_IsAllowedTransformMode(GizmoTransformMode mode) { return mode == GizmoTransformMode.MOVE || mode == GizmoTransformMode.ROTATE; }
    bool Gizmo_IsAllowedSpaceMode(GizmoSpaceMode mode) { return true; }
    void Gizmo_GetWorldTransform(vector transform[4]) { if (m_Item) m_Item.GetTransform(transform); }
    void Gizmo_SetWorldTransform(vector transform[4], bool finalize)
    {
        if (m_PlayerMode || !m_Item || !m_Editing) return;
        if (m_ClickPending) m_NativeGesture = true;
        m_Item.SetTransform(transform);
        if (finalize) { m_DirtyInputs = false; SyncFields(); }
    }

    protected float MoveStep()
    {
        if (m_MoveStepIndex == 0) return 0.001;
        if (m_MoveStepIndex == 2) return 0.1;
        return 0.01;
    }

    protected float AngleStep()
    {
        if (m_AngleStepIndex == 0) return 0.1;
        if (m_AngleStepIndex == 2) return 5;
        return 1;
    }

    void Nudge(bool rotate, int axis, int direction, bool fine = false)
    {
        if (!m_Item || !m_Anchor || !m_Editing) return;
        vector position = ProxyPosition();
        vector angles = ProxyAngles();
        float factor = direction;
        if (fine) factor = factor * 0.1;
        if (rotate) angles[axis] = angles[axis] + AngleStep() * factor;
        else position[axis] = position[axis] + MoveStep() * factor;
        SetProxyPose(position, angles);
    }

    protected bool NudgeButton(Widget widget)
    {
        if (!widget) return false;
        string name = widget.GetName();
        for (int axis = 0; axis < 3; axis++)
        {
            string suffix = axis.ToString();
            if (name == "PosMinus" + suffix) { Nudge(false, axis, -1); return true; }
            if (name == "PosPlus" + suffix) { Nudge(false, axis, 1); return true; }
            if (name == "RotMinus" + suffix) { Nudge(true, axis, -1); return true; }
            if (name == "RotPlus" + suffix) { Nudge(true, axis, 1); return true; }
        }
        return false;
    }

    protected bool ValidNumber(string value)
    {
        value.TrimInPlace();
        value.Replace(",", ".");
        if (value.Length() == 0) return false;
        int digits;
        int dots;
        for (int i = 0; i < value.Length(); i++)
        {
            string c = value.Substring(i, 1);
            if ("0123456789".Contains(c)) digits++;
            else if (c == ".") dots++;
            else if (i != 0 || (c != "-" && c != "+")) return false;
        }
        return digits > 0 && dots <= 1;
    }

    bool ApplyFields()
    {
        if (!m_Item || !m_Anchor) return false;
        vector position;
        vector angles;
        for (int i = 0; i < 3; i++)
        {
            string p = m_PosFields[i].GetText();
            string r = m_RotFields[i].GetText();
            if (!ValidNumber(p) || !ValidNumber(r))
            {
                Status(IOTL.T("INVALID_NUMBER"));
                return false;
            }
            p.Replace(",", ".");
            r.Replace(",", ".");
            position[i] = p.ToFloat();
            angles[i] = r.ToFloat();
            if (Math.AbsFloat(position[i]) > 100 || Math.AbsFloat(angles[i]) > 3600)
            {
                Status(IOTL.T("NUMBER_LIMIT"));
                return false;
            }
        }
        SetProxyPose(position, angles);
        Status(IOTL.T("POSE_APPLIED"));
        return true;
    }

    protected void SyncFields()
    {
        if (!m_Item || !m_Anchor || m_DirtyInputs) return;
        m_UpdatingUI = true;
        vector position = ProxyPosition();
        vector angles = ProxyAngles();
        for (int i = 0; i < 3; i++)
        {
            m_PosFields[i].SetText(Clean(position[i]).ToString());
            m_RotFields[i].SetText(Clean(angles[i]).ToString());
        }
        m_LastPos = position;
        m_LastAngles = angles;
        m_ItemLabel.SetText(IOTL.T("ITEM"));
        m_AnchorLabel.SetText(IOTL.T("ANCHOR"));
        m_UpdatingUI = false;
    }

    void Ground()
    {
        if (!m_Item || !m_Anchor) return;
        vector position = m_Anchor.GetPosition() + "1 0 -3.5";
        position[1] = GetGame().SurfaceY(position[0], position[2]);
        m_Item.SetOrientation("0 0 0");
        vector bounds[2];
        m_Item.ClippingInfo(bounds);
        position[1] = position[1] - bounds[0][1] + 0.02;
        m_Item.SetPosition(position);
        m_DirtyInputs = false;
        SyncFields();
        Status(IOTL.T("GROUNDED"));
    }

    void Reset()
    {
        if (!m_Item) return;
        m_Item.SetTransform(m_Original);
        m_DirtyInputs = false;
        SyncFields();
        Status(IOTL.T("POSE_RESET"));
    }

    string ProxyLine()
    {
        return ItemProxyLine(m_Item);
    }

    string ItemProxyLine(ItemBase item)
    {
        return "<proxy type=\"" + item.GetType() + "\" pos=\"" + Numbers(ItemProxyPosition(item)) + "\" rpy=\"" + Numbers(ItemProxyAngles(item)) + "\" />";
    }

    bool ExportAnchor()
    {
        if (!m_Anchor || !m_ActiveScene) return false;
        if (m_Item && m_DirtyInputs && !ApplyFields()) return false;
        string folder = "$profile:ProxyPlacement";
        MakeDirectory(folder);
        folder = folder+"/"+m_Anchor.GetType();
        MakeDirectory(folder);
        string path = folder+"/"+m_RunTag+"_scene_"+m_ActiveScene.Id.ToString()+".xml";
        FileHandle file = OpenFile(path,FileMode.WRITE);
        if (!file) { SceneStatus(IOTL.T("ANCHOR_XML_FAILED")); return false; }
        FPrintln(file,"<prototype>");
        FPrintln(file,"  <group name=\""+m_Anchor.GetType()+"\">");
        FPrintln(file,"    <dispatch>");
        int count;
        foreach (ItemBase item : m_ActiveScene.Items)
        {
            if (!item || item.GetHierarchyParent() || item.IsHologram()) continue;
            FPrintln(file,"      "+ItemProxyLine(item));
            count++;
        }
        FPrintln(file,"    </dispatch>");
        FPrintln(file,"  </group>");
        FPrintln(file,"</prototype>");
        CloseFile(file);
        SceneStatus(IOTL.F("ANCHOR_XML_SAVED",count.ToString()));
        PrintToRPT("[PROXY SCENE EXPORT] " + path + " proxies=" + count.ToString());
        return true;
    }

    bool Export()
    {
        if (!m_Item || !m_Anchor) return false;
        if (m_DirtyInputs && !ApplyFields()) return false;
        string folder = "$profile:ProxyPlacement";
        MakeDirectory(folder);
        FileHandle file = OpenFile(folder + "/selection.xml", FileMode.WRITE);
        if (!file) { Status(IOTL.T("XML_FAILED")); return false; }
        FPrintln(file, "<prototype>");
        FPrintln(file, "  <group name=\"" + m_Anchor.GetType() + "\">");
        FPrintln(file, "    <dispatch>");
        FPrintln(file, "      " + ProxyLine());
        FPrintln(file, "    </dispatch>");
        FPrintln(file, "  </group>");
        FPrintln(file, "</prototype>");
        CloseFile(file);
        file = OpenFile(folder + "/" + m_Item.GetType() + ".proxy.xml", FileMode.WRITE);
        if (file) { FPrintln(file, ProxyLine()); CloseFile(file); }
        PrintToRPT("[PROXY TOOL V2] EXPORTED " + m_Anchor.GetType() + " / " + ProxyLine());
        return ExportAnchor();
    }

    override bool OnMouseButtonDown(Widget w, int x, int y, int button)
    {
        Widget widget = w;
        if (button == 0 && NudgeButton(widget))
        {
            m_HeldButton = widget;
            m_SuppressClick = widget;
            m_HoldStart = GetGame().GetTime();
            m_LastRepeat = m_HoldStart;
            return true;
        }
        return false;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button)
    {
        m_HeldButton = null;
        MouseRelease(button);
        return false;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
    {
        Widget widget = w;
        if (widget == m_HeldButton) m_HeldButton = null;
        return false;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        Widget widget = w;
        if (widget == m_SuppressClick) { m_SuppressClick = null; return true; }
        if (NudgeButton(widget)) return true;
        string name = widget.GetName();
        if (name == "PlayerMode") { EnterPlayer(); return true; }
        if (name == "ApplyValues") { ApplyFields(); return true; }
        if (name == "MoveMode") { m_RotateMode = false; UpdateGizmo(); return true; }
        if (name == "RotateMode") { m_RotateMode = true; UpdateGizmo(); return true; }
        if (name == "Ground") { Ground(); return true; }
        if (name == "Reset") { Reset(); return true; }
        if (name == "Export") { Export(); return true; }
        if (name == "Gizmo") { m_GizmoEnabled = !m_GizmoEnabled; UpdateGizmo(); return true; }
        if (name == "MoveStep")
        {
            m_MoveStepIndex = (m_MoveStepIndex + 1) % 3;
            ButtonText("MoveStep",IOTL.F("MOVE_STEP",Clean(MoveStep() * 1000).ToString()));
            return true;
        }
        if (name == "AngleStep")
        {
            m_AngleStepIndex = (m_AngleStepIndex + 1) % 3;
            ButtonText("AngleStep",IOTL.F("ANGLE_STEP",AngleStep().ToString()));
            return true;
        }
        return false;
    }

    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        Widget widget = w;
        if (m_UpdatingUI) return false;
        if (widget == m_ItemsList)
        {
            int itemIndex = m_ItemsList.GetCurrentItem() - 1;
            if (itemIndex >= 0 && itemIndex < m_Items.Count()) SelectItem(m_Items[itemIndex]);
            else DeselectItem();
            return true;
        }
        if (widget == m_AnchorsList)
        {
            int anchorIndex = m_AnchorsList.GetCurrentItem() - 1;
            if (anchorIndex >= 0 && anchorIndex < m_Anchors.Count()) SetAnchor(m_Anchors[anchorIndex]);
            else SetAnchor(null);
            RefreshObjects();
            FocusAnchor();
            return true;
        }
        if (EditBoxWidget.Cast(widget)) { m_DirtyInputs = true; return true; }
        return false;
    }

    void HandleKey(int key)
    {
        if (GetGame().GetUIManager().GetMenu() != null) return;
        if (key == KeyCode.KC_F4)
        {
            if (m_PlayerMode) EnterEditor();
            else EnterPlayer();
            return;
        }
        if (m_PlayerMode) return;
        if (key == KeyCode.KC_F1) { SetPointer(!m_Pointer); return; }
        if (key == KeyCode.KC_F9) { Reset(); return; }
        if (key == KeyCode.KC_F10) { Export(); return; }
        if (key == KeyCode.KC_F11)
        {
            m_ShowDebug = !m_ShowDebug;
            m_Debug.Show(m_ShowDebug);
            ResizePanel();
            return;
        }
        if (!m_Item || EditBoxWidget.Cast(GetFocus())) return;
        if (key == KeyCode.KC_F7) { m_RotateMode = false; UpdateGizmo(); Status(IOTL.T("MOVE_KEYS")); return; }
        if (key == KeyCode.KC_F8) { m_RotateMode = true; UpdateGizmo(); Status(IOTL.T("ROTATE_KEYS")); return; }
        bool fine = KeyState(KeyCode.KC_LSHIFT) != 0 || KeyState(KeyCode.KC_RSHIFT) != 0;
        if (m_RotateMode)
        {
            if (key == KeyCode.KC_LEFT) Nudge(true, 1, -1, fine);
            if (key == KeyCode.KC_RIGHT) Nudge(true, 1, 1, fine);
            if (key == KeyCode.KC_UP) Nudge(true, 0, 1, fine);
            if (key == KeyCode.KC_DOWN) Nudge(true, 0, -1, fine);
            if (key == KeyCode.KC_PRIOR) Nudge(true, 2, 1, fine);
            if (key == KeyCode.KC_NEXT) Nudge(true, 2, -1, fine);
        }
        else
        {
            if (key == KeyCode.KC_LEFT) Nudge(false, 0, -1, fine);
            if (key == KeyCode.KC_RIGHT) Nudge(false, 0, 1, fine);
            if (key == KeyCode.KC_UP) Nudge(false, 2, 1, fine);
            if (key == KeyCode.KC_DOWN) Nudge(false, 2, -1, fine);
            if (key == KeyCode.KC_PRIOR) Nudge(false, 1, 1, fine);
            if (key == KeyCode.KC_NEXT) Nudge(false, 1, -1, fine);
        }
    }

    protected void SelfTestStart()
    {
        if (!SelfTestLocalization()) return;
        PlayerBase testPlayer = PlayerBase.Cast(GetGame().GetPlayer());
        EntityAI boots = testPlayer.FindAttachmentBySlotName("Feet");
        EntityAI shirt = testPlayer.FindAttachmentBySlotName("Body");
        EntityAI trousers = testPlayer.FindAttachmentBySlotName("Legs");
        if (!TestCheck(boots && boots.GetType() == "HikingBoots_Black" && !boots.IsRuined(), "test player starts with usable hiking boots attached to feet")) return;
        if (!TestCheck(shirt && shirt.GetType() == "TShirt_Grey" && trousers && trousers.GetType() == "CargoPants_Grey", "test player starts dressed with shirt and trousers")) return;
        if (!TestCheck(PlayerHudRoot() && !PlayerHudRoot().IsVisible() && m_PlayerHudHidden, "character HUD hidden in initial editor mode")) return;
        if (!TestCheck(!m_Anchor && !m_Item && m_Scenes.Count() == 0, "empty editor starts without predefined anchor")) return;
        if (!TestCheck(m_CreatedTray.Count() == 0 && m_CreatedTray.IsVisible(), "bottom created-item tray starts empty")) return;
        float stepX,stepY,stepWidth,stepHeight,rowX,rowY;
        Widget stepButton = m_Root.FindAnyWidget("MoveStep");
        stepButton.GetScreenPos(stepX,stepY);
        stepButton.GetScreenSize(stepWidth,stepHeight);
        m_Root.FindAnyWidget("PosPlus0").GetScreenPos(rowX,rowY);
        if (!TestCheck(stepY+stepHeight <= rowY+1, "right panel step control does not overlap coordinate row at UI scale")) return;
        if (!TestCheck(m_Browser.CatalogCount(false) > 0 && m_Browser.CatalogCount(true) > 0, "loaded anchor and inventory catalogs")) return;
        if (!TestCheck(m_Browser.ResolveClass("land_garage_row_small",false) == "Land_Garage_Row_Small" && m_Browser.ResolveClass("AK101",true) == "AK101", "catalog resolves buildings and weapons")) return;
        if (!SelfTestObjectTree()) return;
        if (!SelfTestWreckCategories()) return;
        if (!SelfTestVehicleTypes()) return;
        if (!SelfTestItemTree()) return;
        if (!TestCheck(SpawnSceneClass("Land_Wreck_hb01_aban1_blue",false) && SpawnSceneClass("HatchbackWheel",true), "runtime creation of wreck and wheel")) return;
        DeselectItem();
        RefreshObjects();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTest,1000,false);
    }

    protected bool SelfTestObjectTree()
    {
        m_Browser.SetMode(false);
        if (!SelfTestStaticObjectFilter()) return false;
        m_Browser.SetShowStaticObjects(true);
        if (!TestCheck(m_Browser.CatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(false), "object tree covers every loaded anchor class")) return false;
        if (!TestCheck(m_Browser.RowCount() == 6 && m_Browser.FirstClass() == "", "object root contains four maps and Other without Common")) return false;
        if (!TestCheck(IOTCatalogAsset.Category("\\DZ\\Structures\\Industrial\\Garages\\garage_row_small.p3d") == "INDUSTRIAL" && IOTCatalogAsset.Category("dz/structures_bliss/underground/prison.p3d") == "UNDERGROUND", "model paths determine normalized object categories")) return false;
        if (!TestCheck(IOTCatalogAsset.FamilyMask("dz/structures_sakhal/residential/house.p3d") == 4 && IOTCatalogAsset.FamilyMask("dz/structures_takistan/military/tower.p3d") == 8 && IOTCatalogAsset.FamilyMask("custom/map/house.p3d") == 0 && IOTCatalogAsset.Category("custom/map/house.p3d") == "UNCATEGORIZED", "unrecorded resource families have explicit map and unknown fallbacks")) return false;
        for (int i = 1; i <= 4; i++)
        {
            string mapKey = IOTSceneBrowser.MapKey(i);
            string mapName = IOTSceneBrowser.MapLabel(i);
            string categoryKey = mapKey+"/INDUSTRIAL";
            string leafKey = categoryKey+"/Land_Garage_Row_Small";
            if (!TestCheck(m_Browser.BranchCount(i) > 100 && m_Browser.RowIndex(mapKey) >= 0, "map branch is populated: "+mapName)) return false;
            PrintToRPT("[PROXY TREE TEST] "+mapName+"="+m_Browser.BranchCount(i).ToString());
            m_Browser.ActivateRow(mapKey);
            if (!TestCheck(m_Browser.RowIndex(categoryKey) >= 0 && m_Browser.FirstClass() == "", "map expands to categories without choosing a spawn class: "+mapName)) return false;
            m_Browser.ActivateRow(categoryKey);
            if (!TestCheck(m_Browser.RowIndex(leafKey) >= 0, "category expands to shared garage: "+mapName)) return false;
            m_Browser.ActivateRow(leafKey);
            if (!TestCheck(m_Browser.FirstClass() == "Land_Garage_Row_Small", "tree leaf selects the exact spawn classname: "+mapName)) return false;
            m_Browser.ActivateRow(categoryKey);
            if (!TestCheck(m_Browser.RowIndex(leafKey) < 0 && m_Browser.FirstClass() == "", "collapsing a category hides its objects and clears spawn selection: "+mapName)) return false;
        }
        m_Browser.Search("  LAND_GARAGE_ROW_SMALL  ");
        if (!TestCheck(m_Browser.MatchCount() == 1 && m_Browser.ShownCount() == 1 && m_Browser.RowCount() == 13 && m_Browser.FirstClass() == "Land_Garage_Row_Small", "global tree search reveals shared objects under all four maps")) return false;
        m_Browser.ActivateRow("map:2");
        if (!TestCheck(m_Browser.RowIndex("map:2/INDUSTRIAL/Land_Garage_Row_Small") < 0 && m_Browser.RowIndex("map:1/INDUSTRIAL/Land_Garage_Row_Small") >= 0, "search results can be collapsed independently")) return false;
        m_Browser.Search("Land_Underground_Storage_Prison");
        if (!TestCheck(m_Browser.MatchCount() == 1 && m_Browser.RowIndex("map:2/UNDERGROUND/Land_Underground_Storage_Prison") >= 0 && m_Browser.RowIndex("map:1") < 0, "map-specific search prunes unrelated branches")) return false;
        m_Browser.Search("no_such_proxy_tool_class");
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.FirstClass() == "" && m_Browser.RowCount() == 1, "empty tree search clears the previous spawn class")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow("map:1/INDUSTRIAL");
        m_Browser.SetMode(true);
        if (!TestCheck(m_Browser.RowIndex("objects") < 0 && m_Browser.RowIndex("items/GEAR") >= 0 && m_Browser.MatchCount() == m_Browser.CatalogCount(true) && m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "", "item tab opens an independent category tree")) return false;
        m_Browser.Search("  canistergasoline  ");
        if (!TestCheck(m_Browser.MatchCount() == 1 && m_Browser.FirstClass() == "CanisterGasoline", "item search still resolves inventory classes")) return false;
        m_Browser.SetMode(false);
        if (!TestCheck(m_Browser.RowIndex("map:1/INDUSTRIAL/Land_Garage_Row_Small") >= 0, "return to objects preserves expanded maps and categories")) return false;
        m_Browser.ActivateRow("objects");
        if (!TestCheck(m_Browser.RowCount() == 1 && m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "", "object root collapses without selecting a spawn class")) return false;
        m_Browser.ActivateRow("objects");
        if (!TestCheck(m_Browser.RowIndex("map:1/INDUSTRIAL/Land_Garage_Row_Small") >= 0, "object root restores previously open branches")) return false;
        PrintToRPT("[PROXY TREE TEST] Other="+m_Browser.BranchCount(5).ToString());
        m_Browser.SetShowStaticObjects(false);
        return true;
    }

    protected bool SelfTestWreckCategories()
    {
        int baseline = m_Browser.MatchCount();
        if (!TestCheck(IOTCatalogAsset.WreckSubcategory("dz/structures_takistan/wrecks/tracked/tank.p3d") == "VEHICLES" && IOTCatalogAsset.WreckSubcategory("dz/structures_sakhal/wrecks/Static_Mi8_Civilian.p3d") == "AIRCRAFT" && IOTCatalogAsset.WreckSubcategory("dz/structures/wrecks/unknown.p3d") == "OTHER", "wreck models classify tracked vehicles, Sakhal aircraft and unknown wrecks")) return false;
        array<string> examples = {"Land_Wreck_hb01_aban1_blue","Land_Wreck_C130J","Land_Boat_Small1","Land_Train_742_Blue"};
        array<string> subcategories = {"VEHICLES","AIRCRAFT","SHIPS","TRAINS"};
        for (int i = 0; i < examples.Count(); i++)
        {
            m_Browser.Search(examples[i]);
            string key = "map:1/WRECKS/"+subcategories[i]+"/"+examples[i];
            if (subcategories[i] == "VEHICLES") key = "map:1/WRECKS/VEHICLES/OFFROAD/"+examples[i];
            if (!TestCheck(m_Browser.ActivateRow(key) && m_Browser.FirstClass() == examples[i], "wreck search reveals and selects its nested subcategory: "+subcategories[i])) return false;
        }
        m_Browser.Search("Land_Submarine_Back");
        if (!TestCheck(m_Browser.ActivateRow("map:3/WRECKS/SHIPS/Land_Submarine_Back") && m_Browser.FirstClass() == "Land_Submarine_Back", "Sakhal submarine parts appear under ships and boats")) return false;
        m_Browser.Search("Land_Wreck_hb01_aban1_blue");
        m_Browser.ActivateRow("map:1/WRECKS/VEHICLES");
        if (!TestCheck(m_Browser.RowIndex("map:1/WRECKS/VEHICLES/OFFROAD/Land_Wreck_hb01_aban1_blue") < 0 && m_Browser.RowIndex("map:1/WRECKS") >= 0 && m_Browser.FirstClass() == "", "wreck subcategory collapses independently and clears its spawn selection")) return false;
        m_Browser.SetShowStaticObjects(true);
        m_Browser.Search("StaticObj_Wreck_Mi8");
        if (!TestCheck(m_Browser.RowIndex("map:1/WRECKS/AIRCRAFT/StaticObj_Wreck_Mi8") >= 0, "StaticObj wrecks use the same aircraft subcategory")) return false;
        m_Browser.SetShowStaticObjects(false);
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.RowIndex("map:1/WRECKS/AIRCRAFT") < 0, "StaticObj filter removes empty wreck subcategories")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.CatalogCovered() && m_Browser.MatchCount() == baseline, "wreck nesting preserves full catalog coverage and filtered totals")) return false;
        return true;
    }

    protected bool SelfTestVehicleTypes()
    {
        int baseline = m_Browser.MatchCount();
        array<string> examples = {"Land_wreck_truck01_aban1_blue","Land_Wreck_sed01_aban1_black","Land_Wreck_hb01_aban1_blue","Land_Wreck_hb02_aban1_blue"};
        array<string> types = {"TRUCK","SEDAN","OFFROAD","HATCHBACK"};
        for (int i = 0; i < examples.Count(); i++)
        {
            m_Browser.Search(examples[i]);
            string key = "map:1/WRECKS/VEHICLES/"+types[i]+"/"+examples[i];
            if (!TestCheck(m_Browser.ActivateRow(key) && m_Browser.FirstClass() == examples[i], "vehicle type search selects the exact wreck: "+types[i])) return false;
        }
        if (!TestCheck(IOTCatalogAsset.VehicleSubcategory("dz/structures/wrecks/vehicles/Wreck_Trailer_Flat.p3d") == "OTHER" && IOTCatalogAsset.VehicleSubcategory("dz/structures_takistan/wrecks/tracked/Wreck_T62_Hull_TK.p3d") == "OTHER", "unclassified trailers and tracked vehicles remain in Other ground vehicles")) return false;
        m_Browser.ActivateRow("map:1/WRECKS/VEHICLES/HATCHBACK");
        if (!TestCheck(m_Browser.RowIndex("map:1/WRECKS/VEHICLES/HATCHBACK/Land_Wreck_hb02_aban1_blue") < 0 && m_Browser.RowIndex("map:1/WRECKS/VEHICLES") >= 0 && m_Browser.FirstClass() == "", "vehicle type folders collapse without selecting a spawn class")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.CatalogCovered() && m_Browser.MatchCount() == baseline && !m_Browser.ShowStaticObjects(), "vehicle type nesting preserves catalog totals and the StaticObj default")) return false;
        return true;
    }

    protected bool SelfTestItemTree()
    {
        m_Browser.SetMode(true);
        if (!TestCheck(m_Browser.ItemCatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(true) && !m_Browser.StaticControlVisible(), "item tree covers every loaded inventory class exactly once")) return false;
        array<string> examples = {"AK101","Ammo_556x45","Mag_AK101_30Rnd","AmmoBox_556x45_20Rnd","ReflexOptic","CargoPants_Grey","BakedBeansCan","WaterBottle","Hammer","CanisterGasoline","HatchbackWheel","HatchbackDoors_Driver"};
        array<string> groups = {"WEAPONS/FIREARMS","AMMO/ROUNDS","AMMO/MAGAZINES","AMMO/BOXES","ATTACHMENTS/OPTICS","CLOTHING/PANTS","FOOD_DRINKS/FOOD","FOOD_DRINKS/DRINKS","GEAR/TOOLS","VEHICLE_PARTS/COMPONENTS","VEHICLE_PARTS/WHEELS","VEHICLE_PARTS/BODY"};
        for (int i = 0; i < examples.Count(); i++)
        {
            m_Browser.Search(examples[i]);
            string key = "items/"+groups[i]+"/"+examples[i];
            if (!TestCheck(m_Browser.ActivateRow(key) && m_Browser.FirstClass() == examples[i], "item search reveals its category and selects exact classname: "+examples[i])) return false;
        }
        m_Browser.ActivateRow("items/VEHICLE_PARTS/BODY");
        if (!TestCheck(m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "" && m_Browser.RowIndex("items/VEHICLE_PARTS") >= 0, "item search folders collapse without selecting a spawn class")) return false;
        m_Browser.Search("a");
        if (!TestCheck(m_Browser.MatchCount() > 100 && m_Browser.ShownCount() == m_Browser.MatchCount(), "item search displays every matching class without a 100-result cap")) return false;
        m_Browser.Search("no_such_proxy_tool_item");
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.RowCount() == 1 && m_Browser.FirstClass() == "", "empty item search clears the previous spawn classname")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow("items/GEAR");
        m_Browser.ActivateRow("items/GEAR/TOOLS");
        if (!TestCheck(m_Browser.RowIndex("items/GEAR/TOOLS/Hammer") >= 0 && m_Browser.FirstClass() == "", "item folders expand without choosing a spawn classname")) return false;
        m_Browser.SetMode(false);
        m_Browser.SetMode(true);
        if (!TestCheck(m_Browser.RowIndex("items/GEAR/TOOLS/Hammer") >= 0 && m_Browser.RowIndex("objects") < 0, "return to items preserves its expanded categories")) return false;
        m_Browser.Search("  hAmMeR  ");
        if (!TestCheck(m_Browser.ActivateRow("items/GEAR/TOOLS/Hammer") && m_Browser.FirstClass() == "Hammer" && m_Browser.RowIndex("items/CLOTHING") < 0, "item search ignores case and spaces and hides unrelated categories")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow("items");
        if (!TestCheck(m_Browser.RowCount() == 1 && m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "", "item root collapses without selecting a spawn class")) return false;
        m_Browser.ActivateRow("items");
        if (!TestCheck(m_Browser.RowIndex("items/GEAR/TOOLS/Hammer") >= 0, "item root restores previously expanded categories")) return false;
        if (!TestCheck(IOTItemCatalog.Group("Hammer","custom/items/tool.p3d","CfgVehicles") == "OTHER" && IOTItemCatalog.Group("AK101","custom/weapons/rifle.p3d","CfgWeapons") == "WEAPONS/OTHER" && IOTItemCatalog.Group("HatchbackWheel","custom/items/wheel.p3d","CfgVehicles") == "VEHICLE_PARTS/WHEELS", "unknown item resources retain Other fallbacks and inherited wheel classification")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestStaticObjectFilter()
    {
        int hiddenCount = m_Browser.MatchCount();
        int hiddenBranch = m_Browser.BranchCount(1);
        if (!TestCheck(!m_Browser.ShowStaticObjects() && m_Browser.StaticControlVisible() && hiddenCount > 0 && hiddenCount < m_Browser.CatalogCount(false), "StaticObj checkbox starts off and reduces object counts")) return false;
        m_Browser.Search("  STATICOBJ_FURNITURE_MATRESS_WHITE  ");
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "", "StaticObj search is empty while checkbox is off")) return false;
        m_Browser.SetShowStaticObjects(true);
        if (!TestCheck(m_Browser.MatchCount() > 0 && m_Browser.RowIndex("map:1/FURNITURE/StaticObj_Furniture_matress_white") >= 0, "enabling StaticObj reveals matching objects in their categories")) return false;
        m_Browser.ActivateRow("map:1/FURNITURE/StaticObj_Furniture_matress_white");
        m_Browser.SetShowStaticObjects(false);
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.FirstClass() == "" && m_Browser.RowIndex("map:1/FURNITURE/StaticObj_Furniture_matress_white") < 0, "disabling StaticObj clears a hidden selected spawn classname")) return false;
        m_Browser.Search("");
        m_Browser.SetShowStaticObjects(true);
        if (!TestCheck(m_Browser.MatchCount() == m_Browser.CatalogCount(false) && m_Browser.BranchCount(1) > hiddenBranch, "enabling StaticObj restores full root and branch counts")) return false;
        m_Browser.SetMode(true);
        if (!TestCheck(!m_Browser.StaticControlVisible() && m_Browser.MatchCount() == m_Browser.CatalogCount(true), "item catalog ignores and hides the StaticObj checkbox")) return false;
        m_Browser.SetMode(false);
        if (!TestCheck(m_Browser.ShowStaticObjects() && m_Browser.StaticControlVisible(), "StaticObj checkbox state survives tab switching")) return false;
        m_Browser.SetShowStaticObjects(false);
        if (!TestCheck(m_Browser.MatchCount() == hiddenCount && m_Browser.BranchCount(1) == hiddenBranch, "disabling StaticObj restores filtered counts")) return false;
        PrintToRPT("[PROXY STATIC FILTER TEST] Default="+hiddenCount.ToString()+" all="+m_Browser.CatalogCount(false).ToString());
        return true;
    }

    protected bool SelfTestLocalization()
    {
        array<string> keys = IOTL.Keys();
        foreach (string key : keys)
        {
            string translated = Widget.TranslateString("#STR_IOT_"+key);
            if (translated == "" || translated.IndexOf("STR_IOT_") >= 0)
            {
                TestCheck(false,"missing native localization key: "+key);
                return false;
            }
        }
        if (!TestCheck(keys.Count() >= 60,"all native localization keys resolve")) return false;
        string expected;
        string locale = IOTL.T("LOCALE");
        if (GetGame().CommandlineGetParam("proxyToolExpectedLanguage",expected))
        {
            string expectedLocale = "en";
            if (expected == "Russian") expectedLocale = "ru";
            if (!TestCheck(locale == expectedLocale,"client language selects the expected translation column")) return false;
        }
        TextWidget title = TextWidget.Cast(m_Root.FindAnyWidget("Title"));
        int textWidth,textHeight;
        float titleWidth,titleHeight;
        title.GetTextSize(textWidth,textHeight);
        title.GetScreenSize(titleWidth,titleHeight);
        if (!TestCheck(textWidth > 0 && textWidth <= titleWidth+1,"localized layout title renders within its bounds")) return false;
        string count = IOTL.F("FOUND","12","3");
        if (!TestCheck(count.IndexOf("%1") < 0 && count.IndexOf("%2") < 0 && count.IndexOf("12") >= 0 && count.IndexOf("3") >= 0,"localized counter substitutes both format arguments")) return false;
        PrintToRPT("[PROXY LOCALE TEST] locale="+locale+" keys="+keys.Count().ToString()+" title="+IOTL.T("TITLE")+" counter="+count+" create="+IOTL.T("CREATE_ANCHOR"));
        return true;
    }

    protected void SelfTest()
    {
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!TestCheck(camera && camera.IsActive() && !m_Item && !m_Editing && GetGizmoApi().GetCount() == 0, "initial camera, no selection")) return;
        if (!TestCheck(m_SpeedRoot && m_SpeedValue && !m_SpeedRoot.IsVisible(), "speed HUD loaded, hidden with cursor")) return;
        vector cameraPose[4];
        camera.GetTransform(cameraPose);
        vector cameraBefore = camera.GetPosition();
        SetPointer(false);
        ChangeCameraSpeed(1);
        if (!TestCheck(m_SpeedRoot.IsVisible() && CameraMultiplierText() == "1.3x" && vector.Distance(camera.GetPosition(),cameraBefore) < 0.0001, "multiplier appears immediately while stationary")) return;
        MoveFlightCamera(0.2,1,0,0,0,0,1);
        if (!TestCheck(Math.AbsFloat(vector.Distance(camera.GetPosition(),cameraBefore) - 1.25) < 0.002, "camera travel follows displayed multiplier")) return;
        ChangeCameraSpeed(1);
        if (!TestCheck(CameraMultiplierText() == "1.6x", "one-decimal multiplier display")) return;
        ChangeCameraSpeed(-2);
        if (!TestCheck(Math.AbsFloat(m_CameraMultiplier - 1) < 0.00001, "wheel changes reverse to base coefficient")) return;
        ChangeCameraSpeed(100);
        if (!TestCheck(m_CameraMultiplier == 16 && CameraMultiplierText() == "16x", "maximum coefficient and integer label")) return;
        ChangeCameraSpeed(-1);
        if (!TestCheck(CameraMultiplierText() == "12.8x", "values above 12 retain decimal")) return;
        ChangeCameraSpeed(-100);
        if (!TestCheck(m_CameraMultiplier == 0.1 && CameraMultiplierText() == "0.1x", "minimum coefficient and decimal label")) return;
        m_CameraMultiplier = 1;
        camera.SetTransform(cameraPose);
        SetPointer(true);
        if (!TestCheck(m_ActiveScene.Items.Count() == 1, "one runtime-created authoring wheel")) return;
        ItemBase wheel = m_ActiveScene.Items[0];
        if (!TestCheck(wheel && !wheel.GetHierarchyParent(), "runtime wheel is a loose inventory item")) return;

        // Test the actual screen unprojection and physics ray against the mesh.
        // Sample the bounds because the wheel's central hole may not be hittable.
        vector bounds[2];
        wheel.ClippingInfo(bounds);
        bool hitWheel;
        vector screen;
        for (int ix = 0; ix < 5 && !hitWheel; ix++)
        {
            for (int iy = 0; iy < 5 && !hitWheel; iy++)
            {
                for (int iz = 0; iz < 5 && !hitWheel; iz++)
                {
                    vector localPoint;
                    localPoint[0] = bounds[0][0] + (bounds[1][0] - bounds[0][0]) * (0.1 + ix * 0.2);
                    localPoint[1] = bounds[0][1] + (bounds[1][1] - bounds[0][1]) * (0.1 + iy * 0.2);
                    localPoint[2] = bounds[0][2] + (bounds[1][2] - bounds[0][2]) * (0.1 + iz * 0.2);
                    screen = GetGame().GetScreenPos(wheel.ModelToWorld(localPoint));
                    if (PointerObject(screen) == wheel) hitWheel = true;
                }
            }
        }
        if (!TestCheck(hitWheel, "cursor ray hits wheel mesh")) return;
        PickPoint(screen);
        if (!TestCheck(m_Item == wheel && m_Editing && GetGizmoApi().GetCount() == 1, "cursor selection enables native gizmo")) return;
        vector baseline = ProxyPosition();
        vector angles = ProxyAngles();
        Widget plus = m_Root.FindAnyWidget("PosPlus0");
        OnMouseButtonDown(plus, 0, 0, 0);
        OnMouseButtonUp(plus, 0, 0, 0);
        OnClick(plus, 0, 0, 0);
        vector nudged = ProxyPosition();
        if (!TestCheck(Math.AbsFloat(nudged[0] - baseline[0] - 0.01) < 0.0002, "position control")) return;
        SetProxyPose(baseline, "10 20 30");
        if (!TestCheck(vector.Distance(ProxyAngles(), "10 20 30") < 0.001, "combined rotation")) return;
        SetProxyPose(baseline, angles);

        vector blank = Vector(20,20,0);
        if (!TestCheck(ItemBase.Cast(PointerObject(blank)) == null, "empty screen sample")) return;
        PickPoint(blank);
        vector beforeNudge = wheel.GetPosition();
        Nudge(false,0,1);
        if (!TestCheck(!m_Item && !m_Editing && GetGizmoApi().GetCount() == 0 && vector.Distance(beforeNudge,wheel.GetPosition()) < 0.0001, "empty click clears selection and blocks movement")) return;
        SelectItem(wheel);
        EnterPlayer();
        if (!TestCheck(m_PlayerMode && !camera.IsActive() && !m_Item && GetGizmoApi().GetCount() == 0 && !m_Root.IsVisible() && !m_Browser.IsVisible() && !m_CreatedTray.IsVisible() && GetGame().GetInput().HasGameFocus(), "player mode restores camera and input and hides all panels")) return;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestPlayer,250,false,wheel,baseline,angles);
    }

    protected void SelfTestPlayer(ItemBase wheel, vector baseline, vector angles)
    {
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        PrintToRPT("[PROXY MODES TEST] Player disabled=" + player.GetIsSimulationDisabled().ToString() + " wheel disabled=" + wheel.GetIsSimulationDisabled().ToString() + " canHands=" + player.GetHumanInventory().CanAddEntityInHands(wheel).ToString());
        if (!TestCheck(!player.GetIsSimulationDisabled(), "player simulation restored")) return;
        if (!TestCheck(PlayerHudRoot() && PlayerHudRoot().IsVisible() == m_PlayerHudWasVisible && !m_PlayerHudHidden, "player mode restores previous character HUD visibility")) return;
        if (!TestCheck(player.GetHumanInventory().CanAddEntityInHands(wheel), "take in hands permitted")) return;
        vector placedPosition = wheel.GetPosition();
        vector placedOrientation = wheel.GetOrientation();
        EnterEditor();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestEditor,250,false,wheel,placedPosition,placedOrientation);
    }

    protected void SelfTestEditor(ItemBase wheel, vector placedPosition, vector placedOrientation)
    {
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!TestCheck(!m_PlayerMode && camera.IsActive() && !m_Item && GetGizmoApi().GetCount() == 0 && m_Root.IsVisible() && m_Browser.IsVisible() && m_CreatedTray.IsVisible() && player.GetIsSimulationDisabled(), "return to editor without selection and restore all panels")) return;
        if (!TestCheck(PlayerHudRoot() && !PlayerHudRoot().IsVisible() && m_PlayerHudHidden, "return to editor hides character HUD again")) return;
        SelectItem(wheel);
        if (!TestCheck(vector.Distance(wheel.GetPosition(),placedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),placedOrientation) < 0.001, "editor return preserves current placement")) return;
        bool exported = Export();
        if (!TestCheck(exported, "context XML export")) return;
        Object firstAnchor = m_Anchor;
        vector firstPosition = wheel.GetPosition();
        if (!TestCheck(SpawnSceneClass("Land_Garage_Row_Small",false), "second anchor created at runtime")) return;
        // Deliberately overlap the anchors to exercise the separation calculation.
        m_Anchor.SetPosition(firstAnchor.GetPosition());
        SeparateAnchor(m_Anchor);
        vector firstBounds[2];
        vector secondBounds[2];
        firstAnchor.ClippingInfo(firstBounds);
        m_Anchor.ClippingInfo(secondBounds);
        vector firstMin = firstAnchor.GetPosition()+firstBounds[0];
        vector firstMax = firstAnchor.GetPosition()+firstBounds[1];
        vector secondMin = m_Anchor.GetPosition()+secondBounds[0];
        vector secondMax = m_Anchor.GetPosition()+secondBounds[1];
        bool separatedX = secondMin[0] >= firstMax[0]+7.99 || firstMin[0] >= secondMax[0]+7.99;
        bool separatedZ = secondMin[2] >= firstMax[2]+7.99 || firstMin[2] >= secondMax[2]+7.99;
        if (!TestCheck(separatedX || separatedZ, "overlapping anchors separated with eight metre margin")) return;
        FocusAnchor();
        if (!TestCheck(SpawnSceneClass("Hammer",true) && SpawnSceneClass("CanisterGasoline",true), "different inventory items created at runtime")) return;
        if (!TestCheck(m_Scenes.Count() == 2 && m_ActiveScene.Items.Count() == 2 && m_Anchor != firstAnchor, "separate anchor sessions and item ownership")) return;
        if (!TestCheck(ExportAnchor(), "multi-item anchor XML export")) return;
        SelectItem(wheel);
        RefreshObjects();
        if (!TestCheck(m_Anchor == firstAnchor && m_ActiveScene.Items.Count() == 1 && vector.Distance(wheel.GetPosition(),firstPosition) < 0.001, "switching back preserves first anchor placement")) return;
        if (!TestCheck(Export(), "first anchor export retained independently")) return;
        SelfTestCreatedTray(firstAnchor);
    }

    protected void SelfTestCreatedTray(Object firstAnchor)
    {
        if (!TestCheck(m_CreatedTray.Count() == 3, "tray contains items across anchors")) return;
        if (!TestCheck(TextWidget.Cast(m_CreatedTray.Root().FindAnyWidget("CreatedName0")).GetColor() == ARGB(255,30,115,175), "tray marks world selection")) return;
        // More than one page, including three identical classnames.
        for (int extra = 0; extra < 3; extra++)
            if (!TestCheck(SpawnSceneClass("Hammer",true), "create duplicate-class item for tray pagination")) return;
        ItemBase lastItem = m_Item;
        if (!TestCheck(m_CreatedTray.Count() == 6 && m_CreatedTray.Page() == 1, "new item reveals second tray page")) return;
        m_CreatedTray.OnClick(m_CreatedTray.Root().FindAnyWidget("CreatedPrev"),0,0,0);
        if (!TestCheck(m_CreatedTray.Page() == 0 && m_Item == lastItem, "tray pagination preserves world selection")) return;
        m_CreatedTray.OnClick(m_CreatedTray.Root().FindAnyWidget("CreatedItem1"),0,0,0);
        if (!TestCheck(m_Item == m_CreatedItems[1] && m_Anchor != firstAnchor && m_Editing && GetGizmoApi().GetCount() == 1 && TextWidget.Cast(m_CreatedTray.Root().FindAnyWidget("CreatedName1")).GetColor() == ARGB(255,30,115,175), "tray click selects exact item, switches anchor and enables native gizmo")) return;
        m_CreatedTray.OnClick(m_CreatedTray.Root().FindAnyWidget("CreatedNext"),0,0,0);
        m_CreatedTray.OnClick(m_CreatedTray.Root().FindAnyWidget("CreatedItem1"),0,0,0);
        if (!TestCheck(m_Item == lastItem && m_Anchor == firstAnchor, "second-page click distinguishes identical items")) return;
        float trayX,trayY,trayWidth,trayHeight;
        m_CreatedTray.Root().GetScreenPos(trayX,trayY);
        m_CreatedTray.Root().GetScreenSize(trayWidth,trayHeight);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        PrintToRPT("[PROXY TRAY TEST] Screen="+screenWidth.ToString()+"x"+screenHeight.ToString()+" tray="+Vector(trayX,trayY,0).ToString(false)+" size="+Vector(trayWidth,trayHeight,0).ToString(false));
        if (!TestCheck(Math.AbsFloat(trayX+trayWidth*0.5 - screenWidth*0.5) < 2 && trayY > screenHeight*0.5 && trayY+trayHeight <= screenHeight && PanelPoint(Vector(trayX+20,trayY+20,0)), "tray stays bottom centered and blocks world clicks")) return;
        DeselectItem();
        if (!TestCheck(TextWidget.Cast(m_CreatedTray.Root().FindAnyWidget("CreatedName1")).GetColor() == ARGB(255,255,255,255) && GetGizmoApi().GetCount() == 0, "world deselection clears tray marker and gizmo")) return;
        PrintToRPT("[PROXY TOOL V2 SELFTEST] PASS: bottom created-item tray, exact click selection, duplicate items, pagination, anchor switching, XML and editor regressions.");
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(Tick);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().RequestExit, 1500, false, 0);
    }

    protected bool TestCheck(bool passed, string description)
    {
        if (passed)
        {
            PrintToRPT("[PROXY MODES TEST] OK: " + description);
            return true;
        }
        PrintToRPT("[PROXY TOOL V2 SELFTEST] FAIL: " + description);
        GetGame().RequestExit(1);
        return false;
    }

    void Tick()
    {
        if (m_CreatedTray && !m_PlayerMode)
        {
            m_CreatedTray.Position();
            if (GetGame().GetTime() >= m_TrayRefreshTime)
            {
                RefreshCreatedItems();
                m_TrayRefreshTime = GetGame().GetTime() + 500;
            }
        }
        if (!m_Booted)
        {
            m_Attempts++;
            if (m_Attempts % 10 == 0 && Boot())
            {
                m_Booted = true;
                if (m_SelfTest) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestStart, 250, false);
            }
            if (m_SelfTest && m_Attempts > 1200) { PrintToRPT("[PROXY TOOL V2 SELFTEST] FAIL: editor did not start."); GetGame().RequestExit(1); }
        }
        if (m_Item && m_Item.GetHierarchyParent())
        {
            DeselectItem();
            Status(IOTL.T("ITEM_PICKED_UP"));
            return;
        }
        if (m_Item && m_Anchor)
        {
            if (!m_DirtyInputs && (vector.Distance(m_LastPos, ProxyPosition()) > 0.000001 || vector.Distance(m_LastAngles, ProxyAngles()) > 0.000001)) SyncFields();
            if (m_ShowDebug) m_Debug.SetText(IOTL.F("WORLD_POSITION",m_Item.GetPosition().ToString(false))+"\n"+IOTL.F("WORLD_ORIENTATION",m_Item.GetOrientation().ToString(false)));
        }
        if (m_HeldButton && (GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK))
        {
            int now = GetGame().GetTime();
            if (now - m_HoldStart > 350 && now - m_LastRepeat >= 80)
            {
                NudgeButton(m_HeldButton);
                m_LastRepeat = now;
            }
        }
        else m_HeldButton = null;
    }
}

ref IOTProxyTool g_IOTProxyTool;

void IOT_StartProxyTool()
{
    if (!GetGame().IsMultiplayer()) g_IOTProxyTool = new IOTProxyTool;
}

class IOTProxyMission : MissionGameplay
{
    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        if (g_IOTProxyTool) g_IOTProxyTool.FrameUpdate(timeslice);
    }

    override void OnMouseButtonPress(int button)
    {
        super.OnMouseButtonPress(button);
        if (g_IOTProxyTool) g_IOTProxyTool.MousePress(button);
    }

    override void OnMouseButtonRelease(int button)
    {
        super.OnMouseButtonRelease(button);
        if (g_IOTProxyTool) g_IOTProxyTool.MouseRelease(button);
    }

    override void OnKeyPress(int key)
    {
        super.OnKeyPress(key);
        if (g_IOTProxyTool) g_IOTProxyTool.HandleKey(key);
    }
}
