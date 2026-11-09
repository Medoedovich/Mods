# Regression cases: root distance must never hide an in-range container.
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
. (Join-Path $PSScriptRoot '../HarborNeighbors.ps1')
function Assert($ok,$message){if(!$ok){throw $message}}
function ValidPosition($p,$status){$status -ceq 'resolved' -and $p.Count -eq 3}
function PhysicalNodeName($node){$node.name}
function IsDescendant($id,$ancestor){while($id){if($id -ceq $ancestor){return $true};$id=$nodes[$id].parentSourceId};$false}
function WriteJson($path,$value){$script:result=$value}
$HarborRuntimeReportPath='';$snapshotId='fixture';$nodes=@{};$resources=@();$parents=@()
function Node($id,$parent,$xyz){$nodes[$id]=[pscustomobject]@{sourceId=$id;parentSourceId=$parent;worldPositionMeters=$xyz;positionStatus='resolved';prefab='fixture.et';name=$id}}
Node 'dock' '' @(0,0,0)
foreach($case in @(
    @('root-out',@(150,0,0),'child-in',@(99,0,0)),
    @('root-in',@(50,0,0),'child-out',@(101,0,0)),
    @('boundary-root',@(150,0,0),'boundary',@(0,0,100)),
    @('excluded-root',@(150,0,0),'excluded',@(100.001,0,0)),
    @('height-root',@(150,0,0),'height',@(0,101,0))
)){
    Node $case[0] '' $case[1];Node $case[2] $case[0] $case[3]
    $parents+=[pscustomobject]@{sourceId=$case[0];objectId=$case[0]}
    $resources+=[pscustomobject]@{sourceId=$case[2];componentIndex=0;containers=@([pscustomobject]@{index=0;className='SCR_ResourceContainer';fields=@([pscustomobject]@{name='m_eResourceType';enumLabel='SUPPLIES'})})}
}
Node 'virtual' 'root-out' @(99,0,0)
$resources+=[pscustomobject]@{sourceId='virtual';componentIndex=0;containers=@([pscustomobject]@{index=0;className='SCR_ResourceContainerVirtual';fields=@([pscustomobject]@{name='m_eResourceType';enumLabel='SUPPLIES'})})}
$inventory=[pscustomobject]@{resources=$resources};$other=[pscustomobject]@{records=$parents}
$rows=@{dock=[pscustomobject]@{sourceId='dock'}}
$saved=[pscustomobject]@{inputs=@{};groups=@([pscustomobject]@{id='dock';category='harbors';anchorObjectId='dock';name='dock';worldPositionMeters=@(0,0,0)})}
InitializeHarborNeighbors
$c=$script:result.records[0].containers
Assert ($c.Count -eq 4) 'Unexpected candidates/siblings'
Assert ('child-in' -cin $c.sourceId) 'Root outside hid child inside'
Assert ('child-out' -cin $c.sourceId) 'Outside sibling of inside root missing'
Assert ('boundary' -cin $c.sourceId) 'Inclusive 100m boundary failed'
Assert ('excluded' -cnotin $c.sourceId -and 'height' -cnotin $c.sourceId) 'Rounding or horizontal-distance error'
Assert (@($c | Where-Object rootOriginDisagreement).Count -eq 4) 'Discrepancy flags failed'
Assert (@($c | Where-Object virtual).Count -eq 1) 'Virtual slot excluded'
Assert (@($c | Where-Object runtimeStatus -eq not_measured).Count -eq 4) 'Invented runtime result'
'PASS: container/root disagreement, inclusive unrounded 3D boundary, virtual slot, unknown runtime.'
