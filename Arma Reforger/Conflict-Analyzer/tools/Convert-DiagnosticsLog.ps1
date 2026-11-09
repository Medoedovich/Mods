<# Extract a complete native report; reject truncated or mixed runs. #>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$LogPath,
    [Parameter(Mandatory = $true)][string]$OutputPath,
    [ValidateSet('Diagnostics', 'SupplySources', 'StorageCapacity', 'StorageCapacityBatch', 'WorldSupplyContainers', 'NamedLocations', 'ControlPoints', 'SupplyDepots')][string]$ReportKind = 'Diagnostics'
)
$ErrorActionPreference = 'Stop'
$lines = Get-Content -LiteralPath $LogPath
$begin = @($lines | Where-Object { $_ -match '\[ME_CA_JSON_BEGIN\] characters=(\d+)\s*$' })
$end = @($lines | Where-Object { $_ -match '\[ME_CA_JSON_END\]\s*$' })
$success = @($lines | Where-Object { $_ -match '\[ME_CA\] status=SUCCESS .*output=console-log\s*$' })
if ($begin.Count -ne 1 -or $end.Count -ne 1 -or $success.Count -ne 1) {
    throw 'Expected one complete, successful native JSON run in the log.'
}
$null = $begin[0] -match 'characters=(\d+)'
$expectedLength = [int]$Matches[1]
$prefix = '[ME_CA_JSON_CHUNK] '
$chunks = @($lines | Where-Object { $_.Contains($prefix) } | ForEach-Object {
    $_.Substring($_.IndexOf($prefix) + $prefix.Length)
})
$json = $chunks -join ''
if ([Text.Encoding]::UTF8.GetByteCount($json) -ne $expectedLength -or $json.Contains([string][char]0xFFFD)) {
    # Enforce string.Length() counts UTF-8 bytes, including localized map labels.
    throw "Incomplete JSON: expected $expectedLength UTF-8 bytes, received $([Text.Encoding]::UTF8.GetByteCount($json))."
}
$report = $json | ConvertFrom-Json -ErrorAction Stop
if (!$report.worldPath -or !$report.editorEntityCountUnchanged -or
    $report.editorEntityCountBefore -ne $report.editorEntityCountAfter) {
    throw 'Report metadata or editor entity counts are inconsistent.'
}
if ($ReportKind -eq 'SupplyDepots') {
    if ($report.schemaVersion -ne 2 -or $report.kind -ne 'campaign-remnants-supply-depots' -or
        $report.selection -ne 'CampaignRemnantsSupplyDepot-prefab' -or $report.records.Count -ne $report.recordCount -or
        @($report.records | Where-Object { $_.prefab -notmatch '/CampaignRemnantsSupplyDepot\.et$' }).Count -or
        @($report.records.sourceId | Sort-Object -Unique).Count -ne $report.recordCount) {
        throw 'Supply-depot inventory metadata or counts are inconsistent.'
    }
    $recordCount = $report.recordCount
} elseif ($ReportKind -eq 'ControlPoints') {
    if ($report.schemaVersion -ne 2 -or $report.kind -ne 'conflict-control-points' -or
        $report.selection -ne 'ConflictControlPoint-prefab' -or $report.records.Count -ne $report.recordCount -or
        @($report.records | Where-Object { $_.prefab -notmatch '/ConflictControlPoint[^/]*\.et$' }).Count -or
        @($report.records.sourceId | Sort-Object -Unique).Count -ne $report.recordCount) {
        throw 'Control-point inventory metadata or counts are inconsistent.'
    }
    $recordCount = $report.recordCount
} elseif ($ReportKind -eq 'NamedLocations') {
    if ($report.schemaVersion -ne 2 -or $report.kind -ne 'named-world-locations' -or
        $report.selection -ne 'named-map-descriptor-DisplayName' -or $report.locations.Count -ne $report.recordCount -or
        $report.inspectedDescriptorCount -ne $report.recordCount + $report.unnamedDescriptorCount) {
        throw 'Named location inventory metadata or counts are inconsistent.'
    }
    $recordCount = $report.recordCount
} elseif ($ReportKind -eq 'WorldSupplyContainers') {
    if ($report.schemaVersion -ne 2 -or $report.kind -ne 'world-supply-containers' -or
        $report.selection -ne 'SCR_ResourceComponent-SUPPLIES-and-unresolved-slots' -or
        $report.resources.Count -ne $report.recordCount -or
        $report.inspectedResourceComponentCount -lt $report.recordCount) {
        throw 'World supply container inventory metadata or counts are inconsistent.'
    }
    $recordCount = $report.recordCount
} elseif ($ReportKind -eq 'StorageCapacityBatch') {
    if ($report.schemaVersion -ne 2 -or $report.kind -ne 'source-bases-storage-capacity' -or
        $report.selection -ne 'all-source-base-descendant-resource-containers' -or
        $report.bases.Count -ne $report.baseCount -or $report.baseCount -le 0 -or
        ($report.bases | Measure-Object -Property recordCount -Sum).Sum -ne $report.recordCount) {
        throw 'Batch storage-capacity report metadata or counts are inconsistent.'
    }
    $recordCount = $report.recordCount
} elseif ($ReportKind -eq 'StorageCapacity') {
    if ($report.schemaVersion -ne 2 -or $report.kind -ne 'source-base-storage-capacity' -or
        $report.selection -ne 'source-base-descendant-resource-containers' -or
        !$report.baseName -or !$report.baseSourceId -or $report.resources.Count -ne $report.recordCount -or
        @($report.nodes | Where-Object sourceId -eq $report.baseSourceId).Count -ne 1) {
        throw 'Storage-capacity report metadata or record count is inconsistent.'
    }
    $recordCount = $report.recordCount
} elseif ($ReportKind -eq 'SupplySources') {
    if ($report.schemaVersion -ne 2 -or $report.kind -ne 'supply-source-bases' -or
        $report.selection -ne 'SCR_CampaignSourceBaseComponent' -or $report.records.Count -ne $report.recordCount) {
        throw 'Supply-source report metadata or record count is inconsistent.'
    }
    $recordCount = $report.recordCount
} else {
    if ($report.schemaVersion -ne 1 -or $report.kind -ne 'editor-source-diagnostics' -or
        $report.entities.Count -ne $report.diagnosticEntityCount) {
        throw 'Diagnostic report metadata or entity counts are inconsistent.'
    }
    $recordCount = $report.diagnosticEntityCount
}
$absoluteOutput = [IO.Path]::GetFullPath($OutputPath)
# CreateNew refuses to overwrite an existing export, including a concurrent one.
$stream = [IO.File]::Open($absoluteOutput, [IO.FileMode]::CreateNew, [IO.FileAccess]::Write, [IO.FileShare]::None)
$writer = New-Object IO.StreamWriter($stream, (New-Object Text.UTF8Encoding($false)))
try { $writer.Write($json) } finally { $writer.Dispose() }
[pscustomobject]@{
    OutputPath = $absoluteOutput
    GameVersion = $report.gameVersion
    WorldPath = $report.worldPath
    VisitedSources = $report.visitedSourceCount
    RecordCount = $recordCount
    Kind = $report.kind
    CoordinateMismatches = $report.coordinateMismatchCount
}
