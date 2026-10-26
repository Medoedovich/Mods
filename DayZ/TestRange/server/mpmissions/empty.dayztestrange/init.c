void main()
{
    // Deliberately do not call CreateHive().InitOffline(): this test mission
    // has no automatic economy, event, animal, infected or vehicle spawning.
    GetGame().GetWorld().SetDate(2026, 6, 15, 12, 0);
    Weather weather = GetGame().GetWeather();
    weather.MissionWeather(true);
    weather.GetOvercast().SetLimits(0, 0);
    weather.GetRain().SetLimits(0, 0);
    weather.GetFog().SetLimits(0, 0);
    weather.GetOvercast().Set(0, 0, 0);
    weather.GetRain().Set(0, 0, 0);
    weather.GetFog().Set(0, 0, 0);
    Print("[DTR] DayZ Test Range: economy disabled; center=512,1,512; test bounds=387..637.");
}

class DTRMission: MissionServer
{
    float m_DTRCommandPoll;

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        m_DTRCommandPoll += timeslice;
        if (m_DTRCommandPoll < 1)
            return;
        m_DTRCommandPoll = 0;
        FileHandle handle = OpenFile("$profile:dtr-server-command.txt", FileMode.READ);
        if (!handle)
            return;
        string command;
        FGets(handle, command);
        CloseFile(handle);
        command.TrimInPlace();
        if (command == "shutdown")
        {
            handle = OpenFile("$profile:dtr-server-command.txt", FileMode.WRITE);
            if (handle)
                CloseFile(handle);
            Print("[DTR] Clean shutdown requested by the local launcher.");
            GetGame().RequestExit(0);
        }
    }

    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        vector center = "512 1.1 512";
        center[1] = GetGame().SurfaceY(center[0], center[2]) + 0.1;
        PlayerBase player = super.CreateCharacter(identity, center, ctx, characterName);
        if (player)
            Print("[DTR] New player at " + player.GetPosition().ToString());
        return player;
    }

    override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
    {
        // Keep the vanilla character's clothing. No random inventory items.
    }
}

Mission CreateCustomMission(string path)
{
    return new DTRMission();
}
