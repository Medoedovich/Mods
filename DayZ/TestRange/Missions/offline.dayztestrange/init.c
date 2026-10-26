void main()
{
    GetGame().GetWorld().SetDate(2026, 6, 15, 12, 0);
    Weather weather = GetGame().GetWeather();
    weather.MissionWeather(true);
    weather.GetOvercast().SetLimits(0, 0);
    weather.GetRain().SetLimits(0, 0);
    weather.GetFog().SetLimits(0, 0);
    weather.GetOvercast().Set(0, 0, 0);
    weather.GetRain().Set(0, 0, 0);
    weather.GetFog().Set(0, 0, 0);
    // Do not initialize Hive: this mission has no automatic economy.
    Print("[DTR OFFLINE] Vanilla mission; economy disabled; world=dayztestrange.");
}

class DTROfflineMission: MissionGameplay
{
    bool m_DTRLoaded;

    override void OnInit()
    {
        super.OnInit();
        vector center = "512 1.1 512";
        center[1] = GetGame().SurfaceY(512, 512) + 0.1;
        PlayerBase player = PlayerBase.Cast(GetGame().CreatePlayer(null, GetGame().CreateRandomPlayer(), center, 0, "NONE"));
        if (player)
        {
            GetGame().SelectPlayer(null, player);
            Print("[DTR OFFLINE] Player at " + player.GetPosition().ToString());
        }
        else
        {
            Print("[DTR OFFLINE] ERROR: player creation failed.");
        }
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        if (!m_DTRLoaded && !GetDayZGame().IsLoading())
        {
            m_DTRLoaded = true;
            Print("[DTR OFFLINE] World loaded; size=" + GetGame().GetWorld().GetWorldSize());
        }
    }
}

Mission CreateCustomMission(string path)
{
    return new DTROfflineMission();
}
