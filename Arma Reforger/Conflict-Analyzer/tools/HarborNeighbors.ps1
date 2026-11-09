function HarborDistance($a,$b){[Math]::Sqrt([Math]::Pow($a[0]-$b[0],2)+[Math]::Pow($a[1]-$b[1],2)+[Math]::Pow($a[2]-$b[2],2))}
function InitializeHarborNeighbors {
    $script:harborNeighbors=@{}
    $runtime=$null
    if($HarborRuntimeReportPath){$runtimeInput=ReadInput $HarborRuntimeReportPath;$runtime=$runtimeInput.value;Assert ($runtime.kind -ceq 'harbor-container-runtime' -and $runtime.gameVersion -ceq $version -and $runtime.complete) 'Invalid harbor runtime report.';Assert ($cp.worldPath.EndsWith($runtime.world,[StringComparison]::Ordinal)) 'Runtime world differs from source inventory.';Assert (@($runtime.bases | Where-Object {$_.sampleSeconds -eq $runtime.selectedSampleSeconds -and $_.radiusMeters -eq 100 -and $_.initialized}).Count -eq 18) 'Runtime generator coverage or range differs.'}
    $rootParents=@{};foreach($parent in $other.records){$rootParents[$parent.sourceId]=$parent}
    $catalog=@(foreach($resource in $inventory.resources){foreach($slot in $resource.containers){
        $type=@($slot.fields | Where-Object name -ceq 'm_eResourceType')
        if($type.Count -ne 1 -or $type[0].enumLabel -cne 'SUPPLIES'){continue}
        $node=$nodes[$resource.sourceId]
        $rootParent=$null;$walk=$resource.sourceId
        while($walk){if($rootParents.ContainsKey($walk)){$rootParent=$rootParents[$walk]};$walk=$nodes[$walk].parentSourceId}
        [pscustomobject]@{id="$($resource.sourceId)/$($resource.componentIndex)/$($slot.index)";sourceId=$resource.sourceId;node=$node;rootParent=$rootParent;virtual=($slot.className -ceq 'SCR_ResourceContainerVirtual');fields=$slot.fields;index=$slot.index}
    }})
    foreach($group in @($saved.groups | Where-Object category -ceq 'harbors')){
        $anchor=$rows[$group.anchorObjectId].sourceId
        $liveRecords=@();if($runtime){$liveRecords=@($runtime.records | Where-Object harbor -CEQ $group.name)}
        $audit=[Collections.Generic.List[object]]::new()
        $buckets=@{}
        foreach($slot in $catalog){
            $root=$null;$objectId=$null;$relation='detached'
            if($slot.rootParent){$root=$slot.rootParent.sourceId;$objectId=$slot.rootParent.objectId}
            if(IsDescendant $slot.sourceId $anchor){
                $relation='source_descendant';$root=$slot.sourceId
                while($nodes[$root].parentSourceId -and $nodes[$root].parentSourceId -cne $anchor -and $root -cne $anchor){$root=$nodes[$root].parentSourceId}
                $objectId=$group.anchorObjectId
            }
            if(!$root){$root=$slot.sourceId}
            $rootNode=$nodes[$root]
            if(!(ValidPosition $slot.node.worldPositionMeters $slot.node.positionStatus) -or !(ValidPosition $rootNode.worldPositionMeters $rootNode.positionStatus)){continue}
            $d=HarborDistance $slot.node.worldPositionMeters $group.worldPositionMeters
            $rd=HarborDistance $rootNode.worldPositionMeters $group.worldPositionMeters
            $live=$null
            if($runtime){
                $matches=@($liveRecords | Where-Object { $_.virtual -eq $slot.virtual -and $_.containerIndex -eq $slot.index -and ($_.runtimeEntityId -ceq $slot.sourceId -or ($_.prefab -and $_.prefab -ceq $slot.node.prefab -and (HarborDistance $_.worldPositionMeters $slot.node.worldPositionMeters) -le 0.03))})
                Assert ($matches.Count -le 1) 'Ambiguous runtime container match.'
                if($matches.Count){$live=$matches[0]}
            }
            $entry=[pscustomobject][ordered]@{id=$slot.id;sourceId=$slot.sourceId;name=(PhysicalNodeName $slot.node);prefab=$slot.node.prefab;virtual=$slot.virtual;worldPositionMeters=$slot.node.worldPositionMeters;positionStatus=$slot.node.positionStatus;distanceMeters=$d;originWithinRadius=($d -le 100);rootSourceId=$root;rootName=(PhysicalNodeName $rootNode);rootWorldPositionMeters=$rootNode.worldPositionMeters;rootDistanceMeters=$rd;rootWithinRadius=($rd -le 100);rootOriginDisagreement=(($d -le 100) -ne ($rd -le 100));relation=$relation;objectId=$objectId;runtime=$live;runtimePositionDeltaMeters=$(if($live){HarborDistance $live.worldPositionMeters $slot.node.worldPositionMeters}else{$null});runtimeStatus=$(if($live){'measured'}else{'not_measured'});fields=$slot.fields}
            if(!$buckets.ContainsKey($root)){$buckets[$root]=[Collections.Generic.List[object]]::new()}
            $buckets[$root].Add($entry)
        }
        foreach($bucket in $buckets.Values){
            # Root distance never excludes a container; retain outside siblings to expose discrepancies.
            $relevant=@($bucket | Where-Object {$_.originWithinRadius -or $_.rootWithinRadius -or $_.relation -ceq 'source_descendant' -or ($null -ne $_.runtime -and $_.runtime.inRange)}).Count -gt 0
            if($relevant){foreach($entry in $bucket){$audit.Add($entry)}}
        }
        $script:harborNeighbors[$group.id]=[ordered]@{groupId=$group.id;anchorObjectId=$group.anchorObjectId;name=$group.name;worldPositionMeters=$group.worldPositionMeters;containers=@($audit | Sort-Object rootName,rootSourceId,virtual,id)}
    }
    WriteJson 'Supplies/HarborNeighbors.json' ([ordered]@{schemaVersion=2;kind='harbor-container-inspection';snapshotId=$snapshotId;scope='physical_and_virtual_supplies_slots_near_harbors_and_relevant_composition_siblings';method='container_origin_screen_with_separate_runtime_AABB_and_connection_checks';radiusMeters=100;boundary='inclusive_before_rounding';classificationChanged=$false;runtimeConnectionMeasured=($null -ne $runtime);runtimeInput=$(if($runtime){[ordered]@{sha256=$runtimeInput.hash;report=$runtime}}else{$null});inputs=$saved.inputs;records=@($script:harborNeighbors.Values | Sort-Object {$_.name})})
}
function HarborYes($value){if($null -eq $value){return 'не измерено'};if($value){return 'да'};'нет'}
function AddHarborNeighbors($lines,$page,$pages){
    if($page.category -cne 'harbors'){return}
    $record=$script:harborNeighbors[$page.id]
    $lines.Add('## Проверка контейнеров в радиусе дока');$lines.Add('')
    $lines.Add('Отбор проверяет каждый физический и виртуальный SUPPLIES-контейнер отдельно. Расстояния по X/Y/Z — от дока до контейнера и до корня композиции, порог 100 м до округления. Показаны также вышедшие за радиус контейнеры выбранной композиции для поиска расхождений. Они не считаются попавшими в радиус.');$lines.Add('')
    $lines.Add('Игра использует IsInRange (пересечение сферы с границами сущности), IsIsolated и CanInteractWith. Виртуальное представление может подключаться вместо физических ящиков; его запас не суммируется повторно. Координаты и дистанции в таблице взяты из editor source, игровые проверки — из отдельной сессии; сдвиги позиции показаны ниже. «Связан» — наблюдение IsInteractorLinked, а не доказательство пополнения. Этот диагностический список не прибавляется к суммам повторно.');$lines.Add('')
    foreach($bucket in @($record.containers | Group-Object rootSourceId)){
        $first=$bucket.Group[0]
        $lines.Add("### $(Text $first.rootName) - $(Position $first.rootWorldPositionMeters 'resolved')");$lines.Add('')
        $lines.Add("Расстояние до корня: **$(Distance $first.rootDistanceMeters) м**. Корень в радиусе: **$(HarborYes $first.rootWithinRadius)**.");$lines.Add('')
        $lines.Add('| Контейнер | Вид | Координаты X Y Z, м | До дока, м | Позиция ≤ 100 м | Расхождение с корнем | IsInRange | Изолирован | Разрешено | Связан |');$lines.Add('| --- | --- | --- | ---: | --- | --- | --- | --- | --- | --- |')
        foreach($item in $bucket.Group){
            $live=$item.runtime;$inRange=$null;$isolated=$null;$allowed=$null;$linked=$null
            if($live){$inRange=$live.inRange;$isolated=$live.isolated;$allowed=$live.allowed;$linked=$live.linked}
            $kind=if($item.virtual){'виртуальный'}else{'физический'}
            $lines.Add("| $(Text $item.name) | $kind | $(Position $item.worldPositionMeters $item.positionStatus) | $(Distance $item.distanceMeters) | $(HarborYes $item.originWithinRadius) | $(HarborYes $item.rootOriginDisagreement) | $(HarborYes $inRange) | $(HarborYes $isolated) | $(HarborYes $allowed) | $(HarborYes $linked) |")
        }
        $lines.Add('')
        $shifted=@($bucket.Group | Where-Object {$null -ne $_.runtimePositionDeltaMeters -and $_.runtimePositionDeltaMeters -gt 0.03})
        if($shifted.Count){
            $lines.Add('Положение после запуска отличается от editor source более чем на 0.03 м:');$lines.Add('')
            $lines.Add('| Контейнер | Координаты в сессии X Y Z, м | Сдвиг, м |');$lines.Add('| --- | --- | ---: |')
            foreach($item in $shifted){$lines.Add("| $(Text $item.name) | $(Position $item.runtime.worldPositionMeters 'resolved') | $(Distance $item.runtimePositionDeltaMeters) |")}
            $lines.Add('')
        }
        $owners=@($pages | Where-Object {$first.objectId -in $_.entryIds})
        if($owners.Count){$links=@($owners | ForEach-Object {"[$(Text $_.label)](../$($_.file))"}) -join ', ';$lines.Add("Учтено в справочнике: $links.");$lines.Add('')}
    }
    if(!$record.containers.Count){$lines.Add('Подходящих контейнеров не найдено.');$lines.Add('')}
    $lines.Add('[Проверки контейнеров, корней и подключения](../HarborNeighbors.json).');$lines.Add('')
}
