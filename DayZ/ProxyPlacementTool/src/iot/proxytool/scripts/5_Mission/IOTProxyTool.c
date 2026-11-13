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
        array<string> keys = {"LOCALE","TITLE","ITEM","ANCHOR","MOVE","ROTATE","POSITION","MOVE_STEP_DEFAULT","ROTATION","ANGLE_STEP_DEFAULT","APPLY","CHARACTER","RESET","GROUND","SELECT_HINT","HELP","CREATE_TITLE","BUILDINGS","ITEMS","SEARCH","CLASSNAME","CREATE_ANCHOR","CREATE_ITEM","FOCUS_ANCHOR","EXPORT_ANCHOR","ITEM_MODE_HINT","ANCHOR_MODE_HINT","FOUND","UNKNOWN_CLASS","ANCHOR_REQUIRED","SPAWN_FAILED","NOT_INVENTORY_ITEM","NOT_ANCHOR","CREATED","ANCHOR_TRANSFORM_LIMIT","GIZMO_HINT","DESELECT_HINT","NO_ITEM","NO_ANCHOR","START_HINT","GIZMO_ON","GIZMO_OFF","INVALID_NUMBER","NUMBER_LIMIT","POSE_APPLIED","GROUNDED","POSE_RESET","ANCHOR_XML_FAILED","ANCHOR_XML_SAVED","XML_FAILED","MOVE_STEP","ANGLE_STEP","MOVE_KEYS","ROTATE_KEYS","ITEM_PICKED_UP","WORLD_POSITION","WORLD_ORIENTATION","TRAY_TITLE","TRAY_TITLE_EMPTY","TRAY_EMPTY","TRAY_OWNER","TRAY_SELECTED","TRAY_INVENTORY","CHARACTER_HINT"};
        return keys;
    }
}
class IOTSceneEntry
{
    Object Anchor;
    int Id;
    ref array<ItemBase> Items = new array<ItemBase>;
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
    protected bool m_ItemsMode;
    protected bool m_Updating;
    protected ref array<string> m_AnchorClasses = new array<string>;
    protected ref array<string> m_ItemClasses = new array<string>;
    protected ref array<string> m_Filtered = new array<string>;

    void IOTSceneBrowser(IOTProxyTool tool)
    {
        m_Tool = tool;
        m_Root = GetGame().GetWorkspace().CreateWidgets("iot\\proxytool\\gui\\scene_browser.layout");
        m_Search = EditBoxWidget.Cast(m_Root.FindAnyWidget("SceneSearch"));
        m_ClassName = EditBoxWidget.Cast(m_Root.FindAnyWidget("SceneClass"));
        m_Results = TextListboxWidget.Cast(m_Root.FindAnyWidget("SceneResults"));
        m_Count = TextWidget.Cast(m_Root.FindAnyWidget("SceneCount"));
        m_Status = MultilineTextWidget.Cast(m_Root.FindAnyWidget("SceneStatus"));
        m_Root.SetHandler(this);
        LoadCatalog();
        SetMode(false);
    }

    void ~IOTSceneBrowser()
    {
        if (m_Root) m_Root.Unlink();
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
                if (root == "CfgVehicles" && (lower.IndexOf("land_") == 0 || lower.IndexOf("staticobj_") == 0))
                    m_AnchorClasses.Insert(name);
                if (GetGame().ConfigGetInt(path + " scope") != 2) continue;
                if (root == "CfgVehicles" && !GetGame().IsKindOf(name,"Inventory_Base")) continue;
                if (m_ItemClasses.Find(name) < 0) m_ItemClasses.Insert(name);
            }
        }
        m_AnchorClasses.Sort();
        m_ItemClasses.Sort();
        PrintToRPT("[PROXY CATALOG] Anchors=" + m_AnchorClasses.Count().ToString() + " items=" + m_ItemClasses.Count().ToString());
    }

    int CatalogCount(bool items)
    {
        if (items) return m_ItemClasses.Count();
        return m_AnchorClasses.Count();
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
        m_Search.SetText("");
        m_ClassName.SetText("");
        ButtonWidget.Cast(m_Root.FindAnyWidget("SceneAnchorsMode")).SetState(!items);
        ButtonWidget.Cast(m_Root.FindAnyWidget("SceneItemsMode")).SetState(items);
        ButtonWidget button = ButtonWidget.Cast(m_Root.FindAnyWidget("SceneCreate"));
        if (items) button.SetText(IOTL.T("CREATE_ITEM"));
        else button.SetText(IOTL.T("CREATE_ANCHOR"));
        m_Updating = false;
        Filter();
        if (items) SetStatus(IOTL.T("ITEM_MODE_HINT"));
        else SetStatus(IOTL.T("ANCHOR_MODE_HINT"));
    }

    protected void Filter()
    {
        m_Updating = true;
        string query = m_Search.GetText();
        query.TrimInPlace();
        query.ToLower();
        m_Results.ClearItems();
        m_Filtered.Clear();
        array<string> source = m_AnchorClasses;
        if (m_ItemsMode) source = m_ItemClasses;
        int count;
        foreach (string name : source)
        {
            string lower = name;
            lower.ToLower();
            if (query != "" && lower.IndexOf(query) < 0) continue;
            count++;
            if (m_Filtered.Count() >= 100) continue;
            m_Filtered.Insert(name);
            m_Results.AddItem(name,null,0);
        }
        m_Count.SetText(IOTL.F("FOUND",count.ToString(),m_Filtered.Count().ToString()));
        if (m_Filtered.Count() > 0)
        {
            m_Results.SelectRow(0);
            m_ClassName.SetText(m_Filtered[0]);
        }
        else m_ClassName.SetText("");
        m_Updating = false;
        UpdateButtons();
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
        if (w == m_Search) { Filter(); return true; }
        if (w == m_ClassName) { UpdateButtons(); return true; }
        if (w == m_Results)
        {
            int row = m_Results.GetSelectedRow();
            if (row >= 0 && row < m_Filtered.Count()) m_ClassName.SetText(m_Filtered[row]);
            UpdateButtons();
            return true;
        }
        return false;
    }

    override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn)
    {
        if (m_Updating || w != m_Results) return false;
        if (row >= 0 && row < m_Filtered.Count()) m_ClassName.SetText(m_Filtered[row]);
        UpdateButtons();
        return true;
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

    void EnterEditor()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player)
        {
            m_PlayerWasDisabled = player.GetIsSimulationDisabled();
            player.DisableSimulation(true);
        }
        m_PlayerMode = false;
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
        if (!TestCheck(SpawnSceneClass("Land_Wreck_hb01_aban1_blue",false) && SpawnSceneClass("HatchbackWheel",true), "runtime creation of wreck and wheel")) return;
        DeselectItem();
        RefreshObjects();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SelfTest,1000,false);
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
