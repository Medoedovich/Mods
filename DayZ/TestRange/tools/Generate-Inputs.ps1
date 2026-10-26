param([string]$Root = (Split-Path -Parent $PSScriptRoot))
$ErrorActionPreference = 'Stop'
$source = Join-Path $Root 'src\dtr\test_range\source'
$data = Join-Path $Root 'src\dtr\test_range\data'
New-Item -ItemType Directory -Force -Path $source,$data | Out-Null
$header = @('ncols 256','nrows 256','xllcorner 200000','yllcorner 0','cellsize 4','NODATA_value -9999')
$borderRow = ((1..256 | ForEach-Object {'-20.000000'}) -join ' ')
$innerRow = '-20.000000 ' + ((1..254 | ForEach-Object {'1.000000'}) -join ' ') + ' -20.000000'
$heightRows = 0..255 | ForEach-Object { if ($_ -eq 0 -or $_ -eq 255) { $borderRow } else { $innerRow } }
[IO.File]::WriteAllLines((Join-Path $source 'heightmap.asc'), $header + $heightRows, [Text.Encoding]::ASCII)
Add-Type -AssemblyName System.Drawing
function Write-SolidPng([string]$Path,[int]$Size,[int]$R,[int]$G,[int]$B) {
    $bitmap = New-Object Drawing.Bitmap $Size,$Size
    $graphics = [Drawing.Graphics]::FromImage($bitmap)
    try {
        $graphics.Clear([Drawing.Color]::FromArgb($R,$G,$B))
        $bitmap.Save($Path,[Drawing.Imaging.ImageFormat]::Png)
    } finally { $graphics.Dispose(); $bitmap.Dispose() }
}
Write-SolidPng (Join-Path $source 'sat_lco.png') 1024 137 137 133
Write-SolidPng (Join-Path $source 'mask_lco.png') 1024 255 0 255
Write-SolidPng (Join-Path $source 'normal_lco.png') 1024 128 128 255
foreach ($name in @('sat_lco','mask_lco','normal_lco')) {
    [IO.File]::WriteAllLines((Join-Path $source "$name.pgw"), @('1.0','0.0','0.0','-1.0','200000.5','1023.5'), [Text.Encoding]::ASCII)
}
Write-SolidPng (Join-Path $source 'mapLegend.png') 16 255 0 255
Write-SolidPng (Join-Path $data 'dtr_middlesat_mco.png') 256 128 128 128
Write-SolidPng (Join-Path $data 'dtr_global_nohq.png') 256 128 128 255
Write-SolidPng (Join-Path $data 'dtr_outside_co.png') 256 137 137 133
Write-Host 'Generated 256 x 256 height samples, 4 m cell: flat interior 1 m, outer sample ring -20 m; 1024 px rasters.'
