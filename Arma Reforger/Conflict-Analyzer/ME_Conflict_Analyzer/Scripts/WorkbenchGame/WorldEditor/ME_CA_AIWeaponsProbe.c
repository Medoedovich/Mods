[WorkbenchPluginAttribute(name: "Read AI character weapons", wbModules: {"WorldEditor"}, category: "[ME] Conflict Analyzer/Diagnostics")]
class ME_CA_AIWeaponsProbe : WorldEditorPlugin
{
 override void RunCommandline() { Run(); }
 override void Run()
 {
  PrintFormat("[ME_CA_AI_WEAPONS] BEGIN|%1", GetGame().GetBuildVersion());
  array<ResourceName> paths = {"{1FDA92972C1B771B}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_Rebel_Sharpshooter.et","{23D81C023DBF85AC}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_RTO.et","{244E2E8B42B42490}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_MG_Elite.et","{254F12535581E4C2}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_AC_Partisan.et","{273F0239FE94FDA5}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_AC_Partisan_Grenadier.et","{45A02CA25CBA9443}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Medic.et","{4E29194BA809DF32}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AC_Medic.et","{58E47E5A4D599432}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_MG.et","{677B515F119222C2}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_SL.et","{75FC25863194612A}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AMG.et","{84B40583F4D1B7A3}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Rifleman.et","{B4977616CD19191A}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AC_Scout.et","{BF1E43FF39AA526B}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Scout.et","{C77DFB8546B3F2A2}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_LAT.et","{CE33AB22F61F3365}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Sharpshooter.et","{D25BC9815A9F9E8D}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AT.et","{FF43925D26526B95}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AAT.et"};
  foreach(ResourceName path : paths)
  {
   Resource loaded = Resource.Load(path);
   if (!loaded || !loaded.GetResource()) { PrintFormat("[ME_CA_AI_WEAPONS] ERROR|%1", path); continue; }
   IEntitySource source = IEntitySource.Cast(loaded.GetResource().ToBaseContainer());
   if (!source) { PrintFormat("[ME_CA_AI_WEAPONS] ERROR|%1", path); continue; }
   PrintFormat("[ME_CA_AI_WEAPONS] CHARACTER|%1", path);
   for(int c = 0; c < source.GetComponentCount(); c++)
   {
    IEntityComponentSource component = source.GetComponent(c);
    string cls = component.GetClassName();
    if (cls == "CharacterWeaponSlotComponent" || cls == "CharacterGrenadeSlotComponent")
    {
     ResourceName weapon;
     bool ok = component.Get("WeaponTemplate", weapon);
     PrintFormat("[ME_CA_AI_WEAPONS] SLOT|%1|%2|%3|%4|%5", path, c, cls, weapon, ok);
    }
    if (cls == "SCR_InventoryStorageManagerComponent")
    {
     BaseContainerList items = component.GetObjectArray("InitialInventoryItems");
     if (!items) continue;
     for(int i = 0; i < items.Count(); i++)
     {
      array<ResourceName> prefabs = {};
      bool read = items.Get(i).Get("PrefabsToSpawn", prefabs);
      if (!read) { PrintFormat("[ME_CA_AI_WEAPONS] INVENTORY_UNRESOLVED|%1|%2", path, i); continue; }
      foreach(ResourceName item : prefabs)
       PrintFormat("[ME_CA_AI_WEAPONS] ITEM|%1|%2|%3", path, i, item);
     }
    }
   }
  }
  PrintFormat("[ME_CA_AI_WEAPONS] COMPLETE|%1", paths.Count());
 }
}