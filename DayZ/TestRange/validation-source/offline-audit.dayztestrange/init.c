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


// Observation-only subclass of the unchanged released gameplay mission.
class DTRAuditMission: DTROfflineMission
{
    int m_Phase;
    float m_WaitUntil;
    float m_AuditStart;
    int m_NextSample;
    bool m_AuditFailed;
    Object m_Control;

    int Scan(int elapsed, bool control = false)
    {
        array<Object> objects = {};
        array<CargoBase> cargos = {};
        GetGame().GetObjectsAtPosition3D("512 1 512", 1800, objects, cargos);
        int infected, animals, vehicles, groundItems;
        foreach (Object obj: objects)
        {
            if (obj.IsInherited(ZombieBase)) infected++;
            else if (obj.IsInherited(AnimalBase)) animals++;
            else if (obj.IsInherited(Transport)) vehicles++;
            else
            {
                ItemBase item = ItemBase.Cast(obj);
                if (item && !item.GetHierarchyParent()) groundItems++;
            }
        }
        array<Man> players = {};
        GetGame().GetPlayers(players);
        string prefix = "[DTR AUDIT]";
        if (control) prefix = "[DTR SENSOR]";
        Print(prefix + " t=" + elapsed + " infected=" + infected + " animals=" + animals + " vehicles=" + vehicles + " groundItems=" + groundItems + " players=" + players.Count());
        if (!control && (infected || animals || vehicles || groundItems || players.Count() != 1)) m_AuditFailed = true;
        return groundItems;
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        if (!m_DTRLoaded) return;
        float now = GetGame().GetTime() * 0.001;
        if (m_Phase == 0)
        {
            m_Control = GetGame().CreateObject("SodaCan_Cola", "520 2 512", true);
            m_WaitUntil = now + 2;
            m_Phase = 1;
            return;
        }
        if (m_Phase == 1 && now >= m_WaitUntil)
        {
            if (!m_Control || Scan(-1, true) != 1)
            {
                Print("[DTR AUDIT] SENSOR FAILED");
                GetGame().RequestExit(1);
                return;
            }
            GetGame().ObjectDelete(m_Control);
            m_Control = null;
            Print("[DTR AUDIT] SENSOR PASSED; controlled item deleted before observation.");
            m_Phase = 2;
            m_WaitUntil = now + 3;
            return;
        }
        if (m_Phase == 2 && now >= m_WaitUntil)
        {
            m_AuditStart = now;
            m_NextSample = 0;
            m_Phase = 3;
        }
        if (m_Phase == 3 && now - m_AuditStart >= m_NextSample)
        {
            Scan(m_NextSample);
            if (m_NextSample >= 600)
            {
                if (m_AuditFailed) Print("[DTR AUDIT] FAILED after 600 seconds.");
                else Print("[DTR AUDIT] PASSED after 600 seconds.");
                m_Phase = 4;
                m_WaitUntil = now + 3;
            }
            m_NextSample += 60;
        }
        if (m_Phase == 4 && now >= m_WaitUntil)
        {
            m_Phase = 5;
            GetGame().RequestExit(0);
        }
    }
}

Mission CreateCustomMission(string path)
{
    return new DTRAuditMission();
}
