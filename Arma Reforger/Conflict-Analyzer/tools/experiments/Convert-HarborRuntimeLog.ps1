[CmdletBinding()]
param(
    [Parameter(Mandatory=$true)][string]$LogPath,
    [Parameter(Mandatory=$true)][string]$LaunchMetadataPath,
    [Parameter(Mandatory=$true)][string]$OutputPath,
    [string]$ProbePath=(Join-Path $PSScriptRoot 'ME_CA_HarborProbe.c')
)
$ErrorActionPreference='Stop'
# LaunchMetadataPath is a JSON object with StartedUTC from the launch of this log's process.
$text=Get-Content $LogPath -Raw
if($text -notmatch '\[ME_HARBOR\] COMPLETE'){throw 'Probe is not complete'}
if($text -match 'Virtual Machine Exception|SCRIPT\s+\(E\)'){throw 'Probe script error'}
$entries=@(foreach($line in ($text -split '\r?\n')){if($line -match '\[ME_HARBOR\] (\w+)(?: (.*))?$'){
    $kind=$Matches[1];$fields=@{};foreach($m in [regex]::Matches($Matches[2],'(\w+)=(.*?)(?= \w+=|$)')){$fields[$m.Groups[1].Value]=$m.Groups[2].Value};[pscustomobject]@{kind=$kind;f=$fields}
}})
$begin=@($entries | Where-Object kind -eq BEGIN)
if($begin.Count -ne 1 -or $begin[0].f.game -ne '1.8.0.13' -or $begin[0].f.header -ne '1'){throw 'Wrong scenario/version'}
$records=@();$bases=@()
foreach($sample in @('30','45')){
    $bs=@($entries | Where-Object {$_.kind -eq 'BASE' -and $_.f.sample -eq $sample})
    if($bs.Count -ne 18 -or @($bs.f.name | Sort-Object -Unique).Count -ne 18){throw 'Incomplete harbor sample'}
    foreach($b in $bs){if($b.f.initialized -ne '1' -or $b.f.range -ne '100'){throw 'Unexpected generator'};$bases+=[ordered]@{sampleSeconds=[int]$sample;name=$b.f.name;radiusMeters=[double]$b.f.range;isolated=($b.f.isolated -eq '1');initialized=($b.f.initialized -eq '1')}}
    foreach($slot in @($entries | Where-Object {$_.kind -eq 'SLOT' -and $_.f.sample -eq $sample})){
        $s=$slot.f
        $entityKey=$s.entity; if($entityKey -match '^0x([0-9A-Fa-f]+)') {$entityKey=[string]([Convert]::ToUInt64($Matches[1],16) -band 4294967295)}
        $checks=@($entries | Where-Object {$_.kind -eq 'CHECK' -and $_.f.sample -eq $sample -and $_.f.harbor -ceq $s.harbor -and $_.f.entity -eq $entityKey -and $_.f.index -eq $s.index})
        $prefabs=@($entries | Where-Object {$_.kind -eq 'PREFAB' -and $_.f.sample -eq $sample -and $_.f.harbor -ceq $s.harbor -and $_.f.entity -eq $entityKey -and $_.f.index -eq $s.index})
        if($checks.Count -ne 1 -or $prefabs.Count -ne 1){throw "Missing/duplicate probe data $($s | ConvertTo-Json -Compress) checks=$($checks.Count) prefabs=$($prefabs.Count)"}
        $c=$checks[0].f
        $records+=[ordered]@{sampleSeconds=[int]$sample;harbor=$s.harbor;runtimeEntityId=$s.entity;containerIndex=[int]$s.index;virtual=($s.virtual -eq '1');worldPositionMeters=@(([double]$s.xMm/1000),([double]$s.yMm/1000),([double]$s.zMm/1000));prefab=$prefabs[0].f.path;isolated=($c.isolated -eq '1');allowed=($c.allowed -eq '1');inRange=($c.inRange -eq '1');linked=($c.linked -eq '1')}
    }
}
$run=Get-Content $LaunchMetadataPath -Raw | ConvertFrom-Json
$report=[ordered]@{schemaVersion=1;kind='harbor-container-runtime';gameVersion='1.8.0.13';world='worlds/MP/CTI_Campaign_HQC_Eden.ent';missionHeader='{0220741028718E7F}Missions/23_Campaign_HQC_Everon.conf';complete=$true;startedAtUTC=$run.StartedUTC;selectedSampleSeconds=45;queryRadiusMeters=300;queryRadiusMeaning='Probe candidate discovery only, not supply radius';sourceMatchToleranceMeters=0.03;sourceMatchMethod='unique exact source entity ID plus kind and slot index; fallback unique prefab plus kind, slot index and position within 0.03m; source/runtime displacement retained';logSha256=(Get-FileHash $LogPath).Hash;probeSha256=(Get-FileHash $ProbePath).Hash;readOnly=$true;limitations=@('No forced grid update or supply generation: unlinked may simply mean the generator has not requested an update.','Observed state applies only to this initialized session; it does not prove periodic replenishment.','300m query probes nearby loaded runtime entities; unmatched and dynamic records are retained without invented source IDs.');bases=$bases;records=@($records | Where-Object sampleSeconds -eq 45);earlierSample=@($records | Where-Object sampleSeconds -eq 30)}
$report | ConvertTo-Json -Depth 15 | Set-Content $OutputPath -Encoding utf8
"Runtime records: $($report.records.Count); bases: $($bases.Count)"
