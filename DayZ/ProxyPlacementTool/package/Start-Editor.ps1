[CmdletBinding()]
param(
    [string]$Game = '',
    [string]$TestRange = '',
    [string]$ExtraMods = '',
    [string]$ModRoot = '',
    [string]$RuntimeRoot = '',
    [switch]$CheckOnly,
    [switch]$SelfTest,
    [ValidateSet('','English','Russian')][string]$ExpectedLanguage = ''
)
$ErrorActionPreference = 'Stop'

function Test-EditorMap([string]$Path) {
    if (-not $Path) { return $false }
    foreach ($taskPart in @('world','data','ce')) {
        if (-not (Test-Path -LiteralPath (Join-Path $Path ('addons\dtr_test_range_'+$taskPart+'.pbo')) -PathType Leaf)) { return $false }
    }
    return $true
}

try {
    if (-not $ModRoot) { $ModRoot = $PSScriptRoot }
    $ModRoot = [IO.Path]::GetFullPath($ModRoot)
    if (-not (Test-Path -LiteralPath (Join-Path $ModRoot 'addons\iot_proxy_tool.pbo') -PathType Leaf)) { throw 'Editor PBO is missing. Run this script from the installed mod folder.' }
    $taskTemplate = Join-Path $ModRoot 'Missions\editor.dayztestrange'
    if (-not (Test-Path -LiteralPath (Join-Path $taskTemplate 'init.c') -PathType Leaf)) { throw 'Editor mission template is missing.' }

    $taskSteamRoots = New-Object 'System.Collections.Generic.List[string]'
    $taskLibraries = New-Object 'System.Collections.Generic.List[string]'
    $taskSteamSettings = Get-ItemProperty -LiteralPath 'HKCU:\Software\Valve\Steam' -ErrorAction SilentlyContinue
    if ($taskSteamSettings.SteamPath) { $taskSteamRoots.Add($taskSteamSettings.SteamPath) }
    if (${env:ProgramFiles(x86)}) { $taskSteamRoots.Add((Join-Path ${env:ProgramFiles(x86)} 'Steam')) }
    $taskAncestor = [IO.DirectoryInfo]$ModRoot
    while ($taskAncestor) {
        if ($taskAncestor.Name -ieq 'steamapps') { $taskLibraries.Add($taskAncestor.Parent.FullName) }
        $taskAncestor = $taskAncestor.Parent
    }
    foreach ($taskSteamRoot in @($taskSteamRoots | Select-Object -Unique)) {
        $taskLibraries.Add($taskSteamRoot)
        foreach ($taskVdf in @('steamapps\libraryfolders.vdf','config\libraryfolders.vdf')) {
            $taskLibraryFile = Join-Path $taskSteamRoot $taskVdf
            if (-not (Test-Path -LiteralPath $taskLibraryFile -PathType Leaf)) { continue }
            foreach ($taskLine in Get-Content -LiteralPath $taskLibraryFile) {
                if ($taskLine -match '^\s*"path"\s+"([^"]+)"') { $taskLibraries.Add($Matches[1].Replace('\\','\')) }
            }
        }
    }
    $taskLibraryPaths = @($taskLibraries | Select-Object -Unique)
    if (-not $Game) {
        foreach ($taskLibrary in $taskLibraryPaths) {
            $taskCandidate = Join-Path $taskLibrary 'steamapps\common\DayZ'
            if (Test-Path -LiteralPath (Join-Path $taskCandidate 'DayZDiag_x64.exe') -PathType Leaf) { $Game = $taskCandidate; break }
        }
    }
    if (-not $Game) { throw 'DayZDiag was not found. Install DayZ Tools, prepare DayZDiag, or pass -Game "path to DayZ". This alpha requires DayZDiag.' }
    $Game = (Resolve-Path -LiteralPath $Game).Path
    $taskExecutable = Join-Path $Game 'DayZDiag_x64.exe'
    if (-not (Test-Path -LiteralPath $taskExecutable -PathType Leaf)) { throw 'The selected game folder does not contain DayZDiag_x64.exe. Retail DayZ is not supported by this alpha.' }

    if (-not $TestRange) {
        $taskRangeCandidates = New-Object 'System.Collections.Generic.List[string]'
        $taskRangeCandidates.Add((Join-Path (Split-Path -Parent $ModRoot) '3826868718'))
        foreach ($taskLibrary in $taskLibraryPaths) { $taskRangeCandidates.Add((Join-Path $taskLibrary 'steamapps\workshop\content\221100\3826868718')) }
        foreach ($taskCandidate in @($taskRangeCandidates | Select-Object -Unique)) {
            if (Test-EditorMap $taskCandidate) { $TestRange = $taskCandidate; break }
        }
    }
    if (-not (Test-EditorMap $TestRange)) { throw 'Test Range is missing or incomplete. Subscribe to Workshop item 3826868718, or pass -TestRange "path to Test Range".' }
    $TestRange = (Resolve-Path -LiteralPath $TestRange).Path
    $taskMods = @($TestRange,$ModRoot)
    if ($ExtraMods) {
        foreach ($taskExtra in $ExtraMods.Split(';')) {
            if (-not [IO.Path]::IsPathRooted($taskExtra) -or -not (Test-Path -LiteralPath $taskExtra -PathType Container)) { throw 'ExtraMods must contain existing absolute mod-folder paths separated by semicolons.' }
            $taskMods += (Resolve-Path -LiteralPath $taskExtra).Path
        }
    }
    if (-not $RuntimeRoot) { $RuntimeRoot = Join-Path ([Environment]::GetFolderPath('LocalApplicationData')) 'ProxyPlacementTool' }
    $RuntimeRoot = [IO.Path]::GetFullPath($RuntimeRoot)
    $taskProfiles = Join-Path $RuntimeRoot 'profiles'
    Write-Host 'Proxy Placement Tool - Alpha 0.1.0 / Medoedovich'
    Write-Host ('DayZDiag: '+$taskExecutable)
    Write-Host ('Test Range: '+$TestRange)
    Write-Host ('Editor: '+$ModRoot)
    Write-Host ('Exports: '+(Join-Path $taskProfiles 'ProxyPlacement'))
    Write-Host 'ALPHA: project save/load is not available. Export XML before exiting.'
    if ($CheckOnly) { Write-Host 'Preflight OK. No files changed and no game started.'; exit 0 }
    $taskExisting = @(Get-CimInstance Win32_Process -Filter "Name='DayZDiag_x64.exe' OR Name='DayZ_x64.exe'" | Where-Object { $_.CommandLine -notmatch '(?i)(?:^|\s)-server(?:\s|$)' })
    if ($taskExisting.Count) { throw 'A DayZ client is already running. Close it before starting the editor.' }
    if (-not (Get-Process -Name steam -ErrorAction SilentlyContinue)) { throw 'Start Steam before launching the editor.' }

    $taskSession = Join-Path (Join-Path $RuntimeRoot 'sessions') ([guid]::NewGuid().ToString('N'))
    $taskMission = Join-Path $taskSession 'editor.dayztestrange'
    [IO.Directory]::CreateDirectory($taskProfiles) | Out-Null
    [IO.Directory]::CreateDirectory($taskMission) | Out-Null
    Get-ChildItem -LiteralPath $taskTemplate -Force | Copy-Item -Destination $taskMission -Recurse
    $taskStart = New-Object Diagnostics.ProcessStartInfo
    $taskStart.FileName = $taskExecutable
    $taskStart.WorkingDirectory = $Game
    $taskStart.UseShellExecute = $false
    $taskStart.EnvironmentVariables['SteamAppId'] = '221100'
    $taskStart.EnvironmentVariables['SteamGameId'] = '221100'
    $taskArguments = @(('"-mod='+($taskMods -join ';')+'"'),('"-mission='+$taskMission+'"'),('"-profiles='+$taskProfiles+'"'),('"-storage='+(Join-Path $taskSession 'storage')+'"'),'-window','-noPause','-noSplash','-doLogs')
    if ($SelfTest) { $taskArguments += '-proxyToolSelfTest=1' }
    if ($SelfTest -and $ExpectedLanguage) { $taskArguments += ('-proxyToolExpectedLanguage='+$ExpectedLanguage) }
    $taskStart.Arguments = $taskArguments -join ' '
    $taskProcess = [Diagnostics.Process]::Start($taskStart)
    $taskLaunch = [ordered]@{Version='0.1.0-alpha';StartedAt=(Get-Date -Format o);PID=$taskProcess.Id;Game=$Game;Mod=$ModRoot;TestRange=$TestRange;Mission=$taskMission;Profiles=$taskProfiles;SelfTest=[bool]$SelfTest}
    $taskLaunch | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $RuntimeRoot 'last-launch.json') -Encoding UTF8
    $taskLaunch | ConvertTo-Json
} catch {
    Write-Host ('ERROR: '+$_.Exception.Message) -ForegroundColor Red
    exit 1
}
