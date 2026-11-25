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
        array<string> keys = new array<string>;
        keys.Insert("CATALOG_SUB_OPENED");
        keys.Insert("CATALOG_SUB_SEALED");
        keys.Insert("CATALOG_SUB_OTHER");
        keys.Insert("CATALOG_SUB_OTHER_VEHICLES");
        keys.Insert("CATALOG_SUB_CAR_ADA");
        keys.Insert("CATALOG_SUB_CAR_OLGA");
        keys.Insert("CATALOG_SUB_CAR_GUNTER");
        keys.Insert("CATALOG_SUB_CAR_SARKA");
        keys.Insert("CATALOG_SUB_CAR_M3S");
        keys.Insert("CATALOG_SUB_CAR_M1025");
        keys.Insert("CATALOG_SUB_DOORS");
        keys.Insert("CATALOG_SUB_HOODS");
        keys.Insert("CATALOG_SUB_TRUNKS");
        keys.Insert("CATALOG_SUB_PLAIN");
        keys.Insert("CATALOG_SUB_PLACES");
        keys.Insert("CATALOG_SUB_ANIMALS");
        keys.Insert("CATALOG_SUB_ORGANIZATIONS");
        keys.Insert("CATALOG_SUB_OTHER_SYMBOLS");
        keys.Insert("CATALOG_SUB_HELMET_ACCESSORIES");
        keys.Insert("CATALOG_SUB_HELMETS");
        keys.Insert("CATALOG_SUB_HOODS_WRAPS");
        keys.Insert("CATALOG_SUB_WARM_HATS");
        keys.Insert("CATALOG_SUB_CAPS_BERETS");
        keys.Insert("CATALOG_SUB_HATS_HEADBANDS");
        keys.Insert("CATALOG_SUB_ARMBANDS");
        keys.Insert("CATALOG_SUB_PROTECTIVE");
        keys.Insert("CATALOG_SUB_IMPROVISED");
        keys.Insert("CATALOG_SUB_UNIFORMS");
        keys.Insert("CATALOG_SUB_SWEATERS");
        keys.Insert("CATALOG_SUB_SHIRTS");
        keys.Insert("CATALOG_SUB_JACKETS");
        keys.Insert("CATALOG_SUB_MUSHROOMS");
        keys.Insert("CATALOG_SUB_CARCASSES");
        keys.Insert("CATALOG_SUB_FISHING");
        keys.Insert("CATALOG_SUB_CANNED");
        keys.Insert("CATALOG_SUB_FISH");
        keys.Insert("CATALOG_SUB_MEAT");
        keys.Insert("CATALOG_SUB_VEGETABLES");
        keys.Insert("CATALOG_SUB_FRUIT");
        keys.Insert("CATALOG_SUB_DRY_FOOD");
        keys.Insert("CATALOG_SUB_SNACKS");
        keys.Insert("CATALOG_SUB_CAMOUFLAGE");
        keys.Insert("CATALOG_SUB_STOCKS");
        keys.Insert("CATALOG_SUB_HANDGUARDS");
        keys.Insert("CATALOG_SUB_SYSTEM_AK");
        keys.Insert("CATALOG_SUB_SYSTEM_M4");
        keys.Insert("CATALOG_SUB_SYSTEM_MP5");
        keys.Insert("CATALOG_SUB_SYSTEM_FAL");
        keys.Insert("CATALOG_SUB_SYSTEM_SCAR");
        keys.Insert("CATALOG_SUB_PELTS");
        keys.Insert("CATALOG_SUB_GAS");
        keys.Insert("CATALOG_SUB_LIGHT_POWER");
        keys.Insert("CATALOG_SUB_MATERIALS");
        keys.Insert("CATALOG_SUB_FIRE_STARTING");
        keys.Insert("CATALOG_SUB_TEXTILES");
        keys.Insert("CATALOG_SUB_TECHNICAL");
        keys.Insert("CATALOG_SUB_KEYS_RESTRAINTS");
        keys.Insert("CATALOG_SUB_CLOCKS_WRITING");
        keys.Insert("CATALOG_SUB_DETONATORS");
        keys.Insert("CATALOG_SUB_BOLTS");
        keys.Insert("CATALOG_SUB_FLARES");
        keys.Insert("CATALOG_SUB_GRENADES");
        keys.Insert("CATALOG_SUB_CARTRIDGES");
        keys.Insert("CATALOG_SUB_BARRELS");
        keys.Insert("CATALOG_SUB_GIFTS");
        keys.Insert("CATALOG_SUB_TOYS");
        keys.Insert("CATALOG_SUB_BAGS");
        keys.Insert("CATALOG_SUB_CASES");
        keys.Insert("CATALOG_SUB_FLAGS");
        keys.Insert("CATALOG_SUB_FLAGPOLES");
        keys.Insert("CATALOG_SUB_CHARACTER_HEADS");
        keys.Insert("CATALOG_SUB_MALE");
        keys.Insert("CATALOG_SUB_FEMALE");
        keys.Insert("CATALOG_SUB_DEVICES");
        keys.Insert("CATALOG_SUB_STORAGE");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_SHELTERS");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_STORAGE");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_BUILDING");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_LOCKS");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_POWER");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_LIGHTING");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_FLAGS");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING_OTHER");
        keys.Insert("CALIBER_MM");
        keys.Insert("CALIBER_12GA");
        keys.Insert("CALIBER_MULTIPLE");
        keys.Insert("CALIBER_OTHER");
        keys.Insert("ITEM_MAP_COMMON");
        keys.Insert("LOCALE");
        keys.Insert("DELETE_ITEM");
        keys.Insert("UNSAVED_TITLE");
        keys.Insert("UNSAVED_TEXT");
        keys.Insert("UNSAVED_SAVE");
        keys.Insert("UNSAVED_DISCARD");
        keys.Insert("TITLE");
        keys.Insert("ITEM");
        keys.Insert("ANCHOR");
        keys.Insert("MOVE");
        keys.Insert("ROTATE");
        keys.Insert("POSITION");
        keys.Insert("MOVE_STEP_DEFAULT");
        keys.Insert("ROTATION");
        keys.Insert("ANGLE_STEP_DEFAULT");
        keys.Insert("APPLY");
        keys.Insert("CHARACTER");
        keys.Insert("RESET");
        keys.Insert("GROUND");
        keys.Insert("PLACE_ON_SURFACE");
        keys.Insert("PLACEMENT_NO_SURFACE");
        keys.Insert("PLACEMENT_NO_BOUNDS");
        keys.Insert("SELECT_HINT");
        keys.Insert("HELP");
        keys.Insert("CREATE_TITLE");
        keys.Insert("BUILDINGS");
        keys.Insert("ITEMS");
        keys.Insert("ITEM_GROUP_WEAPONS");
        keys.Insert("ITEM_GROUP_WEAPONS_FIREARMS");
        keys.Insert("ITEM_GROUP_WEAPONS_PISTOLS");
        keys.Insert("ITEM_GROUP_WEAPONS_SHOTGUNS");
        keys.Insert("ITEM_GROUP_WEAPONS_ARCHERY");
        keys.Insert("ITEM_GROUP_WEAPONS_MELEE");
        keys.Insert("ITEM_GROUP_WEAPONS_EXPLOSIVES");
        keys.Insert("ITEM_GROUP_WEAPONS_LAUNCHERS");
        keys.Insert("ITEM_GROUP_WEAPONS_OTHER");
        keys.Insert("ITEM_GROUP_AMMO");
        keys.Insert("ITEM_GROUP_AMMO_ROUNDS");
        keys.Insert("ITEM_GROUP_AMMO_MAGAZINES");
        keys.Insert("ITEM_GROUP_AMMO_BOXES");
        keys.Insert("ITEM_GROUP_ATTACHMENTS");
        keys.Insert("ITEM_GROUP_ATTACHMENTS_OPTICS");
        keys.Insert("ITEM_GROUP_ATTACHMENTS_MUZZLE");
        keys.Insert("ITEM_GROUP_ATTACHMENTS_LIGHT");
        keys.Insert("ITEM_GROUP_ATTACHMENTS_SUPPORT");
        keys.Insert("ITEM_GROUP_ATTACHMENTS_OTHER");
        keys.Insert("ITEM_GROUP_CLOTHING");
        keys.Insert("ITEM_GROUP_CLOTHING_BACKPACKS");
        keys.Insert("ITEM_GROUP_CLOTHING_VESTS");
        keys.Insert("ITEM_GROUP_CLOTHING_TOPS");
        keys.Insert("ITEM_GROUP_CLOTHING_PANTS");
        keys.Insert("ITEM_GROUP_CLOTHING_SHOES");
        keys.Insert("ITEM_GROUP_CLOTHING_HEADGEAR");
        keys.Insert("ITEM_GROUP_CLOTHING_MASKS");
        keys.Insert("ITEM_GROUP_CLOTHING_GLOVES");
        keys.Insert("ITEM_GROUP_CLOTHING_GLASSES");
        keys.Insert("ITEM_GROUP_CLOTHING_BELTS");
        keys.Insert("ITEM_GROUP_CLOTHING_OTHER");
        keys.Insert("ITEM_GROUP_FOOD_DRINKS");
        keys.Insert("ITEM_GROUP_FOOD_DRINKS_FOOD");
        keys.Insert("ITEM_GROUP_FOOD_DRINKS_DRINKS");
        keys.Insert("ITEM_GROUP_GEAR");
        keys.Insert("ITEM_GROUP_GEAR_TOOLS");
        keys.Insert("ITEM_GROUP_GEAR_TOOLS_CONSTRUCTION");
        keys.Insert("ITEM_GROUP_GEAR_TOOLS_METALWORK");
        keys.Insert("ITEM_GROUP_GEAR_TOOLS_CUTTING");
        keys.Insert("ITEM_GROUP_GEAR_TOOLS_REPAIR");
        keys.Insert("ITEM_GROUP_GEAR_TOOLS_OTHER");
        keys.Insert("ITEM_GROUP_GEAR_CONTAINERS");
        keys.Insert("ITEM_GROUP_GEAR_CAMPING");
        keys.Insert("ITEM_GROUP_GEAR_COOKING");
        keys.Insert("ITEM_GROUP_GEAR_CRAFTING");
        keys.Insert("ITEM_GROUP_GEAR_CULTIVATION");
        keys.Insert("ITEM_GROUP_GEAR_MEDICAL");
        keys.Insert("ITEM_GROUP_GEAR_NAVIGATION");
        keys.Insert("ITEM_GROUP_GEAR_RADIO");
        keys.Insert("ITEM_GROUP_GEAR_OPTICS");
        keys.Insert("ITEM_GROUP_GEAR_TRAPS");
        keys.Insert("ITEM_GROUP_GEAR_BOOKS");
        keys.Insert("ITEM_GROUP_GEAR_CONSUMABLES");
        keys.Insert("ITEM_GROUP_GEAR_OTHER");
        keys.Insert("ITEM_GROUP_VEHICLE_PARTS");
        keys.Insert("ITEM_GROUP_VEHICLE_PARTS_WHEELS");
        keys.Insert("ITEM_GROUP_VEHICLE_PARTS_BODY");
        keys.Insert("ITEM_GROUP_VEHICLE_PARTS_COMPONENTS");
        keys.Insert("ITEM_GROUP_VEHICLE_PARTS_OTHER");
        keys.Insert("ITEM_GROUP_OTHER");
        keys.Insert("SHOW_STATICOBJ");
        keys.Insert("OTHER_OBJECTS");
        keys.Insert("OBJECT_TREE_HINT");
        keys.Insert("CATEGORY_RESIDENTIAL");
        keys.Insert("RESIDENTIAL_SUB_SHEDS");
        keys.Insert("RESIDENTIAL_SUB_OFFICE");
        keys.Insert("RESIDENTIAL_SUB_MISC");
        keys.Insert("RESIDENTIAL_SUB_HOUSE");
        keys.Insert("RESIDENTIAL_SUB_CITY");
        keys.Insert("RESIDENTIAL_SUB_TENEMENTS");
        keys.Insert("RESIDENTIAL_SUB_STORES");
        keys.Insert("RESIDENTIAL_SUB_MEDICAL");
        keys.Insert("RESIDENTIAL_SUB_POLICE");
        keys.Insert("RESIDENTIAL_SUB_SCHOOLS");
        keys.Insert("RESIDENTIAL_SUB_FIREDEP");
        keys.Insert("RESIDENTIAL_SUB_BUS");
        keys.Insert("RESIDENTIAL_SUB_SLUMS");
        keys.Insert("RESIDENTIAL_SUB_PLATFORMS");
        keys.Insert("RESIDENTIAL_SUB_TERRACES");
        keys.Insert("RESIDENTIAL_SUB_OTHER");
        keys.Insert("CATEGORY_INDUSTRIAL");
        keys.Insert("INDUSTRIAL_SUB_CONTAINERS");
        keys.Insert("INDUSTRIAL_SUB_BARNS");
        keys.Insert("INDUSTRIAL_SUB_FARMS");
        keys.Insert("INDUSTRIAL_SUB_CEMENTWORKS");
        keys.Insert("INDUSTRIAL_SUB_COALPLANT");
        keys.Insert("INDUSTRIAL_SUB_FACTORIES");
        keys.Insert("INDUSTRIAL_SUB_WORKSHOPS");
        keys.Insert("INDUSTRIAL_SUB_GARAGES");
        keys.Insert("INDUSTRIAL_SUB_BUILDINGS");
        keys.Insert("INDUSTRIAL_SUB_CONSTRUCTION");
        keys.Insert("INDUSTRIAL_SUB_SHEDS");
        keys.Insert("INDUSTRIAL_SUB_SAWMILLS");
        keys.Insert("INDUSTRIAL_SUB_MINES");
        keys.Insert("INDUSTRIAL_SUB_QUARRIES");
        keys.Insert("INDUSTRIAL_SUB_OIL");
        keys.Insert("INDUSTRIAL_SUB_POWER");
        keys.Insert("INDUSTRIAL_SUB_HARBOUR");
        keys.Insert("INDUSTRIAL_SUB_STOCKYARDS");
        keys.Insert("INDUSTRIAL_SUB_DAMS");
        keys.Insert("INDUSTRIAL_SUB_IRRIGATION");
        keys.Insert("INDUSTRIAL_SUB_WATERTOWERS");
        keys.Insert("INDUSTRIAL_SUB_TANKS");
        keys.Insert("INDUSTRIAL_SUB_PIPES");
        keys.Insert("INDUSTRIAL_SUB_SMOKESTACKS");
        keys.Insert("INDUSTRIAL_SUB_MISC");
        keys.Insert("INDUSTRIAL_SUB_OTHER");
        keys.Insert("RESIDENTIAL_FAMILY_HOUSE");
        keys.Insert("RESIDENTIAL_FAMILY_PUBS");
        keys.Insert("RESIDENTIAL_FAMILY_HOSPITALS");
        keys.Insert("RESIDENTIAL_FAMILY_POLICE");
        keys.Insert("RESIDENTIAL_FAMILY_SCHOOLS");
        keys.Insert("RESIDENTIAL_FAMILY_FIRESTATIONS");
        keys.Insert("RESIDENTIAL_FAMILY_STORES");
        keys.Insert("RESIDENTIAL_FAMILY_KIOSKS");
        keys.Insert("RESIDENTIAL_FAMILY_OTHER_CITY");
        keys.Insert("RESIDENTIAL_FAMILY_OTHER_HOUSE");
        keys.Insert("CATEGORY_MILITARY");
        keys.Insert("CATEGORY_UNDERGROUND");
        keys.Insert("CATEGORY_WRECKS");
        keys.Insert("WRECK_SUB_VEHICLES");
        keys.Insert("WRECK_SUB_AIRCRAFT");
        keys.Insert("WRECK_SUB_SHIPS");
        keys.Insert("WRECK_SUB_TRAINS");
        keys.Insert("WRECK_SUB_OTHER");
        keys.Insert("VEHICLE_TYPE_TRUCK");
        keys.Insert("VEHICLE_TYPE_SEDAN");
        keys.Insert("VEHICLE_TYPE_OFFROAD");
        keys.Insert("VEHICLE_TYPE_HATCHBACK");
        keys.Insert("VEHICLE_TYPE_OTHER");
        keys.Insert("CATEGORY_FURNITURE");
        keys.Insert("CATEGORY_ROADS");
        keys.Insert("CATEGORY_RAIL");
        keys.Insert("CATEGORY_WALLS");
        keys.Insert("CATEGORY_SIGNS");
        keys.Insert("CATEGORY_RUINS");
        keys.Insert("CATEGORY_SPECIFIC");
        keys.Insert("SPECIFIC_SUB_CASTLES");
        keys.Insert("SPECIFIC_SUB_CHURCHES");
        keys.Insert("SPECIFIC_SUB_MOSQUES");
        keys.Insert("SPECIFIC_SUB_CEMETERIES");
        keys.Insert("SPECIFIC_SUB_MONUMENTS");
        keys.Insert("SPECIFIC_SUB_AIRFIELDS");
        keys.Insert("SPECIFIC_SUB_CABLEWAYS");
        keys.Insert("SPECIFIC_SUB_CAMPS");
        keys.Insert("SPECIFIC_SUB_HOTELS");
        keys.Insert("SPECIFIC_SUB_FUELSTATIONS");
        keys.Insert("SPECIFIC_SUB_PRISONS");
        keys.Insert("SPECIFIC_SUB_RADIO");
        keys.Insert("SPECIFIC_SUB_AMUSEMENT");
        keys.Insert("SPECIFIC_SUB_SPORTS");
        keys.Insert("SPECIFIC_SUB_MARKETS");
        keys.Insert("SPECIFIC_SUB_BORDERS");
        keys.Insert("SPECIFIC_SUB_RESEARCH");
        keys.Insert("SPECIFIC_SUB_FOREST");
        keys.Insert("SPECIFIC_SUB_REMAINS");
        keys.Insert("SPECIFIC_SUB_MAPS");
        keys.Insert("SPECIFIC_SUB_OTHER");
        keys.Insert("CATEGORY_PROPS");
        keys.Insert("CATEGORY_BUILDING_PARTS");
        keys.Insert("CATEGORY_VEGETATION");
        keys.Insert("CATEGORY_ROCKS");
        keys.Insert("CATEGORY_WATER");
        keys.Insert("CATEGORY_TERRAIN");
        keys.Insert("CATEGORY_UNCATEGORIZED");
        keys.Insert("SEARCH");
        keys.Insert("CLASSNAME");
        keys.Insert("CREATE_ANCHOR");
        keys.Insert("CREATE_ITEM");
        keys.Insert("FOCUS_ANCHOR");
        keys.Insert("EXPORT_ANCHOR");
        keys.Insert("ITEM_MODE_HINT");
        keys.Insert("ANCHOR_MODE_HINT");
        keys.Insert("FOUND");
        keys.Insert("UNKNOWN_CLASS");
        keys.Insert("ANCHOR_REQUIRED");
        keys.Insert("SPAWN_FAILED");
        keys.Insert("NOT_INVENTORY_ITEM");
        keys.Insert("NOT_ANCHOR");
        keys.Insert("CREATED");
        keys.Insert("ANCHOR_TRANSFORM_LIMIT");
        keys.Insert("GIZMO_HINT");
        keys.Insert("DESELECT_HINT");
        keys.Insert("NO_ITEM");
        keys.Insert("NO_ANCHOR");
        keys.Insert("START_HINT");
        keys.Insert("GIZMO_ON");
        keys.Insert("GIZMO_OFF");
        keys.Insert("INVALID_NUMBER");
        keys.Insert("NUMBER_LIMIT");
        keys.Insert("POSE_APPLIED");
        keys.Insert("GROUNDED");
        keys.Insert("POSE_RESET");
        keys.Insert("ANCHOR_XML_FAILED");
        keys.Insert("ANCHOR_XML_SAVED");
        keys.Insert("XML_FAILED");
        keys.Insert("MOVE_STEP");
        keys.Insert("ANGLE_STEP");
        keys.Insert("MOVE_KEYS");
        keys.Insert("ROTATE_KEYS");
        keys.Insert("MOVE_KEYS_HEIGHT");
        keys.Insert("ROTATE_KEYS_YAW");
        keys.Insert("FINE_KEYS");
        keys.Insert("ITEM_PICKED_UP");
        keys.Insert("WORLD_POSITION");
        keys.Insert("WORLD_ORIENTATION");
        keys.Insert("TRAY_TITLE");
        keys.Insert("TRAY_TITLE_EMPTY");
        keys.Insert("TRAY_EMPTY");
        keys.Insert("TRAY_OWNER");
        keys.Insert("TRAY_SELECTED");
        keys.Insert("TRAY_INVENTORY");
        keys.Insert("CHARACTER_HINT");
        keys.Insert("WORLD_FLIGHT_HINT");
        keys.Insert("ITEM_DRAG_HINT");
        keys.Insert("ITEM_DROP_READY");
        keys.Insert("ITEM_DROP_INVALID");
        keys.Insert("ITEM_DROP_CANCELLED");
        keys.Insert("ITEM_PREVIEW_SELECT");
        keys.Insert("ITEM_PREVIEW_LOADING");
        keys.Insert("ITEM_PREVIEW_UNAVAILABLE");
        keys.Insert("SCENE_OBJECTS_TITLE");
        keys.Insert("SCENE_OBJECTS_TITLE_EMPTY");
        keys.Insert("SCENE_OBJECTS_EMPTY");
        keys.Insert("SCENE_ANCHOR_ROW");
        keys.Insert("SCENE_CHARACTER");
        keys.Insert("SCENE_OBJECT");
        keys.Insert("POSITION_WORLD");
        keys.Insert("SCENE_MOVE_HINT");
        keys.Insert("WORLD_NUMBER_LIMIT");
        keys.Insert("POSITION_SHORT");
        keys.Insert("ROTATION_SHORT");
        keys.Insert("FINE_SETTINGS");
        keys.Insert("COORDINATES_RELATIVE");
        keys.Insert("COORDINATES_WORLD");
        keys.Insert("PROPERTIES_ANCHOR");
        keys.Insert("XML_SELECTION");
        keys.Insert("CAMERA_FLIGHT");
        keys.Insert("CAMERA_CURSOR");
        keys.Insert("CAMERA_HELP");
        keys.Insert("CAMERA_HELP_ENTER");
        keys.Insert("CAMERA_HELP_MOVE");
        keys.Insert("CAMERA_HELP_HEIGHT");
        keys.Insert("CAMERA_HELP_LOOK");
        keys.Insert("CAMERA_HELP_SPEED");
        keys.Insert("CAMERA_HELP_BOOST");
        keys.Insert("CAMERA_HELP_SLOW");
        keys.Insert("SEARCH_ITEMS_PLACEHOLDER");
        keys.Insert("ERROR_TITLE");
        keys.Insert("ANCHOR_DROP_READY");
        keys.Insert("ANCHOR_DROP_REPLACE");
        keys.Insert("REPLACE_TITLE");
        keys.Insert("REPLACE_NAMES");
        keys.Insert("REPLACE_WARNING");
        keys.Insert("REPLACE_CONFIRM");
        keys.Insert("REPLACE_CANCEL");
        keys.Insert("REPLACE_SCENE_CHANGED");
        keys.Insert("REPLACE_NEW");
        keys.Insert("UNDO");
        keys.Insert("REDO");
        keys.Insert("PROJECT_SAVE");
        keys.Insert("PROJECT_OPEN");
        keys.Insert("PROJECT_NAME");
        keys.Insert("PROJECT_NAME_INVALID");
        keys.Insert("PROJECT_FORMAT_INVALID");
        keys.Insert("PROJECT_WORLD_INVALID");
        keys.Insert("PROJECT_CLASS_INVALID");
        keys.Insert("PROJECT_STAGE_FAILED");
        keys.Insert("PROJECT_WRITE_FAILED");
        keys.Insert("PROJECT_OPEN_WARNING");
        keys.Insert("PROJECT_OVERWRITE");
        keys.Insert("PROJECT_OPEN_REPLACE");
        keys.Insert("PROJECT_SAVE_REPLACE");
        keys.Insert("PROJECT_NOT_FOUND");
        keys.Insert("PROJECT_READ_FAILED");
        keys.Insert("PROJECT_JSON_INVALID");
        keys.Insert("TOOLS_PROJECT");
        keys.Insert("TOOLS_HISTORY");
        keys.Insert("TOOLS_EDIT");
        keys.Insert("TOOLS_VIEW");
        keys.Insert("TOOLS_EXPORT");
        keys.Insert("SUCCESS_TITLE");
        keys.Insert("WARNING_TITLE");
        keys.Insert("PROJECT_SAVED");
        keys.Insert("PROJECT_OPENED");
        keys.Insert("ITEM_XML_SAVED");
        keys.Insert("LOOT_VOLUMES");
        keys.Insert("LOOT_SOURCE");
        keys.Insert("LOOT_DATA_UNAVAILABLE");
        keys.Insert("LOOT_GROUP_UNAVAILABLE");
        keys.Insert("LOOT_NO_POINTS");
        keys.Insert("LOOT_DIMENSIONS_UNSPECIFIED");
        keys.Insert("LOOT_FROM_GAME");
        keys.Insert("LOOT_FROM_SNAPSHOT");
        keys.Insert("LOOT_FALLBACK_WARNING");
        return keys;
    }
}
// Scoped flat styles; no replacement of DayZ's global Default widget styles.
class IOTEditorTheme
{
    protected static bool s_Loaded;

    static void Load()
    {
        if (s_Loaded) return;
        LoadWidgetStyles("iot\\proxytool\\gui\\editor.styles");
        s_Loaded = true;
    }

    static int Matte() { return ARGB(255,11,13,15); }
    static int Row() { return ARGB(0,24,27,29); }
    static int RowHover() { return ARGB(62,171,184,194); }
    static int RowSelected() { return ARGB(100,192,203,211); }
    static int Accent() { return ARGB(255,224,210,178); }
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

    static string IndustrialSubcategory(string model)
    {
        if (Category(model) != "INDUSTRIAL") return "OTHER";
        array<string> parts = ModelParts(model);
        if (parts.Count() < 5) return "OTHER";
        string folder = parts[3];
        string filename = parts[parts.Count() - 1];
        if (folder == "containers") return "CONTAINERS";
        if (folder == "cementworks") return "CEMENTWORKS";
        if (folder == "coalplant") return "COALPLANT";
        if (folder == "construction") return "CONSTRUCTION";
        if (folder == "dams" || folder == "dam") return "DAMS";
        if (folder == "farms")
        {
            if (filename.IndexOf("barn_") == 0) return "BARNS";
            return "FARMS";
        }
        if (folder == "garages") return "GARAGES";
        if (folder == "harbour") return "HARBOUR";
        if (folder == "houses")
        {
            if (filename.IndexOf("workshop") == 0 || filename.IndexOf("repair_center") == 0) return "WORKSHOPS";
            if (filename.IndexOf("factory") == 0) return "FACTORIES";
            return "BUILDINGS";
        }
        if (folder == "mines") return "MINES";
        if (folder == "pipes") return "PIPES";
        if (folder == "power" || folder == "powerplant" || folder == "dieselpowerplant" || folder == "windpowerplant" || folder == "solarpowerplant") return "POWER";
        if (folder == "quarry") return "QUARRIES";
        if (folder == "sawmills") return "SAWMILLS";
        if (folder == "sheds") return "SHEDS";
        if (folder == "smokestacks") return "SMOKESTACKS";
        if (folder == "tanks") return "TANKS";
        if (folder == "stockyard") return "STOCKYARDS";
        if (folder == "oilmine" || folder == "oilrefinery") return "OIL";
        if (folder == "irrigation") return "IRRIGATION";
        if (folder == "watertowers") return "WATERTOWERS";
        if (folder == "misc") return "MISC";
        return "OTHER";
    }

    static string IndustrialLabel(string subcategory)
    {
        string key = "INDUSTRIAL_SUB_"+subcategory;
        return IOTL.T(key);
    }

    static array<string> ResidentialFamilies(string subcategory)
    {
        if (subcategory == "HOUSE")
        {
            array<string> houses = {"HOUSE_1W","HOUSE_2W","HOUSE_1B","HOUSE_2B","HOUSE_1C","HOUSE_2C","HOUSE_3C","HOUSE_1M","HOUSE_2M","HOUSE_1S","HOUSE_2S","HOUSE_3S","PUBS","OTHER"};
            return houses;
        }
        if (subcategory == "CITY")
        {
            array<string> city = {"BLOCK_1F","BLOCK_2F","BLOCK_3F","BLOCK_5F","BLOCK_2C","BLOCK_3C","BLOCK_4C","HOSPITALS","POLICE","SCHOOLS","FIRESTATIONS","STORES","KIOSKS","OTHER"};
            return city;
        }
        return new array<string>;
    }

    static string ResidentialFamily(string model)
    {
        string subcategory = ResidentialSubcategory(model);
        if (subcategory != "HOUSE" && subcategory != "CITY") return "";
        array<string> parts = ModelParts(model);
        string filename = parts[parts.Count() - 1];
        if (subcategory == "HOUSE")
        {
            if (filename == "village_pub.p3d" || filename.IndexOf("house_1b01_pub") == 0) return "PUBS";
            array<string> houseFamilies = ResidentialFamilies(subcategory);
            foreach (string houseFamily : houseFamilies)
            {
                if (houseFamily.IndexOf("HOUSE_") != 0) continue;
                string housePrefix = houseFamily;
                housePrefix.ToLower();
                if (filename.IndexOf(housePrefix) == 0) return houseFamily;
            }
            return "OTHER";
        }
        if (subcategory == "CITY")
        {
            if (filename.IndexOf("city_hospital") == 0) return "HOSPITALS";
            if (filename.IndexOf("city_policestation") == 0) return "POLICE";
            if (filename.IndexOf("city_school") == 0) return "SCHOOLS";
            if (filename.IndexOf("city_firestation") == 0) return "FIRESTATIONS";
            if (filename.IndexOf("city_stand_") == 0) return "KIOSKS";
            if (filename.IndexOf("city_store") == 0) return "STORES";
            array<string> cityFamilies = ResidentialFamilies(subcategory);
            foreach (string cityFamily : cityFamilies)
            {
                if (cityFamily.IndexOf("BLOCK_") != 0) continue;
                string blockPrefix = "house"+cityFamily;
                blockPrefix.ToLower();
                if (filename.IndexOf(blockPrefix) == 0) return cityFamily;
            }
            return "OTHER";
        }
        return "";
    }

    static string ResidentialFamilyLabel(string subcategory, string family)
    {
        if (family.IndexOf("HOUSE_") == 0)
        {
            string houseSeries = family.Substring(6,family.Length() - 6);
            return IOTL.T("RESIDENTIAL_FAMILY_HOUSE")+" "+houseSeries;
        }
        if (family.IndexOf("BLOCK_") == 0)
        {
            string blockSeries = family.Substring(6,family.Length() - 6);
            return "HouseBlock "+blockSeries;
        }
        if (family == "OTHER")
        {
            if (subcategory == "CITY") return IOTL.T("RESIDENTIAL_FAMILY_OTHER_CITY");
            return IOTL.T("RESIDENTIAL_FAMILY_OTHER_HOUSE");
        }
        string key = "RESIDENTIAL_FAMILY_"+family;
        return IOTL.T(key);
    }

    static string SpecificSubcategory(string model)
    {
        if (Category(model) != "SPECIFIC") return "OTHER";
        array<string> parts = ModelParts(model);
        if (parts.Count() < 5) return "OTHER";
        string folder = parts[3];
        string filename = parts[parts.Count() - 1];
        if (folder == "castles" || folder == "castle" || folder == "palace") return "CASTLES";
        if (folder == "churches") return "CHURCHES";
        if (folder == "mosques" || folder == "minarets") return "MOSQUES";
        if (folder == "cemeteries" || folder == "cemetery" || folder == "cemetary" || folder == "mausolea") return "CEMETERIES";
        if (folder == "statues" || folder == "monuments") return "MONUMENTS";
        if (folder == "cultural")
        {
            if (filename.IndexOf("church") == 0 || filename.IndexOf("chapel") == 0) return "CHURCHES";
            if (filename.IndexOf("misc_calvary") == 0) return "CEMETERIES";
            if (filename.IndexOf("monument") == 0 || filename.IndexOf("statue") == 0) return "MONUMENTS";
            return "OTHER";
        }
        if (folder == "airfields" || folder == "airport") return "AIRFIELDS";
        if (folder == "cableway" || folder == "skilift") return "CABLEWAYS";
        if (folder == "camps" || folder == "refugeecamp" || folder == "tradtents") return "CAMPS";
        if (folder == "hotel" || folder == "villa" || folder == "caravanserai") return "HOTELS";
        if (folder == "fuelstation") return "FUELSTATIONS";
        if (folder == "prison") return "PRISONS";
        if (folder == "radio" || folder == "towers") return "RADIO";
        if (folder == "lunapark") return "AMUSEMENT";
        if (folder == "tribune") return "SPORTS";
        if (folder == "bazaar") return "MARKETS";
        if (folder == "bordercrossing") return "BORDERS";
        if (folder == "institute" || folder == "volcano") return "RESEARCH";
        if (folder == "forest") return "FOREST";
        if (folder == "deadbodies") return "REMAINS";
        if (folder == "maps") return "MAPS";
        return "OTHER";
    }

    static string SpecificLabel(string subcategory)
    {
        string key = "SPECIFIC_SUB_" + subcategory;
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
            "GEAR/TOOLS","GEAR/TOOLS/CONSTRUCTION","GEAR/TOOLS/METALWORK","GEAR/TOOLS/CUTTING","GEAR/TOOLS/REPAIR","GEAR/TOOLS/OTHER","GEAR/CONTAINERS","GEAR/CAMPING","GEAR/CAMPING/SHELTERS","GEAR/CAMPING/STORAGE","GEAR/CAMPING/BUILDING","GEAR/CAMPING/LOCKS","GEAR/CAMPING/POWER","GEAR/CAMPING/LIGHTING","GEAR/CAMPING/FLAGS","GEAR/CAMPING/OTHER","GEAR/COOKING","GEAR/CRAFTING","GEAR/CULTIVATION","GEAR/MEDICAL","GEAR/NAVIGATION","GEAR/RADIO","GEAR/OPTICS","GEAR/TRAPS","GEAR/BOOKS","GEAR/CONSUMABLES","GEAR/OTHER",
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

    // Explicit placeholder markers and technical naming conventions only.
    // Ordinary names such as BloodTestKit and missing $STR translations remain.
    static string HiddenReason(string classname, string displayName)
    {
        string label = displayName;
        label.TrimInPlace();
        label.ToUpper();
        if (label.Contains("$UNT$") || label == "TODO") return "placeholder";
        string name = classname;
        name.ToLower();
        if (name == "doortestcamera" || name == "m79dummyoptics") return "technical";
        if (name.IndexOf("test_") == 0 || name.IndexOf("debug_") == 0) return "technical";
        if (name.Length() >= 5 && name.Substring(name.Length() - 5,5) == "_test") return "technical";
        if (name.Length() >= 6 && name.Substring(name.Length() - 6,6) == "_debug") return "technical";
        return "";
    }

    protected static string ClothingModelKey(string model)
    {
        model.ToLower();
        model.Replace("\\","/");
        model.Replace("//","/");
        while (model.IndexOf("/") == 0) model = model.Substring(1,model.Length() - 1);
        return model;
    }

    protected static bool ClothingColorBase(string classname)
    {
        classname.ToLower();
        return classname.Length() >= 9 && classname.Substring(classname.Length() - 9,9) == "colorbase";
    }

    static string ClothingFamily(string classname, string model)
    {
        string modelKey = ClothingModelKey(model);
        if (modelKey == "") return classname;
        string family = classname;
        for (int depth = 0; depth < 32; depth++)
        {
            if (ClothingColorBase(family)) break;
            string parent;
            if (!GetGame().ConfigGetBaseName("CfgVehicles "+family,parent) || parent == "" || parent == family) break;
            string parentKey = parent;
            parentKey.ToLower();
            if (parentKey == "clothing" || parentKey == "clothing_base" || parentKey == "inventory_base" || parentKey == "itembase" || parentKey == "default") break;
            string parentModel;
            GetGame().ConfigGetText("CfgVehicles "+parent+" model",parentModel);
            parentModel = ClothingModelKey(parentModel);
            // A ColorBase may leave the ground model to its seasonal variants.
            if (parentModel != modelKey && !(parentModel == "" && ClothingColorBase(parent))) break;
            family = parent;
        }
        return family;
    }

    static string ClothingFamilyLabel(string family, string fallback)
    {
        string label;
        GetGame().ConfigGetText("CfgVehicles "+family+" displayName",label);
        label.TrimInPlace();
        string key = label;
        key.ToUpper();
        if (label == "" || key.IndexOf("$STR") == 0 || key.IndexOf("#STR") == 0 || key.Contains("$UNT$") || key == "TODO") return fallback;
        return label;
    }

    // Applied only to items already classified as GEAR/TOOLS. Model aliases
    // keep modded classes sharing a known tool model in the same subgroup.
    static string ToolSubcategory(string name, string model)
    {
        name.ToLower();
        array<string> parts = IOTCatalogAsset.ModelParts(model);
        string modelFile;
        if (parts.Count() > 0) modelFile = parts[parts.Count() - 1];
        array<string> construction = {"hammer","sledgehammer","shovel","fieldshovel","crowbar","pickaxe","farminghoe","iceaxe"};
        array<string> constructionModels = {"hammer.p3d","sledgehammer.p3d","sledge_hammer.p3d","shovel.p3d","csla_field_shovel.p3d","crowbar.p3d","pickaxe.p3d","farming_hoe.p3d","iceaxe.p3d","ice_axe.p3d"};
        if (construction.Find(name) >= 0 || constructionModels.Find(modelFile) >= 0) return "CONSTRUCTION";
        array<string> metalwork = {"pliers","screwdriver","wrench","lugwrench","lockpick"};
        array<string> metalworkModels = {"pliers.p3d","screwdriver.p3d","wrench.p3d","lug_wrench.p3d","lockpick.p3d"};
        if (metalwork.Find(name) >= 0 || metalworkModels.Find(modelFile) >= 0) return "METALWORK";
        array<string> cutting = {"hacksaw","handsaw","kitchenknife","steakknife","boneknife","stoneknife","cleaver","hatchet","firefighteraxe","sickle"};
        array<string> cuttingModels = {"hacksaw.p3d","handsaw.p3d","hand_saw.p3d","kitchenknife.p3d","steak_knife.p3d","bone_knife.p3d","stone_knife.p3d","cleaver.p3d","hatchet.p3d","firefighter_axe.p3d","sickle.p3d"};
        if (cutting.Find(name) >= 0 || cuttingModels.Find(modelFile) >= 0) return "CUTTING";
        array<string> repair = {"sewingkit","leathersewingkit","weaponcleaningkit","electronicrepairkit","tirerepairkit","epoxyputty","whetstone","blowtorch"};
        array<string> repairModels = {"sewing_kit.p3d","leather_sewing_kit.p3d","cleaning_kit_wood.p3d","electronic_repair_kit.p3d","electronicrepairkit.p3d","electroniccase.p3d","tirerepairkit.p3d","epoxy_putty.p3d","epoxyputty.p3d","whetstone.p3d","blowtorch.p3d"};
        if (repair.Find(name) >= 0 || repairModels.Find(modelFile) >= 0) return "REPAIR";
        return "OTHER";
    }

    // Applied only inside GEAR/CAMPING. Inheritance identifies renamed mod
    // subclasses, while known model filenames cover resource-sharing classes.
    static string CampingSubcategory(string classname, string model)
    {
        array<string> parts = IOTCatalogAsset.ModelParts(model);
        string filename;
        if (parts.Count() > 0) filename = parts[parts.Count() - 1];
        if (GetGame().IsKindOf(classname,"Flag_Base") || GetGame().IsKindOf(classname,"TerritoryFlag") || GetGame().IsKindOf(classname,"TerritoryFlagKit") || filename == "dz_flag.p3d" || filename.IndexOf("territory_flag") == 0) return "FLAGS";
        if (GetGame().IsKindOf(classname,"CombinationLock") || GetGame().IsKindOf(classname,"DigitalCodeLock") || filename.IndexOf("combination_lock") == 0 || filename == "codelock.p3d") return "LOCKS";
        if (GetGame().IsKindOf(classname,"TentBase") || GetGame().IsKindOf(classname,"ShelterKit") || GetGame().IsKindOf(classname,"ShelterSite") || filename.Contains("tent") || filename.IndexOf("shelter_") == 0) return "SHELTERS";
        if (GetGame().IsKindOf(classname,"Container_Base") || GetGame().IsKindOf(classname,"UndergroundStash") || filename.IndexOf("sea_chest") == 0 || filename == "wooden_case.p3d" || filename.IndexOf("underground_stash") == 0) return "STORAGE";
        if (GetGame().IsKindOf(classname,"PowerGenerator") || GetGame().IsKindOf(classname,"BatteryCharger") || GetGame().IsKindOf(classname,"CableReel") || filename == "power_generator.p3d" || filename == "battery_charger.p3d" || filename == "cable_reel.p3d") return "POWER";
        if (GetGame().IsKindOf(classname,"Spotlight") || GetGame().IsKindOf(classname,"XmasLights") || filename == "spotlight.p3d" || filename == "christmas_lights.p3d") return "LIGHTING";
        if (GetGame().IsKindOf(classname,"BaseBuildingBase") || GetGame().IsKindOf(classname,"FenceKit") || GetGame().IsKindOf(classname,"WatchtowerKit") || GetGame().IsKindOf(classname,"BarbedWire") || GetGame().IsKindOf(classname,"BarbedWireLocked") || GetGame().IsKindOf(classname,"CamoNet") || GetGame().IsKindOf(classname,"Fabric") || GetGame().IsKindOf(classname,"HescoBox") || GetGame().IsKindOf(classname,"WoodenLog")) return "BUILDING";
        if (filename.IndexOf("fence") == 0 || filename.IndexOf("watchtower") == 0 || filename.IndexOf("barbed_wire") == 0 || filename == "camo_net_p.p3d" || filename == "fabric_ground.p3d" || filename == "hbox_base.p3d" || filename == "wooden_log.p3d") return "BUILDING";
        return "OTHER";
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
    protected Widget m_ScrollTrack;
    protected Widget m_ScrollThumb;
    protected CanvasWidget m_StaticIcon;
    protected bool m_StaticIconDrawn;
    protected bool m_StaticIconChecked;
    protected ref array<Widget> m_ItemRows = new array<Widget>;
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
    protected ref IOTItemMaps m_ItemMaps = new IOTItemMaps;
    protected ref array<string> m_ItemPaths;
    protected ref map<string,string> m_CustomGroupLabels = new map<string,string>;
    protected ref map<string,string> m_ToolSubcategories = new map<string,string>;
    protected ref map<string,string> m_CampingSubcategories = new map<string,string>;
    protected ref map<string,string> m_ClothingFamilies = new map<string,string>;
    protected ref map<string,string> m_ItemModels = new map<string,string>;
    protected ref map<string,bool> m_Expanded = new map<string,bool>;
    protected ref map<string,bool> m_SearchClosed = new map<string,bool>;
    protected ref array<ref IOTCatalogRow> m_Rows = new array<ref IOTCatalogRow>;
    protected ref array<string> m_AnchorClasses = new array<string>;
    protected ref array<string> m_ItemClasses = new array<string>;
    protected ref array<string> m_KnownItemClasses = new array<string>;
    protected ref map<string,string> m_HiddenItems = new map<string,string>;
    protected ref map<string,string> m_ItemNames = new map<string,string>;
    protected ref array<string> m_Filtered = new array<string>;
    protected ref array<string> m_Categories = {"RESIDENTIAL","INDUSTRIAL","MILITARY","UNDERGROUND","WRECKS","FURNITURE","ROADS","RAIL","WALLS","SIGNS","RUINS","SPECIFIC","PROPS","BUILDING_PARTS","VEGETATION","ROCKS","WATER","TERRAIN","UNCATEGORIZED"};
    protected ref array<string> m_WreckSubcategories = {"VEHICLES","AIRCRAFT","SHIPS","TRAINS","OTHER"};
    protected ref array<string> m_VehicleTypes = {"TRUCK","SEDAN","OFFROAD","HATCHBACK","OTHER"};
    protected ref array<string> m_ResidentialSubcategories = {"SHEDS","OFFICE","MISC","HOUSE","CITY","TENEMENTS","STORES","MEDICAL","POLICE","SCHOOLS","FIREDEP","BUS","SLUMS","PLATFORMS","TERRACES","OTHER"};
    protected ref array<string> m_IndustrialSubcategories = {"CONTAINERS","BARNS","FARMS","CEMENTWORKS","COALPLANT","FACTORIES","WORKSHOPS","GARAGES","BUILDINGS","CONSTRUCTION","SHEDS","SAWMILLS","MINES","QUARRIES","OIL","POWER","HARBOUR","STOCKYARDS","DAMS","IRRIGATION","WATERTOWERS","TANKS","PIPES","SMOKESTACKS","MISC","OTHER"};
    protected ref array<string> m_SpecificSubcategories = {"CASTLES","CHURCHES","MOSQUES","CEMETERIES","MONUMENTS","AIRFIELDS","CABLEWAYS","CAMPS","HOTELS","FUELSTATIONS","PRISONS","RADIO","AMUSEMENT","SPORTS","MARKETS","BORDERS","RESEARCH","FOREST","REMAINS","MAPS","OTHER"};

    void IOTSceneBrowser(IOTProxyTool tool)
    {
        m_Tool = tool;
        m_Root = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\scene_browser.layout");
        m_Search = EditBoxWidget.Cast(m_Root.FindAnyWidget("SceneSearch"));
        m_SearchPlaceholder = TextWidget.Cast(m_Root.FindAnyWidget("SceneSearchPlaceholder"));
        m_Results = TextListboxWidget.Cast(m_Root.FindAnyWidget("SceneResults"));
        m_ItemScroll = ScrollWidget.Cast(m_Root.FindAnyWidget("SceneItemScroll"));
        m_ItemContent = m_Root.FindAnyWidget("SceneItemRows");
        m_ScrollTrack = m_Root.FindAnyWidget("CatalogScrollTrack");
        m_ScrollThumb = m_Root.FindAnyWidget("CatalogScrollThumb");
        m_StaticIcon = CanvasWidget.Cast(m_Root.FindAnyWidget("SceneShowStaticIcon"));
        m_HoverRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\item_hover_preview.layout");
        m_HoverView = ItemPreviewWidget.Cast(m_HoverRoot.FindAnyWidget("HoverItemModel"));
        m_HoverClass = MultilineTextWidget.Cast(m_HoverRoot.FindAnyWidget("HoverItemClass"));
        TextWidget.Cast(m_HoverRoot.FindAnyWidget("HoverClassTitle")).SetText(IOTL.T("CLASSNAME"));
        m_HoverEmpty = TextWidget.Cast(m_HoverRoot.FindAnyWidget("HoverItemEmpty"));
        m_HoverEmpty.SetFlags(WidgetFlags.CENTER | WidgetFlags.VCENTER);
        m_HoverEmpty.SetText(IOTL.T("ITEM_PREVIEW_UNAVAILABLE"));
        m_HoverRoot.Show(false);
        m_ShowStatic = CheckBoxWidget.Cast(m_Root.FindAnyWidget("SceneShowStatic"));
        float panelWidth,panelHeight;
        m_Root.GetScreenSize(panelWidth,panelHeight);
        m_PanelScale = panelWidth/360;
        m_ShowStatic.SetChecked(false);
        m_Expanded.Set("objects",true);
        m_Expanded.Set("items",true);
        IOTMapCatalog.Populate(m_MapMasks);
        m_ItemMaps.Load();
        m_ItemPaths = IOTItemCatalog.Paths();
        LoadCatalog();
        m_ItemScroll.SetHandler(this);
        m_Root.SetHandler(this);
        SetMode(false);
        DrawSearchIcon();
        UpdateTheme();
    }

    void UpdateTheme()
    {
        // The ScrollWidget owns its native scrollbar and its mouse handling.
        // Pointer-transparent chrome only replaces the hard-coded red drawing.
        bool scrolling = m_Root.IsVisible() && m_ItemScroll.IsVisible() && m_ItemScroll.IsScrollbarVisible();
        m_ScrollTrack.Show(scrolling);
        if (scrolling)
        {
            float x,y,width,height;
            m_ItemScroll.GetScreenPos(x,y);
            m_ItemScroll.GetScreenSize(width,height);
            float trackWidth = Math.Max(8*m_PanelScale,m_ItemScroll.GetScrollbarWidth());
            m_ScrollTrack.SetScreenPos(x+width - trackWidth,y);
            m_ScrollTrack.SetScreenSize(trackWidth,height);
            float contentWidth,contentHeight;
            m_ItemContent.GetScreenSize(contentWidth,contentHeight);
            float thumbHeight = Math.Min(height,Math.Max(18*m_PanelScale,height*height/Math.Max(height,contentHeight)));
            float thumbWidth = Math.Min(trackWidth,4*m_PanelScale);
            float thumbY = (height - thumbHeight)*Math.Clamp(m_ItemScroll.GetVScrollPos01(),0,1);
            m_ScrollThumb.SetScreenPos(x+width - (trackWidth+thumbWidth)*0.5,y+thumbY);
            m_ScrollThumb.SetScreenSize(thumbWidth,thumbHeight);
        }

        bool checked = m_ShowStatic.IsChecked();
        if (m_StaticIconDrawn && checked == m_StaticIconChecked) return;
        m_StaticIconDrawn = true;
        m_StaticIconChecked = checked;
        float iconWidth,iconHeight;
        m_StaticIcon.GetScreenSize(iconWidth,iconHeight);
        float scale = Math.Min(iconWidth,iconHeight)/16;
        float stroke = Math.Max(1,scale);
        int color = ARGB(255,200,204,205);
        m_StaticIcon.Clear();
        m_StaticIcon.DrawLine(1*scale,1*scale,15*scale,1*scale,stroke,color);
        m_StaticIcon.DrawLine(15*scale,1*scale,15*scale,15*scale,stroke,color);
        m_StaticIcon.DrawLine(15*scale,15*scale,1*scale,15*scale,stroke,color);
        m_StaticIcon.DrawLine(1*scale,15*scale,1*scale,1*scale,stroke,color);
        if (checked)
        {
            m_StaticIcon.DrawLine(4*scale,8*scale,7*scale,11*scale,2*stroke,IOTEditorTheme.Accent());
            m_StaticIcon.DrawLine(7*scale,11*scale,12*scale,5*scale,2*stroke,IOTEditorTheme.Accent());
        }
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
        // Buildings need no temporary collision envelope for this renderer.
        if (!m_ItemsMode) flags = flags & ~ECE_CREATEPHYSICS;
        Object created = GetGame().CreateObjectEx(classname,"0 -1000 0",flags,RF_IGNORE);
        EntityAI entity = EntityAI.Cast(created);
        #ifdef DEVELOPER
        DayZGame.m_IsPreviewSpawn = false;
        #endif
        if (!entity)
        {
            if (created) GetGame().ObjectDelete(created);
            return null;
        }
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
            int color = IOTEditorTheme.Row();
            if (i == m_HoverRow) color = IOTEditorTheme.RowHover();
            if (i == selected) color = IOTEditorTheme.RowSelected();
            m_ItemRows[i].FindAnyWidget("CatalogItemBackground").SetColor(color);
            m_ItemRows[i].FindAnyWidget("CatalogItemAccent").Show(i == selected);
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
        if (enabled && m_Root.IsVisible()) row = ItemRowAt(point);
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
        float footer = 12;
        float listHeight = 228*m_PanelScale;
        if (m_CatalogHeight > 0) listHeight = Math.Max(24*m_PanelScale,m_CatalogHeight - (161+footer)*m_PanelScale);
        m_Results.SetScreenSize(328*m_PanelScale,listHeight);
        m_ItemScroll.SetScreenSize(328*m_PanelScale,listHeight);
        m_Root.SetScreenSize(360*m_PanelScale,161*m_PanelScale+listHeight+footer*m_PanelScale);
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
        if (category == "SPECIFIC") subcategory = IOTCatalogAsset.SpecificSubcategory(model);
        if (category == "INDUSTRIAL") subcategory = IOTCatalogAsset.IndustrialSubcategory(model);
        string family;
        if (category == "WRECKS" && subcategory == "VEHICLES") family = IOTCatalogAsset.VehicleSubcategory(model);
        if (category == "RESIDENTIAL") family = IOTCatalogAsset.ResidentialFamily(model);
        for (int mapIndex = 1; mapIndex <= 5; mapIndex++)
        {
            if (mapIndex == 5 && mask != 0) continue;
            int mapBit = 1 << (mapIndex - 1);
            int belongs = mask & mapBit;
            if (mapIndex < 5 && belongs == 0) continue;
            string key = MapKey(mapIndex)+"/"+category;
            if (subcategory != "") key += "/"+subcategory;
            if (family != "") key += "/"+family;
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
        if (m_KnownItemClasses.Find(name) >= 0) return;
        m_KnownItemClasses.Insert(name);
        // ConfigGetText resolves inherited displayName stringtable entries
        // in the client language without constructing an inventory entity.
        string displayName;
        GetGame().ConfigGetText(root+" "+name+" displayName",displayName);
        displayName.TrimInPlace();
        string hiddenReason = IOTItemCatalog.HiddenReason(name,displayName);
        if (hiddenReason != "")
        {
            m_HiddenItems.Insert(name,hiddenReason);
            PrintToRPT("[PROXY CATALOG HIDDEN] "+name+" reason="+hiddenReason);
            return;
        }
        m_ItemClasses.Insert(name);
        string key = displayName;
        key.ToUpper();
        if (displayName == "" || key.IndexOf("$STR") == 0 || key.IndexOf("#STR") == 0) displayName = name;
        m_ItemNames.Set(name,displayName);
        m_ItemModels.Set(name,model);
        string path = IOTItemCatalog.Group(name,model,root);
        if (path == "GEAR/TOOLS") m_ToolSubcategories.Set(name,IOTItemCatalog.ToolSubcategory(name,model));
        if (path == "GEAR/CAMPING") m_CampingSubcategories.Set(name,IOTItemCatalog.CampingSubcategory(name,model));
        if (path.IndexOf("CLOTHING/") == 0) m_ClothingFamilies.Set(name,IOTItemCatalog.ClothingFamily(name,model));
        key = "items/"+m_ItemMaps.ForClass(name)+"/"+path;
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

    protected void SplitLargeToolGroup()
    {
        array<string> branches = IOTItemMaps.Branches();
        foreach (string branch : branches)
        {
            string parent = "items/"+branch+"/GEAR/TOOLS";
            IOTCatalogGroup tools = m_ItemGroups.Get(parent);
            if (!tools || tools.Classes.Count() <= 30) continue;
            foreach (string classname : tools.Classes)
            {
                string subcategory = m_ToolSubcategories.Get(classname);
                if (subcategory == "") subcategory = "OTHER";
                string key = parent+"/"+subcategory;
                IOTCatalogGroup group = m_ItemGroups.Get(key);
                if (!group)
                {
                    group = new IOTCatalogGroup;
                    group.Category = "GEAR";
                    m_ItemGroups.Insert(key,group);
                }
                group.Classes.Insert(classname);
            }
            m_ItemGroups.Remove(parent);
        }
    }

    string ItemMapBranch(string classname) { return m_ItemMaps.ForClass(classname); }
    int ItemMapMask(string classname) { return m_ItemMaps.Mask(classname); }
    int ItemMapSources() { return m_ItemMaps.ReadableMaps(); }
    string ClothingFamilyOf(string classname) { return m_ClothingFamilies.Get(classname); }

    protected void SplitLargeCampingGroup()
    {
        array<string> branches = IOTItemMaps.Branches();
        foreach (string branch : branches)
        {
            string parent = "items/"+branch+"/GEAR/CAMPING";
            IOTCatalogGroup source = m_ItemGroups.Get(parent);
            if (!source || source.Classes.Count() <= 30) continue;
            foreach (string classname : source.Classes)
            {
                string subcategory = m_CampingSubcategories.Get(classname);
                if (subcategory == "") subcategory = "OTHER";
                string key = parent+"/"+subcategory;
                IOTCatalogGroup target = m_ItemGroups.Get(key);
                if (!target)
                {
                    target = new IOTCatalogGroup;
                    target.Category = "GEAR";
                    m_ItemGroups.Insert(key,target);
                }
                target.Classes.Insert(classname);
            }
            m_ItemGroups.Remove(parent);
        }
    }

    string ItemGroupLabel(string path)
    {
        string label = m_CustomGroupLabels.Get(path);
        if (label != "") return label;
        return IOTItemCatalog.Label(path);
    }

    protected void SplitWeaponGroups()
    {
        array<string> branches = IOTItemMaps.Branches();
        array<string> sections = {"WEAPONS/FIREARMS","AMMO/MAGAZINES"};
        foreach (string branch : branches)
        {
            foreach (string section : sections)
            {
                string parent = "items/"+branch+"/"+section;
                IOTCatalogGroup source = m_ItemGroups.Get(parent);
                if (!source || source.Classes.Count() <= 30) continue;
                foreach (string classname : source.Classes)
                {
                    string caliber;
                    if (section == "WEAPONS/FIREARMS")
                    {
                        caliber = IOTWeaponCatalog.WeaponCaliber(classname);
                    }
                    else
                    {
                        caliber = IOTWeaponCatalog.MagazineCaliber(classname);
                    }
                    string code = "CAL_"+caliber;
                    string label = IOTWeaponCatalog.CaliberLabel(caliber);
                    string path = section+"/"+code;
                    m_CustomGroupLabels.Set(path,label);
                    string key = "items/"+branch+"/"+path;
                    IOTCatalogGroup target = m_ItemGroups.Get(key);
                    if (!target)
                    {
                        target = new IOTCatalogGroup;
                        target.Category = source.Category;
                        m_ItemGroups.Insert(key,target);
                    }
                    target.Classes.Insert(classname);
                }
                m_ItemGroups.Remove(parent);
            }
        }
    }

    protected void SplitClothingGroups()
    {
        array<string> branches = IOTItemMaps.Branches();
        array<string> sections = IOTItemCatalog.Paths();
        foreach (string branch : branches)
        {
            foreach (string section : sections)
            {
                if (section.IndexOf("CLOTHING/") != 0) continue;
                string parent = "items/"+branch+"/"+section;
                IOTCatalogGroup source = m_ItemGroups.Get(parent);
                if (!source || source.Classes.Count() <= 30) continue;
                map<string,ref array<string>> families = new map<string,ref array<string>>;
                foreach (string classname : source.Classes)
                {
                    string family = m_ClothingFamilies.Get(classname);
                    if (family == "") family = classname;
                    string kind = IOTCatalogSubgroups.ClothingKind(section,family);
                    string familyKey = kind+"|"+family;
                    array<string> members = families.Get(familyKey);
                    if (!members)
                    {
                        members = new array<string>;
                        families.Insert(familyKey,members);
                    }
                    members.Insert(classname);
                }
                source.Classes.Clear();
                foreach (string bucket, array<string> variants : families)
                {
                    string path = section;
                    string variantFamily = m_ClothingFamilies.Get(variants[0]);
                    if (variantFamily == "") variantFamily = variants[0];
                    string variantKind = IOTCatalogSubgroups.ClothingKind(section,variantFamily);
                    if (variantKind != "")
                    {
                        RegisterSubgroupLabels(section,variantKind);
                        path += "/"+variantKind;
                    }
                    if (variants.Count() > 1)
                    {
                        path += "/MODEL_"+variantFamily;
                        m_CustomGroupLabels.Set(path,IOTItemCatalog.ClothingFamilyLabel(variantFamily,ItemName(variants[0])));
                    }
                    string key = "items/"+branch+"/"+path;
                    IOTCatalogGroup target = m_ItemGroups.Get(key);
                    if (!target)
                    {
                        target = new IOTCatalogGroup;
                        target.Category = "CLOTHING";
                        m_ItemGroups.Insert(key,target);
                    }
                    foreach (string variant : variants) target.Classes.Insert(variant);
                }
                if (source.Classes.Count() == 0) m_ItemGroups.Remove(parent);
            }
        }
    }

    protected void RegisterSubgroupLabels(string section, string code)
    {
        array<string> parts = new array<string>;
        code.Split("/",parts);
        string path = section;
        foreach (string part : parts)
        {
            path += "/"+part;
            m_CustomGroupLabels.Set(path,IOTCatalogSubgroups.Label(part));
        }
    }

    protected void SplitAdditionalGroups()
    {
        array<string> branches = IOTItemMaps.Branches();
        array<string> sections = IOTCatalogSubgroups.Sections();
        foreach (string branch : branches)
        {
            foreach (string section : sections)
            {
                string parent = "items/"+branch+"/"+section;
                IOTCatalogGroup source = m_ItemGroups.Get(parent);
                if (!source || source.Classes.Count() <= 30) continue;
                foreach (string classname : source.Classes)
                {
                    string code = IOTCatalogSubgroups.Group(section,classname,m_ItemModels.Get(classname));
                    RegisterSubgroupLabels(section,code);
                    string key = parent+"/"+code;
                    IOTCatalogGroup target = m_ItemGroups.Get(key);
                    if (!target)
                    {
                        target = new IOTCatalogGroup;
                        target.Category = source.Category;
                        m_ItemGroups.Insert(key,target);
                    }
                    target.Classes.Insert(classname);
                }
                m_ItemGroups.Remove(parent);
            }
        }
    }

    protected void RegisterCustomItemPaths()
    {
        array<string> customPaths = new array<string>;
        foreach (string customPath, string customLabel : m_CustomGroupLabels) customPaths.Insert(customPath);
        customPaths.Sort();
        foreach (string addedPath : customPaths)
        {
            m_ItemPaths.Insert(addedPath);
            PrintToRPT("[PROXY ITEM GROUP] "+addedPath+" label="+m_CustomGroupLabels.Get(addedPath));
        }
    }

    string ItemGroupPath(string classname)
    {
        foreach (string key, IOTCatalogGroup group : m_ItemGroups)
        {
            if (group.Classes.Find(classname) >= 0) return key.Substring(6,key.Length() - 6);
        }
        return "";
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
        SplitLargeToolGroup();
        SplitLargeCampingGroup();
        SplitWeaponGroups();
        SplitClothingGroups();
        SplitAdditionalGroups();
        RegisterCustomItemPaths();
        m_AnchorClasses.Sort();
        m_ItemClasses.Sort();
        m_KnownItemClasses.Sort();
        foreach (string groupKey, IOTCatalogGroup group : m_Groups) group.Classes.Sort();
        foreach (string itemKey, IOTCatalogGroup itemGroup : m_ItemGroups) itemGroup.Classes.Sort();
        PrintToRPT("[PROXY CATALOG] Anchors="+m_AnchorClasses.Count().ToString()+" items="+m_ItemClasses.Count().ToString()+" hidden="+m_HiddenItems.Count().ToString());
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
        if (names.Count() != m_ItemClasses.Count() || count != m_ItemClasses.Count() || m_KnownItemClasses.Count() != count+m_HiddenItems.Count()) return false;
        foreach (string classname : m_KnownItemClasses)
        {
            if (names.Contains(classname) == m_HiddenItems.Contains(classname)) return false;
        }
        return true;
    }

    int HiddenItemCount() { return m_HiddenItems.Count(); }
    int KnownItemCount() { return m_KnownItemClasses.Count(); }

    protected static string AuditCsvField(string value)
    {
        value.Replace("\"","\"\"");
        return "\""+value+"\"";
    }

    // Developer catalog-only runs write the actual post-grouping inventory.
    // Counts distinguish direct item lists from folders with descendants.
    bool WriteItemCatalogAudit(string path)
    {
        FileHandle file = OpenFile(path,FileMode.WRITE);
        if (!file) return false;
        FPrintln(file,"Path,Group,Classname,Name");
        foreach (string key, IOTCatalogGroup group : m_ItemGroups)
        {
            array<string> parts = new array<string>;
            key.Split("/",parts);
            string caption = IOTItemMaps.Label(parts[1]);
            string relative = "";
            for (int partIndex = 2; partIndex < parts.Count(); partIndex++)
            {
                if (relative != "") relative += "/";
                relative += parts[partIndex];
                caption += " > "+ItemGroupLabel(relative);
            }
            foreach (string classname : group.Classes)
                FPrintln(file,AuditCsvField(key)+","+AuditCsvField(caption)+","+AuditCsvField(classname)+","+AuditCsvField(ItemName(classname)));
        }
        CloseFile(file);
        PrintToRPT("[PROXY CATALOG AUDIT] "+path+" items="+m_ItemClasses.Count().ToString());
        return FileExist(path);
    }

    string ResolveClass(string value, bool items)
    {
        value.TrimInPlace();
        value.ToLower();
        array<string> source = m_AnchorClasses;
        if (items) source = m_KnownItemClasses;
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
                if (cat == "SPECIFIC")
                {
                    BuildSpecificRows(categoryKey,matches);
                    continue;
                }
                if (cat == "INDUSTRIAL")
                {
                    BuildIndustrialRows(categoryKey,matches);
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
        map<string,int> branchCounts = new map<string,int>;
        foreach (string key, IOTCatalogGroup group : m_ItemGroups)
        {
            array<string> found = new array<string>;
            foreach (string name : group.Classes) { if (MatchesQuery(name,query)) found.Insert(name); }
            matches.Insert(key,found);
            array<string> parts = new array<string>;
            key.Split("/",parts);
            string branch = "items";
            for (int i = 1; i < parts.Count(); i++)
            {
                branch += "/"+parts[i];
                branchCounts.Set(branch,branchCounts.Get(branch)+found.Count());
            }
            m_MatchCount += found.Count();
        }
        AddFolder("items",IOTL.T("ITEMS"),m_MatchCount,"");
        if (!FolderOpen("items")) return;
        array<string> branches = IOTItemMaps.Branches();
        array<string> categories = IOTItemCatalog.Categories();
        foreach (string mapBranch : branches)
        {
            string mapKey = "items/"+mapBranch;
            int mapCount = branchCounts.Get(mapKey);
            if (mapCount == 0) continue;
            AddFolder(mapKey,IOTItemMaps.Label(mapBranch),mapCount,"  ");
            if (!FolderOpen(mapKey)) continue;
            foreach (string category : categories)
            {
                string categoryKey = mapKey+"/"+category;
                int count = branchCounts.Get(categoryKey);
                if (count == 0) continue;
                AddFolder(categoryKey,IOTItemCatalog.Label(category),count,"    ");
                if (FolderOpen(categoryKey)) BuildItemBranch(mapBranch,category,matches,branchCounts,"      ");
            }
        }
    }

    protected void BuildItemBranch(string mapBranch, string parent, map<string,ref array<string>> matches, map<string,int> branchCounts, string indent)
    {
        string parentKey = "items/"+mapBranch+"/"+parent;
        string prefix = parent+"/";
        foreach (string path : m_ItemPaths)
        {
            if (path.IndexOf(prefix) != 0) continue;
            string child = path.Substring(prefix.Length(),path.Length() - prefix.Length());
            if (child.IndexOf("/") >= 0) continue;
            string key = "items/"+mapBranch+"/"+path;
            int count = branchCounts.Get(key);
            if (count == 0) continue;
            AddFolder(key,ItemGroupLabel(path),count,indent);
            if (FolderOpen(key)) BuildItemBranch(mapBranch,path,matches,branchCounts,indent+"  ");
        }
        array<string> classes = matches.Get(parentKey);
        if (classes)
        {
            foreach (string classname : classes) AddRow(parentKey+"/"+classname,indent+"  "+ItemName(classname),classname);
        }
    }

    protected void BuildResidentialRows(string parentKey, map<string,ref array<string>> matches)
    {
        foreach (string subcategory : m_ResidentialSubcategories)
        {
            string key = parentKey+"/"+subcategory;
            array<string> classes = matches.Get(key);
            array<string> families = IOTCatalogAsset.ResidentialFamilies(subcategory);
            int count = 0;
            if (classes) count = classes.Count();
            foreach (string family : families)
            {
                array<string> members = matches.Get(key+"/"+family);
                if (members) count += members.Count();
            }
            if (count == 0) continue;
            AddFolder(key,IOTCatalogAsset.ResidentialLabel(subcategory),count,"      ");
            if (!FolderOpen(key)) continue;
            foreach (string familyKey : families)
            {
                string childKey = key+"/"+familyKey;
                array<string> children = matches.Get(childKey);
                if (!children || children.Count() == 0) continue;
                AddFolder(childKey,IOTCatalogAsset.ResidentialFamilyLabel(subcategory,familyKey),children.Count(),"        ");
                if (FolderOpen(childKey))
                {
                    foreach (string childClass : children) AddRow(childKey+"/"+childClass,"            "+childClass,childClass);
                }
            }
            if (classes)
            {
                foreach (string classname : classes) AddRow(key+"/"+classname,"          "+classname,classname);
            }
        }
    }

    protected void BuildIndustrialRows(string parentKey, map<string,ref array<string>> matches)
    {
        foreach (string subcategory : m_IndustrialSubcategories)
        {
            string key = parentKey+"/"+subcategory;
            array<string> classes = matches.Get(key);
            if (!classes || classes.Count() == 0) continue;
            AddFolder(key,IOTCatalogAsset.IndustrialLabel(subcategory),classes.Count(),"      ");
            if (!FolderOpen(key)) continue;
            foreach (string classname : classes) AddRow(key+"/"+classname,"          "+classname,classname);
        }
    }

    protected void BuildSpecificRows(string parentKey, map<string,ref array<string>> matches)
    {
        foreach (string subcategory : m_SpecificSubcategories)
        {
            string key = parentKey+"/"+subcategory;
            array<string> classes = matches.Get(key);
            if (!classes || classes.Count() == 0) continue;
            AddFolder(key,IOTCatalogAsset.SpecificLabel(subcategory),classes.Count(),"      ");
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

    int MapForClass(string classname)
    {
        if (m_ItemsMode) return 0;
        int row = m_Results.GetSelectedRow();
        if (row < 0 || row >= m_Rows.Count() || m_Rows[row].ClassName != classname) return 0;
        string key = m_Rows[row].Key;
        if (key.IndexOf("map:") != 0) return 0;
        int index = key.Substring(4,1).ToInt();
        if (index >= 1 && index <= 4) return index;
        return 0;
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
            float delta = 2*24*m_PanelScale;
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
    protected int m_VisibleRows;

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
    int VisibleRows() { return m_VisibleRows; }
    void Show(bool visible) { m_Root.Show(visible); }

    void Position(Widget browser)
    {
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float x,y,width,height;
        browser.GetScreenPos(x,y);
        browser.GetScreenSize(width,height);
        float scale = width/360;
        float bottom = screenHeight - Math.Max(54,24*scale);
        float space = bottom - y;
        // Reserve the catalog header and several rows before growing the scene.
        m_VisibleRows = Math.Clamp(Math.Floor((space - 326*scale)/(24*scale)),1,10);
        float sceneHeight = (54+m_VisibleRows*24)*scale;
        float currentX,currentY,currentWidth,currentHeight;
        m_Root.GetScreenPos(currentX,currentY);
        m_Root.GetScreenSize(currentWidth,currentHeight);
        if (Math.AbsFloat(currentWidth - width) > 0.1 || Math.AbsFloat(currentHeight - sceneHeight) > 0.1) m_Root.SetScreenSize(width,sceneHeight);
        m_List.GetScreenSize(currentWidth,currentHeight);
        if (Math.AbsFloat(currentWidth - width+32*scale) > 0.1 || Math.AbsFloat(currentHeight - m_VisibleRows*24*scale) > 0.1)
        {
            m_List.SetPos(16*scale,46*scale);
            m_List.SetScreenSize(width - 32*scale,m_VisibleRows*24*scale);
        }
        if (Math.AbsFloat(currentX - x) > 0.1 || Math.AbsFloat(currentY - bottom+sceneHeight) > 0.1) m_Root.SetScreenPos(x,bottom - sceneHeight);
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
                if (entry.Anchor == active) color = IOTEditorTheme.Accent();
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
    protected Widget m_Matte;
    protected ref array<Widget> m_Backdrop = new array<Widget>;
    protected bool m_BackdropLoadFailed;
    protected vector m_MatteOrigin;
    protected vector m_MatteSize;
    protected int m_ScreenWidth;
    protected int m_ScreenHeight;
    protected bool m_MatteValid;
    protected float m_Left;
    protected float m_Top;
    protected float m_Right;
    protected float m_Bottom;
    protected bool m_Valid;
    protected bool m_Active;

    void IOTEditorViewport()
    {
        m_Root = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\editor_viewport.layout");
        m_Matte = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\editor_matte.layout");
        if (m_Matte) { m_Matte.SetSort(-200); m_Matte.Show(false); }
        if (m_Root) { m_Root.SetSort(-100); m_Root.Show(false); }
    }

    void ~IOTEditorViewport()
    {
        foreach (Widget frame : m_Backdrop) if (frame) frame.Unlink();
        if (m_Root) m_Root.Unlink();
        if (m_Matte) m_Matte.Unlink();
    }

    bool Ready() { return m_Root != null && m_Matte != null; }
    Widget MatteRoot() { return m_Matte; }
    Widget BackdropPart(int index)
    {
        if (index >= m_Backdrop.Count()) return null;
        return m_Backdrop[index];
    }
    bool IsVisible() { return m_Root && m_Root.IsVisible(); }
    vector Origin() { return Vector(m_Left,m_Top,0); }
    vector Size() { return Vector(m_Right-m_Left,m_Bottom-m_Top,0); }
    vector Center() { return (Origin()+Vector(m_Right,m_Bottom,0))*0.5; }

    void Show(bool visible)
    {
        if (!visible)
        {
            m_Valid = false;
            m_MatteValid = false;
        }
        if (m_Root) m_Root.Show(visible && m_Valid);
        if (m_Matte) m_Matte.Show(visible);
        if (!visible) foreach (Widget frame : m_Backdrop) frame.Show(false);
    }

    protected bool LoadBackdrop()
    {
        if (m_BackdropLoadFailed) return false;
        if (m_Backdrop.Count() == 4) return true;
        int flags = WidgetFlags.HEXACTPOS | WidgetFlags.VEXACTPOS | WidgetFlags.HEXACTSIZE | WidgetFlags.VEXACTSIZE | WidgetFlags.IGNOREPOINTER;
        int imageFlags = flags | WidgetFlags.VISIBLE | WidgetFlags.BLEND | WidgetFlags.SOURCEALPHA | WidgetFlags.STRETCH;
        string texture = "iot\\proxytool\\gui\\editor_backdrop.edds";
        for (int index = 0; index < 4; index++)
        {
            // Leave the native sort-zero layer available for ItemPreviewWidget.
            Widget frame = GetGame().GetWorkspace().CreateWidget(FrameWidgetTypeID,0,0,1,1,flags | WidgetFlags.CLIPCHILDREN,ARGB(255,255,255,255),-150);
            ImageWidget image;
            if (frame)
            {
                m_Backdrop.Insert(frame);
                image = ImageWidget.Cast(GetGame().GetWorkspace().CreateWidget(ImageWidgetTypeID,0,0,1,1,imageFlags,ARGB(255,255,255,255),0,frame));
            }
            if (!image || !image.LoadImageFile(0,texture))
            {
                foreach (Widget loaded : m_Backdrop) loaded.Unlink();
                m_Backdrop.Clear();
                m_BackdropLoadFailed = true;
                PrintToRPT("[PROXY THEME] Backdrop texture failed to load.");
                return false;
            }
        }
        PrintToRPT("[PROXY THEME] Backdrop texture loaded.");
        return true;
    }

    protected void BackdropRect(int index, float x, float y, float width, float height, float u0, float v0, float u1, float v1)
    {
        Widget frame = m_Backdrop[index];
        frame.Show(width > 0 && height > 0);
        if (!frame.IsVisible()) return;
        frame.SetScreenPos(x,y);
        frame.SetScreenSize(width,height);
        Widget image = frame.GetChildren();
        float scaleX = width/(u1-u0);
        float scaleY = height/(v1-v0);
        image.SetPos(-u0*scaleX,-v0*scaleY);
        image.SetScreenSize(1024*scaleX,512*scaleY);
    }

    protected void LayoutBackdrop(int width, int height)
    {
        if (!m_Valid)
        {
            foreach (Widget frame : m_Backdrop) frame.Show(false);
            return;
        }
        if (!LoadBackdrop()) return;
        // The source atlas has a cutout from (156,54) to (854,498).
        // Fit the four opaque strips independently so no margins show on resize.
        BackdropRect(0,0,0,width,m_Top,0,0,1024,53);
        BackdropRect(1,0,m_Bottom,width,height - m_Bottom,0,499,1024,512);
        BackdropRect(2,0,m_Top,m_Left,m_Bottom - m_Top,0,55,155,497);
        BackdropRect(3,m_Right,m_Top,width - m_Right,m_Bottom - m_Top,855,55,1024,497);
    }

    protected void MatteRect(string name, float x, float y, float width, float height)
    {
        Widget panel = m_Matte.FindAnyWidget(name);
        panel.SetScreenPos(x,y);
        panel.SetScreenSize(Math.Max(0,width),Math.Max(0,height));
        panel.SetColor(IOTEditorTheme.Matte());
        panel.Show(width > 0 && height > 0);
    }

    protected void LayoutMatte(int width, int height)
    {
        if (!m_Matte) return;
        vector origin = Origin();
        vector size = Size();
        if (m_ScreenWidth != width || m_ScreenHeight != height || m_MatteValid != m_Valid || vector.Distance(origin,m_MatteOrigin) > 0.01 || vector.Distance(size,m_MatteSize) > 0.01)
        {
            m_Matte.SetScreenPos(0,0);
            m_Matte.SetScreenSize(width,height);
            if (m_Valid)
            {
                MatteRect("MatteTop",0,0,width,m_Top);
                MatteRect("MatteBottom",0,m_Bottom,width,height - m_Bottom);
                MatteRect("MatteLeft",0,m_Top,m_Left,m_Bottom - m_Top);
                MatteRect("MatteRight",m_Right,m_Top,width - m_Right,m_Bottom - m_Top);
            }
            else
            {
                MatteRect("MatteTop",0,0,width,height);
                MatteRect("MatteBottom",0,0,0,0);
                MatteRect("MatteLeft",0,0,0,0);
                MatteRect("MatteRight",0,0,0,0);
            }
            m_ScreenWidth = width;
            m_ScreenHeight = height;
            m_MatteOrigin = origin;
            m_MatteSize = size;
            m_MatteValid = m_Valid;
            LayoutBackdrop(width,height);
        }
        m_Matte.Show(true);
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
        m_Left = Math.Ceil(m_Left); m_Top = Math.Ceil(m_Top);
        m_Right = Math.Floor(m_Right); m_Bottom = Math.Floor(m_Bottom);
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
        LayoutMatte(screenWidth,screenHeight);
    }

    bool Contains(vector point)
    {
        return m_Valid && point[0] >= m_Left && point[0] < m_Right && point[1] >= m_Top && point[1] < m_Bottom;
    }

    void SetActive(bool active)
    {
        if (!m_Root || active == m_Active) return;
        m_Active = active;
        int color = ARGB(95,185,189,190);
        if (active) color = ARGB(190,224,210,178);
        Widget edge = m_Root.GetChildren();
        while (edge) { edge.SetColor(color); edge = edge.GetSibling(); }
    }
}

class IOTProjectObject
{
    string Classname;
    vector Position;
    vector Orientation;
}

class IOTProjectData
{
    int Version;
    string WorldName;
    int LootMap; // Optional in version 1: 0 auto, 1..4 official CE reference map.
    ref IOTProjectObject Anchor;
    ref array<ref IOTProjectObject> Items = new array<ref IOTProjectObject>;
    vector CharacterPosition;
    vector CameraPosition;
    vector CameraOrientation;
    float CameraSpeed;
}

class IOTProjectFiles
{
    static string Folder() { return "$profile:ProxyPlacement/Projects"; }

    static bool ValidName(string name)
    {
        name.TrimInPlace();
        if (name == "" || name.Length() > 80 || name.Contains("..") || name.Substring(name.Length() - 1,1) == ".") return false;
        string forbidden = "<>:\"/\\|?*\r\n\t";
        for (int i = 0; i < name.Length(); i++)
            if (forbidden.Contains(name.Substring(i,1))) return false;
        return true;
    }

    static string Path(string name) { return Folder()+"/"+name+".json"; }

    static array<string> Names()
    {
        array<string> names = new array<string>;
        string filename;
        FileAttr attributes;
        FindFileHandle handle = FindFile(Folder()+"/*.json",filename,attributes,FindFileFlags.DIRECTORIES);
        if (handle)
        {
            bool more = true;
            while (more)
            {
                if (!(attributes & FileAttr.DIRECTORY) && filename.Length() > 5)
                {
                    string name = filename.Substring(0,filename.Length() - 5);
                    if (ValidName(name)) names.Insert(name);
                }
                more = FindNextFile(handle,filename,attributes);
            }
            CloseFindFile(handle);
        }
        names.Sort();
        return names;
    }

    static bool Load(string name, out IOTProjectData data, out string error)
    {
        name.TrimInPlace();
        data = null;
        if (!ValidName(name)) { error = IOTL.T("PROJECT_NAME_INVALID"); return false; }
        string path = Path(name);
        if (!FileExist(path))
        {
            PrintToRPT("[PROXY PROJECT IO] File not found: "+path);
            error = IOTL.F("PROJECT_NOT_FOUND",name+".json");
            return false;
        }
        FileHandle handle = OpenFile(path,FileMode.READ);
        if (handle == 0)
        {
            PrintToRPT("[PROXY PROJECT IO] Cannot open for reading: "+path);
            error = IOTL.F("PROJECT_READ_FAILED",name+".json");
            return false;
        }
        string content;
        int bytes = ReadFile(handle,content,100000000);
        CloseFile(handle);
        if (bytes < 0)
        {
            PrintToRPT("[PROXY PROJECT IO] Cannot read: "+path);
            error = IOTL.F("PROJECT_READ_FAILED",name+".json");
            return false;
        }
        string detail;
        if (!JsonFileLoader<IOTProjectData>.LoadData(content,data,detail))
        {
            PrintToRPT("[PROXY PROJECT IO] "+path+": "+detail);
            data = null;
            error = IOTL.F("PROJECT_JSON_INVALID",name+".json");
            return false;
        }
        error = "";
        return true;
    }

    protected static bool WriteFailure(string detail, out string error)
    {
        PrintToRPT("[PROXY PROJECT IO] "+detail);
        error = IOTL.T("PROJECT_WRITE_FAILED");
        return false;
    }

    static bool Save(string name, IOTProjectData data, out string error)
    {
        name.TrimInPlace();
        if (!ValidName(name)) { error = IOTL.T("PROJECT_NAME_INVALID"); return false; }
        MakeDirectory("$profile:ProxyPlacement");
        MakeDirectory(Folder());
        string path = Path(name);
        string temporary = path+".tmp";
        string backup = path+".bak";
        string detail;
        if (!JsonFileLoader<IOTProjectData>.SaveFile(temporary,data,detail))
        {
            DeleteFile(temporary);
            return WriteFailure(detail,error);
        }
        IOTProjectData check;
        if (!JsonFileLoader<IOTProjectData>.LoadFile(temporary,check,detail)) { DeleteFile(temporary); return WriteFailure(detail,error); }
        bool existed = FileExist(path);
        if (existed)
        {
            if (FileExist(backup) && !DeleteFile(backup)) { DeleteFile(temporary); return WriteFailure("Cannot remove backup: "+backup,error); }
            if (!CopyFile(path,backup)) { DeleteFile(temporary); return WriteFailure("Cannot create backup: "+backup,error); }
            if (!DeleteFile(path)) { DeleteFile(temporary); return WriteFailure("Cannot replace: "+path,error); }
        }
        if (!CopyFile(temporary,path))
        {
            if (existed) CopyFile(backup,path);
            DeleteFile(temporary);
            return WriteFailure("Cannot copy temporary project to: "+path,error);
        }
        DeleteFile(temporary);
        error = "";
        return true;
    }
}

// Vector toolbar icons use the native canvas and scale with the UI.
class IOTToolbarIcons
{
    static void Line(CanvasWidget canvas, vector a, vector b, float scale, int color)
    {
        canvas.DrawLine(a[0]*scale,a[1]*scale,b[0]*scale,b[1]*scale,1.8*scale,color);
    }

    static void Poly(CanvasWidget canvas, array<vector> points, float scale, int color)
    {
        for (int i = 1; i < points.Count(); i++) Line(canvas,points[i - 1],points[i],scale,color);
    }

    static void Arc(CanvasWidget canvas, vector center, float rx, float ry, float from, float to, float scale, int color)
    {
        vector previous;
        for (int i = 0; i <= 32; i++)
        {
            float angle = (from+(to-from)*i/32)*Math.DEG2RAD;
            vector point = Vector(center[0]+Math.Cos(angle)*rx,center[1]+Math.Sin(angle)*ry,0);
            if (i > 0) Line(canvas,previous,point,scale,color);
            previous = point;
        }
    }

    static void Draw(CanvasWidget canvas, string action, bool active = false)
    {
        canvas.Clear();
        float width,height;
        canvas.GetScreenSize(width,height);
        float scale = Math.Min(width,height)/32;
        int white = ARGB(255,225,231,235);
        int red = ARGB(255,240,92,92);
        int green = ARGB(255,103,218,132);
        int blue = ARGB(255,91,163,244);
        if (action == "ProjectSave")
        {
            Poly(canvas,{"4 3 0","24 3 0","29 8 0","29 29 0","3 29 0","3 3 0","4 3 0"},scale,white);
            Poly(canvas,{"9 3 0","9 12 0","22 12 0","22 3 0"},scale,white);
            Poly(canvas,{"8 29 0","8 20 0","24 20 0","24 29 0"},scale,white);
            Line(canvas,"18 5 0","18 10 0",scale,white);
        }
        else if (action == "ProjectOpen")
        {
            Poly(canvas,{"3 13 0","3 6 0","12 6 0","16 10 0","28 10 0","28 13 0"},scale,white);
            Poly(canvas,{"3 13 0","30 13 0","26 27 0","5 27 0","3 13 0"},scale,white);
        }
        else if (action == "Undo" || action == "Redo")
        {
            if (action == "Undo")
            {
                Arc(canvas,"16 18 0",10,10,215,395,scale,white);
                Poly(canvas,{"6 4 0","6 12 0","14 12 0"},scale,white);
            }
            else
            {
                Arc(canvas,"16 18 0",10,10,-35,-215,scale,white);
                Poly(canvas,{"26 4 0","26 12 0","18 12 0"},scale,white);
            }
        }
        else if (action == "MoveMode")
        {
            Line(canvas,"13 20 0","13 3 0",scale,green);
            Poly(canvas,{"9 8 0","13 3 0","17 8 0"},scale,green);
            Line(canvas,"13 20 0","30 20 0",scale,red);
            Poly(canvas,{"25 16 0","30 20 0","25 24 0"},scale,red);
            Line(canvas,"13 20 0","3 29 0",scale,blue);
            Poly(canvas,{"3 23 0","3 29 0","9 29 0"},scale,blue);
        }
        else if (action == "RotateMode")
        {
            Arc(canvas,"16 16 0",13,13,0,360,scale,red);
            Arc(canvas,"16 16 0",5,13,0,360,scale,blue);
            Arc(canvas,"16 16 0",13,5,0,360,scale,green);
        }
        else if (action == "PlaceOnSurface")
        {
            Line(canvas,"16 4 0","16 20 0",scale,white);
            Poly(canvas,{"10 14 0","16 20 0","22 14 0"},scale,white);
            Line(canvas,"3 26 0","29 26 0",scale,white);
        }
        else if (action == "DeleteItem")
        {
            Line(canvas,"5 9 0","27 9 0",scale,white);
            Poly(canvas,{"11 9 0","11 4 0","21 4 0","21 9 0"},scale,white);
            Poly(canvas,{"8 9 0","10 29 0","22 29 0","24 9 0"},scale,white);
            Line(canvas,"13 14 0","14 24 0",scale,white);
            Line(canvas,"19 14 0","18 24 0",scale,white);
        }
        else if (action == "SceneFocus")
        {
            Poly(canvas,{"3 11 0","3 3 0","11 3 0"},scale,white);
            Poly(canvas,{"21 3 0","29 3 0","29 11 0"},scale,white);
            Poly(canvas,{"29 21 0","29 29 0","21 29 0"},scale,white);
            Poly(canvas,{"11 29 0","3 29 0","3 21 0"},scale,white);
            Line(canvas,"10 16 0","22 16 0",scale,white);
            Line(canvas,"16 10 0","16 22 0",scale,white);
        }
        else if (action == "PlayerMode")
        {
            Arc(canvas,"16 7 0",4,4,0,360,scale,white);
            Poly(canvas,{"5 28 0","6 19 0","10 15 0","22 15 0","26 19 0","27 28 0","5 28 0"},scale,white);
        }
        else if (action == "LootVolumes")
        {
            int lootColor = white;
            if (active) lootColor = ARGB(255,70,205,245);
            Arc(canvas,"16 7 0",12,4,0,360,scale,lootColor);
            Arc(canvas,"16 25 0",12,4,0,360,scale,lootColor);
            Line(canvas,"4 7 0","4 25 0",scale,lootColor);
            Line(canvas,"28 7 0","28 25 0",scale,lootColor);
            Arc(canvas,"16 25 0",2,2,0,360,scale,white);
        }
        else if (action == "CameraHelp")
        {
            Poly(canvas,{"3 8 0","21 8 0","21 24 0","3 24 0","3 8 0"},scale,white);
            Poly(canvas,{"21 13 0","29 8 0","29 24 0","21 19 0"},scale,white);
            Arc(canvas,"12 16 0",4,4,0,360,scale,white);
        }
        else if (action == "Export")
        {
            Poly(canvas,{"20 29 0","5 29 0","5 3 0","20 3 0","26 9 0","26 14 0"},scale,white);
            Poly(canvas,{"19 3 0","19 10 0","26 10 0"},scale,white);
            Line(canvas,"15 22 0","30 22 0",scale,white);
            Poly(canvas,{"25 17 0","30 22 0","25 27 0"},scale,white);
        }
        else if (action == "SceneExport")
        {
            Poly(canvas,{"2 12 0","14 3 0","26 12 0"},scale,white);
            Poly(canvas,{"5 10 0","5 29 0","20 29 0"},scale,white);
            Poly(canvas,{"10 29 0","10 17 0","17 17 0","17 29 0"},scale,white);
            Line(canvas,"20 21 0","31 21 0",scale,white);
            Poly(canvas,{"26 16 0","31 21 0","26 26 0"},scale,white);
        }
    }
}

class IOTToolbarChrome
{
    protected Widget m_Root;
    protected Widget m_Hint;
    protected MultilineTextWidget m_Text;
    protected string m_Hovered;
    protected int m_HoverStart;
    protected float m_Scale = 1;
    protected bool m_HasLayout;
    protected float m_LayoutWidth;
    protected float m_LayoutHeight;
    protected int m_LayoutVisibility;
    protected string m_LootDetail;
    protected bool m_LootActive;
    protected bool m_CameraHelpOpen;
    protected bool m_ProjectDirty;

    void SetProjectDirty(bool dirty)
    {
        if (m_ProjectDirty == dirty) return;
        m_ProjectDirty = dirty;
        m_HasLayout = false;
    }

    void IOTToolbarChrome(Widget root)
    {
        m_Root = root;
        m_Hint = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\toolbar_hint.layout");
        m_Text = MultilineTextWidget.Cast(m_Hint.FindAnyWidget("ToolbarHintText"));
        // Above the toolbar, hover preview and optional editor backdrop.
        m_Hint.SetSort(1770);
        m_Hint.Show(false);
    }

    void ~IOTToolbarChrome() { if (m_Hint) m_Hint.Unlink(); }

    static array<string> Actions()
    {
        return {"ProjectSave","ProjectOpen","Undo","Redo","MoveMode","RotateMode","PlaceOnSurface","DeleteItem","SceneFocus","PlayerMode","LootVolumes","CameraHelp","Export","SceneExport"};
    }

    static int GroupIndex(int action)
    {
        if (action < 4) return action/2;
        if (action < 8) return 2;
        if (action < 12) return 3;
        return 4;
    }

    void SetLootDetail(string detail) { m_LootDetail = detail; }

    void SetLootActive(bool active)
    {
        if (m_LootActive == active) return;
        m_LootActive = active;
        m_Root.FindAnyWidget("LootVolumesActive").Show(active);
        CanvasWidget icon = CanvasWidget.Cast(m_Root.FindAnyWidget("LootVolumesIcon"));
        IOTToolbarIcons.Draw(icon,"LootVolumes",active);
    }

    static string GroupLabel(int index)
    {
        array<string> keys = {"TOOLS_PROJECT","TOOLS_HISTORY","TOOLS_EDIT","TOOLS_VIEW","TOOLS_EXPORT"};
        return IOTL.T(keys[index]);
    }

    static string HintText(string action)
    {
        array<string> names = Actions();
        int index = names.Find(action);
        if (index < 0) return "";
        array<string> keys = {"PROJECT_SAVE","PROJECT_OPEN","UNDO","REDO","MOVE","ROTATE","PLACE_ON_SURFACE","DELETE_ITEM","FOCUS_ANCHOR","CHARACTER","LOOT_VOLUMES","CAMERA_HELP","XML_SELECTION","EXPORT_ANCHOR"};
        string text = IOTL.T(keys[index]);
        if (action == "Redo") text = text+" / Ctrl+Shift+Z";
        return text;
    }

    float Layout(float width, float scale)
    {
        array<string> names = Actions();
        int visibility = 0;
        for (int action = 0; action < names.Count(); action++)
            if (m_Root.FindAnyWidget(names[action]).IsVisible()) visibility = visibility | (1 << action);
        // Tick refreshes button state every 50 ms. Preserve the hover timer
        // and retained canvas lines until geometry or visible actions change.
        if (m_HasLayout && Math.AbsFloat(m_LayoutWidth - width) < 0.01 && Math.AbsFloat(m_Scale - scale) < 0.001 && m_LayoutVisibility == visibility) return m_LayoutHeight;
        HideHint();
        m_Scale = scale;
        for (int separator = 1; separator < 5; separator++) m_Root.FindAnyWidget("ToolsSeparator"+separator.ToString()).Show(false);
        float headingHeight = 18;
        for (int labelIndex = 0; labelIndex < 5; labelIndex++)
        {
            TextWidget label = TextWidget.Cast(m_Root.FindAnyWidget("ToolsHeading"+labelIndex.ToString()));
            string headingText = GroupLabel(labelIndex);
            if (labelIndex == 0 && m_ProjectDirty) headingText = headingText+" *";
            label.SetText(headingText);
            int labelWidth,labelHeight;
            label.GetTextSize(labelWidth,labelHeight);
            headingHeight = Math.Max(headingHeight,labelHeight/scale+2);
        }
        float rowHeight = headingHeight+52;
        float available = width/scale;
        float x = 8;
        float y = 8;
        for (int group = 0; group < 5; group++)
        {
            int count = 0;
            for (int entry = 0; entry < names.Count(); entry++)
                if (GroupIndex(entry) == group && m_Root.FindAnyWidget(names[entry]).IsVisible()) count++;
            TextWidget heading = TextWidget.Cast(m_Root.FindAnyWidget("ToolsHeading"+group.ToString()));
            heading.Show(count > 0);
            if (count == 0) continue;
            int textWidth,textHeight;
            heading.GetTextSize(textWidth,textHeight);
            float iconsWidth = count*40+(count - 1)*4;
            float groupWidth = Math.Max(iconsWidth,textWidth/scale+8);
            if (x > 8)
            {
                if (x+20+groupWidth > available - 8) { x = 8; y = y+rowHeight; }
                else
                {
                    Widget divider = m_Root.FindAnyWidget("ToolsSeparator"+group.ToString());
                    divider.SetPos((x+9)*scale,(y+4)*scale);
                    divider.SetScreenSize(Math.Max(1,scale),(headingHeight+36)*scale);
                    divider.Show(true);
                    x = x+20;
                }
            }
            heading.SetPos(x*scale,y*scale);
            heading.SetScreenSize(groupWidth*scale,headingHeight*scale);
            float buttonX = x+(groupWidth - iconsWidth)*0.5;
            for (int item = 0; item < names.Count(); item++)
            {
                if (GroupIndex(item) != group) continue;
                string name = names[item];
                Widget button = m_Root.FindAnyWidget(name);
                if (!button.IsVisible()) continue;
                button.SetPos(buttonX*scale,(y+headingHeight+4)*scale);
                button.SetScreenSize(40*scale,40*scale);
                CanvasWidget icon = CanvasWidget.Cast(button.FindAnyWidget(name+"Icon"));
                icon.SetPos(6*scale,6*scale);
                icon.SetScreenSize(28*scale,28*scale);
                IOTToolbarIcons.Draw(icon,name,name == "LootVolumes" && m_LootActive);
                buttonX = buttonX+44;
            }
            x = x+groupWidth;
        }
        m_HasLayout = true;
        m_LayoutWidth = width;
        m_LayoutHeight = (y+rowHeight)*scale;
        m_LayoutVisibility = visibility;
        return m_LayoutHeight;
    }

    string ActionAt(vector point)
    {
        if (!m_Root.IsVisible()) return "";
        array<string> names = Actions();
        foreach (string name : names)
        {
            Widget button = m_Root.FindAnyWidget(name);
            if (!button.IsVisible()) continue;
            float x,y,w,h;
            button.GetScreenPos(x,y); button.GetScreenSize(w,h);
            if (point[0] >= x && point[0] < x+w && point[1] >= y && point[1] < y+h) return name;
        }
        return "";
    }

    void HideHint()
    {
        if (m_CameraHelpOpen)
        {
            m_CameraHelpOpen = false;
            m_Root.FindAnyWidget("CameraHelpActive").Show(false);
        }
        m_Hovered = "";
        m_Hint.Show(false);
    }

    void ToggleCameraHelp()
    {
        bool open = !m_CameraHelpOpen;
        HideHint();
        if (!open) return;
        m_CameraHelpOpen = true;
        m_Root.FindAnyWidget("CameraHelpActive").Show(true);
        string hint = IOTL.T("CAMERA_HELP")+"\n\n"+IOTL.T("CAMERA_HELP_ENTER")+"\n";
        array<string> lines = {"CAMERA_HELP_MOVE","CAMERA_HELP_HEIGHT","CAMERA_HELP_LOOK","CAMERA_HELP_SPEED","CAMERA_HELP_BOOST","CAMERA_HELP_SLOW"};
        foreach (string line : lines) hint += "\n"+IOTL.T(line);
        ShowHint("CameraHelp",hint,360,300);
    }

    Widget HintRoot() { return m_Hint; }

    bool ContainsHint(vector point)
    {
        if (!m_Hint.IsVisible()) return false;
        float x,y,w,h;
        m_Hint.GetScreenPos(x,y); m_Hint.GetScreenSize(w,h);
        return point[0] >= x && point[0] < x+w && point[1] >= y && point[1] < y+h;
    }

    void HoverAt(vector point, bool allowed, bool immediate = false)
    {
        if (m_CameraHelpOpen) return;
        string action;
        if (allowed) action = ActionAt(point);
        if (action == "") { HideHint(); return; }
        if (m_Hovered != action)
        {
            m_Hovered = action;
            m_HoverStart = GetGame().GetTime();
            m_Hint.Show(false);
        }
        if (!immediate && GetGame().GetTime() - m_HoverStart < 350) return;
        string hint = HintText(action);
        if (action == "LootVolumes" && m_LootDetail != "") hint = hint+"\n"+m_LootDetail;
        ShowHint(action,hint,280,180);
    }

    protected void ShowHint(string action, string hint, float baseWidth, float baseHeight)
    {
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float width = Math.Min(baseWidth*m_Scale,screenWidth - 16*m_Scale);
        float maxHeight = Math.Min(baseHeight*m_Scale,screenHeight);
        m_Hint.SetScreenSize(width,maxHeight);
        m_Text.SetPos(12*m_Scale,8*m_Scale);
        m_Text.SetScreenSize(width - 24*m_Scale,maxHeight - 16*m_Scale);
        m_Text.SetText(hint);
        m_Hint.Show(true);
        int textWidth,textHeight;
        m_Text.GetTextSize(textWidth,textHeight);
        float height = Math.Clamp(textHeight+16*m_Scale,32*m_Scale,maxHeight);
        m_Hint.SetScreenSize(width,height);
        m_Text.SetScreenSize(width - 24*m_Scale,height - 16*m_Scale);
        Widget button = m_Root.FindAnyWidget(action);
        float x,y,w,h;
        button.GetScreenPos(x,y); button.GetScreenSize(w,h);
        m_Hint.SetScreenPos(Math.Clamp(x,8*m_Scale,Math.Max(8*m_Scale,screenWidth - width - 8*m_Scale)),Math.Clamp(y+h+8*m_Scale,0,Math.Max(0,screenHeight - height)));
    }
}

// Runtime CE reference reader. Only ordinary container points are interpreted.
class IOTLootPoint
{
    vector Position;
    float Range = -1;
    float Height = -1;
    string ContainerName;
}

class IOTLootGroup
{
    ref array<ref IOTLootPoint> Points = new array<ref IOTLootPoint>;
}

class IOTLootDataset
{
    bool Valid;
    string Error;
    int PointCount;
    ref map<string,ref IOTLootGroup> Groups = new map<string,ref IOTLootGroup>;
}

// CE XML uses element/attribute data. No entity expansion, DTD or external IO.
// Reject unsupported/malformed input as a whole instead of publishing partial data.
class IOTLootXml
{
    protected static bool Space(string c) { return c == " " || c == "\t" || c == "\r" || c == "\n"; }

    static string Trim(string text)
    {
        // Keep Replace on short tag fragments: native Replace truncates large
        // strings on this client. Never normalize the complete XML buffer.
        text.Replace("\r"," "); text.Replace("\n"," "); text.Replace("\t"," ");
        text.TrimInPlace();
        return text;
    }

    static bool Number(string text, out float value)
    {
        text.TrimInPlace();
        int n = text.Length();
        if (n == 0) return false;
        // Native numeric tokenization avoids a script call per digit in the
        // common decimal case. Keep explicit exponent parsing as a fallback.
        string unsigned = text;
        if (unsigned.Substring(0,1) == "+" || unsigned.Substring(0,1) == "-") unsigned = unsigned.Substring(1,n - 1);
        if (unsigned == "" || Space(unsigned.Substring(0,1)) || unsigned.Substring(0,1) == "+" || unsigned.Substring(0,1) == "-") return false;
        string remainder = unsigned;
        string token;
        int kind = remainder.ParseStringEx(token);
        remainder.TrimInPlace();
        if (kind == 4 && remainder == "" && !unsigned.Contains("x") && !unsigned.Contains("X") && !unsigned.Contains("f") && !unsigned.Contains("F"))
        {
            value = text.ToFloat();
            return Math.AbsFloat(value) <= 1000000;
        }
        int i = 0;
        if (text.Substring(i,1) == "+" || text.Substring(i,1) == "-") i++;
        bool digit = false;
        bool dot = false;
        while (i < n)
        {
            string c = text.Substring(i,1);
            if ("0123456789".Contains(c)) digit = true;
            else if (c == "." && !dot) dot = true;
            else break;
            i++;
        }
        if (!digit) return false;
        if (i < n && (text.Substring(i,1) == "e" || text.Substring(i,1) == "E"))
        {
            i++;
            if (i < n && (text.Substring(i,1) == "+" || text.Substring(i,1) == "-")) i++;
            int exponentStart = i;
            while (i < n && "0123456789".Contains(text.Substring(i,1))) i++;
            if (i == exponentStart) return false;
        }
        if (i != n) return false;
        value = text.ToFloat();
        return Math.AbsFloat(value) <= 1000000;
    }

    static bool Attributes(string tag, out string name, map<string,string> attributes)
    {
        int length = tag.Length();
        int cursor = tag.IndexOf(" ");
        if (cursor < 0) cursor = length;
        name = tag.Substring(0,cursor);
        if (name == "") return false;
        while (cursor < length)
        {
            while (cursor < length && Space(tag.Substring(cursor,1))) cursor++;
            if (cursor == length) break;
            int equals = tag.IndexOfFrom(cursor,"=");
            if (equals < 0) return false;
            string key = Trim(tag.Substring(cursor,equals - cursor));
            if (key == "" || key.Contains(" ")) return false;
            cursor = equals+1;
            while (cursor < length && Space(tag.Substring(cursor,1))) cursor++;
            if (cursor >= length) return false;
            string quote = tag.Substring(cursor,1);
            if (quote != "\"" && quote != "'") return false;
            int start = cursor+1;
            int end = tag.IndexOfFrom(start,quote);
            if (end < 0 || attributes.Contains(key)) return false;
            string value = tag.Substring(start,end - start);
            if (value.Contains("<") || value.Contains("&")) return false;
            attributes.Insert(key,value);
            cursor = end+1;
            if (cursor < length && !Space(tag.Substring(cursor,1))) return false;
        }
        return true;
    }

    static bool Point(map<string,string> attributes, string containerName, IOTLootGroup group)
    {
        string position = attributes.Get("pos");
        array<string> words = new array<string>;
        position.Split(" ",words);
        array<float> values = new array<float>;
        foreach (string word : words)
        {
            if (word == "") continue;
            float component;
            if (!Number(word,component)) return false;
            values.Insert(component);
        }
        if (values.Count() != 3) return false;
        IOTLootPoint point = new IOTLootPoint;
        point.Position = Vector(values[0],values[1],values[2]);
        point.ContainerName = containerName;
        float rangeValue;
        float heightValue;
        if (attributes.Contains("range"))
        {
            if (!Number(attributes.Get("range"),rangeValue) || rangeValue < 0 || rangeValue > 10000) return false;
            point.Range = rangeValue;
        }
        if (attributes.Contains("height"))
        {
            if (!Number(attributes.Get("height"),heightValue) || heightValue < 0 || heightValue > 10000) return false;
            point.Height = heightValue;
        }
        group.Points.Insert(point);
        return true;
    }

    static IOTLootDataset Parse(string xml)
    {
        IOTLootXmlStream reader = new IOTLootXmlStream;
        for (int offset = 0; offset < xml.Length(); offset = offset+2048)
            reader.Feed(xml.Substring(offset,Math.Min(2048,xml.Length() - offset)));
        return reader.Finish();
    }

    static IOTLootDataset ParseFile(FileHandle file)
    {
        IOTLootXmlStream reader = new IOTLootXmlStream;
        string line;
        int totalBytes = 0;
        while (FGets(file,line) >= 0)
        {
            totalBytes = totalBytes+line.Length();
            if (totalBytes > 10000000)
            {
                IOTLootDataset oversized = new IOTLootDataset;
                oversized.Error = "Oversized CE XML";
                return oversized;
            }
            for (int offset = 0; offset < line.Length(); offset = offset+2048)
                reader.Feed(line.Substring(offset,Math.Min(2048,line.Length() - offset)));
            reader.Feed("\n");
            if (reader.Failed()) return reader.Finish();
        }
        return reader.Finish();
    }
}
class IOTLootCache
{
    protected static ref map<string,ref IOTLootDataset> s_Files = new map<string,ref IOTLootDataset>;
    protected static string s_Version;

    static void Clear() { s_Files.Clear(); s_Version = ""; }

    static string Version()
    {
        if (s_Version == "")
        {
            string version;
            GetGame().GetVersion(version);
            s_Version = version;
        }
        return s_Version;
    }

    static string WorldFolder(int index)
    {
        array<string> names = {"","chernarusplus","enoch","sakhal","nasdara"};
        return names[index];
    }

    static IOTLootDataset Get(string path)
    {
        if (s_Files.Contains(path)) return s_Files.Get(path);
        IOTLootDataset data = new IOTLootDataset;
        data.Error = "File unavailable";
        FileHandle file = OpenFile(path,FileMode.READ);
        if (file)
        {
            data = IOTLootXml.ParseFile(file);
            CloseFile(file);
        }
        // Never retain partially parsed groups after validation fails.
        if (!data.Valid) { data.Groups.Clear(); data.PointCount = 0; }
        s_Files.Insert(path,data);
        PrintToRPT("[PROXY LOOT SOURCE] "+path+" valid="+data.Valid.ToString()+" groups="+data.Groups.Count().ToString()+" points="+data.PointCount.ToString()+" error="+data.Error);
        return data;
    }
}

class IOTLootReference
{
    int MapIndex;
    bool Readable;
    bool Known;
    bool Snapshot;
    ref array<ref IOTLootPoint> Points = new array<ref IOTLootPoint>;
}

class IOTLootSources
{
    protected string m_GameRoot;
    protected string m_BackupPath;

    void IOTLootSources(string gameRoot = "DZ\\worlds", string backupPath = "iot\\proxytool\\data\\loot_volumes.txt")
    {
        m_GameRoot = gameRoot;
        m_BackupPath = backupPath;
    }

    protected IOTLootReference ForMap(string classname, int mapIndex)
    {
        IOTLootReference result = new IOTLootReference;
        result.MapIndex = mapIndex;
        string path = m_GameRoot+"\\"+IOTLootCache.WorldFolder(mapIndex)+"\\ce\\mapgroupproto.xml";
        IOTLootDataset installed = IOTLootCache.Get(path);
        if (installed.Valid)
        {
            result.Readable = true;
            result.Known = installed.Groups.Contains(classname);
            if (result.Known) foreach (IOTLootPoint point : installed.Groups.Get(classname).Points) result.Points.Insert(point);
            return result;
        }
        result.Snapshot = true;
        FileHandle backup = OpenFile(m_BackupPath,FileMode.READ);
        if (!backup) return result;
        result.Readable = true;
        int bit = 1 << (mapIndex - 1);
        string line;
        while (FGets(backup,line) >= 0)
        {
            if (line.IndexOf(classname+"|") != 0) continue;
            array<string> columns = new array<string>;
            line.Split("|",columns);
            if (columns.Count() < 2 || (columns[1].ToInt() & bit) == 0) continue;
            result.Known = true;
            if (columns.Count() < 4) continue;
            array<string> points = new array<string>;
            columns[3].Split(";",points);
            foreach (string entry : points)
            {
                array<string> numbers = new array<string>;
                entry.Split(" ",numbers);
                if (numbers.Count() != 5) continue;
                IOTLootPoint stored = new IOTLootPoint;
                stored.Position = Vector(numbers[0].ToFloat(),numbers[1].ToFloat(),numbers[2].ToFloat());
                stored.Range = numbers[3].ToFloat();
                stored.Height = numbers[4].ToFloat();
                stored.ContainerName = columns[2];
                result.Points.Insert(stored);
            }
        }
        CloseFile(backup);
        return result;
    }

    IOTLootReference Resolve(string classname, int preferredMap)
    {
        classname.ToLower();
        if (preferredMap >= 1 && preferredMap <= 4) return ForMap(classname,preferredMap);
        bool readable;
        IOTLootReference result;
        for (int index = 1; index <= 4; index++)
        {
            result = ForMap(classname,index);
            if (result.Known) return result;
            readable = readable || result.Readable;
        }
        result.MapIndex = 0;
        result.Readable = readable;
        return result;
    }
}

// Feed short fragments: string searches on whole megabyte buffers are costly
// in the script runtime. State survives file lines and fragment boundaries.
class IOTLootXmlStream
{
    protected ref IOTLootDataset m_Result = new IOTLootDataset;
    protected ref array<string> m_Stack = new array<string>;
    protected ref IOTLootGroup m_Group;
    protected string m_ContainerName;
    protected string m_Buffer;
    protected string m_SkipUntil;
    protected bool m_Root;
    protected bool m_Closed;
    protected bool m_Failed;
    protected bool m_Started;

    protected void Fail(string message) { m_Failed = true; m_Result.Error = message; }
    bool Failed() { return m_Failed; }

    protected void Tag(string raw)
    {
        string tag = IOTLootXml.Trim(raw);
        if (tag == "") { Fail("Empty XML tag"); return; }
        bool closing = tag.Substring(0,1) == "/";
        bool empty = tag.Substring(tag.Length() - 1,1) == "/";
        if (closing)
        {
            string closeName = IOTLootXml.Trim(tag.Substring(1,tag.Length() - 1));
            if (m_Stack.Count() == 0 || m_Stack[m_Stack.Count() - 1] != closeName) { Fail("Mismatched close tag: "+closeName); return; }
            if (closeName == "container" && m_Stack.Count() == 3) m_ContainerName = "";
            if (closeName == "group" && m_Stack.Count() == 2) m_Group = null;
            m_Stack.Remove(m_Stack.Count() - 1);
            if (m_Stack.Count() == 0) m_Closed = true;
            return;
        }
        if (m_Closed) { Fail("Tag after document end"); return; }
        if (empty) tag = IOTLootXml.Trim(tag.Substring(0,tag.Length() - 1));
        string name;
        map<string,string> attributes = new map<string,string>;
        if (!IOTLootXml.Attributes(tag,name,attributes)) { Fail("Invalid attributes: "+tag); return; }
        string parent;
        if (m_Stack.Count() > 0) parent = m_Stack[m_Stack.Count() - 1];
        if (m_Stack.Count() == 0)
        {
            if (m_Root || name != "prototype") { Fail("Invalid root tag: "+name); return; }
            m_Root = true;
        }
        else if (m_Stack.Count() == 1 && parent == "prototype" && name == "group")
        {
            string classname = attributes.Get("name");
            classname.ToLower();
            if (classname == "" || m_Result.Groups.Contains(classname)) { Fail("Missing or duplicate group"); return; }
            m_Group = new IOTLootGroup;
            m_Result.Groups.Insert(classname,m_Group);
            if (empty) m_Group = null;
        }
        else if (m_Stack.Count() == 2 && parent == "group" && name == "container")
        {
            m_ContainerName = attributes.Get("name");
            if (m_ContainerName == "") { Fail("Unnamed container"); return; }
            if (empty) m_ContainerName = "";
        }
        else if (m_Stack.Count() == 3 && parent == "container" && name == "point")
        {
            if (!m_Group || !IOTLootXml.Point(attributes,m_ContainerName,m_Group)) { Fail("Invalid point: "+tag); return; }
            m_Result.PointCount++;
        }
        if (!empty) m_Stack.Insert(name);
        else if (m_Stack.Count() == 0) m_Closed = true;
    }

    void Feed(string text)
    {
        if (m_Failed) return;
        m_Buffer = m_Buffer+text;
        if (!m_Started)
        {
            if (m_Buffer.Length() < 3) return;
            if (m_Buffer.Substring(0,1).ToAscii() == 239 && m_Buffer.Substring(1,1).ToAscii() == 187 && m_Buffer.Substring(2,1).ToAscii() == 191) m_Buffer = m_Buffer.Substring(3,m_Buffer.Length() - 3);
            m_Started = true;
        }
        while (m_Buffer != "" && !m_Failed)
        {
            if (m_SkipUntil != "")
            {
                int skipped = m_Buffer.IndexOf(m_SkipUntil);
                if (skipped < 0)
                {
                    int retain = Math.Min(m_Buffer.Length(),m_SkipUntil.Length() - 1);
                    m_Buffer = m_Buffer.Substring(m_Buffer.Length() - retain,retain);
                    return;
                }
                int after = skipped+m_SkipUntil.Length();
                m_Buffer = m_Buffer.Substring(after,m_Buffer.Length() - after);
                m_SkipUntil = "";
                continue;
            }
            int start = m_Buffer.IndexOf("<");
            if (start < 0)
            {
                if (m_Stack.Count() == 0 && IOTLootXml.Trim(m_Buffer) != "") Fail("Unexpected text outside prototype");
                m_Buffer = "";
                return;
            }
            if (start > 0)
            {
                if (m_Stack.Count() == 0 && IOTLootXml.Trim(m_Buffer.Substring(0,start)) != "") { Fail("Unexpected text outside prototype"); return; }
                m_Buffer = m_Buffer.Substring(start,m_Buffer.Length() - start);
            }
            if (m_Buffer.Length() < 4) return;
            if (m_Buffer.IndexOf("<!--") == 0)
            {
                m_SkipUntil = "-->";
                m_Buffer = m_Buffer.Substring(4,m_Buffer.Length() - 4);
                continue;
            }
            if (m_Buffer.IndexOf("<?") == 0)
            {
                m_SkipUntil = "?>";
                m_Buffer = m_Buffer.Substring(2,m_Buffer.Length() - 2);
                continue;
            }
            if (m_Buffer.IndexOf("<!") == 0) { Fail("Unsupported XML declaration"); return; }
            int end = m_Buffer.IndexOf(">");
            if (end < 0)
            {
                if (m_Buffer.Length() > 4096) Fail("Oversized XML tag");
                return;
            }
            if (end > 4096) { Fail("Oversized XML tag"); return; }
            string raw = m_Buffer.Substring(1,end - 1);
            m_Buffer = m_Buffer.Substring(end+1,m_Buffer.Length() - end - 1);
            Tag(raw);
        }
    }

    IOTLootDataset Finish()
    {
        if (!m_Failed && (m_Buffer != "" || m_SkipUntil != "" || !m_Root || !m_Closed || m_Stack.Count() != 0)) Fail("Incomplete CE XML");
        m_Result.Valid = !m_Failed;
        return m_Result;
    }
}

// Catalog membership, not a CE simulation: only positive nominal values count.
// Read installed data on startup so game updates do not require a new snapshot.
class IOTItemTypesXml
{
    ref map<string,bool> Enabled = new map<string,bool>;
    string Error;
    protected ref map<string,bool> m_Seen = new map<string,bool>;
    protected ref array<string> m_Stack = new array<string>;
    protected string m_Buffer;
    protected string m_SkipUntil;
    protected string m_Classname;
    protected string m_Nominal;
    protected bool m_NominalSeen;
    protected bool m_Root;
    protected bool m_Closed;
    protected bool m_Started;

    protected void Content(string text)
    {
        if (m_Stack.Count() == 3 && m_Stack[2] == "nominal")
        {
            m_Nominal += text;
            if (m_Nominal.Length() > 64) Error = "Oversized nominal";
        }
        else if (m_Stack.Count() == 0 && IOTLootXml.Trim(text) != "") Error = "Text outside types root";
    }

    protected void Tag(string raw)
    {
        string tag = IOTLootXml.Trim(raw);
        if (tag == "") { Error = "Empty XML tag"; return; }
        bool closing = tag.Substring(0,1) == "/";
        bool empty = tag.Substring(tag.Length() - 1,1) == "/";
        if (closing)
        {
            string closeName = IOTLootXml.Trim(tag.Substring(1,tag.Length() - 1));
            if (m_Stack.Count() == 0 || m_Stack[m_Stack.Count() - 1] != closeName) { Error = "Mismatched close tag"; return; }
            if (closeName == "nominal" && m_Stack.Count() == 3)
            {
                float nominal;
                if (!IOTLootXml.Number(m_Nominal,nominal) || nominal < 0 || nominal != Math.Floor(nominal)) { Error = "Invalid nominal"; return; }
                if (nominal > 0) Enabled.Insert(m_Classname,true);
            }
            if (closeName == "type" && m_Stack.Count() == 2 && !m_NominalSeen) { Error = "Missing nominal"; return; }
            m_Stack.Remove(m_Stack.Count() - 1);
            if (m_Stack.Count() == 0) m_Closed = true;
            return;
        }
        if (m_Closed) { Error = "Tag after document end"; return; }
        if (empty) tag = IOTLootXml.Trim(tag.Substring(0,tag.Length() - 1));
        string name;
        map<string,string> attributes = new map<string,string>;
        if (!IOTLootXml.Attributes(tag,name,attributes)) { Error = "Invalid XML attributes"; return; }
        if (m_Stack.Count() == 0)
        {
            if (m_Root || name != "types") { Error = "Invalid types root"; return; }
            m_Root = true;
        }
        else if (m_Stack.Count() == 1)
        {
            if (name != "type" || empty) { Error = "Invalid type entry"; return; }
            m_Classname = attributes.Get("name");
            m_Classname.ToLower();
            if (m_Classname == "" || m_Seen.Contains(m_Classname)) { Error = "Missing or duplicate type"; return; }
            m_Seen.Insert(m_Classname,true);
            m_NominalSeen = false;
        }
        else if (m_Stack.Count() == 2 && name == "nominal")
        {
            if (m_NominalSeen || empty) { Error = "Missing or duplicate nominal"; return; }
            m_NominalSeen = true;
            m_Nominal = "";
        }
        else if (m_Stack.Count() >= 3) { Error = "Unexpected nested type data"; return; }
        if (!empty) m_Stack.Insert(name);
        else if (m_Stack.Count() == 0) m_Closed = true;
    }

    void Feed(string text)
    {
        if (Error != "") return;
        m_Buffer += text;
        if (!m_Started)
        {
            if (m_Buffer.Length() < 3) return;
            if (m_Buffer.Substring(0,1).ToAscii() == 239 && m_Buffer.Substring(1,1).ToAscii() == 187 && m_Buffer.Substring(2,1).ToAscii() == 191) m_Buffer = m_Buffer.Substring(3,m_Buffer.Length() - 3);
            m_Started = true;
        }
        while (m_Buffer != "" && Error == "")
        {
            if (m_SkipUntil != "")
            {
                int skipped = m_Buffer.IndexOf(m_SkipUntil);
                if (skipped < 0)
                {
                    int retain = Math.Min(m_Buffer.Length(),m_SkipUntil.Length() - 1);
                    m_Buffer = m_Buffer.Substring(m_Buffer.Length() - retain,retain);
                    return;
                }
                int after = skipped+m_SkipUntil.Length();
                m_Buffer = m_Buffer.Substring(after,m_Buffer.Length() - after);
                m_SkipUntil = "";
                continue;
            }
            int start = m_Buffer.IndexOf("<");
            if (start < 0) { Content(m_Buffer); m_Buffer = ""; return; }
            if (start > 0)
            {
                Content(m_Buffer.Substring(0,start));
                m_Buffer = m_Buffer.Substring(start,m_Buffer.Length() - start);
                if (Error != "") return;
            }
            if (m_Buffer.Length() < 4) return;
            if (m_Buffer.IndexOf("<!--") == 0) { m_SkipUntil = "-->"; m_Buffer = m_Buffer.Substring(4,m_Buffer.Length() - 4); continue; }
            if (m_Buffer.IndexOf("<?") == 0) { m_SkipUntil = "?>"; m_Buffer = m_Buffer.Substring(2,m_Buffer.Length() - 2); continue; }
            if (m_Buffer.IndexOf("<!") == 0) { Error = "Unsupported XML declaration"; return; }
            int end = m_Buffer.IndexOf(">");
            if (end < 0) { if (m_Buffer.Length() > 4096) Error = "Oversized XML tag"; return; }
            if (end > 4096) { Error = "Oversized XML tag"; return; }
            string raw = m_Buffer.Substring(1,end - 1);
            m_Buffer = m_Buffer.Substring(end+1,m_Buffer.Length() - end - 1);
            Tag(raw);
        }
    }

    bool Finish()
    {
        if (Error == "" && (m_Buffer != "" || m_SkipUntil != "" || !m_Root || !m_Closed || m_Stack.Count() != 0)) Error = "Incomplete types XML";
        if (Error != "") Enabled.Clear();
        return Error == "";
    }
}

class IOTItemMaps
{
    protected ref map<string,int> m_Masks = new map<string,int>;
    protected int m_ReadableMaps;

    static array<string> Branches()
    {
        array<string> branches = {"common","map:1","map:2","map:3","map:4"};
        return branches;
    }

    static string Branch(int mask, int readableMaps)
    {
        // A failed map file must not turn a shared item into a false exclusive.
        if (mask != 0 && (mask & (mask - 1)) != 0) return "common";
        if (readableMaps == 15)
        {
            if (mask == 1) return "map:1";
            if (mask == 2) return "map:2";
            if (mask == 4) return "map:3";
            if (mask == 8) return "map:4";
        }
        return "common";
    }

    static string Label(string branch)
    {
        if (branch == "common") return IOTL.T("ITEM_MAP_COMMON");
        if (branch == "map:1") return "ChernarusPlus";
        if (branch == "map:2") return "Livonia";
        if (branch == "map:3") return "Sakhal";
        if (branch == "map:4") return "Nasdara";
        return IOTL.T("ITEM_MAP_COMMON");
    }

    void Load(string root = "DZ\\worlds")
    {
        m_Masks.Clear();
        m_ReadableMaps = 0;
        for (int mapIndex = 1; mapIndex <= 4; mapIndex++)
        {
            string path = root+"\\"+IOTLootCache.WorldFolder(mapIndex)+"\\ce\\db\\types.xml";
            FileHandle file = OpenFile(path,FileMode.READ);
            if (!file) { PrintToRPT("[PROXY ITEM MAP SOURCE] Unavailable: "+path); continue; }
            IOTItemTypesXml reader = new IOTItemTypesXml;
            string line;
            int bytes = 0;
            while (FGets(file,line) >= 0 && reader.Error == "")
            {
                bytes += line.Length();
                if (bytes > 10000000) { reader.Error = "Oversized types XML"; break; }
                for (int offset = 0; offset < line.Length(); offset += 2048)
                    reader.Feed(line.Substring(offset,Math.Min(2048,line.Length() - offset)));
                reader.Feed("\n");
            }
            CloseFile(file);
            if (!reader.Finish()) { PrintToRPT("[PROXY ITEM MAP SOURCE] Invalid: "+path+" error="+reader.Error); continue; }
            int bit = 1 << (mapIndex - 1);
            m_ReadableMaps = m_ReadableMaps | bit;
            foreach (string classname, bool enabled : reader.Enabled) m_Masks.Set(classname,m_Masks.Get(classname) | bit);
            PrintToRPT("[PROXY ITEM MAP SOURCE] "+path+" enabled="+reader.Enabled.Count().ToString());
        }
    }

    int ReadableMaps() { return m_ReadableMaps; }
    int Mask(string classname) { classname.ToLower(); return m_Masks.Get(classname); }
    string ForClass(string classname) { return Branch(Mask(classname),m_ReadableMaps); }
}

// Cartridge identities come from chamberableFrom / ammoItems, not CfgAmmo.caliber:
// the latter is a penetration coefficient rather than a cartridge designation.
class IOTWeaponCatalog
{
    static string AmmoCaliber(string ammo)
    {
        ammo.ToLower();
        if (ammo.IndexOf("ammo_") != 0) return "OTHER";
        string id = ammo.Substring(5,ammo.Length() - 5);
        if (id.Length() > 6 && id.Substring(id.Length() - 6,6) == "tracer") id = id.Substring(0,id.Length() - 6);
        if (id == "9x39ap") id = "9x39";
        if (id.IndexOf("12ga") == 0) return "12GA";
        array<string> known = {"22","308win","357","380","45acp","545x39","556x45","762x39","762x54","9x19","9x39"};
        if (known.Find(id) < 0) return "OTHER";
        id.ToUpper();
        return id;
    }

    static string CaliberLabel(string id)
    {
        if (id == "22") return ".22 LR";
        if (id == "308WIN") return ".308 Win";
        if (id == "357") return ".357 Magnum";
        if (id == "380") return ".380 ACP";
        if (id == "45ACP") return ".45 ACP";
        if (id == "545X39") return IOTL.F("CALIBER_MM","5.45x39");
        if (id == "556X45") return IOTL.F("CALIBER_MM","5.56x45");
        if (id == "762X39") return IOTL.F("CALIBER_MM","7.62x39");
        if (id == "762X54") return IOTL.F("CALIBER_MM","7.62x54")+" R";
        if (id == "9X19") return IOTL.F("CALIBER_MM","9x19");
        if (id == "9X39") return IOTL.F("CALIBER_MM","9x39");
        if (id == "12GA") return IOTL.T("CALIBER_12GA");
        if (id == "MULTIPLE") return IOTL.T("CALIBER_MULTIPLE");
        return IOTL.T("CALIBER_OTHER");
    }

    protected static void AppendConfigArray(string path, array<string> values)
    {
        array<string> configured = new array<string>;
        GetGame().ConfigGetTextArray(path,configured);
        foreach (string value : configured) { if (values.Find(value) < 0) values.Insert(value); }
    }

    protected static bool AppendChamberCalibers(string entry, array<string> calibers, int depth = 0)
    {
        if (depth >= 8) return false;
        string caliber = AmmoCaliber(entry);
        if (caliber != "OTHER")
        {
            if (calibers.Find(caliber) < 0) calibers.Insert(caliber);
            return true;
        }
        // SKS and Mosin chamber lists also accept clips; inspect their rounds.
        array<string> rounds = new array<string>;
        GetGame().ConfigGetTextArray("CfgMagazines "+entry+" ammoItems",rounds);
        if (rounds.Count() == 0) return false;
        foreach (string round : rounds)
        {
            if (!AppendChamberCalibers(round,calibers,depth+1)) return false;
        }
        return true;
    }

    static string WeaponCaliber(string classname)
    {
        string path = "CfgWeapons "+classname;
        array<string> ammo = new array<string>;
        AppendConfigArray(path+" chamberableFrom",ammo);
        array<string> muzzles = new array<string>;
        GetGame().ConfigGetTextArray(path+" muzzles",muzzles);
        foreach (string muzzle : muzzles)
        {
            if (muzzle != "this") AppendConfigArray(path+" "+muzzle+" chamberableFrom",ammo);
        }
        array<string> calibers = new array<string>;
        foreach (string ammoClass : ammo)
        {
            if (!AppendChamberCalibers(ammoClass,calibers)) return "OTHER";
        }
        if (calibers.Count() == 1) return calibers[0];
        if (calibers.Count() > 1) return "MULTIPLE";
        return "OTHER";
    }

    static string MagazineCaliber(string classname)
    {
        array<string> ammo = new array<string>;
        AppendConfigArray("CfgMagazines "+classname+" ammoItems",ammo);
        array<string> calibers = new array<string>;
        foreach (string ammoClass : ammo)
        {
            if (!AppendChamberCalibers(ammoClass,calibers)) return "OTHER";
        }
        if (calibers.Count() == 1) return calibers[0];
        if (calibers.Count() > 1) return "MULTIPLE";
        return "OTHER";
    }
}

// Presentation-only subdivisions. Unknown classes stay in an explicit fallback.
class IOTCatalogSubgroups
{
    static array<string> Sections()
    {
        array<string> sections = {"VEHICLE_PARTS/BODY","FOOD_DRINKS/FOOD","ATTACHMENTS/SUPPORT","GEAR/CONSUMABLES","GEAR/TOOLS/OTHER","AMMO/ROUNDS","GEAR/CONTAINERS","GEAR/CAMPING/FLAGS","OTHER","CLOTHING/TOPS/ARMBANDS/MODEL_Armband_ColorBase"};
        return sections;
    }

    static string Last(string path)
    {
        array<string> parts = new array<string>;
        path.Split("/",parts);
        return parts[parts.Count() - 1];
    }

    static string Label(string code)
    {
        code = Last(code);
        if (code.IndexOf("CAL_") == 0) return IOTWeaponCatalog.CaliberLabel(code.Substring(4,code.Length() - 4));
        string key = "CATALOG_SUB_"+code;
        return IOTL.T(key);
    }

    static string BodyGroup(string classname, string model)
    {
        string source = classname;
        string vehicle;
        string part;
        for (int depth = 0; depth < 32; depth++)
        {
            string name = source;
            name.ToLower();
            if (name.IndexOf("hatchback_02_") == 0) vehicle = "CAR_GUNTER";
            else if (name.IndexOf("hatchback") == 0) vehicle = "CAR_ADA";
            else if (name.IndexOf("civsedan") == 0) vehicle = "CAR_OLGA";
            else if (name.IndexOf("sedan_02_") == 0) vehicle = "CAR_SARKA";
            else if (name.IndexOf("truck_01_") == 0) vehicle = "CAR_M3S";
            else if (name.IndexOf("offroad_02_") == 0) vehicle = "CAR_M1025";
            if (part == "")
            {
                if (name.Contains("hood")) part = "HOODS";
                else if (name.Contains("trunk")) part = "TRUNKS";
                else if (name.Contains("door")) part = "DOORS";
            }
            if (vehicle != "" && part != "") break;
            string parent;
            if (!GetGame().ConfigGetBaseName("CfgVehicles "+source,parent) || parent == source || parent == "" || parent == "CarDoor") break;
            source = parent;
        }
        // Renamed classes may use stock proxy resources without stock ancestry.
        array<string> parts = IOTCatalogAsset.ModelParts(model);
        if (vehicle == "" && parts.Count() > 4 && parts[0] == "dz" && parts[1] == "vehicles" && parts[2] == "wheeled")
        {
            string folder = parts[3];
            if (folder == "offroadhatchback") vehicle = "CAR_ADA";
            if (folder == "civiliansedan") vehicle = "CAR_OLGA";
            if (folder == "hatchback_02") vehicle = "CAR_GUNTER";
            if (folder == "sedan_02") vehicle = "CAR_SARKA";
            if (folder == "truck_01") vehicle = "CAR_M3S";
            if (folder == "offroad_02") vehicle = "CAR_M1025";
        }
        if (part == "" && parts.Count() > 0)
        {
            string filename = parts[parts.Count() - 1];
            if (filename.Contains("hood")) part = "HOODS";
            else if (filename.Contains("trunk")) part = "TRUNKS";
            else if (filename.Contains("door")) part = "DOORS";
        }
        if (vehicle == "") vehicle = "OTHER_VEHICLES";
        if (part == "") part = "OTHER";
        return vehicle+"/"+part;
    }

    static string SymbolGroup(string classname)
    {
        classname.ToLower();
        array<string> parts = new array<string>;
        classname.Split("_",parts);
        string symbol = parts[parts.Count() - 1];
        array<string> plain = {"black","blue","green","orange","pink","red","white","yellow"};
        array<string> places = {"chernarus","livonia","sakhal","altis","ssahrani","nsahrani"};
        array<string> animals = {"bear","wolf","babydeer","rooster","snake"};
        array<string> organizations = {"apa","cdf","chedaki","napa","livoniaarmy","livoniapolice","uec","cmc","tec","chel","rsta","pirates","cannibals"};
        if (plain.Find(symbol) >= 0) return "PLAIN";
        if (places.Find(symbol) >= 0) return "PLACES";
        if (animals.Find(symbol) >= 0) return "ANIMALS";
        if (organizations.Find(symbol) >= 0) return "ORGANIZATIONS";
        return "OTHER_SYMBOLS";
    }

    static string ClothingKind(string section, string family)
    {
        string name = family;
        name.ToLower();
        if (section == "CLOTHING/HEADGEAR")
        {
            if (name.Contains("visor") || name.Contains("mouthguard") || name.Contains("helmetlight")) return "HELMET_ACCESSORIES";
            if (name.Contains("helmet") || name.Contains("greathelm") || name.Contains("norsehelm")) return "HELMETS";
            if (name.Contains("hood") || name.Contains("coif") || name.Contains("headcover") || name.Contains("bandana") || name.Contains("burlap")) return "HOODS_WRAPS";
            if (name.Contains("ushanka") || name.Contains("beanie") || name.Contains("morozko") || name.Contains("winter") || name.Contains("budenovka") || name.Contains("petushok") || name.Contains("sherpa")) return "WARM_HATS";
            if (name.Contains("cap") || name.Contains("beret") || name.Contains("pilotka")) return "CAPS_BERETS";
            if (name.Contains("hat") || name.Contains("headdress") || name.Contains("crown") || name.Contains("headband")) return "HATS_HEADBANDS";
            return "OTHER";
        }
        if (section == "CLOTHING/TOPS")
        {
            if (name.Contains("armband")) return "ARMBANDS";
            if (name.Contains("chainmail") || name.Contains("armor") || name.Contains("chestplate")) return "PROTECTIVE";
            if (name.Contains("torsocover")) return "IMPROVISED";
            if (name.Contains("police") || name.Contains("uniform") || name.Contains("bdu") || name.Contains("ttsko") || name.Contains("usmc") || name.Contains("scrubs") || name.Contains("paramedic") || name.Contains("firefighter") || name.Contains("nbc")) return "UNIFORMS";
            if (name.Contains("hoodie") || name.Contains("sweater") || name.Contains("jumper") || name.Contains("tracksuit")) return "SWEATERS";
            if (name.Contains("shirt") || name.Contains("blouse")) return "SHIRTS";
            if (name.Contains("jacket") || name.Contains("coat")) return "JACKETS";
            return "OTHER";
        }
        return "";
    }

    static string FoodGroup(string classname)
    {
        string name = classname;
        name.ToLower();
        if (GetGame().IsKindOf(classname,"MushroomBase")) return "MUSHROOMS";
        if (name.IndexOf("dead") == 0) return "CARCASSES";
        if (name == "worm") return "FISHING";
        bool can = name.Length() >= 3 && name.Substring(name.Length() - 3,3) == "can";
        if (can || name.Contains("can_") || name.Contains("pajka") || name.Contains("pate") || name.Contains("brisketspread") || name.Contains("lunchmeat"))
        {
            if (name.Contains("_opened")) return "CANNED/OPENED";
            return "CANNED/SEALED";
        }
        array<string> fish = {"carp","catfish","mackerel","walleyepollock","steelheadtrout","roundgoby","bitterlings","shrimp","sardines"};
        foreach (string species : fish) { if (name.IndexOf(species) == 0) return "FISH"; }
        if (name.Contains("meat") || name == "lard" || name == "guts") return "MEAT";
        if (name.Contains("pepper") || name.Contains("tomato") || name.Contains("potato") || name.Contains("pumpkin") || name.Contains("zucchini")) return "VEGETABLES";
        if (name == "apple" || name == "pear" || name == "plum" || name == "figs" || name.Contains("berry")) return "FRUIT";
        if (name == "rice" || name.Contains("cereal") || name == "powderedmilk" || name == "crackers" || name == "saltysticks") return "DRY_FOOD";
        if (name.Contains("zagorky") || name.Contains("candycane") || name == "honey" || name == "marmalade" || name == "chips") return "SNACKS";
        return "OTHER";
    }

    static string Group(string section, string classname, string model)
    {
        string name = classname;
        name.ToLower();
        if (section == "VEHICLE_PARTS/BODY") return BodyGroup(classname,model);
        if (section == "FOOD_DRINKS/FOOD") return FoodGroup(classname);
        if (section == "ATTACHMENTS/SUPPORT")
        {
            if (name.Contains("ghillie")) return "CAMOUFLAGE";
            string kind;
            if (name.Contains("bttstck")) kind = "STOCKS";
            else if (name.Contains("hndgrd")) kind = "HANDGUARDS";
            if (kind == "") return "OTHER";
            if (name.IndexOf("ak") == 0) return kind+"/SYSTEM_AK";
            if (name.IndexOf("m4_") == 0) return kind+"/SYSTEM_M4";
            if (name.IndexOf("mp5") == 0) return kind+"/SYSTEM_MP5";
            if (name.IndexOf("fal_") == 0) return kind+"/SYSTEM_FAL";
            if (name.IndexOf("scar_") == 0) return kind+"/SYSTEM_SCAR";
            return kind+"/OTHER";
        }
        if (section == "GEAR/CONSUMABLES")
        {
            if (GetGame().IsKindOf(classname,"Pelt_Base") || name.Contains("pelt") || name == "tannedleather") return "PELTS";
            if (name.Contains("gascanister")) return "GAS";
            if (name.Contains("chemlight") || name == "roadflare" || name == "battery9v") return "LIGHT_POWER";
            if (name == "hook" || name == "jig" || name == "bait") return "FISHING";
            if (name == "nail" || name == "nailbox" || name == "metalplate" || name == "woodenplank" || name == "stone" || name == "smallstone" || name == "pileofbricks" || name.Contains("mortarmix") || name == "gardenlime") return "MATERIALS";
            if (name.Contains("bark") || name == "matchbox") return "FIRE_STARTING";
            if (name.Contains("rag") || name.Contains("paper") || name == "netting") return "TEXTILES";
            return "OTHER";
        }
        if (section == "GEAR/TOOLS/OTHER")
        {
            if (name == "raycaster" || name == "undergroundbreadcrumbhandle" || name == "undergroundtriggerhandle") return "TECHNICAL";
            if (name.Contains("fishingrod")) return "FISHING";
            if (name.Contains("key") || name.Contains("handcuff")) return "KEYS_RESTRAINTS";
            if (name.Contains("alarmclock") || name == "kitchentimer" || name.IndexOf("pen_") == 0) return "CLOCKS_WRITING";
            if (name == "flashlight" || name == "heatpack" || name.Contains("fireworks")) return "LIGHT_POWER";
            if (name.Contains("detonator")) return "DETONATORS";
            return "OTHER";
        }
        if (section == "AMMO/ROUNDS")
        {
            if (name.Contains("bolt")) return "BOLTS";
            if (name.IndexOf("ammo_flare") == 0) return "FLARES";
            if (name.IndexOf("ammo_40mm_") == 0) return "GRENADES";
            return "CARTRIDGES/CAL_"+IOTWeaponCatalog.AmmoCaliber(classname);
        }
        if (section == "GEAR/CONTAINERS")
        {
            if (name.IndexOf("barrel_") == 0) return "BARRELS";
            if (name.IndexOf("giftbox_") == 0) return "GIFTS";
            if (name.IndexOf("bear_") == 0) return "TOYS";
            if (name.Contains("bag") || name.Contains("nbcpack") || name == "firstaidkit") return "BAGS";
            if (name.Contains("case") || name == "ammobox") return "CASES";
            return "OTHER";
        }
        if (section == "GEAR/CAMPING/FLAGS")
        {
            if (GetGame().IsKindOf(classname,"Flag_Base")) return "FLAGS/"+SymbolGroup(classname);
            return "FLAGPOLES";
        }
        if (section == "OTHER")
        {
            if (name.Contains("head") && name.IndexOf("male") == 0) return "CHARACTER_HEADS/MALE";
            if (name.Contains("head") && name.IndexOf("female") == 0) return "CHARACTER_HEADS/FEMALE";
            if (name == "head_default") return "CHARACTER_HEADS/OTHER";
            if (name == "powergeneratorstatic") return "DEVICES";
            if (name == "storagebox_wooden") return "STORAGE";
            return "OTHER";
        }
        if (section.Contains("MODEL_Armband_ColorBase")) return SymbolGroup(classname);
        return "OTHER";
    }
}

// Read-only official CE reference. No entities, CE registration or export entries.
class IOTLootVolumes
{
    protected ref array<ref IOTLootPoint> m_Points = new array<ref IOTLootPoint>;
    protected ref array<Shape> m_Shapes = new array<Shape>;
    protected Object m_Anchor;
    protected int m_RequestedMap = -1;
    protected int m_Map;
    protected bool m_Known;
    protected bool m_Readable;
    protected bool m_Snapshot;
    protected ref IOTLootSources m_Sources = new IOTLootSources;
    protected bool m_Enabled;
    protected bool m_Drawn;
    protected vector m_Pose[4];

    void ~IOTLootVolumes() { ClearShapes(); }

    static string DataPath() { return "iot\\proxytool\\data\\loot_volumes.txt"; }

    static string MapName(int index)
    {
        if (index == 1) return "ChernarusPlus";
        if (index == 2) return "Livonia";
        if (index == 3) return "Sakhal";
        if (index == 4) return "Nasdara";
        return "";
    }

    static int WorldMap()
    {
        string world = GetGame().GetWorldName();
        world.ToLower();
        if (world == "chernarusplus") return 1;
        if (world == "enoch") return 2;
        if (world == "sakhal") return 3;
        if (world == "nasdara") return 4;
        return 0;
    }

    static vector ModelPosition(vector ce) { return Vector(-ce[2],ce[1],ce[0]); }
    static vector WorldPosition(Object anchor, vector ce) { return anchor.ModelToWorld(ModelPosition(ce)); }

    bool Enabled() { return m_Enabled; }
    bool Known() { return m_Known; }
    bool Readable() { return m_Readable; }
    bool UsingSnapshot() { return m_Snapshot; }
    int SourceMap() { return m_Map; }
    int Count() { return m_Points.Count(); }
    int ShapeCount() { return m_Shapes.Count(); }
    IOTLootPoint Point(int index) { return m_Points[index]; }

    int IncompleteCount()
    {
        int count;
        foreach (IOTLootPoint point : m_Points) if (point.Range < 0 || point.Height < 0) count++;
        return count;
    }

    void Enable(bool enabled)
    {
        m_Enabled = enabled;
        if (!enabled) ClearShapes();
    }

    protected void ClearShapes()
    {
        foreach (Shape shape : m_Shapes) if (shape) shape.Destroy();
        m_Shapes.Clear();
        m_Drawn = false;
    }

    void Reset()
    {
        ClearShapes();
        m_Anchor = null;
        m_RequestedMap = -1;
        m_Map = 0;
        m_Known = false;
        m_Readable = false;
        m_Snapshot = false;
        m_Points.Clear();
    }

    // Source files are cached for the editor session. Each anchor gets a view
    // of exactly one map's data; the installed XML is authoritative when valid.
    protected void Read(Object anchor, int requestedMap)
    {
        Reset();
        m_Anchor = anchor;
        m_RequestedMap = requestedMap;
        if (!anchor) return;
        string classname = anchor.GetType();
        int preferred = requestedMap;
        if (preferred == 0) preferred = WorldMap();
        IOTLootReference data = m_Sources.Resolve(classname,preferred);
        m_Map = data.MapIndex;
        m_Readable = data.Readable;
        m_Known = data.Known;
        m_Snapshot = data.Snapshot;
        foreach (IOTLootPoint point : data.Points) m_Points.Insert(point);
        PrintToRPT("[PROXY LOOT VOLUMES] "+classname+" map="+MapName(m_Map)+" snapshot="+m_Snapshot.ToString()+" points="+Count().ToString()+" unspecified="+IncompleteCount().ToString());
    }

    void Update(Object anchor, int requestedMap, bool visible)
    {
        if (!m_Enabled || !visible || !anchor)
        {
            if (m_Drawn) ClearShapes();
            if (!anchor && m_Anchor) Reset();
            return;
        }
        if (anchor != m_Anchor || requestedMap != m_RequestedMap) Read(anchor,requestedMap);
        vector pose[4];
        anchor.GetTransform(pose);
        bool changed = !m_Drawn;
        for (int i = 0; i < 4; i++) if (vector.Distance(pose[i],m_Pose[i]) > 0.00001) changed = true;
        if (!changed) return;
        ClearShapes();
        copyarray(m_Pose,pose);
        Draw();
        m_Drawn = true;
    }

    protected void Keep(Shape shape) { if (shape) m_Shapes.Insert(shape); }

    protected void Draw()
    {
        int flags = ShapeFlags.NOZWRITE | ShapeFlags.TRANSP | ShapeFlags.DOUBLESIDE;
        foreach (IOTLootPoint point : m_Points)
        {
            // Point center at the base. Shape geometry is built explicitly in
            // world space to avoid relying on native cylinder pivot conventions.
            vector base = WorldPosition(m_Anchor,point.Position);
            bool complete = point.Range >= 0 && point.Height >= 0;
            int outline = ARGB(210,70,205,245);
            if (!complete) outline = ARGB(230,245,185,65);
            Keep(Shape.CreateSphere(outline,ShapeFlags.NOZWRITE | ShapeFlags.NOOUTLINE,base,0.025));
            if (point.Range <= 0) continue;
            vector lowerRing[25];
            vector upperRing[25];
            vector faces[288];
            int faceCount = 0;
            vector top = base;
            if (complete) top = WorldPosition(m_Anchor,point.Position+Vector(0,point.Height,0));
            for (int segment = 0; segment < 24; segment++)
            {
                float a = segment*Math.PI2/24;
                float b = (segment+1)*Math.PI2/24;
                vector offsetA = Vector(Math.Cos(a)*point.Range,0,Math.Sin(a)*point.Range);
                vector offsetB = Vector(Math.Cos(b)*point.Range,0,Math.Sin(b)*point.Range);
                vector lowerA = WorldPosition(m_Anchor,point.Position+offsetA);
                vector lowerB = WorldPosition(m_Anchor,point.Position+offsetB);
                lowerRing[segment] = lowerA;
                if (segment == 23) lowerRing[24] = lowerB;
                if (!complete || point.Height == 0) continue;
                vector upperA = lowerA+(top - base);
                vector upperB = lowerB+(top - base);
                upperRing[segment] = upperA;
                if (segment == 23) upperRing[24] = upperB;
                if (segment % 6 == 0) Keep(Shape.Create(ShapeType.LINE,outline,flags,lowerA,upperA));
                faces[faceCount++] = lowerA; faces[faceCount++] = lowerB; faces[faceCount++] = upperB;
                faces[faceCount++] = lowerA; faces[faceCount++] = upperB; faces[faceCount++] = upperA;
                faces[faceCount++] = base; faces[faceCount++] = lowerB; faces[faceCount++] = lowerA;
                faces[faceCount++] = top; faces[faceCount++] = upperA; faces[faceCount++] = upperB;
            }
            Keep(Shape.CreateLines(outline,flags,lowerRing,25));
            if (faceCount > 0)
            {
                Keep(Shape.CreateLines(outline,flags,upperRing,25));
                Keep(Shape.CreateTris(ARGB(25,70,205,245),flags | ShapeFlags.NOOUTLINE,faces,faceCount/3));
            }
        }
    }

    string Detail()
    {
        if (!m_Readable) return IOTL.T("LOOT_DATA_UNAVAILABLE");
        if (m_Map == 0) return IOTL.T("LOOT_GROUP_UNAVAILABLE");
        string text = IOTL.F("LOOT_SOURCE",MapName(m_Map));
        if (m_Snapshot) text = text+"\n"+IOTL.T("LOOT_FROM_SNAPSHOT");
        else text = text+"\n"+IOTL.F("LOOT_FROM_GAME",IOTLootCache.Version());
        if (!m_Known) return text+"\n"+IOTL.T("LOOT_GROUP_UNAVAILABLE");
        if (IncompleteCount() > 0) text = text+"\n"+IOTL.T("LOOT_DIMENSIONS_UNSPECIFIED");
        return text;
    }
}

// Offline proxy authoring: existing world items, native Gizmo, precise controls.
// CE export remains calibrated for an unrotated, scale-one anchor / group a=90.
enum IOTNoticeKind
{
    ERROR,
    SUCCESS,
    WARNING
}

enum IOTHistoryKind
{
    TRANSFORM,
    ITEM_CREATE,
    ITEM_DELETE
}

// Shared identity keeps earlier edits attached to an item after native recreation.
class IOTHistoryItem
{
    ItemBase Target;
    IOTSceneEntry Scene;
}

class IOTTransformEdit
{
    IOTHistoryKind Kind;
    Object Target;
    ref IOTHistoryItem Item;
    string Classname;
    int SceneIndex;
    int CreatedIndex;
    bool SimulationDisabled;
    vector Before[4];
    vector After[4];
}

enum IOTProjectTransition
{
    OPEN_PROJECT,
    REPLACE_ANCHOR,
    EXIT_EDITOR
}

class IOTPendingProjectAction
{
    IOTProjectTransition Kind;
    string Name;
    Object ExpectedAnchor;
    bool AtSurface;
    vector Position;
    vector Normal;
    int LootMap;
}

class IOTProxyTool : ScriptedWidgetEventHandler
{
    protected Object m_Anchor;
    protected ref IOTLootVolumes m_LootVolumes = new IOTLootVolumes;
    protected int m_LootMap;
    protected int m_ReplaceLootMap;
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
    protected bool m_GameMenuOpen;
    protected bool m_ResumeProjectDialog;
    protected bool m_ResumeUnsavedDialog;
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
    protected bool m_CameraHeld;
    protected bool m_RightWasDown;
    protected bool m_CameraBlockedUntilRelease;
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
    protected int m_SelfTestStartupDeadline;
    protected vector m_TestPlayerPosition;
    protected vector m_TestPlayerMovedPosition;
    protected int m_Attempts;
    protected int m_MoveStepIndex = 1;
    protected int m_AngleStepIndex = 1;
    protected Widget m_Root;
    protected Widget m_Toolbar;
    protected ref IOTToolbarChrome m_ToolbarChrome;
    protected ref IOTToolbarChrome m_ToolbarHoverTest;
    protected Widget m_ErrorRoot;
    protected MultilineTextWidget m_ErrorText;
    protected string m_LastError;
    protected IOTNoticeKind m_NoticeKind;
    protected string m_NoticeMessage;
    protected int m_NoticeUntil;
    protected float m_ChromeTop;
    protected int m_ChromeWidth;
    protected int m_ChromeHeight;
    protected float m_PanelScale = 1;
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
    protected ref array<ref IOTTransformEdit> m_Undo = new array<ref IOTTransformEdit>;
    protected ref array<ref IOTTransformEdit> m_Redo = new array<ref IOTTransformEdit>;
    protected ref IOTTransformEdit m_HistoryPending;
    protected string m_HistoryGroup;
    protected bool m_ApplyingHistory;
    protected Widget m_ProjectRoot;
    protected EditBoxWidget m_ProjectName;
    protected TextListboxWidget m_ProjectList;
    protected ref array<string> m_ProjectNames = new array<string>;
    protected bool m_ProjectSaving;
    protected string m_ProjectConfirm;
    protected string m_CurrentProject;
    protected ref array<ItemBase> m_ProjectFrozen = new array<ItemBase>;
    protected ref IOTProjectData m_ProjectBaseline;
    protected Widget m_UnsavedRoot;
    protected ref IOTPendingProjectAction m_PendingProjectAction;
    protected bool m_ExitApproved;

    protected bool SavedObjectMatches(IOTProjectObject saved, Object current)
    {
        if (!saved || !current) return !saved && !current;
        return saved.Classname == current.GetType() && vector.Distance(saved.Position,current.GetPosition()) < 0.00001 && vector.Distance(saved.Orientation,current.GetOrientation()) < 0.00001;
    }

    bool HasUnsavedChanges()
    {
        if (!m_Booted) return false;
        Object anchor = ExistingSceneAnchor();
        if (!m_ProjectBaseline) return anchor != null;
        if (m_LootMap != m_ProjectBaseline.LootMap || !SavedObjectMatches(m_ProjectBaseline.Anchor,anchor)) return true;
        Man player = GetGame().GetPlayer();
        if (player && vector.Distance(player.GetPosition(),m_ProjectBaseline.CharacterPosition) >= 0.00001) return true;
        int index;
        foreach (IOTSceneEntry scene : m_Scenes)
        {
            foreach (ItemBase item : scene.Items)
            {
                if (!item || item.GetHierarchyParent() || item.IsHologram()) continue;
                if (index >= m_ProjectBaseline.Items.Count() || !SavedObjectMatches(m_ProjectBaseline.Items[index],item)) return true;
                index++;
            }
        }
        return index != m_ProjectBaseline.Items.Count();
    }

    protected void MarkProjectClean()
    {
        m_ProjectBaseline = CaptureProject();
        UpdateToolbar();
    }

    bool UnsavedDialogOpen() { return m_UnsavedRoot && m_UnsavedRoot.IsVisible(); }

    protected void PositionUnsavedDialog()
    {
        if (!UnsavedDialogOpen()) return;
        int width,height;
        GetScreenSize(width,height);
        m_UnsavedRoot.SetScreenPos(0,0);
        m_UnsavedRoot.SetScreenSize(width,height);
        Widget dialog = m_UnsavedRoot.FindAnyWidget("UnsavedDialog");
        float w = Math.Min(560*m_PanelScale,width);
        float h = Math.Min(230*m_PanelScale,height);
        dialog.SetScreenSize(w,h);
        dialog.SetScreenPos((width-w)*0.5,(height-h)*0.5);
    }

    protected void CancelPendingProjectAction()
    {
        m_UnsavedRoot.Show(false);
        m_PendingProjectAction = null;
        SetFocus(null);
        UpdateGizmo();
    }

    protected bool RequestProjectAction(IOTPendingProjectAction action)
    {
        EndCameraHold();
        SetPointer(true);
        SetFocus(null);
        CancelWorldGesture();
        FinishHistory();
        if (!HasUnsavedChanges()) return PerformProjectAction(action);
        m_PendingProjectAction = action;
        m_Browser.HideHoverPreview();
        m_ToolbarChrome.HideHint();
        ClearError();
        m_UnsavedRoot.Show(true);
        PositionUnsavedDialog();
        SetFocus(m_UnsavedRoot.FindAnyWidget("UnsavedCancel"));
        UpdateGizmo();
        return false;
    }

    protected bool PerformProjectAction(IOTPendingProjectAction action)
    {
        if (action.Kind == IOTProjectTransition.OPEN_PROJECT) return LoadProject(action.Name,true);
        else if (action.Kind == IOTProjectTransition.REPLACE_ANCHOR)
        {
            if (!action.ExpectedAnchor || ExistingSceneAnchor() != action.ExpectedAnchor) { ReportError(IOTL.T("REPLACE_SCENE_CHANGED")); return false; }
            return SpawnResolvedSceneClass(action.Name,false,action.AtSurface,action.Position,action.Normal,true,action.LootMap);
        }
        else
        {
            m_ExitApproved = true;
            GetGame().GetMission().AbortMission();
            return true;
        }
        return false;
    }

    protected void UnsavedChoice(bool save)
    {
        IOTPendingProjectAction action = m_PendingProjectAction;
        if (!action) return;
        m_UnsavedRoot.Show(false);
        SetFocus(null);
        if (save) ShowProjectDialog(true);
        else
        {
            m_PendingProjectAction = null;
            PerformProjectAction(action);
        }
    }

    bool RequestEditorExit()
    {
        if (m_ExitApproved || !HasUnsavedChanges()) return false;
        if (m_PendingProjectAction) return true;
        GetGame().GetMission().Continue();
        GetGame().GetUIManager().CloseAll();
        if (m_PlayerMode) EnterEditor();
        UpdateGameMenuVisibility(false);
        IOTPendingProjectAction action = new IOTPendingProjectAction;
        action.Kind = IOTProjectTransition.EXIT_EDITOR;
        RequestProjectAction(action);
        return true;
    }

    protected void ReleaseProjectItems()
    {
        foreach (ItemBase item : m_ProjectFrozen) if (item) SetItemSimulation(item,false);
        m_ProjectFrozen.Clear();
    }

    protected bool ProjectVectorValid(vector value, float limit)
    {
        for (int i = 0; i < 3; i++) if (!(Math.AbsFloat(value[i]) <= limit)) return false;
        return true;
    }

    protected bool ValidateProject(IOTProjectData data)
    {
        if (!data || data.Version != 1 || !data.Items) { ReportError(IOTL.T("PROJECT_FORMAT_INVALID")); return false; }
        if (data.LootMap < 0 || data.LootMap > 4) { ReportError(IOTL.T("PROJECT_FORMAT_INVALID")); return false; }
        string world = GetGame().GetWorldName();
        string savedWorld = data.WorldName;
        world.ToLower(); savedWorld.ToLower();
        if (world != savedWorld) { ReportError(IOTL.T("PROJECT_WORLD_INVALID")); return false; }
        if (!ProjectVectorValid(data.CharacterPosition,100000) || !ProjectVectorValid(data.CameraPosition,100000) || !ProjectVectorValid(data.CameraOrientation,3600) || !(data.CameraSpeed >= 0.1 && data.CameraSpeed <= 16)) { ReportError(IOTL.T("PROJECT_FORMAT_INVALID")); return false; }
        if (!data.Anchor && data.Items.Count() > 0) { ReportError(IOTL.T("PROJECT_FORMAT_INVALID")); return false; }
        array<ref IOTProjectObject> entities = new array<ref IOTProjectObject>;
        if (data.Anchor) entities.Insert(data.Anchor);
        foreach (IOTProjectObject item : data.Items) entities.Insert(item);
        foreach (IOTProjectObject entry : entities)
        {
            if (!entry || entry.Classname == "" || !ProjectVectorValid(entry.Position,100000) || !ProjectVectorValid(entry.Orientation,3600)) { ReportError(IOTL.T("PROJECT_FORMAT_INVALID")); return false; }
            if (!GetGame().ConfigIsExisting("CfgVehicles "+entry.Classname) && !GetGame().ConfigIsExisting("CfgWeapons "+entry.Classname) && !GetGame().ConfigIsExisting("CfgMagazines "+entry.Classname)) { ReportError(IOTL.F("PROJECT_CLASS_INVALID",entry.Classname)); return false; }
        }
        if (data.Anchor && data.Anchor.Orientation.Length() > 0.001) { ReportError(IOTL.T("ANCHOR_TRANSFORM_LIMIT")); return false; }
        return true;
    }

    protected IOTProjectObject ProjectObject(Object entity)
    {
        IOTProjectObject result = new IOTProjectObject;
        result.Classname = entity.GetType();
        result.Position = entity.GetPosition();
        result.Orientation = entity.GetOrientation();
        return result;
    }

    protected IOTProjectData CaptureProject()
    {
        if (m_PlayerMode || AnchorReplacementPending()) return null;
        if (m_DirtyInputs && !ApplyFields()) return null;
        FinishHistory();
        IOTProjectData data = new IOTProjectData;
        data.Version = 1;
        data.WorldName = GetGame().GetWorldName();
        data.LootMap = m_LootMap;
        Object anchor = ExistingSceneAnchor();
        if (anchor) data.Anchor = ProjectObject(anchor);
        foreach (IOTSceneEntry scene : m_Scenes)
        {
            if (scene.Anchor != anchor) { ReportError(IOTL.T("PROJECT_FORMAT_INVALID")); return null; }
            foreach (ItemBase item : scene.Items)
                if (item && !item.GetHierarchyParent() && !item.IsHologram()) data.Items.Insert(ProjectObject(item));
        }
        data.CharacterPosition = GetGame().GetPlayer().GetPosition();
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        data.CameraPosition = camera.GetPosition();
        data.CameraOrientation = camera.GetOrientation();
        data.CameraSpeed = m_CameraMultiplier;
        return data;
    }

    bool SaveProject(string name)
    {
        name.TrimInPlace();
        IOTProjectData data = CaptureProject();
        if (!data) return false;
        string error;
        if (!IOTProjectFiles.Save(name,data,error)) { ReportError(error); return false; }
        m_CurrentProject = name;
        m_ProjectBaseline = data;
        UpdateToolbar();
        PrintToRPT("[PROXY PROJECT] Saved "+IOTProjectFiles.Path(name));
        ReportSuccess(IOTL.F("PROJECT_SAVED",name+".json"));
        return true;
    }

    protected bool ApplyProject(IOTProjectData data)
    {
        if (m_PlayerMode || EditorModalPending() || !ValidateProject(data)) return false;
        array<Object> staged = new array<Object>;
        array<ItemBase> items = new array<ItemBase>;
        Object anchor;
        int flags = ECE_SETUP | ECE_CREATEPHYSICS | ECE_UPDATEPATHGRAPH | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOSURFACEALIGN;
        bool valid = true;
        if (data.Anchor)
        {
            anchor = GetGame().CreateObjectEx(data.Anchor.Classname,"0 -10000 0",flags,RF_IGNORE);
            if (anchor) staged.Insert(anchor);
            valid = ValidAnchor(anchor);
        }
        foreach (IOTProjectObject entry : data.Items)
        {
            if (!valid) break;
            Object created = GetGame().CreateObjectEx(entry.Classname,"0 -10000 0",flags,RF_IGNORE);
            if (created) staged.Insert(created);
            ItemBase item = ItemBase.Cast(created);
            if (!item) { valid = false; break; }
            SetItemSimulation(item,true);
            items.Insert(item);
        }
        if (!valid)
        {
            foreach (Object failed : staged) if (failed) GetGame().ObjectDelete(failed);
            ReportError(IOTL.T("PROJECT_STAGE_FAILED"));
            return false;
        }
        ClearSceneLayout();
        if (anchor)
        {
            anchor.SetPosition(data.Anchor.Position);
            anchor.SetOrientation("0 0 0");
            anchor.SetScale(1);
            SetAnchor(anchor);
            m_LootMap = data.LootMap;
            for (int i = 0; i < items.Count(); i++)
            {
                ItemBase placed = items[i];
                placed.SetPosition(data.Items[i].Position);
                placed.SetOrientation(data.Items[i].Orientation);
                m_ActiveScene.Items.Insert(placed);
                m_CreatedItems.Insert(placed);
                m_ProjectFrozen.Insert(placed);
            }
        }
        GetGame().GetPlayer().SetPosition(data.CharacterPosition);
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        camera.SetPosition(data.CameraPosition);
        camera.SetOrientation(data.CameraOrientation);
        m_CameraMultiplier = data.CameraSpeed;
        m_HasCameraPose = false;
        SetPointer(true);
        if (items.Count() > 0) SelectItem(items[0]);
        else if (anchor) SelectMoveTarget(anchor,false);
        RefreshObjects();
        ClearHistory();
        ClearError();
        return true;
    }

    bool LoadProject(string name, bool replaceConfirmed = false)
    {
        if (m_PlayerMode || EditorModalPending()) return false;
        if (ExistingSceneAnchor() && !replaceConfirmed) { ReportError(IOTL.T("PROJECT_OPEN_WARNING")); return false; }
        IOTProjectData data;
        string error;
        if (!IOTProjectFiles.Load(name,data,error)) { ReportError(error); return false; }
        if (!ApplyProject(data)) return false;
        m_CurrentProject = name;
        MarkProjectClean();
        PrintToRPT("[PROXY PROJECT] Opened "+IOTProjectFiles.Path(name));
        ReportSuccess(IOTL.F("PROJECT_OPENED",name+".json"));
        return true;
    }

    protected void PositionProjectDialog()
    {
        if (!ProjectDialogOpen()) return;
        int width,height;
        GetScreenSize(width,height);
        m_ProjectRoot.SetScreenPos(0,0);
        m_ProjectRoot.SetScreenSize(width,height);
        Widget dialog = m_ProjectRoot.FindAnyWidget("ProjectDialog");
        float w = Math.Min(560*m_PanelScale,width);
        float h = Math.Min(440*m_PanelScale,height);
        dialog.SetScreenSize(w,h);
        dialog.SetScreenPos((width-w)*0.5,(height-h)*0.5);
    }

    protected void ResetProjectConfirm()
    {
        m_ProjectConfirm = "";
        string action = "PROJECT_OPEN";
        if (m_ProjectSaving) action = "PROJECT_SAVE";
        ButtonWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectAction")).SetText(IOTL.T(action));
        string info = IOTProjectFiles.Folder();
        if (!m_ProjectSaving) info = IOTL.T("PROJECT_OPEN_WARNING")+"\n"+info;
        MultilineTextWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectInfo")).SetText(info);
    }

    protected void ShowProjectDialog(bool saving)
    {
        if (m_PlayerMode || EditorModalPending() || !m_Pointer || m_CatalogPressed) return;
        SetFocus(null);
        CancelWorldGesture();
        FinishHistory();
        m_Browser.HideHoverPreview();
        ClearError();
        m_ProjectSaving = saving;
        m_ProjectNames = IOTProjectFiles.Names();
        m_ProjectList.ClearItems();
        foreach (string name : m_ProjectNames) m_ProjectList.AddItem(name,null,0);
        m_ProjectName.SetText(m_CurrentProject);
        string title = "PROJECT_OPEN";
        if (saving) title = "PROJECT_SAVE";
        TextWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectTitle")).SetText(IOTL.T(title));
        ResetProjectConfirm();
        m_ProjectRoot.Show(true);
        PositionProjectDialog();
        SetFocus(m_ProjectName);
        UpdateGizmo();
    }

    protected void CloseProjectDialog()
    {
        m_ProjectRoot.Show(false);
        m_PendingProjectAction = null;
        SetFocus(null);
        m_ProjectConfirm = "";
        ClearError();
        UpdateGizmo();
    }

    protected void ProjectAction()
    {
        string name = m_ProjectName.GetText();
        name.TrimInPlace();
        if (!m_ProjectSaving && IOTProjectFiles.ValidName(name))
        {
            IOTProjectData check;
            string error;
            if (!IOTProjectFiles.Load(name,check,error) || !ValidateProject(check))
            {
                if (error == "") error = m_LastError;
                MultilineTextWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectInfo")).SetText(error);
                return;
            }
        }
        string info;
        if (!IOTProjectFiles.ValidName(name)) info = IOTL.T("PROJECT_NAME_INVALID");
        else if (m_ProjectConfirm != name && ((!m_ProjectSaving && ExistingSceneAnchor()) || (m_ProjectSaving && FileExist(IOTProjectFiles.Path(name)))))
        {
            m_ProjectConfirm = name;
            info = IOTL.T("PROJECT_OPEN_WARNING");
            string action = "PROJECT_OPEN_REPLACE";
            if (m_ProjectSaving) { info = IOTL.T("PROJECT_OVERWRITE"); action = "PROJECT_SAVE_REPLACE"; }
            ButtonWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectAction")).SetText(IOTL.T(action));
        }
        else if (m_ProjectSaving)
        {
            if (SaveProject(name))
            {
                IOTPendingProjectAction continuation = m_PendingProjectAction;
                CloseProjectDialog();
                if (continuation) PerformProjectAction(continuation);
                return;
            }
            info = m_LastError;
        }
        else
        {
            CloseProjectDialog();
            IOTPendingProjectAction open = new IOTPendingProjectAction;
            open.Kind = IOTProjectTransition.OPEN_PROJECT;
            open.Name = name;
            RequestProjectAction(open);
            return;
        }
        MultilineTextWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectInfo")).SetText(info);
    }

    protected bool HistoryTargetValid(Object target)
    {
        if (!target) return false;
        if (target == GetGame().GetPlayer()) return true;
        ItemBase item = ItemBase.Cast(target);
        if (item)
        {
            IOTSceneEntry owner = ItemScene(item);
            return owner && owner.Anchor && !item.GetHierarchyParent() && !item.IsHologram();
        }
        foreach (IOTSceneEntry scene : m_Scenes)
            if (scene.Anchor == target) return true;
        return false;
    }

    protected Object HistoryTarget(IOTTransformEdit change)
    {
        if (change.Item) return change.Item.Target;
        return change.Target;
    }

    protected IOTHistoryItem HistoryItem(ItemBase item)
    {
        foreach (IOTTransformEdit undo : m_Undo)
            if (undo.Item && undo.Item.Target == item) return undo.Item;
        foreach (IOTTransformEdit redo : m_Redo)
            if (redo.Item && redo.Item.Target == item) return redo.Item;
        IOTHistoryItem identity = new IOTHistoryItem;
        identity.Target = item;
        identity.Scene = ItemScene(item);
        return identity;
    }

    protected bool HistoryRestoresItem(IOTTransformEdit change, bool redo)
    {
        return (change.Kind == IOTHistoryKind.ITEM_CREATE && redo) || (change.Kind == IOTHistoryKind.ITEM_DELETE && !redo);
    }

    protected bool HistoryEntryValid(IOTTransformEdit change, bool redo)
    {
        if (change.Kind == IOTHistoryKind.TRANSFORM) return HistoryTargetValid(HistoryTarget(change));
        if (!change.Item || !change.Item.Scene || !change.Item.Scene.Anchor || m_Scenes.Find(change.Item.Scene) < 0) return false;
        if (HistoryRestoresItem(change,redo)) return !change.Item.Target;
        return HistoryTargetValid(change.Item.Target) && ItemScene(change.Item.Target) == change.Item.Scene;
    }

    protected bool HistoryChanged(IOTTransformEdit change)
    {
        if (!change || !HistoryTarget(change)) return false;
        vector current[4];
        HistoryTarget(change).GetTransform(current);
        for (int i = 0; i < 4; i++)
            if (vector.Distance(change.Before[i],current[i]) > 0.000001) return true;
        return false;
    }

    protected bool HistoryAvailable(array<ref IOTTransformEdit> entries, bool redo = false)
    {
        foreach (IOTTransformEdit entry : entries)
            if (HistoryEntryValid(entry,redo)) return true;
        return false;
    }

    protected bool HistoryInputAllowed()
    {
        return m_Booted && !m_PlayerMode && m_Pointer && !m_CameraHeld && !EditorModalPending() && !m_CatalogPressed && !m_HeldButton && (!m_ClickPending || m_ClickReleased) && GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu();
    }

    protected void UpdateHistoryButtons()
    {
        if (!m_Toolbar) return;
        bool allowed = HistoryInputAllowed();
        m_Toolbar.FindAnyWidget("Undo").Enable(allowed && (HistoryAvailable(m_Undo) || HistoryChanged(m_HistoryPending)));
        m_Toolbar.FindAnyWidget("Redo").Enable(allowed && !HistoryChanged(m_HistoryPending) && HistoryAvailable(m_Redo,true));
        m_Toolbar.FindAnyWidget("DeleteItem").Enable(allowed && m_Item && HistoryTargetValid(m_Item));
    }

    protected void BeginHistory(string group)
    {
        if (m_ApplyingHistory || m_PlayerMode || !SelectedObject()) return;
        if (m_HistoryPending && m_HistoryPending.Target == SelectedObject() && m_HistoryGroup == group) return;
        FinishHistory();
        m_HistoryPending = new IOTTransformEdit;
        m_HistoryPending.Target = SelectedObject();
        if (m_Item) m_HistoryPending.Item = HistoryItem(m_Item);
        vector before[4];
        SelectedObject().GetTransform(before);
        copyarray(m_HistoryPending.Before,before);
        m_HistoryGroup = group;
    }

    protected void FinishHistory()
    {
        if (m_ApplyingHistory || !m_HistoryPending) return;
        IOTTransformEdit change = m_HistoryPending;
        m_HistoryPending = null;
        m_HistoryGroup = "";
        if (HistoryTargetValid(HistoryTarget(change)) && HistoryChanged(change))
        {
            vector after[4];
            HistoryTarget(change).GetTransform(after);
            copyarray(change.After,after);
            PushHistory(change);
        }
        UpdateHistoryButtons();
    }

    protected void PushHistory(IOTTransformEdit change)
    {
        m_Undo.Insert(change);
        if (m_Undo.Count() > 100) m_Undo.Remove(0);
        m_Redo.Clear();
        UpdateHistoryButtons();
    }

    protected IOTTransformEdit ItemHistoryEdit(ItemBase item, IOTHistoryKind kind)
    {
        FinishHistory();
        IOTTransformEdit change = new IOTTransformEdit;
        change.Kind = kind;
        change.Item = HistoryItem(item);
        change.Classname = item.GetType();
        change.SceneIndex = change.Item.Scene.Items.Find(item);
        change.CreatedIndex = m_CreatedItems.Find(item);
        change.SimulationDisabled = item.GetIsSimulationDisabled();
        if (item == m_Item && m_Editing) change.SimulationDisabled = m_WasSimulationDisabled;
        vector pose[4];
        item.GetTransform(pose);
        copyarray(change.Before,pose);
        copyarray(change.After,pose);
        return change;
    }

    protected bool ApplyItemHistory(IOTTransformEdit change, bool restore)
    {
        IOTSceneEntry scene = change.Item.Scene;
        ItemBase item = change.Item.Target;
        if (restore)
        {
            if (!GetGame().ConfigIsExisting("CfgVehicles "+change.Classname)) { ReportError(IOTL.F("SPAWN_FAILED",change.Classname)); return false; }
            vector pose[4];
            if (change.Kind == IOTHistoryKind.ITEM_CREATE) copyarray(pose,change.After);
            else copyarray(pose,change.Before);
            int flags = ECE_SETUP | ECE_CREATEPHYSICS | ECE_UPDATEPATHGRAPH | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOSURFACEALIGN;
            item = ItemBase.Cast(GetGame().CreateObjectEx(change.Classname,pose[3],flags,RF_IGNORE));
            if (!item) { ReportError(IOTL.F("SPAWN_FAILED",change.Classname)); return false; }
            item.SetTransform(pose);
            SetItemSimulation(item,change.SimulationDisabled);
            scene.Items.InsertAt(item,Math.Min(change.SceneIndex,scene.Items.Count()));
            if (change.CreatedIndex >= 0) m_CreatedItems.InsertAt(item,Math.Min(change.CreatedIndex,m_CreatedItems.Count()));
            change.Item.Target = item;
            SelectItem(item);
        }
        else
        {
            if (item == m_Item) DeselectItem();
            scene.Items.RemoveItem(item);
            m_CreatedItems.RemoveItem(item);
            m_Items.RemoveItem(item);
            m_ProjectFrozen.RemoveItem(item);
            change.Item.Target = null;
            GetGame().ObjectDelete(item);
        }
        RefreshObjects();
        UpdateGizmo();
        return true;
    }

    bool DeleteSelectedItem()
    {
        if (!HistoryInputAllowed() || !m_Item || !HistoryTargetValid(m_Item)) return false;
        SetFocus(null);
        IOTTransformEdit change = ItemHistoryEdit(m_Item,IOTHistoryKind.ITEM_DELETE);
        if (!ApplyItemHistory(change,false)) return false;
        PushHistory(change);
        return true;
    }

    protected void ClearHistory()
    {
        m_HistoryPending = null;
        m_HistoryGroup = "";
        m_Undo.Clear();
        m_Redo.Clear();
        UpdateHistoryButtons();
    }

    bool StepHistory(bool redo)
    {
        if (!HistoryInputAllowed()) return false;
        FinishHistory();
        array<ref IOTTransformEdit> source = m_Undo;
        array<ref IOTTransformEdit> destination = m_Redo;
        if (redo) { source = m_Redo; destination = m_Undo; }
        while (source.Count() > 0)
        {
            int last = source.Count() - 1;
            IOTTransformEdit change = source[last];
            if (!HistoryEntryValid(change,redo)) { source.Remove(last); continue; }
            m_ApplyingHistory = true;
            CancelWorldGesture();
            SetFocus(null);
            bool selected;
            if (change.Kind != IOTHistoryKind.TRANSFORM) selected = ApplyItemHistory(change,HistoryRestoresItem(change,redo));
            else
            {
                Object target = HistoryTarget(change);
                ItemBase item = ItemBase.Cast(target);
                if (item) selected = SelectItem(item);
                else selected = SelectMoveTarget(target,target == GetGame().GetPlayer());
                vector pose[4];
                if (redo) copyarray(pose,change.After);
                else copyarray(pose,change.Before);
                if (selected && item) item.SetTransform(pose);
                else if (selected) target.SetPosition(pose[3]);
            }
            if (selected)
            {
                source.Remove(last);
                destination.Insert(change);
                m_DirtyInputs = false;
                SyncFields();
                RefreshCreatedItems(true);
                UpdateGizmo();
            }
            m_ApplyingHistory = false;
            UpdateHistoryButtons();
            return selected;
        }
        UpdateHistoryButtons();
        return false;
    }

    bool HandleHistoryKey(int key)
    {
        if (m_PlayerMode || EditBoxWidget.Cast(GetFocus())) return false;
        if (!KeyState(KeyCode.KC_LCONTROL) && !KeyState(KeyCode.KC_RCONTROL)) return false;
        if (key != KeyCode.KC_Z && key != KeyCode.KC_Y) return false;
        bool redo = key == KeyCode.KC_Y || KeyState(KeyCode.KC_LSHIFT) || KeyState(KeyCode.KC_RSHIFT);
        StepHistory(redo);
        return true;
    }

    void IOTProxyTool()
    {
        IOTEditorTheme.Load();
        IOTLootCache.Clear();
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
        m_Toolbar.SetSort(1740);
        m_Toolbar.Show(false);
        m_ToolbarChrome = new IOTToolbarChrome(m_Toolbar);
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
        m_ProjectRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\project_dialog.layout");
        m_ProjectRoot.SetHandler(this);
        m_ProjectRoot.SetSort(2600);
        m_ProjectRoot.Show(false);
        m_UnsavedRoot = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\unsaved_project.layout");
        m_UnsavedRoot.SetHandler(this);
        m_UnsavedRoot.SetSort(2700);
        m_UnsavedRoot.Show(false);
        TextWidget.Cast(m_UnsavedRoot.FindAnyWidget("UnsavedTitle")).SetText(IOTL.T("UNSAVED_TITLE"));
        MultilineTextWidget.Cast(m_UnsavedRoot.FindAnyWidget("UnsavedText")).SetText(IOTL.T("UNSAVED_TEXT"));
        ButtonWidget.Cast(m_UnsavedRoot.FindAnyWidget("UnsavedSave")).SetText(IOTL.T("UNSAVED_SAVE"));
        ButtonWidget.Cast(m_UnsavedRoot.FindAnyWidget("UnsavedDiscard")).SetText(IOTL.T("UNSAVED_DISCARD"));
        ButtonWidget.Cast(m_UnsavedRoot.FindAnyWidget("UnsavedCancel")).SetText(IOTL.T("REPLACE_CANCEL"));
        m_ProjectName = EditBoxWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectName"));
        m_ProjectList = TextListboxWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectList"));
        TextWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectNameLabel")).SetText(IOTL.T("PROJECT_NAME"));
        ButtonWidget.Cast(m_ProjectRoot.FindAnyWidget("ProjectCancel")).SetText(IOTL.T("REPLACE_CANCEL"));
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
        PrintToRPT("[PROXY TOOL V2] Panel loaded. Hold RMB in world for camera; F4 player/editor; F7/F8 move/rotate; F10 export.");
    }

    void ~IOTProxyTool()
    {
        if (m_LootVolumes) m_LootVolumes.Reset();
        if (GetGame()) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(Tick);
        SetPlayerHudHidden(false);
        if (m_ModeHint) m_ModeHint.Unlink();
        if (m_SpeedRoot) m_SpeedRoot.Unlink();
        if (m_CatalogDragRoot) m_CatalogDragRoot.Unlink();
        if (m_ErrorRoot) m_ErrorRoot.Unlink();
        if (m_ReplaceRoot) m_ReplaceRoot.Unlink();
        if (m_ProjectRoot) m_ProjectRoot.Unlink();
        if (m_UnsavedRoot) m_UnsavedRoot.Unlink();
        m_Browser = null;
        m_CreatedTray = null;
        m_Viewport = null;
        m_ToolbarChrome = null;
        if (m_Toolbar) m_Toolbar.Unlink();
        if (m_Root) m_Root.Unlink();
    }

    protected void Notify(IOTNoticeKind kind, string message)
    {
        m_NoticeKind = kind;
        m_NoticeMessage = message;
        m_LastError = "";
        m_NoticeUntil = 0;
        string title = "ERROR_TITLE";
        int accent = ARGB(255,242,90,90);
        int background = ARGB(250,27,24,24);
        if (kind == IOTNoticeKind.SUCCESS)
        {
            title = "SUCCESS_TITLE";
            accent = ARGB(255,103,218,132);
            background = ARGB(250,23,28,26);
            m_NoticeUntil = GetGame().GetTime()+4000;
        }
        else if (kind == IOTNoticeKind.WARNING)
        {
            title = "WARNING_TITLE";
            accent = ARGB(255,240,190,75);
            background = ARGB(250,29,27,23);
            m_NoticeUntil = GetGame().GetTime()+6000;
        }
        else m_LastError = message;
        m_ErrorRoot.SetColor(background);
        m_ErrorRoot.FindAnyWidget("ErrorAccent").SetColor(accent);
        TextWidget.Cast(m_ErrorRoot.FindAnyWidget("ErrorTitle")).SetText(IOTL.T(title));
        m_ErrorRoot.FindAnyWidget("ErrorTitle").SetColor(accent);
        m_ErrorText.SetText(message);
        m_ErrorRoot.Show(!m_PlayerMode && !m_GameMenuOpen);
        PositionError();
        m_ErrorRoot.Update();
    }

    void ReportError(string message)
    {
        Notify(IOTNoticeKind.ERROR,message);
        PrintToRPT("[PROXY ERROR] "+message);
    }

    protected void ReportSuccess(string message)
    {
        Notify(IOTNoticeKind.SUCCESS,message);
        PrintToRPT("[PROXY SUCCESS] "+message);
    }

    protected void ReportWarning(string message)
    {
        Notify(IOTNoticeKind.WARNING,message);
        PrintToRPT("[PROXY WARNING] "+message);
    }

    protected void ClearError()
    {
        m_LastError = "";
        if (m_NoticeKind == IOTNoticeKind.ERROR) DismissNotification();
    }

    protected void DismissNotification()
    {
        m_LastError = "";
        m_NoticeMessage = "";
        m_NoticeUntil = 0;
        if (m_ErrorRoot) m_ErrorRoot.Show(false);
    }

    protected void UpdateNotificationAt(int now)
    {
        if (m_NoticeUntil > 0 && now >= m_NoticeUntil) DismissNotification();
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
        ClearError();
        return true;
    }

    protected bool MoveSceneTarget(vector position)
    {
        if (!m_MoveTarget || !m_Editing || m_PlayerMode || EditorModalPending()) return false;
        for (int axis = 0; axis < 3; axis++)
            if (Math.AbsFloat(position[axis]) > 100000) { ReportError(IOTL.T("WORLD_NUMBER_LIMIT")); return false; }
        m_MoveTarget.SetPosition(position);
        return true;
    }

    bool SelectSceneCharacter()
    {
        if (EditorModalPending()) return false;
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
        if (EditorModalPending()) return false;
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
        if (EditorModalPending()) return false;
        if (m_PlayerMode || m_CreatedItems.Find(item) < 0) return false;
        IOTSceneEntry owner = ItemScene(item);
        bool changedAnchor = owner && owner.Anchor != m_Anchor;
        if (!SelectItem(item)) return false;
        if (changedAnchor) FocusAnchor();
        RefreshObjects();
        return true;
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
        if (m_PlayerMode || EditorModalPending()) return false;
        classname = m_Browser.ResolveClass(classname,itemMode);
        if (classname == "") { ReportError(IOTL.T("UNKNOWN_CLASS")); return false; }
        if (itemMode && !m_Anchor) { ReportError(IOTL.T("ANCHOR_REQUIRED")); return false; }
        if (!itemMode && ExistingSceneAnchor())
        {
            RequestAnchorReplacement(classname,atSurface,surfacePosition,surfaceNormal,m_Browser.MapForClass(classname));
            return false;
        }
        return SpawnResolvedSceneClass(classname,itemMode,atSurface,surfacePosition,surfaceNormal,false,m_Browser.MapForClass(classname));
    }

    protected void PlaceCharacterByAnchor(Object anchor, vector viewPosition)
    {
        Man player = GetGame().GetPlayer();
        if (!anchor || !player) return;
        vector bounds[2];
        anchor.ClippingInfo(bounds);
        vector center = (bounds[0]+bounds[1])*0.5;
        vector outward = anchor.WorldToModel(viewPosition) - center;
        outward[1] = 0;
        if (outward.Length() < 0.001) outward = "0 0 -1";
        outward.Normalize();
        float toX = 100000;
        float toZ = 100000;
        if (Math.AbsFloat(outward[0]) > 0.00001) toX = (bounds[1][0] - bounds[0][0])*0.5/Math.AbsFloat(outward[0]);
        if (Math.AbsFloat(outward[2]) > 0.00001) toZ = (bounds[1][2] - bounds[0][2])*0.5/Math.AbsFloat(outward[2]);
        vector normal = "0 0 1";
        if (toX < toZ)
        {
            normal = "1 0 0";
            if (outward[0] < 0) normal[0] = -1;
        }
        else if (outward[2] < 0) normal[2] = -1;
        // Intersect the center-to-camera ray with the model's horizontal bounds,
        // then step five metres out from that face, rather than from the pivot.
        vector localPosition = center+outward*Math.Min(toX,toZ)+normal*5;
        vector position = anchor.ModelToWorld(localPosition);
        position[1] = GetGame().SurfaceY(position[0],position[2])+0.1;
        vector facing = anchor.ModelToWorld(center) - position;
        facing[1] = 0;
        vector angles = facing.VectorToAngles();
        player.SetPosition(position);
        player.SetOrientation(Vector(angles[0],0,0));
    }

    // The only commit path: validate the candidate before clearing old entities.
    protected bool SpawnResolvedSceneClass(string classname, bool itemMode, bool atSurface, vector surfacePosition, vector surfaceNormal, bool replacing, int lootMap = 0)
    {
        bool dropping = atSurface;
        vector viewPosition = GetGame().GetCurrentCameraPosition();
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
            PushHistory(ItemHistoryEdit(item,IOTHistoryKind.ITEM_CREATE));
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
            m_LootMap = lootMap;
            PlaceCharacterByAnchor(created,viewPosition);
            SelectSceneAnchor(created);
        }
        RefreshObjects();
        ClearError();
        PrintToRPT("[PROXY SCENE] Created " + classname + " at " + created.GetPosition().ToString(false));
        return true;
    }

    bool AnchorReplacementPending() { return m_ReplaceClass != ""; }
    bool ProjectDialogOpen() { return m_ProjectRoot && m_ProjectRoot.IsVisible(); }
    bool EditorModalPending() { return AnchorReplacementPending() || ProjectDialogOpen() || UnsavedDialogOpen(); }

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

    protected void RequestAnchorReplacement(string classname, bool atSurface, vector position, vector normal, int lootMap = 0)
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
        m_ReplaceLootMap = lootMap;
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
        int lootMap = m_ReplaceLootMap;
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
        IOTPendingProjectAction action = new IOTPendingProjectAction;
        action.Kind = IOTProjectTransition.REPLACE_ANCHOR;
        action.Name = classname;
        action.ExpectedAnchor = expected;
        action.AtSurface = atSurface;
        action.Position = position;
        action.Normal = normal;
        action.LootMap = lootMap;
        return RequestProjectAction(action);
    }

    protected void ClearSceneLayout()
    {
        m_LootVolumes.Reset();
        m_LootMap = 0;
        ReleaseProjectItems();
        CancelWorldGesture();
        CancelCatalogDrag();
        DeselectItem();
        ClearHistory();
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
        if (EditorModalPending()) return false;
        if (!candidate)
        {
            DeselectItem();
            m_LootVolumes.Reset();
            m_LootMap = 0;
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
        if (m_Anchor != candidate) { m_LootVolumes.Reset(); m_LootMap = 0; }
        m_Anchor = candidate;
        m_ActiveScene = RegisterAnchor(candidate);
        if (m_Item) m_DirtyInputs = false;
        SyncFields();
        RefreshCreatedItems();
        return true;
    }

    bool SelectItem(ItemBase item)
    {
        if (m_PlayerMode || EditorModalPending() || !item || item.GetHierarchyParent() || item.IsHologram()) return false;
        if (m_MoveTarget) DeselectItem();
        m_CharacterFocused = false;
        IOTSceneEntry owner = ItemScene(item);
        if (owner && owner.Anchor != m_Anchor) SetAnchor(owner.Anchor);
        if (!m_Anchor) { ReportError(IOTL.T("ANCHOR_REQUIRED")); return false; }
        if (!owner && m_ActiveScene.Items.Find(item) < 0) m_ActiveScene.Items.Insert(item);
        if (item == m_Item && m_Editing) return true;
        FinishHistory();
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
        if (m_ProjectFrozen.Find(m_Item) >= 0)
        {
            m_WasSimulationDisabled = false;
            m_ProjectFrozen.RemoveItem(m_Item);
        }
        SetItemSimulation(m_Item,true);
        m_Editing = true;
        m_DirtyInputs = false;
        UpdateGizmo();
        SelectionControls(true);
        SyncFields();
        PrintToRPT("[PROXY SELECTION] Selected " + m_Item.GetType());
        RefreshCreatedItems(true);
        ClearError();
        return true;
    }

    protected void SelectionControls(bool enabled)
    {
        bool itemMode = enabled && m_Item != null;
        m_Root.FindAnyWidget("MoveStep").Enable(enabled);
        m_Root.FindAnyWidget("AngleStep").Enable(itemMode);
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

    protected void ToggleLootVolumes()
    {
        if (!m_Anchor || m_PlayerMode || EditorModalPending()) return;
        m_LootVolumes.Enable(!m_LootVolumes.Enabled());
        m_LootVolumes.Update(m_Anchor,m_LootMap,true);
        if (m_LootVolumes.Enabled())
        {
            if (!m_LootVolumes.Readable() || !m_LootVolumes.Known()) ReportWarning(m_LootVolumes.Detail());
            else if (m_LootVolumes.Count() == 0) ReportWarning(IOTL.T("LOOT_NO_POINTS"));
            else if (m_LootVolumes.UsingSnapshot()) ReportWarning(IOTL.T("LOOT_FALLBACK_WARNING"));
            else if (m_LootVolumes.IncompleteCount() > 0) ReportWarning(IOTL.T("LOOT_DIMENSIONS_UNSPECIFIED"));
        }
        UpdateToolbar();
    }

    protected void UpdateToolbar()
    {
        if (!m_Toolbar) return;
        m_ToolbarChrome.SetProjectDirty(HasUnsavedChanges());
        UpdateHistoryButtons();
        bool selected = SelectedObject() != null && m_Editing && !m_PlayerMode;
        m_Toolbar.FindAnyWidget("MoveMode").Show(selected);
        m_Toolbar.FindAnyWidget("RotateMode").Show(selected);
        m_Toolbar.FindAnyWidget("MoveMode").Enable(selected);
        m_Toolbar.FindAnyWidget("RotateMode").Enable(selected && m_Item != null);
        m_Toolbar.FindAnyWidget("PlaceOnSurface").Show(selected && m_Item != null);
        m_Toolbar.FindAnyWidget("DeleteItem").Show(selected && m_Item != null);
        m_Toolbar.FindAnyWidget("Export").Enable(selected && m_Item != null);
        m_Toolbar.FindAnyWidget("SceneFocus").Enable(m_Anchor != null);
        m_Toolbar.FindAnyWidget("SceneExport").Enable(m_Anchor != null);
        m_Toolbar.FindAnyWidget("LootVolumes").Enable(m_Anchor != null);
        bool showLoot = m_Anchor && m_LootVolumes.Enabled();
        m_ToolbarChrome.SetLootActive(showLoot);
        if (showLoot) m_ToolbarChrome.SetLootDetail(m_LootVolumes.Detail());
        else m_ToolbarChrome.SetLootDetail("");
        m_Toolbar.FindAnyWidget("MoveModeActive").Show(selected && !m_RotateMode);
        m_Toolbar.FindAnyWidget("RotateModeActive").Show(selected && m_RotateMode);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float margin = 20*m_PanelScale;
        float width = Math.Max(1,screenWidth - margin*2);
        float height = m_ToolbarChrome.Layout(width,m_PanelScale);
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
        float toggleY = 200;
        m_Root.FindAnyWidget("FineToggle").SetPos(16*m_PanelScale,toggleY*m_PanelScale);
        ButtonWidget.Cast(m_Root.FindAnyWidget("FineToggle")).SetState(m_FineOpen);
        string prefix = "+ ";
        if (m_FineOpen) prefix = "- ";
        ButtonText("FineToggle",prefix+IOTL.T("FINE_SETTINGS"));
        Widget finePanel = m_Root.FindAnyWidget("FinePanel");
        finePanel.Show(selected && m_FineOpen);
        float fineHeight = 64;
        if (showAngles) fineHeight = 132;
        finePanel.SetPos(16*m_PanelScale,(toggleY+36)*m_PanelScale);
        finePanel.SetScreenSize(368*m_PanelScale,fineHeight*m_PanelScale);
        float footerY = toggleY+40;
        if (m_FineOpen) footerY = footerY+fineHeight+10;
        if (!selected) footerY = 44;
        m_Debug.SetPos(16*m_PanelScale,footerY*m_PanelScale);
        m_Debug.Show(m_ShowDebug);
        float height = footerY+12;
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
        FinishHistory();
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
        ClearError();
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
        ClearError();
        PrintToRPT("[PROXY TOOL V2] Editor ready: camera active, no item selected; loose items=" + m_Items.Count().ToString());
        return true;
    }

    protected bool PanelPoint(vector point)
    {
        if (EditorModalPending()) return true;
        if (m_ToolbarChrome && m_ToolbarChrome.ContainsHint(point)) return true;
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
        m_Viewport.Update(m_Browser.Root(),m_Root,m_CreatedTray.Root(),m_Toolbar,!m_PlayerMode && !m_GameMenuOpen);
        PositionError();
        PositionReplacement();
        PositionProjectDialog();
        PositionUnsavedDialog();
    }

    protected bool WorldPoint(vector point)
    {
        return !m_PlayerMode && m_Viewport && m_Viewport.Contains(point) && !PanelPoint(point);
    }

    protected bool EditorWidget(Widget widget)
    {
        while (widget)
        {
            if (widget == m_Root || widget == m_Toolbar || widget == m_ErrorRoot || widget == m_ReplaceRoot || widget == m_ProjectRoot || widget == m_Browser.Root() || widget == m_CreatedTray.Root() || (m_ToolbarChrome && widget == m_ToolbarChrome.HintRoot())) return true;
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
        if (m_HistoryGroup == "gizmo") FinishHistory();
        m_ClickPending = false;
        m_ClickReleased = false;
        m_WorldDragCancelled = true;
        UpdateHistoryButtons();
    }

    protected bool BeginWorldGesture(vector point)
    {
        if (!WorldPoint(point)) { CancelWorldGesture(); return false; }
        m_ToolbarChrome.HideHint();
        m_ClickStart = point;
        m_ClickPending = true;
        m_ClickReleased = false;
        m_NativeGesture = false;
        m_WorldDragCancelled = false;
        return true;
    }

    protected bool BeginCatalogPress(vector point)
    {
        if (m_PlayerMode || EditorModalPending() || !m_Pointer || !m_Browser.CatalogListPoint(point)) return false;
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
        if (!valid) { ReportWarning(IOTL.T("ITEM_DROP_CANCELLED")); return false; }
        SetFocus(null);
        return SpawnSceneClass(classname,itemMode,true,hit,normal);
    }

    protected bool CameraContextActive()
    {
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        return m_Booted && !m_PlayerMode && !EditorModalPending() && m_Viewport && m_Viewport.IsVisible() && camera && camera.IsActive() && GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu();
    }

    protected bool BeginCameraHold(vector point, bool leftDown = false)
    {
        if (!CameraContextActive() || !m_Pointer || m_CameraHeld || m_CameraBlockedUntilRelease || leftDown || m_MouseWasDown || m_ClickPending || m_CatalogPressed || m_HeldButton || !WorldPoint(point)) return false;
        m_CameraHeld = true;
        SetPointer(false);
        return true;
    }

    protected void EndCameraHold()
    {
        if (!m_CameraHeld) return;
        m_CameraHeld = false;
        m_MouseWasDown = (GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK) != 0;
        SetPointer(true);
    }

    // Shared by mouse events and frame polling: consume each press once.
    // Once captured, hidden cursor coordinates do not limit camera flight.
    protected void UpdateCameraHold(bool down, bool contextActive, vector point, bool leftDown)
    {
        if (!contextActive)
        {
            EndCameraHold();
            m_CameraBlockedUntilRelease = true;
        }
        else if (!down)
        {
            EndCameraHold();
            m_CameraBlockedUntilRelease = false;
        }
        else if (!m_RightWasDown && !m_CameraBlockedUntilRelease) BeginCameraHold(point,leftDown);
        m_RightWasDown = down;
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
        if (button == MouseState.RIGHT)
        {
            int rightX,rightY;
            GetMousePos(rightX,rightY);
            UpdateCameraHold(true,CameraContextActive(),Vector(rightX,rightY,0),(GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK) != 0);
            return;
        }
        if (button != MouseState.LEFT || !m_Booted || m_PlayerMode || EditorModalPending() || !m_Pointer || m_ClickPending || m_CatalogPressed || !GetGame().IsAppActive() || GetGame().GetUIManager().GetMenu()) return;
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
        if (button == MouseState.RIGHT)
        {
            UpdateCameraHold(false,CameraContextActive(),vector.Zero,false);
            return;
        }
        if (button != MouseState.LEFT) return;
        if (m_HeldButton)
        {
            m_HeldButton = null;
            FinishHistory();
        }
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
        bool flying = m_CameraHeld && !m_Pointer && CameraContextActive();
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
        // Editor height controls do not depend on the Bulldozer bindings.
        float vertical = 0;
        if (KeyState(KeyCode.KC_Q)) vertical = vertical + 1;
        if (KeyState(KeyCode.KC_Z)) vertical = vertical - 1;
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
        bool menuOpen = GetGame().GetUIManager().GetMenu() != null;
        UpdateGameMenuVisibility(menuOpen);
        if (m_Browser) m_Browser.UpdateTheme();
        m_LootVolumes.Update(m_Anchor,m_LootMap,m_Booted && !m_PlayerMode && GetGame().IsAppActive() && !menuOpen);
        UpdateViewport();
        // MissionGameplay can update HUD visibility while menus open or close.
        if (m_Booted && !m_PlayerMode) SetPlayerHudHidden(true);
        int mouseX,mouseY;
        GetMousePos(mouseX,mouseY);
        bool down = (GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK) != 0;
        bool rightDown = (GetMouseState(MouseState.RIGHT) & MB_PRESSED_MASK) != 0;
        UpdateCameraHold(rightDown,CameraContextActive(),Vector(mouseX,mouseY,0),down);
        UpdateFlightCamera(timeslice);
        if (!m_Booted || m_PlayerMode || !GetGame().IsAppActive() || menuOpen)
        {
            m_ToolbarChrome.HideHint();
            CancelWorldGesture();
            CancelCatalogDrag();
            m_HeldButton = null;
            FinishHistory();
            m_MouseWasDown = down;
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
            if (m_HistoryGroup == "gizmo") FinishHistory();
            if (select) PickPoint(point);
        }
        UpdateHistoryButtons();
        if (!m_Pointer || EditorModalPending() || m_CatalogPressed) m_ToolbarChrome.HideHint();
        else m_ToolbarChrome.HoverAt(Vector(mouseX,mouseY,0),!m_MouseWasDown && !m_ClickPending);
    }

    protected void ShowEditorPanels(bool visible)
    {
        if (!visible) m_ToolbarChrome.HideHint();
        m_Root.Show(visible);
        m_Toolbar.Show(visible);
        m_Browser.Show(visible);
        m_CreatedTray.Show(visible);
    }

    protected void UpdateGameMenuVisibility(bool menuOpen)
    {
        if (!m_Booted || m_PlayerMode || m_GameMenuOpen == menuOpen) return;
        if (menuOpen)
        {
            m_ResumeProjectDialog = ProjectDialogOpen();
            m_ResumeUnsavedDialog = UnsavedDialogOpen();
        }
        m_GameMenuOpen = menuOpen;
        ShowEditorPanels(!menuOpen);
        m_ProjectRoot.Show(!menuOpen && m_ResumeProjectDialog);
        m_UnsavedRoot.Show(!menuOpen && m_ResumeUnsavedDialog);
        m_ReplaceRoot.Show(!menuOpen && AnchorReplacementPending());
        m_ErrorRoot.Show(!menuOpen && m_NoticeMessage != "");
        if (!menuOpen)
        {
            if (m_ResumeProjectDialog) SetFocus(m_ProjectName);
            else if (m_ResumeUnsavedDialog) SetFocus(m_UnsavedRoot.FindAnyWidget("UnsavedCancel"));
            m_ResumeProjectDialog = false;
            m_ResumeUnsavedDialog = false;
        }
        UpdateGizmo();
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
        m_CameraHeld = false;
        m_CameraBlockedUntilRelease = true;
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
        ShowEditorPanels(true);
        m_CreatedTray.Position(m_Browser.Root());
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
        m_LootVolumes.Update(m_Anchor,m_LootMap,false);
        EndCameraHold();
        m_CameraBlockedUntilRelease = true;
        DismissNotification();
        CancelCatalogDrag();
        DeselectItem();
        ReleaseProjectItems();
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
        ShowEditorPanels(false);
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
        if (pointer && m_CameraHeld)
        {
            m_CameraHeld = false;
            m_CameraBlockedUntilRelease = true;
        }
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        if (camera && !camera.IsActive()) camera.SetActive(true);
        if (pointer)
        {
            if (GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu()) GetGame().GetInput().ResetGameFocus();
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
        UpdateGizmo();
    }

    protected void UpdateGizmo()
    {
        GizmoApi api = GetGizmoApi();
        if (!api) return;
        api.DeselectTracker(this);
        if (!m_PlayerMode && !m_GameMenuOpen && m_Pointer && !EditorModalPending() && !m_CatalogPressed && m_GizmoEnabled && SelectedObject() && m_Editing)
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

    bool Gizmo_IsSupported() { return m_Pointer && !m_PlayerMode && !m_GameMenuOpen && !EditorModalPending() && m_Editing && SelectedObject() != null; }
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
        BeginHistory("gizmo");
        if (m_ClickPending) m_NativeGesture = true;
        if (m_MoveTarget)
        {
            // Scene objects support translation only: preserve the original
            // rotation and scale even if a caller supplies another basis.
            if (!MoveSceneTarget(transform[3])) { FinishHistory(); return false; }
        }
        else m_Item.SetTransform(transform);
        if (finalize) { m_DirtyInputs = false; SyncFields(); FinishHistory(); }
        else UpdateHistoryButtons();
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
        if (rotate && m_MoveTarget) return;
        string group = "nudge";
        if (m_HeldButton) group = group+":"+m_HeldButton.GetName();
        BeginHistory(group);
        if (m_MoveTarget)
        {
            if (rotate) return;
            vector worldPosition = m_MoveTarget.GetPosition();
            float worldFactor = direction;
            if (fine) worldFactor *= 0.1;
            worldPosition[axis] = worldPosition[axis]+MoveStep()*worldFactor;
            if (MoveSceneTarget(worldPosition)) { m_DirtyInputs = false; SyncFields(); }
            if (!m_HeldButton) FinishHistory();
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
        if (!m_HeldButton) FinishHistory();
    }

    protected bool NudgeButton(Widget widget, bool apply = true)
    {
        if (!widget) return false;
        string name = widget.GetName();
        for (int axis = 0; axis < 3; axis++)
        {
            string suffix = axis.ToString();
            if (name == "PosMinus" + suffix) { if (apply) Nudge(false, axis, -1); return true; }
            if (name == "PosPlus" + suffix) { if (apply) Nudge(false, axis, 1); return true; }
            if (name == "RotMinus" + suffix) { if (apply) Nudge(true, axis, -1); return true; }
            if (name == "RotPlus" + suffix) { if (apply) Nudge(true, axis, 1); return true; }
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
            BeginHistory("fields");
            if (!MoveSceneTarget(worldPosition)) { FinishHistory(); return false; }
            m_DirtyInputs = false;
            SyncFields();
            FinishHistory();
            ClearError();
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
        BeginHistory("fields");
        SetProxyPose(position, angles);
        FinishHistory();
        ClearError();
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
        BeginHistory("field:"+field.GetName());
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
        if (finished) { SyncFields(); FinishHistory(); }
        else SyncFields(field);
        UpdateHistoryButtons();
        ClearError();
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

    protected bool FindPlacementSurface(vector position, out vector hit, out vector normal)
    {
        // Start at the item's pivot with a small allowance for an intersecting floor.
        // A ray cast from above the model could instead land on the wreck or roof above it.
        vector from = position+"0 0.05 0";
        vector to = position-"0 100 0";
        Object surface;
        float fraction;
        bool found = DayZPhysics.RayCastBullet(from,to,PhxInteractionLayers.TERRAIN | PhxInteractionLayers.ROADWAY | PhxInteractionLayers.BUILDING,m_Item,surface,hit,normal,fraction);
        if (!found || normal.Length() < 0.1) return false;
        normal.Normalize();
        // An almost vertical face offers little support and would amplify the height offset.
        return normal[1] >= 0.5;
    }

    protected bool PlaceItemOnSurface()
    {
        if (!m_Item || !m_Editing || m_PlayerMode || m_CameraHeld || m_GameMenuOpen || EditorModalPending()) return false;
        vector pose[4];
        m_Item.GetTransform(pose);
        vector hit,normal;
        vector bounds[2];
        // Clipping bounds can include parts outside the contact geometry, such
        // as the hatchback wheel's oversized bounds along its axle.
        if (!m_Item.GetCollisionBox(bounds)) m_Item.ClippingInfo(bounds);
        vector size = bounds[1] - bounds[0];
        if (size.Length() < 0.001)
        {
            ReportWarning(IOTL.T("PLACEMENT_NO_BOUNDS"));
            return false;
        }
        if (!FindPlacementSurface(pose[3],hit,normal))
        {
            ReportWarning(IOTL.T("PLACEMENT_NO_SURFACE"));
            return false;
        }

        // Put the broad face down. Keep the same side facing up when possible,
        // and retain the in-plane direction by projecting a model axis.
        int flatAxis = 0;
        if (size[1] < size[flatAxis]) flatAxis = 1;
        if (size[2] < size[flatAxis]) flatAxis = 2;
        float side = 1;
        if (vector.Dot(pose[flatAxis],normal) < -0.0001) side = -1;
        int tangent = (flatAxis+1) % 3;
        int other = (flatAxis+2) % 3;
        vector basis[4];
        if (Math.AbsFloat(vector.Dot(pose[tangent],normal)) < 0.95)
        {
            vector direction = pose[tangent] - normal*vector.Dot(pose[tangent],normal);
            direction.Normalize();
            Math3D.DirectionAndUpMatrix(direction,normal*side,basis);
            pose[tangent] = basis[2];
            pose[other] = basis[0];
        }
        else
        {
            vector fallback = pose[other] - normal*vector.Dot(pose[other],normal);
            fallback.Normalize();
            Math3D.DirectionAndUpMatrix(fallback,normal*side,basis);
            pose[tangent] = -basis[0];
            pose[other] = basis[2];
        }
        pose[flatAxis] = basis[1];
        float support = Math.Min(bounds[0][flatAxis]*side,bounds[1][flatAxis]*side);
        // The hit and origin share X/Z. Convert clearance along the normal into Y.
        pose[3][1] = hit[1]+(0.003 - support)/normal[1];

        BeginHistory("surface-placement");
        m_Item.SetTransform(pose);
        m_DirtyInputs = false;
        SyncFields();
        FinishHistory();
        ClearError();
        return true;
    }

    void Reset()
    {
        BeginHistory("reset");
        if (m_MoveTarget) { if (!MoveSceneTarget(m_Original[3])) { FinishHistory(); return; } }
        else if (m_Item) m_Item.SetTransform(m_Original);
        else return;
        m_DirtyInputs = false;
        SyncFields();
        FinishHistory();
        ClearError();
    }

    protected void ResetComponent(bool rotate, int axis)
    {
        if (!SelectedObject() || !m_Editing || m_PlayerMode || (rotate && !m_Item)) return;
        BeginHistory("reset");
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
        FinishHistory();
        ClearError();
    }

    string ProxyLine()
    {
        return ItemProxyLine(m_Item);
    }

    string ItemProxyLine(ItemBase item)
    {
        return "<proxy type=\"" + item.GetType() + "\" pos=\"" + Numbers(ItemProxyPosition(item)) + "\" rpy=\"" + Numbers(ItemProxyAngles(item)) + "\" />";
    }

    bool ExportAnchor(bool showNotification = true)
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
        if (showNotification) ReportSuccess(IOTL.F("ANCHOR_XML_SAVED",count.ToString()));
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
        bool exported = ExportAnchor(false);
        if (exported) ReportSuccess(IOTL.F("ITEM_XML_SAVED",m_Item.GetType()));
        return exported;
    }

    override bool OnMouseButtonDown(Widget w, int x, int y, int button)
    {
        if (EditorModalPending()) return false;
        Widget widget = w;
        if (button == 0 && NudgeButton(widget,false))
        {
            FinishHistory();
            m_HeldButton = widget;
            m_SuppressClick = widget;
            m_HoldStart = GetGame().GetTime();
            m_LastRepeat = m_HoldStart;
            NudgeButton(widget);
            return true;
        }
        return false;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button)
    {
        MouseRelease(button);
        return false;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
    {
        Widget widget = w;
        if (widget == m_HeldButton) { m_HeldButton = null; FinishHistory(); }
        return false;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (UnsavedDialogOpen())
        {
            if (w.GetName() == "UnsavedCancel") CancelPendingProjectAction();
            else if (w.GetName() == "UnsavedSave") UnsavedChoice(true);
            else if (w.GetName() == "UnsavedDiscard") UnsavedChoice(false);
            return true;
        }
        if (ProjectDialogOpen())
        {
            if (w.GetName() == "ProjectCancel") CloseProjectDialog();
            else if (w.GetName() == "ProjectAction") ProjectAction();
            return true;
        }
        if (EditorModalPending())
        {
            if (w.GetName() == "ReplaceCancel") FinishAnchorReplacement(false);
            else if (w.GetName() == "ReplaceConfirm") FinishAnchorReplacement(true);
            return true;
        }
        Widget widget = w;
        if (widget == m_SuppressClick) { m_SuppressClick = null; return true; }
        if (NudgeButton(widget)) return true;
        string name = widget.GetName();
        if (name == "CameraHelp") { m_ToolbarChrome.ToggleCameraHelp(); return true; }
        m_ToolbarChrome.HideHint();
        if (name == "ProjectSave") { ShowProjectDialog(true); return true; }
        if (name == "ProjectOpen") { ShowProjectDialog(false); return true; }
        if (name == "LootVolumes") { ToggleLootVolumes(); return true; }
        if (name == "Undo") { StepHistory(false); return true; }
        if (name == "Redo") { StepHistory(true); return true; }
        if (name == "DeleteItem") { DeleteSelectedItem(); return true; }
        if (name == "ErrorClose") { DismissNotification(); return true; }
        if (name == "FineToggle") { ToggleFineSettings(); return true; }
        if (name == "PlayerMode") { EnterPlayer(); return true; }
        if (name == "SceneFocus") { FocusAnchor(); return true; }
        if (name == "SceneExport") { ExportAnchor(); return true; }
        if (name == "MoveMode") { if (SelectedObject()) { FinishHistory(); m_RotateMode = false; UpdateGizmo(); } return true; }
        if (name == "RotateMode") { if (m_Item) { FinishHistory(); m_RotateMode = true; UpdateGizmo(); } return true; }
        if (name == "PlaceOnSurface") { PlaceItemOnSurface(); return true; }
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
        if (ProjectDialogOpen())
        {
            if (w == m_ProjectList)
            {
                int row = m_ProjectList.GetSelectedRow();
                if (row >= 0 && row < m_ProjectNames.Count()) m_ProjectName.SetText(m_ProjectNames[row]);
            }
            ResetProjectConfirm();
            return true;
        }
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
        if (m_UpdatingUI || EditorModalPending() || !SelectedObject()) return false;
        for (int axis = 0; axis < 3; axis++)
        {
            if (w != m_PosFields[axis] && w != m_RotFields[axis]) continue;
            bool rotate = w == m_RotFields[axis];
            if (!ApplyEditedField(EditBoxWidget.Cast(w),rotate,axis,true))
            {
                m_DirtyInputs = false;
                SyncFields();
                FinishHistory();
            }
            return true;
        }
        return false;
    }

    void HandleKey(int key)
    {
        if (UnsavedDialogOpen())
        {
            if (key == KeyCode.KC_ESCAPE) CancelPendingProjectAction();
            return;
        }
        if (ProjectDialogOpen())
        {
            if (key == KeyCode.KC_ESCAPE) CloseProjectDialog();
            return;
        }
        if (HandleHistoryKey(key)) return;
        if (!m_PlayerMode && key == KeyCode.KC_F1) return;
        if (EditorModalPending())
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
        if (key == KeyCode.KC_DELETE) { DeleteSelectedItem(); return; }
        if (key == KeyCode.KC_F7)
        {
            FinishHistory();
            m_RotateMode = false;
            UpdateGizmo();
            ClearError();
            return;
        }
        if (key == KeyCode.KC_F8)
        {
            if (m_Item)
            {
                FinishHistory();
                m_RotateMode = true;
                UpdateGizmo();
                ClearError();
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
        if (!GetGame().IsAppActive() || m_GameMenuOpen || GetGame().GetUIManager().GetMenu())
        {
            // DayZ may open its pause menu if a batch launch starts in the background.
            if (!m_SelfTestStartupDeadline) m_SelfTestStartupDeadline = GetGame().GetTime()+45000;
            if (GetGame().GetTime() >= m_SelfTestStartupDeadline)
            {
                TestCheck(false,"editor did not become active and unpaused for startup checks");
                return;
            }
            Mission mission = GetGame().GetMission();
            if (GetGame().IsAppActive() && mission && mission.IsPaused()) mission.Continue();
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestStart,250,false);
            return;
        }
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
        if (!TestCheck(m_Toolbar.IsVisible() && !m_Toolbar.FindAnyWidget("MoveMode").IsVisible() && !m_Toolbar.FindAnyWidget("RotateMode").IsVisible() && !m_Toolbar.FindAnyWidget("PlaceOnSurface").IsVisible() && !Export() && !ExportAnchor(), "toolbar hides manipulation modes without selection and rejects export without an anchor")) return;
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
        if (!SelfTestSpecificCategories()) return;
        if (!SelfTestBuildingFamilies()) return;
        if (!SelfTestItemTree()) return;
        if (!SelfTestItemMaps()) return;
        if (!SelfTestItemVisibility()) return;
        if (!SelfTestWeaponGroups()) return;
        if (!SelfTestClothingGroups()) return;
        if (!SelfTestCampingGroups()) return;
        if (!SelfTestAdditionalGroups()) return;
        string catalogOnly;
        if (GetGame().CommandlineGetParam("proxyToolCatalogOnly",catalogOnly))
        {
            if (!TestCheck(m_Browser.WriteItemCatalogAudit("$profile:catalog-audit.csv"),"catalog audit exports actual visible group membership for subdivision analysis")) return;
            if (!SpawnSceneClass("Land_Wreck_hb01_aban1_blue",false) || !SpawnSceneClass("HatchbackWheel",true)) { TestCheck(false,"catalog review scene created"); return; }
            if (!SelfTestAnchorHoverPreview()) return;
            m_Browser.SetMode(false);
            m_Browser.Search("Land_Garage_Row_Small");
            m_SelfTest = false;
            PrintToRPT("[PROXY TOOL V2 SELFTEST] PASS: catalog map membership, complete coverage, nested search and selection.");
            PrintToRPT("[PROXY TOOL V2 SELFTEST] REVIEW_READY: client retained for author review.");
            return;
        }
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
        if (!TestCheck(created && m_Scenes.Count() == 1 && m_Anchor && !EditorModalPending(), "first anchor drop creates one anchor without a replacement dialog")) return;
        vector actual = m_Anchor.GetPosition();
        PrintToRPT("[PROXY ANCHOR DROP] hit="+hit.ToString(false)+" actual="+actual.ToString(false)+" orientation="+m_Anchor.GetOrientation().ToString(false)+" scale="+m_Anchor.GetScale().ToString());
        if (!TestCheck(Math.AbsFloat(actual[0]-hit[0]) < 0.05 && Math.AbsFloat(actual[2]-hit[2]) < 0.05 && m_Anchor.GetOrientation().Length() < 0.001 && m_Anchor.GetScale() == 1, "anchor drop preserves horizontal hit coordinates and the CE transform constraints")) return;
        if (!TestCheck(CharacterReadyAtAnchor(m_Anchor), "first anchor creation positions the character on the ground five metres away facing the model")) return;
        if (!SelfTestCharacterStart()) return;
        vector playerPosition = GetGame().GetPlayer().GetPosition();
        vector playerOrientation = GetGame().GetPlayer().GetOrientation();
        if (!TestCheck(SpawnSceneClass("HatchbackWheel",true), "runtime creation of wreck and wheel")) return;
        if (!TestCheck(vector.Distance(GetGame().GetPlayer().GetPosition(),playerPosition) < 0.001 && vector.Distance(GetGame().GetPlayer().GetOrientation(),playerOrientation) < 0.001, "creating an item preserves the character placement and facing")) return;
        DeselectItem();
        RefreshObjects();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTest,1000,false);
    }

    protected bool CharacterReadyAtAnchor(Object anchor)
    {
        Man player = GetGame().GetPlayer();
        vector bounds[2];
        anchor.ClippingInfo(bounds);
        vector position = player.GetPosition();
        vector modelPosition = anchor.WorldToModel(position);
        float dx = Math.Max(Math.Max(bounds[0][0] - modelPosition[0],modelPosition[0] - bounds[1][0]),0);
        float dz = Math.Max(Math.Max(bounds[0][2] - modelPosition[2],modelPosition[2] - bounds[1][2]),0);
        vector facing = anchor.ModelToWorld((bounds[0]+bounds[1])*0.5) - position;
        facing[1] = 0;
        facing.Normalize();
        return Math.AbsFloat(Math.Sqrt(dx*dx+dz*dz) - 5) < 0.01 && Math.AbsFloat(position[1] - GetGame().SurfaceY(position[0],position[2]) - 0.1) < 0.01 && vector.Dot(player.GetDirection(),facing) > 0.999;
    }

    protected bool SelfTestCharacterStart()
    {
        Man player = GetGame().GetPlayer();
        vector original[4];
        player.GetTransform(original);
        vector cameraPosition = FreeDebugCamera.GetInstance().GetPosition();
        Object boots = player.FindAttachmentBySlotName("Feet");
        vector bounds[2];
        m_Anchor.ClippingInfo(bounds);
        vector center = m_Anchor.ModelToWorld((bounds[0]+bounds[1])*0.5);
        array<vector> views = {"50 10 0","-50 10 0","0 10 50","0 10 -50","50 10 50","0 50 0"};
        bool placement = true;
        foreach (vector view : views)
        {
            PlaceCharacterByAnchor(m_Anchor,center+view);
            if (!CharacterReadyAtAnchor(m_Anchor)) placement = false;
            if (view[0] != 0 && (player.GetPosition()[0] - center[0])*view[0] <= 0) placement = false;
            if (view[2] != 0 && (player.GetPosition()[2] - center[2])*view[2] <= 0) placement = false;
        }
        player.SetTransform(original);
        if (!TestCheck(placement, "character placement works from every camera side and directly overhead outside the model bounds")) return false;
        if (!TestCheck(player == GetGame().GetPlayer() && boots == player.FindAttachmentBySlotName("Feet") && vector.Distance(FreeDebugCamera.GetInstance().GetPosition(),cameraPosition) < 0.001 && m_CreatedItems.Count() == 0 && m_Scenes.Count() == 1, "character placement preserves the existing survivor equipment camera and scene entities")) return false;
        return true;
    }

    protected bool SelfTestBackdrop(bool visible)
    {
        array<string> names = {"MatteTop","MatteBottom","MatteLeft","MatteRight"};
        for (int i = 0; i < names.Count(); i++)
        {
            Widget image = m_Viewport.BackdropPart(i);
            if (!image || image.IsVisible() != visible) return false;
            if (!visible) continue;
            Widget matte = m_Viewport.MatteRoot().FindAnyWidget(names[i]);
            float ix,iy,iw,ih,x,y,w,h;
            image.GetScreenPos(ix,iy);
            image.GetScreenSize(iw,ih);
            matte.GetScreenPos(x,y);
            matte.GetScreenSize(w,h);
            if (Math.AbsFloat(ix-x) > 1 || Math.AbsFloat(iy-y) > 1 || Math.AbsFloat(iw-w) > 1 || Math.AbsFloat(ih-h) > 1) return false;
            if (!(image.GetFlags() & WidgetFlags.IGNOREPOINTER) || image.GetSort() <= m_Viewport.MatteRoot().GetSort() || image.GetSort() >= m_Root.GetSort() || image.GetSort() >= m_ToolbarChrome.HintRoot().GetSort()) return false;
        }
        return true;
    }

    protected bool SelfTestViewportLayout()
    {
        UpdateViewport();
        vector origin = m_Viewport.Origin();
        vector size = m_Viewport.Size();
        vector center = m_Viewport.Center();
        if (!TestCheck(m_Viewport.IsVisible() && size[0] > 64 && size[1] > 64 && WorldPoint(center), "world viewport has a visible usable center")) return false;
        if (!TestCheck(SelfTestBackdrop(true), "landscape loads above the matte and covers only the frame margins")) return false;
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
        bool backdropFollowsLayout = SelfTestBackdrop(true);
        m_Browser.Root().SetScreenPos(leftX,leftY);
        m_CreatedTray.Root().SetScreenPos(trayX,trayY);
        UpdateViewport();
        if (!TestCheck(followsLayout, "world viewport follows live panel and tray geometry")) return false;
        if (!TestCheck(backdropFollowsLayout && SelfTestBackdrop(true), "landscape stays aligned when the opening is resized")) return false;
        m_CreatedTray.Root().SetScreenPos(trayX+24,trayY);
        UpdateViewport();
        vector sceneOrigin = m_Viewport.Origin();
        bool followsScene = Math.AbsFloat(sceneOrigin[0] - origin[0] - 24) < 1;
        m_CreatedTray.Root().SetScreenPos(trayX,trayY);
        UpdateViewport();
        if (!TestCheck(followsScene, "world viewport includes the live width of the left scene list")) return false;
        m_Browser.Root().SetScreenPos(rightX+100,leftY);
        UpdateViewport();
        bool overlapBlocked = !m_Viewport.IsVisible() && !WorldPoint(center) && SelfTestBackdrop(false);
        m_Browser.Root().SetScreenPos(leftX,leftY);
        UpdateViewport();
        if (!TestCheck(overlapBlocked && WorldPoint(center) && SelfTestBackdrop(true), "overlapping panels disable world input and recover after layout restore")) return false;
        UpdateCameraHold(false,true,center,false);
        if (!TestCheck(!BeginCameraHold(leftPanel) && m_Pointer, "RMB over editor panels does not enter flight")) return false;
        if (!TestCheck(BeginCameraHold(center) && !m_Pointer, "RMB inside world viewport enters flight")) return false;
        UpdateCameraHold(false,true,leftPanel,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld, "RMB release outside world returns to cursor mode")) return false;
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
            string leafKey = categoryKey+"/GARAGES/Land_Garage_Row_Small";
            if (!TestCheck(m_Browser.BranchCount(i) > 100 && m_Browser.RowIndex(mapKey) >= 0, "map branch is populated: "+mapName)) return false;
            PrintToRPT("[PROXY TREE TEST] "+mapName+"="+m_Browser.BranchCount(i).ToString());
            m_Browser.ActivateRow(mapKey);
            if (!TestCheck(m_Browser.RowIndex(categoryKey) >= 0 && m_Browser.FirstClass() == "", "map expands to categories without choosing a spawn class: "+mapName)) return false;
            m_Browser.ActivateRow(categoryKey);
            m_Browser.ActivateRow(categoryKey+"/GARAGES");
            if (!TestCheck(m_Browser.RowIndex(leafKey) >= 0, "category expands to shared garage: "+mapName)) return false;
            m_Browser.ActivateRow(leafKey);
            if (!TestCheck(m_Browser.FirstClass() == "Land_Garage_Row_Small", "tree leaf selects the exact spawn classname: "+mapName)) return false;
            m_Browser.ActivateRow(categoryKey);
            if (!TestCheck(m_Browser.RowIndex(leafKey) < 0 && m_Browser.FirstClass() == "", "collapsing a category hides its objects and clears spawn selection: "+mapName)) return false;
        }
        m_Browser.Search("  LAND_GARAGE_ROW_SMALL  ");
        if (!TestCheck(m_Browser.MatchCount() == 1 && m_Browser.ShownCount() == 1 && m_Browser.RowCount() == 17 && m_Browser.FirstClass() == "Land_Garage_Row_Small", "global tree search reveals shared objects under all four maps")) return false;
        m_Browser.ActivateRow("map:2");
        if (!TestCheck(m_Browser.RowIndex("map:2/INDUSTRIAL/GARAGES/Land_Garage_Row_Small") < 0 && m_Browser.RowIndex("map:1/INDUSTRIAL/GARAGES/Land_Garage_Row_Small") >= 0, "search results can be collapsed independently")) return false;
        m_Browser.Search("Land_Underground_Storage_Prison");
        if (!TestCheck(m_Browser.MatchCount() == 1 && m_Browser.RowIndex("map:2/UNDERGROUND/Land_Underground_Storage_Prison") >= 0 && m_Browser.RowIndex("map:1") < 0, "map-specific search prunes unrelated branches")) return false;
        m_Browser.Search("no_such_proxy_tool_class");
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.FirstClass() == "" && m_Browser.RowCount() == 1, "empty tree search clears the previous spawn class")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow("map:1/INDUSTRIAL");
        m_Browser.SetMode(true);
        if (!TestCheck(m_Browser.RowIndex("objects") < 0 && m_Browser.RowIndex("items/common") >= 0 && m_Browser.MatchCount() == m_Browser.CatalogCount(true) && m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "", "item tab opens an independent category tree")) return false;
        m_Browser.Search("  canistergasoline  ");
        if (!TestCheck(m_Browser.MatchCount() == 1 && m_Browser.FirstClass() == "CanisterGasoline", "item search still resolves inventory classes")) return false;
        m_Browser.SetMode(false);
        if (!TestCheck(m_Browser.RowIndex("map:1/INDUSTRIAL/GARAGES/Land_Garage_Row_Small") >= 0, "return to objects preserves expanded maps and categories")) return false;
        m_Browser.ActivateRow("objects");
        if (!TestCheck(m_Browser.RowCount() == 1 && m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "", "object root collapses without selecting a spawn class")) return false;
        m_Browser.ActivateRow("objects");
        if (!TestCheck(m_Browser.RowIndex("map:1/INDUSTRIAL/GARAGES/Land_Garage_Row_Small") >= 0, "object root restores previously open branches")) return false;
        m_Browser.ActivateRow("map:1/INDUSTRIAL/GARAGES/Land_Garage_Row_Small");
        if (!TestCheck(SelfTestCatalogWheel(), "Objects wheel scrolls two rows per step without changing selection")) return false;
        m_Browser.SelectCatalogItemRow(m_Browser.RowIndex("map:1/INDUSTRIAL"));
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

    protected bool SelfTestSpecificCategories()
    {
        int baseline = m_Browser.MatchCount();
        array<int> mapCounts = new array<int>;
        for (int mapIndex = 1; mapIndex <= 5; mapIndex++) mapCounts.Insert(m_Browser.BranchCount(mapIndex));
        if (!TestCheck(IOTCatalogAsset.SpecificSubcategory("\\DZ\\Structures\\Specific\\Castles\\castle_donjon.p3d") == "CASTLES" && IOTCatalogAsset.SpecificSubcategory("dz/structures/specific/churches/chapel.p3d") == "CHURCHES", "specific groups normalize model paths for castles and churches")) return false;
        if (!TestCheck(IOTCatalogAsset.SpecificSubcategory("dz/structures_bliss/specific/cultural/church4_red.p3d") == "CHURCHES" && IOTCatalogAsset.SpecificSubcategory("dz/structures_bliss/specific/cultural/statue_enoch1.p3d") == "MONUMENTS" && IOTCatalogAsset.SpecificSubcategory("dz/structures_bliss/specific/cultural/misc_calvary1.p3d") == "CEMETERIES", "Livonia cultural models separate churches monuments and crosses")) return false;
        if (!TestCheck(IOTCatalogAsset.SpecificSubcategory("dz/structures_sakhal/specific/airport/airport_small_main.p3d") == "AIRFIELDS" && IOTCatalogAsset.SpecificSubcategory("dz/structures_sakhal/specific/volcano/mobilelaboratory.p3d") == "RESEARCH", "Sakhal specific groups include airports and research laboratories")) return false;
        if (!TestCheck(IOTCatalogAsset.SpecificSubcategory("dz/structures_takistan/specific/mosques/mosque_big_main.p3d") == "MOSQUES" && IOTCatalogAsset.SpecificSubcategory("dz/structures_takistan/specific/minarets/minaret1.p3d") == "MOSQUES" && IOTCatalogAsset.SpecificSubcategory("dz/structures_takistan/specific/mausolea/mausoleum_small1.p3d") == "CEMETERIES", "Nasdara specific groups separate religious buildings and burial sites")) return false;
        if (!TestCheck(IOTCatalogAsset.SpecificSubcategory("dz/structures/specific/skilift/skilift_tower_start.p3d") == "CABLEWAYS" && IOTCatalogAsset.SpecificSubcategory("dz/structures/specific/cableway/cableway_base.p3d") == "CABLEWAYS", "cableways and ski lifts share one specific group")) return false;
        if (!TestCheck(IOTCatalogAsset.SpecificSubcategory("dz/structures/specific/custom/new_building.p3d") == "OTHER" && IOTCatalogAsset.SpecificSubcategory("dz/structures_bliss/specific/cultural/new_asset.p3d") == "OTHER" && IOTCatalogAsset.SpecificSubcategory("dz/structures/industrial/castles/test.p3d") == "OTHER", "unknown specific models stay accessible without reclassifying other categories")) return false;
        array<string> examples = {"Land_Castle_Bergfrit2","Land_Chapel","Land_Church4_Red","Land_Airport_Small_Main","Land_Mosque_Big_Main","Land_FuelStation_Build","Land_MobileLaboratory","Land_Bazaar_Left","Land_TajbegPalace_Middle"};
        array<string> subgroups = {"CASTLES","CHURCHES","CHURCHES","AIRFIELDS","MOSQUES","FUELSTATIONS","RESEARCH","MARKETS","CASTLES"};
        array<int> maps = {1,1,2,3,4,1,3,4,4};
        for (int i = 0; i < examples.Count(); i++)
        {
            m_Browser.Search("  "+examples[i]+"  ");
            string parent = IOTSceneBrowser.MapKey(maps[i])+"/SPECIFIC/"+subgroups[i];
            if (!TestCheck(m_Browser.RowIndex(parent) >= 0 && m_Browser.ActivateRow(parent+"/"+examples[i]) && m_Browser.FirstClass() == examples[i], "specific subgroup search selects the exact object: "+examples[i])) return false;
        }
        m_Browser.Search("Land_Castle_Bergfrit2");
        if (!TestCheck(m_Browser.MatchCount() == 1 && m_Browser.ShownCount() == 1 && m_Browser.RowIndex("map:1/SPECIFIC/CASTLES/Land_Castle_Bergfrit2") >= 0 && m_Browser.RowIndex("map:2/SPECIFIC/CASTLES/Land_Castle_Bergfrit2") >= 0 && m_Browser.RowIndex("map:1/SPECIFIC/CHURCHES") < 0, "specific subgroup search preserves shared map membership and hides empty siblings")) return false;
        m_Browser.ActivateRow("map:1/SPECIFIC/CASTLES");
        if (!TestCheck(m_Browser.RowIndex("map:1/SPECIFIC/CASTLES/Land_Castle_Bergfrit2") < 0 && m_Browser.RowIndex("map:2/SPECIFIC/CASTLES/Land_Castle_Bergfrit2") >= 0 && m_Browser.FirstClass() == "", "specific subgroups collapse independently without becoming spawn classes")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow("map:1/SPECIFIC");
        m_Browser.ActivateRow("map:1/SPECIFIC/CASTLES");
        m_Browser.SetMode(true);
        m_Browser.SetMode(false);
        if (!TestCheck(m_Browser.RowIndex("map:1/SPECIFIC/CASTLES/Land_Castle_Bergfrit2") >= 0 && m_Browser.FirstClass() == "", "specific subgroup expansion survives catalog tab switching")) return false;
        for (int branch = 1; branch <= 5; branch++)
        {
            if (!TestCheck(m_Browser.BranchCount(branch) == mapCounts[branch - 1], "specific subgrouping preserves object counts in map branch "+branch.ToString())) return false;
        }
        if (!TestCheck(m_Browser.CatalogCovered() && m_Browser.MatchCount() == baseline && !m_Browser.ShowStaticObjects(), "specific subgrouping preserves every object and the StaticObj default")) return false;
        return true;
    }

    protected bool SelfTestBuildingFamilies()
    {
        int baseline = m_Browser.MatchCount();
        array<int> mapCounts = new array<int>;
        for (int mapIndex = 1; mapIndex <= 5; mapIndex++) mapCounts.Insert(m_Browser.BranchCount(mapIndex));
        if (!TestCheck(IOTCatalogAsset.IndustrialSubcategory("\\DZ\\Structures\\Industrial\\Containers\\container_1aoh.p3d") == "CONTAINERS" && IOTCatalogAsset.IndustrialSubcategory("dz/structures/industrial/cementworks/cementworks_millb.p3d") == "CEMENTWORKS", "industrial groups normalize container and cement works model paths")) return false;
        if (!TestCheck(IOTCatalogAsset.IndustrialSubcategory("dz/structures/industrial/farms/barn_brick1.p3d") == "BARNS" && IOTCatalogAsset.IndustrialSubcategory("dz/structures/industrial/farms/farm_cowsheda.p3d") == "FARMS", "industrial farm models separate barns from other farm buildings")) return false;
        if (!TestCheck(IOTCatalogAsset.IndustrialSubcategory("dz/structures_sakhal/industrial/powerplant/powerplant_building.p3d") == "POWER" && IOTCatalogAsset.IndustrialSubcategory("dz/structures_takistan/industrial/oilrefinery/distillationtower.p3d") == "OIL" && IOTCatalogAsset.IndustrialSubcategory("dz/structures_takistan/industrial/irrigation/irrigationtunnel.p3d") == "IRRIGATION", "industrial grouping covers Sakhal power facilities and Nasdara oil and irrigation")) return false;
        if (!TestCheck(IOTCatalogAsset.ResidentialFamily("dz/structures/residential/houses/house_1w05_yellow.p3d") == "HOUSE_1W" && IOTCatalogAsset.ResidentialFamily("dz/structures_sakhal/residential/houses/house_1w14_dam_snow.p3d") == "HOUSE_1W" && IOTCatalogAsset.ResidentialFamily("dz/structures_takistan/residential/houses/house_2c2_dam3.p3d") == "HOUSE_2C", "house families preserve their series across color damage and snow variants")) return false;
        if (!TestCheck(IOTCatalogAsset.ResidentialFamily("dz/structures/residential/houseblocks/houseblock_2f_corner.p3d") == "BLOCK_2F" && IOTCatalogAsset.ResidentialFamily("dz/structures/residential/medical/city_hospital_ghost1.p3d") == "HOSPITALS" && IOTCatalogAsset.ResidentialFamily("dz/structures/residential/stores/city_stand_news1.p3d") == "KIOSKS", "city families distinguish block series hospitals and kiosks")) return false;
        if (!TestCheck(IOTCatalogAsset.IndustrialSubcategory("dz/structures/industrial/newfamily/building.p3d") == "OTHER" && IOTCatalogAsset.ResidentialFamily("dz/structures/residential/houses/newhouse.p3d") == "OTHER" && IOTCatalogAsset.ResidentialFamily("dz/structures/residential/houseblocks/newblock.p3d") == "OTHER" && IOTCatalogAsset.ResidentialFamily("") == "", "unknown building families keep explicit fallbacks without changing other residential categories")) return false;
        array<string> examples = {"Land_Container_1Aoh","Land_Barn_Brick1","Land_CementWorks_ExpeditionA","Land_Garage_Row_Small","Land_Workshop1","Land_CementWorks_ExpeditionB","Land_KirovDam_House_A","Land_Garage_Tall","Land_House_1W05_Yellow","Land_House_2B01","Land_House_1W13_Dam","Land_House_1W14_Dam_Snow","Land_House_2C2_Dam3","Land_House_1B01_Pub","Land_HouseBlock_1F1","Land_HouseBlock_2F_Corner","Land_HouseBlock_2C1_Dam1","Land_City_Hospital_East","Land_City_Store","Land_City_Stand_FastFood"};
        array<string> groups = {"INDUSTRIAL/CONTAINERS","INDUSTRIAL/BARNS","INDUSTRIAL/CEMENTWORKS","INDUSTRIAL/GARAGES","INDUSTRIAL/WORKSHOPS","INDUSTRIAL/CEMENTWORKS","INDUSTRIAL/DAMS","INDUSTRIAL/GARAGES","RESIDENTIAL/HOUSE/HOUSE_1W","RESIDENTIAL/HOUSE/HOUSE_2B","RESIDENTIAL/HOUSE/HOUSE_1W","RESIDENTIAL/HOUSE/HOUSE_1W","RESIDENTIAL/HOUSE/HOUSE_2C","RESIDENTIAL/HOUSE/PUBS","RESIDENTIAL/CITY/BLOCK_1F","RESIDENTIAL/CITY/BLOCK_2F","RESIDENTIAL/CITY/BLOCK_2C","RESIDENTIAL/CITY/HOSPITALS","RESIDENTIAL/CITY/STORES","RESIDENTIAL/CITY/KIOSKS"};
        array<int> maps = {1,1,1,1,1,4,4,3,1,1,2,3,4,1,1,1,4,3,1,1};
        foreach (string fixture : examples)
        {
            string fixtureClass = m_Browser.ResolveClass(fixture,false);
            string fixtureModel;
            GetGame().ConfigGetText("CfgVehicles "+fixture+" model",fixtureModel);
            PrintToRPT("[PROXY BUILDING GROUP] requested="+fixture+" resolved="+fixtureClass+" model="+fixtureModel+" industrial="+IOTCatalogAsset.IndustrialSubcategory(fixtureModel)+" residential="+IOTCatalogAsset.ResidentialFamily(fixtureModel));
        }
        for (int i = 0; i < examples.Count(); i++)
        {
            string classname = m_Browser.ResolveClass(examples[i],false);
            m_Browser.Search(examples[i]);
            string parent = IOTSceneBrowser.MapKey(maps[i])+"/"+groups[i];
            if (!TestCheck(classname != "" && m_Browser.RowIndex(parent) >= 0 && m_Browser.ActivateRow(parent+"/"+classname) && m_Browser.FirstClass() == classname, "building family search selects the exact object: "+examples[i])) return false;
        }
        m_Browser.Search("Land_Container_1Mo_Desert");
        if (!TestCheck(m_Browser.RowIndex("map:4/MILITARY/Land_Container_1Mo_Desert") >= 0 && m_Browser.RowIndex("map:4/INDUSTRIAL") < 0, "industrial grouping preserves military container category membership")) return false;
        m_Browser.Search("  LAND_HOUSE_1W05  ");
        if (!TestCheck(m_Browser.MatchCount() == 2 && m_Browser.ShownCount() == 2 && m_Browser.RowIndex("map:1/RESIDENTIAL/HOUSE/HOUSE_1W/Land_House_1W05_Yellow") >= 0 && m_Browser.RowIndex("map:1/RESIDENTIAL/HOUSE/HOUSE_2B") < 0, "house family search keeps separate color variants and hides empty siblings")) return false;
        m_Browser.ActivateRow("map:1/RESIDENTIAL/HOUSE/HOUSE_1W");
        if (!TestCheck(m_Browser.RowIndex("map:1/RESIDENTIAL/HOUSE/HOUSE_1W/Land_House_1W05_Yellow") < 0 && m_Browser.RowIndex("map:2/RESIDENTIAL/HOUSE/HOUSE_1W/Land_House_1W05_Yellow") >= 0 && m_Browser.FirstClass() == "", "house family folders collapse independently without selecting spawn classes")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow("map:1/RESIDENTIAL");
        m_Browser.ActivateRow("map:1/RESIDENTIAL/HOUSE");
        m_Browser.ActivateRow("map:1/RESIDENTIAL/HOUSE/HOUSE_1W");
        m_Browser.SetMode(true);
        m_Browser.SetMode(false);
        if (!TestCheck(m_Browser.RowIndex("map:1/RESIDENTIAL/HOUSE/HOUSE_1W/Land_House_1W05_Yellow") >= 0 && m_Browser.FirstClass() == "", "residential family expansion survives catalog tab switching")) return false;
        for (int branch = 1; branch <= 5; branch++)
        {
            if (!TestCheck(m_Browser.BranchCount(branch) == mapCounts[branch - 1], "industrial and residential grouping preserves map branch "+branch.ToString())) return false;
        }
        if (!TestCheck(m_Browser.CatalogCovered() && m_Browser.MatchCount() == baseline && !m_Browser.ShowStaticObjects(), "building family grouping preserves all objects global totals and StaticObj filtering")) return false;
        return true;
    }

    protected bool SelfTestItemTree()
    {
        m_Browser.SetMode(true);
        string hammerPath = m_Browser.ItemGroupPath("Hammer");
        string hammerKey = "items/"+hammerPath+"/Hammer";
        string hammerRoot = "items/"+m_Browser.ItemMapBranch("Hammer");
        string hammerTools = hammerRoot+"/GEAR/TOOLS";
        bool splitTools = hammerPath != m_Browser.ItemMapBranch("Hammer")+"/GEAR/TOOLS";
        string hammerGroup = "GEAR/TOOLS";
        if (splitTools) hammerGroup += "/CONSTRUCTION";
        if (!TestCheck(m_Browser.ItemCatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(true) && !m_Browser.StaticControlVisible(), "item tree covers every visible inventory class exactly once")) return false;
        array<string> examples = {"AK101","Ammo_556x45","Mag_AK101_30Rnd","AmmoBox_556x45_20Rnd","ReflexOptic","CargoPants_Grey","BakedBeansCan","WaterBottle","Hammer","CanisterGasoline","HatchbackWheel","HatchbackDoors_Driver"};
        array<string> groups = {"WEAPONS/FIREARMS","AMMO/ROUNDS","AMMO/MAGAZINES","AMMO/BOXES","ATTACHMENTS/OPTICS","CLOTHING/PANTS","FOOD_DRINKS/FOOD","FOOD_DRINKS/DRINKS",hammerGroup,"VEHICLE_PARTS/COMPONENTS","VEHICLE_PARTS/WHEELS","VEHICLE_PARTS/BODY"};
        for (int i = 0; i < examples.Count(); i++)
        {
            m_Browser.Search(examples[i]);
            string path = m_Browser.ItemGroupPath(examples[i]);
            string expected = m_Browser.ItemMapBranch(examples[i])+"/"+groups[i];
            string key = "items/"+path+"/"+examples[i];
            if (!TestCheck((path == expected || path.IndexOf(expected+"/") == 0) && m_Browser.ActivateRow(key) && m_Browser.FirstClass() == examples[i], "item search reveals its category and selects exact classname: "+examples[i])) return false;
        }
        string bodyRoot = "items/"+m_Browser.ItemMapBranch("HatchbackDoors_Driver")+"/VEHICLE_PARTS";
        m_Browser.ActivateRow(bodyRoot+"/BODY");
        if (!TestCheck(m_Browser.RowIndex("items/"+m_Browser.ItemGroupPath("HatchbackDoors_Driver")+"/HatchbackDoors_Driver") < 0 && m_Browser.FirstClass() == "" && m_Browser.RowIndex(bodyRoot) >= 0, "item search folders collapse without selecting a spawn class")) return false;
        m_Browser.Search("a");
        if (!TestCheck(m_Browser.MatchCount() > 100 && m_Browser.ShownCount() == m_Browser.MatchCount(), "item search displays every matching class without a 100-result cap")) return false;
        m_Browser.Search("no_such_proxy_tool_item");
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.RowCount() == 1 && m_Browser.FirstClass() == "", "empty item search clears the previous spawn classname")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow(hammerRoot);
        m_Browser.ActivateRow(hammerRoot+"/GEAR");
        m_Browser.ActivateRow(hammerTools);
        if (splitTools) m_Browser.ActivateRow("items/"+hammerPath);
        if (!TestCheck(m_Browser.RowIndex(hammerKey) >= 0 && m_Browser.FirstClass() == "", "item folders expand without choosing a spawn classname")) return false;
        m_Browser.SetMode(false);
        m_Browser.SetMode(true);
        if (!TestCheck(m_Browser.RowIndex(hammerKey) >= 0 && m_Browser.RowIndex("objects") < 0, "return to items preserves its expanded categories")) return false;
        m_Browser.Search("  hAmMeR  ");
        if (!TestCheck(m_Browser.ActivateRow(hammerKey) && m_Browser.FirstClass() == "Hammer" && m_Browser.RowIndex(hammerRoot+"/CLOTHING") < 0, "item search ignores case and spaces and hides unrelated categories")) return false;
        string hammerName = m_Browser.ItemName("Hammer");
        string upperName = hammerName;
        upperName.ToUpper();
        m_Browser.Search("  "+upperName+"  ");
        if (!TestCheck(upperName != hammerName && m_Browser.ActivateRow(hammerKey) && m_Browser.SelectedDragClass() == "Hammer", "localized item search ignores letter case and surrounding spaces")) return false;
        string partialName = hammerName.SubstringUtf8(1,hammerName.LengthUtf8() - 2);
        m_Browser.Search(partialName);
        if (!TestCheck(m_Browser.ActivateRow(hammerKey) && m_Browser.FirstClass() == "Hammer", "partial localized item names reveal the matching catalog path")) return false;
        m_Browser.Search(m_Browser.ItemName("AK74"));
        string akKey = "items/"+m_Browser.ItemGroupPath("AK74")+"/AK74";
        bool localizedWeapon = m_Browser.ActivateRow(akKey);
        m_Browser.Search("aK74");
        if (!TestCheck(localizedWeapon && m_Browser.ActivateRow(akKey) && m_Browser.SelectedDragClass() == "AK74", "weapon search accepts both localized names and original classnames")) return false;
        string sharedName = m_Browser.ItemName("CargoPants_Grey");
        m_Browser.Search(sharedName);
        bool greySelected = m_Browser.ActivateRow("items/"+m_Browser.ItemGroupPath("CargoPants_Grey")+"/CargoPants_Grey") && m_Browser.SelectedDragClass() == "CargoPants_Grey";
        bool blackSelected = m_Browser.ActivateRow("items/"+m_Browser.ItemGroupPath("CargoPants_Black")+"/CargoPants_Black") && m_Browser.SelectedDragClass() == "CargoPants_Black";
        if (!TestCheck(sharedName == m_Browser.ItemName("CargoPants_Black") && greySelected && blackSelected && m_Browser.MatchCount() >= 2 && m_Browser.ShownCount() == m_Browser.MatchCount(), "shared localized names preserve separate selectable item classes")) return false;
        m_Browser.Search("");
        m_Browser.ActivateRow("items");
        if (!TestCheck(m_Browser.RowCount() == 1 && m_Browser.ShownCount() == 0 && m_Browser.FirstClass() == "", "item root collapses without selecting a spawn class")) return false;
        m_Browser.ActivateRow("items");
        if (!TestCheck(m_Browser.RowIndex(hammerKey) >= 0, "item root restores previously expanded categories")) return false;
        array<string> toolExamples = {"Hammer","SledgeHammer","Shovel","Pliers","Screwdriver","Wrench","Hacksaw","HandSaw","SewingKit","LeatherSewingKit","WeaponCleaningKit","KitchenTimer"};
        array<string> toolGroups = {"CONSTRUCTION","CONSTRUCTION","CONSTRUCTION","METALWORK","METALWORK","METALWORK","CUTTING","CUTTING","REPAIR","REPAIR","REPAIR","OTHER"};
        for (int toolIndex = 0; toolIndex < toolExamples.Count(); toolIndex++)
        {
            string toolPath = m_Browser.ItemGroupPath(toolExamples[toolIndex]);
            string toolParent = m_Browser.ItemMapBranch(toolExamples[toolIndex])+"/GEAR/TOOLS";
            string expectedPath = toolParent;
            if (toolPath != toolParent) expectedPath += "/"+toolGroups[toolIndex];
            m_Browser.Search(toolExamples[toolIndex]);
            bool ancestorsVisible = m_Browser.RowIndex("items/"+toolParent) >= 0 && m_Browser.RowIndex("items/"+toolPath) >= 0;
            bool toolPathMatches = toolPath == expectedPath || (toolGroups[toolIndex] == "OTHER" && toolPath.IndexOf(expectedPath+"/") == 0);
            if (!TestCheck(ancestorsVisible && toolPathMatches && m_Browser.ActivateRow("items/"+toolPath+"/"+toolExamples[toolIndex]) && m_Browser.SelectedDragClass() == toolExamples[toolIndex], "tool search reveals ancestors and selects its exact classname: "+toolExamples[toolIndex])) return false;
        }
        m_Browser.Search("Hammer");
        m_Browser.ActivateRow(hammerTools);
        if (!TestCheck(m_Browser.RowIndex(hammerKey) < 0 && m_Browser.RowIndex(hammerRoot+"/GEAR") >= 0 && m_Browser.FirstClass() == "", "collapsing tools hides all nested item leaves without choosing a spawn class")) return false;
        if (!TestCheck(IOTItemCatalog.ToolSubcategory("AddonHammer","\\DZ\\gear\\tools\\Hammer.p3d") == "CONSTRUCTION" && IOTItemCatalog.ToolSubcategory("AddonTool","dz/gear/tools/new_tool.p3d") == "OTHER", "tool model aliases retain modded tools and unknown tools have an explicit fallback")) return false;
        if (!TestCheck(IOTItemCatalog.Group("Hammer","custom/items/tool.p3d","CfgVehicles") == "OTHER" && IOTItemCatalog.Group("AK101","custom/weapons/rifle.p3d","CfgWeapons") == "WEAPONS/OTHER" && IOTItemCatalog.Group("HatchbackWheel","custom/items/wheel.p3d","CfgVehicles") == "VEHICLE_PARTS/WHEELS", "unknown item resources retain Other fallbacks and inherited wheel classification")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestItemMaps()
    {
        IOTItemTypesXml parser = new IOTItemTypesXml;
        string fixture = "<?xml version='1.0'?><types><!-- <type name='False'><nominal>7</nominal></type> --><type name='Enabled'><nominal>12</nominal><flags crafted='0'/></type><type name='Disabled'><nominal>0</nominal></type></types>";
        for (int offset = 0; offset < fixture.Length(); offset += 7) parser.Feed(fixture.Substring(offset,Math.Min(7,fixture.Length() - offset)));
        if (!TestCheck(parser.Finish() && parser.Enabled.Count() == 1 && parser.Enabled.Contains("enabled") && !parser.Enabled.Contains("disabled") && !parser.Enabled.Contains("false"), "item map XML handles fragmented tags numbers comments and disabled records")) return false;
        array<string> invalid = {"<types><type name='X'><nominal>2</nominal></type>","<types><type name='X'><nominal>2</nominal></type><type name='x'><nominal>1</nominal></type></types>","<types><type name='X'><nominal>-1</nominal></type></types>","<types><type name='X'/></types>","<types><type name='X'><nominal>2</nominal><nominal>0</nominal></type></types>"};
        for (int invalidIndex = 0; invalidIndex < invalid.Count(); invalidIndex++)
        {
            IOTItemTypesXml broken = new IOTItemTypesXml;
            broken.Feed(invalid[invalidIndex]);
            if (!TestCheck(!broken.Finish() && broken.Enabled.Count() == 0, "invalid item map XML cannot publish partial membership: "+invalidIndex.ToString())) return false;
        }
        if (!TestCheck(IOTItemMaps.Branch(3,15) == "common" && IOTItemMaps.Branch(15,15) == "common" && IOTItemMaps.Branch(0,15) == "common", "shared items have one Common branch and unknown items remain accessible")) return false;
        if (!TestCheck(IOTItemMaps.Branch(1,7) == "common" && IOTItemMaps.Branch(3,7) == "common" && IOTItemMaps.Branch(0,0) == "common", "unavailable map sources never create false exclusive item membership")) return false;
        if (!TestCheck(m_Browser.ItemMapSources() == 15, "item map sources read all four installed official types files")) return false;
        array<string> classes = {"Hammer","Flag_Chernarus","Flag_Livonia","Iceaxe","BrickTrowel","ScientificBriefcase"};
        array<string> branches = {"common","map:1","map:2","map:3","map:4","common"};
        m_Browser.SetMode(true);
        for (int index = 0; index < classes.Count(); index++)
        {
            m_Browser.Search(classes[index]);
            string branch = branches[index];
            string path = m_Browser.ItemGroupPath(classes[index]);
            if (!TestCheck(m_Browser.ItemMapBranch(classes[index]) == branch && path.IndexOf(branch+"/") == 0 && m_Browser.RowIndex("items/"+branch) >= 0 && m_Browser.ActivateRow("items/"+path+"/"+classes[index]) && m_Browser.SelectedDragClass() == classes[index], "map catalog search reveals the correct unique branch and exact item: "+classes[index])) return false;
        }
        m_Browser.Search("Hammer");
        m_Browser.ActivateRow("items/common");
        if (!TestCheck(m_Browser.RowIndex("items/"+m_Browser.ItemGroupPath("Hammer")+"/Hammer") < 0 && m_Browser.FirstClass() == "" && m_Browser.RowIndex("items/common") >= 0, "collapsing Common hides its category descendants without selecting an item")) return false;
        m_Browser.Search("no_such_item_map_class");
        if (!TestCheck(m_Browser.RowCount() == 1 && m_Browser.MatchCount() == 0, "empty map catalog search has no unrelated map branches")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.ItemCatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(true), "map item branches preserve every visible classname exactly once and keep global counts")) return false;
        array<string> mapBranches = IOTItemMaps.Branches();
        foreach (string mapBranch : mapBranches)
        {
            PrintToRPT("[PROXY ITEM MAP TEST] branch="+mapBranch+" label="+IOTItemMaps.Label(mapBranch));
        }
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestItemVisibility()
    {
        if (!TestCheck(IOTItemCatalog.HiddenReason("Candle","$UNT$Candle") == "placeholder" && IOTItemCatalog.HiddenReason("WipAmmo","TODO") == "placeholder", "catalog excludes explicit untranslated placeholders and TODO labels")) return false;
        if (!TestCheck(IOTItemCatalog.HiddenReason("Test_Item","Item") == "technical" && IOTItemCatalog.HiddenReason("Item_Debug","Item") == "technical" && IOTItemCatalog.HiddenReason("Debug_Item","Item") == "technical", "catalog excludes explicit technical classname tokens")) return false;
        if (!TestCheck(IOTItemCatalog.HiddenReason("BloodTestKit","Blood test kit") == "" && IOTItemCatalog.HiddenReason("LatestTool","Tool") == "" && IOTItemCatalog.HiddenReason("AddonTool","$STR_AddonTool") == "", "catalog preserves gameplay blood tests ordinary names and missing translations")) return false;
        m_Browser.SetMode(true);
        array<string> technical = {"DoorTestCamera","DarkMotoHelmet_YellowScarred_Test","ChernarusMap_Open_Test"};
        foreach (string classname : technical)
        {
            m_Browser.Search(classname);
            if (!TestCheck(m_Browser.ResolveClass(classname,true) == classname && m_Browser.MatchCount() == 0 && m_Browser.FirstClass() == "" && m_Browser.ItemGroupPath(classname) == "", "technical items stay resolvable without appearing in catalog or search: "+classname)) return false;
        }
        m_Browser.Search("BloodTestKit");
        if (!TestCheck(m_Browser.ClassRow("BloodTestKit") >= 0 && m_Browser.ActivateRow("items/"+m_Browser.ItemGroupPath("BloodTestKit")+"/BloodTestKit") && m_Browser.SelectedDragClass() == "BloodTestKit", "gameplay blood test kit remains searchable and selectable")) return false;
        m_Browser.Search("$UNT$");
        if (!TestCheck(m_Browser.MatchCount() == 0 && m_Browser.RowCount() == 1, "untranslated placeholder items do not leak into search results")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.RowIndex("items/unassigned") < 0 && m_Browser.HiddenItemCount() >= 3 && m_Browser.KnownItemCount() == m_Browser.CatalogCount(true)+m_Browser.HiddenItemCount() && m_Browser.ItemCatalogCovered(), "five map branches account for all visible and deliberately hidden classes")) return false;
        PrintToRPT("[PROXY ITEM VISIBILITY TEST] visible="+m_Browser.CatalogCount(true).ToString()+" hidden="+m_Browser.HiddenItemCount().ToString()+" known="+m_Browser.KnownItemCount().ToString());
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestWeaponGroups()
    {
        if (!TestCheck(IOTWeaponCatalog.AmmoCaliber("Ammo_556x45Tracer") == "556X45" && IOTWeaponCatalog.AmmoCaliber("Ammo_9x39AP") == "9X39" && IOTWeaponCatalog.AmmoCaliber("Modded_UnknownRound") == "OTHER", "cartridge groups merge tracer and AP variants without guessing unknown cartridges")) return false;
        array<string> weapons = {"AK101","AK74","AKM","SKS","VSS","B95","UMP45","MP5K","Mosin9130"};
        array<string> calibers = {"556X45","545X39","762X39","762X39","9X39","308WIN","45ACP","9X19","762X54"};
        m_Browser.SetMode(true);
        for (int weaponIndex = 0; weaponIndex < weapons.Count(); weaponIndex++)
        {
            string classname = weapons[weaponIndex];
            m_Browser.Search(classname);
            string root = m_Browser.ItemMapBranch(classname)+"/WEAPONS/FIREARMS";
            string path = m_Browser.ItemGroupPath(classname);
            string expected = root;
            if (path != root) expected += "/CAL_"+calibers[weaponIndex];
            if (!TestCheck(IOTWeaponCatalog.WeaponCaliber(classname) == calibers[weaponIndex] && path == expected && m_Browser.RowIndex("items/"+path) >= 0 && m_Browser.ActivateRow("items/"+path+"/"+classname) && m_Browser.SelectedDragClass() == classname, "weapon caliber search preserves exact item selection: "+classname)) return false;
        }
        array<string> magazines = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK101_30Rnd","Mag_STANAG_30Rnd","Mag_Aug_30Rnd","Mag_FAMAS_25Rnd","Mag_SVD_10Rnd","Mag_Saiga_5Rnd","Mag_CLIP762x39_10Rnd","Mag_MP5_30Rnd","Mag_1911_7Rnd","Mag_Ruger1022_10Rnd","Mag_CZ61_20Rnd","Mag_Deagle_9rnd"};
        array<string> magazineCalibers = {"545X39","545X39","556X45","556X45","556X45","556X45","762X54","12GA","762X39","9X19","45ACP","22","380","357"};
        for (int magazineIndex = 0; magazineIndex < magazines.Count(); magazineIndex++)
        {
            string magazine = magazines[magazineIndex];
            m_Browser.Search(magazine);
            string magazinePath = m_Browser.ItemGroupPath(magazine);
            string magazineRoot = m_Browser.ItemMapBranch(magazine)+"/AMMO/MAGAZINES";
            string magazineExpected = magazineRoot;
            if (magazinePath != magazineRoot) magazineExpected += "/CAL_"+magazineCalibers[magazineIndex];
            if (!TestCheck(IOTWeaponCatalog.MagazineCaliber(magazine) == magazineCalibers[magazineIndex] && magazinePath == magazineExpected && m_Browser.RowIndex("items/"+magazinePath) >= 0 && m_Browser.ActivateRow("items/"+magazinePath+"/"+magazine) && m_Browser.SelectedDragClass() == magazine, "magazine caliber search preserves exact item selection: "+magazine)) return false;
        }
        if (!TestCheck(m_Browser.ItemGroupPath("Mag_AK74_30Rnd") == m_Browser.ItemGroupPath("Mag_AK74_30Rnd_Black") && m_Browser.ItemGroupPath("Mag_AK74_30Rnd") != m_Browser.ItemGroupPath("Mag_AK101_30Rnd"), "cosmetic magazine variants share caliber groups while different cartridges remain separate")) return false;
        if (!TestCheck(m_Browser.ItemGroupPath("Mag_FAMAS_25Rnd") == m_Browser.ItemGroupPath("Mag_STANAG_30Rnd") && m_Browser.ItemGroupPath("Mag_SVD_10Rnd") != m_Browser.ItemGroupPath("Mag_CLIP762x39_10Rnd"), "magazine folders group different weapon systems by cartridge without merging distinct 7.62 cartridges")) return false;
        m_Browser.Search("AK74");
        string akPath = "items/"+m_Browser.ItemGroupPath("AK74");
        m_Browser.ActivateRow(akPath);
        if (!TestCheck(m_Browser.RowIndex(akPath+"/AK74") < 0 && m_Browser.FirstClass() == "" && m_Browser.RowIndex("items/"+m_Browser.ItemGroupPath("Mag_AK74_30Rnd")+"/Mag_AK74_30Rnd") >= 0, "collapsing a caliber search branch preserves matching magazines in another category")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.ItemCatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(true), "weapon and magazine subgroups preserve visible totals and single classname coverage")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestClothingGroups()
    {
        array<string> classes = {"Breeches_Pink","Breeches_Red","AthleticShoes_Blue","AthleticShoes_Black","LeatherGloves_Natural","LeatherGloves_Black","BallisticHelmet_Green","BallisticHelmet_Black","Hoodie_Blue","Hoodie_Black","AliceBag_Green","AliceBag_Black","BalaclavaMask_Black","BalaclavaMask_Green","PlateCarrierVest","PlateCarrierVest_Camo"};
        array<string> sections = {"PANTS","PANTS","SHOES","SHOES","GLOVES","GLOVES","HEADGEAR","HEADGEAR","TOPS","TOPS","BACKPACKS","BACKPACKS","MASKS","MASKS","VESTS","VESTS"};
        array<string> families = {"Breeches_ColorBase","Breeches_ColorBase","AthleticShoes_ColorBase","AthleticShoes_ColorBase","LeatherGloves_ColorBase","LeatherGloves_ColorBase","BallisticHelmet_ColorBase","BallisticHelmet_ColorBase","Hoodie_ColorBase","Hoodie_ColorBase","AliceBag_ColorBase","AliceBag_ColorBase","BalaclavaMask_ColorBase","BalaclavaMask_ColorBase","PlateCarrierVest","PlateCarrierVest"};
        m_Browser.SetMode(true);
        for (int index = 0; index < classes.Count(); index++)
        {
            string classname = classes[index];
            string parent = m_Browser.ItemMapBranch(classname)+"/CLOTHING/"+sections[index];
            string path = m_Browser.ItemGroupPath(classname);
            string expected = parent;
            if (sections[index] == "HEADGEAR") expected += "/HELMETS";
            if (sections[index] == "TOPS") expected += "/SWEATERS";
            if (path != parent) expected += "/MODEL_"+families[index];
            m_Browser.Search(classname);
            if (!TestCheck(m_Browser.ClothingFamilyOf(classname) == families[index] && path == expected && m_Browser.RowIndex("items/"+parent) >= 0 && m_Browser.ActivateRow("items/"+path+"/"+classname) && m_Browser.SelectedDragClass() == classname, "clothing family search selects the exact color variant: "+classname)) return false;
        }
        if (!TestCheck(m_Browser.ItemGroupPath("Breeches_Pink").Contains("/MODEL_Breeches_ColorBase") && m_Browser.ItemGroupPath("AthleticShoes_Black").Contains("/MODEL_AthleticShoes_ColorBase") && m_Browser.ItemGroupPath("LeatherGloves_Black").Contains("/MODEL_LeatherGloves_ColorBase") && m_Browser.ItemGroupPath("BallisticHelmet_Black").Contains("/MODEL_BallisticHelmet_ColorBase"), "large pants footwear gloves and headgear lists expose model family folders")) return false;
        if (!TestCheck(m_Browser.ItemGroupPath("CargoPants_Grey") == m_Browser.ItemGroupPath("CargoPants_Black") && m_Browser.ItemGroupPath("CargoPants_Grey") != m_Browser.ItemGroupPath("Breeches_Pink"), "clothing variants share one family without mixing different garments")) return false;
        if (!TestCheck(m_Browser.ClothingFamilyOf("USMCPants_Woodland") == "USMCPants_ColorBase" && m_Browser.ClothingFamilyOf("OMKPants_Navy") == "OMKPants_ColorBase", "different clothing families remain distinct even when their ground model is shared")) return false;
        if (!TestCheck(IOTItemCatalog.ClothingFamily("AddonUnknownClothing","") == "AddonUnknownClothing" && IOTItemCatalog.ClothingFamily("AddonUnknownClothing","addon/custom_g.p3d") == "AddonUnknownClothing", "unknown clothing configuration retains an exact independent family")) return false;
        m_Browser.Search("HandsCover_Improvised");
        string handPath = m_Browser.ItemMapBranch("HandsCover_Improvised")+"/CLOTHING/GLOVES";
        if (!TestCheck(m_Browser.ItemGroupPath("HandsCover_Improvised") == handPath && m_Browser.ActivateRow("items/"+handPath+"/HandsCover_Improvised"), "single garment families remain direct selectable rows without one-item folders")) return false;
        string breechesName = m_Browser.ItemName("Breeches_Pink");
        string breechesPath = m_Browser.ItemGroupPath("Breeches_Pink");
        string familyLabel = m_Browser.ItemGroupLabel("CLOTHING/PANTS/MODEL_Breeches_ColorBase");
        m_Browser.Search(breechesName);
        if (!TestCheck(familyLabel == breechesName && m_Browser.RowIndex("items/"+breechesPath) >= 0 && m_Browser.ActivateRow("items/"+breechesPath+"/Breeches_Pink") && m_Browser.ActivateRow("items/"+m_Browser.ItemGroupPath("Breeches_Red")+"/Breeches_Red"), "localized garment names reveal model folders and keep same-name variants distinct")) return false;
        m_Browser.ActivateRow("items/"+breechesPath);
        if (!TestCheck(m_Browser.RowIndex("items/"+breechesPath+"/Breeches_Pink") < 0 && m_Browser.FirstClass() == "", "collapsing a clothing family hides its variants and clears the spawn classname")) return false;
        m_Browser.Search("AthleticShoes_Black");
        m_Browser.Search(breechesName);
        if (!TestCheck(m_Browser.RowIndex("items/"+breechesPath+"/Breeches_Pink") >= 0, "changing clothing search restores the revealed family path")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.ItemCatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(true), "clothing family subgroups preserve all visible items exactly once and keep global counts")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestCampingGroups()
    {
        array<string> classes = {"CarTent","MediumTent","ShelterKit","ShelterFabric","SeaChest","WoodenCrate","AnniversaryBox","UndergroundStash","FenceKit","CamoNet","Fabric","WoodenLog","CombinationLock","CombinationLock4","DigitalCodeLock","PowerGenerator","BatteryCharger","CableReel","Spotlight","XmasLights","Flag_DayZ","TerritoryFlagKit","TerritoryFlag"};
        array<string> subcategories = {"SHELTERS","SHELTERS","SHELTERS","SHELTERS","STORAGE","STORAGE","STORAGE","STORAGE","BUILDING","BUILDING","BUILDING","BUILDING","LOCKS","LOCKS","LOCKS","POWER","POWER","POWER","LIGHTING","LIGHTING","FLAGS","FLAGS","FLAGS"};
        m_Browser.SetMode(true);
        for (int index = 0; index < classes.Count(); index++)
        {
            string classname = classes[index];
            string parent = m_Browser.ItemMapBranch(classname)+"/GEAR/CAMPING";
            string path = m_Browser.ItemGroupPath(classname);
            string expected = parent;
            if (path != parent) expected += "/"+subcategories[index];
            m_Browser.Search(classname);
            if (!TestCheck((path == expected || path.IndexOf(expected+"/") == 0) && m_Browser.RowIndex("items/"+parent) >= 0 && m_Browser.ActivateRow("items/"+path+"/"+classname) && m_Browser.SelectedDragClass() == classname, "camping search reveals a purpose group and exact classname: "+classname)) return false;
        }
        if (!TestCheck(m_Browser.ItemGroupPath("CarTent") == "common/GEAR/CAMPING/SHELTERS" && m_Browser.ItemGroupPath("WoodenCrate") == "common/GEAR/CAMPING/STORAGE" && m_Browser.ItemGroupPath("TerritoryFlag").IndexOf("common/GEAR/CAMPING/FLAGS/") == 0, "tent containers and flagpole structures use their camping purpose before generic inheritance")) return false;
        if (!TestCheck(IOTItemCatalog.CampingSubcategory("AddonCampingLock","DZ/gear/camping/combination_lock4.p3d") == "LOCKS" && IOTItemCatalog.CampingSubcategory("AddonUnknownCamping","addon/new_item.p3d") == "OTHER", "camping model aliases support renamed classes and unknown resources retain a fallback")) return false;
        m_Browser.Search("CableReel");
        string powerPath = "items/"+m_Browser.ItemGroupPath("CableReel");
        m_Browser.ActivateRow(powerPath);
        if (!TestCheck(m_Browser.RowIndex(powerPath+"/CableReel") < 0 && m_Browser.FirstClass() == "", "camping subgroups collapse without choosing a spawn classname")) return false;
        m_Browser.Search(m_Browser.ItemName("CableReel"));
        if (!TestCheck(m_Browser.RowIndex(powerPath+"/CableReel") >= 0 && m_Browser.ActivateRow(powerPath+"/CableReel") && m_Browser.SelectedDragClass() == "CableReel", "localized camping search restores the exact item under its subgroup")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.ItemCatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(true), "camping subdivisions preserve all visible items and global totals")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestAdditionalGroups()
    {
        // Fixed stock examples exercise the real catalog, not only the classifier.
        array<string> cases = {
            "HatchbackDoors_Driver|VEHICLE_PARTS/BODY/CAR_ADA/DOORS",
            "HatchbackHood_BlueRust|VEHICLE_PARTS/BODY/CAR_ADA/HOODS",
            "HatchbackTrunk|VEHICLE_PARTS/BODY/CAR_ADA/TRUNKS",
            "CivSedanDoors_Driver|VEHICLE_PARTS/BODY/CAR_OLGA/DOORS",
            "Hatchback_02_Door_1_1|VEHICLE_PARTS/BODY/CAR_GUNTER/DOORS",
            "Sedan_02_Door_1_1|VEHICLE_PARTS/BODY/CAR_SARKA/DOORS",
            "Truck_01_Hood|VEHICLE_PARTS/BODY/CAR_M3S/HOODS",
            "Offroad_02_Trunk|VEHICLE_PARTS/BODY/CAR_M1025/TRUNKS",
            "BakedBeansCan_Opened|FOOD_DRINKS/FOOD/CANNED/OPENED",
            "BakedBeansCan|FOOD_DRINKS/FOOD/CANNED/SEALED",
            "Candycane_Red|FOOD_DRINKS/FOOD/SNACKS",
            "CaninaBerry|FOOD_DRINKS/FOOD/FRUIT",
            "CarpFilletMeat|FOOD_DRINKS/FOOD/FISH",
            "BearSteakMeat|FOOD_DRINKS/FOOD/MEAT",
            "BoletusMushroom|FOOD_DRINKS/FOOD/MUSHROOMS",
            "DeadRabbit|FOOD_DRINKS/FOOD/CARCASSES",
            "Rice|FOOD_DRINKS/FOOD/DRY_FOOD",
            "AK_WoodBttstck|ATTACHMENTS/SUPPORT/STOCKS/SYSTEM_AK",
            "M4_RISHndgrd|ATTACHMENTS/SUPPORT/HANDGUARDS/SYSTEM_M4",
            "GhillieAtt_Tan|ATTACHMENTS/SUPPORT/CAMOUFLAGE",
            "FoxPelt|GEAR/CONSUMABLES/PELTS",
            "SmallGasCanister|GEAR/CONSUMABLES/GAS",
            "Nail|GEAR/CONSUMABLES/MATERIALS",
            "Chemlight_Green|GEAR/CONSUMABLES/LIGHT_POWER"
        };
        array<string> remainingCases = {
            "KitchenTimer|GEAR/TOOLS/OTHER/CLOCKS_WRITING",
            "Raycaster|GEAR/TOOLS/OTHER/TECHNICAL",
            "HandcuffKeys|GEAR/TOOLS/OTHER/KEYS_RESTRAINTS",
            "Ammo_556x45Tracer|AMMO/ROUNDS/CARTRIDGES/CAL_556X45",
            "Ammo_40mm_Explosive|AMMO/ROUNDS/GRENADES",
            "Ammo_Flare|AMMO/ROUNDS/FLARES",
            "Ammo_HuntingBolt|AMMO/ROUNDS/BOLTS",
            "Barrel_Blue|GEAR/CONTAINERS/BARRELS",
            "GiftBox_Large_1|GEAR/CONTAINERS/GIFTS",
            "Bear_Beige|GEAR/CONTAINERS/TOYS",
            "WaterproofBag_Green|GEAR/CONTAINERS/BAGS",
            "ScientificBriefcase|GEAR/CONTAINERS/CASES",
            "Flag_Bear|GEAR/CAMPING/FLAGS/FLAGS/ANIMALS",
            "TerritoryFlag|GEAR/CAMPING/FLAGS/FLAGPOLES",
            "Armband_Red|CLOTHING/TOPS/ARMBANDS/MODEL_Armband_ColorBase/PLAIN",
            "Armband_Wolf|CLOTHING/TOPS/ARMBANDS/MODEL_Armband_ColorBase/ANIMALS",
            "MaleAdamHead|OTHER/CHARACTER_HEADS/MALE",
            "FemaleEvaHead|OTHER/CHARACTER_HEADS/FEMALE",
            "Head_Default|OTHER/CHARACTER_HEADS/OTHER",
            "PowerGeneratorStatic|OTHER/DEVICES",
            "StorageBox_Wooden|OTHER/STORAGE"
        };
        cases.InsertAll(remainingCases);
        m_Browser.SetMode(true);
        foreach (string example : cases)
        {
            array<string> pair = new array<string>;
            example.Split("|",pair);
            string classname = pair[0];
            string path = m_Browser.ItemMapBranch(classname)+"/"+pair[1];
            m_Browser.Search(classname);
            if (!TestCheck(m_Browser.ItemGroupPath(classname) == path && m_Browser.RowIndex("items/"+path) >= 0 && m_Browser.ActivateRow("items/"+path+"/"+classname) && m_Browser.SelectedDragClass() == classname, "expanded catalog search selects the exact nested item: "+classname)) return false;
        }
        if (!TestCheck(m_Browser.ItemGroupPath("Bone") == "map:3/FOOD_DRINKS/FOOD" && m_Browser.ItemGroupPath("Offroad_02_Door_1_1_BeigeRust") == "map:4/VEHICLE_PARTS/BODY", "small map-specific lists remain flat under the thirty-item threshold")) return false;
        if (!TestCheck(m_Browser.ItemGroupPath("BookTheCallOfCthulhu") == "common/GEAR/BOOKS" && m_Browser.ItemGroupPath("BookAliceInWonderland") == "common/GEAR/BOOKS", "books keep their existing flat category and remain searchable")) return false;
        if (!TestCheck(IOTCatalogSubgroups.BodyGroup("AddonDoor","DZ/vehicles/wheeled/OffroadHatchback/proxy/nivaDoors_Driver.p3d") == "CAR_ADA/DOORS" && IOTCatalogSubgroups.BodyGroup("AddonUnknownPart","addon/custom.p3d") == "OTHER_VEHICLES/OTHER", "body model aliases retain renamed parts and unknown vehicles have a fallback")) return false;
        m_Browser.Search(m_Browser.ItemName("CivSedanDoors_Driver"));
        string itemPath = "items/"+m_Browser.ItemGroupPath("CivSedanDoors_Driver");
        if (!TestCheck(m_Browser.ActivateRow(itemPath+"/CivSedanDoors_Driver") && m_Browser.SelectedDragClass() == "CivSedanDoors_Driver", "localized body-part search reveals vehicle and part levels")) return false;
        m_Browser.ActivateRow("items/common/VEHICLE_PARTS/BODY/CAR_OLGA");
        if (!TestCheck(m_Browser.RowIndex(itemPath+"/CivSedanDoors_Driver") < 0 && m_Browser.FirstClass() == "", "collapsing a vehicle folder clears its descendant spawn selection")) return false;
        m_Browser.Search("");
        if (!TestCheck(m_Browser.ItemCatalogCovered() && m_Browser.MatchCount() == m_Browser.CatalogCount(true), "expanded subdivisions preserve every visible classname exactly once")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestAnchorHoverPreview()
    {
        Object anchor = m_Anchor;
        ItemBase selected = m_Item;
        vector anchorPosition = anchor.GetPosition();
        vector itemPosition = selected.GetPosition();
        int sceneCount = m_Scenes.Count();
        int itemCount = m_CreatedItems.Count();
        int gizmoCount = GetGizmoApi().GetCount();
        m_Browser.SetMode(false);
        m_Browser.Search("Land_Garage_Row_Small");
        int row = m_Browser.ClassRow("Land_Garage_Row_Small");
        vector point = CatalogRowPoint(row);
        m_Browser.HoverAt(point,true);
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible(), "object hover waits before constructing a popup model")) return false;
        m_Browser.HoverAt(point,true,true);
        EntityAI preview = m_Browser.HoverEntity();
        if (!TestCheck(preview && preview.GetType() == "Land_Garage_Row_Small" && m_Browser.HoverView().GetItem() == preview && m_Browser.HoverBoundVisible(), "building hover binds the exact model after visible preview bounds are established")) return false;
        m_Browser.HoverAt(point,true,true);
        if (!TestCheck(m_Browser.HoverEntity() == preview, "hovering the same building reuses its temporary model")) return false;
        array<string> classes = {"Land_Wreck_hb01_aban1_blue","Land_Underground_Storage_Prison","StaticObj_Furniture_matress_white"};
        m_Browser.SetShowStaticObjects(true);
        foreach (string classname : classes)
        {
            m_Browser.Search(classname);
            row = m_Browser.ClassRow(classname);
            if (!TestCheck(row >= 0, "preview fixture appears in the object catalog: "+classname)) return false;
            m_Browser.HoverAt(CatalogRowPoint(row),true,true);
            EntityAI model = m_Browser.HoverEntity();
            MultilineTextWidget classLabel = MultilineTextWidget.Cast(m_Browser.HoverRoot().FindAnyWidget("HoverItemClass"));
            if (!TestCheck(model && model.GetType() == classname && m_Browser.HoverView().GetItem() == model && m_Browser.HoverView().GetView() == model.GetViewIndex() && classLabel && !m_Browser.HoverRoot().FindAnyWidget("HoverItemEmpty").IsVisible(), "object hover shows the exact classname and native model: "+classname)) return false;
            vector previewPosition = model.GetPosition();
            PrintToRPT("[PROXY OBJECT PREVIEW] "+classname+" position="+previewPosition.ToString()+" body="+dBodyIsSet(model).ToString()+" simulationDisabled="+model.GetIsSimulationDisabled().ToString()+" damage="+model.GetAllowDamage().ToString());
            if (!TestCheck(previewPosition[1] < -999 && !dBodyIsSet(model) && !model.GetAllowDamage(), "object hover model stays local below the map without physics or damage: "+classname)) return false;
        }
        m_Browser.SetShowStaticObjects(false);
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible(), "changing the StaticObj filter releases the hovered object model")) return false;
        m_Browser.Search("Land_Garage_Row_Small");
        row = m_Browser.ClassRow("Land_Garage_Row_Small");
        point = CatalogRowPoint(row);
        m_Browser.HoverAt(point,true,true);
        float x,y,width,height,panelX,panelY,panelWidth,panelHeight;
        m_Browser.HoverRoot().GetScreenPos(x,y);
        m_Browser.HoverRoot().GetScreenSize(width,height);
        m_Browser.Root().GetScreenPos(panelX,panelY);
        m_Browser.Root().GetScreenSize(panelWidth,panelHeight);
        bool separated = x >= panelX+panelWidth+12*m_PanelScale - 1 || x+width <= panelX - 12*m_PanelScale+1;
        if (!TestCheck(separated && !WorldPoint(Vector(x+width*0.5,y+height*0.5,0)), "building hover popup preserves its sidebar gap and blocks clicks through to the world")) return false;
        m_Browser.HoverAt(CatalogRowPoint(0),true,true);
        if (!TestCheck(!m_Browser.HoverEntity(), "object folder rows do not spawn preview entities")) return false;
        m_Browser.HoverAt(point,true,true);
        m_Browser.HoverAt("0 0 0",true);
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverView().GetItem(), "leaving the object list clears its native renderer and temporary model")) return false;
        m_Browser.HoverAt(point,true,true);
        if (!TestCheck(BeginCatalogPress(point) && m_CatalogPressed && !m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible(), "starting an object catalog drag immediately releases the hover preview")) return false;
        CancelCatalogDrag();
        m_Browser.HoverAt(point,true,true);
        m_Browser.SetMode(true);
        if (!TestCheck(!m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible(), "switching from Objects to Items releases the building preview")) return false;
        m_Browser.Search("Hammer");
        m_Browser.HoverAt(CatalogRowPoint(m_Browser.ClassRow("Hammer")),true,true);
        if (!TestCheck(m_Browser.HoverEntity() && m_Browser.HoverEntity().GetType() == "Hammer" && m_Browser.HoverView().GetItem() == m_Browser.HoverEntity(), "item preview still works after previewing buildings and wrecks")) return false;
        m_Browser.HideHoverPreview();
        if (!TestCheck(m_Anchor == anchor && m_Item == selected && m_Scenes.Count() == sceneCount && m_CreatedItems.Count() == itemCount && GetGizmoApi().GetCount() == gizmoCount && vector.Distance(anchor.GetPosition(),anchorPosition) < 0.001 && vector.Distance(selected.GetPosition(),itemPosition) < 0.001 && !AnchorReplacementPending(), "object hover preserves the scene anchor selection gizmo layout and replacement state")) return false;
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
        UpdateCameraHold(false,true,m_Viewport.Center(),false);
        BeginCameraHold(m_Viewport.Center());
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
        EndCameraHold();
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
        if (!SelfTestNotifications(wheel)) return;
        if (!SelfTestLootVolumes(wheel)) return;
        if (!SelfTestToolbar(wheel)) return;
        if (!SelfTestCompactProperties(wheel)) return;
        if (!SelfTestHistory(wheel)) return;
        if (!SelfTestItemOperations(wheel)) return;
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
        if (!TestCheck(!m_Viewport.IsVisible() && !WorldPoint(m_Viewport.Center()) && SelfTestBackdrop(false), "character mode hides and disables world viewport")) return;
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
        if (!TestCheck(m_Viewport.IsVisible() && WorldPoint(m_Viewport.Center()) && SelfTestBackdrop(true), "return to editor restores world viewport")) return;
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
        if (!TestCheck(Math.AbsFloat(trayX - browserX) < 1 && Math.AbsFloat(trayWidth - browserWidth) < 1 && trayY > browserY+browserHeight && trayY+trayHeight <= screenHeight && trayHeight <= 294*m_PanelScale+1, "expanded scene list fits below the catalog in the left column")) return;
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
        vector oldCharacterPosition = GetGame().GetPlayer().GetPosition();
        vector oldCharacterOrientation = GetGame().GetPlayer().GetOrientation();
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
        if (!TestCheck(!EditorModalPending() && m_Anchor == oldAnchor && m_CreatedItems.Count() == oldCount, "object drop outside the world cancels without prompting or changing the scene")) return;
        m_Browser.SelectCatalogItemRow(0);
        BeginCatalogPress(CatalogRowPoint(0));
        UpdateCatalogDrag(drop);
        if (!TestCheck(!m_CatalogPressed && !EditorModalPending(), "object folders cannot create anchors or open the replacement dialog")) return;
        m_Browser.SelectCatalogItemRow(row);
        BeginCatalogPress(press);
        FinishCatalogDrag(drop,true);
        if (!TestCheck(EditorModalPending() && m_ReplaceRoot.IsVisible() && m_Scenes.Count() == oldScenes && m_CreatedItems.Count() == oldCount && m_Item == oldItem, "existing anchor drop requests confirmation before creating or deleting entities")) return;
        vector transform[4];
        oldItem.GetTransform(transform);
        transform[3] = transform[3]+"1 0 0";
        HandleKey(KeyCode.KC_F4);
        bool blocked = !StepHistory(false) && !StepHistory(true) && !BeginCameraHold(drop) && !WorldPoint(drop) && PanelPoint(drop) && !ApplyGizmoTransformAt(transform,false,drop) && !SelectSceneCharacter() && !SpawnSceneClass("Hammer",true) && !SetAnchor(null);
        if (!TestCheck(blocked && !m_PlayerMode && m_Pointer && m_Item == oldItem && GetGizmoApi().GetCount() == 0, "replacement modal blocks world edits selection camera player mode and parallel creation")) return;
        OnClick(m_ReplaceRoot.FindAnyWidget("ReplaceCancel"),0,0,0);
        if (!TestCheck(!EditorModalPending() && !m_ReplaceRoot.IsVisible() && m_Anchor == oldAnchor && m_Item == oldItem && m_Scenes.Count() == oldScenes && m_CreatedItems.Count() == oldCount && vector.Distance(oldItem.GetPosition(),oldPosition) < 0.0001 && GetGizmoApi().GetCount() == 1, "cancelling replacement preserves the complete scene selection pose and gizmo")) return;
        SetAnchor(null);
        SpawnSceneClass("Land_Garage_Row_Small",false);
        bool guarded = EditorModalPending() && m_Scenes.Count() == oldScenes;
        HandleKey(KeyCode.KC_ESCAPE);
        if (!TestCheck(guarded && !EditorModalPending(), "clearing active selection cannot bypass the single-anchor guard and Escape cancels")) return;
        SetAnchor(oldAnchor);
        SelectItem(oldItem);
        SpawnSceneClass("NotAnActualAnchorClass",false);
        if (!TestCheck(!EditorModalPending() && m_Anchor == oldAnchor && m_CreatedItems.Count() == oldCount && m_LastError == IOTL.T("UNKNOWN_CLASS"), "invalid anchor names report an error without requesting replacement")) return;
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
        if (!TestCheck(EditorModalPending(), "central creation API also requires replacement confirmation")) return;
        if (!TestCheck(vector.Distance(GetGame().GetPlayer().GetPosition(),oldCharacterPosition) < 0.001 && vector.Distance(GetGame().GetPlayer().GetOrientation(),oldCharacterOrientation) < 0.001, "cancelled pending and invalid anchor replacements preserve the character pose")) return;
        OnClick(m_ReplaceRoot.FindAnyWidget("ReplaceConfirm"),0,0,0);
        if (UnsavedDialogOpen()) OnClick(m_UnsavedRoot.FindAnyWidget("UnsavedDiscard"),0,0,0);
        if (!TestCheck(!EditorModalPending() && m_Scenes.Count() == 1 && m_Anchor && m_Anchor != oldAnchor && m_Anchor.GetType() == "Land_Garage_Row_Small" && m_ActiveScene.Items.Count() == 0 && m_CreatedItems.Count() == 0 && SelectedObject() == m_Anchor, "confirmed replacement commits one selected anchor and an empty layout")) return;
        vector actual = m_Anchor.GetPosition();
        if (!TestCheck(Math.AbsFloat(actual[0]-hit[0]) < 0.05 && Math.AbsFloat(actual[2]-hit[2]) < 0.05 && m_ActiveScene.Id > previousId && FileExist(oldXml), "replacement keeps the drop location and never reuses exported scene filenames")) return;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestAnchorCleanup,250,false,removed,carried,player,oldXml);
    }

    protected void SelfTestAnchorCleanup(array<Object> removed, ItemBase carried, Man player, string oldXml)
    {
        if (!TestCheck(m_Undo.Count() == 0 && m_Redo.Count() == 0 && !m_HistoryPending, "confirmed anchor replacement clears transform history")) return;
        bool cleared = true;
        foreach (Object oldEntity : removed) if (oldEntity) cleared = false;
        if (!TestCheck(cleared && m_Scenes.Count() == 1, "replacement removes every old tracked world item and anchor")) return;
        if (!TestCheck(player && player == GetGame().GetPlayer() && carried && carried.GetHierarchyRootPlayer() == player && player.FindAttachmentBySlotName("Feet"), "replacement preserves the character inventory and footwear")) return;
        if (!TestCheck(CharacterReadyAtAnchor(m_Anchor), "confirmed anchor replacement positions and faces the character five metres from the new model")) return;
        if (!TestCheck(SpawnSceneClass("HatchbackWheel",true) && ItemScene(m_Item) == m_ActiveScene && ExportAnchor() && FileExist(oldXml), "new anchor accepts and exports items while the previous XML remains intact")) return;
        m_Browser.SetMode(false);
        m_Browser.Search("");
        RefreshObjects();
        if (!SelfTestProjects()) return;
        if (!SelfTestUnsavedProjects()) return;
        SelfTestToolbarHoverStart();
    }

    protected void SelfTestToolbarHoverStart()
    {
        float width,height;
        m_Toolbar.GetScreenSize(width,height);
        m_ToolbarHoverTest = new IOTToolbarChrome(m_Toolbar);
        IOTToolbarChrome probe = m_ToolbarHoverTest;
        probe.SetProjectDirty(HasUnsavedChanges());
        probe.Layout(width,m_PanelScale);
        Widget button = m_Toolbar.FindAnyWidget("ProjectSave");
        float x,y,w,h;
        button.GetScreenPos(x,y); button.GetScreenSize(w,h);
        vector point = Vector(x+w*0.5,y+h*0.5,0);
        int started = GetGame().GetTime();
        probe.HoverAt(point,true);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestToolbarHoverTick,50,false,probe,point,started,width);
    }

    protected void SelfTestToolbarHoverTick(IOTToolbarChrome probe, vector point, int started, float width)
    {
        // Exercise real elapsed time and the same refresh interval as Tick.
        probe.Layout(width,m_PanelScale);
        probe.HoverAt(point,true);
        if (GetGame().GetTime() - started < 500)
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestToolbarHoverTick,50,false,probe,point,started,width);
            return;
        }
        if (!TestCheck(probe.HintRoot().IsVisible(), "toolbar hints appear after real hover delay despite periodic layout refresh")) return;
        probe.Layout(width,m_PanelScale);
        if (!TestCheck(probe.HintRoot().IsVisible(), "unchanged toolbar refresh preserves an already visible hint")) return;
        probe.HideHint();
        m_ToolbarHoverTest = null;
        SelfTestFinish();
    }

    protected void SelfTestFinish()
    {
        DismissNotification();
        m_LootVolumes.Enable(true);
        m_LootVolumes.Update(m_Anchor,m_LootMap,true);
        UpdateToolbar();
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

    protected bool SelfTestUnsavedProjects()
    {
        IOTProjectData original = CaptureProject();
        IOTProjectData previousBaseline = m_ProjectBaseline;
        string previousName = m_CurrentProject;
        string name = "__selftest_unsaved_"+GetGame().GetTime().ToString();
        if (!SaveProject(name)) return false;
        if (!TestCheck(!HasUnsavedChanges(), "successful saves clear the scene dirty marker")) return false;
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        vector cameraPosition = camera.GetPosition();
        camera.SetPosition(cameraPosition+"1 0 0");
        if (!TestCheck(!HasUnsavedChanges(), "camera browsing preserves the saved scene state")) return false;
        camera.SetPosition(cameraPosition);
        ClearHistory();
        if (!SpawnSceneClass("Hammer",true)) return false;
        if (!TestCheck(HasUnsavedChanges() && StepHistory(false) && !HasUnsavedChanges() && StepHistory(true) && HasUnsavedChanges(), "creation Undo and Redo follow the saved scene baseline")) return false;
        if (!DeleteSelectedItem()) return false;
        if (!TestCheck(!HasUnsavedChanges(), "deleting a new item returns to the saved scene contents")) return false;
        SelectItem(m_ActiveScene.Items[0]);
        ClearHistory();
        Nudge(false,0,1);
        if (!TestCheck(HasUnsavedChanges() && StepHistory(false) && !HasUnsavedChanges(), "transform Undo clears dirty state at the saved pose")) return false;
        Nudge(false,0,1);
        ItemBase selected = m_Item;
        Object anchor = m_Anchor;
        vector changedPosition = selected.GetPosition();
        IOTPendingProjectAction open = new IOTPendingProjectAction;
        open.Kind = IOTProjectTransition.OPEN_PROJECT;
        open.Name = name;
        RequestProjectAction(open);
        if (!TestCheck(UnsavedDialogOpen() && !WorldPoint(m_Viewport.Center()) && !StepHistory(false) && !DeleteSelectedItem() && m_Anchor == anchor, "unsaved prompt blocks edits before replacing the current project")) return false;
        HandleKey(KeyCode.KC_ESCAPE);
        if (!TestCheck(!EditorModalPending() && !m_PendingProjectAction && m_Item == selected && vector.Distance(m_Item.GetPosition(),changedPosition) < 0.001 && HasUnsavedChanges(), "Escape cancels the pending action and preserves unsaved placement")) return false;
        if (!TestCheck(RequestEditorExit() && UnsavedDialogOpen() && m_PendingProjectAction.Kind == IOTProjectTransition.EXIT_EDITOR, "editor exit requests save discard or cancel for a dirty scene")) return false;
        CancelPendingProjectAction();
        RequestProjectAction(open);
        UnsavedChoice(true);
        m_ProjectName.SetText("..");
        ProjectAction();
        if (!TestCheck(ProjectDialogOpen() && m_PendingProjectAction && m_Anchor == anchor && m_Item == selected && HasUnsavedChanges(), "failed save validation preserves the pending action and current scene")) return false;
        CloseProjectDialog();
        if (!TestCheck(!m_PendingProjectAction && !EditorModalPending() && m_Anchor == anchor, "cancelling Save As also cancels the destructive continuation")) return false;
        RequestProjectAction(open);
        UnsavedChoice(true);
        m_ProjectName.SetText(name+"_changed");
        ProjectAction();
        IOTProjectData savedChanges;
        string error;
        if (!TestCheck(!EditorModalPending() && !m_PendingProjectAction && m_CurrentProject == name && !HasUnsavedChanges() && IOTProjectFiles.Load(name+"_changed",savedChanges,error) && vector.Distance(savedChanges.Items[0].Position,changedPosition) < 0.001 && vector.Distance(m_ActiveScene.Items[0].GetPosition(),original.Items[0].Position) < 0.001, "save completes before opening the requested project")) return false;
        SelectItem(m_ActiveScene.Items[0]);
        Nudge(false,0,1);
        RequestProjectAction(open);
        UnsavedChoice(false);
        if (!TestCheck(!EditorModalPending() && !HasUnsavedChanges() && vector.Distance(m_ActiveScene.Items[0].GetPosition(),original.Items[0].Position) < 0.001, "discard opens the requested project without saving current edits")) return false;
        SelectItem(m_ActiveScene.Items[0]);
        Nudge(false,0,1);
        anchor = m_Anchor;
        SpawnSceneClass("Land_Wreck_hb01_aban1_blue",false);
        FinishAnchorReplacement(true);
        if (!TestCheck(UnsavedDialogOpen() && m_Anchor == anchor && m_PendingProjectAction.Kind == IOTProjectTransition.REPLACE_ANCHOR, "anchor replacement waits for the unsaved scene decision")) return false;
        CancelPendingProjectAction();
        if (!ApplyProject(original)) return false;
        m_CurrentProject = previousName;
        m_ProjectBaseline = previousBaseline;
        UpdateToolbar();
        array<string> files = {name,name+"_changed"};
        foreach (string file : files)
        {
            DeleteFile(IOTProjectFiles.Path(file));
            if (FileExist(IOTProjectFiles.Path(file)+".bak")) DeleteFile(IOTProjectFiles.Path(file)+".bak");
        }
        ClearError();
        return true;
    }

    protected bool SelfTestProjects()
    {
        IOTProjectData original = CaptureProject();
        string name = "__selftest_"+m_RunTag;
        string currentName = m_CurrentProject;
        Object oldAnchor = m_Anchor;
        ItemBase first = m_Item;
        SetProxyPose(ProxyPosition(),"15 10 25");
        if (!SpawnSceneClass("HatchbackWheel",true) || !SpawnSceneClass("Hammer",true)) return false;
        m_CameraMultiplier = 1.25;
        IOTProjectData expected = CaptureProject();
        if (!TestCheck(SaveProject(name) && FileExist(IOTProjectFiles.Path(name)) && IOTProjectFiles.Names().Find(name) >= 0, "projects save as discoverable JSON files in the profile")) return false;
        if (!TestCheck(m_NoticeKind == IOTNoticeKind.SUCCESS && m_NoticeMessage == IOTL.F("PROJECT_SAVED",name+".json") && m_ErrorRoot.IsVisible(), "project saving reports success in the standalone notification")) return false;
        IOTProjectData disk;
        string error;
        if (!TestCheck(IOTProjectFiles.Load(name,disk,error) && disk.Version == 1 && disk.WorldName == GetGame().GetWorldName() && disk.Items.Count() == 3 && disk.Items[0].Classname == disk.Items[1].Classname, "project JSON retains version world and duplicate item classes")) return false;
        m_CameraMultiplier = 2;
        if (!TestCheck(SaveProject(name) && JsonFileLoader<IOTProjectData>.LoadFile(IOTProjectFiles.Path(name)+".bak",disk,error) && disk.CameraSpeed == 1.25, "project overwrite retains the previous valid JSON as a backup")) return false;
        if (!TestCheck(!SaveProject("../escape") && !SaveProject("D:\\escape") && !IOTProjectFiles.ValidName(""), "project names cannot escape the project directory")) return false;
        ClearError();
        int count = m_CreatedItems.Count();
        IOTProjectData missing;
        string missingName = name+"_missing";
        if (!TestCheck(!IOTProjectFiles.Load(missingName,missing,error) && !missing && error == IOTL.F("PROJECT_NOT_FOUND",missingName+".json"), "missing project files return a localized message with the filename")) return false;
        if (!TestCheck(!LoadProject(missingName,true) && m_LastError == IOTL.F("PROJECT_NOT_FOUND",missingName+".json") && m_Anchor == oldAnchor, "project error notifications retain localized file errors without replacing the scene")) return false;
        if (!TestCheck(!LoadProject(name) && m_Anchor == oldAnchor && m_CreatedItems.Count() == count, "opening an existing scene requires explicit replacement confirmation")) return false;
        ClearError();
        ShowProjectDialog(false);
        m_ProjectName.SetText(name);
        ProjectAction();
        bool modal = ProjectDialogOpen() && m_ProjectConfirm == name && !WorldPoint(m_Viewport.Center()) && !StepHistory(false) && !BeginCameraHold(m_Viewport.Center());
        HandleKey(KeyCode.KC_F4);
        HandleKey(KeyCode.KC_ESCAPE);
        if (!TestCheck(modal && !ProjectDialogOpen() && !m_PlayerMode && m_Anchor == oldAnchor && m_CreatedItems.Count() == count, "project dialog blocks editor actions and Escape preserves the current scene")) return false;
        ShowProjectDialog(true);
        m_ProjectName.SetText(name);
        ProjectAction();
        bool overwrite = ProjectDialogOpen() && m_ProjectConfirm == name;
        CloseProjectDialog();
        if (!TestCheck(overwrite && IOTProjectFiles.Load(name,disk,error) && disk.CameraSpeed == 2, "save dialog requires confirmation before overwriting an existing project")) return false;
        disk.Version = 999;
        IOTProjectFiles.Save(name+"_future",disk,error);
        if (!TestCheck(!LoadProject(name+"_future",true) && m_Anchor == oldAnchor && m_CreatedItems.Count() == count, "unsupported project versions leave the scene unchanged")) return false;
        disk.Version = 1;
        disk.WorldName = "unavailable_world";
        IOTProjectFiles.Save(name+"_world",disk,error);
        if (!TestCheck(!LoadProject(name+"_world",true) && m_Anchor == oldAnchor, "projects for another world cannot replace the scene")) return false;
        disk.WorldName = GetGame().GetWorldName();
        disk.Items[0].Classname = "IOT_Missing_Project_Class";
        IOTProjectFiles.Save(name+"_class",disk,error);
        if (!TestCheck(!LoadProject(name+"_class",true) && m_Anchor == oldAnchor && m_CreatedItems.Count() == count, "missing project classes cannot partially replace the scene")) return false;
        disk.Items[0].Classname = oldAnchor.GetType();
        IOTProjectFiles.Save(name+"_stage",disk,error);
        if (!TestCheck(!LoadProject(name+"_stage",true) && m_Anchor == oldAnchor && m_CreatedItems.Count() == count && first, "failed native candidate validation preserves the complete old project")) return false;
        FileHandle malformed = OpenFile(IOTProjectFiles.Path(name+"_broken"),FileMode.WRITE);
        FPrint(malformed,"{broken");
        CloseFile(malformed);
        if (!TestCheck(!LoadProject(name+"_broken",true) && m_Anchor == oldAnchor, "malformed JSON reports failure without replacing the scene")) return false;
        if (!TestCheck(!IOTProjectFiles.Load(name+"_broken",missing,error) && !missing && error == IOTL.F("PROJECT_JSON_INVALID",name+"_broken.json"), "malformed project JSON returns localized text while parser details stay in the log")) return false;
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        EntityAI boots = player.FindAttachmentBySlotName("Feet");
        if (!TestCheck(LoadProject(name,true) && m_Anchor != oldAnchor && m_CreatedItems.Count() == 3 && m_ActiveScene.Items.Count() == 3 && m_Undo.Count() == 0 && m_Redo.Count() == 0, "confirmed project opening replaces the scene and clears transform history")) return false;
        if (!TestCheck(m_NoticeKind == IOTNoticeKind.SUCCESS && m_NoticeMessage == IOTL.F("PROJECT_OPENED",name+".json"), "project opening reports success after replacing the scene")) return false;
        bool poses = vector.Distance(m_Anchor.GetPosition(),expected.Anchor.Position) < 0.001;
        for (int i = 0; i < 3; i++)
        {
            ItemBase loaded = m_ActiveScene.Items[i];
            if (loaded.GetType() != expected.Items[i].Classname || vector.Distance(loaded.GetPosition(),expected.Items[i].Position) > 0.001 || vector.Distance(loaded.GetOrientation(),expected.Items[i].Orientation) > 0.001) poses = false;
        }
        if (!TestCheck(poses && m_Anchor.GetOrientation().Length() < 0.001 && Math.AbsFloat(m_Anchor.GetScale() - 1) < 0.0001, "project loading restores item positions rotations and the anchor CE constraints")) return false;
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        if (!TestCheck(vector.Distance(player.GetPosition(),expected.CharacterPosition) < 0.001 && player.FindAttachmentBySlotName("Feet") == boots && vector.Distance(camera.GetPosition(),expected.CameraPosition) < 0.001 && m_CameraMultiplier == 2, "project loading restores character camera and speed while preserving inventory")) return false;
        if (!TestCheck(ExportAnchor() && m_Item && GetGizmoApi().GetCount() == 1 && m_CreatedTray.Count() == 3, "opened projects support CE export scene selection and native gizmo editing")) return false;
        EnterPlayer();
        bool released = m_ProjectFrozen.Count() == 0;
        EnterEditor();
        if (!TestCheck(released && player.FindAttachmentBySlotName("Feet") == boots, "character mode releases loaded item simulation without changing equipment")) return false;
        IOTProjectData empty = CaptureProject();
        empty.Anchor = null;
        empty.Items.Clear();
        if (!TestCheck(ApplyProject(empty) && !m_Anchor && m_CreatedItems.Count() == 0 && m_CreatedTray.RowCount() == 1, "empty projects restore a character-only editor scene")) return false;
        if (!ApplyProject(original)) return false;
        m_CurrentProject = currentName;
        array<string> suffixes = {"","_future","_world","_class","_stage","_broken"};
        foreach (string suffix : suffixes)
        {
            string path = IOTProjectFiles.Path(name+suffix);
            if (FileExist(path)) DeleteFile(path);
            if (FileExist(path+".bak")) DeleteFile(path+".bak");
            if (FileExist(path+".tmp")) DeleteFile(path+".tmp");
        }
        ClearError();
        return true;
    }

    protected bool SelfTestNotifications(ItemBase wheel)
    {
        vector position = wheel.GetPosition();
        vector angles = wheel.GetOrientation();
        if (!TestCheck(!m_Root.FindAnyWidget("Status") && !m_Browser.Root().FindAnyWidget("SceneStatus"), "properties and catalog omit persistent hints and action result footers")) return false;
        ReportSuccess(IOTL.T("PROJECT_SAVE"));
        int successAccent = m_ErrorRoot.FindAnyWidget("ErrorAccent").GetColor();
        int until = m_NoticeUntil;
        if (!TestCheck(m_ErrorRoot.IsVisible() && m_NoticeKind == IOTNoticeKind.SUCCESS && m_LastError == "" && until > GetGame().GetTime() && m_Item == wheel && vector.Distance(wheel.GetPosition(),position) < 0.001, "success notifications preserve selection and use a timed independent widget")) return false;
        ClearError();
        UpdateNotificationAt(until - 1);
        bool stays = m_ErrorRoot.IsVisible();
        UpdateNotificationAt(until);
        if (!TestCheck(stays && !m_ErrorRoot.IsVisible(), "success notifications remain until their deadline and then disappear")) return false;
        ReportWarning(IOTL.T("ITEM_DROP_CANCELLED"));
        int warningAccent = m_ErrorRoot.FindAnyWidget("ErrorAccent").GetColor();
        float x,y,w,h;
        m_ErrorRoot.GetScreenPos(x,y); m_ErrorRoot.GetScreenSize(w,h);
        vector center = Vector(x+w*0.5,y+h*0.5,0);
        bool warning = warningAccent != successAccent && m_NoticeKind == IOTNoticeKind.WARNING && m_LastError == "" && ErrorContains(center) && !WorldPoint(center);
        OnClick(m_ErrorRoot.FindAnyWidget("ErrorClose"),0,0,0);
        if (!TestCheck(warning && !m_ErrorRoot.IsVisible() && m_Item == wheel, "warnings have a distinct accent block world clicks and close without deselecting")) return false;
        ReportError(IOTL.T("XML_FAILED"));
        int errorAccent = m_ErrorRoot.FindAnyWidget("ErrorAccent").GetColor();
        UpdateNotificationAt(GetGame().GetTime()+100000);
        bool persistent = m_ErrorRoot.IsVisible() && m_LastError == IOTL.T("XML_FAILED") && m_NoticeUntil == 0;
        ReportSuccess(IOTL.T("PROJECT_SAVE"));
        ClearError();
        if (!TestCheck(persistent && errorAccent != successAccent && errorAccent != warningAccent && m_ErrorRoot.IsVisible() && m_NoticeKind == IOTNoticeKind.SUCCESS && m_LastError == "", "errors persist while genuine success replaces them and normal edits preserve success")) return false;
        DismissNotification();
        if (!TestCheck(ExportAnchor() && m_NoticeKind == IOTNoticeKind.SUCCESS && m_NoticeMessage.Contains("XML") && Export() && m_NoticeMessage == IOTL.F("ITEM_XML_SAVED",wheel.GetType()) && vector.Distance(wheel.GetPosition(),position) < 0.001 && vector.Distance(wheel.GetOrientation(),angles) < 0.001, "anchor and item XML export report success without changing scene entities")) return false;
        DismissNotification();
        float browserX,browserY,browserWidth,browserHeight,listWidth,listHeight;
        m_Browser.Root().GetScreenPos(browserX,browserY); m_Browser.Root().GetScreenSize(browserWidth,browserHeight);
        m_CreatedTray.List().GetScreenSize(listWidth,listHeight);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        float scale = browserWidth/360;
        bool roomy = screenHeight - Math.Max(54,24*scale) - browserY >= 518*scale;
        bool rows = m_CreatedTray.VisibleRows() >= 1 && m_CreatedTray.VisibleRows() <= 10 && listHeight >= m_CreatedTray.VisibleRows()*24*scale - 1;
        if (roomy && m_CreatedTray.VisibleRows() < 8) rows = false;
        if (!TestCheck(rows, "scene list expands beyond four rows when space allows without shrinking row text")) return false;
        return true;
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

    protected bool SelfTestSurfaceFloor(ItemBase wheel, Widget button)
    {
        vector position = wheel.GetPosition()+"10 0 -10";
        float terrainY = GetGame().SurfaceY(position[0],position[2]);
        position[1] = terrainY+4;
        Object garage = GetGame().CreateObjectEx("Land_Garage_Row_Small",position,ECE_SETUP | ECE_CREATEPHYSICS | ECE_NOSURFACEALIGN | ECE_NOPERSISTENCY_WORLD,RF_IGNORE);
        if (!TestCheck(garage != null, "surface placement test creates an elevated garage")) return false;

        // Place the wheel a metre above a vanilla lootFloor point inside a bay.
        vector floorPoint = IOTLootVolumes.ModelPosition("-2.468829 -1.543565 -0.445114");
        position = garage.ModelToWorld(floorPoint+"0 1 0");
        wheel.SetPosition(position);
        vector hit,normal;
        bool found = FindPlacementSurface(position,hit,normal);
        OnClick(button,0,0,MouseState.LEFT);
        vector placed = wheel.GetPosition();
        GetGame().ObjectDelete(garage);
        if (!TestCheck(found && hit[1] > terrainY+1 && placed[1] < position[1] && placed[1] >= hit[1] && Math.AbsFloat(placed[0] - position[0]) < 0.001 && Math.AbsFloat(placed[2] - position[2]) < 0.001, "surface placement uses the floor below the item inside an elevated garage")) return false;

        position[1] = terrainY+120;
        wheel.SetPosition(position);
        int historyCount = m_Undo.Count();
        OnClick(button,0,0,MouseState.LEFT);
        bool accepted = TestCheck(vector.Distance(wheel.GetPosition(),position) < 0.001 && m_Undo.Count() == historyCount && m_NoticeKind == IOTNoticeKind.WARNING && m_ErrorRoot.IsVisible(), "surface placement without a nearby surface preserves pose and history and shows a warning");
        DismissNotification();
        return accepted;
    }

    protected bool SelfTestItemOperations(ItemBase wheel)
    {
        ClearHistory();
        int initialCount = m_ActiveScene.Items.Count();
        int initialCreated = m_CreatedItems.Count();
        Object anchor = m_Anchor;
        SelectMoveTarget(anchor,false);
        if (!TestCheck(!DeleteSelectedItem() && m_Undo.Count() == 0 && !m_Toolbar.FindAnyWidget("DeleteItem").IsVisible(), "item deletion excludes the anchor")) return false;
        SelectMoveTarget(GetGame().GetPlayer(),true);
        if (!TestCheck(!DeleteSelectedItem() && m_Undo.Count() == 0, "item deletion excludes the character")) return false;
        DeselectItem();
        if (!TestCheck(!DeleteSelectedItem() && m_Undo.Count() == 0, "item deletion without a selection changes nothing")) return false;
        if (!SpawnSceneClass("Hammer",true)) return false;
        ItemBase first = m_Item;
        vector initialPosition = first.GetPosition();
        vector initialAngles = first.GetOrientation();
        IOTHistoryItem identity = m_Undo[0].Item;
        if (!TestCheck(m_Undo.Count() == 1 && m_Undo[0].Kind == IOTHistoryKind.ITEM_CREATE && m_Toolbar.FindAnyWidget("DeleteItem").IsVisible(), "item creation records one undoable scene action")) return false;
        Nudge(false,0,1);
        m_RotFields[0].SetText("17");
        OnChange(m_RotFields[0],0,0,true);
        vector moved = first.GetPosition();
        vector rotated = first.GetOrientation();
        string proxy = ItemProxyLine(first);
        SetFocus(m_PosFields[0]);
        HandleKey(KeyCode.KC_DELETE);
        if (!TestCheck(m_Item == first && m_Undo.Count() == 3, "Delete in a text field preserves the selected scene item")) return false;
        SetFocus(null);
        m_Pointer = false;
        bool blockedFlight = !DeleteSelectedItem();
        m_Pointer = true;
        ShowProjectDialog(false);
        bool blockedModal = !DeleteSelectedItem();
        CloseProjectDialog();
        if (!TestCheck(blockedFlight && blockedModal && m_Item == first && m_Undo.Count() == 3, "flight and project dialogs block item deletion")) return false;
        if (!SpawnSceneClass("Hammer",true)) return false;
        ItemBase duplicate = m_Item;
        SelectItem(first);
        OnClick(m_Toolbar.FindAnyWidget("DeleteItem"),0,0,MouseState.LEFT);
        if (!TestCheck(!identity.Target && m_ActiveScene.Items.Count() == initialCount+1 && m_CreatedItems.Count() == initialCreated+1 && m_ActiveScene.Items.Find(duplicate) >= 0 && !SelectedObject() && GetGizmoApi().GetCount() == 0, "toolbar deletion removes only the selected duplicate and clears its gizmo")) return false;
        IOTProjectData deleted = CaptureProject();
        if (!TestCheck(deleted.Items.Count() == initialCount+1 && m_CreatedTray.ItemRow(duplicate) >= 0, "deleted items leave project and scene-list membership")) return false;
        IOTTransformEdit deletion = m_Undo[m_Undo.Count() - 1];
        deletion.Classname = "IOT_MissingHistoryClass";
        if (!TestCheck(!StepHistory(false) && m_Undo.Count() == 5 && m_Redo.Count() == 0 && !identity.Target && m_ActiveScene.Items.Find(duplicate) >= 0, "failed item restoration preserves the scene and history for retry")) return false;
        deletion.Classname = "Hammer";
        if (!TestCheck(StepHistory(false) && identity.Target && m_Item == identity.Target && m_Item.GetType() == "Hammer" && vector.Distance(m_Item.GetPosition(),moved) < 0.001 && vector.Distance(m_Item.GetOrientation(),rotated) < 0.001 && ProxyLine() == proxy && m_ActiveScene.Items[initialCount] == m_Item && m_CreatedItems[initialCreated] == m_Item, "Undo deletion restores classname pose export and original scene order")) return false;
        if (!TestCheck(CaptureProject().Items.Count() == initialCount+2 && GetGizmoApi().GetCount() == 1, "restored items rejoin projects and native selection")) return false;
        if (!TestCheck(StepHistory(false) && m_ActiveScene.Items.Count() == initialCount+1 && identity.Target && StepHistory(false) && vector.Distance(identity.Target.GetOrientation(),initialAngles) < 0.001 && StepHistory(false) && vector.Distance(identity.Target.GetPosition(),initialPosition) < 0.001, "older transforms follow the recreated item identity")) return false;
        if (!TestCheck(StepHistory(false) && !identity.Target && m_ActiveScene.Items.Count() == initialCount && m_CreatedItems.Count() == initialCreated && m_Undo.Count() == 0, "Undo creation removes the item after its later edits are undone")) return false;
        if (!TestCheck(StepHistory(true) && identity.Target && m_Item == identity.Target && vector.Distance(m_Item.GetPosition(),initialPosition) < 0.001 && StepHistory(true) && StepHistory(true) && ProxyLine() == proxy, "Redo creation restores the item and replays its original transform history")) return false;
        if (!TestCheck(StepHistory(true) && StepHistory(true) && !identity.Target && m_ActiveScene.Items.Count() == initialCount+1, "Redo deletion removes the restored item while retaining its duplicate")) return false;
        if (!StepHistory(false)) return false;
        HandleKey(KeyCode.KC_DELETE);
        if (!TestCheck(!identity.Target && m_Redo.Count() == 0 && m_ActiveScene.Items.Count() == initialCount+1, "Delete key removes the item and discards the previous redo branch")) return false;
        if (!SelectItem(m_ActiveScene.Items[initialCount]) || !DeleteSelectedItem()) return false;
        ClearHistory();
        SelectItem(wheel);
        ClearHistory();
        if (!TestCheck(m_Anchor == anchor && m_ActiveScene.Items.Count() == initialCount && m_CreatedItems.Count() == initialCreated && m_Item == wheel, "item operation cleanup preserves the anchor character and original layout")) return false;
        return true;
    }

    protected bool SelfTestHistory(ItemBase wheel)
    {
        FinishHistory();
        CancelWorldGesture();
        SetFocus(null);
        DeselectItem();
        SelectItem(wheel);
        ClearHistory();
        vector original[4];
        wheel.GetTransform(original);
        vector angles = wheel.GetOrientation();
        vector proxyPosition = ProxyPosition();
        vector proxyAngles = ProxyAngles();
        string proxy = ProxyLine();
        Object anchor = m_Anchor;
        vector anchorPosition = anchor.GetPosition();
        vector center = m_Viewport.Center();
        if (!TestCheck(!StepHistory(false) && !StepHistory(true) && (m_Toolbar.FindAnyWidget("Undo").GetFlags() & WidgetFlags.DISABLED) && (m_Toolbar.FindAnyWidget("Redo").GetFlags() & WidgetFlags.DISABLED), "empty history disables Undo and Redo")) return false;
        BeginWorldGesture(center);
        ApplyGizmoTransformAt(original,true,center);
        CancelWorldGesture();
        if (!TestCheck(m_Undo.Count() == 0 && !m_HistoryPending, "unchanged gizmo transforms do not create history")) return false;
        vector moved[4];
        copyarray(moved,original);
        BeginWorldGesture(center);
        moved[3] = original[3]+"0.1 0 0";
        ApplyGizmoTransformAt(moved,false,center);
        bool blockedDuringDrag = !StepHistory(false);
        moved[3] = original[3]+"0.2 0.1 0";
        ApplyGizmoTransformAt(moved,false,center);
        moved[3] = original[3]+"0.3 0.1 0";
        ApplyGizmoTransformAt(moved,true,center);
        CancelWorldGesture();
        if (!TestCheck(blockedDuringDrag && m_Undo.Count() == 1 && !m_HistoryPending, "a complete multi-frame gizmo drag creates one undo action")) return false;
        if (!TestCheck(StepHistory(false) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001 && ProxyLine() == proxy && m_Redo.Count() == 1, "Undo restores the initial item pose and CE proxy output")) return false;
        if (!TestCheck(StepHistory(true) && vector.Distance(wheel.GetPosition(),moved[3]) < 0.001 && m_Undo.Count() == 1, "Redo restores the full completed item move")) return false;
        StepHistory(false);
        Nudge(false,0,1);
        if (!TestCheck(m_Redo.Count() == 0 && m_Undo.Count() == 1 && !StepHistory(true), "new edits after Undo discard the redo branch")) return false;
        StepHistory(false);
        ClearHistory();
        m_PosFields[0].SetText(FieldNumber(proxyPosition[0]+0.1));
        OnChange(m_PosFields[0],0,0,false);
        m_PosFields[0].SetText(FieldNumber(proxyPosition[0]+0.3));
        OnChange(m_PosFields[0],0,0,false);
        vector typedPosition = wheel.GetPosition();
        m_PosFields[0].SetText("-");
        OnChange(m_PosFields[0],0,0,false);
        OnFocusLost(m_PosFields[0],0,0);
        if (!TestCheck(m_Undo.Count() == 1 && !m_HistoryPending && vector.Distance(wheel.GetPosition(),typedPosition) < 0.001 && StepHistory(false) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001, "live numeric typing groups valid edits and reverts incomplete text before Undo")) return false;
        ClearHistory();
        Widget plus = m_Root.FindAnyWidget("PosPlus0");
        OnMouseButtonDown(plus,0,0,MouseState.LEFT);
        NudgeButton(plus);
        NudgeButton(plus);
        OnMouseButtonUp(plus,0,0,MouseState.LEFT);
        OnClick(plus,0,0,MouseState.LEFT);
        if (!TestCheck(m_Undo.Count() == 1 && StepHistory(false) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001, "holding a fine adjustment button creates one undo action without a duplicate click")) return false;
        ClearHistory();
        m_RotFields[0].SetText(FieldNumber(proxyAngles[0]+15));
        OnChange(m_RotFields[0],0,0,true);
        vector rotated = wheel.GetOrientation();
        if (!TestCheck(m_Undo.Count() == 1 && StepHistory(false) && vector.Distance(wheel.GetOrientation(),angles) < 0.001 && StepHistory(true) && vector.Distance(wheel.GetOrientation(),rotated) < 0.001 && vector.Distance(wheel.GetPosition(),original[3]) < 0.001, "Undo and Redo restore item rotation without moving it")) return false;
        ClearHistory();
        ResetComponent(true,0);
        if (!TestCheck(m_Undo.Count() == 1 && StepHistory(false) && vector.Distance(wheel.GetOrientation(),rotated) < 0.001, "individual angle resets can be undone")) return false;
        ClearHistory();
        Reset();
        if (!TestCheck(m_Undo.Count() == 1 && StepHistory(false) && vector.Distance(wheel.GetOrientation(),rotated) < 0.001 && StepHistory(true) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001 && vector.Distance(wheel.GetOrientation(),angles) < 0.001, "F9 reset is an undoable transform rather than clearing history")) return false;
        ClearHistory();
        SetProxyPose(proxyPosition+"0 1 0",proxyAngles);
        vector beforeGround = wheel.GetPosition();
        Widget place = m_Toolbar.FindAnyWidget("PlaceOnSurface");
        OnClick(place,0,0,MouseState.LEFT);
        vector onGround[4];
        wheel.GetTransform(onGround);
        vector ground = beforeGround;
        ground[1] = GetGame().SurfaceY(ground[0],ground[2]);
        vector wheelBounds[2];
        bool hasWheelCollision = wheel.GetCollisionBox(wheelBounds);
        vector size = wheelBounds[1] - wheelBounds[0];
        float lowest = Math.Min(wheel.ModelToWorld(wheelBounds[0])[1],wheel.ModelToWorld(wheelBounds[1])[1]);
        if (!TestCheck(hasWheelCollision && size[0] < 0.5*Math.Min(size[1],size[2]) && Math.AbsFloat(onGround[3][0] - ground[0]) < 0.001 && Math.AbsFloat(onGround[3][2] - ground[2]) < 0.001 && Math.AbsFloat(onGround[0][1]) > 0.999 && Math.AbsFloat(lowest - ground[1] - 0.003) < 0.002, "surface placement lays the wheel flat on terrain without changing X/Z")) return false;
        OnClick(place,0,0,MouseState.LEFT);
        if (!TestCheck(m_Undo.Count() == 1 && StepHistory(false) && vector.Distance(wheel.GetPosition(),beforeGround) < 0.001 && vector.Distance(wheel.GetOrientation(),angles) < 0.001, "ground placement can be undone with its original orientation")) return false;
        bool redone = StepHistory(true);
        vector afterRedo[4];
        wheel.GetTransform(afterRedo);
        if (!TestCheck(redone && vector.Distance(afterRedo[3],onGround[3]) < 0.001 && vector.Dot(afterRedo[0],onGround[0]) > 0.9999 && vector.Dot(afterRedo[2],onGround[2]) > 0.9999, "surface placement supports Redo and repeated clicks do not add edits")) return false;
        if (!SelfTestSurfaceFloor(wheel,place)) return false;
        wheel.SetTransform(original);
        ClearHistory();
        BeginWorldGesture(center);
        ApplyGizmoTransformAt(moved,false,center);
        vector outside = m_Viewport.Origin() - "2 0 0";
        ApplyGizmoTransformAt(original,false,outside);
        if (!TestCheck(m_Undo.Count() == 1 && !m_HistoryPending && StepHistory(false) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001, "boundary-cancelled gizmo drags retain one undoable final placement")) return false;
        ClearHistory();
        Nudge(false,0,1);
        if (!SpawnSceneClass("Hammer",true)) return false;
        ItemBase other = m_Item;
        vector otherPosition = other.GetPosition();
        Nudge(false,2,1);
        DeselectItem();
        if (!TestCheck(m_Undo.Count() == 3 && StepHistory(false) && m_Item == other && vector.Distance(other.GetPosition(),otherPosition) < 0.001 && StepHistory(false) && m_CreatedItems.Find(other) < 0 && StepHistory(false) && m_Item == wheel && vector.Distance(wheel.GetPosition(),original[3]) < 0.001 && GetGizmoApi().GetCount() == 1, "history spans selection changes and restores the exact affected entity")) return false;
        // Restore the temporary item for the remaining inventory/ownership checks.
        StepHistory(true);
        StepHistory(true);
        other = m_Item;
        wheel.SetTransform(original);
        ClearHistory();
        SelectMoveTarget(anchor,false);
        Nudge(false,0,1);
        if (!TestCheck(StepHistory(false) && vector.Distance(anchor.GetPosition(),anchorPosition) < 0.001 && StepHistory(true) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001 && vector.Distance(other.GetPosition(),otherPosition) < 0.001 && anchor.GetOrientation().Length() < 0.001, "anchor history moves only the anchor and leaves loot in place")) return false;
        StepHistory(false);
        ClearHistory();
        Man player = GetGame().GetPlayer();
        vector playerPosition = player.GetPosition();
        SelectMoveTarget(player,true);
        Nudge(false,1,1);
        if (!TestCheck(StepHistory(false) && vector.Distance(player.GetPosition(),playerPosition) < 0.001 && StepHistory(true) && vector.Distance(anchor.GetPosition(),anchorPosition) < 0.001 && vector.Distance(wheel.GetPosition(),original[3]) < 0.001, "character history changes only character position")) return false;
        StepHistory(false);
        SelectItem(wheel);
        ClearHistory();
        Nudge(false,0,1);
        UpdateCameraHold(false,true,center,false);
        BeginCameraHold(center);
        bool blockedInFlight = !StepHistory(false) && m_Undo.Count() == 1;
        EndCameraHold();
        EnterPlayer();
        bool blockedAsPlayer = !StepHistory(false) && m_Undo.Count() == 1;
        EnterEditor();
        SelectItem(wheel);
        if (!TestCheck(blockedInFlight && blockedAsPlayer && StepHistory(false) && vector.Distance(wheel.GetPosition(),original[3]) < 0.001, "camera and character modes block history without losing completed edits")) return false;
        ClearHistory();
        SelectItem(other);
        Nudge(false,0,1);
        DeselectItem();
        m_ActiveScene.Items.RemoveItem(other);
        m_CreatedItems.RemoveItem(other);
        if (!TestCheck(!StepHistory(false) && m_Undo.Count() == 0 && vector.Distance(other.GetPosition(),otherPosition) > 0.001, "history discards entities that no longer belong to the editable scene")) return false;
        GetGame().ObjectDelete(other);
        SelectItem(wheel);
        ClearHistory();
        for (int step = 0; step < 105; step++) Nudge(false,0,1);
        if (!TestCheck(m_Undo.Count() == 100, "transform history retains the most recent 100 completed actions")) return false;
        for (int back = 0; back < 100; back++) if (!StepHistory(false)) return false;
        if (!TestCheck(m_Undo.Count() == 0 && m_Redo.Count() == 100 && !StepHistory(false), "bounded history can undo every retained action without replay entries")) return false;
        ClearHistory();
        wheel.SetTransform(original);
        DeselectItem();
        SelectItem(wheel);
        ClearHistory();
        RefreshCreatedItems(true);
        ClearError();
        return true;
    }

    protected bool SelfTestCameraHold(ItemBase wheel)
    {
        vector center = m_Viewport.Center();
        vector panel = m_Viewport.Origin() - "2 0 0";
        vector savedPosition = wheel.GetPosition();
        vector savedAngles = wheel.GetOrientation();
        vector cameraPose[4];
        FreeDebugCamera camera = FreeDebugCamera.GetInstance();
        camera.GetTransform(cameraPose);
        UpdateCameraHold(false,true,center,false);
        HandleKey(KeyCode.KC_F1);
        if (!TestCheck(m_Pointer && !m_CameraHeld && !m_Toolbar.FindAnyWidget("CameraMode"), "camera hold replaces the F1 toggle and toolbar camera button")) return false;
        UpdateCameraHold(true,true,panel,false);
        UpdateCameraHold(true,true,center,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld, "RMB pressed on a panel cannot start flight by moving into the world")) return false;
        UpdateCameraHold(false,true,center,false);
        UpdateCameraHold(true,true,center,false);
        if (!TestCheck(m_CameraHeld && !m_Pointer && !Gizmo_IsSupported() && GetGizmoApi().GetCount() == 0 && m_Item == wheel && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.001, "camera hold suspends gizmo without changing selection or item pose")) return false;
        vector transform[4];
        wheel.GetTransform(transform);
        transform[3] = transform[3]+"1 0 0";
        UpdateCameraHold(true,true,panel,false);
        HandleKey(KeyCode.KC_F1);
        if (!TestCheck(m_CameraHeld && !m_Pointer && !ApplyGizmoTransformAt(transform,false,center) && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001, "captured camera ignores hidden cursor bounds and blocks item transforms")) return false;
        UpdateCameraHold(false,true,panel,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld && !m_SpeedRoot.IsVisible() && m_Item == wheel && GetGizmoApi().GetCount() == 1 && !m_ClickPending && vector.Distance(camera.GetPosition(),cameraPose[3]) < 0.001, "RMB release restores cursor gizmo and hides multiplier without a world click")) return false;
        UpdateCameraHold(true,true,center,true);
        UpdateCameraHold(true,true,center,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld, "held left mouse blocks camera capture until a fresh RMB press")) return false;
        UpdateCameraHold(false,true,center,false);
        BeginWorldGesture(center);
        UpdateCameraHold(true,true,center,false);
        CancelWorldGesture();
        UpdateCameraHold(true,true,center,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld, "RMB cannot hijack a world selection or gizmo gesture")) return false;
        UpdateCameraHold(false,true,center,false);
        UpdateCameraHold(true,true,center,false);
        UpdateCameraHold(true,false,center,false);
        UpdateCameraHold(true,true,center,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld && m_CameraBlockedUntilRelease && GetGizmoApi().GetCount() == 1, "camera context loss cancels flight and requires release before recapture")) return false;
        UpdateCameraHold(false,true,center,false);
        UpdateCameraHold(true,true,center,false);
        if (!TestCheck(m_CameraHeld && !m_Pointer, "fresh RMB press restores flight after context recovery")) return false;
        m_Viewport.Show(false);
        UpdateCameraHold(true,CameraContextActive(),center,false);
        UpdateViewport();
        UpdateCameraHold(true,CameraContextActive(),center,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld && m_Viewport.IsVisible(), "hiding the world viewport cancels capture without resuming on restore")) return false;
        UpdateCameraHold(false,true,center,false);
        UpdateCameraHold(true,true,center,false);
        EnterPlayer();
        UpdateCameraHold(true,CameraContextActive(),center,false);
        if (!TestCheck(m_PlayerMode && !m_CameraHeld && !camera.IsActive(), "character mode cancels camera capture and leaves ordinary player controls")) return false;
        EnterEditor();
        SelectItem(wheel);
        UpdateCameraHold(true,CameraContextActive(),center,false);
        if (!TestCheck(m_Pointer && !m_CameraHeld && m_Item == wheel && GetGizmoApi().GetCount() == 1, "returning from character mode with held RMB cannot recapture camera")) return false;
        UpdateCameraHold(false,true,center,false);
        camera.SetTransform(cameraPose);
        return true;
    }

    protected bool SelfTestLootVolumes(ItemBase wheel)
    {
        if (!TestCheck(!m_LootVolumes.Enabled() && m_LootVolumes.ShapeCount() == 0, "standard loot overlay starts hidden without creating scene objects")) return false;
        int itemCount = m_CreatedItems.Count();
        int sceneCount = m_Scenes.Count();
        string proxy = ProxyLine();
        OnClick(m_Toolbar.FindAnyWidget("LootVolumes"),0,0,0);
        PrintToRPT("[PROXY LOOT TEST] enabled="+m_LootVolumes.Enabled().ToString()+" readable="+m_LootVolumes.Readable().ToString()+" known="+m_LootVolumes.Known().ToString()+" points="+m_LootVolumes.Count().ToString()+" shapes="+m_LootVolumes.ShapeCount().ToString());
        if (!TestCheck(m_LootVolumes.Enabled() && m_LootVolumes.Known() && m_LootVolumes.Count() == 8 && m_LootVolumes.ShapeCount() == 64 && m_Toolbar.FindAnyWidget("LootVolumesActive").IsVisible(), "overlay toolbar toggle shows eight vanilla wreck points and translucent volumes")) return false;
        IOTLootPoint point = m_LootVolumes.Point(0);
        if (!TestCheck(vector.Distance(point.Position,"-0.514923 -0.683249 -0.580811") < 0.00001 && Math.AbsFloat(point.Range - 0.1) < 0.00001 && Math.AbsFloat(point.Height - 0.25) < 0.00001 && point.ContainerName == "lootFloor", "wreck point positions radius height and container match the official CE source")) return false;
        vector model = IOTLootVolumes.ModelPosition("2 3 4");
        if (!TestCheck(vector.Distance(model,"-4 3 2") < 0.00001 && vector.Distance(IOTLootVolumes.WorldPosition(m_Anchor,point.Position),m_Anchor.ModelToWorld(Vector(-point.Position[2],point.Position[1],point.Position[0]))) < 0.00001, "standard point coordinates use the calibrated CE to model basis")) return false;
        vector anchorPosition = m_Anchor.GetPosition();
        vector before = IOTLootVolumes.WorldPosition(m_Anchor,point.Position);
        m_Anchor.SetPosition(anchorPosition+"2 1 -3");
        m_LootVolumes.Update(m_Anchor,m_LootMap,true);
        bool follows = vector.Distance(IOTLootVolumes.WorldPosition(m_Anchor,point.Position),before+"2 1 -3") < 0.0001 && m_LootVolumes.ShapeCount() == 64;
        m_Anchor.SetPosition(anchorPosition);
        m_LootVolumes.Update(m_Anchor,m_LootMap,true);
        if (!TestCheck(follows && m_Item == wheel && proxy == ProxyLine() && itemCount == m_CreatedItems.Count() && sceneCount == m_Scenes.Count(), "overlay follows anchor translation while preserving items selection and proxy XML")) return false;
        m_LootVolumes.Update(m_Anchor,m_LootMap,false);
        bool hidden = m_LootVolumes.Enabled() && m_LootVolumes.ShapeCount() == 0;
        m_LootVolumes.Update(m_Anchor,m_LootMap,true);
        if (!TestCheck(hidden && m_LootVolumes.ShapeCount() == 64, "hidden editor contexts remove shapes and restore the same overlay preference")) return false;
        ToggleLootVolumes();
        if (!TestCheck(!m_LootVolumes.Enabled() && m_LootVolumes.ShapeCount() == 0 && m_Item == wheel && GetGizmoApi().GetCount() == 1, "disabling standard loot volumes destroys shapes without changing native gizmo selection")) return false;

        Object garage = GetGame().CreateObjectEx("Land_Garage_Row_Small",anchorPosition+"30 0 0",ECE_SETUP | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD,RF_IGNORE);
        Object office = GetGame().CreateObjectEx("Land_Office2",anchorPosition+"60 0 0",ECE_SETUP | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD,RF_IGNORE);
        if (!TestCheck(garage && office, "official garage and office anchors are available for reference validation")) return false;
        IOTLootVolumes sampleVolumes = new IOTLootVolumes;
        sampleVolumes.Enable(true);
        bool maps = true;
        for (int mapIndex = 1; mapIndex <= 4; mapIndex++)
        {
            sampleVolumes.Update(garage,mapIndex,true);
            if (!sampleVolumes.Known() || sampleVolumes.SourceMap() != mapIndex || sampleVolumes.Count() != 64 || sampleVolumes.IncompleteCount() != 0 || sampleVolumes.ShapeCount() != 512) maps = false;
        }
        if (!TestCheck(maps, "garage reference includes all 64 container points on each of the four maps")) return false;
        sampleVolumes.Update(office,1,true);
        bool chernarus = sampleVolumes.Count() == 122 && sampleVolumes.IncompleteCount() == 0;
        sampleVolumes.Update(office,3,true);
        if (!TestCheck(chernarus && sampleVolumes.Count() == 94 && sampleVolumes.IncompleteCount() == 1 && sampleVolumes.SourceMap() == 3, "different map prototypes remain separate and unspecified dimensions stay explicit")) return false;
        if (!TestCheck(sampleVolumes.Detail().Contains(IOTL.T("LOOT_DIMENSIONS_UNSPECIFIED")) && !sampleVolumes.Detail().Contains("#STR_IOT_"), "reference source and incomplete dimension help use localized text")) return false;
        sampleVolumes.Reset();
        if (!TestCheck(sampleVolumes.ShapeCount() == 0 && sampleVolumes.Count() == 0 && !sampleVolumes.Known(), "replacing or clearing an anchor removes all previous reference geometry and data")) return false;
        GetGame().ObjectDelete(garage);
        GetGame().ObjectDelete(office);
        int oldMap = m_LootMap;
        m_LootMap = 3;
        IOTProjectData data = CaptureProject();
        string error;
        bool saved = IOTProjectFiles.Save("__selftest_loot_source",data,error);
        IOTProjectData loaded;
        bool opened = IOTProjectFiles.Load("__selftest_loot_source",loaded,error);
        m_LootMap = oldMap;
        if (!TestCheck(saved && opened && loaded.LootMap == 3 && loaded.Items.Count() == data.Items.Count(), "projects retain the selected official loot map without serializing overlay shapes")) return false;
        loaded.LootMap = 5;
        bool rejected = !ValidateProject(loaded);
        loaded.LootMap = 0;
        if (!TestCheck(rejected && ValidateProject(loaded) && itemCount == m_CreatedItems.Count() && m_Item == wheel, "project loot map validation accepts legacy auto and rejects invalid sources without scene changes")) return false;
        DismissNotification();
        return true;
    }

    protected bool SelfTestIconToolbar(ItemBase wheel)
    {
        array<string> names = IOTToolbarChrome.Actions();
        bool icons = true;
        foreach (string name : names)
        {
            ButtonWidget button = ButtonWidget.Cast(m_Toolbar.FindAnyWidget(name));
            CanvasWidget icon = CanvasWidget.Cast(button.FindAnyWidget(name+"Icon"));
            string label;
            button.GetText(label);
            float iconButtonWidth,iconButtonHeight;
            button.GetScreenSize(iconButtonWidth,iconButtonHeight);
            if (!icon || !(icon.GetFlags() & WidgetFlags.IGNOREPOINTER) || label != "" || Math.AbsFloat(iconButtonWidth - 40*m_PanelScale) > 0.1 || Math.AbsFloat(iconButtonHeight - iconButtonWidth) > 0.1) icons = false;
        }
        if (!TestCheck(icons && names.Count() == 14, "toolbar actions use square vector icons without duplicate button labels")) return false;
        int separators;
        for (int i = 1; i < 5; i++) if (m_Toolbar.FindAnyWidget("ToolsSeparator"+i.ToString()).IsVisible()) separators++;
        if (!TestCheck(separators == 4 && ToolbarHeadingsFit(), "toolbar categories have centered readable headings above their icons and four separators")) return false;
        DeselectItem();
        bool hiddenGroup = !m_Toolbar.FindAnyWidget("MoveMode").IsVisible() && !m_Toolbar.FindAnyWidget("RotateMode").IsVisible() && !m_Toolbar.FindAnyWidget("ToolsSeparator2").IsVisible() && !m_Toolbar.FindAnyWidget("ToolsHeading2").IsVisible();
        SelectItem(wheel);
        if (!TestCheck(hiddenGroup && m_Toolbar.FindAnyWidget("ToolsSeparator2").IsVisible() && m_Toolbar.FindAnyWidget("ToolsHeading2").IsVisible(), "hidden editing actions leave no orphan category heading or separator")) return false;
        float narrowWidth = 230*m_PanelScale;
        float narrowHeight = m_ToolbarChrome.Layout(narrowWidth,m_PanelScale);
        m_Toolbar.SetScreenSize(narrowWidth,narrowHeight);
        float rootX,rootY;
        m_Toolbar.GetScreenPos(rootX,rootY);
        bool wrapped = narrowHeight > 78*m_PanelScale && ToolbarHeadingsFit();
        for (int group = 0; group < 5; group++)
        {
            float groupY = -1;
            for (int entry = 0; entry < names.Count(); entry++)
            {
                if (IOTToolbarChrome.GroupIndex(entry) != group) continue;
                Widget member = m_Toolbar.FindAnyWidget(names[entry]);
                float ax,ay,aw,ah;
                member.GetScreenPos(ax,ay); member.GetScreenSize(aw,ah);
                if (groupY < 0) groupY = ay;
                if (Math.AbsFloat(ay - groupY) > 0.1 || ax < rootX || ax+aw > rootX+narrowWidth+0.1 || ay+ah > rootY+narrowHeight+0.1) wrapped = false;
                if (group > 0 && Math.AbsFloat(ax - rootX - 8*m_PanelScale) < 0.1 && m_Toolbar.FindAnyWidget("ToolsSeparator"+group.ToString()).IsVisible()) wrapped = false;
            }
        }
        UpdateToolbar();
        UpdateViewport();
        if (!TestCheck(wrapped, "narrow toolbar layouts wrap whole categories without leading separators")) return false;
        Widget move = m_Toolbar.FindAnyWidget("MoveMode");
        float x,y,w,h;
        move.GetScreenPos(x,y); move.GetScreenSize(w,h);
        vector point = Vector(x+w*0.5,y+h*0.5,0);
        vector position = wheel.GetPosition();
        m_ToolbarChrome.HideHint();
        m_ToolbarChrome.HoverAt(point,true);
        bool delayed = !m_ToolbarChrome.HintRoot().IsVisible();
        m_ToolbarChrome.HoverAt(point,true,true);
        Widget hint = m_ToolbarChrome.HintRoot();
        float hx,hy,hw,hh;
        hint.GetScreenPos(hx,hy); hint.GetScreenSize(hw,hh);
        int screenWidth,screenHeight;
        GetScreenSize(screenWidth,screenHeight);
        string moveHint = IOTToolbarChrome.HintText("MoveMode");
        bool readable = delayed && hint.IsVisible() && hx >= 0 && hy >= 0 && hx+hw <= screenWidth && hy+hh <= screenHeight && moveHint == IOTL.T("MOVE") && !moveHint.Contains(IOTL.T("TOOLS_EDIT")) && moveHint.Contains("F7");
        if (!TestCheck(readable && m_Item == wheel && vector.Distance(wheel.GetPosition(),position) < 0.001, "toolbar hover shows only the localized action and shortcut without duplicating its heading")) return false;
        if (!TestCheck(m_ToolbarChrome.ContainsHint(Vector(hx+hw*0.5,hy+hh*0.5,0)) && PanelPoint(Vector(hx+hw*0.5,hy+hh*0.5,0)), "visible toolbar hints block world input through their bounds")) return false;
        m_ToolbarChrome.HoverAt(point,false,true);
        bool blocked = !hint.IsVisible();
        Widget undo = m_Toolbar.FindAnyWidget("Undo");
        undo.Enable(false);
        undo.GetScreenPos(x,y); undo.GetScreenSize(w,h);
        point = Vector(x+w*0.5,y+h*0.5,0);
        m_ToolbarChrome.HoverAt(point,true,true);
        bool disabledHint = hint.IsVisible() && m_ToolbarChrome.ActionAt(point) == "Undo" && IOTToolbarChrome.HintText("Undo").Contains("Ctrl+Z");
        m_ToolbarChrome.HoverAt("-1 -1 0",true,true);
        UpdateHistoryButtons();
        if (!TestCheck(blocked && disabledHint && !hint.IsVisible(), "toolbar hints explain disabled actions and disappear when hover is disallowed or leaves")) return false;
        Widget cameraHelp = m_Toolbar.FindAnyWidget("CameraHelp");
        Widget cameraHelpActive = m_Toolbar.FindAnyWidget("CameraHelpActive");
        OnClick(cameraHelp,0,0,MouseState.LEFT);
        m_ToolbarChrome.HoverAt("-1 -1 0",true,true);
        hint.GetScreenPos(hx,hy);
        hint.GetScreenSize(hw,hh);
        MultilineTextWidget cameraText = MultilineTextWidget.Cast(hint.FindAnyWidget("ToolbarHintText"));
        int textWidth,textHeight;
        cameraText.GetTextSize(textWidth,textHeight);
        bool fits = hx >= 0 && hy >= 0 && hx+hw <= screenWidth && hy+hh <= screenHeight && textHeight > 80*m_PanelScale && textHeight <= hh;
        if (!TestCheck(hint.IsVisible() && cameraHelpActive.IsVisible() && fits && !WorldPoint(Vector(hx+hw/2,hy+hh/2,0)) && m_Item == wheel && !m_CameraHeld && vector.Distance(wheel.GetPosition(),position) < 0.001, "camera help stays open after pointer departure and fits without changing the scene")) return false;
        OnClick(cameraHelp,0,0,MouseState.LEFT);
        if (!TestCheck(!hint.IsVisible() && !cameraHelpActive.IsVisible(), "camera help closes on the next click")) return false;
        OnClick(cameraHelp,0,0,MouseState.LEFT);
        bool worldGesture = BeginWorldGesture(m_Viewport.Center());
        CancelWorldGesture();
        if (!TestCheck(worldGesture && !hint.IsVisible() && !cameraHelpActive.IsVisible(), "returning to world editing closes camera help")) return false;
        return true;
    }

    protected bool ToolbarHeadingsFit()
    {
        array<string> names = IOTToolbarChrome.Actions();
        for (int group = 0; group < 5; group++)
        {
            TextWidget heading = TextWidget.Cast(m_Toolbar.FindAnyWidget("ToolsHeading"+group.ToString()));
            float left = 100000;
            float right = -100000;
            float top = 100000;
            foreach (int index, string name : names)
            {
                Widget button = m_Toolbar.FindAnyWidget(name);
                if (IOTToolbarChrome.GroupIndex(index) != group || !button.IsVisible()) continue;
                float bx,by,bw,bh;
                button.GetScreenPos(bx,by); button.GetScreenSize(bw,bh);
                left = Math.Min(left,bx);
                right = Math.Max(right,bx+bw);
                top = Math.Min(top,by);
            }
            if (left > right) { if (heading.IsVisible()) return false; continue; }
            float x,y,w,h;
            heading.GetScreenPos(x,y); heading.GetScreenSize(w,h);
            int textWidth,textHeight;
            heading.GetTextSize(textWidth,textHeight);
            if (!heading.IsVisible() || !(heading.GetFlags() & WidgetFlags.IGNOREPOINTER) || textWidth <= 0 || textWidth > w || textHeight > h || y+h > top || Math.AbsFloat(x+w*0.5 - (left+right)*0.5) > 1) return false;
        }
        return true;
    }

    protected bool SelfTestToolbar(ItemBase wheel)
    {
        UpdateToolbar();
        UpdateViewport();
        if (!SelfTestIconToolbar(wheel)) return false;
        float toolbarX,toolbarY,toolbarWidth,toolbarHeight;
        m_Toolbar.GetScreenPos(toolbarX,toolbarY);
        m_Toolbar.GetScreenSize(toolbarWidth,toolbarHeight);
        vector worldOrigin = m_Viewport.Origin();
        bool fits = toolbarY+toolbarHeight < worldOrigin[1];
        array<string> names = IOTToolbarChrome.Actions();
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
        if (!TestCheck(ToolbarPoint(point) && PanelPoint(point) && !WorldPoint(point) && !BeginCameraHold(point) && m_Pointer && m_Item == wheel, "toolbar input preserves selection and cannot select the world or enter camera flight")) return false;
        vector savedPosition = wheel.GetPosition();
        vector savedAngles = wheel.GetOrientation();
        if (!SelfTestCameraHold(wheel)) return false;
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
        m_Debug.GetScreenPos(footerX,footerY);
        m_Root.GetScreenSize(expandedWidth,expandedHeight);
        if (!TestCheck(footerY >= fineY+fineHeight && expandedHeight > collapsedHeight, "expanded fine settings keep content inside the properties panel")) return false;
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
        if (!TestCheck(m_PosFields[0].IsVisible() && !m_RotFields[0].IsVisible() && m_Root.FindAnyWidget("PositionTitle").IsVisible() && !m_Root.FindAnyWidget("RotationTitle").IsVisible() && m_Root.FindAnyWidget("MoveStep").IsVisible() && !m_Root.FindAnyWidget("AngleStep").IsVisible() && m_Root.FindAnyWidget("PosPlus0").IsVisible() && !m_Root.FindAnyWidget("RotPlus0").IsVisible() && m_Toolbar.FindAnyWidget("PlaceOnSurface").IsVisible(), "move mode shows only position and movement fine controls")) return false;
        OnClick(m_Toolbar.FindAnyWidget("RotateMode"),0,0,0);
        if (!TestCheck(!m_PosFields[0].IsVisible() && m_RotFields[0].IsVisible() && !m_Root.FindAnyWidget("PositionTitle").IsVisible() && m_Root.FindAnyWidget("RotationTitle").IsVisible() && !m_Root.FindAnyWidget("MoveStep").IsVisible() && m_Root.FindAnyWidget("AngleStep").IsVisible() && !m_Root.FindAnyWidget("PosPlus0").IsVisible() && m_Root.FindAnyWidget("RotPlus0").IsVisible() && m_Toolbar.FindAnyWidget("PlaceOnSurface").IsVisible() && vector.Distance(wheel.GetPosition(),savedPosition) < 0.001 && vector.Distance(wheel.GetOrientation(),savedAngles) < 0.001, "rotate mode shows only angles and angular fine controls without moving the item")) return false;
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
        vector characterBeforeMove = GetGame().GetPlayer().GetPosition();
        vector characterFacingBeforeMove = GetGame().GetPlayer().GetOrientation();
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
        if (!TestCheck(vector.Distance(GetGame().GetPlayer().GetPosition(),characterBeforeMove) < 0.001 && vector.Distance(GetGame().GetPlayer().GetOrientation(),characterFacingBeforeMove) < 0.001, "moving an existing anchor preserves the manually placed character pose")) return false;
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
        int previewLayer = m_Browser.HoverRoot().GetSort();
        if (!TestCheck(previewLayer == 0 && m_Viewport.BackdropPart(0).GetSort() < previewLayer && m_ToolbarChrome.HintRoot().GetSort() > previewLayer, "item preview keeps its native render layer between the backdrop and toolbar hints")) return false;
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
        if (!TestCheck(SelfTestCatalogWheel(), "Items wheel scrolls two rows per step without changing selection")) return false;
        int akmRow = m_Browser.ClassRow("AKM");
        float rowWidth,rowHeight;
        m_Browser.ItemRowWidget(0).GetScreenSize(rowWidth,rowHeight);
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
        UpdateCameraHold(false,true,m_Viewport.Center(),false);
        BeginCameraHold(m_Viewport.Center());
        bool flightCleared = !m_Browser.HoverEntity() && !m_Browser.HoverRoot().IsVisible();
        EndCameraHold();
        if (!TestCheck(flightCleared, "entering camera flight immediately releases the hover preview")) return false;
        m_Browser.SetMode(false);
        return true;
    }

    protected bool SelfTestCatalogWheel()
    {
        ScrollWidget scroll = m_Browser.ItemScroll();
        string selectedClass = m_Browser.SelectedDragClass();
        scroll.VScrollToPos(0);
        scroll.Update();
        Widget row = m_Browser.ItemRowWidget(0);
        float width,height,x,startY,scrolledY,restoredY;
        row.GetScreenSize(width,height);
        row.GetScreenPos(x,startY);
        bool down = m_Browser.OnMouseWheel(row,0,0,-1);
        row.GetScreenPos(x,scrolledY);
        bool up = m_Browser.OnMouseWheel(row,0,0,1);
        row.GetScreenPos(x,restoredY);
        return down && up && Math.AbsFloat(startY - scrolledY - 2*height) < 1 && Math.AbsFloat(restoredY - startY) < 1 && m_Browser.SelectedDragClass() == selectedClass;
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
        if (!TestCheck(!BeginCameraHold(drop) && m_Pointer && m_CatalogPressed && m_CatalogDragRoot.IsVisible() && m_CreatedItems.Count() == before+1, "RMB cannot hijack an active catalog drag")) return false;
        CancelCatalogDrag();
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
        bool hasMenu = GetGame().GetUIManager().GetMenu() != null;
        bool hasHeldButton = m_HeldButton != null;
        bool centerWorld;
        if (m_Viewport) centerWorld = WorldPoint(m_Viewport.Center());
        PrintToRPT("[PROXY SELFTEST CONTEXT] appActive="+GetGame().IsAppActive().ToString()+" menu="+hasMenu.ToString()+" cameraContext="+CameraContextActive().ToString()+" pointer="+m_Pointer.ToString()+" cameraHeld="+m_CameraHeld.ToString()+" blocked="+m_CameraBlockedUntilRelease.ToString()+" leftWasDown="+m_MouseWasDown.ToString()+" clickPending="+m_ClickPending.ToString()+" catalogPressed="+m_CatalogPressed.ToString()+" heldButton="+hasHeldButton.ToString()+" centerWorld="+centerWorld.ToString());
        GetGame().RequestExit(1);
        return false;
    }

    void Tick()
    {
        UpdateNotificationAt(GetGame().GetTime());
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
            bool hoverEnabled = m_Booted && !m_PlayerMode && !EditorModalPending() && m_Pointer && !m_CatalogPressed && GetGame().IsAppActive() && !GetGame().GetUIManager().GetMenu();
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
                MarkProjectClean();
                if (m_SelfTest) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTestStart, 250, false);
            }
            if (m_SelfTest && m_Attempts > 1200) { PrintToRPT("[PROXY TOOL V2 SELFTEST] FAIL: editor did not start."); GetGame().RequestExit(1); }
        }
        if (m_Item && m_Item.GetHierarchyParent())
        {
            DeselectItem();
            ReportWarning(IOTL.T("ITEM_PICKED_UP"));
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
    protected bool m_ModeSwitchKeyDown;

    override void AbortMission()
    {
        if (g_IOTProxyTool && g_IOTProxyTool.RequestEditorExit()) return;
        super.AbortMission();
    }

    override void OnUpdate(float timeslice)
    {
        if (!GetGame().IsAppActive()) m_ModeSwitchKeyDown = false;
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
        if (GetGame().GetUIManager().GetMenu())
        {
            super.OnKeyPress(key);
            return;
        }
        if (g_IOTProxyTool && key == KeyCode.KC_F4)
        {
            // Emotes poll UAInput independently of OnKeyPress. Consume both the
            // current key and its mapped press before restoring player controls.
            UAInput taunt = GetUApi().GetInputByName("EmoteTaunt");
            UAInput legacyGesture = GetUApi().GetInputByName("UAGestureSlot04");
            if (taunt) taunt.Supress();
            if (legacyGesture) legacyGesture.Supress();
            GetGame().GetInput().DisableKey(key);
            if (!m_ModeSwitchKeyDown)
            {
                m_ModeSwitchKeyDown = true;
                g_IOTProxyTool.HandleKey(key);
            }
            return;
        }
        if (g_IOTProxyTool && g_IOTProxyTool.HandleHistoryKey(key)) return;
        if (g_IOTProxyTool && g_IOTProxyTool.EditorModalPending())
        {
            g_IOTProxyTool.HandleKey(key);
            return;
        }
        super.OnKeyPress(key);
        if (g_IOTProxyTool) g_IOTProxyTool.HandleKey(key);
    }

    override void OnKeyRelease(int key)
    {
        if (key == KeyCode.KC_F4) m_ModeSwitchKeyDown = false;
        super.OnKeyRelease(key);
    }
}
