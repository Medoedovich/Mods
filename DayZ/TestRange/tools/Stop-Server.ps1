param([string]$Root=(Split-Path -Parent $PSScriptRoot), [switch]$Force)
$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'Server-Control.ps1')
Stop-DTRServer -Root $Root -Force:$Force
