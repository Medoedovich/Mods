void main()
{
	// economy init
	CreateHive();
	GetHive().InitOffline();

	// player creation
	vector spawnPos = "512 0 512";
    PlayerBase player = PlayerBase.Cast( GetGame().CreatePlayer(NULL, "SurvivorF_Eva", spawnPos, 0, "NONE") );
	GetGame().SelectPlayer(NULL, player);
};