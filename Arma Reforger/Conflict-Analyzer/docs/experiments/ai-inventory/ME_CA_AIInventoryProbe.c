modded class SCR_GameModeCampaign
{
 ref array<ResourceName> m_CA_Paths = {};
 int m_CA_Index;
 override void OnGameStart()
 {
  super.OnGameStart();
  if (!GetGame().InPlayMode() || !IsMaster() || !System.IsCLIParam("CA_AI_Inventory")) return;
  m_CA_Paths.Insert("{1FDA92972C1B771B}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_Rebel_Sharpshooter.et");
  m_CA_Paths.Insert("{23D81C023DBF85AC}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_RTO.et");
  m_CA_Paths.Insert("{244E2E8B42B42490}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_MG_Elite.et");
  m_CA_Paths.Insert("{254F12535581E4C2}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_AC_Partisan.et");
  m_CA_Paths.Insert("{273F0239FE94FDA5}Prefabs/Characters/Factions/INDFOR/FIA/Special Units/Character_FIA_AC_Partisan_Grenadier.et");
  m_CA_Paths.Insert("{45A02CA25CBA9443}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Medic.et");
  m_CA_Paths.Insert("{4E29194BA809DF32}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AC_Medic.et");
  m_CA_Paths.Insert("{58E47E5A4D599432}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_MG.et");
  m_CA_Paths.Insert("{677B515F119222C2}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_SL.et");
  m_CA_Paths.Insert("{75FC25863194612A}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AMG.et");
  m_CA_Paths.Insert("{84B40583F4D1B7A3}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Rifleman.et");
  m_CA_Paths.Insert("{B4977616CD19191A}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AC_Scout.et");
  m_CA_Paths.Insert("{BF1E43FF39AA526B}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Scout.et");
  m_CA_Paths.Insert("{C77DFB8546B3F2A2}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_LAT.et");
  m_CA_Paths.Insert("{CE33AB22F61F3365}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_Sharpshooter.et");
  m_CA_Paths.Insert("{D25BC9815A9F9E8D}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AT.et");
  m_CA_Paths.Insert("{FF43925D26526B95}Prefabs/Characters/Factions/INDFOR/FIA/Character_FIA_AAT.et");
  PrintFormat("[ME_CA_AI_INV] BEGIN|%1",GetGame().GetBuildVersion());
  GetGame().GetCallqueue().CallLater(CA_Next,5000,false);
 }
 void CA_Next()
 {
  if(m_CA_Index>=m_CA_Paths.Count()){ PrintFormat("[ME_CA_AI_INV] COMPLETE|%1",m_CA_Paths.Count()); return; }
  ResourceName path=m_CA_Paths[m_CA_Index++];
  EntitySpawnParams p=new EntitySpawnParams();
  p.TransformMode=ETransformMode.WORLD;
  p.Transform[3]="4900 29 11790";
  IEntity character=GetGame().SpawnEntityPrefab(Resource.Load(path),GetGame().GetWorld(),p);
  if(!character){PrintFormat("[ME_CA_AI_INV] ERROR|%1",path);CA_Next();return;}
  GetGame().GetCallqueue().CallLater(CA_Read,500,false,character,path);
 }
 void CA_Read(IEntity character, ResourceName path)
 {
  InventoryStorageManagerComponent inv=InventoryStorageManagerComponent.Cast(character.FindComponent(InventoryStorageManagerComponent));
  if(!inv){PrintFormat("[ME_CA_AI_INV] ERROR|%1",path);return;}
  array<IEntity> items={}; inv.GetItems(items);
  array<IEntity> loaded={};
  foreach(IEntity item : items)
  {
   WeaponComponent weapon=WeaponComponent.Cast(item.FindComponent(WeaponComponent));
   if(!weapon)continue;
   array<BaseMuzzleComponent> muzzles={};weapon.GetMuzzlesList(muzzles);
   foreach(BaseMuzzleComponent muzzle : muzzles)
   {
    BaseMagazineComponent mag=muzzle.GetMagazine();
    if(mag && loaded.Find(mag.GetOwner())<0) loaded.Insert(mag.GetOwner());
    PrintFormat("[ME_CA_AI_INV] MUZZLE|%1|%2|%3|%4",path,item.GetPrefabData().GetPrefabName(),muzzle.GetAmmoCount(),muzzle.IsCurrentBarrelChambered());
   }
  }
  foreach(IEntity magazine : loaded){if(items.Find(magazine)<0)items.Insert(magazine);}
  array<IEntity> seen={};
  foreach(IEntity obj : items)
  {
   if(seen.Find(obj)>=0)continue;seen.Insert(obj);
   if(!obj.GetPrefabData())continue;
   ResourceName prefab=obj.GetPrefabData().GetPrefabName();
   if(!prefab.Contains("Prefabs/Weapons/"))continue;
   BaseMagazineComponent mc=BaseMagazineComponent.Cast(obj.FindComponent(BaseMagazineComponent));
   int rounds=-1;int capacity=-1;
   if(mc){rounds=mc.GetAmmoCount();capacity=mc.GetMaxAmmoCount();}
   PrintFormat("[ME_CA_AI_INV] ITEM|%1|%2|%3|%4|%5",path,prefab,loaded.Find(obj)>=0,rounds,capacity);
  }
  PrintFormat("[ME_CA_AI_INV] CHARACTER|%1|%2",path,inv.GetGrenadesCount());
  SCR_EntityHelper.DeleteEntityAndChildren(character);
  GetGame().GetCallqueue().CallLater(CA_Next,100,false);
 }
}
