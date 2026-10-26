param([string]$Root = (Split-Path -Parent $PSScriptRoot), [string]$VanillaCE = 'P:\DZ\worlds\chernarusplus\ce')
$ErrorActionPreference = 'Stop'
$ce = Join-Path $Root 'src\dtr\test_range\ce'
$mission = Join-Path $Root 'server\mpmissions\empty.dayztestrange'
New-Item -ItemType Directory -Force -Path (Join-Path $ce 'db') | Out-Null
function Write-XmlText([string]$Relative,[string]$Text) {
    [IO.File]::WriteAllText((Join-Path $ce $Relative), "<?xml version=`"1.0`" encoding=`"UTF-8`"?>`r`n$Text`r`n", (New-Object Text.UTF8Encoding $false))
}
Write-XmlText 'db\economy.xml' @'
<economy>
    <dynamic init="0" load="0" respawn="0" save="0"/>
    <animals init="0" load="0" respawn="0" save="0"/>
    <zombies init="0" load="0" respawn="0" save="0"/>
    <vehicles init="0" load="0" respawn="0" save="0"/>
    <randoms init="0" load="0" respawn="0" save="0"/>
    <custom init="0" load="0" respawn="0" save="0"/>
    <building init="0" load="0" respawn="0" save="0"/>
    <player init="1" load="1" respawn="1" save="1"/>
</economy>
'@
$empty = @{
    'db\types.xml'='<types/>'
    'db\events.xml'='<events/>'
    'cfgenvironment.xml'='<env><territories/></env>'
    'cfgeventspawns.xml'='<eventposdef/>'
    'cfgspawnabletypes.xml'='<spawnabletypes/>'
    'cfgrandompresets.xml'='<randompresets/>'
    'mapgrouppos.xml'='<map/>'
    'mapgroupproto.xml'='<prototype/>'
    'mapclusterproto.xml'='<prototype><clusters/></prototype>'
    'mapgroupcluster.xml'='<map/>'
}
foreach ($item in $empty.GetEnumerator()) { Write-XmlText $item.Key $item.Value }
foreach ($file in @('cfgeconomycore.xml','cfglimitsdefinition.xml','cfglimitsdefinitionuser.xml','db\globals.xml')) {
    if (-not (Test-Path -LiteralPath (Join-Path $VanillaCE $file))) { throw "Extract the current game data first: $VanillaCE\$file" }
    Copy-Item -LiteralPath (Join-Path $VanillaCE $file) -Destination (Join-Path $ce $file)
}
[xml]$globals = Get-Content -LiteralPath (Join-Path $ce 'db\globals.xml') -Raw
foreach ($v in $globals.variables.var) {
    if ($v.name -in @('AnimalMaxCount','ZombieMaxCount','InitialSpawn','SpawnInitial','RestartSpawn')) { $v.value = '0' }
}
$globals.Save((Join-Path $ce 'db\globals.xml'))
$section = @'
        <spawn_params>
            <min_dist_infected>0</min_dist_infected><max_dist_infected>0</max_dist_infected>
            <min_dist_player>0</min_dist_player><max_dist_player>0</max_dist_player>
            <min_dist_static>0</min_dist_static><max_dist_static>0</max_dist_static>
        </spawn_params>
        <generator_params>
            <grid_density>2</grid_density><grid_width>2</grid_width><grid_height>2</grid_height>
            <min_dist_static>0</min_dist_static><max_dist_static>0</max_dist_static>
            <min_steepness>-1</min_steepness><max_steepness>1</max_steepness>
        </generator_params>
        <generator_posbubbles><pos x="512" z="512"/></generator_posbubbles>
'@
Write-XmlText 'cfgplayerspawnpoints.xml' "<playerspawnpoints>`r`n    <fresh>`r`n$section`r`n    </fresh>`r`n    <hop>`r`n$section`r`n    </hop>`r`n    <travel>`r`n$section`r`n    </travel>`r`n</playerspawnpoints>"
# Mission overrides make the disabled spawn setup easy to inspect and customize.
Get-ChildItem -LiteralPath $ce | Where-Object Name -ne 'config.cpp' | ForEach-Object {
    Copy-Item -LiteralPath $_.FullName -Destination $mission -Recurse -Force
}
