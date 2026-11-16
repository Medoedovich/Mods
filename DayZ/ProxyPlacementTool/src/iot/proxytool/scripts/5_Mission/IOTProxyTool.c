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
        array<string> keys = {"LOCALE","TITLE","ITEM","ANCHOR","MOVE","ROTATE","POSITION","MOVE_STEP_DEFAULT","ROTATION","ANGLE_STEP_DEFAULT","APPLY","CHARACTER","RESET","GROUND","SELECT_HINT","HELP","CREATE_TITLE","BUILDINGS","ITEMS","ITEM_GROUP_WEAPONS","ITEM_GROUP_WEAPONS_FIREARMS","ITEM_GROUP_WEAPONS_PISTOLS","ITEM_GROUP_WEAPONS_SHOTGUNS","ITEM_GROUP_WEAPONS_ARCHERY","ITEM_GROUP_WEAPONS_MELEE","ITEM_GROUP_WEAPONS_EXPLOSIVES","ITEM_GROUP_WEAPONS_LAUNCHERS","ITEM_GROUP_WEAPONS_OTHER","ITEM_GROUP_AMMO","ITEM_GROUP_AMMO_ROUNDS","ITEM_GROUP_AMMO_MAGAZINES","ITEM_GROUP_AMMO_BOXES","ITEM_GROUP_ATTACHMENTS","ITEM_GROUP_ATTACHMENTS_OPTICS","ITEM_GROUP_ATTACHMENTS_MUZZLE","ITEM_GROUP_ATTACHMENTS_LIGHT","ITEM_GROUP_ATTACHMENTS_SUPPORT","ITEM_GROUP_ATTACHMENTS_OTHER","ITEM_GROUP_CLOTHING","ITEM_GROUP_CLOTHING_BACKPACKS","ITEM_GROUP_CLOTHING_VESTS","ITEM_GROUP_CLOTHING_TOPS","ITEM_GROUP_CLOTHING_PANTS","ITEM_GROUP_CLOTHING_SHOES","ITEM_GROUP_CLOTHING_HEADGEAR","ITEM_GROUP_CLOTHING_MASKS","ITEM_GROUP_CLOTHING_GLOVES","ITEM_GROUP_CLOTHING_GLASSES","ITEM_GROUP_CLOTHING_BELTS","ITEM_GROUP_CLOTHING_OTHER","ITEM_GROUP_FOOD_DRINKS","ITEM_GROUP_FOOD_DRINKS_FOOD","ITEM_GROUP_FOOD_DRINKS_DRINKS","ITEM_GROUP_GEAR","ITEM_GROUP_GEAR_TOOLS","ITEM_GROUP_GEAR_CONTAINERS","ITEM_GROUP_GEAR_CAMPING","ITEM_GROUP_GEAR_COOKING","ITEM_GROUP_GEAR_CRAFTING","ITEM_GROUP_GEAR_CULTIVATION","ITEM_GROUP_GEAR_MEDICAL","ITEM_GROUP_GEAR_NAVIGATION","ITEM_GROUP_GEAR_RADIO","ITEM_GROUP_GEAR_OPTICS","ITEM_GROUP_GEAR_TRAPS","ITEM_GROUP_GEAR_BOOKS","ITEM_GROUP_GEAR_CONSUMABLES","ITEM_GROUP_GEAR_OTHER","ITEM_GROUP_VEHICLE_PARTS","ITEM_GROUP_VEHICLE_PARTS_WHEELS","ITEM_GROUP_VEHICLE_PARTS_BODY","ITEM_GROUP_VEHICLE_PARTS_COMPONENTS","ITEM_GROUP_VEHICLE_PARTS_OTHER","ITEM_GROUP_OTHER","SHOW_STATICOBJ","OTHER_OBJECTS","OBJECT_TREE_HINT","CATEGORY_RESIDENTIAL","RESIDENTIAL_SUB_SHEDS","RESIDENTIAL_SUB_OFFICE","RESIDENTIAL_SUB_MISC","RESIDENTIAL_SUB_HOUSE","RESIDENTIAL_SUB_CITY","RESIDENTIAL_SUB_TENEMENTS","RESIDENTIAL_SUB_STORES","RESIDENTIAL_SUB_MEDICAL","RESIDENTIAL_SUB_POLICE","RESIDENTIAL_SUB_SCHOOLS","RESIDENTIAL_SUB_FIREDEP","RESIDENTIAL_SUB_BUS","RESIDENTIAL_SUB_SLUMS","RESIDENTIAL_SUB_PLATFORMS","RESIDENTIAL_SUB_TERRACES","RESIDENTIAL_SUB_OTHER","CATEGORY_INDUSTRIAL","CATEGORY_MILITARY","CATEGORY_UNDERGROUND","CATEGORY_WRECKS","WRECK_SUB_VEHICLES","WRECK_SUB_AIRCRAFT","WRECK_SUB_SHIPS","WRECK_SUB_TRAINS","WRECK_SUB_OTHER","VEHICLE_TYPE_TRUCK","VEHICLE_TYPE_SEDAN","VEHICLE_TYPE_OFFROAD","VEHICLE_TYPE_HATCHBACK","VEHICLE_TYPE_OTHER","CATEGORY_FURNITURE","CATEGORY_ROADS","CATEGORY_RAIL","CATEGORY_WALLS","CATEGORY_SIGNS","CATEGORY_RUINS","CATEGORY_SPECIFIC","CATEGORY_PROPS","CATEGORY_BUILDING_PARTS","CATEGORY_VEGETATION","CATEGORY_ROCKS","CATEGORY_WATER","CATEGORY_TERRAIN","CATEGORY_UNCATEGORIZED","SEARCH","CLASSNAME","CREATE_ANCHOR","CREATE_ITEM","FOCUS_ANCHOR","EXPORT_ANCHOR","ITEM_MODE_HINT","ANCHOR_MODE_HINT","FOUND","UNKNOWN_CLASS","ANCHOR_REQUIRED","SPAWN_FAILED","NOT_INVENTORY_ITEM","NOT_ANCHOR","CREATED","ANCHOR_TRANSFORM_LIMIT","GIZMO_HINT","DESELECT_HINT","NO_ITEM","NO_ANCHOR","START_HINT","GIZMO_ON","GIZMO_OFF","INVALID_NUMBER","NUMBER_LIMIT","POSE_APPLIED","GROUNDED","POSE_RESET","ANCHOR_XML_FAILED","ANCHOR_XML_SAVED","XML_FAILED","MOVE_STEP","ANGLE_STEP","MOVE_KEYS","ROTATE_KEYS","MOVE_KEYS_HEIGHT","ROTATE_KEYS_YAW","FINE_KEYS","ITEM_PICKED_UP","WORLD_POSITION","WORLD_ORIENTATION","TRAY_TITLE","TRAY_TITLE_EMPTY","TRAY_EMPTY","TRAY_OWNER","TRAY_SELECTED","TRAY_INVENTORY","CHARACTER_HINT","WORLD_FLIGHT_HINT","ITEM_DRAG_HINT","ITEM_DROP_READY","ITEM_DROP_INVALID","ITEM_DROP_CANCELLED","ITEM_PREVIEW_SELECT","ITEM_PREVIEW_LOADING","ITEM_PREVIEW_UNAVAILABLE","SCENE_OBJECTS_TITLE","SCENE_OBJECTS_TITLE_EMPTY","SCENE_OBJECTS_EMPTY","SCENE_ANCHOR_ROW","SCENE_CHARACTER","SCENE_OBJECT","POSITION_WORLD","SCENE_MOVE_HINT","WORLD_NUMBER_LIMIT","POSITION_SHORT","ROTATION_SHORT","FINE_SETTINGS","COORDINATES_RELATIVE","COORDINATES_WORLD","PROPERTIES_ANCHOR","XML_SELECTION","CAMERA_FLIGHT","CAMERA_CURSOR","SEARCH_ITEMS_PLACEHOLDER","ERROR_TITLE","ANCHOR_DROP_READY","ANCHOR_DROP_REPLACE","REPLACE_TITLE","REPLACE_NAMES","REPLACE_WARNING","REPLACE_CONFIRM","REPLACE_CANCEL","REPLACE_SCENE_CHANGED","REPLACE_NEW"};
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
    protected TextWidget m_SearchPlaceholder;
    protected TextListboxWidget m_Results;
    protected ScrollWidget m_ItemScroll;
    protected Widget m_ItemContent;
    protected ref array<Widget> m_ItemRows = new array<Widget>;
    protected MultilineTextWidget m_Status;
    protected CheckBoxWidget m_ShowStatic;
    protected Widget m_HoverRoot;
    protected ItemPreviewWidget m_HoverView;
    protected MultilineTextWidget m_HoverClass;
    protected TextWidget m_HoverEmpty;
    protected EntityAI m_HoverEntity;
    protected string m_HoverRequested;
    protected string m_HoverApplied;
    protected int m_HoverDue;
    protected int m_HoverRow = -1;
    protected bool m_HoverBoundVisible;
    protected float m_PanelScale = 1;
    protected float m_CatalogHeight;
    protected bool m_ShowStaticObjects;
    protected int m_MatchCount;
    protected bool m_ItemsMode;
    protected bool m_Updating;
    protected string m_LastQuery;
    protected string m_SelectedKey;
    protected string m_SelectedClass;
    protected ref map<string,int> m_MapMasks = new map<string,int>;
    protected ref map<string,ref IOTCatalogGroup> m_Groups = new map<string,ref IOTCatalogGroup>;
    protected ref map<string,ref IOTCatalogGroup> m_ItemGroups = new map<string,ref IOTCatalogGroup>;
    protected ref map<string,bool> m_Expanded = new map<string,bool>;
    protected ref map<string,bool> m_SearchClosed = new map<string,bool>;
    protected ref array<ref IOTCatalogRow> m_Rows = new array<ref IOTCatalogRow>;
    protected ref array<string> m_AnchorClasses = new array<string>;
    protected ref array<string> m_ItemClasses = new array<string>;
    protected ref map<string,string> m_ItemNames = new map<string,string>;
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
        m_SearchPlaceholder = TextWidget.Cast(m_Root.FindAnyWidget("SceneSearchPlaceholder"));
        m_Results = TextListboxWidget.Cast(m_Root.FindAnyWidget("SceneResults"));
        m_ItemScroll = ScrollWidget.Cast(m_Root.FindAnyWidget("SceneItemScroll"));
        m_ItemContent = m_Root.FindAnyWidget("SceneItemRows");
        m_HoverRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\item_hover_preview.layout");
        m_HoverView = ItemPreviewWidget.Cast(m_HoverRoot.FindAnyWidget("HoverItemModel"));
        m_HoverClass = MultilineTextWidget.Cast(m_HoverRoot.FindAnyWidget("HoverItemClass"));
        TextWidget.Cast(m_HoverRoot.FindAnyWidget("HoverClassTitle")).SetText(IOTL.T("CLASSNAME"));
        m_HoverEmpty = TextWidget.Cast(m_HoverRoot.FindAnyWidget("HoverItemEmpty"));
        m_HoverEmpty.SetFlags(WidgetFlags.CENTER | WidgetFlags.VCENTER);
        m_HoverEmpty.SetText(IOTL.T("ITEM_PREVIEW_UNAVAILABLE"));
        m_HoverRoot.Show(false);
        m_Status = MultilineTextWidget.Cast(m_Root.FindAnyWidget("SceneStatus"));
        m_ShowStatic = CheckBoxWidget.Cast(m_Root.FindAnyWidget("SceneShowStatic"));
        float panelWidth,panelHeight;
        m_Root.GetScreenSize(panelWidth,panelHeight);
        m_PanelScale = panelWidth/360;
        m_ShowStatic.SetChecked(false);
        m_Expanded.Set("objects",true);
        m_Expanded.Set("items",true);
        IOTMapCatalog.Populate(m_MapMasks);
        LoadCatalog();
        m_ItemScroll.SetHandler(this);
        m_Root.SetHandler(this);
        SetMode(false);
        DrawSearchIcon();
    }

    protected void DrawSearchIcon()
    {
        CanvasWidget icon = CanvasWidget.Cast(m_Root.FindAnyWidget("SceneSearchIcon"));
        float width,height;
        icon.GetScreenSize(width,height);
        float scale = width/24;
        float stroke = Math.Max(1,1.7*scale);
        int color = ARGB(255,200,208,214);
        icon.Clear();
        for (int segment = 0; segment < 32; segment++)
        {
            float start = segment*360.0/32*Math.DEG2RAD;
            float end = (segment+1)*360.0/32*Math.DEG2RAD;
            icon.DrawLine((9+6*Math.Cos(start))*scale,(9+6*Math.Sin(start))*scale,(9+6*Math.Cos(end))*scale,(9+6*Math.Sin(end))*scale,stroke,color);
        }
        icon.DrawLine(13.5*scale,13.5*scale,21*scale,21*scale,stroke,color);
    }

    void ~IOTSceneBrowser()
    {
        HideHoverPreview();
        if (m_HoverRoot) m_HoverRoot.Unlink();
        if (m_Root) m_Root.Unlink();
    }







    protected EntityAI CreatePreviewEntity(string classname)
    {
        // Follow the game's script-console preview approach. Keep the local
        // instance below the map, without physics, pathgraph or scene ownership.
        #ifdef DEVELOPER
        DayZGame.m_IsPreviewSpawn = true;
        #endif
        int flags = ECE_LOCAL | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT | ECE_NOSURFACEALIGN | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD;
        EntityAI entity = EntityAI.Cast(GetGame().CreateObjectEx(classname,"0 -1000 0",flags,RF_IGNORE));
        #ifdef DEVELOPER
        DayZGame.m_IsPreviewSpawn = false;
        #endif
        if (!entity) return null;
        dBodyDestroy(entity);
        entity.DisableSimulation(true);
        entity.SetAllowDamage(false);
        return entity;
    }


    EntityAI HoverEntity() { return m_HoverEntity; }
    Widget HoverRoot() { return m_HoverRoot; }
    ItemPreviewWidget HoverView() { return m_HoverView; }
    bool HoverBoundVisible() { return m_HoverBoundVisible; }
    Widget ItemRowWidget(int index)
    {
        Widget widget;
        if (index >= 0 && index < m_ItemRows.Count()) widget = m_ItemRows[index];
        return widget;
    }
    ScrollWidget ItemScroll() { return m_ItemScroll; }

    void RevealItemRow(int index)
    {
        if (index < 0 || index >= m_ItemRows.Count()) return;
        m_ItemScroll.Update();
        float x,y,width,height,rowX,rowY,rowWidth,rowHeight;
        m_ItemScroll.GetScreenPos(x,y);
        m_ItemScroll.GetScreenSize(width,height);
        m_ItemRows[index].GetScreenPos(rowX,rowY);
        m_ItemRows[index].GetScreenSize(rowWidth,rowHeight);
        float position = m_ItemScroll.GetVScrollPos();
        if (rowY < y) position = position+rowY - y - 1;
        else if (rowY+rowHeight > y+height) position = position+rowY+rowHeight - y - height+1;
        m_ItemScroll.VScrollToPos(Math.Max(0,position));
        m_ItemScroll.Update();
    }

    int ClassRow(string classname)
    {
        for (int i = 0; i < m_Rows.Count(); i++)
        {
            if (m_Rows[i].ClassName == classname) return i;
        }
        return -1;
    }

    void SelectCatalogItemRow(int index)
    {
        if (index < 0 || index >= m_Rows.Count()) return;
        m_Updating = true;
        m_Results.SelectRow(index);
        SelectRow(index);
        m_Updating = false;
    }

    protected void UpdateItemRowColors()
    {
        int selected = m_Results.GetSelectedRow();
        for (int i = 0; i < m_ItemRows.Count(); i++)
        {
            int color = ARGB(255,35,40,43);
            if (i == m_HoverRow) color = ARGB(255,60,73,82);
            if (i == selected) color = ARGB(255,150,43,43);
            m_ItemRows[i].FindAnyWidget("CatalogItemBackground").SetColor(color);
        }
    }

    void HideHoverPreview()
    {
        if (m_HoverView) m_HoverView.SetItem(null);
        if (m_HoverEntity && GetGame()) GetGame().ObjectDelete(m_HoverEntity);
        m_HoverEntity = null;
        m_HoverRequested = "";
        m_HoverApplied = "";
        m_HoverRow = -1;
        m_HoverBoundVisible = false;
        if (m_HoverRoot) m_HoverRoot.Show(false);
        if (m_Results) UpdateItemRowColors();
    }

    bool HoverContains(vector point)
    {
        if (!m_HoverRoot || !m_HoverRoot.IsVisible()) return false;
        float x,y,width,height;
        m_HoverRoot.GetScreenPos(x,y);
        m_HoverRoot.GetScreenSize(width,height);
        return point[0] >= x && point[0] < x+width && point[1] >= y && point[1] < y+height;
    }

    protected int ItemRowAt(vector point)
    {
        if (!CatalogListPoint(point)) return -1;
        for (int i = 0; i < m_ItemRows.Count(); i++)
        {
            float x,y,width,height;
            m_ItemRows[i].GetScreenPos(x,y);
            m_ItemRows[i].GetScreenSize(width,height);
            if (point[0] >= x && point[0] < x+width && point[1] >= y && point[1] < y+height) return i;
        }
        return -1;
    }

    protected void PositionHoverPreview(int row)
    {
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float panelX,panelY,panelWidth,panelHeight,rowX,rowY;
        m_Root.GetScreenPos(panelX,panelY);
        m_Root.GetScreenSize(panelWidth,panelHeight);
        m_ItemRows[row].GetScreenPos(rowX,rowY);
        float width = Math.Min(280*m_PanelScale,screenWidth - 8);
        float height = Math.Min(292*m_PanelScale,screenHeight - 8);
        float gap = 12*m_PanelScale;
        float x = panelX+panelWidth+gap;
        if (x+width > screenWidth - gap) x = panelX - width - gap;
        x = Math.Clamp(x,4,Math.Max(4,screenWidth - width - 4));
        float y = Math.Clamp(rowY,4,Math.Max(4,screenHeight - height - 40));
        float currentX,currentY,currentWidth,currentHeight;
        m_HoverRoot.GetScreenPos(currentX,currentY);
        m_HoverRoot.GetScreenSize(currentWidth,currentHeight);
        if (Math.AbsFloat(currentX - x) > 0.1 || Math.AbsFloat(currentY - y) > 0.1) m_HoverRoot.SetScreenPos(x,y);
        if (Math.AbsFloat(currentWidth - width) > 0.1 || Math.AbsFloat(currentHeight - height) > 0.1) m_HoverRoot.SetScreenSize(width,height);
    }

    // Hit-test real row widgets after scrolling; never change list selection
    // just to determine the class under the pointer.
    void HoverAt(vector point, bool enabled, bool force = false)
    {
        int row = -1;
        if (enabled && m_ItemsMode && m_Root.IsVisible()) row = ItemRowAt(point);
        if (row < 0 || row >= m_Rows.Count() || m_Rows[row].ClassName == "")
        {
            if (m_HoverRequested != "" || m_HoverRoot.IsVisible()) HideHoverPreview();
            return;
        }
        string classname = m_Rows[row].ClassName;
        if (classname != m_HoverRequested)
        {
            HideHoverPreview();
            m_HoverRequested = classname;
            m_HoverDue = GetGame().GetTime()+250;
        }
        if (m_HoverRow != row) { m_HoverRow = row; UpdateItemRowColors(); }
        if (m_HoverApplied != classname && !force && GetGame().GetTime() < m_HoverDue) return;
        // Native ItemPreviewWidget needs its visible final bounds before
        // SetItem/SetView initializes the render target.
        PositionHoverPreview(row);
        if (!m_HoverRoot.IsVisible())
        {
            m_HoverRoot.Show(true);
            m_HoverRoot.Update();
            m_HoverView.Update();
        }
        if (m_HoverApplied != classname)
        {
            m_HoverApplied = classname;
            m_HoverEntity = CreatePreviewEntity(classname);
            m_HoverClass.SetText(classname);
            m_HoverEmpty.Show(!m_HoverEntity);
            if (m_HoverEntity)
            {
                m_HoverBoundVisible = m_HoverView.IsVisibleHierarchy();
                m_HoverView.SetItem(m_HoverEntity);
                m_HoverView.SetView(m_HoverEntity.GetViewIndex());
                m_HoverView.SetModelOrientation("0 0 0");
                m_HoverView.SetModelPosition("0 0 1");
            }
        }
    }

    protected void LayoutCatalog(bool items)
    {
        HideHoverPreview();
        // Keep the native list only as a selection/data bridge. Real rows
        // provide exact press hit testing in both catalog modes.
        m_Results.Show(false);
        m_ItemScroll.Show(true);
        ResizeCatalog();
    }

    void FitAbove(Widget sceneList)
    {
        float x,y,sceneX,sceneY;
        m_Root.GetScreenPos(x,y);
        sceneList.GetScreenPos(sceneX,sceneY);
        float height = Math.Max(0,sceneY - y - 12*m_PanelScale);
        if (Math.AbsFloat(height - m_CatalogHeight) < 0.1) return;
        m_CatalogHeight = height;
        HideHoverPreview();
        ResizeCatalog();
    }

    protected void ResizeCatalog()
    {
        float footer = 66;
        float listHeight = 228*m_PanelScale;
        if (m_CatalogHeight > 0) listHeight = Math.Max(24*m_PanelScale,m_CatalogHeight - (161+footer)*m_PanelScale);
        m_Results.SetScreenSize(328*m_PanelScale,listHeight);
        m_ItemScroll.SetScreenSize(328*m_PanelScale,listHeight);
        float statusY = 169*m_PanelScale+listHeight;
        m_Status.SetPos(16*m_PanelScale,statusY);
        m_Root.SetScreenSize(360*m_PanelScale,statusY+58*m_PanelScale);
        m_ItemScroll.Update();
    }

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
        // ConfigGetText resolves inherited displayName stringtable entries
        // in the client language without constructing an inventory entity.
        string displayName;
        GetGame().ConfigGetText(root+" "+name+" displayName",displayName);
        displayName.TrimInPlace();
        string key = displayName;
        key.ToUpper();
        if (displayName == "" || key.IndexOf("$STR") == 0 || key.IndexOf("#STR") == 0) displayName = name;
        m_ItemNames.Set(name,displayName);
        string path = IOTItemCatalog.Group(name,model,root);
        key = "items/"+path;
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

    string ItemName(string classname)
    {
        string displayName = m_ItemNames.Get(classname);
        if (displayName == "") displayName = classname;
        return displayName;
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
        LayoutCatalog(items);
        m_Updating = true;
        m_ShowStatic.Show(!items);
        if (items) m_SearchPlaceholder.SetText(IOTL.T("SEARCH_ITEMS_PLACEHOLDER"));
        else m_SearchPlaceholder.SetText(IOTL.T("CLASSNAME"));
        m_Search.SetText("");
        m_SelectedClass = "";
        m_SelectedKey = "";
        ButtonWidget.Cast(m_Root.FindAnyWidget("SceneAnchorsMode")).SetState(!items);
        ButtonWidget.Cast(m_Root.FindAnyWidget("SceneItemsMode")).SetState(items);
        m_Updating = false;
        Filter();
        if (items) SetStatus("");
        else SetStatus(IOTL.T("OBJECT_TREE_HINT"));
    }

    protected bool MatchesQuery(string name, string query)
    {
        if (query == "") return true;
        string classname = name;
        classname.ToLower();
        if (classname.IndexOf(query) >= 0) return true;
        if (!m_ItemsMode) return false;
        string displayName = ItemName(name);
        displayName.ToLower();
        return displayName.IndexOf(query) >= 0;
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
        {
            Widget widget = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\item_catalog_row.layout",m_ItemContent);
            widget.SetPos(0,(m_ItemRows.Count()*24)*m_PanelScale);
            widget.SetScreenSize(308*m_PanelScale,24*m_PanelScale);
            TextWidget.Cast(widget.FindAnyWidget("CatalogItemLabel")).SetText(label);
            m_ItemRows.Insert(widget);
        }
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
                foreach (string classname : classes) AddRow(keyPath+"/"+classname,indent+ItemName(classname),classname);
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
        HideHoverPreview();
        float scrollPosition = m_ItemScroll.GetVScrollPos01();
        m_Updating = true;
        string query = m_Search.GetText();
        m_SearchPlaceholder.Show(query == "");
        query.TrimInPlace();
        query.ToLower();
        if (query != m_LastQuery)
        {
            scrollPosition = 0;
            m_SearchClosed.Clear();
            m_SelectedKey = "";
        }
        m_LastQuery = query;
        m_Results.ClearItems();
        foreach (Widget oldRow : m_ItemRows) oldRow.Unlink();
        m_ItemRows.Clear();
        m_Filtered.Clear();
        m_Rows.Clear();
        m_MatchCount = 0;
        if (m_ItemsMode) BuildItemTree(query);
        else BuildTree(query);
        m_ItemContent.SetScreenSize(308*m_PanelScale,Math.Max(1,m_ItemRows.Count()*24)*m_PanelScale);
        m_ItemContent.Update();
        m_ItemScroll.Update();
        m_ItemScroll.VScrollToPos01(scrollPosition);
        int selected = RowIndex(m_SelectedKey);
        if (selected < 0 && query != "")
        {
            for (int i = 0; i < m_Rows.Count(); i++)
            {
                if (m_Rows[i].ClassName != "") { selected = i; break; }
            }
        }
        if (selected < 0 && m_Rows.Count() > 0) selected = 0;
        m_SelectedClass = "";
        if (selected >= 0) { m_Results.SelectRow(selected); SelectRow(selected); }
        m_Updating = false;
    }

    protected void SelectRow(int row)
    {
        if (row < 0 || row >= m_Rows.Count()) return;
        m_SelectedKey = m_Rows[row].Key;
        m_SelectedClass = m_Rows[row].ClassName;
        UpdateItemRowColors();
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
        return true;
    }

    int MatchCount() { return m_MatchCount; }
    int ShownCount() { return m_Filtered.Count(); }
    int RowCount() { return m_Rows.Count(); }
    string FirstClass() { return m_SelectedClass; }

    void Search(string query)
    {
        m_Updating = true;
        m_Search.SetText(query);
        m_Updating = false;
        Filter();
    }

    void SetStatus(string value) { m_Status.SetText(value); }
    void Show(bool visible)
    {
        m_Root.Show(visible);
        if (!visible) HideHoverPreview();
    }
    bool IsVisible() { return m_Root.IsVisible(); }
    Widget Root() { return m_Root; }

    bool ItemsMode() { return m_ItemsMode; }

    bool CatalogListPoint(vector point)
    {
        if (!m_Root.IsVisible()) return false;
        float x,y,width,height;
        m_ItemScroll.GetScreenPos(x,y);
        m_ItemScroll.GetScreenSize(width,height);
        // Leave the native scrollbar available for normal list navigation.
        float scrollbarWidth = Math.Max(20*m_PanelScale,m_ItemScroll.GetScrollbarWidth());
        return point[0] >= x && point[0] < x+width-scrollbarWidth && point[1] >= y && point[1] < y+height;
    }

    string SelectedDragClass()
    {
        int row = m_Results.GetSelectedRow();
        if (row < 0 || row >= m_Rows.Count()) return "";
        return m_Rows[row].ClassName;
    }

    bool Contains(vector point)
    {
        if (HoverContains(point)) return true;
        if (!m_Root.IsVisible()) return false;
        float x,y,width,height;
        m_Root.GetScreenPos(x,y);
        m_Root.GetScreenSize(width,height);
        return point[0] >= x && point[0] <= x+width && point[1] >= y && point[1] <= y+height;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (m_Tool.AnchorReplacementPending()) return true;
        int itemRow = m_ItemRows.Find(w);
        if (itemRow >= 0 && itemRow < m_Rows.Count()) return ActivateRow(m_Rows[itemRow].Key);
        if (w == m_ShowStatic) { SetShowStaticObjects(m_ShowStatic.IsChecked()); return true; }
        if (w == m_Results)
        {
            int row = m_Results.GetSelectedRow();
            if (row >= 0 && row < m_Rows.Count()) return ActivateRow(m_Rows[row].Key);
        }
        string name = w.GetName();
        if (name == "SceneAnchorsMode") { SetMode(false); return true; }
        if (name == "SceneItemsMode") { SetMode(true); return true; }
        return false;
    }

    override bool OnMouseButtonDown(Widget w, int x, int y, int button)
    {
        if (m_Tool.AnchorReplacementPending()) return true;
        int itemRow = m_ItemRows.Find(w);
        if (itemRow >= 0 && button == MouseState.LEFT)
        {
            SelectCatalogItemRow(itemRow);
            HideHoverPreview();
            SetFocus(w);
            m_Tool.MousePress(button);
            return true;
        }
        if (w == m_Results && button == MouseState.LEFT) m_Tool.MousePress(button);
        return false;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button)
    {
        if (button == MouseState.LEFT) m_Tool.MouseRelease(button);
        return false;
    }

    override bool OnMouseWheel(Widget w, int x, int y, int wheel)
    {
        if (m_Tool.AnchorReplacementPending()) return true;
        if (!m_Root.IsVisible()) return false;
        Widget target = w;
        while (target && target != m_ItemScroll) target = target.GetParent();
        if (!target) return false;
        // Consume the native wheel action: its default step skips several
        // catalog rows. Use the same scaled height as the item row widgets.
        if (wheel != 0)
        {
            HideHoverPreview();
            float delta = 24*m_PanelScale;
            if (wheel > 0) delta = -delta;
            m_ItemScroll.VScrollToPos(Math.Max(0,m_ItemScroll.GetVScrollPos()+delta));
            m_ItemScroll.Update();
        }
        return true;
    }

    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        if (m_Updating || m_Tool.AnchorReplacementPending()) return false;
        if (w == m_ShowStatic) { SetShowStaticObjects(m_ShowStatic.IsChecked()); return true; }
        if (w == m_Search) { Filter(); return true; }
        if (w == m_Results) { SelectRow(m_Results.GetSelectedRow()); return true; }
        return false;
    }

    override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn)
    {
        if (m_Updating || w != m_Results) return false;
        SelectRow(row);
        return true;
    }

    override bool OnKeyDown(Widget w, int x, int y, int key)
    {
        if (m_Tool.AnchorReplacementPending()) return true;
        int itemRow = m_ItemRows.Find(w);
        if (itemRow >= 0)
        {
            if (key == KeyCode.KC_RETURN) return ActivateRow(m_Rows[itemRow].Key);
            if (key == KeyCode.KC_UP || key == KeyCode.KC_DOWN)
            {
                int next = itemRow+1;
                if (key == KeyCode.KC_UP) next = itemRow - 1;
                next = Math.Clamp(next,0,m_ItemRows.Count() - 1);
                SelectCatalogItemRow(next);
                RevealItemRow(next);
                SetFocus(m_ItemRows[next]);
                return true;
            }
        }
        if (w != m_Results || key != KeyCode.KC_RETURN) return false;
        int row = m_Results.GetSelectedRow();
        if (row >= 0 && row < m_Rows.Count()) return ActivateRow(m_Rows[row].Key);
        return false;
    }
}

// Flat scene list. Rows bind directly to entities rather than visible IDs.
class IOTSceneListRow
{
    Object Anchor;
    ItemBase Item;
    Man Character;
}

class IOTSceneItems : ScriptedWidgetEventHandler
{
    protected IOTProxyTool m_Tool;
    protected Widget m_Root;
    protected TextListboxWidget m_List;
    protected ref array<ref IOTSceneListRow> m_Rows = new array<ref IOTSceneListRow>;
    protected int m_ItemCount;
    protected int m_AnchorCount;
    protected bool m_Updating;

    void IOTSceneItems(IOTProxyTool tool)
    {
        m_Tool = tool;
        m_Root = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\scene_items.layout");
        m_List = TextListboxWidget.Cast(m_Root.FindAnyWidget("SceneObjectsList"));
        m_Root.SetHandler(this);
        m_Root.SetSort(1000);
    }

    void ~IOTSceneItems() { if (m_Root) m_Root.Unlink(); }

    Widget Root() { return m_Root; }
    TextListboxWidget List() { return m_List; }
    int Count() { return m_ItemCount; }
    int AnchorCount() { return m_AnchorCount; }
    int RowCount() { return m_Rows.Count(); }
    bool IsVisible() { return m_Root.IsVisible(); }
    void Show(bool visible) { m_Root.Show(visible); }

    void Position(Widget browser)
    {
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float x,y,width,height;
        browser.GetScreenPos(x,y);
        browser.GetScreenSize(width,height);
        float scale = width/360;
        m_Root.SetScreenSize(width,150*scale);
        // Keep the same window-safe lower margin as the former bottom tray.
        m_Root.SetScreenPos(x,screenHeight - 150*scale - Math.Max(54,24*scale));
    }

    bool Contains(vector point)
    {
        if (!m_Root.IsVisible()) return false;
        float x,y,width,height;
        m_Root.GetScreenPos(x,y);
        m_Root.GetScreenSize(width,height);
        return point[0] >= x && point[0] < x+width && point[1] >= y && point[1] < y+height;
    }

    int ItemRow(ItemBase item)
    {
        if (!item) return -1;
        for (int i = 0; i < m_Rows.Count(); i++)
            if (m_Rows[i].Item == item) return i;
        return -1;
    }

    int AnchorRow(Object anchor)
    {
        if (!anchor) return -1;
        for (int i = 0; i < m_Rows.Count(); i++)
            if (m_Rows[i].Anchor == anchor) return i;
        return -1;
    }

    int CharacterRow()
    {
        for (int i = 0; i < m_Rows.Count(); i++)
            if (m_Rows[i].Character) return i;
        return -1;
    }

    Object RowObject(int row)
    {
        if (row < 0 || row >= m_Rows.Count()) return null;
        if (m_Rows[row].Character) return m_Rows[row].Character;
        if (m_Rows[row].Item) return m_Rows[row].Item;
        return m_Rows[row].Anchor;
    }

    void Refresh(array<ref IOTSceneEntry> scenes, array<ItemBase> created, Object selected, Object active, bool reveal = false)
    {
        array<ref IOTSceneListRow> rows = new array<ref IOTSceneListRow>;
        array<ItemBase> tracked = new array<ItemBase>;
        m_ItemCount = 0;
        m_AnchorCount = 0;
        Man player = GetGame().GetPlayer();
        if (player)
        {
            IOTSceneListRow characterRow = new IOTSceneListRow;
            characterRow.Character = player;
            rows.Insert(characterRow);
        }
        foreach (IOTSceneEntry scene : scenes)
        {
            if (!scene.Anchor) continue;
            IOTSceneListRow anchorRow = new IOTSceneListRow;
            anchorRow.Anchor = scene.Anchor;
            rows.Insert(anchorRow);
            m_AnchorCount++;
            foreach (ItemBase item : scene.Items)
                if (item) tracked.Insert(item);
        }
        // Creation order is independent of anchor ownership. All entries use
        // the same level; CE ownership remains in the tool's scene data.
        foreach (ItemBase createdItem : created)
        {
            if (!createdItem || createdItem.IsHologram() || tracked.Find(createdItem) < 0) continue;
            IOTSceneListRow itemRow = new IOTSceneListRow;
            itemRow.Item = createdItem;
            rows.Insert(itemRow);
            m_ItemCount++;
        }
        bool rebuild = rows.Count() != m_Rows.Count();
        if (!rebuild)
        {
            for (int row = 0; row < rows.Count(); row++)
            {
                if (rows[row].Anchor != m_Rows[row].Anchor || rows[row].Item != m_Rows[row].Item || rows[row].Character != m_Rows[row].Character) { rebuild = true; break; }
            }
        }
        m_Updating = true;
        m_Rows = rows;
        // Update in place during periodic refreshes so manual scrolling survives.
        if (rebuild) m_List.ClearItems();
        for (int index = 0; index < m_Rows.Count(); index++)
        {
            IOTSceneListRow entry = m_Rows[index];
            string label;
            int color = ARGB(255,255,255,255);
            if (entry.Character) label = IOTL.T("SCENE_CHARACTER");
            else if (entry.Item)
            {
                label = entry.Item.GetType();
                if (entry.Item.GetHierarchyParent()) { label += IOTL.T("TRAY_INVENTORY"); color = ARGB(255,150,155,160); }
            }
            else
            {
                label = entry.Anchor.GetType();
                if (entry.Anchor == active) color = ARGB(255,110,195,245);
            }
            if (rebuild) m_List.AddItem(label,null,0);
            else m_List.SetItem(index,label,null,0);
            m_List.SetItemColor(index,0,color);
        }
        int selectedRow = -1;
        for (int selectedIndex = 0; selectedIndex < m_Rows.Count(); selectedIndex++)
            if (RowObject(selectedIndex) == selected) { selectedRow = selectedIndex; break; }
        if (m_List.GetSelectedRow() != selectedRow) m_List.SelectRow(selectedRow);
        if (reveal && selectedRow >= 0) m_List.EnsureVisible(selectedRow);
        m_Root.FindAnyWidget("CreatedEmpty").Show(m_Rows.Count() == 0);
        m_Updating = false;
    }

    bool ActivateRow(int row)
    {
        if (row < 0 || row >= m_Rows.Count()) return false;
        IOTSceneListRow entry = m_Rows[row];
        if (entry.Character) return m_Tool.SelectSceneCharacter();
        if (entry.Item) return m_Tool.SelectCreatedItem(entry.Item);
        return m_Tool.SelectSceneAnchor(entry.Anchor);
    }

    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        if (w != m_List || m_Updating) return false;
        if (!ActivateRow(m_List.GetSelectedRow())) m_Tool.RefreshObjects();
        return true;
    }

    override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn)
    {
        if (w != m_List || m_Updating) return false;
        if (!ActivateRow(row)) m_Tool.RefreshObjects();
        return true;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w != m_List || m_Updating || button != 0) return false;
        // Clicking the selected anchor or character can focus it again.
        int row = m_List.GetSelectedRow();
        if (row >= 0 && row < m_Rows.Count() && !m_Rows[row].Item) ActivateRow(row);
        return true;
    }
}

// Shared screen bounds for world input. Native camera projection stays unchanged,
// so screen rays and the stock Gizmo use the same coordinate system.
class IOTEditorViewport
{
    protected Widget m_Root;
    protected float m_Left;
    protected float m_Top;
    protected float m_Right;
    protected float m_Bottom;
    protected bool m_Valid;
    protected bool m_Active;

    void IOTEditorViewport()
    {
        m_Root = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\editor_viewport.layout");
        if (m_Root) { m_Root.SetSort(-100); m_Root.Show(false); }
    }

    void ~IOTEditorViewport() { if (m_Root) m_Root.Unlink(); }

    bool Ready() { return m_Root != null; }
    bool IsVisible() { return m_Root && m_Root.IsVisible(); }
    vector Origin() { return Vector(m_Left,m_Top,0); }
    vector Size() { return Vector(m_Right-m_Left,m_Bottom-m_Top,0); }
    vector Center() { return (Origin()+Vector(m_Right,m_Bottom,0))*0.5; }

    void Show(bool visible)
    {
        if (!visible) m_Valid = false;
        if (m_Root) m_Root.Show(visible && m_Valid);
    }

    void Update(Widget browser, Widget settings, Widget tray, Widget toolbar, bool visible)
    {
        if (!m_Root || !browser || !settings || !tray || !visible)
        {
            Show(false);
            return;
        }
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float leftX,leftY,leftWidth,leftHeight,rightX,rightY,trayX,trayY,trayWidth,trayHeight;
        browser.GetScreenPos(leftX,leftY);
        browser.GetScreenSize(leftWidth,leftHeight);
        settings.GetScreenPos(rightX,rightY);
        tray.GetScreenPos(trayX,trayY);
        tray.GetScreenSize(trayWidth,trayHeight);
        float gap = Math.Max(4,leftWidth/30);
        m_Left = Math.Max(0,Math.Max(leftX+leftWidth,trayX+trayWidth)+gap);
        m_Top = Math.Max(0,Math.Min(leftY,rightY));
        if (toolbar && toolbar.IsVisible())
        {
            float toolbarX,toolbarY,toolbarWidth,toolbarHeight;
            toolbar.GetScreenPos(toolbarX,toolbarY);
            toolbar.GetScreenSize(toolbarWidth,toolbarHeight);
            m_Top = Math.Max(m_Top,toolbarY+toolbarHeight+gap);
        }
        m_Right = Math.Min(screenWidth,rightX-gap);
        m_Bottom = screenHeight - Math.Max(40,gap);
        m_Valid = m_Right-m_Left >= 64 && m_Bottom-m_Top >= 64;
        if (m_Valid)
        {
            float width = m_Right-m_Left;
            float height = m_Bottom-m_Top;
            m_Root.SetScreenPos(m_Left,m_Top);
            m_Root.SetScreenSize(width,height);
            m_Root.FindAnyWidget("WorldTop").SetScreenSize(width,1);
            m_Root.FindAnyWidget("WorldBottom").SetScreenPos(m_Left,m_Bottom - 1);
            m_Root.FindAnyWidget("WorldBottom").SetScreenSize(width,1);
            m_Root.FindAnyWidget("WorldLeft").SetScreenSize(1,height);
            m_Root.FindAnyWidget("WorldRight").SetScreenPos(m_Right - 1,m_Top);
            m_Root.FindAnyWidget("WorldRight").SetScreenSize(1,height);
        }
        m_Root.Show(m_Valid);
    }

    bool Contains(vector point)
    {
        return m_Valid && point[0] >= m_Left && point[0] < m_Right && point[1] >= m_Top && point[1] < m_Bottom;
    }

    void SetActive(bool active)
    {
        if (!m_Root || active == m_Active) return;
        m_Active = active;
        int color = ARGB(130,160,175,185);
        if (active) color = ARGB(210,90,165,215);
        Widget edge = m_Root.GetChildren();
        while (edge) { edge.SetColor(color); edge = edge.GetSibling(); }
    }
}

// Offline proxy authoring: existing world items, native Gizmo, precise controls.
// CE export remains calibrated for an unrotated, scale-one anchor / group a=90.
class IOTProxyTool : ScriptedWidgetEventHandler
{
    protected Object m_Anchor;
    protected ref IOTSceneBrowser m_Browser;
    protected ref IOTSceneItems m_CreatedTray;
    protected ref IOTEditorViewport m_Viewport;
    protected Widget m_CatalogDragRoot;
    protected TextWidget m_CatalogDragName;
    protected TextWidget m_CatalogDragHint;
    protected bool m_CatalogPressed;
    protected bool m_CatalogDragging;
    protected vector m_CatalogStart;
    protected string m_CatalogClass;
    protected bool m_CatalogItems;
    protected Widget m_ReplaceRoot;
    protected string m_ReplaceClass;
    protected Object m_ReplaceAnchor;
    protected bool m_ReplaceAtSurface;
    protected vector m_ReplacePosition;
    protected vector m_ReplaceNormal;
    protected int m_NextSceneId;
    protected ref array<ItemBase> m_CreatedItems = new array<ItemBase>;
    protected int m_TrayRefreshTime;
    protected ref array<ref IOTSceneEntry> m_Scenes = new array<ref IOTSceneEntry>;
    protected IOTSceneEntry m_ActiveScene;
    protected string m_RunTag;
    protected ItemBase m_Item;
    protected Object m_MoveTarget;
    protected vector m_Original[4];
    protected vector m_OriginalProxyPosition;
    protected vector m_OriginalProxyAngles;
    protected bool m_WasSimulationDisabled;
    protected bool m_Editing;
    protected bool m_Pointer;
    protected bool m_Booted;
    protected bool m_PlayerMode;
    protected bool m_CharacterFocused;
    protected bool m_PlayerWasDisabled;
    protected bool m_PlayerSimulationPending;
    protected bool m_PlayerSimulationRequested;
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
    protected bool m_WorldDragCancelled;
    protected int m_ReleaseTime;
    protected vector m_ClickStart;
    protected vector m_ClickEnd;
    protected bool m_ShowDebug;
    protected bool m_GizmoEnabled = true;
    protected bool m_RotateMode;
    protected bool m_DirtyInputs;
    protected bool m_UpdatingUI;
    protected bool m_FineOpen;
    protected bool m_SelfTest;
    protected vector m_TestPlayerPosition;
    protected vector m_TestPlayerMovedPosition;
    protected int m_Attempts;
    protected int m_MoveStepIndex = 1;
    protected int m_AngleStepIndex = 1;
    protected Widget m_Root;
    protected Widget m_Toolbar;
    protected Widget m_ErrorRoot;
    protected MultilineTextWidget m_ErrorText;
    protected string m_LastError;
    protected float m_ChromeTop;
    protected int m_ChromeWidth;
    protected int m_ChromeHeight;
    protected float m_PanelScale = 1;
    protected TextWidget m_Status;
    protected TextWidget m_NumberMeasure;
    protected TextWidget m_Debug;
    protected XComboBoxWidget m_ItemsList;
    protected XComboBoxWidget m_AnchorsList;
    protected ref array<EditBoxWidget> m_PosFields = new array<EditBoxWidget>;
    protected ref array<EditBoxWidget> m_RotFields = new array<EditBoxWidget>;
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
        m_Toolbar = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\editor_toolbar.layout");
        m_Toolbar.SetHandler(this);
        m_Toolbar.SetSort(1100);
        m_Toolbar.Show(false);
        m_ErrorRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\error_notification.layout");
        m_ErrorText = MultilineTextWidget.Cast(m_ErrorRoot.FindAnyWidget("ErrorText"));
        TextWidget.Cast(m_ErrorRoot.FindAnyWidget("ErrorTitle")).SetText(IOTL.T("ERROR_TITLE"));
        m_ErrorRoot.SetHandler(this);
        m_ErrorRoot.SetSort(1800);
        m_ErrorRoot.Show(false);
        m_ReplaceRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\anchor_replace.layout");
        m_ReplaceRoot.SetHandler(this);
        m_ReplaceRoot.SetSort(2500);
        m_ReplaceRoot.Show(false);
        TextWidget.Cast(m_ReplaceRoot.FindAnyWidget("ReplaceTitle")).SetText(IOTL.T("REPLACE_TITLE"));
        MultilineTextWidget.Cast(m_ReplaceRoot.FindAnyWidget("ReplaceWarning")).SetText(IOTL.T("REPLACE_WARNING"));
        ButtonWidget.Cast(m_ReplaceRoot.FindAnyWidget("ReplaceConfirm")).SetText(IOTL.T("REPLACE_CONFIRM"));
        ButtonWidget.Cast(m_ReplaceRoot.FindAnyWidget("ReplaceCancel")).SetText(IOTL.T("REPLACE_CANCEL"));
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
        m_CatalogDragRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\catalog_drag.layout");
        m_CatalogDragName = TextWidget.Cast(m_CatalogDragRoot.FindAnyWidget("DragClassName"));
        m_CatalogDragHint = TextWidget.Cast(m_CatalogDragRoot.FindAnyWidget("DragDropHint"));
        m_CatalogDragRoot.SetSort(2000);
        m_CatalogDragRoot.Show(false);
        m_Status = TextWidget.Cast(m_Root.FindAnyWidget("Status"));
        m_NumberMeasure = TextWidget.Cast(m_Root.FindAnyWidget("NumberMeasure"));
        m_Debug = TextWidget.Cast(m_Root.FindAnyWidget("Debug"));
        m_Debug.Show(false);
        m_ItemsList = XComboBoxWidget.Cast(m_Root.FindAnyWidget("ItemList"));
        m_AnchorsList = XComboBoxWidget.Cast(m_Root.FindAnyWidget("AnchorList"));
        for (int i = 0; i < 3; i++)
        {
            m_PosFields.Insert(EditBoxWidget.Cast(m_Root.FindAnyWidget("Pos" + i.ToString())));
            m_RotFields.Insert(EditBoxWidget.Cast(m_Root.FindAnyWidget("Rot" + i.ToString())));
        }
        SelectionControls(false);
        int year,month,day,hour,minute,second;
        GetYearMonthDayUTC(year,month,day);
        GetHourMinuteSecondUTC(hour,minute,second);
        m_RunTag = year.ToString()+"-"+month.ToString()+"-"+day.ToString()+"_"+hour.ToString()+"-"+minute.ToString()+"-"+second.ToString()+"UTC";
        m_Browser = new IOTSceneBrowser(this);
        m_CreatedTray = new IOTSceneItems(this);
        m_CreatedTray.Position(m_Browser.Root());
        m_Viewport = new IOTEditorViewport;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Tick, 50, true);
        PrintToRPT("[PROXY TOOL V2] Panel loaded. Click item/empty space; F1 cursor/flight; F4 player/editor; F7/F8 move/rotate; F10 export.");
    }

    void ~IOTProxyTool()
    {
        if (GetGame()) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(Tick);
        SetPlayerHudHidden(false);
        if (m_ModeHint) m_ModeHint.Unlink();
        if (m_SpeedRoot) m_SpeedRoot.Unlink();
        if (m_CatalogDragRoot) m_CatalogDragRoot.Unlink();
        if (m_ErrorRoot) m_ErrorRoot.Unlink();
        if (m_ReplaceRoot) m_ReplaceRoot.Unlink();
        m_Browser = null;
        m_CreatedTray = null;
        m_Viewport = null;
        if (m_Toolbar) m_Toolbar.Unlink();
        if (m_Root) m_Root.Unlink();
    }

    protected void Status(string message)
    {
        ClearError();
        if (m_Status) m_Status.SetText(message);
    }

    void ReportError(string message)
    {
        m_LastError = message;
        m_ErrorText.SetText(message);
        m_ErrorRoot.Show(!m_PlayerMode);
        PositionError();
        m_ErrorRoot.Update();
        PrintToRPT("[PROXY ERROR] "+message);
    }

    protected void ClearError()
    {
        m_LastError = "";
        if (m_ErrorRoot && m_ErrorRoot.IsVisible()) m_ErrorRoot.Show(false);
    }

    protected bool ErrorContains(vector point)
    {
        if (!m_ErrorRoot || !m_ErrorRoot.IsVisible()) return false;
        float x,y,width,height;
        m_ErrorRoot.GetScreenPos(x,y);
        m_ErrorRoot.GetScreenSize(width,height);
        return point[0] >= x && point[0] < x+width && point[1] >= y && point[1] < y+height;
    }

    protected void PositionError()
    {
        if (!m_ErrorRoot || !m_ErrorRoot.IsVisible()) return;
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float areaX = 0;
        float areaY = 0;
        float areaWidth = screenWidth;
        float areaHeight = screenHeight;
        if (m_Viewport && m_Viewport.IsVisible())
        {
            vector origin = m_Viewport.Origin();
            vector size = m_Viewport.Size();
            if (size[0] >= 280*m_PanelScale && size[1] >= 160*m_PanelScale)
            {
                areaX = origin[0]; areaY = origin[1];
                areaWidth = size[0]; areaHeight = size[1];
            }
        }
        float margin = 12*m_PanelScale;
        float width = Math.Max(1,Math.Min(440*m_PanelScale,areaWidth - 2*margin));
        float height = 120*m_PanelScale;
        float x = areaX+(areaWidth - width)*0.5;
        float y = Math.Max(margin,areaY+areaHeight - height - margin);
        float currentX,currentY,currentWidth,currentHeight;
        m_ErrorRoot.GetScreenPos(currentX,currentY);
        m_ErrorRoot.GetScreenSize(currentWidth,currentHeight);
        if (Math.AbsFloat(currentX - x) > 0.1 || Math.AbsFloat(currentY - y) > 0.1) m_ErrorRoot.SetScreenPos(x,y);
        if (Math.AbsFloat(currentWidth - width) > 0.1 || Math.AbsFloat(currentHeight - height) > 0.1)
        {
            m_ErrorRoot.SetScreenSize(width,height);
            m_ErrorRoot.FindAnyWidget("ErrorTitle").SetScreenSize(Math.Max(1,width - 76*m_PanelScale),24*m_PanelScale);
            m_ErrorRoot.FindAnyWidget("ErrorClose").SetPos(width - 38*m_PanelScale,8*m_PanelScale);
            m_ErrorText.SetScreenSize(Math.Max(1,width - 32*m_PanelScale),66*m_PanelScale);
        }
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

    protected string FieldNumber(float value)
    {
        float absolute = Math.AbsFloat(value);
        int whole = Math.Floor(absolute);
        int fraction = Math.Round((absolute - whole)*100000);
        if (fraction >= 100000) { whole++; fraction = 0; }
        string sign;
        if (value < 0 && (whole > 0 || fraction > 0)) sign = "-";
        return sign+whole.ToString()+"."+fraction.ToStringLen(5);
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
    void SetProxyPose(vector position, vector angles, bool refreshFields = true)
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
        if (refreshFields) SyncFields();
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
        m_NextSceneId++;
        scene.Id = m_NextSceneId;
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
        Object selected = SelectedObject();
        if (!selected)
        {
            selected = m_Anchor;
            if (m_CharacterFocused) selected = GetGame().GetPlayer();
        }
        if (m_CreatedTray) m_CreatedTray.Refresh(m_Scenes,m_CreatedItems,selected,m_Anchor,reveal);
        UpdateToolbar();
    }

    Object SelectedObject()
    {
        if (m_Item) return m_Item;
        return m_MoveTarget;
    }

    protected void SetItemSimulation(ItemBase item, bool disabled)
    {
        if (!item) return;
        item.DisableSimulation(disabled);
    }

    protected void SetPlayerSimulation(Man player, bool disabled)
    {
        m_PlayerSimulationPending = true;
        m_PlayerSimulationRequested = disabled;
        player.DisableSimulation(disabled);
    }

    protected bool SelectMoveTarget(Object target, bool character)
    {
        if (m_PlayerMode || !target) return false;
        if (m_MoveTarget == target && m_Editing) return true;
        DeselectItem();
        m_MoveTarget = target;
        m_CharacterFocused = character;
        vector initial[4];
        target.GetTransform(initial);
        copyarray(m_Original,initial);
        m_Editing = true;
        m_RotateMode = false;
        SelectionControls(true);
        UpdateGizmo();
        SyncFields();
        RefreshCreatedItems(true);
        Status("");
        return true;
    }

    protected bool MoveSceneTarget(vector position)
    {
        if (!m_MoveTarget || !m_Editing || m_PlayerMode || AnchorReplacementPending()) return false;
        for (int axis = 0; axis < 3; axis++)
            if (Math.AbsFloat(position[axis]) > 100000) { ReportError(IOTL.T("WORLD_NUMBER_LIMIT")); return false; }
        m_MoveTarget.SetPosition(position);
        return true;
    }

    bool SelectSceneCharacter()
    {
        if (AnchorReplacementPending()) return false;
        Man player = GetGame().GetPlayer();
        if (m_PlayerMode || !player) return false;
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        if (!camera) return false;
        if (!SelectMoveTarget(player,true)) return false;
        vector target = player.GetPosition()+"0 1 0";
        camera.SetPosition(target+"2 1 -3");
        camera.LookAt(target);
        SetPointer(true);
        RefreshCreatedItems(true);
        return true;
    }

    bool SelectSceneAnchor(Object anchor)
    {
        if (AnchorReplacementPending()) return false;
        if (m_PlayerMode || !anchor) return false;
        bool registered;
        foreach (IOTSceneEntry scene : m_Scenes)
            if (scene.Anchor == anchor) registered = true;
        if (!registered || !ValidAnchor(anchor)) return false;
        if (!SetAnchor(anchor)) return false;
        if (!SelectMoveTarget(anchor,false)) return false;
        RefreshObjects();
        FocusAnchor();
        RefreshCreatedItems(true);
        return true;
    }

    bool SelectCreatedItem(ItemBase item)
    {
        if (AnchorReplacementPending()) return false;
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

    bool SpawnSceneClass(string classname, bool itemMode, bool atSurface = false, vector surfacePosition = "0 0 0", vector surfaceNormal = "0 1 0")
    {
        if (m_PlayerMode || AnchorReplacementPending()) return false;
        classname = m_Browser.ResolveClass(classname,itemMode);
        if (classname == "") { ReportError(IOTL.T("UNKNOWN_CLASS")); return false; }
        if (itemMode && !m_Anchor) { ReportError(IOTL.T("ANCHOR_REQUIRED")); return false; }
        if (!itemMode && ExistingSceneAnchor())
        {
            RequestAnchorReplacement(classname,atSurface,surfacePosition,surfaceNormal);
            return false;
        }
        return SpawnResolvedSceneClass(classname,itemMode,atSurface,surfacePosition,surfaceNormal,false);
    }

    // The only commit path: validate the candidate before clearing old entities.
    protected bool SpawnResolvedSceneClass(string classname, bool itemMode, bool atSurface, vector surfacePosition, vector surfaceNormal, bool replacing)
    {
        bool dropping = atSurface;
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
        if (dropping) position = surfacePosition;
        else position[1] = GetGame().SurfaceY(position[0],position[2]) + 0.1;
        int flags = ECE_SETUP | ECE_CREATEPHYSICS | ECE_UPDATEPATHGRAPH | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOSURFACEALIGN;
        Object created = GetGame().CreateObjectEx(classname,position,flags,RF_IGNORE);
        if (!created) { ReportError(IOTL.F("SPAWN_FAILED",classname)); return false; }
        created.SetOrientation("0 0 0");
        created.SetScale(1);
        if (!dropping || !itemMode) created.PlaceOnSurface();
        created.SetOrientation("0 0 0");
        if (dropping && !itemMode)
        {
            // Native surface placement can offset the model horizontally.
            // Keep its ground height, but honor the author's drop X/Z.
            position = created.GetPosition();
            position[0] = surfacePosition[0];
            position[2] = surfacePosition[2];
            created.SetPosition(position);
        }
        if (itemMode)
        {
            ItemBase item = ItemBase.Cast(created);
            if (!item)
            {
                GetGame().ObjectDelete(created);
                ReportError(IOTL.T("NOT_INVENTORY_ITEM"));
                return false;
            }
            // PlaceOnSurface may use the item's configured resting rotation.
            // Recompute ground contact after restoring the editor's zero rotation.
            vector itemBounds[2];
            item.ClippingInfo(itemBounds);
            position = item.GetPosition();
            if (dropping)
            {
                if (surfaceNormal.Length() < 0.1) surfaceNormal = vector.Up;
                surfaceNormal.Normalize();
                float support;
                for (int corner = 0; corner < 8; corner++)
                {
                    vector vertex = itemBounds[0];
                    if (corner & 1) vertex[0] = itemBounds[1][0];
                    if (corner & 2) vertex[1] = itemBounds[1][1];
                    if (corner & 4) vertex[2] = itemBounds[1][2];
                    float projection = vector.Dot(vertex,surfaceNormal);
                    if (corner == 0 || projection < support) support = projection;
                }
                position = surfacePosition + surfaceNormal*(0.02 - support);
            }
            else position[1] = GetGame().SurfaceY(position[0],position[2]) - itemBounds[0][1] + 0.02;
            item.SetPosition(position);
            SetItemSimulation(item,false);
            m_ActiveScene.Items.Insert(item);
            m_CreatedItems.Insert(item);
            SelectItem(item);
        }
        else
        {
            if (!ValidAnchor(created))
            {
                GetGame().ObjectDelete(created);
                ReportError(IOTL.T("NOT_ANCHOR"));
                return false;
            }
            if (created.GetOrientation().Length() > 0.001 || Math.AbsFloat(created.GetScale() - 1) > 0.0001)
            {
                GetGame().ObjectDelete(created);
                ReportError(IOTL.T("ANCHOR_TRANSFORM_LIMIT"));
                return false;
            }
            if (replacing) ClearSceneLayout();
            SetAnchor(created);
            SelectSceneAnchor(created);
        }
        RefreshObjects();
        SceneStatus("");
        PrintToRPT("[PROXY SCENE] Created " + classname + " at " + created.GetPosition().ToString(false));
        return true;
    }

    bool AnchorReplacementPending() { return m_ReplaceClass != ""; }

    protected Object ExistingSceneAnchor()
    {
        foreach (IOTSceneEntry scene : m_Scenes)
            if (scene.Anchor) return scene.Anchor;
        return null;
    }

    protected void PositionReplacement()
    {
        if (!AnchorReplacementPending()) return;
        int width,height;
        GetScreenSize(width,height);
        m_ReplaceRoot.SetScreenPos(0,0);
        m_ReplaceRoot.SetScreenSize(width,height);
        Widget dialog = m_ReplaceRoot.FindAnyWidget("ReplaceDialog");
        float dialogWidth = Math.Min(520*m_PanelScale,width);
        float dialogHeight = Math.Min(310*m_PanelScale,height);
        dialog.SetScreenSize(dialogWidth,dialogHeight);
        dialog.SetScreenPos((width-dialogWidth)*0.5,(height-dialogHeight)*0.5);
    }

    protected void RequestAnchorReplacement(string classname, bool atSurface, vector position, vector normal)
    {
        SetFocus(null);
        CancelWorldGesture();
        CancelCatalogDrag();
        m_HeldButton = null;
        m_SuppressClick = null;
        m_Browser.HideHoverPreview();
        ClearError();
        m_ReplaceAnchor = ExistingSceneAnchor();
        m_ReplaceClass = classname;
        m_ReplaceAtSurface = atSurface;
        m_ReplacePosition = position;
        m_ReplaceNormal = normal;
        MultilineTextWidget.Cast(m_ReplaceRoot.FindAnyWidget("ReplaceNames")).SetText(IOTL.F("REPLACE_NAMES",m_ReplaceAnchor.GetType())+"\n"+IOTL.F("REPLACE_NEW",classname));
        PositionReplacement();
        m_ReplaceRoot.Show(true);
        m_ReplaceRoot.Update();
        SetFocus(m_ReplaceRoot.FindAnyWidget("ReplaceCancel"));
        UpdateGizmo();
    }

    protected bool FinishAnchorReplacement(bool confirm)
    {
        if (!AnchorReplacementPending()) return false;
        string classname = m_ReplaceClass;
        Object expected = m_ReplaceAnchor;
        bool atSurface = m_ReplaceAtSurface;
        vector position = m_ReplacePosition;
        vector normal = m_ReplaceNormal;
        m_ReplaceClass = "";
        m_ReplaceAnchor = null;
        m_ReplaceRoot.Show(false);
        SetFocus(null);
        CancelWorldGesture();
        UpdateGizmo();
        if (!confirm) return false;
        if (!expected || ExistingSceneAnchor() != expected)
        {
            ReportError(IOTL.T("REPLACE_SCENE_CHANGED"));
            return false;
        }
        return SpawnResolvedSceneClass(classname,false,atSurface,position,normal,true);
    }

    protected void ClearSceneLayout()
    {
        CancelWorldGesture();
        CancelCatalogDrag();
        DeselectItem();
        // Only tracked world entities belong to this layout. Picked-up items,
        // the character and its equipment survive anchor replacement.
        array<ItemBase> oldItems = new array<ItemBase>;
        foreach (ItemBase created : m_CreatedItems)
            if (created && oldItems.Find(created) < 0) oldItems.Insert(created);
        foreach (IOTSceneEntry scene : m_Scenes)
            foreach (ItemBase placed : scene.Items)
                if (placed && oldItems.Find(placed) < 0) oldItems.Insert(placed);
        foreach (ItemBase oldItem : oldItems)
            if (oldItem && !oldItem.GetHierarchyParent()) GetGame().ObjectDelete(oldItem);
        foreach (IOTSceneEntry oldScene : m_Scenes)
            if (oldScene.Anchor) GetGame().ObjectDelete(oldScene.Anchor);
        m_Scenes.Clear();
        m_CreatedItems.Clear();
        m_Items.Clear();
        m_Anchors.Clear();
        m_ActiveScene = null;
        m_Anchor = null;
    }

    bool SetAnchor(Object candidate)
    {
        if (AnchorReplacementPending()) return false;
        if (!candidate)
        {
            DeselectItem();
            m_Anchor = null;
            m_ActiveScene = null;
            RefreshCreatedItems();
            return true;
        }
        if (!ValidAnchor(candidate)) return false;
        if (candidate.GetOrientation().Length() > 0.001 || Math.AbsFloat(candidate.GetScale() - 1) > 0.0001)
        {
            ReportError(IOTL.T("ANCHOR_TRANSFORM_LIMIT"));
            return false;
        }
        if (candidate != m_Anchor || (m_MoveTarget && m_MoveTarget != candidate)) DeselectItem();
        m_CharacterFocused = false;
        m_Anchor = candidate;
        m_ActiveScene = RegisterAnchor(candidate);
        if (m_Item) m_DirtyInputs = false;
        SyncFields();
        RefreshCreatedItems();
        return true;
    }

    bool SelectItem(ItemBase item)
    {
        if (m_PlayerMode || AnchorReplacementPending() || !item || item.GetHierarchyParent() || item.IsHologram()) return false;
        if (m_MoveTarget) DeselectItem();
        m_CharacterFocused = false;
        IOTSceneEntry owner = ItemScene(item);
        if (owner && owner.Anchor != m_Anchor) SetAnchor(owner.Anchor);
        if (!m_Anchor) { ReportError(IOTL.T("ANCHOR_REQUIRED")); return false; }
        if (!owner && m_ActiveScene.Items.Find(item) < 0) m_ActiveScene.Items.Insert(item);
        if (item == m_Item && m_Editing) return true;
        if (m_Item && m_Editing)
        {
            GetGizmoApi().DeselectTracker(this);
            SetItemSimulation(m_Item,m_WasSimulationDisabled);
        }
        m_Item = item;
        vector initial[4];
        m_Item.GetTransform(initial);
        copyarray(m_Original, initial);
        m_OriginalProxyPosition = ProxyPosition();
        m_OriginalProxyAngles = ProxyAngles();
        m_WasSimulationDisabled = m_Item.GetIsSimulationDisabled();
        SetItemSimulation(m_Item,true);
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
        bool itemMode = enabled && m_Item != null;
        array<string> names = {"MoveStep","AngleStep","Ground"};
        foreach (string name : names)
        {
            Widget control = m_Root.FindAnyWidget(name);
            if (control) control.Enable(enabled);
        }
        array<string> itemControls = {"AngleStep","Ground"};
        foreach (string itemControl : itemControls) m_Root.FindAnyWidget(itemControl).Enable(itemMode);
        m_ItemsList.Show(false);
        m_AnchorsList.Show(false);
        for (int axis = 0; axis < 3; axis++)
        {
            m_PosFields[axis].Enable(enabled);
            m_RotFields[axis].Enable(itemMode);
            m_Root.FindAnyWidget("PosReset"+axis.ToString()).Enable(enabled);
            m_Root.FindAnyWidget("RotReset"+axis.ToString()).Enable(itemMode);
            m_Root.FindAnyWidget("PosMinus"+axis.ToString()).Enable(enabled);
            m_Root.FindAnyWidget("PosPlus"+axis.ToString()).Enable(enabled);
            m_Root.FindAnyWidget("RotMinus"+axis.ToString()).Enable(itemMode);
            m_Root.FindAnyWidget("RotPlus"+axis.ToString()).Enable(itemMode);
        }
        ResizePanel();
        UpdateToolbar();
    }

    protected bool ToolbarPoint(vector point)
    {
        if (!m_Toolbar || !m_Toolbar.IsVisible()) return false;
        float x,y,width,height;
        m_Toolbar.GetScreenPos(x,y);
        m_Toolbar.GetScreenSize(width,height);
        return point[0] >= x && point[0] < x+width && point[1] >= y && point[1] < y+height;
    }

    protected void UpdateToolbar()
    {
        if (!m_Toolbar) return;
        bool selected = SelectedObject() != null && m_Editing && !m_PlayerMode;
        m_Toolbar.FindAnyWidget("MoveMode").Show(selected);
        m_Toolbar.FindAnyWidget("RotateMode").Show(selected);
        m_Toolbar.FindAnyWidget("MoveMode").Enable(selected);
        m_Toolbar.FindAnyWidget("RotateMode").Enable(selected && m_Item != null);
        m_Toolbar.FindAnyWidget("Export").Enable(selected && m_Item != null);
        m_Toolbar.FindAnyWidget("SceneFocus").Enable(m_Anchor != null);
        m_Toolbar.FindAnyWidget("SceneExport").Enable(m_Anchor != null);
        m_Toolbar.FindAnyWidget("CameraMode").Enable(m_Booted && !m_PlayerMode);
        string cameraLabel = IOTL.T("CAMERA_FLIGHT");
        if (!m_Pointer) cameraLabel = IOTL.T("CAMERA_CURSOR");
        ButtonWidget.Cast(m_Toolbar.FindAnyWidget("CameraMode")).SetText(cameraLabel);
        m_Toolbar.FindAnyWidget("MoveModeActive").Show(selected && !m_RotateMode);
        m_Toolbar.FindAnyWidget("RotateModeActive").Show(selected && m_RotateMode);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float margin = 20*m_PanelScale;
        float width = Math.Max(1,screenWidth - margin*2);
        float available = width/m_PanelScale;
        float x = 8;
        float y = 8;
        array<string> names = {"MoveMode","RotateMode","CameraMode","SceneFocus","PlayerMode","Export","SceneExport"};
        array<float> widths = {156,156,160,160,156,184,160};
        for (int i = 0; i < names.Count(); i++)
        {
            Widget control = m_Toolbar.FindAnyWidget(names[i]);
            if (!control.IsVisible()) continue;
            if (x > 8 && x+widths[i] > available - 8) { x = 8; y = y+40; }
            control.SetPos(x*m_PanelScale,y*m_PanelScale);
            control.SetScreenSize(widths[i]*m_PanelScale,32*m_PanelScale);
            x = x+widths[i]+8;
        }
        float height = (y+40)*m_PanelScale;
        m_Toolbar.SetScreenPos(margin,margin);
        m_Toolbar.SetScreenSize(width,height);
        if (!m_Browser || !m_CreatedTray) return;
        float top = margin+height+12*m_PanelScale;
        if (m_ChromeWidth != screenWidth || m_ChromeHeight != screenHeight || Math.AbsFloat(top - m_ChromeTop) > 0.1)
        {
            float leftX,leftY,rightX,rightY;
            m_Browser.Root().GetScreenPos(leftX,leftY);
            m_Root.GetScreenPos(rightX,rightY);
            m_Browser.Root().SetScreenPos(leftX,top);
            m_Root.SetScreenPos(rightX,top);
            m_CreatedTray.Position(m_Browser.Root());
            m_Browser.FitAbove(m_CreatedTray.Root());
            m_ChromeWidth = screenWidth;
            m_ChromeHeight = screenHeight;
            m_ChromeTop = top;
            UpdateViewport();
        }
    }

    protected void ResizePanel()
    {
        bool selected = SelectedObject() != null;
        bool itemMode = m_Item != null;
        bool showAngles = selected && itemMode && m_RotateMode;
        bool showPosition = selected && !showAngles;
        m_Root.FindAnyWidget("PositionTitle").Show(showPosition);
        m_Root.FindAnyWidget("RotationTitle").Show(showAngles);
        m_Root.FindAnyWidget("FineToggle").Show(selected);
        for (int axis = 0; axis < 3; axis++)
        {
            string suffix = axis.ToString();
            m_PosFields[axis].Show(showPosition);
            m_RotFields[axis].Show(showAngles);
            m_Root.FindAnyWidget("PosLabel"+suffix).Show(showPosition);
            m_Root.FindAnyWidget("RotLabel"+suffix).Show(showAngles);
            m_Root.FindAnyWidget("PosAxis"+suffix).Show(showPosition);
            m_Root.FindAnyWidget("RotAxis"+suffix).Show(showAngles);
            m_Root.FindAnyWidget("PosReset"+suffix).Show(showPosition);
            m_Root.FindAnyWidget("RotReset"+suffix).Show(showAngles);
            m_Root.FindAnyWidget("FinePosAxis"+suffix).Show(showPosition);
            m_Root.FindAnyWidget("PosMinus"+suffix).Show(showPosition);
            m_Root.FindAnyWidget("PosPlus"+suffix).Show(showPosition);
            m_Root.FindAnyWidget("FineRotAxis"+suffix).Show(showAngles);
            m_Root.FindAnyWidget("FineRotLabel"+suffix).Show(showAngles);
            m_Root.FindAnyWidget("RotMinus"+suffix).Show(showAngles);
            m_Root.FindAnyWidget("RotPlus"+suffix).Show(showAngles);
        }
        m_Root.FindAnyWidget("MoveStep").Show(showPosition);
        m_Root.FindAnyWidget("AngleStep").Show(showAngles);
        m_Root.FindAnyWidget("Ground").Show(showPosition && itemMode);
        float toggleY = 200;
        m_Root.FindAnyWidget("FineToggle").SetPos(16*m_PanelScale,toggleY*m_PanelScale);
        ButtonWidget.Cast(m_Root.FindAnyWidget("FineToggle")).SetState(m_FineOpen);
        string prefix = "+ ";
        if (m_FineOpen) prefix = "- ";
        ButtonText("FineToggle",prefix+IOTL.T("FINE_SETTINGS"));
        Widget finePanel = m_Root.FindAnyWidget("FinePanel");
        finePanel.Show(selected && m_FineOpen);
        float fineHeight = 64;
        if (showPosition && itemMode) fineHeight = 100;
        if (showAngles) fineHeight = 132;
        finePanel.SetPos(16*m_PanelScale,(toggleY+36)*m_PanelScale);
        finePanel.SetScreenSize(368*m_PanelScale,fineHeight*m_PanelScale);
        float footerY = toggleY+40;
        if (m_FineOpen) footerY = footerY+fineHeight+10;
        if (!selected) footerY = 44;
        m_Status.SetPos(16*m_PanelScale,footerY*m_PanelScale);
        m_Debug.SetPos(16*m_PanelScale,(footerY+64)*m_PanelScale);
        m_Debug.Show(m_ShowDebug);
        float height = footerY+64;
        if (m_ShowDebug) height = height+72;
        m_Root.SetScreenSize(400*m_PanelScale,height*m_PanelScale);
        LayoutValueRows();
    }

    protected void LayoutValueRows()
    {
        float panelX,panelY,panelWidth,panelHeight;
        m_Root.GetScreenPos(panelX,panelY);
        m_Root.GetScreenSize(panelWidth,panelHeight);
        for (int kind = 0; kind < 2; kind++)
        {
            array<EditBoxWidget> fields = m_PosFields;
            string prefix = "PosReset";
            if (kind == 1) { fields = m_RotFields; prefix = "RotReset"; }
            float textWidth = 0;
            foreach (EditBoxWidget field : fields)
            {
                m_NumberMeasure.SetText(field.GetText());
                int measuredWidth,measuredHeight;
                m_NumberMeasure.GetTextSize(measuredWidth,measuredHeight);
                textWidth = Math.Max(textWidth,measuredWidth);
            }
            float firstX,firstY;
            fields[0].GetScreenPos(firstX,firstY);
            float width = Math.Max(64*m_PanelScale,textWidth+10*m_PanelScale);
            width = Math.Min(width,panelWidth - (firstX - panelX) - 46*m_PanelScale);
            for (int axis = 0; axis < fields.Count(); axis++)
            {
                float x,y,currentWidth,height;
                fields[axis].GetScreenPos(x,y);
                fields[axis].GetScreenSize(currentWidth,height);
                if (Math.AbsFloat(currentWidth - width) > 0.1) fields[axis].SetScreenSize(width,height);
                Widget reset = m_Root.FindAnyWidget(prefix+axis.ToString());
                float resetX,resetY;
                reset.GetPos(resetX,resetY);
                float nextX = x - panelX+width+4*m_PanelScale;
                if (Math.AbsFloat(resetX - nextX) > 0.1) reset.SetPos(nextX,resetY);
            }
        }
    }

    void ToggleFineSettings()
    {
        if (!SelectedObject()) return;
        m_FineOpen = !m_FineOpen;
        m_HeldButton = null;
        m_SuppressClick = null;
        ResizePanel();
    }

    void DeselectItem()
    {
        m_CharacterFocused = false;
        GetGizmoApi().DeselectTracker(this);
        if (m_Item && m_Editing)
        {
            SetItemSimulation(m_Item,m_WasSimulationDisabled);
            PrintToRPT("[PROXY SELECTION] Cleared " + m_Item.GetType() + "; restored simulation disabled=" + m_WasSimulationDisabled.ToString());
        }
        m_MoveTarget = null;
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
        if (!GetGame().GetPlayer() || !m_Browser || !m_CreatedTray || !m_Viewport || !m_Viewport.Ready()) return false;
        RefreshObjects();
        DeselectItem();
        EnterEditor();
        SceneStatus(IOTL.T("START_HINT"));
        PrintToRPT("[PROXY TOOL V2] Editor ready: camera active, no item selected; loose items=" + m_Items.Count().ToString());
        return true;
    }

    protected bool PanelPoint(vector point)
    {
        if (AnchorReplacementPending()) return true;
        if (ErrorContains(point)) return true;
        if (m_Browser && m_Browser.Contains(point)) return true;
        if (m_CreatedTray && m_CreatedTray.Contains(point)) return true;
        if (ToolbarPoint(point)) return true;
        if (!m_Root.IsVisible()) return false;
        float x,y,width,height;
        m_Root.GetScreenPos(x,y);
        m_Root.GetScreenSize(width,height);
        return point[0] >= x && point[0] <= x+width && point[1] >= y && point[1] <= y+height;
    }

    protected void UpdateViewport()
    {
        if (!m_Viewport || !m_Browser || !m_CreatedTray) return;
        m_Viewport.Update(m_Browser.Root(),m_Root,m_CreatedTray.Root(),m_Toolbar,!m_PlayerMode);
        PositionError();
        PositionReplacement();
    }

    protected bool WorldPoint(vector point)
    {
        return !m_PlayerMode && m_Viewport && m_Viewport.Contains(point) && !PanelPoint(point);
    }

    protected bool EditorWidget(Widget widget)
    {
        while (widget)
        {
            if (widget == m_Root || widget == m_Toolbar || widget == m_ErrorRoot || widget == m_ReplaceRoot || widget == m_Browser.Root() || widget == m_CreatedTray.Root()) return true;
            widget = widget.GetParent();
        }
        return false;
    }

    protected bool WorldMouse()
    {
        int x,y;
        GetMousePos(x,y);
        return WorldPoint(Vector(x,y,0)) && !EditorWidget(GetWidgetUnderCursor());
    }

    protected void CancelWorldGesture()
    {
        m_ClickPending = false;
        m_ClickReleased = false;
        m_WorldDragCancelled = true;
    }

    protected bool BeginWorldGesture(vector point)
    {
        if (!WorldPoint(point)) { CancelWorldGesture(); return false; }
        m_ClickStart = point;
        m_ClickPending = true;
        m_ClickReleased = false;
        m_NativeGesture = false;
        m_WorldDragCancelled = false;
        return true;
    }

    protected bool BeginCatalogPress(vector point)
    {
        if (m_PlayerMode || AnchorReplacementPending() || !m_Pointer || !m_Browser.CatalogListPoint(point)) return false;
        if (m_Browser.ItemsMode() && !m_Anchor) { ReportError(IOTL.T("ANCHOR_REQUIRED")); return false; }
        CancelWorldGesture();
        m_Browser.HideHoverPreview();
        m_CatalogPressed = true;
        m_CatalogDragging = false;
        m_CatalogStart = point;
        m_CatalogClass = "";
        m_CatalogItems = m_Browser.ItemsMode();
        UpdateGizmo();
        return true;
    }

    protected void CancelCatalogDrag()
    {
        bool restore = m_CatalogPressed;
        m_CatalogPressed = false;
        m_CatalogDragging = false;
        m_CatalogClass = "";
        if (m_CatalogDragRoot) m_CatalogDragRoot.Show(false);
        if (restore) UpdateGizmo();
    }

    protected bool DropSurface(vector point, out vector position, out vector normal)
    {
        if (!WorldPoint(point)) return false;
        vector from = GetGame().GetCurrentCameraPosition();
        vector to = from + PointerRay(point)*100;
        int component;
        set<Object> results = new set<Object>;
        normal = vector.Zero;
        if (!DayZPhysics.RaycastRV(from,to,position,normal,component,results,null,GetGame().GetPlayer(),true)) return false;
        if (normal.Length() < 0.1) normal = GetGame().SurfaceGetNormal(position[0],position[2]);
        normal.Normalize();
        return true;
    }

    protected void UpdateCatalogDrag(vector point)
    {
        if (!m_CatalogPressed) return;
        if (m_Browser.ItemsMode() != m_CatalogItems) { CancelCatalogDrag(); return; }
        if (!m_CatalogDragging)
        {
            if (vector.Distance(m_CatalogStart,point) < Math.Max(6,6*m_PanelScale)) return;
            // Read after the list processes its press/selection notification.
            m_CatalogClass = m_Browser.SelectedDragClass();
            if (m_CatalogClass == "") { CancelCatalogDrag(); return; }
            m_CatalogDragging = true;
            m_CatalogDragName.SetText(m_CatalogClass);
        }
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float width,height;
        m_CatalogDragRoot.GetScreenSize(width,height);
        m_CatalogDragRoot.SetScreenPos(Math.Clamp(point[0]+16,0,Math.Max(0,screenWidth-width)),Math.Clamp(point[1]+20,0,Math.Max(0,screenHeight-height)));
        vector hit,normal;
        if (DropSurface(point,hit,normal))
        {
            if (m_CatalogItems) m_CatalogDragHint.SetText(IOTL.T("ITEM_DROP_READY"));
            else if (ExistingSceneAnchor()) m_CatalogDragHint.SetText(IOTL.T("ANCHOR_DROP_REPLACE"));
            else m_CatalogDragHint.SetText(IOTL.T("ANCHOR_DROP_READY"));
            m_CatalogDragHint.SetColor(ARGB(255,130,230,150));
        }
        else
        {
            m_CatalogDragHint.SetText(IOTL.T("ITEM_DROP_INVALID"));
            m_CatalogDragHint.SetColor(ARGB(255,240,195,115));
        }
        m_CatalogDragRoot.Show(true);
    }

    protected bool FinishCatalogDrag(vector point, bool worldTarget)
    {
        if (!m_CatalogPressed) return false;
        // A fast gesture can press, move and release between two frame polls.
        UpdateCatalogDrag(point);
        bool dragged = m_CatalogDragging;
        string classname = m_CatalogClass;
        bool itemMode = m_CatalogItems;
        vector hit,normal;
        bool valid = dragged && worldTarget && DropSurface(point,hit,normal);
        CancelCatalogDrag();
        if (!dragged) return false;
        if (!valid) { SceneStatus(IOTL.T("ITEM_DROP_CANCELLED")); return false; }
        SetFocus(null);
        return SpawnSceneClass(classname,itemMode,true,hit,normal);
    }

    protected bool TogglePointerAt(vector point)
    {
        if (m_Pointer && !WorldPoint(point))
        {
            Status(IOTL.T("WORLD_FLIGHT_HINT"));
            return false;
        }
        SetPointer(!m_Pointer);
        return true;
    }

    protected bool ToggleToolbarCamera()
    {
        if (!m_Booted || m_PlayerMode || !GetGame().IsAppActive() || GetGame().GetUIManager().GetMenu()) return false;
        UpdateViewport();
        if (!m_Viewport || !m_Viewport.IsVisible()) return false;
        // This explicit action works from the toolbar; the F1 key keeps its
        // existing requirement to start flight from inside the world area.
        return TogglePointerAt(m_Viewport.Center());
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
        if (!WorldPoint(point)) return;
        ItemBase item = ItemBase.Cast(PointerObject(point));
        if (!SelectItem(item)) DeselectItem();
        RefreshObjects();
    }

    void MousePress(int button)
    {
        if (button != MouseState.LEFT || !m_Booted || m_PlayerMode || AnchorReplacementPending() || !m_Pointer || m_ClickPending || m_CatalogPressed || !GetGame().IsAppActive() || GetGame().GetUIManager().GetMenu()) return;
        int x,y;
        GetMousePos(x,y);
        vector point = Vector(x,y,0);
        if (m_Browser.CatalogListPoint(point)) { BeginCatalogPress(point); return; }
        if (!WorldMouse()) { CancelWorldGesture(); return; }
        SetFocus(null);
        BeginWorldGesture(point);
    }

    void MouseRelease(int button)
    {
        if (button != MouseState.LEFT) return;
        if (m_CatalogPressed)
        {
            int dragX,dragY;
            GetMousePos(dragX,dragY);
            vector dropPoint = Vector(dragX,dragY,0);
            bool worldTarget = WorldPoint(dropPoint) && GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu();
            FinishCatalogDrag(dropPoint,worldTarget);
            return;
        }
        if (!m_ClickPending || m_ClickReleased) return;
        int x,y;
        GetMousePos(x,y);
        m_ClickEnd = Vector(x,y,0);
        if (!WorldMouse()) { CancelWorldGesture(); return; }
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
        bool flying = m_Booted && !m_PlayerMode && !m_Pointer && m_Viewport && m_Viewport.IsVisible() && camera && camera.IsActive() && GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu();
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
        UpdateViewport();
        // MissionGameplay can update HUD visibility while menus open or close.
        if (m_Booted && !m_PlayerMode) SetPlayerHudHidden(true);
        UpdateFlightCamera(timeslice);
        if (!m_Booted || m_PlayerMode || !GetGame().IsAppActive() || GetGame().GetUIManager().GetMenu())
        {
            CancelWorldGesture();
            CancelCatalogDrag();
            m_MouseWasDown = false;
            return;
        }
        if (m_Pointer)
        {
            bool world = WorldMouse();
            m_Viewport.SetActive(world);
            if (!world && m_ClickPending && !m_ClickReleased) CancelWorldGesture();
            bool gameFocus = world && !m_CatalogPressed;
            if (!gameFocus && GetGame().GetInput().HasGameFocus()) GetGame().GetInput().ChangeGameFocus(1);
            else if (gameFocus && !GetGame().GetInput().HasGameFocus()) GetGame().GetInput().ResetGameFocus();
        }
        else m_Viewport.SetActive(true);
        bool down = (GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK) != 0;
        if (down && !m_MouseWasDown) MousePress(MouseState.LEFT);
        if (!down && m_MouseWasDown) MouseRelease(MouseState.LEFT);
        m_MouseWasDown = down;
        if (m_CatalogPressed)
        {
            int dragX,dragY;
            GetMousePos(dragX,dragY);
            UpdateCatalogDrag(Vector(dragX,dragY,0));
        }
        if (m_ClickPending && m_ClickReleased && GetGame().GetTime() - m_ReleaseTime >= 35)
        {
            bool select = !m_NativeGesture && !m_WorldDragCancelled && WorldPoint(m_ClickStart) && WorldPoint(m_ClickEnd) && vector.Distance(m_ClickStart,m_ClickEnd) < 5;
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
            if (m_PlayerSimulationPending) m_PlayerWasDisabled = m_PlayerSimulationRequested;
            SetPlayerSimulation(player,true);
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
        m_Toolbar.Show(true);
        m_Browser.Show(true);
        m_CreatedTray.Position(m_Browser.Root());
        m_CreatedTray.Show(true);
        UpdateToolbar();
        UpdateViewport();
        m_ModeHint.Show(false);
        SetPointer(true);
        RefreshObjects();
        DeselectItem();
    }

    void EnterPlayer()
    {
        if (m_PlayerMode) return;
        ClearError();
        CancelCatalogDrag();
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
        if (player) SetPlayerSimulation(player,m_PlayerWasDisabled);
        m_PlayerMode = true;
        m_Pointer = false;
        m_ClickPending = false;
        m_Root.Show(false);
        m_Toolbar.Show(false);
        m_Browser.Show(false);
        m_CreatedTray.Show(false);
        m_Viewport.Show(false);
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
        CancelCatalogDrag();
        m_HeldButton = null;
        CancelWorldGesture();
        m_SkipLookFrames = 2;
        if (pointer) m_SpeedRoot.Show(false);
        else { ShowCameraMultiplier(); if (m_Browser) m_Browser.HideHoverPreview(); }
        UpdateToolbar();
    }

    protected void UpdateGizmo()
    {
        GizmoApi api = GetGizmoApi();
        if (!api) return;
        api.DeselectTracker(this);
        if (!m_PlayerMode && !AnchorReplacementPending() && !m_CatalogPressed && m_GizmoEnabled && SelectedObject() && m_Editing)
        {
            api.SelectUser(this);
            if (m_RotateMode) api.SetTransformMode(GizmoTransformMode.ROTATE);
            else api.SetTransformMode(GizmoTransformMode.MOVE);
            api.SetSpaceMode(GizmoSpaceMode.WORLD);
        }
        if (m_GizmoEnabled) ButtonText("Gizmo", IOTL.T("GIZMO_ON"));
        else ButtonText("Gizmo", IOTL.T("GIZMO_OFF"));
        ResizePanel();
        UpdateToolbar();
    }

    bool Gizmo_IsSupported() { return !AnchorReplacementPending() && m_Editing && SelectedObject() != null; }
    bool Gizmo_IsAllowedTransformMode(GizmoTransformMode mode) { return mode == GizmoTransformMode.MOVE || (m_Item != null && mode == GizmoTransformMode.ROTATE); }
    bool Gizmo_IsAllowedSpaceMode(GizmoSpaceMode mode) { return true; }
    void Gizmo_GetWorldTransform(vector transform[4]) { Object target = SelectedObject(); if (target) target.GetTransform(transform); }
    void Gizmo_SetWorldTransform(vector transform[4], bool finalize)
    {
        if (!GetGame().IsAppActive() || GetGame().GetUIManager().GetMenu() || EditorWidget(GetWidgetUnderCursor()))
        {
            CancelWorldGesture();
            return;
        }
        int x,y;
        GetMousePos(x,y);
        ApplyGizmoTransformAt(transform,finalize,Vector(x,y,0));
    }

    protected bool ApplyGizmoTransformAt(vector transform[4], bool finalize, vector point)
    {
        if (m_PlayerMode || !m_Pointer || m_CatalogPressed || !SelectedObject() || !m_Editing || m_WorldDragCancelled) return false;
        if (!WorldPoint(point)) { CancelWorldGesture(); return false; }
        if (m_ClickPending) m_NativeGesture = true;
        if (m_MoveTarget)
        {
            // Scene objects support translation only: preserve the original
            // rotation and scale even if a caller supplies another basis.
            if (!MoveSceneTarget(transform[3])) return false;
        }
        else m_Item.SetTransform(transform);
        if (finalize) { m_DirtyInputs = false; SyncFields(); }
        return true;
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
        if (!SelectedObject() || !m_Editing) return;
        if (m_MoveTarget)
        {
            if (rotate) return;
            vector worldPosition = m_MoveTarget.GetPosition();
            float worldFactor = direction;
            if (fine) worldFactor *= 0.1;
            worldPosition[axis] = worldPosition[axis]+MoveStep()*worldFactor;
            if (MoveSceneTarget(worldPosition)) { m_DirtyInputs = false; SyncFields(); }
            return;
        }
        if (!m_Anchor) return;
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
        if (m_MoveTarget)
        {
            vector worldPosition;
            for (int worldAxis = 0; worldAxis < 3; worldAxis++)
            {
                string number = m_PosFields[worldAxis].GetText();
                if (!ValidNumber(number)) { ReportError(IOTL.T("INVALID_NUMBER")); return false; }
                number.Replace(",", ".");
                worldPosition[worldAxis] = number.ToFloat();
            }
            if (!MoveSceneTarget(worldPosition)) return false;
            m_DirtyInputs = false;
            SyncFields();
            Status(IOTL.T("POSE_APPLIED"));
            return true;
        }
        if (!m_Item || !m_Anchor) return false;
        vector position;
        vector angles;
        for (int i = 0; i < 3; i++)
        {
            string p = m_PosFields[i].GetText();
            string r = m_RotFields[i].GetText();
            if (!ValidNumber(p) || !ValidNumber(r))
            {
                ReportError(IOTL.T("INVALID_NUMBER"));
                return false;
            }
            p.Replace(",", ".");
            r.Replace(",", ".");
            position[i] = p.ToFloat();
            angles[i] = r.ToFloat();
            if (Math.AbsFloat(position[i]) > 100 || Math.AbsFloat(angles[i]) > 3600)
            {
                ReportError(IOTL.T("NUMBER_LIMIT"));
                return false;
            }
        }
        SetProxyPose(position, angles);
        Status(IOTL.T("POSE_APPLIED"));
        return true;
    }

    // Keep the text and caret in the edited field while updating the actual pose.
    protected bool ApplyEditedField(EditBoxWidget field, bool rotate, int axis, bool finished)
    {
        if (!SelectedObject() || !m_Editing || m_PlayerMode || (rotate && !m_Item)) return false;
        string number = field.GetText();
        m_DirtyInputs = true;
        if (!ValidNumber(number))
        {
            if (finished) ReportError(IOTL.T("INVALID_NUMBER"));
            return false;
        }
        number.Replace(",", ".");
        float value = number.ToFloat();
        float limit = 100;
        if (rotate) limit = 3600;
        if (m_MoveTarget) limit = 100000;
        if (Math.AbsFloat(value) > limit)
        {
            if (m_MoveTarget) ReportError(IOTL.T("WORLD_NUMBER_LIMIT"));
            else ReportError(IOTL.T("NUMBER_LIMIT"));
            return false;
        }
        if (m_MoveTarget)
        {
            vector worldPosition = m_MoveTarget.GetPosition();
            worldPosition[axis] = value;
            if (!MoveSceneTarget(worldPosition)) return false;
        }
        else
        {
            vector position = ProxyPosition();
            vector angles = ProxyAngles();
            if (rotate) angles[axis] = value;
            else position[axis] = value;
            SetProxyPose(position,angles,false);
        }
        m_DirtyInputs = false;
        if (finished) SyncFields();
        else SyncFields(field);
        Status(IOTL.T("POSE_APPLIED"));
        return true;
    }

    protected void SyncFields(EditBoxWidget preserve = null)
    {
        if (m_MoveTarget)
        {
            if (m_DirtyInputs) return;
            m_UpdatingUI = true;
            vector worldPosition = m_MoveTarget.GetPosition();
            for (int worldAxis = 0; worldAxis < 3; worldAxis++)
            {
                if (m_PosFields[worldAxis] != preserve) m_PosFields[worldAxis].SetText(FieldNumber(worldPosition[worldAxis]));
                m_RotFields[worldAxis].SetText("");
            }
            m_LastPos = worldPosition;
            LayoutValueRows();
            m_UpdatingUI = false;
            return;
        }
        if (!m_Item || !m_Anchor || m_DirtyInputs) return;
        m_UpdatingUI = true;
        vector position = ProxyPosition();
        vector angles = ProxyAngles();
        for (int i = 0; i < 3; i++)
        {
            if (m_PosFields[i] != preserve) m_PosFields[i].SetText(FieldNumber(position[i]));
            if (m_RotFields[i] != preserve) m_RotFields[i].SetText(FieldNumber(angles[i]));
        }
        m_LastPos = position;
        m_LastAngles = angles;
        LayoutValueRows();
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
        if (m_MoveTarget) { if (!MoveSceneTarget(m_Original[3])) return; }
        else if (m_Item) m_Item.SetTransform(m_Original);
        else return;
        m_DirtyInputs = false;
        SyncFields();
        Status(IOTL.T("POSE_RESET"));
    }

    protected void ResetComponent(bool rotate, int axis)
    {
        if (!SelectedObject() || !m_Editing || m_PlayerMode || (rotate && !m_Item)) return;
        if (m_MoveTarget)
        {
            vector worldPosition = m_MoveTarget.GetPosition();
            vector initialPosition = m_Original[3];
            worldPosition[axis] = initialPosition[axis];
            if (!MoveSceneTarget(worldPosition)) return;
        }
        else
        {
            vector position = ProxyPosition();
            vector angles = ProxyAngles();
            if (rotate) angles[axis] = m_OriginalProxyAngles[axis];
            else position[axis] = m_OriginalProxyPosition[axis];
            SetProxyPose(position,angles,false);
        }
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
        if (SelectedObject() && m_DirtyInputs && !ApplyFields()) return false;
        string folder = "$profile:ProxyPlacement";
        MakeDirectory(folder);
        folder = folder+"/"+m_Anchor.GetType();
        MakeDirectory(folder);
        string path = folder+"/"+m_RunTag+"_scene_"+m_ActiveScene.Id.ToString()+".xml";
        FileHandle file = OpenFile(path,FileMode.WRITE);
        if (!file) { ReportError(IOTL.T("ANCHOR_XML_FAILED")); return false; }
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
        if (!file) { ReportError(IOTL.T("XML_FAILED")); return false; }
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
        if (AnchorReplacementPending()) return false;
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
        if (AnchorReplacementPending())
        {
            if (w.GetName() == "ReplaceCancel") FinishAnchorReplacement(false);
            else if (w.GetName() == "ReplaceConfirm") FinishAnchorReplacement(true);
            return true;
        }
        Widget widget = w;
        if (widget == m_SuppressClick) { m_SuppressClick = null; return true; }
        if (NudgeButton(widget)) return true;
        string name = widget.GetName();
        if (name == "ErrorClose") { ClearError(); return true; }
        if (name == "FineToggle") { ToggleFineSettings(); return true; }
        if (name == "PlayerMode") { EnterPlayer(); return true; }
        if (name == "CameraMode") { ToggleToolbarCamera(); return true; }
        if (name == "SceneFocus") { FocusAnchor(); return true; }
        if (name == "SceneExport") { ExportAnchor(); return true; }
        if (name == "MoveMode") { if (SelectedObject()) { m_RotateMode = false; UpdateGizmo(); } return true; }
        if (name == "RotateMode") { if (m_Item) { m_RotateMode = true; UpdateGizmo(); } return true; }
        if (name == "Ground") { Ground(); return true; }
        for (int axis = 0; axis < 3; axis++)
        {
            if (name == "PosReset"+axis.ToString()) { ResetComponent(false,axis); return true; }
            if (name == "RotReset"+axis.ToString()) { ResetComponent(true,axis); return true; }
        }
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
        for (int axis = 0; axis < 3; axis++)
        {
            if (widget == m_PosFields[axis]) { ApplyEditedField(m_PosFields[axis],false,axis,finished); LayoutValueRows(); return true; }
            if (widget == m_RotFields[axis]) { ApplyEditedField(m_RotFields[axis],true,axis,finished); LayoutValueRows(); return true; }
        }
        return false;
    }

    override bool OnFocusLost(Widget w, int x, int y)
    {
        if (m_UpdatingUI || AnchorReplacementPending() || !SelectedObject()) return false;
        for (int axis = 0; axis < 3; axis++)
        {
            if (w != m_PosFields[axis] && w != m_RotFields[axis]) continue;
            bool rotate = w == m_RotFields[axis];
            if (!ApplyEditedField(EditBoxWidget.Cast(w),rotate,axis,true))
            {
                m_DirtyInputs = false;
                SyncFields();
            }
            return true;
        }
        return false;
    }

    void HandleKey(int key)
    {
        if (AnchorReplacementPending())
        {
            if (key == KeyCode.KC_ESCAPE) FinishAnchorReplacement(false);
            return;
        }
        if (GetGame().GetUIManager().GetMenu() != null) return;
        if (key == KeyCode.KC_F4)
        {
            if (m_PlayerMode) EnterEditor();
            else EnterPlayer();
            return;
        }
        if (m_PlayerMode) return;
        if (m_CatalogPressed) { CancelCatalogDrag(); return; }
        if (key == KeyCode.KC_F1)
        {
            int x,y;
            GetMousePos(x,y);
            if (!m_Pointer || !EditorWidget(GetWidgetUnderCursor())) TogglePointerAt(Vector(x,y,0));
            else Status(IOTL.T("WORLD_FLIGHT_HINT"));
            return;
        }
        if (key == KeyCode.KC_F9) { Reset(); return; }
        if (key == KeyCode.KC_F10) { Export(); return; }
        if (key == KeyCode.KC_F11)
        {
            m_ShowDebug = !m_ShowDebug;
            m_Debug.Show(m_ShowDebug);
            ResizePanel();
            return;
        }
        if (!SelectedObject() || EditBoxWidget.Cast(GetFocus())) return;
        if (key == KeyCode.KC_F7)
        {
            m_RotateMode = false;
            UpdateGizmo();
            Status(IOTL.T("MOVE_KEYS")+"\n"+IOTL.T("MOVE_KEYS_HEIGHT")+"\n"+IOTL.T("FINE_KEYS"));
            return;
        }
        if (key == KeyCode.KC_F8)
        {
            if (m_Item)
            {
                m_RotateMode = true;
                UpdateGizmo();
                Status(IOTL.T("ROTATE_KEYS")+"\n"+IOTL.T("ROTATE_KEYS_YAW")+"\n"+IOTL.T("FINE_KEYS"));
            }
            return;
        }
        if (!m_Pointer || !WorldMouse()) return;
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
        if (!TestCheck(m_CreatedTray.RowCount() == 1 && m_CreatedTray.Count() == 0 && m_CreatedTray.AnchorCount() == 0 && m_CreatedTray.RowObject(m_CreatedTray.CharacterRow()) == testPlayer && m_CreatedTray.IsVisible(), "scene list initially contains the character without an anchor")) return;
        if (!SelfTestViewportLayout()) return;
        if (!TestCheck(m_Toolbar.IsVisible() && !m_Toolbar.FindAnyWidget("MoveMode").IsVisible() && !m_Toolbar.FindAnyWidget("RotateMode").IsVisible() && !Export() && !ExportAnchor(), "toolbar hides manipulation modes without selection and rejects export without an anchor")) return;
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
        if (!SelfTestItemPreview()) return;
        m_Browser.SetMode(true);
        m_Browser.Search("Hammer");
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestStartScene,250,false);
    }

    protected void SelfTestStartScene()
    {
        float listX,listY;
        m_Browser.Root().FindAnyWidget("SceneResults").GetScreenPos(listX,listY);
        if (!TestCheck(!BeginCatalogPress(Vector(listX+20,listY+20,0)) && !m_CatalogPressed && m_CreatedItems.Count() == 0, "item drag requires an active anchor without spawning anything")) return;
        m_Browser.SetMode(false);
        m_Browser.Search("Land_Wreck_hb01_aban1_blue");
        int wreckRow = m_Browser.ClassRow("Land_Wreck_hb01_aban1_blue");
        m_Browser.SelectCatalogItemRow(wreckRow);
        vector press = CatalogRowPoint(wreckRow);
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        vector ground = GetGame().GetPlayer().GetPosition()+"0 0 10";
        camera.SetPosition(ground+"8 8 -10");
        camera.LookAt(ground);
        vector drop = m_Viewport.Center();
        vector hit,normal;
        if (!TestCheck(DropSurface(drop,hit,normal) && BeginCatalogPress(press), "anchor catalog can start a ground drag without an existing anchor")) return;
        bool created = FinishCatalogDrag(drop,true);
        if (!TestCheck(created && m_Scenes.Count() == 1 && m_Anchor && !AnchorReplacementPending(), "first anchor drop creates one anchor without a replacement dialog")) return;
        vector actual = m_Anchor.GetPosition();
        PrintToRPT("[PROXY ANCHOR DROP] hit="+hit.ToString(false)+" actual="+actual.ToString(false)+" orientation="+m_Anchor.GetOrientation().ToString(false)+" scale="+m_Anchor.GetScale().ToString());
        if (!TestCheck(Math.AbsFloat(actual[0]-hit[0]) < 0.05 && Math.AbsFloat(actual[2]-hit[2]) < 0.05 && m_Anchor.GetOrientation().Length() < 0.001 && m_Anchor.GetScale() == 1, "anchor drop preserves horizontal hit coordinates and the CE transform constraints")) return;
        if (!TestCheck(SpawnSceneClass("HatchbackWheel",true), "runtime creation of wreck and wheel")) return;
        DeselectItem();
        RefreshObjects();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTest,1000,false);
    }

    protected bool SelfTestViewportLayout()
    {
        UpdateViewport();
        vector origin = m_Viewport.Origin();
        vector size = m_Viewport.Size();
        vector center = m_Viewport.Center();
        if (!TestCheck(m_Viewport.IsVisible() && size[0] > 64 && size[1] > 64 && WorldPoint(center), "world viewport has a visible usable center")) return false;
        float leftX,leftY,leftWidth,leftHeight,rightX,rightY,trayX,trayY,trayWidth,trayHeight;
        m_Browser.Root().GetScreenPos(leftX,leftY);
        m_Browser.Root().GetScreenSize(leftWidth,leftHeight);
        m_Root.GetScreenPos(rightX,rightY);
        m_CreatedTray.Root().GetScreenPos(trayX,trayY);
        m_CreatedTray.Root().GetScreenSize(trayWidth,trayHeight);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        if (!TestCheck(origin[0] > leftX+leftWidth && origin[0] > trayX+trayWidth && origin[0]+size[0] < rightX && origin[1]+size[1] > trayY+trayHeight && origin[1]+size[1] < screenHeight, "world viewport fits between side panels and reaches the bottom margin")) return false;
        vector leftPanel = Vector(leftX+5,leftY+5,0);
        if (!TestCheck(!WorldPoint(leftPanel) && !WorldPoint(Vector(rightX+5,rightY+5,0)) && !WorldPoint(Vector(trayX+trayWidth*0.5,trayY+5,0)), "all three editor panels are outside the world viewport")) return false;
        if (!TestCheck(!WorldPoint(Vector(leftX+5,origin[1]+size[1] - 5,0)) && !WorldPoint(Vector(origin[0]+5,screenHeight - 1,0)), "empty side and bottom margins cannot edit the world")) return false;
        if (!TestCheck(WorldPoint(origin) && !WorldPoint(Vector(origin[0] - 1,center[1],0)) && !WorldPoint(Vector(center[0],origin[1] - 1,0)) && !WorldPoint(Vector(origin[0]+size[0],center[1],0)) && !WorldPoint(Vector(center[0],origin[1]+size[1],0)), "world viewport rejects all four outer edges")) return false;
        m_Browser.Root().SetScreenPos(leftX+16,leftY);
        UpdateViewport();
        vector movedOrigin = m_Viewport.Origin();
        vector movedSize = m_Viewport.Size();
        bool followsLayout = Math.AbsFloat(movedOrigin[0] - origin[0] - 16) < 1 && Math.AbsFloat(movedOrigin[1]+movedSize[1] - origin[1] - size[1]) < 1;
        m_Browser.Root().SetScreenPos(leftX,leftY);
        m_CreatedTray.Root().SetScreenPos(trayX,trayY);
        UpdateViewport();
        if (!TestCheck(followsLayout, "world viewport follows live panel and tray geometry")) return false;
        m_CreatedTray.Root().SetScreenPos(trayX+24,trayY);
        UpdateViewport();
        vector sceneOrigin = m_Viewport.Origin();
        bool followsScene = Math.AbsFloat(sceneOrigin[0] - origin[0] - 24) < 1;
        m_CreatedTray.Root().SetScreenPos(trayX,trayY);
        UpdateViewport();
        if (!TestCheck(followsScene, "world viewport includes the live width of the left scene list")) return false;
        m_Browser.Root().SetScreenPos(rightX+100,leftY);
        UpdateViewport();
        bool overlapBlocked = !m_Viewport.IsVisible() && !WorldPoint(center);
        m_Browser.Root().SetScreenPos(leftX,leftY);
        UpdateViewport();
        if (!TestCheck(overlapBlocked && WorldPoint(center), "overlapping panels disable world input and recover after layout restore")) return false;
        if (!TestCheck(!TogglePointerAt(leftPanel) && m_Pointer, "F1 over editor panels does not enter flight")) return false;
        if (!TestCheck(TogglePointerAt(center) && !m_Pointer, "F1 inside world viewport enters flight")) return false;
        if (!TestCheck(TogglePointerAt(leftPanel) && m_Pointer, "F1 always returns from flight to cursor mode")) return false;
        return true;
    }

    protected bool SelfTestViewportGesture(ItemBase wheel)
    {
        vector center = m_Viewport.Center();
        vector origin = m_Viewport.Origin();
        vector outside = Vector(origin[0] - 1,center[1],0);
        vector original[4];
        vector moved[4];
        wheel.GetTransform(original);
        copyarray(moved,original);
        moved[3] = moved[3] + "0.2 0 0";
        if (!TestCheck(BeginWorldGesture(center) && ApplyGizmoTransformAt(moved,false,center) && vector.Distance(wheel.GetPosition(),moved[3]) < 0.001, "native gizmo callback applies transforms inside world viewport")) return false;
        if (!TestCheck(!ApplyGizmoTransformAt(original,false,outside) && vector.Distance(wheel.GetPosition(),moved[3]) < 0.001, "leaving world viewport freezes the current gizmo placement")) return false;
        if (!TestCheck(!ApplyGizmoTransformAt(original,true,center) && vector.Distance(wheel.GetPosition(),moved[3]) < 0.001, "cancelled gizmo drag cannot resume or finalize on reentry")) return false;
        PickPoint(outside);
        if (!TestCheck(m_Item == wheel && m_Editing, "outside world clicks preserve the selected item")) return false;
        if (!TestCheck(BeginWorldGesture(center) && ApplyGizmoTransformAt(original,true,center) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001, "new world gesture restores normal native gizmo editing")) return false;
        CancelWorldGesture();
        return true;
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
        string hammerName = m_Browser.ItemName("Hammer");
        string upperName = hammerName;
        upperName.ToUpper();
        m_Browser.Search("  "+upperName+"  ");
        if (!TestCheck(upperName != hammerName && m_Browser.ActivateRow("items/GEAR/TOOLS/Hammer") && m_Browser.SelectedDragClass() == "Hammer", "localized item search ignores letter case and surrounding spaces")) return false;
        string partialName = hammerName.SubstringUtf8(1,hammerName.LengthUtf8() - 2);
        m_Browser.Search(partialName);
        if (!TestCheck(m_Browser.ActivateRow("items/GEAR/TOOLS/Hammer") && m_Browser.FirstClass() == "Hammer", "partial localized item names reveal the matching catalog path")) return false;
        m_Browser.Search(m_Browser.ItemName("AK74"));
        bool localizedWeapon = m_Browser.ActivateRow("items/WEAPONS/FIREARMS/AK74");
        m_Browser.Search("aK74");
        if (!TestCheck(localizedWeapon && m_Browser.ActivateRow("items/WEAPONS/FIREARMS/AK74") && m_Browser.SelectedDragClass() == "AK74", "weapon search accepts both localized names and original classnames")) return false;
        string sharedName = m_Browser.ItemName("CargoPants_Grey");
        m_Browser.Search(sharedName);
        bool greySelected = m_Browser.ActivateRow("items/CLOTHING/PANTS/CargoPants_Grey") && m_Browser.SelectedDragClass() == "CargoPants_Grey";
        bool blackSelected = m_Browser.ActivateRow("items/CLOTHING/PANTS/CargoPants_Black") && m_Browser.SelectedDragClass() == "CargoPants_Black";
        if (!TestCheck(sharedName == m_Browser.ItemName("CargoPants_Black") && greySelected && blackSelected && m_Browser.MatchCount() >= 2 && m_Browser.ShownCount() == m_Browser.MatchCount(), "shared localized names preserve separate selectable item classes")) return false;
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
                    if (WorldPoint(screen) && PointerObject(screen) == wheel) hitWheel = true;
                }
            }
        }
        if (!TestCheck(hitWheel, "cursor ray hits wheel mesh")) return;
        PickPoint(screen);
        if (!TestCheck(m_Item == wheel && m_Editing && GetGizmoApi().GetCount() == 1, "cursor selection enables native gizmo")) return;
        if (!SelfTestViewportGesture(wheel)) return;
        if (!SelfTestErrors(wheel)) return;
        if (!SelfTestToolbar(wheel)) return;
        if (!SelfTestCompactProperties(wheel)) return;
        vector baseline = ProxyPosition();
        vector angles = ProxyAngles();
        Widget plus = m_Root.FindAnyWidget("PosPlus0");
        if (!m_FineOpen) ToggleFineSettings();
        OnMouseButtonDown(plus, 0, 0, 0);
        OnMouseButtonUp(plus, 0, 0, 0);
        OnClick(plus, 0, 0, 0);
        vector nudged = ProxyPosition();
        if (!TestCheck(Math.AbsFloat(nudged[0] - baseline[0] - 0.01) < 0.0002, "position control")) return;
        if (m_FineOpen) ToggleFineSettings();
        SetProxyPose(baseline, "10 20 30");
        if (!TestCheck(vector.Distance(ProxyAngles(), "10 20 30") < 0.001, "combined rotation")) return;
        SetProxyPose(baseline, angles);

        vector blank = m_Viewport.Origin();
        vector viewportCenter = m_Viewport.Center();
        blank[0] = viewportCenter[0];
        blank[1] = blank[1]+8;
        if (!TestCheck(ItemBase.Cast(PointerObject(blank)) == null, "empty screen sample")) return;
        PickPoint(blank);
        vector beforeNudge = wheel.GetPosition();
        Nudge(false,0,1);
        if (!TestCheck(!m_Item && !m_Editing && GetGizmoApi().GetCount() == 0 && vector.Distance(beforeNudge,wheel.GetPosition()) < 0.0001, "empty click clears selection and blocks movement")) return;
        SelectItem(wheel);
        OnClick(m_Toolbar.FindAnyWidget("PlayerMode"),0,0,0);
        if (!TestCheck(!m_Viewport.IsVisible() && !WorldPoint(m_Viewport.Center()), "character mode hides and disables world viewport")) return;
        if (!TestCheck(m_PlayerMode && !camera.IsActive() && !m_Item && GetGizmoApi().GetCount() == 0 && !m_Root.IsVisible() && !m_Toolbar.IsVisible() && !m_Browser.IsVisible() && !m_CreatedTray.IsVisible() && GetGame().GetInput().HasGameFocus(), "player mode restores camera and input and hides all panels")) return;
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
        if (!TestCheck(!m_PlayerMode && camera.IsActive() && !m_Item && GetGizmoApi().GetCount() == 0 && m_Root.IsVisible() && m_Toolbar.IsVisible() && m_Browser.IsVisible() && m_CreatedTray.IsVisible() && player.GetIsSimulationDisabled(), "return to editor without selection and restore all panels")) return;
        if (!TestCheck(PlayerHudRoot() && !PlayerHudRoot().IsVisible() && m_PlayerHudHidden, "return to editor hides character HUD again")) return;
        if (!TestCheck(m_Viewport.IsVisible() && WorldPoint(m_Viewport.Center()), "return to editor restores world viewport")) return;
        SelectItem(wheel);
        if (!TestCheck(vector.Distance(wheel.GetPosition(),placedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),placedOrientation) < 0.001, "editor return preserves current placement")) return;
        bool exported = Export();
        if (!TestCheck(exported, "context XML export")) return;
        Object firstAnchor = m_Anchor;
        vector firstPosition = wheel.GetPosition();
        if (!TestCheck(SelfTestLegacyAnchor("Land_Garage_Row_Small"), "legacy world anchor fixture registered for ownership regressions")) return;
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
        if (!TestCheck(m_CreatedTray.Count() == 3 && m_CreatedTray.AnchorCount() == 2 && m_CreatedTray.RowCount() == 6, "scene list contains the character anchors and created items")) return;
        if (!TestCheck(m_CreatedTray.List().GetSelectedRow() == m_CreatedTray.ItemRow(m_Item), "scene list marks the world-selected item")) return;
        int firstHeader = m_CreatedTray.AnchorRow(firstAnchor);
        int secondHeader = m_CreatedTray.AnchorRow(m_Scenes[1].Anchor);
        if (!TestCheck(m_CreatedTray.CharacterRow() == 0 && firstHeader == 1 && secondHeader == 2 && m_CreatedTray.ItemRow(m_CreatedItems[0]) == 3 && m_CreatedTray.ItemRow(m_CreatedItems[1]) == 4, "scene rows are flat and item order is independent of anchor grouping")) return;
        for (int extra = 0; extra < 3; extra++)
            if (!TestCheck(SpawnSceneClass("Hammer",true), "create duplicate-class item for scene list")) return;
        ItemBase lastItem = m_Item;
        if (!TestCheck(m_CreatedTray.Count() == 6 && m_CreatedTray.RowCount() == 9 && m_CreatedTray.List().GetNumItems() == 9, "scene list retains every row beyond the old four-item page size")) return;
        string firstLabel,lastLabel;
        m_CreatedTray.List().GetItemText(m_CreatedTray.ItemRow(m_CreatedItems[3]),0,firstLabel);
        m_CreatedTray.List().GetItemText(m_CreatedTray.ItemRow(lastItem),0,lastLabel);
        if (!TestCheck(firstLabel == "Hammer" && lastLabel == "Hammer", "duplicate item labels contain only the classname without IDs or indentation")) return;
        string anchorLabel,characterLabel;
        m_CreatedTray.List().GetItemText(m_CreatedTray.AnchorRow(firstAnchor),0,anchorLabel);
        m_CreatedTray.List().GetItemText(m_CreatedTray.CharacterRow(),0,characterLabel);
        if (!TestCheck(anchorLabel == firstAnchor.GetType() && characterLabel == IOTL.T("SCENE_CHARACTER"), "anchor and localized character labels are plain scene entries without IDs")) return;
        int otherRow = m_CreatedTray.ItemRow(m_CreatedItems[1]);
        m_CreatedTray.OnItemSelected(m_CreatedTray.List(),0,0,otherRow,0,-1,0);
        if (!TestCheck(m_Item == m_CreatedItems[1] && m_Anchor != firstAnchor && m_Editing && GetGizmoApi().GetCount() == 1 && m_CreatedTray.List().GetSelectedRow() == otherRow, "scene item click switches owner and selects the exact native gizmo target")) return;
        m_CreatedTray.ActivateRow(m_CreatedTray.ItemRow(lastItem));
        if (!TestCheck(m_Item == lastItem && m_Anchor == firstAnchor, "scene row selection distinguishes identical items across anchors")) return;
        int selectedRow = m_CreatedTray.List().GetSelectedRow();
        RefreshCreatedItems();
        if (!TestCheck(m_Item == lastItem && m_CreatedTray.List().GetSelectedRow() == selectedRow && m_CreatedTray.RowCount() == 9, "periodic scene list refresh preserves selection and all rows")) return;
        vector itemPosition = lastItem.GetPosition();
        m_CreatedTray.ActivateRow(m_CreatedTray.AnchorRow(m_Scenes[1].Anchor));
        if (!TestCheck(!m_Item && m_Editing && m_MoveTarget == m_Scenes[1].Anchor && m_Anchor == m_Scenes[1].Anchor && GetGizmoApi().GetCount() == 1 && m_CreatedTray.List().GetSelectedRow() == m_CreatedTray.AnchorRow(m_Anchor), "anchor row activates the anchor and its movement gizmo")) return;
        if (!TestCheck(vector.Distance(itemPosition,lastItem.GetPosition()) < 0.0001 && m_CreatedTray.Count() == 6, "selecting a scene anchor preserves item placement and scene membership")) return;
        if (!TestCheck(!m_CreatedTray.ActivateRow(-1) && !m_CreatedTray.ActivateRow(10000), "invalid scene rows cannot change the active anchor")) return;
        Man player = GetGame().GetPlayer();
        vector playerPosition = player.GetPosition();
        Object activeAnchor = m_Anchor;
        if (!TestCheck(m_CreatedTray.ActivateRow(m_CreatedTray.CharacterRow()) && m_CharacterFocused && !m_PlayerMode && !m_Item && m_MoveTarget == player && GetGizmoApi().GetCount() == 1 && FreeDebugCamera.GetInstance().IsActive(), "character row selects its movement gizmo while remaining in editor mode")) return;
        RefreshObjects();
        if (!TestCheck(m_CreatedTray.List().GetSelectedRow() == m_CreatedTray.CharacterRow() && m_Anchor == activeAnchor && vector.Distance(playerPosition,player.GetPosition()) < 0.0001 && vector.Distance(itemPosition,lastItem.GetPosition()) < 0.0001, "character focus survives refresh without moving scene entities or changing the anchor")) return;
        m_CreatedTray.ActivateRow(m_CreatedTray.ItemRow(lastItem));
        if (!TestCheck(m_Item == lastItem && !m_CharacterFocused && GetGizmoApi().GetCount() == 1, "item selection after character focus restores the exact native gizmo target")) return;
        TextWidget sceneTitle = TextWidget.Cast(m_CreatedTray.Root().FindAnyWidget("CreatedTitle"));
        int titleWidth,titleHeight;
        float titleSpaceWidth,titleSpaceHeight;
        sceneTitle.GetTextSize(titleWidth,titleHeight);
        sceneTitle.GetScreenSize(titleSpaceWidth,titleSpaceHeight);
        if (!TestCheck(IOTL.T("SCENE_OBJECTS_TITLE") == IOTL.T("SCENE_OBJECTS_TITLE_EMPTY") && titleWidth > 0 && titleWidth <= titleSpaceWidth+1, "scene title is localized and fits without an element counter")) return;
        float trayX,trayY,trayWidth,trayHeight;
        m_CreatedTray.Root().GetScreenPos(trayX,trayY);
        m_CreatedTray.Root().GetScreenSize(trayWidth,trayHeight);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float browserX,browserY,browserWidth,browserHeight;
        m_Browser.Root().GetScreenPos(browserX,browserY);
        m_Browser.Root().GetScreenSize(browserWidth,browserHeight);
        if (!TestCheck(Math.AbsFloat(trayX - browserX) < 1 && Math.AbsFloat(trayWidth - browserWidth) < 1 && trayY > browserY+browserHeight && trayY+trayHeight <= screenHeight && trayHeight < browserHeight*0.3, "compact scene list fits below the catalog in the left column")) return;
        if (!TestCheck(PanelPoint(Vector(trayX+20,trayY+20,0)) && !WorldPoint(Vector(trayX+20,trayY+20,0)), "scene list clicks stay outside the world editing area")) return;
        DeselectItem();
        if (!TestCheck(m_CreatedTray.List().GetSelectedRow() == m_CreatedTray.AnchorRow(m_Anchor) && GetGizmoApi().GetCount() == 0, "world deselection returns scene indication to the active anchor")) return;
        if (!SelfTestSceneMovement()) return;
        if (!SelfTestItemDrag()) return;
        m_TestPlayerPosition = GetGame().GetPlayer().GetPosition();
        if (!SelectSceneCharacter()) return;
        m_TestPlayerMovedPosition = m_TestPlayerPosition+"0.5 0 0.5";
        if (!MoveSceneTarget(m_TestPlayerMovedPosition)) return;
        EnterPlayer();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestSceneMovePlayerReturn,250,false);
    }

    protected void SelfTestSceneMovePlayerReturn()
    {
        Man player = GetGame().GetPlayer();
        if (!TestCheck(m_PlayerMode && !m_MoveTarget && !m_Editing && GetGizmoApi().GetCount() == 0 && !FreeDebugCamera.GetInstance().IsActive() && !player.GetIsSimulationDisabled() && !m_PlayerWasDisabled && GetGame().GetInput().HasGameFocus(), "F4 restores character simulation and controls after scene movement")) return;
        vector position = player.GetPosition();
        if (!TestCheck(Math.AbsFloat(position[0] - m_TestPlayerMovedPosition[0]) < 0.05 && Math.AbsFloat(position[2] - m_TestPlayerMovedPosition[2]) < 0.05, "character mode starts at the position set by the editor")) return;
        EnterEditor();
        player.SetPosition(m_TestPlayerPosition);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestMovementFinish,250,false);
    }

    protected void SelfTestMovementFinish()
    {
        if (!TestCheck(!m_PlayerMode && !SelectedObject() && GetGame().GetPlayer().GetIsSimulationDisabled() && m_CreatedTray.IsVisible() && GetGizmoApi().GetCount() == 0, "editor return clears the scene movement target and restores the scene list")) return;
        SelfTestAnchorDrag();
    }

    // Existing-world fixture for the older multi-owner bookkeeping tests.
    // User creation always goes through SpawnSceneClass's single-anchor guard.
    protected bool SelfTestLegacyAnchor(string classname)
    {
        vector position = m_Anchor.GetPosition()+"20 0 0";
        Object anchor = GetGame().CreateObjectEx(classname,position,ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD,RF_IGNORE);
        if (!anchor) return false;
        anchor.PlaceOnSurface();
        anchor.SetOrientation("0 0 0");
        SeparateAnchor(anchor);
        return SetAnchor(anchor);
    }

    protected void SelfTestAnchorDrag()
    {
        Object oldAnchor = m_Anchor;
        ItemBase oldItem = m_CreatedItems[0];
        SelectCreatedItem(oldItem);
        oldAnchor = m_Anchor;
        vector oldPosition = oldItem.GetPosition();
        int oldCount = m_CreatedItems.Count();
        int oldScenes = m_Scenes.Count();
        m_Browser.SetMode(false);
        m_Browser.Search("Land_Garage_Row_Small");
        int row = m_Browser.ClassRow("Land_Garage_Row_Small");
        m_Browser.SelectCatalogItemRow(row);
        vector press = CatalogRowPoint(row);
        vector drop = m_Viewport.Center();
        vector ground = oldAnchor.GetPosition()+"12 0 -12";
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        camera.SetPosition(ground+"8 8 -10");
        camera.LookAt(ground);
        vector hit,normal;
        if (!TestCheck(DropSurface(drop,hit,normal), "replacement drag finds a world surface")) return;
        BeginCatalogPress(press);
        UpdateCatalogDrag(drop);
        if (!TestCheck(m_CatalogDragging && !m_CatalogItems && m_CatalogClass == "Land_Garage_Row_Small" && GetGizmoApi().GetCount() == 0, "object leaf drag uses its exact class and suspends the selected gizmo")) return;
        FinishCatalogDrag(drop,false);
        if (!TestCheck(!AnchorReplacementPending() && m_Anchor == oldAnchor && m_CreatedItems.Count() == oldCount, "object drop outside the world cancels without prompting or changing the scene")) return;
        m_Browser.SelectCatalogItemRow(0);
        BeginCatalogPress(CatalogRowPoint(0));
        UpdateCatalogDrag(drop);
        if (!TestCheck(!m_CatalogPressed && !AnchorReplacementPending(), "object folders cannot create anchors or open the replacement dialog")) return;
        m_Browser.SelectCatalogItemRow(row);
        BeginCatalogPress(press);
        FinishCatalogDrag(drop,true);
        if (!TestCheck(AnchorReplacementPending() && m_ReplaceRoot.IsVisible() && m_Scenes.Count() == oldScenes && m_CreatedItems.Count() == oldCount && m_Item == oldItem, "existing anchor drop requests confirmation before creating or deleting entities")) return;
        vector transform[4];
        oldItem.GetTransform(transform);
        transform[3] = transform[3]+"1 0 0";
        HandleKey(KeyCode.KC_F4);
        OnClick(m_Toolbar.FindAnyWidget("CameraMode"),0,0,0);
        bool blocked = !WorldPoint(drop) && PanelPoint(drop) && !ApplyGizmoTransformAt(transform,false,drop) && !SelectSceneCharacter() && !SpawnSceneClass("Hammer",true) && !SetAnchor(null);
        if (!TestCheck(blocked && !m_PlayerMode && m_Pointer && m_Item == oldItem && GetGizmoApi().GetCount() == 0, "replacement modal blocks world edits selection camera player mode and parallel creation")) return;
        OnClick(m_ReplaceRoot.FindAnyWidget("ReplaceCancel"),0,0,0);
        if (!TestCheck(!AnchorReplacementPending() && !m_ReplaceRoot.IsVisible() && m_Anchor == oldAnchor && m_Item == oldItem && m_Scenes.Count() == oldScenes && m_CreatedItems.Count() == oldCount && vector.Distance(oldItem.GetPosition(),oldPosition) < 0.0001 && GetGizmoApi().GetCount() == 1, "cancelling replacement preserves the complete scene selection pose and gizmo")) return;
        SetAnchor(null);
        SpawnSceneClass("Land_Garage_Row_Small",false);
        bool guarded = AnchorReplacementPending() && m_Scenes.Count() == oldScenes;
        HandleKey(KeyCode.KC_ESCAPE);
        if (!TestCheck(guarded && !AnchorReplacementPending(), "clearing active selection cannot bypass the single-anchor guard and Escape cancels")) return;
        SetAnchor(oldAnchor);
        SelectItem(oldItem);
        SpawnSceneClass("NotAnActualAnchorClass",false);
        if (!TestCheck(!AnchorReplacementPending() && m_Anchor == oldAnchor && m_CreatedItems.Count() == oldCount && m_LastError == IOTL.T("UNKNOWN_CLASS"), "invalid anchor names report an error without requesting replacement")) return;
        bool failed = !SpawnResolvedSceneClass("Hammer",false,true,hit,normal,true);
        if (!TestCheck(failed && m_Anchor == oldAnchor && m_Item == oldItem && m_Scenes.Count() == oldScenes && m_CreatedItems.Count() == oldCount && m_LastError == IOTL.T("NOT_ANCHOR"), "candidate validation failure preserves the old layout and selected item")) return;
        ClearError();
        if (!TestCheck(ExportAnchor(), "old layout can be exported before a confirmed replacement")) return;
        string oldXml = "$profile:ProxyPlacement/"+oldAnchor.GetType()+"/"+m_RunTag+"_scene_"+m_ActiveScene.Id.ToString()+".xml";
        int previousId = m_NextSceneId;
        Man player = GetGame().GetPlayer();
        ItemBase carried = ItemBase.Cast(player.GetInventory().CreateInInventory("BandageDressing"));
        if (!TestCheck(carried && carried.GetHierarchyParent(), "replacement regression has a real item in the character inventory")) return;
        m_CreatedItems.Insert(carried);
        m_ActiveScene.Items.Insert(carried);
        array<Object> removed = new array<Object>;
        foreach (IOTSceneEntry scene : m_Scenes) if (scene.Anchor) removed.Insert(scene.Anchor);
        foreach (ItemBase item : m_CreatedItems) if (item && !item.GetHierarchyParent()) removed.Insert(item);
        SpawnSceneClass("Land_Garage_Row_Small",false,true,hit,normal);
        if (!TestCheck(AnchorReplacementPending(), "central creation API also requires replacement confirmation")) return;
        OnClick(m_ReplaceRoot.FindAnyWidget("ReplaceConfirm"),0,0,0);
        if (!TestCheck(!AnchorReplacementPending() && m_Scenes.Count() == 1 && m_Anchor && m_Anchor != oldAnchor && m_Anchor.GetType() == "Land_Garage_Row_Small" && m_ActiveScene.Items.Count() == 0 && m_CreatedItems.Count() == 0 && SelectedObject() == m_Anchor, "confirmed replacement commits one selected anchor and an empty layout")) return;
        vector actual = m_Anchor.GetPosition();
        if (!TestCheck(Math.AbsFloat(actual[0]-hit[0]) < 0.05 && Math.AbsFloat(actual[2]-hit[2]) < 0.05 && m_ActiveScene.Id > previousId && FileExist(oldXml), "replacement keeps the drop location and never reuses exported scene filenames")) return;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestAnchorCleanup,250,false,removed,carried,player,oldXml);
    }

    protected void SelfTestAnchorCleanup(array<Object> removed, ItemBase carried, Man player, string oldXml)
    {
        bool cleared = true;
        foreach (Object oldEntity : removed) if (oldEntity) cleared = false;
        if (!TestCheck(cleared && m_Scenes.Count() == 1, "replacement removes every old tracked world item and anchor")) return;
        if (!TestCheck(player && player == GetGame().GetPlayer() && carried && carried.GetHierarchyRootPlayer() == player && player.FindAttachmentBySlotName("Feet"), "replacement preserves the character inventory and footwear")) return;
        if (!TestCheck(SpawnSceneClass("HatchbackWheel",true) && ItemScene(m_Item) == m_ActiveScene && ExportAnchor() && FileExist(oldXml), "new anchor accepts and exports items while the previous XML remains intact")) return;
        m_Browser.SetMode(false);
        m_Browser.Search("");
        RefreshObjects();
        PrintToRPT("[PROXY TOOL V2 SELFTEST] PASS: independent character and anchor movement, unchanged loot, flat scene list, previews, item dragging and CE XML.");
        string keepOpen;
        if (GetGame().CommandlineGetParam("proxyToolKeepOpen",keepOpen))
        {
            PrintToRPT("[PROXY TOOL V2 SELFTEST] REVIEW_READY: client retained for author review.");
        }
        else
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(Tick);
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().RequestExit, 1500, false, 0);
        }
    }

    protected bool SelfTestErrors(ItemBase wheel)
    {
        vector savedPosition = wheel.GetPosition();
        vector savedAngles = wheel.GetOrientation();
        ReportError(IOTL.T("XML_FAILED"));
        float x,y,width,height,textWidth,textHeight;
        int contentWidth,contentHeight;
        m_ErrorRoot.GetScreenPos(x,y);
        m_ErrorRoot.GetScreenSize(width,height);
        m_ErrorText.GetScreenSize(textWidth,textHeight);
        m_ErrorText.GetTextSize(contentWidth,contentHeight);
        if (!TestCheck(m_ErrorRoot.IsVisible() && m_LastError == IOTL.T("XML_FAILED") && contentWidth > 0 && contentHeight > 0 && contentWidth <= textWidth+1 && contentHeight <= textHeight+1 && m_Item == wheel && vector.Distance(wheel.GetPosition(),savedPosition) < 0.0001, "errors use a readable standalone notification without moving the selected item")) return false;
        vector center = Vector(x+width*0.5,y+height*0.5,0);
        bool blocked = m_Viewport.Contains(center) && PanelPoint(center) && !WorldPoint(center) && EditorWidget(m_ErrorRoot.FindAnyWidget("ErrorClose"));
        PickPoint(center);
        bool preserved = m_Item == wheel;
        OnClick(m_ErrorRoot.FindAnyWidget("ErrorClose"),0,0,0);
        if (!TestCheck(blocked && preserved && !m_ErrorRoot.IsVisible() && m_LastError == "" && WorldPoint(center), "closing an error restores world input and preserves selection")) return false;
        vector relative = ProxyPosition();
        m_PosFields[0].SetText("invalid");
        OnChange(m_PosFields[0],0,0,true);
        bool invalidReported = m_ErrorRoot.IsVisible() && m_LastError == IOTL.T("INVALID_NUMBER") && vector.Distance(wheel.GetPosition(),savedPosition) < 0.0001;
        m_PosFields[0].SetText(FieldNumber(relative[0]));
        OnChange(m_PosFields[0],0,0,true);
        if (!TestCheck(invalidReported && !m_ErrorRoot.IsVisible() && m_LastError == "" && vector.Distance(wheel.GetPosition(),savedPosition) < 0.0001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.0001, "numeric validation routes errors to the notification and valid edits clear it")) return false;
        Object anchor = m_Anchor;
        int count = m_CreatedItems.Count();
        SetAnchor(null);
        bool prevented = !SpawnSceneClass("Hammer",true);
        bool creationReported = m_ErrorRoot.IsVisible() && m_LastError == IOTL.T("ANCHOR_REQUIRED");
        SetAnchor(anchor);
        SelectItem(wheel);
        if (!TestCheck(prevented && creationReported && m_CreatedItems.Count() == count && m_Item == wheel && !m_ErrorRoot.IsVisible(), "creation errors use the notification without spawning extra entities")) return false;
        return true;
    }

    protected bool SelfTestToolbar(ItemBase wheel)
    {
        UpdateToolbar();
        UpdateViewport();
        float toolbarX,toolbarY,toolbarWidth,toolbarHeight;
        m_Toolbar.GetScreenPos(toolbarX,toolbarY);
        m_Toolbar.GetScreenSize(toolbarWidth,toolbarHeight);
        vector worldOrigin = m_Viewport.Origin();
        bool fits = toolbarY+toolbarHeight < worldOrigin[1];
        array<string> names = {"MoveMode","RotateMode","CameraMode","SceneFocus","PlayerMode","Export","SceneExport"};
        float previousRight = toolbarX;
        float previousY = toolbarY;
        foreach (string name : names)
        {
            Widget control = m_Toolbar.FindAnyWidget(name);
            float x,y,width,height;
            control.GetScreenPos(x,y);
            control.GetScreenSize(width,height);
            if (!control.IsVisible() || x < toolbarX || x+width > toolbarX+toolbarWidth+1 || y < toolbarY || y+height > toolbarY+toolbarHeight+1 || (Math.AbsFloat(y - previousY) < 1 && x < previousRight)) fits = false;
            previousRight = x+width;
            previousY = y;
        }
        if (!TestCheck(fits && !m_Root.FindAnyWidget("MoveMode") && !m_Root.FindAnyWidget("PlayerMode") && !m_Root.FindAnyWidget("Help") && !m_Browser.Root().FindAnyWidget("SceneExport"), "toolbar controls fit above the world without duplicate sidebar actions")) return false;
        vector point = Vector(toolbarX+toolbarWidth*0.5,toolbarY+toolbarHeight*0.5,0);
        PickPoint(point);
        if (!TestCheck(ToolbarPoint(point) && PanelPoint(point) && !WorldPoint(point) && !TogglePointerAt(point) && m_Pointer && m_Item == wheel, "toolbar input preserves selection and cannot select the world or enter camera flight")) return false;
        vector savedPosition = wheel.GetPosition();
        vector savedAngles = wheel.GetOrientation();
        ButtonWidget cameraButton = ButtonWidget.Cast(m_Toolbar.FindAnyWidget("CameraMode"));
        string cameraText;
        OnClick(cameraButton,0,0,0);
        cameraButton.GetText(cameraText);
        bool appActive = GetGame().IsAppActive();
        bool menuOpen = GetGame().GetUIManager().GetMenu() != null;
        bool cameraActive = FreeDebugCamera.GetInstance().IsActive();
        float positionDelta = vector.Distance(wheel.GetPosition(),savedPosition);
        float angleDelta = vector.Distance(wheel.GetOrientation(),savedAngles);
        PrintToRPT("[PROXY TOOLBAR CAMERA] active="+appActive.ToString()+" menu="+menuOpen.ToString()+" pointer="+m_Pointer.ToString()+" camera="+cameraActive.ToString()+" label="+cameraText+" positionDelta="+positionDelta.ToString()+" angleDelta="+angleDelta.ToString());
        if (!TestCheck(!m_Pointer && FreeDebugCamera.GetInstance().IsActive() && cameraText == IOTL.T("CAMERA_CURSOR") && m_Item == wheel && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.001, "toolbar flight button enters camera flight and preserves the selected item")) return false;
        OnClick(cameraButton,0,0,0);
        cameraButton.GetText(cameraText);
        if (!TestCheck(m_Pointer && FreeDebugCamera.GetInstance().IsActive() && cameraText == IOTL.T("CAMERA_FLIGHT") && m_Item == wheel && GetGizmoApi().GetCount() == 1, "toolbar camera button restores cursor mode and its action label")) return false;
        OnClick(m_Toolbar.FindAnyWidget("RotateMode"),0,0,0);
        bool rotating = m_RotateMode && GetGizmoApi().GetTransformMode() == GizmoTransformMode.ROTATE && m_Toolbar.FindAnyWidget("RotateModeActive").IsVisible();
        OnClick(m_Toolbar.FindAnyWidget("MoveMode"),0,0,0);
        if (!TestCheck(rotating && !m_RotateMode && GetGizmoApi().GetTransformMode() == GizmoTransformMode.MOVE && m_Toolbar.FindAnyWidget("MoveModeActive").IsVisible() && m_Item == wheel && GetGizmoApi().GetCount() == 1 && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.001, "toolbar switches native gizmo modes without altering the selected item")) return false;
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        vector cameraPose[4];
        camera.GetTransform(cameraPose);
        OnClick(m_Toolbar.FindAnyWidget("SceneFocus"),0,0,0);
        if (!TestCheck(m_Item == wheel && m_Pointer && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.001, "toolbar anchor focus preserves item selection and pose")) return false;
        camera.SetTransform(cameraPose);
        OnClick(m_Toolbar.FindAnyWidget("Export"),0,0,0);
        OnClick(m_Toolbar.FindAnyWidget("SceneExport"),0,0,0);
        string anchorXml = "$profile:ProxyPlacement/"+m_Anchor.GetType()+"/"+m_RunTag+"_scene_"+m_ActiveScene.Id.ToString()+".xml";
        if (!TestCheck(FileExist("$profile:ProxyPlacement/selection.xml") && FileExist(anchorXml) && m_Item == wheel && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001, "toolbar exports selected item and full anchor XML without changing the scene")) return false;
        if (!SelfTestSceneHover(wheel)) return false;
        return true;
    }

    protected bool SelfTestCompactProperties(ItemBase wheel)
    {
        vector savedPosition = wheel.GetPosition();
        vector savedAngles = wheel.GetOrientation();
        float panelX,panelY,panelWidth,collapsedHeight;
        m_Root.GetScreenPos(panelX,panelY);
        m_Root.GetScreenSize(panelWidth,collapsedHeight);
        if (!TestCheck(!m_FineOpen && !m_Root.FindAnyWidget("FinePanel").IsVisible() && !m_ItemsList.IsVisible() && !m_AnchorsList.IsVisible() && !m_Root.FindAnyWidget("SceneTargetLabel") && !m_Root.FindAnyWidget("AnchorLabel") && !m_Root.FindAnyWidget("CoordinateBadge") && !m_Root.FindAnyWidget("ApplyValues") && !m_Root.FindAnyWidget("Reset") && collapsedHeight < 500*m_PanelScale, "properties omit entity names and coordinate badges with fine controls collapsed")) return false;
        bool aligned = true;
        for (int kind = 0; kind < 2; kind++)
        {
            string rowPrefix = "Pos";
            string labelPrefix = "PosAxis";
            if (kind == 1) { rowPrefix = "Rot"; labelPrefix = "RotAxis"; OnClick(m_Toolbar.FindAnyWidget("RotateMode"),0,0,0); }
            else OnClick(m_Toolbar.FindAnyWidget("MoveMode"),0,0,0);
            float previousBottom;
            for (int axis = 0; axis < 3; axis++)
            {
                string suffix = axis.ToString();
                Widget field = m_Root.FindAnyWidget(rowPrefix+suffix);
                Widget label = m_Root.FindAnyWidget(labelPrefix+suffix);
                Widget reset = m_Root.FindAnyWidget(rowPrefix+"Reset"+suffix);
                float x,y,width,height,labelX,labelY,labelWidth,labelHeight,resetX,resetY,resetWidth,resetHeight;
                field.GetScreenPos(x,y);
                field.GetScreenSize(width,height);
                label.GetScreenPos(labelX,labelY);
                label.GetScreenSize(labelWidth,labelHeight);
                reset.GetScreenPos(resetX,resetY);
                reset.GetScreenSize(resetWidth,resetHeight);
                m_NumberMeasure.SetText(EditBoxWidget.Cast(field).GetText());
                int valueWidth,valueHeight;
                m_NumberMeasure.GetTextSize(valueWidth,valueHeight);
                if (!field.IsVisible() || valueWidth <= 0 || width < valueWidth+8*m_PanelScale || x < labelX+labelWidth || Math.AbsFloat(y - labelY) > 1 || (axis > 0 && y < previousBottom) || resetX < x+width || resetX - x - width > 6*m_PanelScale || Math.AbsFloat(resetY+resetHeight*0.5 - y - height*0.5) > 1 || resetX+resetWidth > panelX+panelWidth) aligned = false;
                previousBottom = y+height;
            }
        }
        OnClick(m_Toolbar.FindAnyWidget("MoveMode"),0,0,0);
        if (!TestCheck(aligned, "property rows keep labels values and reset icons together")) return false;
        if (!TestCheck(FieldNumber(0) == "0.00000" && FieldNumber(-0.000001) == "0.00000" && FieldNumber(-1.23456) == "-1.23456" && FieldNumber(100000) == "100000.00000", "five decimal fields handle signs zero and large world coordinates")) return false;
        m_PosFields[0].SetText("1,23456");
        m_DirtyInputs = true;
        OnClick(m_Root.FindAnyWidget("FineToggle"),0,0,0);
        if (!TestCheck(m_FineOpen && m_Root.FindAnyWidget("FinePanel").IsVisible() && m_DirtyInputs && m_PosFields[0].GetText() == "1,23456" && vector.Distance(wheel.GetPosition(),savedPosition) < 0.0001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.0001, "opening fine settings preserves pending input and the item pose")) return false;
        float fineX,fineY,fineWidth,fineHeight,footerX,footerY,expandedWidth,expandedHeight;
        m_Root.FindAnyWidget("FinePanel").GetScreenPos(fineX,fineY);
        m_Root.FindAnyWidget("FinePanel").GetScreenSize(fineWidth,fineHeight);
        m_Status.GetScreenPos(footerX,footerY);
        m_Root.GetScreenSize(expandedWidth,expandedHeight);
        if (!TestCheck(footerY >= fineY+fineHeight && expandedHeight > collapsedHeight, "expanded fine settings move footer actions below the controls")) return false;
        OnClick(m_Root.FindAnyWidget("FineToggle"),0,0,0);
        m_Root.GetScreenSize(expandedWidth,expandedHeight);
        if (!TestCheck(!m_FineOpen && m_DirtyInputs && m_PosFields[0].GetText() == "1,23456" && Math.AbsFloat(expandedHeight - collapsedHeight) < 1, "closing fine settings preserves pending input and restores compact height")) return false;
        m_DirtyInputs = false;
        SyncFields();
        vector baselinePosition = ProxyPosition();
        vector baselineAngles = ProxyAngles();
        m_PosFields[0].SetText("1,23456");
        OnChange(m_PosFields[0],0,0,false);
        vector changedPosition = baselinePosition;
        changedPosition[0] = 1.23456;
        if (!TestCheck(vector.Distance(ProxyPosition(),changedPosition) < 0.0001 && vector.Distance(ProxyAngles(),baselineAngles) < 0.001 && m_PosFields[0].GetText() == "1,23456" && !m_DirtyInputs, "numeric position applies immediately without rewriting the active field")) return false;
        OnClick(m_Toolbar.FindAnyWidget("RotateMode"),0,0,0);
        m_RotFields[2].SetText("35.5");
        OnChange(m_RotFields[2],0,0,false);
        vector changedAngles = baselineAngles;
        changedAngles[2] = 35.5;
        if (!TestCheck(vector.Distance(ProxyAngles(),changedAngles) < 0.001 && vector.Distance(ProxyPosition(),changedPosition) < 0.0001 && m_RotFields[2].GetText() == "35.5", "numeric rotation applies immediately and preserves position")) return false;
        OnClick(m_Toolbar.FindAnyWidget("MoveMode"),0,0,0);
        m_PosFields[0].SetText("-");
        OnChange(m_PosFields[0],0,0,false);
        bool invalidPreserved = m_DirtyInputs && vector.Distance(ProxyPosition(),changedPosition) < 0.0001;
        m_PosFields[0].SetText("101");
        OnChange(m_PosFields[0],0,0,false);
        invalidPreserved = invalidPreserved && m_DirtyInputs && vector.Distance(ProxyPosition(),changedPosition) < 0.0001;
        OnFocusLost(m_PosFields[0],0,0);
        if (!TestCheck(invalidPreserved && !m_DirtyInputs && m_PosFields[0].GetText() == FieldNumber(changedPosition[0]), "incomplete or out of range input keeps the last valid pose and reverts on focus loss")) return false;
        bool independentPositionReset = true;
        bool independentRotationReset = true;
        for (int resetAxis = 0; resetAxis < 3; resetAxis++)
        {
            vector testPosition = m_OriginalProxyPosition+"0.2 0.3 0.4";
            vector testAngles = m_OriginalProxyAngles+"5 6 7";
            SetProxyPose(testPosition,testAngles);
            vector expectedPosition = testPosition;
            expectedPosition[resetAxis] = m_OriginalProxyPosition[resetAxis];
            OnClick(m_Toolbar.FindAnyWidget("MoveMode"),0,0,0);
            OnClick(m_Root.FindAnyWidget("PosReset"+resetAxis.ToString()),0,0,0);
            if (vector.Distance(ProxyPosition(),expectedPosition) > 0.0001 || vector.Distance(ProxyAngles(),testAngles) > 0.001) independentPositionReset = false;
            SetProxyPose(testPosition,testAngles);
            vector expectedAngles = testAngles;
            expectedAngles[resetAxis] = m_OriginalProxyAngles[resetAxis];
            OnClick(m_Toolbar.FindAnyWidget("RotateMode"),0,0,0);
            OnClick(m_Root.FindAnyWidget("RotReset"+resetAxis.ToString()),0,0,0);
            if (vector.Distance(ProxyAngles(),expectedAngles) > 0.001 || vector.Distance(ProxyPosition(),testPosition) > 0.0001) independentRotationReset = false;
        }
        if (!TestCheck(independentPositionReset, "each position icon resets only its coordinate to the selection baseline")) return false;
        if (!TestCheck(independentRotationReset, "each rotation icon resets only its angle to the selection baseline")) return false;
        SetProxyPose(baselinePosition,baselineAngles);
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        vector cameraPose[4];
        camera.GetTransform(cameraPose);
        SelectSceneCharacter();
        ToggleFineSettings();
        m_Root.FindAnyWidget("FinePanel").GetScreenSize(fineWidth,fineHeight);
        vector characterPosition = GetGame().GetPlayer().GetPosition();
        if (!TestCheck(m_MoveTarget == GetGame().GetPlayer() && !m_RotFields[0].IsVisible() && !m_Root.FindAnyWidget("RotReset0").IsVisible() && !m_Root.FindAnyWidget("AngleStep").IsVisible() && Math.AbsFloat(m_PosFields[0].GetText().ToFloat() - characterPosition[0]) < 0.001 && fineHeight < 100*m_PanelScale, "character properties show world position and only movement fine controls")) return false;
        vector characterMoved = characterPosition+"0.5 0 0.5";
        MoveSceneTarget(characterMoved);
        SyncFields();
        m_PosFields[0].SetText((characterPosition[0]+1).ToString());
        OnChange(m_PosFields[0],0,0,false);
        characterMoved[0] = characterPosition[0]+1;
        bool characterLive = vector.Distance(GetGame().GetPlayer().GetPosition(),characterMoved) < 0.001;
        OnClick(m_Root.FindAnyWidget("PosReset0"),0,0,0);
        characterMoved[0] = characterPosition[0];
        if (!TestCheck(characterLive && vector.Distance(GetGame().GetPlayer().GetPosition(),characterMoved) < 0.001, "character world fields apply live and reset one coordinate independently")) return false;
        Reset();
        Object editedAnchor = m_Anchor;
        vector anchorPosition = editedAnchor.GetPosition();
        SelectSceneAnchor(editedAnchor);
        vector anchorMoved = anchorPosition+"0.5 0 0.5";
        MoveSceneTarget(anchorMoved);
        SyncFields();
        m_PosFields[0].SetText((anchorPosition[0]+1).ToString());
        OnChange(m_PosFields[0],0,0,false);
        anchorMoved[0] = anchorPosition[0]+1;
        bool anchorLive = vector.Distance(editedAnchor.GetPosition(),anchorMoved) < 0.001;
        OnClick(m_Root.FindAnyWidget("PosReset0"),0,0,0);
        anchorMoved[0] = anchorPosition[0];
        if (!TestCheck(anchorLive && vector.Distance(editedAnchor.GetPosition(),anchorMoved) < 0.001 && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001, "anchor world fields apply live and reset independently without moving loot")) return false;
        Reset();
        SelectItem(wheel);
        vector relative = ProxyPosition();
        if (!TestCheck(m_FineOpen && m_PosFields[0].IsVisible() && !m_RotFields[0].IsVisible() && !m_Root.FindAnyWidget("AngleStep").IsVisible() && m_Root.FindAnyWidget("MoveStep").IsVisible() && Math.AbsFloat(m_PosFields[0].GetText().ToFloat() - relative[0]) < 0.00002 && vector.Distance(wheel.GetPosition(),savedPosition) < 0.0001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.0001, "return to item properties restores relative coordinates without moving the item")) return false;
        ToggleFineSettings();
        if (!SelfTestPropertyModes(wheel)) return false;
        camera.SetTransform(cameraPose);
        return true;
    }

    protected bool SelfTestPropertyModes(ItemBase wheel)
    {
        vector savedPosition = wheel.GetPosition();
        vector savedAngles = wheel.GetOrientation();
        OnClick(m_Toolbar.FindAnyWidget("MoveMode"),0,0,0);
        ToggleFineSettings();
        if (!TestCheck(m_PosFields[0].IsVisible() && !m_RotFields[0].IsVisible() && m_Root.FindAnyWidget("PositionTitle").IsVisible() && !m_Root.FindAnyWidget("RotationTitle").IsVisible() && m_Root.FindAnyWidget("MoveStep").IsVisible() && !m_Root.FindAnyWidget("AngleStep").IsVisible() && m_Root.FindAnyWidget("PosPlus0").IsVisible() && !m_Root.FindAnyWidget("RotPlus0").IsVisible() && m_Root.FindAnyWidget("Ground").IsVisible(), "move mode shows only position and movement fine controls")) return false;
        OnClick(m_Toolbar.FindAnyWidget("RotateMode"),0,0,0);
        if (!TestCheck(!m_PosFields[0].IsVisible() && m_RotFields[0].IsVisible() && !m_Root.FindAnyWidget("PositionTitle").IsVisible() && m_Root.FindAnyWidget("RotationTitle").IsVisible() && !m_Root.FindAnyWidget("MoveStep").IsVisible() && m_Root.FindAnyWidget("AngleStep").IsVisible() && !m_Root.FindAnyWidget("PosPlus0").IsVisible() && m_Root.FindAnyWidget("RotPlus0").IsVisible() && !m_Root.FindAnyWidget("Ground").IsVisible() && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.001, "rotate mode shows only angles and angular fine controls without moving the item")) return false;
        HandleKey(KeyCode.KC_F7);
        bool returned = !m_RotateMode && m_FineOpen && m_PosFields[0].IsVisible() && !m_RotFields[0].IsVisible() && m_Root.FindAnyWidget("MoveStep").IsVisible() && !m_Root.FindAnyWidget("AngleStep").IsVisible();
        HandleKey(KeyCode.KC_F8);
        bool rotated = m_RotateMode && m_RotFields[0].IsVisible() && !m_PosFields[0].IsVisible();
        HandleKey(KeyCode.KC_F7);
        if (!TestCheck(returned && rotated && m_Item == wheel && m_FineOpen && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.001, "F7 and F8 update property visibility and preserve the item pose and fine section state")) return false;
        ToggleFineSettings();
        return true;
    }

    protected bool SelfTestSceneMovement()
    {
        Object anchor = m_Anchor;
        ItemBase first = m_ActiveScene.Items[0];
        vector anchorPosition = anchor.GetPosition();
        vector firstPosition = first.GetPosition();
        vector proxyPosition = ItemProxyPosition(first);
        vector proxyAngles = ItemProxyAngles(first);
        vector otherAnchorPosition = m_Scenes[1].Anchor.GetPosition();
        bool hadBody = dBodyIsSet(first);
        bool wasDynamic;
        if (hadBody) wasDynamic = dBodyIsDynamic(first);
        if (!TestCheck(SelectSceneAnchor(anchor) && SelectedObject() == anchor && Gizmo_IsSupported() && Gizmo_IsAllowedTransformMode(GizmoTransformMode.MOVE) && !Gizmo_IsAllowedTransformMode(GizmoTransformMode.ROTATE), "anchor selection enables only native translation")) return false;
        if (!TestCheck(!m_Root.FindAnyWidget("SceneTargetLabel") && !m_ItemsList.IsVisible() && Math.AbsFloat(m_PosFields[0].GetText().ToFloat() - anchorPosition[0]) < 0.001 && m_RotFields[0].GetText() == "", "scene target fields show world coordinates and omit editable rotation")) return false;
        vector pose[4];
        Gizmo_GetWorldTransform(pose);
        vector delta = "2 0.3 -1";
        pose[3] = pose[3]+delta;
        vector center = m_Viewport.Center();
        if (!TestCheck(BeginWorldGesture(center) && ApplyGizmoTransformAt(pose,true,center) && vector.Distance(anchor.GetPosition(),anchorPosition+delta) < 0.001, "native scene gizmo translates the selected anchor")) return false;
        vector expectedProxy = proxyPosition+Vector(-delta[2],-delta[1],delta[0]);
        if (!TestCheck(vector.Distance(first.GetPosition(),firstPosition) < 0.001 && vector.Distance(ItemProxyPosition(first),expectedProxy) < 0.001 && vector.Distance(ItemProxyAngles(first),proxyAngles) < 0.001, "moving an anchor leaves loot in place and recalculates its relative coordinates")) return false;
        if (!TestCheck(vector.Distance(m_Scenes[1].Anchor.GetPosition(),otherAnchorPosition) < 0.001, "moving an anchor leaves other scene anchors untouched")) return false;
        pose[0] = "2 0 0";
        pose[1] = "0 2 0";
        pose[2] = "0 0 2";
        if (!TestCheck(ApplyGizmoTransformAt(pose,true,center) && anchor.GetOrientation().Length() < 0.001 && Math.AbsFloat(anchor.GetScale() - 1) < 0.0001, "scene gizmo preserves anchor rotation and scale when supplied another basis")) return false;
        vector outside = m_Viewport.Origin()+"-1 0 0";
        pose[3] = pose[3]+"1 0 0";
        if (!TestCheck(!ApplyGizmoTransformAt(pose,false,outside) && vector.Distance(anchor.GetPosition(),anchorPosition+delta) < 0.001, "anchor movement obeys the world viewport boundary")) return false;
        SelectSceneAnchor(anchor);
        Reset();
        if (!TestCheck(vector.Distance(anchor.GetPosition(),anchorPosition) < 0.001 && vector.Distance(first.GetPosition(),firstPosition) < 0.001, "F9 restores only the anchor and leaves loot untouched")) return false;
        for (int axis = 0; axis < 3; axis++) m_PosFields[axis].SetText((anchorPosition[axis]+delta[axis]).ToString());
        if (!TestCheck(ApplyFields() && vector.Distance(anchor.GetPosition(),anchorPosition+delta) < 0.001 && vector.Distance(first.GetPosition(),firstPosition) < 0.001, "numeric world coordinates move only the selected anchor")) return false;
        m_PosFields[0].SetText("invalid");
        if (!TestCheck(!ApplyFields() && vector.Distance(anchor.GetPosition(),anchorPosition+delta) < 0.001, "invalid world coordinates do not partially move a scene object")) return false;
        m_PosFields[0].SetText("200000");
        if (!TestCheck(!ApplyFields() && vector.Distance(first.GetPosition(),firstPosition) < 0.001, "out of range world coordinates leave scene objects unchanged")) return false;
        Reset();
        Nudge(false,0,1);
        vector nudgedPosition = anchor.GetPosition();
        if (!TestCheck(Math.AbsFloat(nudgedPosition[0] - anchorPosition[0] - MoveStep()) < 0.001 && vector.Distance(first.GetPosition(),firstPosition) < 0.001, "world position nudges move the anchor independently of loot")) return false;
        Reset();
        DeselectItem();
        if (!TestCheck(dBodyIsSet(first) == hadBody && (!hadBody || dBodyIsDynamic(first) == wasDynamic), "anchor editing does not change item physics body presence or mode")) return false;
        SetAnchor(null);
        Man player = GetGame().GetPlayer();
        vector playerPosition = player.GetPosition();
        vector playerAngles = player.GetOrientation();
        if (!TestCheck(SelectSceneCharacter() && !m_Anchor && SelectedObject() == player && GetGizmoApi().GetCount() == 1 && !Gizmo_IsAllowedTransformMode(GizmoTransformMode.ROTATE), "character translation works without a scene anchor")) return false;
        Gizmo_GetWorldTransform(pose);
        pose[3] = playerPosition+"1 0 1";
        if (!TestCheck(BeginWorldGesture(center) && ApplyGizmoTransformAt(pose,true,center) && vector.Distance(player.GetPosition(),pose[3]) < 0.001, "native scene gizmo translates the character")) return false;
        if (!TestCheck(vector.Distance(anchor.GetPosition(),anchorPosition) < 0.001 && vector.Distance(first.GetPosition(),firstPosition) < 0.001 && vector.Distance(player.GetOrientation(),playerAngles) < 0.001, "character movement preserves anchor items and character orientation")) return false;
        vector beforeRotation = player.GetPosition();
        Nudge(true,0,1);
        if (!TestCheck(vector.Distance(player.GetPosition(),beforeRotation) < 0.001 && vector.Distance(player.GetOrientation(),playerAngles) < 0.001, "character rotation commands do not alter its translation target")) return false;
        Reset();
        if (!TestCheck(vector.Distance(player.GetPosition(),playerPosition) < 0.001, "F9 restores the character position")) return false;
        vector numericPosition = playerPosition+"0.5 0 -0.5";
        for (int numericAxis = 0; numericAxis < 3; numericAxis++) m_PosFields[numericAxis].SetText(numericPosition[numericAxis].ToString());
        if (!TestCheck(ApplyFields() && vector.Distance(player.GetPosition(),numericPosition) < 0.001 && !Export(), "character world coordinates never export the character as a proxy")) return false;
        Reset();
        SetAnchor(anchor);
        SelectItem(first);
        OnClick(m_Toolbar.FindAnyWidget("RotateMode"),0,0,0);
        if (!TestCheck(!m_MoveTarget && m_Item == first && !m_ItemsList.IsVisible() && !m_Root.FindAnyWidget("SceneTargetLabel") && m_RotFields[0].IsVisible() && Gizmo_IsAllowedTransformMode(GizmoTransformMode.ROTATE), "item selection restores relative pose fields and native rotation")) return false;
        DeselectItem();
        return true;
    }
    protected bool SelfTestItemPreview()
    {
        m_Browser.SetMode(true);
        m_Browser.Search("Hammer");
        float x,y,width,height,trayX,trayY;
        m_Browser.Root().GetScreenPos(x,y);
        m_Browser.Root().GetScreenSize(width,height);
        m_CreatedTray.Root().GetScreenPos(trayX,trayY);
        if (!TestCheck(!m_Browser.Root().FindAnyWidget("ScenePreviewPanel") && Math.AbsFloat(trayY - y - height - 12*m_PanelScale) < 1, "item catalog uses available height above scene list without a click preview")) return false;
        m_Browser.SelectCatalogItemRow(m_Browser.ClassRow("SledgeHammer"));
        if (!TestCheck(m_Browser.FirstClass() == "SledgeHammer" && m_Browser.SelectedDragClass() == "SledgeHammer" && !m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible() && m_CreatedItems.Count() == 0, "catalog selection updates the drag class without creating a click preview")) return false;
        array<string> classes = {"CanisterGasoline","HatchbackWheel","AK101","Ammo_545x39","CargoPants_Grey"};
        TextListboxWidget catalog = TextListboxWidget.Cast(m_Browser.Root().FindAnyWidget("SceneResults"));
        foreach (string classname : classes)
        {
            m_Browser.Search(classname);
            int row = m_Browser.ClassRow(classname);
            m_Browser.SelectCatalogItemRow(row);
            m_Browser.HoverAt(CatalogRowPoint(row),true,true);
            EntityAI preview = m_Browser.HoverEntity();
            string label;
            catalog.GetItemText(row,0,label);
            label.TrimInPlace();
            if (!TestCheck(preview && preview.GetType() == classname && m_Browser.HoverView().GetItem() == preview && m_Browser.HoverView().GetView() == preview.GetViewIndex() && label == preview.GetDisplayName() && label != classname && m_Browser.SelectedDragClass() == classname, "hover model and localized catalog name retain the exact class: "+classname)) return false;
        }
        m_Browser.SetMode(false);
        if (!SelfTestHoverPreview()) return false;
        return true;
    }

    protected vector CatalogRowPoint(int index)
    {
        Widget widget = m_Browser.ItemRowWidget(index);
        m_Browser.RevealItemRow(index);
        float x,y,width,height;
        widget.GetScreenPos(x,y);
        widget.GetScreenSize(width,height);
        return Vector(x+20,y+height*0.5,0);
    }

    protected bool SelfTestHoverPreview()
    {
        m_Browser.SetMode(true);
        m_Browser.Search("Hammer");
        int hammerRow = m_Browser.ClassRow("Hammer");
        int sledgeRow = m_Browser.ClassRow("SledgeHammer");
        m_Browser.SelectCatalogItemRow(hammerRow);
        vector point = CatalogRowPoint(sledgeRow);
        m_Browser.HoverAt(point,true);
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible(), "item hover waits before constructing a popup model")) return false;
        m_Browser.HoverAt(point,true,true);
        EntityAI hover = m_Browser.HoverEntity();
        if (!TestCheck(hover && hover.GetType() == "SledgeHammer" && m_Browser.HoverView().GetItem() == hover && m_Browser.HoverBoundVisible() && m_Browser.FirstClass() == "Hammer" && !m_Anchor, "hover previews the pointed item independently of catalog selection without an anchor")) return false;
        vector position = hover.GetPosition();
        if (!TestCheck(position[1] < -999 && !dBodyIsSet(hover) && !m_CreatedItems.Count() && !ItemScene(ItemBase.Cast(hover)), "hover models stay below the map without physics scene ownership or export membership")) return false;
        m_Browser.HoverAt(point,true,true);
        if (!TestCheck(m_Browser.HoverEntity() == hover, "hovering the same item reuses its popup model")) return false;
        float x,y,width,height;
        m_Browser.HoverRoot().GetScreenPos(x,y);
        m_Browser.HoverRoot().GetScreenSize(width,height);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        vector popupCenter = Vector(x+width*0.5,y+height*0.5,0);
        float panelX,panelY,panelWidth,panelHeight;
        m_Browser.Root().GetScreenPos(panelX,panelY);
        m_Browser.Root().GetScreenSize(panelWidth,panelHeight);
        bool separated = x >= panelX+panelWidth+12*m_PanelScale - 1 || x+width <= panelX - 12*m_PanelScale+1;
        if (!TestCheck(separated && x >= 0 && y >= 0 && x+width <= screenWidth && y+height <= screenHeight && m_Browser.Contains(popupCenter) && !WorldPoint(popupCenter), "hover popup fits on screen and blocks world editing through its visible area")) return false;
        m_Browser.HoverAt(CatalogRowPoint(hammerRow),true);
        m_Browser.HoverAt(CatalogRowPoint(sledgeRow),true);
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible() && m_Browser.FirstClass() == "Hammer", "rapid hover changes discard intermediate models without changing catalog selection")) return false;
        m_Browser.HoverAt(CatalogRowPoint(sledgeRow),true,true);
        m_Browser.HoverAt("0 0 0",true);
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverView().GetItem() && !m_Browser.HoverRoot().IsVisible(), "leaving the item list clears the hover renderer and temporary entity")) return false;
        m_Browser.HoverAt(CatalogRowPoint(sledgeRow),true,true);
        m_Browser.HoverAt(CatalogRowPoint(0),true,true);
        bool categoryCleared = !m_Browser.HoverEntity();
        m_Browser.ItemScroll().GetScreenPos(x,y);
        m_Browser.ItemScroll().GetScreenSize(width,height);
        m_Browser.HoverAt(Vector(x+width - 1,y+20,0),true,true);
        if (!TestCheck(categoryCleared && !m_Browser.HoverEntity(), "catalog folders and the native scrollbar do not create hover previews")) return false;
        m_Browser.Search("AK");
        string selectedClass = m_Browser.SelectedDragClass();
        m_Browser.ItemScroll().VScrollToPos(0);
        m_Browser.ItemScroll().Update();
        Widget firstRow = m_Browser.ItemRowWidget(0);
        float rowWidth,rowHeight,initialX,initialY,scrolledX,scrolledY,restoredX,restoredY;
        firstRow.GetScreenSize(rowWidth,rowHeight);
        firstRow.GetScreenPos(initialX,initialY);
        bool wheelDown = m_Browser.OnMouseWheel(firstRow,0,0,-1);
        firstRow.GetScreenPos(scrolledX,scrolledY);
        bool wheelUp = m_Browser.OnMouseWheel(firstRow,0,0,1);
        firstRow.GetScreenPos(restoredX,restoredY);
        if (!TestCheck(wheelDown && wheelUp && Math.AbsFloat(initialY - scrolledY - rowHeight) < 1 && Math.AbsFloat(restoredY - initialY) < 1 && m_Browser.SelectedDragClass() == selectedClass, "catalog wheel scrolls one row per step without changing selection")) return false;
        int akmRow = m_Browser.ClassRow("AKM");
        m_Browser.ItemScroll().VScrollToPos(rowHeight);
        m_Browser.ItemScroll().Update();
        point = CatalogRowPoint(akmRow);
        m_Browser.HoverAt(point,true,true);
        float hoverScroll = m_Browser.ItemScroll().GetVScrollPos01();
        float hoverContentHeight = m_Browser.ItemScroll().GetContentHeight();
        string hoverClass;
        if (m_Browser.HoverEntity()) hoverClass = m_Browser.HoverEntity().GetType();
        PrintToRPT("[PROXY HOVER SCROLL] row="+akmRow.ToString()+" point="+point.ToString()+" scroll="+hoverScroll.ToString()+" content="+hoverContentHeight.ToString()+" class="+hoverClass);
        if (!TestCheck(m_Browser.HoverEntity() && m_Browser.HoverEntity().GetType() == "AKM" && m_Browser.ItemScroll().GetVScrollPos01() > 0, "hover hit testing follows actual item rows after native scrolling")) return false;
        m_Browser.Search("Hammer");
        bool searchCleared = !m_Browser.HoverEntity();
        sledgeRow = m_Browser.ClassRow("SledgeHammer");
        m_Browser.HoverAt(CatalogRowPoint(sledgeRow),true,true);
        m_Browser.Show(false);
        bool hiddenCleared = !m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible();
        m_Browser.Show(true);
        m_Browser.HoverAt(CatalogRowPoint(sledgeRow),true,true);
        m_Browser.SetMode(false);
        if (!TestCheck(searchCleared && hiddenCleared && !m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible(), "search catalog hiding and Objects mode release hover previews")) return false;
        m_Browser.SetMode(true);
        m_Browser.Search("Hammer");
        m_Browser.HoverAt(CatalogRowPoint(m_Browser.ClassRow("SledgeHammer")),true,true);
        SetPointer(false);
        bool flightCleared = !m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible();
        SetPointer(true);
        if (!TestCheck(flightCleared, "entering camera flight immediately releases the hover preview")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestSceneHover(ItemBase wheel)
    {
        int count = m_CreatedItems.Count();
        vector position = wheel.GetPosition();
        m_Browser.SetMode(true);
        m_Browser.Search("Hammer");
        m_Browser.SelectCatalogItemRow(m_Browser.ClassRow("Hammer"));
        int sledgeRow = m_Browser.ClassRow("SledgeHammer");
        vector point = CatalogRowPoint(sledgeRow);
        m_Browser.HoverAt(point,true,true);
        if (!TestCheck(m_Browser.HoverEntity() && m_Item == wheel && m_Browser.FirstClass() == "Hammer" && m_CreatedItems.Count() == count && GetGizmoApi().GetCount() == 1 && vector.Distance(wheel.GetPosition(),position) < 0.001, "item hover preserves scene selection gizmo and object placement")) return false;
        m_Browser.OnClick(m_Browser.ItemRowWidget(sledgeRow),0,0,0);
        if (!TestCheck(m_Browser.SelectedDragClass() == "SledgeHammer" && m_Item == wheel, "item row click chooses its own drag class after hovering a different selection")) return false;
        BeginCatalogPress(point);
        UpdateCatalogDrag(point+"20 0 0");
        bool dragging = m_CatalogDragging && m_CatalogClass == "SledgeHammer" && !m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible();
        CancelCatalogDrag();
        if (!TestCheck(dragging && m_Item == wheel && m_CreatedItems.Count() == count && GetGizmoApi().GetCount() == 1, "catalog dragging closes the hover popup and retains the selected scene item")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestItemDrag()
    {
        m_Browser.SetMode(true);
        m_Browser.Search("Hammer");
        if (!TestCheck(!m_Browser.Root().FindAnyWidget("SceneCreate") && !m_Browser.Root().FindAnyWidget("SceneCount") && !m_Browser.Root().FindAnyWidget("SceneClass") && !m_Browser.Root().FindAnyWidget("SceneClassLabel") && !m_Browser.Root().FindAnyWidget("SceneDragHint"), "item catalog omits create button counters class fields and drag instruction")) return false;
        int before = m_CreatedItems.Count();
        m_Browser.OnClick(m_Browser.ItemRowWidget(m_Browser.ClassRow("Hammer")),0,0,0);
        if (!TestCheck(m_CreatedItems.Count() == before, "catalog leaf click selects its class without spawning")) return false;
        float listX,listY;
        m_Browser.Root().FindAnyWidget("SceneResults").GetScreenPos(listX,listY);
        vector press = Vector(listX+20,listY+20,0);
        if (!TestCheck(BeginCatalogPress(press), "catalog press arms an item drag")) return false;
        UpdateCatalogDrag(press+"1 1 0");
        FinishCatalogDrag(press,false);
        if (!TestCheck(m_CreatedItems.Count() == before && !m_CatalogPressed && !m_CatalogDragRoot.IsVisible(), "catalog click below drag threshold creates nothing")) return false;
        m_Browser.Search("");
        BeginCatalogPress(press);
        UpdateCatalogDrag(press+"20 0 0");
        if (!TestCheck(!m_CatalogPressed && m_CreatedItems.Count() == before, "item category rows cannot become dragged spawn classes")) return false;
        m_Browser.Search("Hammer");
        m_Browser.HoverAt(CatalogRowPoint(m_Browser.ClassRow("Hammer")),true,true);
        EntityAI catalogPreview = m_Browser.HoverEntity();
        vector origin = m_Viewport.Origin();
        vector size = m_Viewport.Size();
        vector center = m_Viewport.Center();
        vector drop,hit,normal;
        bool found;
        for (int sample = 0; sample < 5 && !found; sample++)
        {
            drop = Vector(center[0],origin[1]+size[1]*(0.5+sample*0.1),0);
            found = DropSurface(drop,hit,normal) && normal[1] > 0.9;
        }
        if (!TestCheck(found, "item drop ray finds a ground surface inside the world area")) return false;
        ItemBase previous = m_CreatedItems[0];
        SelectItem(previous);
        vector previousPose[4];
        previous.GetTransform(previousPose);
        BeginCatalogPress(press);
        UpdateCatalogDrag(drop);
        if (!TestCheck(m_CatalogDragging && m_CatalogClass == "Hammer" && m_CatalogDragRoot.IsVisible() && GetGizmoApi().GetCount() == 0 && m_Item == previous, "catalog drag shows the classname and suspends native gizmo without deselecting")) return false;
        if (!TestCheck(!ApplyGizmoTransformAt(previousPose,false,drop), "catalog drag blocks transforms of the previously selected item")) return false;
        Object anchor = m_Anchor;
        if (!TestCheck(FinishCatalogDrag(drop,true) && m_CreatedItems.Count() == before+1 && m_Item.GetType() == "Hammer", "world drop creates exactly one selected catalog item")) return false;
        ItemBase placed = m_Item;
        if (!TestCheck(catalogPreview && placed != catalogPreview && !m_Browser.HoverEntity() && !m_Browser.HoverView().GetItem(), "dropped scene items remain independent of the released hover model")) return false;
        vector bounds[2];
        placed.ClippingInfo(bounds);
        vector position = placed.GetPosition();
        vector minimum = bounds[0];
        float distanceX = Math.AbsFloat(position[0] - hit[0]);
        float distanceZ = Math.AbsFloat(position[2] - hit[2]);
        float bottom = position[1]+minimum[1];
        if (!TestCheck(distanceX < 0.05 && distanceZ < 0.05 && bottom >= hit[1]+0.015, "dropped item uses the hit surface and stays above it")) return false;
        if (!TestCheck(m_Anchor == anchor && ItemScene(placed) == m_ActiveScene && m_CreatedTray.Count() == before+1 && GetGizmoApi().GetCount() == 1 && !m_CatalogDragRoot.IsVisible(), "dropped item joins its active anchor tray and restores native gizmo")) return false;
        if (!TestCheck(!FinishCatalogDrag(drop,true) && m_CreatedItems.Count() == before+1, "duplicate release notifications do not create another item")) return false;
        BeginCatalogPress(press);
        UpdateCatalogDrag(drop);
        if (!TestCheck(!FinishCatalogDrag(press,false) && m_CreatedItems.Count() == before+1 && m_Item == placed, "drop outside the world area cancels and preserves selection")) return false;
        vector sky = Vector(center[0],origin[1]+8,0);
        if (!TestCheck(!DropSurface(sky,hit,normal), "sky has no valid item drop surface")) return false;
        BeginCatalogPress(press);
        UpdateCatalogDrag(sky);
        if (!TestCheck(!FinishCatalogDrag(sky,true) && m_CreatedItems.Count() == before+1, "drop over sky creates nothing")) return false;
        BeginCatalogPress(press);
        UpdateCatalogDrag(drop);
        SetPointer(false);
        if (!TestCheck(!m_CatalogPressed && !m_CatalogDragRoot.IsVisible() && m_CreatedItems.Count() == before+1, "switching to camera flight cancels catalog drag")) return false;
        SetPointer(true);
        BeginCatalogPress(press);
        UpdateCatalogDrag(drop);
        EnterPlayer();
        if (!TestCheck(!m_CatalogPressed && !m_CatalogDragRoot.IsVisible(), "character mode cancels catalog drag")) return false;
        if (!TestCheck(!SelectSceneCharacter() && !m_CharacterFocused && !FreeDebugCamera.GetInstance().IsActive(), "character scene selection cannot reactivate the editor camera in player mode")) return false;
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverView().GetItem(), "character mode releases the hover preview")) return false;
        EnterEditor();
        array<string> classes = {"Hammer","Hammer","CanisterGasoline","HatchbackWheel"};
        ItemBase last = placed;
        foreach (string classname : classes)
        {
            m_Browser.SetMode(true);
            m_Browser.Search(classname);
            int count = m_CreatedItems.Count();
            BeginCatalogPress(press);
            if (!TestCheck(FinishCatalogDrag(drop,true) && m_CreatedItems.Count() == count+1 && m_Item.GetType() == classname && m_Item != last, "repeated drops create independent items without a scene quantity limit: "+classname)) return false;
            last = m_Item;
        }
        if (!TestCheck(m_Anchor == anchor && m_CreatedItems.Count() == before+5 && ExportAnchor(), "all dropped items retain their anchor and export to CE XML")) return false;
        m_Browser.SetMode(false);
        if (!TestCheck(!m_Browser.Root().FindAnyWidget("SceneCreate") && m_Browser.ItemRowWidget(0) && !m_Browser.Root().FindAnyWidget("SceneResults").IsVisible(), "object catalog uses drag rows and omits the creation button")) return false;
        return true;
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
        UpdateToolbar();
        Man simulationPlayer = GetGame().GetPlayer();
        if (m_PlayerSimulationPending && simulationPlayer)
        {
            if (simulationPlayer.GetIsSimulationDisabled() == m_PlayerSimulationRequested) m_PlayerSimulationPending = false;
            else simulationPlayer.DisableSimulation(m_PlayerSimulationRequested);
        }
        if (m_Browser)
        {
            int hoverX,hoverY;
            GetMousePos(hoverX,hoverY);
            bool hoverEnabled = m_Booted && !m_PlayerMode && !AnchorReplacementPending() && m_Pointer && !m_CatalogPressed && GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu();
            m_Browser.HoverAt(Vector(hoverX,hoverY,0),hoverEnabled);
        }
        if (m_CreatedTray && !m_PlayerMode)
        {
            m_CreatedTray.Position(m_Browser.Root());
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
        if (m_MoveTarget)
        {
            if (!m_DirtyInputs && vector.Distance(m_LastPos,m_MoveTarget.GetPosition()) > 0.000001) SyncFields();
            if (m_ShowDebug) m_Debug.SetText(IOTL.F("WORLD_POSITION",m_MoveTarget.GetPosition().ToString(false)));
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
        if (g_IOTProxyTool && g_IOTProxyTool.AnchorReplacementPending())
        {
            g_IOTProxyTool.HandleKey(key);
            return;
        }
        super.OnKeyPress(key);
        if (g_IOTProxyTool) g_IOTProxyTool.HandleKey(key);
    }
}
