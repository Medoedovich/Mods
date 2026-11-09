<# Locate supply depots and reserve nearby storage first, then classify remaining parents.
   All spatial links remain proximity observations, not gameplay ownership. #>
[CmdletBinding()]
param(
    [Parameter(Mandatory=$true)][string]$ControlPointsReportPath,
    [Parameter(Mandatory=$true)][string]$SupplyDepotsReportPath,
    [Parameter(Mandatory=$true)][string]$ControlPointStorageReportPath,
    [Parameter(Mandatory=$true)][string]$LocationsReportPath,
    [Parameter(Mandatory=$true)][string]$OtherContainersViewPath,
    [Parameter(Mandatory=$true)][string]$HarborsViewPath,
    [Parameter(Mandatory=$true)][string]$WorldContainersReportPath,
    [Parameter(Mandatory=$true)][string]$OutputDirectory,
    [string]$HarborRuntimeReportPath,
    [string]$StartingBasesReportPath,
    [string]$ControlPointMapLinksPath=(Join-Path $PSScriptRoot 'config/ControlPointMapLinks.json'),
    [ValidateRange(0.001,100000)][double]$RadiusMeters=350,
    [ValidateRange(0.001,100000)][double]$DepotRadiusMeters=200,
    [ValidatePattern('^r[0-9]{4}$')][string]$RevisionId='r0046',
    [Parameter(Mandatory=$true)][string]$RevisionReason
)
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
$culture=[Globalization.CultureInfo]::InvariantCulture
function Assert($condition,$message){if(!$condition){throw $message}}
function ReadInput($path){$full=(Resolve-Path -LiteralPath $path).Path;[pscustomobject]@{hash=(Get-FileHash -LiteralPath $full).Hash;value=(Get-Content -LiteralPath $full -Raw -Encoding utf8 | ConvertFrom-Json)}}
function Same($a,$b){($a | ConvertTo-Json -Depth 40 -Compress) -ceq ($b | ConvertTo-Json -Depth 40 -Compress)}
function ValidPosition($p,$status){if($status -cne 'resolved' -or @($p).Count -ne 3){return $false};foreach($v in $p){if($null -eq $v -or [double]::IsNaN([double]$v) -or [double]::IsInfinity([double]$v)){return $false}};$true}
$output=[IO.Path]::GetFullPath($OutputDirectory);Assert (!(Test-Path -LiteralPath $output)) 'Output exists; select a new revision.'
$cpInput=ReadInput $ControlPointsReportPath;$locInput=ReadInput $LocationsReportPath;$otherInput=ReadInput $OtherContainersViewPath;$harborInput=ReadInput $HarborsViewPath
$inventoryInput=ReadInput $WorldContainersReportPath;$inventory=$inventoryInput.value
$cp=$cpInput.value;$oldLocations=$locInput.value;$other=$otherInput.value;$harbors=$harborInput.value
$depotInput=ReadInput $SupplyDepotsReportPath;$depots=$depotInput.value
Assert ($depots.schemaVersion -eq 2 -and $depots.kind -ceq 'campaign-remnants-supply-depots' -and $depots.selection -ceq 'CampaignRemnantsSupplyDepot-prefab' -and $depots.records.Count -eq $depots.recordCount -and $depots.editorEntityCountUnchanged -and $depots.coordinateMismatchCount -eq 0 -and @($depots.records.sourceId | Sort-Object -Unique).Count -eq $depots.recordCount) 'Invalid native supply-depot export.'
Assert ($cp.schemaVersion -eq 2 -and $cp.kind -ceq 'conflict-control-points' -and $cp.selection -ceq 'ConflictControlPoint-prefab' -and $cp.records.Count -eq $cp.recordCount -and $cp.editorEntityCountUnchanged -and $cp.coordinateMismatchCount -eq 0) 'Invalid native control-point export.'
Assert ($oldLocations.kind -ceq 'location-radius-catalog' -and $oldLocations.schemaVersion -eq 2) 'Invalid map/location seed.'
Assert ($other.kind -ceq 'location-grouped-supply-view' -and $other.category -ceq 'other_supply_parent' -and $harbors.kind -ceq 'location-grouped-supply-view' -and $harbors.category -ceq 'supply_source_base') 'Invalid previous supply views.'
$version=$oldLocations.gameVersion;$scenario=$oldLocations.scenarioKey;$snapshotId="$version/$scenario/$RevisionId";$normalizer='supply-priority-architecture-0.27'
$commandPostInput=ReadInput $ControlPointStorageReportPath;$commandPosts=$commandPostInput.value
Assert ($commandPosts.schemaVersion -eq 2 -and $commandPosts.kind -ceq 'control-point-command-post-storage' -and $commandPosts.gameVersion -ceq $version -and $commandPosts.worldPath -ceq $cp.worldPath -and $commandPosts.recordCount -eq 3 -and $commandPosts.records.Count -eq 3 -and !$commandPosts.runtimeMeasured) 'Invalid command-post storage comparison.'
Assert (Same @($commandPosts.records.variantId | Sort-Object) @('FIA','US','USSR')) 'Missing command-post variant.'
foreach($storage in $commandPosts.records){
    Assert ($storage.capacityStatus -ceq 'resolved' -and $storage.maximumAction.m_bShouldChangeMaximum -and $storage.maximumAction.m_fResourceValueMax -eq $storage.capacitySupplies) 'Unresolved or disabled command-post capacity action.'
    Assert ($storage.physicalContainerCount -eq @($storage.physicalSlotsBeforeAction | Where-Object className -ceq 'SCR_ResourceContainer').Count -and $storage.virtualContainerCount -eq @($storage.virtualSlotsBeforeAction | Where-Object className -ceq 'SCR_ResourceContainerVirtual').Count -and $storage.physicalContainerCount -gt 0) 'Command-post physical count differs.'
    $total=0;$count=0;foreach($part in $storage.capacityComposition){$total+=$part.containerCount*$part.capacitySupplies;$count+=$part.containerCount}
    Assert ($total -eq $storage.capacitySupplies -and $count -eq $storage.physicalContainerCount) 'Command-post composition does not equal capacity/count.'
    $ordinary=[int][Math]::Floor($storage.capacitySupplies/$storage.physicalContainerCount);$remainder=$storage.capacitySupplies-$ordinary*($storage.physicalContainerCount-1)
    $expected=$(if($ordinary -eq $remainder){@([ordered]@{containerCount=$storage.physicalContainerCount;capacitySupplies=$ordinary})}else{@([ordered]@{containerCount=$storage.physicalContainerCount-1;capacitySupplies=$ordinary},[ordered]@{containerCount=1;capacitySupplies=$remainder})})
    Assert (Same $storage.capacityComposition $expected) 'Command-post allocation differs from installed action rule.'
    if($storage.configuredInitialStatus -ceq 'resolved'){
        Assert ($storage.configuredInitialScope -ceq 'command_post_storage_after_encapsulator_action' -and $null -ne $storage.configuredInitialSupplies -and ![double]::IsNaN([double]$storage.configuredInitialSupplies) -and ![double]::IsInfinity([double]$storage.configuredInitialSupplies) -and $storage.configuredInitialSupplies -ge 0 -and $storage.configuredInitialSupplies -le $storage.capacitySupplies -and $storage.maximumAction.m_fResourceValueCurrent -eq $storage.configuredInitialSupplies) 'Invalid command-post initial target or scope.'
        Assert ($storage.initialSuppliesEvidence.Count -eq 2 -and (Same @($storage.initialSuppliesEvidence.rootPrefab | Sort-Object) @(@($storage.storagePrefab,$storage.headquartersEditablePrefab) | Sort-Object)) -and @($storage.initialSuppliesEvidence | Where-Object {$_.status -cne 'resolved' -or $_.property -cne 'm_fResourceValueCurrent' -or $_.instanceGetter -cne 'GetValueCurrent' -or $_.value -ne $storage.configuredInitialSupplies -or $_.instanceGetterValue -ne $storage.configuredInitialSupplies}).Count -eq 0) 'Initial action field/getter evidence differs.'
    }
}
$commonCapacities=@($commandPosts.records.capacitySupplies | Sort-Object -Unique)
Assert ($commonCapacities.Count -eq 1) 'Command-post variant capacities differ; review display before using one capacity.'
$resolvedInitial=@($commandPosts.records | Where-Object configuredInitialStatus -ceq 'resolved')
$initialValues=@($resolvedInitial.configuredInitialSupplies | Sort-Object -Unique)
$commonInitial=[ordered]@{value=$null;status='unknown';scope='command_post_storage_after_encapsulator_action'}
if($resolvedInitial.Count -eq 3){Assert ($initialValues.Count -eq 1) 'Command-post initial targets differ; review display.';$commonInitial.value=$initialValues[0];$commonInitial.status='resolved'}
Assert ($depots.gameVersion -ceq $version -and $depots.worldPath -ceq $cp.worldPath) 'Supply-depot world/version mismatch.'
$mapLinksInput=ReadInput $ControlPointMapLinksPath
Assert ($mapLinksInput.value.schemaVersion -eq 1 -and $mapLinksInput.value.kind -ceq 'user-confirmed-control-point-map-links') 'Invalid explicit control-point/map links.'
$activeMapLinks=@($mapLinksInput.value.rules | Where-Object {$_.gameVersion -ceq $version -and $_.scenarioKey -ceq $scenario})
Assert ($cp.gameVersion -ceq $version -and $cp.worldPath.EndsWith("/$scenario.ent")) 'Control-point world/version mismatch.'
foreach($view in @($other,$harbors)){Assert ($view.gameVersion -ceq $version -and $view.scenarioKey -ceq $scenario -and $view.inputs.locations.sha256 -ceq $locInput.hash -and $view.records.Count -eq $view.summary.objectCount) 'Supply seed identity/hash mismatch.'}
Assert ($inventory.kind -ceq 'world-supply-containers' -and $inventory.schemaVersion -eq 2 -and $inventory.gameVersion -ceq $version -and $inventory.worldPath -ceq $cp.worldPath -and $inventory.editorEntityCountUnchanged -and $inventory.coordinateMismatchCount -eq 0) 'Invalid supply hierarchy inventory.'
$originalOtherPath=[IO.Path]::GetFullPath((Join-Path (Split-Path -Parent ([IO.Path]::GetFullPath($OtherContainersViewPath))) $other.inputs.supplies.path))
$originalOtherInput=ReadInput $originalOtherPath
Assert ($originalOtherInput.hash -ceq $other.inputs.supplies.sha256 -and $originalOtherInput.value.sourceReportSha256 -ceq $inventoryInput.hash) 'Supply hierarchy differs from original OtherContainers inventory.'
$nodes=@{};foreach($node in $inventory.nodes){Assert (!$nodes.ContainsKey($node.sourceId)) 'Duplicate hierarchy node.';$nodes[$node.sourceId]=$node}
function IsDescendant($sourceId,$ancestorId){$visited=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);$id=$sourceId;while($id){Assert ($visited.Add($id)) 'Parent cycle in inventory.';if($id -ceq $ancestorId){return $true};Assert ($nodes.ContainsKey($id)) 'Incomplete source parent chain.';$id=$nodes[$id].parentSourceId};$false}
$physicalSlots=@(foreach($resource in $inventory.resources){foreach($slot in $resource.containers){if($slot.className -cne 'SCR_ResourceContainer'){continue};$type=@($slot.fields | Where-Object name -ceq 'm_eResourceType');Assert ($type.Count -eq 1 -and $type[0].status -ceq 'resolved' -and $type[0].enumLabel -ceq 'SUPPLIES') 'Unexpected physical resource type.';[ordered]@{id="$($resource.sourceId)/$($resource.componentIndex)/$($slot.index)";sourceId=$resource.sourceId;componentIndex=$resource.componentIndex;containerIndex=$slot.index;fields=$slot.fields}}})
function RevisionPath($source,$file){Assert ($source.snapshotId -match "^$([regex]::Escape($version))/$([regex]::Escape($scenario))/(r[0-9]{4})$") 'Invalid previous snapshot identity.';"../$($Matches[1])/$file"}
$inputs=[ordered]@{controlPoints=[ordered]@{sha256=$cpInput.hash;capturedAtUTC=$cp.generatedAtUTC;analyzerVersion=$cp.analyzerVersion};locations=[ordered]@{path=(RevisionPath $oldLocations 'Locations.json');sha256=$locInput.hash;capturedAtUTC=$oldLocations.capturedAtUTC};otherContainers=[ordered]@{path=(RevisionPath $other 'Supplies/OtherContainers.json');sha256=$otherInput.hash;originalSupplies=$other.inputs.supplies};harbors=[ordered]@{path=(RevisionPath $harbors 'Supplies/Harbors.json');sha256=$harborInput.hash;originalSupplies=$harbors.inputs.supplies}}
$inputs.worldContainers=[ordered]@{sha256=$inventoryInput.hash;capturedAtUTC=$inventory.generatedAtUTC;originalOtherContainersSnapshot=$originalOtherInput.value.snapshotId;originalOtherContainersPath=(RevisionPath $originalOtherInput.value 'Supplies/OtherContainers.json');originalOtherContainersSha256=$originalOtherInput.hash}
$inputs.controlPointMapLinks=[ordered]@{kind=$mapLinksInput.value.kind;sha256=$mapLinksInput.hash;rules=$activeMapLinks}
$inputs.supplyDepots=[ordered]@{sha256=$depotInput.hash;capturedAtUTC=$depots.generatedAtUTC;analyzerVersion=$depots.analyzerVersion}
function CfgInteger($record,$componentClass,$fieldName){$fields=@($record.components | Where-Object className -ceq $componentClass | ForEach-Object fields | Where-Object name -ceq $fieldName);if($fields.Count -ne 1 -or $fields[0].status -cne 'resolved'){return [ordered]@{value=$null;status='unknown'}};[ordered]@{value=[int]::Parse($fields[0].value,$culture);status='resolved'}}
function CfgValue($record,$componentClass,$fieldName,$type){$fields=@($record.components | Where-Object className -ceq $componentClass | ForEach-Object fields | Where-Object name -ceq $fieldName);if($fields.Count -ne 1 -or $fields[0].status -cne 'resolved'){return [ordered]@{value=$null;status='unknown'}};$value=$(if($type -ceq 'bool'){[bool]::Parse($fields[0].value)}else{[double]::Parse($fields[0].value,$culture)});[ordered]@{value=$value;status='resolved'}}
$controlRecords=@(foreach($record in ($cp.records | Sort-Object displayName,sourceId)){
    Assert ($record.prefab -match '/ConflictControlPoint[^/]*\.et$') 'Unexpected control-point prefab.'
    Assert ($record.prefab -ceq $commandPosts.controlPointPrefab) 'Control-point prefab differs from the verified command-post scope.'
    [ordered]@{objectId="control_point/$($record.sourceId)";sourceId=$record.sourceId;sourceName=$record.sourceName;name=$record.displayName;nameStatus=$record.nameStatus;worldPositionMeters=@($record.worldPositionMeters);positionStatus=$record.positionStatus;prefab=$record.prefab;configuredComponentSupplies=(CfgInteger $record 'SCR_CampaignSuppliesComponent' 'm_iSupplies');configuredComponentSuppliesMax=(CfgInteger $record 'SCR_CampaignSuppliesComponent' 'm_iSuppliesMax');runtimeResourceGridCapacityStatus='not_analyzed';rawName=$record.rawName;nameMethod=$record.nameMethod;language=$cp.language;provenance=$record.components;commandPostStorage=[ordered]@{catalog='ControlPointStorage.json';capacitySupplies=$commonCapacities[0];capacityStatus='resolved';capacityScope='command_post_storage_composition';configuredInitialSupplies=$commonInitial.value;configuredInitialStatus=$commonInitial.status;configuredInitialScope=$commonInitial.scope;runtimeInitialSuppliesStatus='not_measured';variantIds=@($commandPosts.records.variantId);selectedVariantStatus='not_determined';runtimeMeasured=$false}}
})
$depotRecords=@(foreach($record in ($depots.records | Sort-Object sourceId)){
    Assert ($record.prefab -cmatch '/CampaignRemnantsSupplyDepot\.et$') 'Unexpected supply-depot prefab.'
    [ordered]@{objectId="supply_depot/$($record.sourceId)";sourceId=$record.sourceId;sourceName=$record.sourceName;name=$(if($record.sourceName){$record.sourceName}else{[IO.Path]::GetFileNameWithoutExtension($record.prefab)});labelMethod=$(if($record.sourceName){'source_name'}else{'prefab_stem'});worldPositionMeters=@($record.worldPositionMeters);positionStatus=$record.positionStatus;prefab=$record.prefab;subscene=$record.subscene;layer=$record.layer;enabled=(CfgValue $record 'SCR_CampaignSuppliesComponent' 'Enabled' 'bool');configuredComponentSupplies=(CfgInteger $record 'SCR_CampaignSuppliesComponent' 'm_iSupplies');configuredComponentSuppliesMax=(CfgInteger $record 'SCR_CampaignSuppliesComponent' 'm_iSuppliesMax');operationalRadiusMeters=(CfgValue $record 'SCR_CampaignSuppliesComponent' 'm_fOperationalRadius' 'number');standaloneDepot=(CfgValue $record 'SCR_CampaignSuppliesComponent' 'm_bIsStandaloneDepot' 'bool');runtimeResourceGridCapacityStatus='not_analyzed';provenance=$record.components}
})
$objects=[Collections.Generic.List[object]]::new();$objectIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach($type in @('control_points','harbors','other_containers','supply_depots')){
    $records=switch($type){'control_points'{$controlRecords} 'harbors'{$harbors.records} 'other_containers'{$other.records} 'supply_depots'{$depotRecords}}
    foreach($record in $records){Assert ($objectIds.Add($record.objectId)) 'Duplicate catalog object.';$objects.Add([pscustomobject][ordered]@{id=$record.objectId;sourceId=$record.sourceId;name=$(if($type -ceq 'control_points'){$record.sourceName}else{$record.name});displayName=$record.name;category=$type;worldPositionMeters=@($record.worldPositionMeters);positionStatus=$record.positionStatus;sourceReport=$(switch($type){'control_points'{'Supplies/ControlPoints.json'} 'harbors'{'Supplies/Harbors.json'} 'supply_depots'{'Supplies/SupplyDepots.json'} default{'Supplies/OtherContainers.json'}})})}
}
$settlementTypes=@('Name City','Name Town','Name Village','Name Settlement');$otherTypes=@('Name Generic','Name Island','Name Hill')
$categories=@('supply_depots','control_points','harbors','settlements','other','unrecognized')
$mapClassificationCategories=@('control_points','harbors','settlements','other')
$groups=[Collections.Generic.List[object]]::new()
function AddGroup($id,$category,$name,$p,$status,$anchorObjectId,$origin){$groups.Add([pscustomobject][ordered]@{id=$id;category=$category;name=$name;worldPositionMeters=@($p);positionStatus=$status;anchorObjectId=$anchorObjectId;origin=$origin;members=@();physicalDescendantContainers=@();mergedMapLocations=@();mergedIntoGroupId=$null})}
foreach($record in $controlRecords){AddGroup "control-point/$($record.sourceId)" 'control_points' $record.name $record.worldPositionMeters $record.positionStatus $record.objectId 'ConflictControlPoint_prefab'}
foreach($record in ($harbors.records | Sort-Object name,sourceId)){AddGroup "harbor/$($record.sourceId)" 'harbors' $record.name $record.worldPositionMeters $record.positionStatus $record.objectId 'supply_source_base'}
foreach($record in $depotRecords){AddGroup "supply-depot/$($record.sourceId)" 'supply_depots' $record.name $record.worldPositionMeters $record.positionStatus $record.objectId 'CampaignRemnantsSupplyDepot_prefab'}
foreach($group in $groups){$sourceId=($objects | Where-Object id -ceq $group.anchorObjectId).sourceId;$group.physicalDescendantContainers=@($physicalSlots | Where-Object {IsDescendant $_.sourceId $sourceId})}
$markerFields=@($oldLocations.locations[0].PSObject.Properties.Name | Where-Object {$_ -notin @('nearbyObjectCount','nearbyObjects','matchingEligible','matchingExclusionReason','matchingTier')})
$mapInventory=@($oldLocations.locations | Select-Object $markerFields)
foreach($marker in $mapInventory){if($marker.descriptorType -in $settlementTypes){AddGroup "map/$($marker.id)" 'settlements' $marker.name $marker.worldPositionMeters $marker.positionStatus $null $marker.descriptorType}elseif($marker.descriptorType -in $otherTypes){AddGroup "map/$($marker.id)" 'other' $marker.name $marker.worldPositionMeters $marker.positionStatus $null $marker.descriptorType}}
$policy=[ordered]@{order=$categories;radiusMeters=$RadiusMeters;radiusScope='map_location_stages_only';scope='remaining_other_supply_parents';sourceAnchorRule='confirmed_source_parent_hierarchy';anchorInventoryRule='all_control_points_and_source_bases_are_shown_once_in_their_own_category';withinStage='all_matches';settlementDescriptorTypes=$settlementTypes;otherDescriptorTypes=$otherTypes;otherMapTypes='excluded';ownershipEstablished=$false}
$policy.controlPointMapGroupMerge=[ordered]@{phase='after_source_and_map_classification';correspondenceMethods=@('normalized_display_name','localization_key_prefab_identity','user_confirmed_nearby_location');explicitLinkPriority='before_automatic_identity_matching_for_that_control_point';explicitLinkScope='exact_game_version_scenario_and_source_ids';maximumAnchorDistanceMeters=$RadiusMeters;ambiguousMatch='reject';memberRule='transfer_existing_map_group_members_and_remove_from_lower_categories';radiusOrigin='original_map_label';displayDistanceOrigin='control_point_source';sourceParentEstablished=$false;ownershipEstablished=$false}
$policy.radiusScope='map_location_matching_control_point_label_correspondence_and_depot_marker_location_matching'
$policy.supplyDepotRule=[ordered]@{selection='CampaignRemnantsSupplyDepot_prefab';protectedCategories=@();phase='after_depot_location_matching_before_other_classification';memberRule='horizontal_radius_proximity';radiusMeters=$DepotRadiusMeters;distanceOrigin='supply_depot_marker';positionOrigin='other_container_root_parent';withinStage='all_matches';removeAssignedParentsFromLaterStages=$true;ownershipEstablished=$false}
$policy.supplyDepotLocationRule=[ordered]@{scope='supply_depot_markers_only';radiusMeters=$RadiusMeters;order=@('settlements','other');settlementDescriptorTypes=$settlementTypes;otherDescriptorTypes=$otherTypes;selection='nearest_in_first_matching_tier';equalDistanceTieBreak='map_location_id';unmatched='retain_without_location';sourceParentEstablished=$false;ownershipEstablished=$false}
$depotLocationAssociations=[Collections.Generic.List[object]]::new()
foreach($depotGroup in ($groups | Where-Object category -ceq 'supply_depots')){
    $candidates=@(foreach($marker in $mapInventory){
        if($marker.descriptorType -notin ($settlementTypes+$otherTypes) -or $marker.nameStatus -cne 'resolved' -or [string]::IsNullOrWhiteSpace($marker.name)){continue}
        if(!(ValidPosition $depotGroup.worldPositionMeters $depotGroup.positionStatus) -or !(ValidPosition $marker.worldPositionMeters $marker.positionStatus)){continue}
        $dx=[double]$depotGroup.worldPositionMeters[0]-[double]$marker.worldPositionMeters[0];$dz=[double]$depotGroup.worldPositionMeters[2]-[double]$marker.worldPositionMeters[2]
        $d2=$dx*$dx+$dz*$dz;if($d2 -gt $RadiusMeters*$RadiusMeters){continue}
        [pscustomobject][ordered]@{mapLocationId=$marker.id;tier=$(if($marker.descriptorType -in $settlementTypes){'settlements'}else{'other'});tierRank=$(if($marker.descriptorType -in $settlementTypes){0}else{1});distanceMeters=[Math]::Sqrt($d2)}
    })
    $candidates=@($candidates | Sort-Object tierRank,distanceMeters,mapLocationId)
    $selected=$(if($candidates.Count){$candidates[0]}else{$null})
    $depotLocationAssociations.Add([pscustomobject][ordered]@{depotGroupId=$depotGroup.id;depotObjectId=$depotGroup.anchorObjectId;mapLocationId=$(if($selected){$selected.mapLocationId}else{$null});distanceMeters=$(if($selected){$selected.distanceMeters}else{$null});tier=$(if($selected){$selected.tier}else{$null});status=$(if($selected){'matched'}elseif(ValidPosition $depotGroup.worldPositionMeters $depotGroup.positionStatus){'no_eligible_location_within_radius'}else{'position_unknown_or_invalid'});method='nearest_named_location_in_priority_tier';sourceParentEstablished=$false;ownershipEstablished=$false;candidates=$candidates})
}
$depotRegions=@(foreach($marker in $mapInventory){
    $associated=@($depotLocationAssociations | Where-Object {$_.status -ceq 'matched' -and $_.mapLocationId -ceq $marker.id})
    if(!$associated.Count){continue}
    [pscustomobject][ordered]@{id="depot-location/$($marker.id)";mapLocationId=$marker.id;name=$marker.name;descriptorType=$marker.descriptorType;worldPositionMeters=$marker.worldPositionMeters;positionStatus=$marker.positionStatus;depots=@($associated | Sort-Object depotGroupId)}
})
$depotRegions=@($depotRegions | Sort-Object name,mapLocationId)
$depotLocationGrouping=[ordered]@{policy=$policy.supplyDepotLocationRule;locations=$depotRegions;unlocatedDepots=@($depotLocationAssociations | Where-Object status -cne 'matched' | Sort-Object depotGroupId);associations=@($depotLocationAssociations.ToArray())}
# Determine each depot's named location before collecting storage within its own radius.
# Assigned root parents are excluded from every later source/map classification stage.
$depotAssignedIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach($group in ($groups | Where-Object category -ceq 'supply_depots')){
    foreach($record in $other.records){
        if(!(ValidPosition $record.worldPositionMeters $record.positionStatus) -or !(ValidPosition $group.worldPositionMeters $group.positionStatus)){continue}
        $dx=[double]$record.worldPositionMeters[0]-[double]$group.worldPositionMeters[0];$dz=[double]$record.worldPositionMeters[2]-[double]$group.worldPositionMeters[2]
        $d2=$dx*$dx+$dz*$dz
        if($d2 -le $DepotRadiusMeters*$DepotRadiusMeters){
            $group.members+=@([pscustomobject][ordered]@{objectId=$record.objectId;distanceMeters=[Math]::Sqrt($d2);method='horizontal_radius_proximity';distanceOrigin='supply_depot_marker';sourceParentEstablished=$false;ownershipEstablished=$false})
            $null=$depotAssignedIds.Add($record.objectId)
        }
    }
    $group.members=@($group.members | Sort-Object distanceMeters,objectId)
}
$remaining=@($other.records | Where-Object {!$depotAssignedIds.Contains($_.objectId)});$stageSummary=[ordered]@{}
foreach($category in $mapClassificationCategories){
    $stageGroups=@($groups | Where-Object category -ceq $category);$next=[Collections.Generic.List[object]]::new();$assigned=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);$links=0
    $members=@{};foreach($group in $stageGroups){$members[$group.id]=[Collections.Generic.List[object]]::new()}
    foreach($record in $remaining){$matched=$false
        foreach($group in $stageGroups){
            $byHierarchy=$category -in @('control_points','harbors')
            $distance=$null
            if((ValidPosition $record.worldPositionMeters $record.positionStatus) -and (ValidPosition $group.worldPositionMeters $group.positionStatus)){$dx=[double]$record.worldPositionMeters[0]-[double]$group.worldPositionMeters[0];$dz=[double]$record.worldPositionMeters[2]-[double]$group.worldPositionMeters[2];$d2=$dx*$dx+$dz*$dz;$distance=[Math]::Sqrt($d2)}
            $hit=$(if($byHierarchy){$anchorSource=($objects | Where-Object id -ceq $group.anchorObjectId).sourceId;IsDescendant $record.sourceId $anchorSource}else{$null -ne $distance -and $d2 -le $RadiusMeters*$RadiusMeters})
            if($hit){$members[$group.id].Add([ordered]@{objectId=$record.objectId;distanceMeters=$distance;method=$(if($byHierarchy){'source_parent_hierarchy'}else{'horizontal_radius_proximity'});sourceParentEstablished=$byHierarchy;ownershipEstablished=$false});$matched=$true;$links++}
        }
        if($matched){$null=$assigned.Add($record.objectId)}else{$next.Add($record)}
    }
    foreach($group in $stageGroups){$group.members=@($members[$group.id] | Sort-Object distanceMeters,objectId)}
    $stageSummary[$category]=[ordered]@{anchorCount=$stageGroups.Count;assignedParentCount=$assigned.Count;associationCount=$links;populatedGroupCount=@($stageGroups | Where-Object {$_.members.Count -gt 0}).Count}
    $remaining=@($next.ToArray())
}
# Consolidate existing map groups after classification: retain their membership evidence,
# rather than applying a new radius around the control-point source position.
function HorizontalDistance($a,$b){$dx=[double]$a[0]-[double]$b[0];$dz=[double]$a[2]-[double]$b[2];[Math]::Sqrt($dx*$dx+$dz*$dz)}
function NormalizedName($name){([regex]::Replace(([string]$name).Trim(),'\s+',' ')).ToUpperInvariant()}
$mapMerges=[Collections.Generic.List[object]]::new()
$usedMarkers=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach($rule in $activeMapLinks){
    Assert ($rule.approval -ceq 'user_instruction' -and ![string]::IsNullOrWhiteSpace($rule.id)) 'Unconfirmed explicit link.'
    Assert (@($controlRecords | Where-Object {$_.sourceId -ceq $rule.controlPointSourceId -and $_.rawName -ceq $rule.controlPointRawName}).Count -eq 1) 'Explicit link control point is missing or ambiguous.'
    Assert (@($mapInventory | Where-Object id -ceq $rule.mapLocationId).Count -eq 1) 'Explicit link map label is missing or ambiguous.'
}
foreach($control in $controlRecords){
    $target=@($groups | Where-Object anchorObjectId -CEQ $control.objectId)[0]
    $explicitLinks=@($activeMapLinks | Where-Object controlPointSourceId -ceq $control.sourceId)
    Assert ($explicitLinks.Count -le 1) 'Multiple explicit links for one control point.'
    $candidates=@(foreach($marker in $mapInventory){
        if($marker.descriptorType -notin ($settlementTypes+$otherTypes) -or $control.nameStatus -cne 'resolved' -or $marker.nameStatus -cne 'resolved'){continue}
        if(!(ValidPosition $control.worldPositionMeters $control.positionStatus) -or !(ValidPosition $marker.worldPositionMeters $marker.positionStatus)){continue}
        $dx=[double]$control.worldPositionMeters[0]-[double]$marker.worldPositionMeters[0];$dz=[double]$control.worldPositionMeters[2]-[double]$marker.worldPositionMeters[2]
        if($dx*$dx+$dz*$dz -gt $RadiusMeters*$RadiusMeters){continue}
        $method=$null
        if($explicitLinks.Count){if($marker.id -ceq $explicitLinks[0].mapLocationId){$method='user_confirmed_nearby_location'}}
        elseif(![string]::IsNullOrWhiteSpace($control.name) -and (NormalizedName $control.name) -ceq (NormalizedName $marker.name)){$method='normalized_display_name'}
        elseif($control.rawName -cmatch '^#AR-Campaign_MapLocation_(.+)$'){
            $keyIdentity=$Matches[1]
            $prefabIdentity=[regex]::Replace([IO.Path]::GetFileNameWithoutExtension($marker.prefab),'_[0-9]+$','')
            if($keyIdentity -ceq $prefabIdentity){$method='localization_key_prefab_identity'}
        }
        if($method){[pscustomobject]@{marker=$marker;method=$method;distance=[Math]::Sqrt($dx*$dx+$dz*$dz)}}
    })
    Assert ($candidates.Count -le 1) "Ambiguous corresponding map label for $($control.name); review identities before merging."
    Assert (!$explicitLinks.Count -or $candidates.Count -eq 1) 'Explicit link lacks resolved eligible positions/names or exceeds the anchor radius.'
    if(!$candidates.Count){continue}
    $candidate=$candidates[0];$marker=$candidate.marker
    Assert ($usedMarkers.Add($marker.id)) 'One map label corresponds to multiple control points; review before merging.'
    $source=@($groups | Where-Object id -ceq "map/$($marker.id)")[0]
    $transferred=@($source.members)
    $merge=[ordered]@{mapLocationId=$marker.id;sourceGroupId=$source.id;targetGroupId=$target.id;name=$marker.name;descriptorType=$marker.descriptorType;worldPositionMeters=$marker.worldPositionMeters;positionStatus=$marker.positionStatus;correspondenceMethod=$candidate.method;anchorDistanceMeters=$candidate.distance;controlPointRawName=$control.rawName;mapLocationPrefab=$marker.prefab;originalCategory=$source.category;transferredObjectIds=@($transferred | ForEach-Object objectId);sourceParentEstablished=$false;ownershipEstablished=$false}
    if($explicitLinks.Count){$merge.userDecision=$explicitLinks[0]}
    $mapMerges.Add($merge);$target.mergedMapLocations+=@($merge);$source.mergedIntoGroupId=$target.id;$source.members=@()
    foreach($link in $transferred){
        $obj=@($objects | Where-Object id -ceq $link.objectId)[0]
        $distance=$(if((ValidPosition $obj.worldPositionMeters $obj.positionStatus) -and (ValidPosition $target.worldPositionMeters $target.positionStatus)){HorizontalDistance $obj.worldPositionMeters $target.worldPositionMeters}else{$null})
        $target.members+=@([ordered]@{objectId=$link.objectId;distanceMeters=$distance;method='merged_map_location_group';sourceParentEstablished=$false;ownershipEstablished=$false;mapLocationEvidence=[ordered]@{mapLocationId=$marker.id;sourceGroupId=$source.id;distanceMeters=$link.distanceMeters;method=$link.method;originalCategory=$source.category}})
    }
    $target.members=@($target.members | ForEach-Object {[pscustomobject]$_} | Sort-Object distanceMeters,objectId)
}
# A transferred object cannot remain in a lower category, including overlap lists.
$transferredIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach($merge in $mapMerges){foreach($id in $merge.transferredObjectIds){$null=$transferredIds.Add($id)}}
foreach($group in ($groups | Where-Object {$_.category -in @('settlements','other')})){$group.members=@($group.members | Where-Object {!$transferredIds.Contains($_.objectId)})}
$stageSummary=[ordered]@{}
foreach($category in ($categories | Where-Object {$_ -cne 'unrecognized'})){
    $stageGroups=@($groups | Where-Object {$_.category -ceq $category -and !$_.mergedIntoGroupId})
    $members=@(foreach($group in $stageGroups){foreach($member in $group.members){$member}})
    $memberIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($member in $members){$null=$memberIds.Add($member.objectId)}
    $stageSummary[$category]=[ordered]@{anchorCount=$stageGroups.Count;assignedParentCount=$memberIds.Count;associationCount=$members.Count;populatedGroupCount=@($stageGroups | Where-Object {$_.members.Count -gt 0}).Count}
}
$unrecognized=@($remaining | Sort-Object name,sourceId | ForEach-Object {[ordered]@{objectId=$_.objectId;reason=$(if(ValidPosition $_.worldPositionMeters $_.positionStatus){'no_source_anchor_or_map_location_within_radius'}else{'position_unknown_or_invalid'})}})
$stageSummary.unrecognized=[ordered]@{parentCount=$unrecognized.Count}
$visible=@($groups | Where-Object {$_.anchorObjectId -or $_.members.Count})
$warnings=@('Control points are selected by prefab, source bases by their previous verified catalog; named map labels are a separate source.','Control-point component supplies/max are configured fields, not measured physical capacity or runtime stock.','Control-point and Harbor members require confirmed source hierarchy; the 350 m radius applies only to the remaining map-location stages.','Each remaining OtherContainers root parent belongs only to its first matching category; all matches within that category are retained.','Control-point and Harbor source entities remain inventory anchors in their own category.','Source parenting and map proximity do not establish runtime resource-grid membership; unknown remains unknown.')
$warnings[2]='After hierarchy and map classification, uniquely corresponding map-label groups are merged into their control-point report group. Transferred map neighbors are not confirmed source children.'
$warnings+='Transferred members retain original map-label proximity evidence; displayed distances use the control-point source position and can exceed the map-label radius.'
$warnings+='Supply depots are located first, then reserve root storage parents within their own radius before control-point, Harbor and map classification. Marker component settings remain separate from physical storage.'
$warnings+='Depot markers use named locations within the map radius: settlements first, then other permitted types, nearest within that tier. Unmatched markers remain separate; proximity does not establish source parenting or runtime ownership.'
$catalog=[ordered]@{schemaVersion=3;kind='priority-location-catalog';snapshotId=$snapshotId;status='partial';gameVersion=$version;scenarioKey=$scenario;normalizerVersion=$normalizer;inputs=$inputs;matchingPolicy=$policy;summary=[ordered]@{objectCount=$objects.Count;controlPointCount=$controlRecords.Count;sourceBaseCount=$harbors.records.Count;otherParentCount=$other.records.Count;recognizedParentCount=$other.records.Count-$unrecognized.Count;unrecognizedParentCount=$unrecognized.Count;associationCount=($stageSummary.Values | Where-Object {$_ -is [System.Collections.IDictionary] -and $_.Contains('associationCount')} | ForEach-Object {$_.associationCount} | Measure-Object -Sum).Sum;visibleGroupCount=$visible.Count;stages=$stageSummary};objects=@($objects.ToArray());groups=@($groups.ToArray());unrecognizedObjects=$unrecognized;mapLocationInventory=$mapInventory;warnings=$warnings}
$catalog.mapGroupMerges=@($mapMerges.ToArray())
$catalog.summary.mergedMapLocationCount=$mapMerges.Count
$catalog.summary.transferredParentCount=$transferredIds.Count
$catalog.summary.supplyDepotCount=$depotRecords.Count
$catalog.depotLocationGrouping=$depotLocationGrouping
$catalog.summary.locatedSupplyDepotCount=@($depotLocationAssociations | Where-Object status -ceq 'matched').Count
$catalog.summary.unlocatedSupplyDepotCount=$depotLocationGrouping.unlocatedDepots.Count
$catalog.summary.supplyDepotLocationGroupCount=$depotRegions.Count
$world=[ordered]@{schemaVersion=3;snapshotId=$snapshotId;revisionId=$RevisionId;revisionReason=$RevisionReason;status='partial';gameVersion=$version;scenarioKey=$scenario;worldPath=$cp.worldPath;normalizerVersion=$normalizer;inputs=$inputs;controlPointCapture=$cp;matchingPolicy=$policy;warnings=$warnings}
$world.supplyDepotCapture=$depots
$index=[ordered]@{schemaVersion=3;kind='conflict-world-index';snapshotId=$snapshotId;status='partial';worldMetadata='world.json';sections=[ordered]@{locations=[ordered]@{path='Locations.json';table='Locations.md'};supplies=[ordered]@{catalog='Locations.json';table='Supplies/OtherContainers.md';controlPoints='Supplies/ControlPoints.json';otherContainers='Supplies/OtherContainers.json';harbors='Supplies/Harbors.json';order=$categories};aiGroups=[ordered]@{status='not_analyzed'};startingBases=[ordered]@{status='not_analyzed'};vehicleSpawns=[ordered]@{status='not_analyzed'}}}
$index.sections.supplies.supplyDepots='Supplies/SupplyDepots.json'
$index.sections.supplies.controlPointStorage='Supplies/ControlPointStorage.json'
$index.sections.supplies.summary='Supplies/Summary.json'
$index.sections.supplies.containerDetails='Supplies/ContainerDetails.json'
$index.sections.supplies.harborNeighbors='Supplies/HarborNeighbors.json'
$index.sections.supplies.summaryTable='Supplies/Summary.md'
$world.commandPostStorageCapture=$commandPosts
$world.inputs.commandPostStorage=[ordered]@{sha256=$commandPostInput.hash;capturedAtUTC=$commandPosts.generatedAtUTC;analyzerVersion=$commandPosts.analyzerVersion}
if($commandPosts.evidence.PSObject.Properties.Name -contains 'initialSupplies'){$world.inputs.commandPostStorage.initialSuppliesCapturedAtUTC=$commandPosts.evidence.initialSupplies.capturedAtUTC}
$catalog.inputs.commandPostStorage=$world.inputs.commandPostStorage
$null=New-Item -ItemType Directory -Path (Join-Path $output 'Supplies')
function WriteJson($path,$value){[IO.File]::WriteAllText((Join-Path $output $path),($value | ConvertTo-Json -Depth 45)+"`n",[Text.UTF8Encoding]::new($false))}
WriteJson 'world.json' $world;WriteJson 'data.json' $index;WriteJson 'Locations.json' $catalog
WriteJson 'Supplies/ControlPoints.json' ([ordered]@{schemaVersion=3;kind='control-point-source-settings';snapshotId=$snapshotId;normalizerVersion=$normalizer;sourceSha256=$cpInput.hash;capturedAtUTC=$cp.generatedAtUTC;records=$controlRecords;nativeInventory=$cp})
WriteJson 'Supplies/SupplyDepots.json' ([ordered]@{schemaVersion=3;kind='supply-depot-marker-settings';snapshotId=$snapshotId;normalizerVersion=$normalizer;sourceSha256=$depotInput.hash;capturedAtUTC=$depots.generatedAtUTC;records=$depotRecords;nativeInventory=$depots})
WriteJson 'Supplies/ControlPointStorage.json' ([ordered]@{schemaVersion=3;kind='command-post-storage-variants';snapshotId=$snapshotId;normalizerVersion=$normalizer;sourceSha256=$commandPostInput.hash;capturedAtUTC=$commandPosts.generatedAtUTC;commonCapacitySupplies=$commonCapacities[0];commonConfiguredInitialSupplies=$commonInitial.value;configuredInitialStatus=$commonInitial.status;configuredInitialScope=$commonInitial.scope;records=$commandPosts.records;nativeInventory=$commandPosts;status='partial';runtimeMeasured=$false})
foreach($type in @('OtherContainers','Harbors')){$source=$(if($type -ceq 'OtherContainers'){$other}else{$harbors});WriteJson "Supplies/$type.json" ([ordered]@{schemaVersion=3;kind='supply-settings-view';report=$type;snapshotId=$snapshotId;normalizerVersion=$normalizer;sourceInputs=$source.inputs;sourceSummary=$source.sourceSummary;records=$source.records;classificationCatalog='../Locations.json';warnings=$warnings})}
# Render both documents from the saved canonical graph and settings.
$saved=Get-Content -LiteralPath (Join-Path $output 'Locations.json') -Raw -Encoding utf8 | ConvertFrom-Json
$lookup=@{};foreach($obj in $saved.objects){$lookup[$obj.id]=$obj}
$rows=@{};foreach($type in @('ControlPoints','OtherContainers','Harbors','SupplyDepots')){$settings=Get-Content -LiteralPath (Join-Path $output "Supplies/$type.json") -Raw -Encoding utf8 | ConvertFrom-Json;foreach($row in $settings.records){$rows[$row.objectId]=$row}}
function Text($v){([string]$v).Replace('|','\|').Replace("`r",' ').Replace("`n",' ').Trim()}
function Number($v){if($null -eq $v){return 'unknown'};([double]$v).ToString('0.######',$culture)}
function Position($p,$status){if(!(ValidPosition $p $status)){return 'unknown'};@($p | ForEach-Object {([double]$_).ToString('0.000',$culture)}) -join ' '}
function Distance($d){if($null -eq $d){return 'unknown'};([double]$d).ToString('0.###',$culture)}
function Value($v,$status){if($status -cne 'resolved'){return 'unknown'};Number $v}
$titles=@{control_points='Контрольные точки';harbors='Harbors';supply_depots='Склады припасов';settlements='Города и деревни';other='Остальные объекты';unrecognized='Нераспознанные'}
function CommandPostComposition(){
    $parts=[Collections.Generic.List[string]]::new();$seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($storage in $commandPosts.records){
        $composition=@($storage.capacityComposition | ForEach-Object {"$($_.containerCount) × $(Number $_.capacitySupplies)"}) -join ' + '
        $key="$($storage.physicalContainerCount)/$composition"
        if($seen.Add($key)){$parts.Add("$($storage.physicalContainerCount) контейнеров: $composition")}
    }
    $parts -join '; '
}
function ParentTable($lines,$links,$showDistance,$commandPost=$null){
    $nameHeader=$(if($null -ne $commandPost){'Название'}else{'Родитель'});$header="| $nameHeader | Вместимость / Изначально | Состав, припасы | Координаты X Y Z, м |";$separator='| --- | --- | --- | --- |';if($showDistance){$header+=' Расстояние, м |';$separator+=' ---: |'};$lines.Add($header);$lines.Add($separator)
    if($null -ne $commandPost){
        $line="| Командный пункт | $(Number $commandPost.commandPostStorage.capacitySupplies) / $(Value $commandPost.commandPostStorage.configuredInitialSupplies $commandPost.commandPostStorage.configuredInitialStatus) | $(CommandPostComposition) | $(Position $commandPost.worldPositionMeters $commandPost.positionStatus) |"
        if($showDistance){$line+=" $(Distance 0) |"}
        $lines.Add($line)
    }
    foreach($link in $links){
        $row=$rows[$link.objectId]
        $composition=@($row.capacityComposition | ForEach-Object {"$($_.containerCount) × $(Number $_.capacitySupplies)"}) -join ' + '
        if(!$composition){$composition='unknown'}
        $capacityAndInitial="$(Value $row.capacitySupplies $row.capacityStatus) / $(Value $row.configuredInitialSupplies $row.configuredInitialStatus)"
        $line="| $(Text $row.name) | $capacityAndInitial | $composition | $(Position $row.worldPositionMeters $row.positionStatus) |"
        if($showDistance){$line+=" $(Distance $link.distanceMeters) |"}
        $lines.Add($line)
    }
    $lines.Add('')
}
function HarborComposition($group,$row){
    $counts=[Collections.Generic.SortedDictionary[double,int]]::new()
    $slotIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $unknown=$row.capacityStatus -cne 'resolved'
    foreach($slot in $group.physicalDescendantContainers){
        Assert ($slotIds.Add($slot.id)) 'Duplicate physical Harbor slot.'
        $fields=@($slot.fields | Where-Object name -ceq 'm_fResourceValueMax')
        if($fields.Count -ne 1 -or $fields[0].status -cne 'resolved'){$unknown=$true;continue}
        $capacity=[double]::Parse($fields[0].value,$culture)
        if([double]::IsNaN($capacity) -or [double]::IsInfinity($capacity) -or $capacity -lt 0){$unknown=$true;continue}
        if(!$counts.ContainsKey($capacity)){$counts[$capacity]=0}
        $counts[$capacity]++
    }
    $parts=@($counts.GetEnumerator() | ForEach-Object {"$($_.Value) × $(Number $_.Key)"})
    if($unknown -or !$parts.Count){$parts+=@('unknown')}
    $parts -join ' + '
}
function HarborTable($lines,$categoryGroups,$supply){
    if($supply){
        $lines.Add('| Название | Вместимость хранилищ, припасы | Состав, припасы | Пополнение, мин. | Пополнение за цикл, припасы | Координаты X Y Z, м |')
        $lines.Add('| --- | ---: | --- | ---: | ---: | --- |')
    }else{
        $lines.Add('| Объект | Координаты X Y Z, м |')
        $lines.Add('| --- | --- |')
    }
    foreach($group in $categoryGroups){
        $row=$rows[$group.anchorObjectId]
        if($supply){$lines.Add("| $(Text $row.name) | $(Value $row.capacitySupplies $row.capacityStatus) | $(HarborComposition $group $row) | $(Value $row.arrivalIntervalMinutes $row.valueStatus.arrivalInterval) | $(Value $row.supplyIncomePerCycle $row.valueStatus.supplyIncomePerCycle) | $(Position $row.worldPositionMeters $row.positionStatus) |")}
        else{$lines.Add("| $(Text $row.name) | $(Position $row.worldPositionMeters $row.positionStatus) |")}
    }
    $lines.Add('')
}
function DepotBlock($lines,$assignment,$supply){
    $group=@($saved.groups | Where-Object id -ceq $assignment.depotGroupId)[0]
    if($assignment.status -cne 'matched'){
        $marker=$lookup[$assignment.depotObjectId]
        $lines.Add("#### Склад - $(Position $marker.worldPositionMeters $marker.positionStatus)");$lines.Add('')
    }
    if($assignment.status -ceq 'matched'){$lines.Add("Расстояние от маркера склада до локации: **$(Distance $assignment.distanceMeters) м** по X/Z.");$lines.Add('')}
    if(!$group.members.Count){return}
    if($supply){ParentTable $lines $group.members $true}
    else{
        $lines.Add('| Объект | Расстояние до склада, м | Координаты X Y Z, м |');$lines.Add('| --- | ---: | --- |')
        foreach($link in $group.members){$obj=$lookup[$link.objectId];$lines.Add("| $(Text $obj.name) | $(Distance $link.distanceMeters) | $(Position $obj.worldPositionMeters $obj.positionStatus) |")}
        $lines.Add('')
    }
}
function DepotLocationSections($lines,$supply){
    $lines.Add("Сначала ищется город / деревня / поселение в радиусе **$(Number $RadiusMeters) м**, затем другая допустимая локация в том же радиусе; выбирается ближайшая в первом подходящем этапе. Заголовки локаций содержат их координаты; в списках показаны собственные координаты объектов. Координаты маркеров показаны только у складов без привязки к локации. Хранилища собираются в радиусе **$(Number $DepotRadiusMeters) м** по X/Z от маркера до распределения остальных объектов. Они исключаются из следующих этапов КП / Harbors / локаций; расстояния в таблице отсчитываются до маркера склада.")
    $lines.Add('')
    foreach($location in $saved.depotLocationGrouping.locations){
        $lines.Add("### $(Text $location.name) - $(Position $location.worldPositionMeters $location.positionStatus)");$lines.Add('')
        foreach($assignment in $location.depots){DepotBlock $lines $assignment $supply}
    }
    if($saved.depotLocationGrouping.unlocatedDepots.Count){
        $lines.Add('### Без привязки к локации');$lines.Add('')
        $lines.Add("В радиусе **$(Number $RadiusMeters) м** не найдено допустимой подписи. Эти склады и их контейнеры сохраняются для ручной сверки.");$lines.Add('')
        foreach($assignment in $saved.depotLocationGrouping.unlocatedDepots){DepotBlock $lines $assignment $supply}
    }
}
foreach($document in @('Locations.md','Supplies/OtherContainers.md')){
    $supply=$document.StartsWith('Supplies/');$lines=[Collections.Generic.List[string]]::new();$lines.Add($(if($supply){'# Припасы по группам мира'}else{'# Объекты по группам мира'}));$lines.Add('');$lines.Add('## Цель');$lines.Add('')
    $lines.Add('Сверять группы объектов в мире и находить разбросанные сущности: контрольные точки ConflictControlPoint, Harbors, склады CampaignRemnantsSupplyDepot, города / деревни, остальные допустимые локации и нераспознанные объекты. Соответствующие подписи карты и их готовые списки объединены с контрольными точками. Подтверждённые source-потомки и перенесённые соседи карты различаются в JSON; runtime-сеть не проверялась.');$lines.Add('');$lines.Add('## Summary');$lines.Add('')
    $lines.Add("Игра **$version**, мир ``$scenario.ent``, ревизия ``$RevisionId``. Радиус поиска хранилищ около маркера склада: **$(Number $DepotRadiusMeters) м**; радиус привязки маркеров к локациям и распределения остатка по подписям: **$(Number $RadiusMeters) м** по X/Z включительно. Контрольных точек: **$($saved.summary.controlPointCount)**; Harbors: **$($saved.summary.sourceBaseCount)**; складов припасов: **$($saved.summary.supplyDepotCount)**; остальных корневых родителей: **$($saved.summary.otherParentCount)**. По приоритетам распознано **$($saved.summary.recognizedParentCount)** родителей, нераспознанных — **$($saved.summary.unrecognizedParentCount)**. Статус **partial**.");$lines.Add('')
    $lines.Add('| Категория | Родителей из OtherContainers | Связей |');$lines.Add('| --- | ---: | ---: |');foreach($category in ($categories | Where-Object {$_ -cne 'unrecognized'})){$summary=$saved.summary.stages.$category;$lines.Add("| $($titles[$category]) | $($summary.assignedParentCount) | $($summary.associationCount) |")};$lines.Add('')
    if($supply){$lines.Add("Итоги исходных каталогов по уникальным записям: OtherContainers — **$($other.sourceSummary.physicalContainerCount)** физических контейнеров / **$(Number $other.sourceSummary.capacitySupplies)** вместимости; Harbors — **$(Number $harbors.sourceSummary.physicalContainerCount)** / **$(Number $harbors.sourceSummary.knownCapacitySubtotalSupplies)** известного подытога, **$($harbors.sourceSummary.unknownCapacityBaseCount)** вместимости unknown. Настройки компонентов припасов контрольных точек и складов учитываются отдельно; они не прибавляются к физической вместимости. Повторные строки локаций не суммируются.");$lines.Add('')}
    $lines.Add('Координаты X Y Z округлены до трёх знаков после точки и разделены пробелами для вставки в Workbench. JSON сохраняет полную исходную точность; расстояния и группировка рассчитаны до округления.');$lines.Add('');$lines.Add('## Откуда берутся данные');$lines.Add('')
    $lines.Add('| Данные | Источник |');$lines.Add('| --- | --- |');$lines.Add('| Контрольная точка / название / позиция | Целевой экспорт ConflictControlPoint prefab; m_sBaseName переведено WidgetManager.Translate, координаты source проверены Workbench. |');$lines.Add('| Припасы точки / максимум компонента | SCR_CampaignSuppliesComponent.m_iSupplies / m_iSuppliesMax; это настройки компонента, они учитываются отдельно от физических контейнеров. |');$lines.Add('| Хранилище командного пункта КП | Проверенная цепочка фракция → командный пункт → хранилище; количество физических слотов, целевой максимум и начальное значение encapsulator action; состав и обнуление исходного запаса проверены по коду. Канонические варианты: Supplies/ControlPointStorage.json. |');$lines.Add('| Подтверждённые вложенные контейнеры | Родительские ID полного экспорта world-supply-containers; физические SCR_ResourceContainer, SUPPLIES. Виртуальные представления не суммируются. |');$lines.Add('| Склады припасов | CampaignRemnantsSupplyDepot prefab; локация определяется по именованной подписи карты, список контейнеров — по утверждённому радиусу и приоритетам. |');$lines.Add('| Harbors | Настройки и физическая вместимость прежнего каталога баз-источников; интервал в минутах = исходные секунды / 60. |');$lines.Add('| Контейнерные строки | Прежние OtherContainers по ID корневого родителя; состав / вместимость / начальные припасы сохранены. |');$lines.Add('| Разбивка | Сначала маркеры складов связываются с именованными локациями, затем хранилища в радиусе маркера исключаются из дальнейшего распределения. После этого проверяются source-иерархия КП / Harbors, города / деревни и остальные разрешённые подписи; соответствующие группы карты переносятся к КП. Внутри одного этапа сохраняются все совпадения. |');$lines.Add('')
    if($supply){$lines.Add('Канонический граф: [Locations.json](../Locations.json); настройки: [ControlPoints](ControlPoints.json), [OtherContainers](OtherContainers.json), [Harbors](Harbors.json), [SupplyDepots](SupplyDepots.json), [метаданные](../world.json).')}else{$lines.Add('Канонический граф: [Locations.json](Locations.json), [метаданные](world.json), [таблица припасов](Supplies/OtherContainers.md).')};$lines.Add('')
    foreach($category in $categories){$lines.Add("## $($titles[$category])");$lines.Add('')
        if($category -ceq 'control_points'){$lines.Add('Объекты соответствующих подписей карты перенесены в группы контрольных точек справочника. Расстояния в таблицах этого раздела рассчитаны до соответствующей контрольной точки; исходные координаты подписей и расстояния сохранены в JSON. Source-родство перенесённых объектов этим не подтверждается.');$lines.Add('')}
        if($category -ceq 'unrecognized'){if($saved.unrecognizedObjects.Count){if($supply){ParentTable $lines $saved.unrecognizedObjects $false}else{$lines.Add('| Объект | Координаты X Y Z, м |');$lines.Add('| --- | --- |');foreach($link in $saved.unrecognizedObjects){$obj=$lookup[$link.objectId];$lines.Add("| $(Text $obj.name) | $(Position $obj.worldPositionMeters $obj.positionStatus) |")};$lines.Add('')}}else{$lines.Add('Нераспознанных объектов нет.');$lines.Add('')};continue}
        if($supply -and $category -ceq 'control_points'){$lines.Add(('Строка «Командный пункт» показывает вместимость его собственного хранилища и варианты состава для 5 / 6 контейнеров. Состав рассчитан по конфигу и коду распределения; выбранная игровая фракция не назначена. Командный пункт и остальные хранилища показаны в одной таблице. «Изначально» у командного пункта — целевой запас после действия префаба: {initial_supplies}. Действие обнуляет исходный запас контейнеров и заполняет их до m_fResourceValueCurrent. Отложенное заполнение всей сети базы учитывается отдельно; запас после запуска миссии здесь не измерен. Расстояние 0 относится к корню на позиции КП. Это отдельная композиция, а не сумма всех хранилищ базы. [Варианты и происхождение](../Supplies/ControlPointStorage.json).').Replace('{initial_supplies}',(Value $commonInitial.value $commonInitial.status)));$lines.Add('')}
        $categoryGroups=@($saved.groups | Where-Object {$_.category -ceq $category -and ($_.anchorObjectId -or $_.members.Count)})
        if(!$categoryGroups.Count){$lines.Add('Объектов этой категории нет.');$lines.Add('');continue}
        if($category -ceq 'harbors'){HarborTable $lines $categoryGroups $supply;continue}
        if($category -ceq 'supply_depots'){DepotLocationSections $lines $supply;continue}
        foreach($group in $categoryGroups){$lines.Add("### $(Text $group.name) - $(Position $group.worldPositionMeters $group.positionStatus)");$lines.Add('')
            foreach($merge in ($group.mergedMapLocations | Where-Object correspondenceMethod -ceq 'user_confirmed_nearby_location')){$lines.Add("Подпись **$(Text $merge.name)** связана с этой контрольной точкой по указанию пользователя; расстояние между ними — **$(Distance $merge.anchorDistanceMeters) м** по X/Z.");$lines.Add('')}
            if($category -ceq 'supply_depots'){$lines.Add("Контейнеры сопоставляются с маркером склада в радиусе **$(Number $RadiusMeters) м** по X/Z. Объекты контрольных точек и Harbors сохраняют приоритет; source-родство отмечается отдельно от близости.");$lines.Add('')}
            if($group.anchorObjectId){$anchor=$rows[$group.anchorObjectId]
                if($supply -and $category -ceq 'control_points'){ParentTable $lines $group.members $true $anchor;continue}
                elseif($supply){$lines.Add('| Название | Пополнение за цикл, припасы | Пополнение, мин. | Вместимость хранилищ, припасы | Координаты X Y Z, м |');$lines.Add('| --- | ---: | ---: | ---: | --- |');$lines.Add("| $(Text $anchor.name) | $(Value $anchor.supplyIncomePerCycle $anchor.valueStatus.supplyIncomePerCycle) | $(Value $anchor.arrivalIntervalMinutes $anchor.valueStatus.arrivalInterval) | $(Value $anchor.capacitySupplies $anchor.capacityStatus) | $(Position $anchor.worldPositionMeters $anchor.positionStatus) |");$lines.Add('')}
                else{$obj=$lookup[$group.anchorObjectId];$lines.Add("Source: **$(Text $obj.name)**; координаты **$(Position $obj.worldPositionMeters $obj.positionStatus)**.");$lines.Add('')}
                if(!($supply -and $category -ceq 'control_points')){$lines.Add("Подтверждённых физических SUPPLIES-контейнеров в source-потомках: **$($group.physicalDescendantContainers.Count)**. Состав и поля контейнеров сохранены в Locations.json; это отдельная проверка от соседства на карте.");$lines.Add('')}
            }
            if($group.members.Count){if($supply){ParentTable $lines $group.members $true}else{$lines.Add('| Объект | Расстояние, м | Координаты X Y Z, м |');$lines.Add('| --- | ---: | --- |');foreach($link in $group.members){$obj=$lookup[$link.objectId];$lines.Add("| $(Text $obj.name) | $(Distance $link.distanceMeters) | $(Position $obj.worldPositionMeters $obj.positionStatus) |")};$lines.Add('')}}elseif($supply){$lines.Add('Других корневых родителей в этой группе справочника нет.');$lines.Add('')}
        }
    }
    if($supply){
        $summaryStart=$lines.IndexOf('## Summary');$summaryEnd=$lines.IndexOf('## Откуда берутся данные')
        Assert ($summaryStart -ge 0 -and $summaryEnd -gt $summaryStart) 'Missing summary section.'
        $lines.RemoveRange($summaryStart,$summaryEnd-$summaryStart)
        $lines.Insert($summaryStart,'[Всего припасов изначально и разбивка по категориям](Summary.md).')
        $lines.Insert($summaryStart+1,'')
    }
    [IO.File]::WriteAllText((Join-Path $output $document),($lines -join "`n").TrimEnd([char]13,[char]10)+"`n",[Text.UTF8Encoding]::new($false))
}
[IO.File]::WriteAllText((Join-Path $output 'Supplies.md'),"# Припасы по приоритетам`n`n[Начальные припасы](Supplies/Summary.md). [Единая таблица](Supplies/OtherContainers.md): склады припасов → контрольные точки → Harbors → города / деревни → остальные объекты → нераспознанные. [Справочник объектов](Locations.md), [индекс](data.json), [метаданные](world.json).`n",[Text.UTF8Encoding]::new($false))
$catalog.summary

function WriteInitialSummary {
    $categoryNames=[ordered]@{control_points='Контрольные точки';harbors='Доки';supply_depots='Склады';settlements='Города';other='Другое'}
    $entries=[Collections.Generic.List[object]]::new()
    $parentCategory=@{}
    foreach($group in $saved.groups){
        foreach($member in $group.members){
            if($parentCategory.ContainsKey($member.objectId)){Assert ($parentCategory[$member.objectId] -ceq $group.category) 'Summary: parent assigned across categories.'}
            else{$parentCategory[$member.objectId]=$group.category}
        }
    }
    foreach($item in $saved.unrecognizedObjects){Assert (!$parentCategory.ContainsKey($item.objectId)) 'Summary: unrecognized parent already assigned.';$parentCategory[$item.objectId]='other'}
    foreach($parent in $other.records){
        Assert ($parentCategory.ContainsKey($parent.objectId)) 'Summary: unclassified parent.'
        $status=$parent.configuredInitialStatus
        $value=$parent.configuredInitialSupplies
        $known=$parent.knownConfiguredInitialSubtotalSupplies
        Assert ($null -ne $known -and $known -ge 0) 'Summary: invalid parent known subtotal.'
        if($status -ceq 'resolved'){Assert ($null -ne $value -and $value -ge 0 -and $value -eq $known) 'Summary: initial value/subtotal mismatch.'}
        $entries.Add([ordered]@{id=$parent.objectId;category=$parentCategory[$parent.objectId];name=$parent.name;initialSupplies=$value;knownInitialSubtotal=$known;status=$status;source='Supplies/OtherContainers.json';field='configuredInitialSupplies';unrecognized=($parent.objectId -in @($saved.unrecognizedObjects.objectId))})
    }
    $seenSlots=@{}
    foreach($group in ($saved.groups | Where-Object category -ceq 'harbors')){
        $anchor=$rows[$group.anchorObjectId];$known=0.0;$unknown=0
        foreach($slot in $group.physicalDescendantContainers){
            Assert (!$seenSlots.ContainsKey($slot.id)) 'Summary: duplicate harbor physical slot.';$seenSlots[$slot.id]=$true
            $field=@($slot.fields | Where-Object name -ceq 'm_fResourceValueCurrent')
            $value=$null;$status='unknown'
            if($field.Count -eq 1 -and $field[0].status -ceq 'resolved'){
                $value=[double]::Parse($field[0].value,$culture)
                Assert (![double]::IsNaN($value) -and ![double]::IsInfinity($value) -and $value -ge 0) 'Summary: invalid harbor initial value.'
                $known+=$value;$status='resolved'
            }else{$unknown++}
            $entries.Add([ordered]@{id=$slot.id;category='harbors';anchorObjectId=$group.anchorObjectId;initialSupplies=$value;knownInitialSubtotal=$(if($null -eq $value){0}else{$value});status=$status;source='Locations.json';field='groups.physicalDescendantContainers.fields.m_fResourceValueCurrent'})
        }
    }
    foreach($point in $controlRecords){
        $s=$point.commandPostStorage
        $entries.Add([ordered]@{id=$point.objectId+'/command-post';category='control_points';name=$point.name;initialSupplies=$s.configuredInitialSupplies;knownInitialSubtotal=$(if($s.configuredInitialStatus -ceq 'resolved'){$s.configuredInitialSupplies}else{0});status=$s.configuredInitialStatus;source='Supplies/ControlPoints.json';field='commandPostStorage.configuredInitialSupplies';scope=$s.configuredInitialScope})
    }
    $totals=@(foreach($category in $categoryNames.Keys){
        $selected=@($entries | Where-Object {$_.category -ceq $category})
        $sum=0.0;foreach($entry in $selected){$sum+=$entry.knownInitialSubtotal}
        $unknown=@($selected | Where-Object {$_.status -cne 'resolved'}).Count
        [ordered]@{category=$category;name=$categoryNames[$category];knownInitialSupplies=$sum;status=$(if($unknown){'partial'}else{'resolved'});unknownEntryCount=$unknown;uniqueEntryCount=$selected.Count}
    })
    $total=0.0;foreach($row in $totals){$total+=$row.knownInitialSupplies}
    $unknownCount=@($entries | Where-Object {$_.status -cne 'resolved'}).Count
    $result=[ordered]@{schemaVersion=1;kind='initial-supplies-summary';snapshotId=$snapshotId;scope='configured_initial_supplies_in_catalogued_storage';status=$(if($unknownCount){'partial'}else{'resolved'});runtimeWorldTotalMeasured=$false;knownInitialSupplies=$total;unknownEntryCount=$unknownCount;categories=$totals;entries=@($entries);deduplication='Unique OtherContainers parent per category and unique harbor physical slot; command-post composition counted once per control point.';otherIncludesUnrecognized=$true;sources=@('Locations.json','Supplies/OtherContainers.json','Supplies/Harbors.json','Supplies/ControlPoints.json')}
    WriteJson 'Supplies/Summary.json' $result
    $lines=[Collections.Generic.List[string]]::new()
    $lines.Add('# Начальные припасы');$lines.Add('')
    $lines.Add("Игра **$version**, мир ``$scenario``, ревизия ``$RevisionId``.");$lines.Add('')
    $lines.Add('## Всего припасов изначально');$lines.Add('')
    $lines.Add("**$(Number $total)** — известная сумма по конфигам хранилищ.");$lines.Add('')
    if($unknownCount){$lines.Add("Полный итог пока неизвестен: записей с неопределённым начальным запасом — **$unknownCount**. Они не приравниваются к нулю; сумма выше включает только известные значения.");$lines.Add('')}
    $lines.Add('| Категория | Припасов изначально |');$lines.Add('| --- | ---: |')
    foreach($row in $totals){$suffix=$(if($row.status -ceq 'partial'){' + неизвестно'}else{''});$lines.Add("| $($row.name) | $(Number $row.knownInitialSupplies)$suffix |")}
    $lines.Add('');$lines.Add('«Города» включают города, деревни и поселения. «Другое» — остальные локации и нераспознанные хранилища. Повторные ссылки на один родительский объект не суммируются.');$lines.Add('')
    foreach($category in $categoryNames.Keys){
        $lines.Add("## $($categoryNames[$category])");$lines.Add('');$lines.Add('| Название | Припасов изначально |');$lines.Add('| --- | ---: |')
        $detailGroups=@($saved.groups | Where-Object {$_.category -ceq $category -and ($_.anchorObjectId -or $_.members.Count)})
        foreach($group in $detailGroups){
            $ids=@($group.members | ForEach-Object {$_.objectId} | Sort-Object -Unique)
            if($category -ceq 'control_points'){$ids+=($group.anchorObjectId+'/command-post')}
            if($category -ceq 'harbors'){$ids+=@($group.physicalDescendantContainers | ForEach-Object {$_.id});$ids+=($group.anchorObjectId+'/unresolved-storage')}
            $items=@($entries | Where-Object {$_.id -in $ids})
            $sum=0.0;foreach($item in $items){$sum+=$item.knownInitialSubtotal}
            $unknown=@($items | Where-Object {$_.status -cne 'resolved'}).Count
            $label=$group.name
            if($category -ceq 'supply_depots'){
                $region=@($saved.depotLocationGrouping.locations | Where-Object {$_.depots.depotGroupId -contains $group.id})
                if($region.Count){$label=$region[0].name}else{$label="Склад - $(Position $group.worldPositionMeters $group.positionStatus)"}
            }
            $amount=$(if($unknown -and !$sum){'неизвестно'}elseif($unknown){"$(Number $sum) + неизвестно"}else{Number $sum})
            $lines.Add("| $(Text $label) | $amount |")
        }
        if($category -ceq 'other' -and $saved.unrecognizedObjects.Count){
            $ids=@($saved.unrecognizedObjects.objectId)
            $items=@($entries | Where-Object {$_.id -in $ids})
            $sum=0.0;foreach($item in $items){$sum+=$item.knownInitialSubtotal}
            $unknown=@($items | Where-Object {$_.status -cne 'resolved'}).Count
            $amount=$(if($unknown -and !$sum){'неизвестно'}elseif($unknown){"$(Number $sum) + неизвестно"}else{Number $sum})
            $lines.Add("| Нераспознанные | $amount |")
        }
        $lines.Add('')
    }
    $lines.Add('Один объект может встречаться у нескольких локаций внутри категории. Строки таблиц показывают состав каждой группы, поэтому их суммы могут пересекаться; общий итог и таблица категорий выше учитывают каждый объект один раз.');$lines.Add('')

    $lines.Add('Использованы configuredInitialSupplies у родительских хранилищ, m_fResourceValueCurrent физических контейнеров доков и начальное значение после действия префаба командного пункта. Вместимость, доход за цикл, виртуальные контейнеры и агрегаты общей сети базы в сумму не прибавляются. Это сводка настроенных запасов, а не измерение всего мира после запуска миссии.');$lines.Add('')
    $lines.Add('[Состав расчёта и источники](Summary.json) · [Подробные таблицы](OtherContainers.md).')
    [IO.File]::WriteAllText((Join-Path $output 'Supplies/Summary.md'),($lines -join "`n")+"`n",[Text.UTF8Encoding]::new($false))
    WriteSupplyHierarchy $entries $totals
}
. (Join-Path $PSScriptRoot 'HarborNeighbors.ps1')
. (Join-Path $PSScriptRoot 'PhysicalSupplyDetails.ps1')
. (Join-Path $PSScriptRoot 'Write-SupplyHierarchy.ps1')
WriteInitialSummary

# Optional targeted HQ catalog; keep its original capture/revision metadata.
if($StartingBasesReportPath){
    $hq=Get-Content -LiteralPath $StartingBasesReportPath -Raw | ConvertFrom-Json
    Assert ($hq.gameVersion -ceq $world.gameVersion) 'HQ candidate game version mismatch.'
    $sourceFolder=Join-Path (Split-Path $StartingBasesReportPath) 'StartingBases'
    Copy-Item -LiteralPath $StartingBasesReportPath -Destination (Join-Path $output 'Supplies/StartingBases.json')
    Copy-Item -LiteralPath $sourceFolder -Destination (Join-Path $output 'Supplies/StartingBases') -Recurse
    . (Join-Path $PSScriptRoot 'StartingBasesSummary.ps1')
    AddStartingBasesSummary (Join-Path $output 'Supplies/Summary.md') $hq
    MoveStartingBaseAccounting (Join-Path $output 'Supplies') $hq
    $index.sections.supplies.hierarchy.pages=@($index.sections.supplies.hierarchy.pages | Where-Object {$_ -notmatch '/Other/StartingPos[0-9]+\.md$'}) + @($hq.records | ForEach-Object {"Supplies/StartingBases/$($_.name).md"})
    $index.sections.supplies.hierarchy.categories+=@{category='starting_bases';summary='Supplies/StartingBases/Summary.md'}
    $index.sections.startingBases=@{status='partial';data='Supplies/StartingBases.json';summary='Supplies/StartingBases/Summary.md';sourceSnapshotId=$hq.snapshotId;accounting='static_physical_stock_counted_once_dynamic_candidates_not_additive'}
    WriteJson 'data.json' $index
}
