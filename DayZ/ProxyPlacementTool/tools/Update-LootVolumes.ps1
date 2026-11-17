[CmdletBinding()]
param([Parameter(Mandatory=$true)][string]$WorldsRoot)
$ErrorActionPreference = 'Stop'
$taskProject = Split-Path -Parent $PSScriptRoot
$taskCulture = [Globalization.CultureInfo]::InvariantCulture
$taskMaps = @('chernarusplus','enoch','sakhal','nasdara')
$taskRecords = @{}
$taskSources = @()
for ($taskIndex=0; $taskIndex -lt $taskMaps.Count; $taskIndex++) {
    $taskPath = Join-Path $WorldsRoot ($taskMaps[$taskIndex]+'\ce\mapgroupproto.xml')
    [xml]$taskXml = [IO.File]::ReadAllText($taskPath)
    $taskGroups = @($taskXml.SelectNodes('/prototype/group'))
    if ($taskGroups.Count -lt 100) { throw ('Unexpectedly small source: '+$taskPath) }
    $taskPointCount = 0
    foreach ($taskGroup in $taskGroups) {
        $taskClass = $taskGroup.name.ToLowerInvariant()
        if ($taskClass -notmatch '^[a-z0-9_]+$') { throw 'Invalid classname' }
        # A header also records known prototypes without ordinary container points.
        $taskRows = @('|')
        $taskContainerRows = @{}
        foreach ($taskContainer in $taskGroup.SelectNodes('container')) {
            $taskPoints = @()
            foreach ($taskPoint in $taskContainer.SelectNodes('point')) {
                $taskRange = [string]$taskPoint.range
                $taskHeight = [string]$taskPoint.height
                # -1 means unspecified in the XML, never an invented engine default.
                if (!$taskRange) { $taskRange = '-1' }
                if (!$taskHeight) { $taskHeight = '-1' }
                $taskNumbers = @(([string]$taskPoint.pos -split '\s+') + @($taskRange,$taskHeight))
                if ($taskNumbers.Count -ne 5) { throw 'Invalid point dimensions' }
                $taskValues = @($taskNumbers | ForEach-Object { [double]::Parse($_,$taskCulture) })
                if ($taskValues[3] -lt -1 -or $taskValues[4] -lt -1) { throw 'Invalid volume dimensions' }
                $taskPoints += (($taskValues | ForEach-Object { $_.ToString('0.######',$taskCulture) }) -join ' ')
                $taskPointCount++
            }
            if ($taskPoints.Count) {
                $taskContainerName = [string]$taskContainer.name
                if ($taskContainerRows.ContainsKey($taskContainerName)) { $taskContainerRows[$taskContainerName] += ';'+($taskPoints -join ';') }
                else { $taskContainerRows[$taskContainerName] = $taskPoints -join ';' }
            }
        }
        foreach ($taskContainerName in @($taskContainerRows.Keys | Sort-Object)) { $taskRows += $taskContainerName+'|'+$taskContainerRows[$taskContainerName] }
        foreach ($taskRow in $taskRows) {
            $taskKey = $taskClass+'|'+$taskRow
            $taskRecords[$taskKey] = ([int]$taskRecords[$taskKey]) -bor (1 -shl $taskIndex)
        }
    }
    $taskSources += [ordered]@{World=$taskMaps[$taskIndex];Groups=$taskGroups.Count;Points=$taskPointCount;SHA256=(Get-FileHash -LiteralPath $taskPath).Hash}
}
$taskLines = [Collections.Generic.List[string]]::new()
$taskLines.Add('# Bohemia Interactive official CE mapgroupproto.xml; derived data ADPL-SA. See docs/LOOT-VOLUMES.md.')
$taskLines.Add('# classname|map mask (1 ChernarusPlus,2 Livonia,4 Sakhal,8 Nasdara)|container|CE x y z range height;...')
foreach ($taskKey in @($taskRecords.Keys | Sort-Object)) {
    $taskSplit = $taskKey.IndexOf('|')
    $taskLines.Add($taskKey.Substring(0,$taskSplit)+'|'+$taskRecords[$taskKey]+'|'+$taskKey.Substring($taskSplit+1))
}
$taskData = Join-Path $taskProject 'src\iot\proxytool\data'
[IO.Directory]::CreateDirectory($taskData) | Out-Null
$taskOutput = Join-Path $taskData 'loot_volumes.txt'
[IO.File]::WriteAllLines($taskOutput,$taskLines,[Text.UTF8Encoding]::new($false))
$taskManifest = [ordered]@{Source='Bohemia Interactive installed official terrain CE files';License='ADPL-SA';Definition='Only group/container/point pos, range and height; dispatch proxies excluded; identical container records share a map bitmask';Maps=$taskSources;Records=$taskRecords.Count;GeneratedSHA256=(Get-FileHash -LiteralPath $taskOutput).Hash}
$taskManifest | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $taskProject 'docs\loot-volume-sources.json') -Encoding UTF8
$taskManifest | ConvertTo-Json -Depth 5
