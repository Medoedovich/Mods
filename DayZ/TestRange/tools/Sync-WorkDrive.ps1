[CmdletBinding()]
param([string]$Root=(Split-Path -Parent $PSScriptRoot),[string]$WorkDrive='P:\',[switch]$Pull)
$ErrorActionPreference='Stop'
$local=Join-Path $Root 'src\dtr\test_range'
$drive=Join-Path $WorkDrive 'dtr\test_range'
if ($Pull) { $from=$drive; $to=$local } else { $from=$local; $to=$drive }
if (-not (Test-Path -LiteralPath $from)) { throw "Missing source: $from" }
New-Item -ItemType Directory -Force -Path $to | Out-Null
# Copy only. Never mirror or remove files. Pull after Terrain Builder exports.
Get-ChildItem -LiteralPath $from | Where-Object { $_.Name -notin @('_build','_edge_probe') } | ForEach-Object { Copy-Item -LiteralPath $_.FullName -Destination $to -Recurse -Force }
Write-Host "Copied $from -> $to"
