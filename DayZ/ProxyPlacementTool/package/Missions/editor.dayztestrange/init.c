void main()
{
    GetGame().GetWorld().SetDate(2026, 6, 15, 12, 0);
    CreateHive();
    GetHive().InitOffline();
    vector position = "501 0 515";
    position[1] = GetGame().SurfaceY(position[0], position[2]) + 0.1;
    PlayerBase player = PlayerBase.Cast(GetGame().CreatePlayer(NULL, "SurvivorF_Eva", position, 0, "NONE"));
    if (player)
    {
        GetGame().SelectPlayer(NULL, player);
        player.SetOrientation("0 0 0");
    }
    GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(IOT_StartProxyTool, 2000, false);
    Print("[PROXY ALPHA] 0.1.0-alpha / Medoedovich / DayZDiag offline editor. Scene saving is not available; export XML before exiting.");
}

Mission CreateCustomMission(string path)
{
    return new IOTProxyMission;
}
