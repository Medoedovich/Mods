# Uses the already validated world inventory; stores only physical SUPPLIES slots.
function InitializePhysicalSupplyDetails {
    $script:detailSlots=@{}
    foreach($slot in $physicalSlots){
        $node=$nodes[$slot.sourceId]
        $chain=[Collections.Generic.List[string]]::new();$id=$node.sourceId
        while($id){$chain.Add($id);$id=$nodes[$id].parentSourceId}
        $max=@($slot.fields | Where-Object name -ceq 'm_fResourceValueMax')
        $current=@($slot.fields | Where-Object name -ceq 'm_fResourceValueCurrent')
        Assert ($max.Count -eq 1 -and $current.Count -eq 1) 'Missing physical container fields.'
        $script:detailSlots[$slot.id]=[ordered]@{id=$slot.id;sourceId=$slot.sourceId;name=(PhysicalNodeName $node);prefab=$node.prefab;parentSourceId=$node.parentSourceId;ancestorSourceIds=@($chain);worldPositionMeters=$node.worldPositionMeters;positionStatus=$node.positionStatus;capacitySupplies=$(if($max[0].status -ceq 'resolved'){[double]::Parse($max[0].value,$culture)}else{$null});capacityStatus=$max[0].status;configuredInitialSupplies=$(if($current[0].status -ceq 'resolved'){[double]::Parse($current[0].value,$culture)}else{$null});configuredInitialStatus=$current[0].status;componentIndex=$slot.componentIndex;containerIndex=$slot.containerIndex;fields=$slot.fields}
    }
    WriteJson 'Supplies/ContainerDetails.json' ([ordered]@{schemaVersion=1;kind='physical-supplies-container-details';snapshotId=$snapshotId;sourceSha256=$inventoryInput.hash;capturedAtUTC=$inventory.generatedAtUTC;scope='source_physical_supplies_slots_excluding_virtual_and_runtime_spawned_compositions';recordCount=$script:detailSlots.Count;records=@($script:detailSlots.Values | Sort-Object {$_.id})})
}
function PhysicalNodeName($node){if($node.name){return $node.name};if($node.prefab){return [IO.Path]::GetFileNameWithoutExtension($node.prefab)};return $node.sourceId}
function AddPhysicalSupplyDetails($lines,$page){
    $buckets=[ordered]@{}
    if($page.category -ceq 'harbors'){
        $anchor=$rows[$page.group.anchorObjectId].sourceId
        foreach($slot in $page.group.physicalDescendantContainers){
            $id=$slot.sourceId
            while($nodes[$id].parentSourceId -and $nodes[$id].parentSourceId -cne $anchor){$id=$nodes[$id].parentSourceId}
            Assert ($id -ceq $anchor -or $nodes[$id].parentSourceId -ceq $anchor) 'Container outside harbor hierarchy.'
            if(!$buckets.Contains($id)){$buckets[$id]=[Collections.Generic.List[object]]::new()}
            $buckets[$id].Add($script:detailSlots[$slot.id])
        }
    }else{
        foreach($member in $page.group.members){
            $parent=$rows[$member.objectId];$slots=@($script:detailSlots.Values | Where-Object {$parent.sourceId -cin $_.ancestorSourceIds} | Sort-Object {$_.id})
            Assert ($slots.Count -eq $parent.physicalContainerCount) 'Physical detail count differs from parent aggregate.'
            $max=0.0;$current=0.0
            foreach($slot in $slots){if($slot.capacityStatus -ceq 'resolved'){$max+=$slot.capacitySupplies};if($slot.configuredInitialStatus -ceq 'resolved'){$current+=$slot.configuredInitialSupplies}}
            if($parent.capacityStatus -ceq 'resolved'){Assert ($max -eq $parent.capacitySupplies) 'Physical detail capacity differs from parent aggregate.'}
            if($parent.configuredInitialStatus -ceq 'resolved'){Assert ($current -eq $parent.configuredInitialSupplies) 'Physical detail initial supplies differ from parent aggregate.'}
            $buckets[$parent.sourceId]=$slots
        }
    }
    $lines.Add('## Где находятся контейнеры');$lines.Add('')
    if(!$buckets.Count){$lines.Add('> ⚠️ **Требует проверки структуры дока**');$lines.Add('>');$lines.Add('> Вложенных хранилищ не найдено. Отдельно расположенные контейнеры перечислены ниже.');$lines.Add('>');$lines.Add('> Проверьте, нужно ли включить их в иерархию дока и подключаются ли они к пополнению. Само отсутствие вложенности ещё не означает ошибку или отсутствие пополнения.');$lines.Add('')}
    else{
        $lines.Add('Показаны мировые координаты самих физических контейнеров, округлённые до трёх знаков для перехода в Workbench. Виртуальные представления повторно не учитываются.');$lines.Add('')
        foreach($id in $buckets.Keys){
            $node=$nodes[$id]
            $lines.Add("### $(Text (PhysicalNodeName $node)) - $(Position $node.worldPositionMeters $node.positionStatus)");$lines.Add('')
            $lines.Add('| Контейнер | Вместимость / Изначально | Координаты X Y Z, м |');$lines.Add('| --- | ---: | --- |')
            foreach($slot in $buckets[$id]){$lines.Add("| $(Text $slot.name) | $(Value $slot.capacitySupplies $slot.capacityStatus) / $(Value $slot.configuredInitialSupplies $slot.configuredInitialStatus) | $(Position $slot.worldPositionMeters $slot.positionStatus) |")}
            $lines.Add('')
        }
    }
    if($page.category -ceq 'control_points'){$lines.Add('Командный пункт создаётся при запуске миссии. Координаты его отдельных контейнеров не измерены; позиция КП выше относится к корню композиции. Здесь раскрыты сохранённые хранилища мира, а не ящики динамического командного пункта.');$lines.Add('')}
    $lines.Add('[Контейнеры: координаты, иерархия и исходные поля](../ContainerDetails.json).');$lines.Add('')
}
