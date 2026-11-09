# Called by New-SupplyPriorityReport.ps1 with the validated graph and summary entries.
function WriteSupplyHierarchy($entries,$totals){
    InitializePhysicalSupplyDetails
    InitializeHarborNeighbors
    $folders=[ordered]@{control_points='ControlPoints';harbors='Harbors';supply_depots='SupplyDepots';settlements='Settlements';other='Other'}
    $names=@{control_points='Контрольные точки';harbors='Доки';supply_depots='Склады';settlements='Города';other='Другое'}
    $pages=[Collections.Generic.List[object]]::new()
    foreach($category in $folders.Keys){
        foreach($group in @($saved.groups | Where-Object {$_.category -ceq $category -and ($_.anchorObjectId -or $_.members.Count)})){
            $label=$group.name;$position=$group.worldPositionMeters;$positionStatus=$group.positionStatus
            $harborLocationBinding=$null
            if(($category -ceq 'other' -and ($group.name -ceq 'harbor' -or $group.name -ceq 'Airport' -or ($group.name -ceq 'military site' -and $group.id -cin @('map/0x0000000000085611 {}/1','map/0x00000000000B0C4D {}/1','map/0x00000000000C3925 {}/1')))) -or $category -ceq 'settlements'){
                $candidates=@(@(foreach($dock in @($saved.groups | Where-Object category -ceq 'harbors')){
                    if($category -ceq 'settlements'){
                        $mapKey=([regex]::Replace($group.name.ToLowerInvariant(),'[^a-z0-9]','')) -replace '^saint','st'
                        $dockKey=([regex]::Replace(($dock.name -creplace '^SP_(?:A|T[0-9]+H)_','').ToLowerInvariant(),'[^a-z0-9]',''))
                        if($mapKey -ceq 'stphilippe'){$mapKey='stphillipe'}
                        if($mapKey -cne $dockKey){continue}
                    }
                    if($group.name -ceq 'Airport' -and $dock.name -cne 'SP_A_EveronAirport'){continue}
                    if(!(ValidPosition $group.worldPositionMeters $group.positionStatus) -or !(ValidPosition $dock.worldPositionMeters $dock.positionStatus)){continue}
                    $dx=$dock.worldPositionMeters[0]-$group.worldPositionMeters[0];$dz=$dock.worldPositionMeters[2]-$group.worldPositionMeters[2]
                    $distance=[Math]::Sqrt($dx*$dx+$dz*$dz)
                    if($distance -le $RadiusMeters){[pscustomobject]@{dock=$dock;distance=$distance}}
                }) | Sort-Object distance,{$_.dock.id})
                if($candidates.Count -and ($candidates.Count -eq 1 -or [Math]::Abs($candidates[0].distance-$candidates[1].distance) -gt 0.001)){
                    $nearest=$candidates[0]
                    if($nearest.dock.name -cmatch '^SP_(?:A|T[0-9]+H)_(.+)$'){
                        $label=$Matches[1]
                        $harborLocationBinding=[ordered]@{originalMapLabel=$group.name;mapGroupId=$group.id;dockGroupId=$nearest.dock.id;dockName=$nearest.dock.name;locationName=$label;nameSource='dock_source_name_suffix';method=$(if($group.name -ceq 'Airport'){'user_confirmed_airport_dock_pair_within_horizontal_radius'}elseif($category -ceq 'settlements'){'same_named_settlement_and_dock_within_horizontal_radius'}elseif($group.name -ceq 'military site'){'user_confirmed_military_site_nearest_dock_within_horizontal_radius'}else{'nearest_dock_to_generic_harbor_map_label_horizontal'});distanceMeters=$nearest.distance;radiusMeters=$RadiusMeters;ownershipEstablished=$false;replenishmentEstablished=$false}
                    }
                }
            }
            if($category -ceq 'supply_depots'){
                $region=@($saved.depotLocationGrouping.locations | Where-Object {$_.depots.depotGroupId -contains $group.id})
                if($region.Count){$label=$region[0].name;$position=$region[0].worldPositionMeters;$positionStatus=$region[0].positionStatus}
                else{$label="Склад - $(Position $position $positionStatus)"}
            }
            $ids=@($group.members | ForEach-Object {$_.objectId} | Sort-Object -Unique)
            if($category -ceq 'control_points'){$ids+=($group.anchorObjectId+'/command-post')}
            if($category -ceq 'harbors'){$ids+=@($group.physicalDescendantContainers | ForEach-Object {$_.id})}
            $pages.Add([pscustomobject]@{id=$group.id;category=$category;label=$label;position=$position;positionStatus=$positionStatus;group=$group;harborLocationBinding=$harborLocationBinding;entryIds=$ids;unrecognized=$false;file='';amount='';known=0.0;unknown=0})
        }
    }
    foreach($member in $saved.unrecognizedObjects){
        $obj=$rows[$member.objectId]
        $pages.Add([pscustomobject]@{id=$member.objectId;category='other';label=$obj.name;position=$obj.worldPositionMeters;positionStatus=$obj.positionStatus;group=[pscustomobject]@{members=@($member)};harborLocationBinding=$null;entryIds=@($member.objectId);unrecognized=$true;file='';amount='';known=0.0;unknown=0})
    }
    $paths=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    $labelCounts=@{};foreach($item in $pages){$key=$item.category+'/'+$item.label.ToLowerInvariant();if(!$labelCounts.ContainsKey($key)){$labelCounts[$key]=0};$labelCounts[$key]++}
    foreach($page in $pages){
        $slug=[regex]::Replace($page.label.Normalize([Text.NormalizationForm]::FormD),'\p{Mn}','')
        $slug=[regex]::Replace($slug,'[^\p{L}\p{Nd}_-]+','-').Trim('-')
        if(!$slug){$slug='Object'}
        if($slug -match '^(?i:con|prn|aux|nul|com[0-9]|lpt[0-9]|summary)$'){$slug='Object-'+$slug}
        $duplicate=$labelCounts[$page.category+'/'+$page.label.ToLowerInvariant()] -gt 1
        if($duplicate){
            $hash=[Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($page.id))).Substring(0,8).ToLowerInvariant()
            $slug+='-'+$hash;$page.label+=" - $(Position $page.position $page.positionStatus)"
        }
        $pageFolder=$folders[$page.category];$page.file="$pageFolder/$slug.md"
        Assert ($paths.Add($page.file)) 'Hierarchy: filename collision.'
        $items=@($entries | Where-Object {$_.id -in $page.entryIds})
        $page.entryIds=@($items | ForEach-Object {$_.id})
        foreach($item in $items){$page.known+=$item.knownInitialSubtotal}
        $page.unknown=@($items | Where-Object {$_.status -cne 'resolved'}).Count
        $page.amount=$(if($page.unknown -and !$page.known){'неизвестно'}elseif($page.unknown){"$(Number $page.known) + неизвестно"}else{Number $page.known})
    }
    function SaveHierarchyPage($relative,$lines){
        $path=Join-Path $output "Supplies/$relative";$null=New-Item -ItemType Directory (Split-Path $path) -Force
        [IO.File]::WriteAllText($path,($lines -join "`n").TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))
    }
    $summaryPath=Join-Path $output 'Supplies/Summary.md'
    $previous=[IO.File]::ReadAllText($summaryPath).Replace("`r`n","`n")
    $start=$previous.IndexOf('## Контрольные точки')
    $end=$previous.IndexOf('Один объект может встречаться',$start)
    Assert ($start -ge 0 -and $end -gt $start) 'Hierarchy: missing summary sections.'
    $main=[Collections.Generic.List[string]]::new()
    foreach($category in $folders.Keys){
        $folder=$folders[$category];$name=$names[$category]
        $total=@($totals | Where-Object {$_.category -ceq $category})[0]
        $categoryPages=@($pages | Where-Object category -ceq $category)
        $main.Add("## [$name]($folder/Summary.md)");$main.Add('');$main.Add('| Название | Припасов изначально |');$main.Add('| --- | ---: |')
        $cat=[Collections.Generic.List[string]]::new();$cat.Add("# $name");$cat.Add('');$cat.Add('[Общая сводка](../Summary.md)');$cat.Add('')
        $cat.Add("Игра **$version**, мир ``$scenario``, ревизия ``$RevisionId``.");$cat.Add('')
        $suffix=$(if($total.unknownEntryCount){' + неизвестно'}else{''})
        $cat.Add("Начальных припасов по конфигам: **$(Number $total.knownInitialSupplies)$suffix**. Итог учитывает каждый объект один раз.");$cat.Add('')
        if($category -ceq 'control_points'){
            $cat.Add('Объекты соответствующих подписей карты перенесены в группы контрольных точек справочника. Расстояния в подробных таблицах рассчитаны до соответствующей контрольной точки; исходные координаты подписей и расстояния сохранены в JSON. Source-родство перенесённых объектов этим не подтверждается.');$cat.Add('')
            $cat.Add('Строка командного пункта отражает его собственное хранилище после действия префаба. Начальные припасы всей сети базы и её runtime-агрегаты отдельно не прибавляются.');$cat.Add('')
        }
        if($category -ceq 'supply_depots'){$cat.Add("Хранилища собираются в **$(Number $DepotRadiusMeters) м** по X/Z от маркера склада; привязка маркера к локации — в **$(Number $RadiusMeters) м**. Расстояния в подробных таблицах отсчитываются от маркера.");$cat.Add('')}
        if($category -ceq 'other'){$cat.Add('Включены остальные локации и нераспознанные объекты. Локации могут пересекаться; их строки нельзя повторно складывать для получения общего итога.');$cat.Add('')}
        if($category -ceq 'harbors'){
            $cat.Add('## Радиус поиска хранилищ и пополнение')
            $cat.Add('')
            $cat.Add('В установленной игре **1.8.0.13** базовый префаб `Prefabs/Systems/MilitaryBase/ConflictSourceBase.et` задаёт **100 м** в поле `SCR_ResourceComponent → m_aGenerators → SCR_ResourceGenerator → m_fStorageRange`. Прочитанные `ConflictSourceBase_T1Harbor.et` и `ConflictSourceBase_T2Harbor.et` наследуют этот префаб и не переопределяют это поле. Это настройка генератора ресурсов; одноимённое по величине `m_iRadius` компонента базы — другое поле.')
            $cat.Add('')
            $cat.Add('`SCR_CampaignSourceBaseComponent` наследует механизм пополнения от `SCR_CampaignMilitaryBaseComponent`: таймер вызывает `AddRegularSupplyPackage`, затем `AddSupplies` обращается к генератору SUPPLIES. `SCR_ResourceGenerator.RequestGeneration` вызывает `RequestAvailability`, которая обновляет список контейнеров через `ResourceGrid.UpdateInteractor`. `GetResourceGridRange` генератора возвращает `m_fStorageRange`.')
            $cat.Add('')
            $cat.Add('Ресурсная сеть ищет контейнеры поблизости и проверяет `CanInteractWith`, `IsInRange` и признак изоляции. Поэтому хранилище **не обязано быть дочерним объектом дока**, чтобы участвовать в пополнении. Вместе с тем одной близости недостаточно: действуют условия подключения, свободная вместимость и условия работы базы. Результаты наблюдения подключения показаны отдельно на страницах доков; факт пополнения за цикл этим не измеряется.')
            $cat.Add('')
            $cat.Add('### Как читать список в справочнике')
            $cat.Add('')
            $cat.Add('- Проверяются отдельно все физические и виртуальные SUPPLIES-контейнеры. Расстояние по X/Y/Z считается от сущности дока до позиции каждого контейнера; 100 м включительно, до округления. Корень композиции больше не служит фильтром, исключающим вложенные ящики.')
            $cat.Add('- Расстояние до корня сохранено для сравнения. Вышедшие за радиус соседи внутри выбранной композиции показаны как диагностика: расхождение с корнем — повод проверить расположение, а не автоматически доказанная ошибка мира.')
            $cat.Add('- Игровой IsInRange проверяет пересечение сферы с AABB сущности (GetBounds), поэтому результат может отличаться от расстояния до её позиции. Изоляция, CanInteractWith и IsInteractorLinked показываются отдельными колонками при наличии runtime-измерения; иначе — «не измерено».')
            $cat.Add('- Виртуальные представления хранилищ показаны отдельно от физических ящиков и не добавляются к суммам. Исходные запасы и принадлежность по source-иерархии сохраняются. Связанные группы потенциального расширения включены в категорию сводки «Доки». Динамически созданные объекты, отсутствующие в editor source, остаются в runtime-отчёте без придуманной привязки.')
            $cat.Add('')
            $cat.Add('')
            $cat.Add('У StPierre, Lamentin и Meaux «неизвестно» означает отсутствие подтверждённых вложенных хранилищ в используемом отчёте, а не нулевой запас и не доказанную остановку пополнения. Припасы отдельно стоящих соседей уже учтены в других категориях.')
            $cat.Add('')
            $cat.Add('## Начальные припасы по докам')
            $cat.Add('')
        }
        $cat.Add('| Название | Припасов изначально |');$cat.Add('| --- | ---: |')
        foreach($page in $categoryPages){
            $filename=Split-Path $page.file -Leaf
            $main.Add("| [$(Text $page.label)]($($page.file)) | $($page.amount) |")
            $cat.Add("| [$(Text $page.label)]($filename) | $($page.amount) |")
            $detail=[Collections.Generic.List[string]]::new();$detail.Add("# $(Text $page.label)");$detail.Add('');$detail.Add("[$name — сводка](../$folder/Summary.md) · [Все категории](../Summary.md)");$detail.Add('')
            $detail.Add("Координаты X Y Z: **$(Position $page.position $page.positionStatus)**.");$detail.Add('')
            $detail.Add("Припасов изначально по конфигам: **$($page.amount)**.");$detail.Add('')
            if($page.unrecognized){$detail.Add('Объект пока не отнесён к распознанной группе.');$detail.Add('');ParentTable $detail $page.group.members $false}
            elseif($category -ceq 'harbors'){HarborTable $detail @($page.group) $true}
            elseif($category -ceq 'control_points'){
                ParentTable $detail $page.group.members $true $rows[$page.group.anchorObjectId]
                foreach($merge in @($page.group.mergedMapLocations | Where-Object correspondenceMethod -ceq 'user_confirmed_nearby_location')){$detail.Add("Подпись **$(Text $merge.name)** связана с этой КП по указанию пользователя; расстояние между ними — **$(Distance $merge.anchorDistanceMeters) м**.");$detail.Add('')}
            }else{
                ParentTable $detail $page.group.members $true
                $detail.Add($(if($category -ceq 'supply_depots'){'Расстояния рассчитаны до маркера склада.'}else{'Расстояния рассчитаны до подписи локации.'}));$detail.Add('')
            }
            if($page.harborLocationBinding){
                $binding=$page.harborLocationBinding
                $dockPage=@($pages | Where-Object id -ceq $binding.dockGroupId)[0]
                $detail.Add("Подпись карты ``$($binding.originalMapLabel)`` связана для навигации с доком [$(Text $binding.dockName)](../$($dockPage.file)); между подписью и доком **$(Distance $binding.distanceMeters) м** по X/Z. Название файла взято из имени дока. Координаты группы и расстояния в таблице по-прежнему относятся к подписи карты.");$detail.Add('')
                $detail.Add('Это географическая группа хранилищ, а не список пополнения дока. Попадание отдельных физических и виртуальных контейнеров в радиус 100 м и игровые проверки показаны на странице дока.');$detail.Add('')
            }
            if($category -ceq 'harbors'){
                $locations=@($pages | Where-Object {$_.harborLocationBinding -and $_.harborLocationBinding.dockGroupId -ceq $page.id})
                foreach($location in $locations){$detail.Add("Хранилища локации: [$(Text $location.label)](../$($location.file)). В эту географическую группу могут входить объекты вне радиуса пополнения дока.");$detail.Add('')}
            }
            AddPhysicalSupplyDetails $detail $page
            AddHarborNeighbors $detail $page $pages
            $detail.Add('[Состав расчёта](../Summary.json) · [Группы и происхождение](../../Locations.json).')
            SaveHierarchyPage $page.file $detail
        }
        $main.Add('');$cat.Add('');$cat.Add('[Состав расчёта и неизвестные значения](../Summary.json).')
        if($category -ceq 'harbors'){
            $cat.Add('## Хранилища локаций доков');$cat.Add('')
            foreach($location in @($pages | Where-Object {$_.harborLocationBinding})){
                $leaf="../$($location.file)"
                $cat.Add("- [$(Text $location.label)]($leaf)")
            }
            $cat.Add('');$cat.Add('Это географические группы, включая хранилища вне радиуса пополнения. Их суммы включены в категорию «Доки» по уникальным объектам.');$cat.Add('')
        }
        SaveHierarchyPage "$folder/Summary.md" $cat
    }
    $text=$previous.Substring(0,$start)+($main -join "`n")+"`n"+$previous.Substring($end)
    foreach($category in $folders.Keys){$text=$text.Replace("| $($names[$category]) |","| [$($names[$category])]($($folders[$category])/Summary.md) |")}
    [IO.File]::WriteAllText($summaryPath,$text,[Text.UTF8Encoding]::new($false))
    MergeHarborDetailPages $pages $entries
    UpdateHarborSummaryAccounting $pages $entries
    WriteEligibleHarborGroups $pages $entries
    $result=Get-Content -LiteralPath (Join-Path $output 'Supplies/Summary.json') -Raw | ConvertFrom-Json
    $navigation=@($pages | ForEach-Object {[ordered]@{id=$_.id;category=$_.category;name=$_.label;path=$_.file;entryIds=$_.entryIds;knownInitialSupplies=$_.known;unknownEntryCount=$_.unknown;harborLocationBinding=$_.harborLocationBinding}})
    $result | Add-Member -NotePropertyName detailPages -NotePropertyValue $navigation
    WriteJson 'Supplies/Summary.json' $result
    $index.sections.supplies.hierarchy=[ordered]@{categories=@($folders.Keys | ForEach-Object {[ordered]@{category=$_;summary="Supplies/$($folders[$_])/Summary.md"}});pages=@($pages | ForEach-Object {"Supplies/$($_.file)"} | Sort-Object -Unique)}
    WriteJson 'data.json' $index
}


# Shared presentation for all docks. Accounting categories remain independent.
function MergeHarborDetailPages($pages,$entries){
    $supplies=[IO.Path]::GetFullPath((Join-Path $output 'Supplies'))
    $destinations=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    function DetailBody($path){
        $text=[IO.File]::ReadAllText($path).Replace("`r`n","`n")
        $start=$text.IndexOf('Координаты X Y Z:')
        Assert ($start -ge 0) 'Missing detail body.'
        $text=$text.Substring($start)
        $text=[regex]::Replace($text,'(?m)^Хранилища локации:.*\n\n','')
        $text=[regex]::Replace($text,'(?m)^(#{2,5}) ', '$1# ')
        $text.TrimEnd()
    }
    foreach($dock in @($pages | Where-Object category -ceq 'harbors')){
        $locations=@($pages | Where-Object {$_.harborLocationBinding -and $_.harborLocationBinding.dockGroupId -ceq $dock.id})
        $locations=@($locations | Sort-Object {$_.harborLocationBinding.originalMapLabel},id)
        $location=$null;if($locations.Count){$location=$locations[0]}
        $name=$dock.group.name -creplace '^SP_(?:A|T[0-9]+H)_',''
        $relative="Harbors/$name.md"

        Assert ($destinations.Add($relative)) 'Duplicate merged harbor page.'
        $oldPath=[IO.Path]::GetFullPath((Join-Path $supplies $dock.file))
        $newPath=[IO.Path]::GetFullPath((Join-Path $supplies $relative))
        Assert ($oldPath.StartsWith($supplies+[IO.Path]::DirectorySeparatorChar) -and $newPath.StartsWith($supplies+[IO.Path]::DirectorySeparatorChar) -and $oldPath -cne $newPath) 'Invalid merged page paths.'
        Assert (!(Test-Path -LiteralPath $newPath)) 'Destination already exists.'
        $dockBody=DetailBody $oldPath
        $start=$dockBody.IndexOf('| Название |');Assert ($start -ge 0) 'Missing harbor summary table.'
        $dockBody=$dockBody.Substring($start)
        $known=$dock.known;$unknown=$dock.unknown
        $description='Здесь приведён состав дока и проверки его физических и виртуальных контейнеров.'
        $expansionRow='';$expansionBody=''
        $sourcePaths=[Collections.Generic.List[string]]::new()
        $sourcePaths.Add($oldPath)
        if($locations.Count){
            $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
            foreach($id in $dock.entryIds){$null=$seen.Add($id)}
            $expansionKnown=0.0;$expansionUnknown=0
            $bodies=[Collections.Generic.List[string]]::new()
            foreach($part in $locations){
                $uniqueIds=@($part.entryIds | Where-Object {$seen.Add($_)})
                $selected=@($entries | Where-Object {$_.id -cin $uniqueIds})
                $partKnown=0.0;foreach($entry in $selected){$partKnown+=$entry.knownInitialSubtotal}
                $partUnknown=@($selected | Where-Object status -cne 'resolved').Count
                $expansionKnown+=$partKnown;$expansionUnknown+=$partUnknown
                $partPath=[IO.Path]::GetFullPath((Join-Path $supplies $part.file))
                Assert ($partPath.StartsWith($supplies+[IO.Path]::DirectorySeparatorChar)) 'Location outside output.'
                $sourcePaths.Add($partPath)
                $partLines=[Collections.Generic.List[string]]::new()
                $partLines.Add("### Подпись карты: $(Text $part.harborLocationBinding.originalMapLabel) — $(Position $part.position $part.positionStatus)");$partLines.Add('')
                $members=@($part.group.members | Where-Object {$_.objectId -cin $uniqueIds})
                if(!$members.Count){
                    $partLines.Add('Все хранилища этой подписи уже показаны выше. Повторно не учитываются.');$partLines.Add('')
                }else{
                    $partLines.Add("Начальных припасов в неповторяющихся объектах: **$(Number $partKnown)**.");$partLines.Add('')
                    ParentTable $partLines $members $true
                    $partLines.Add('Расстояния относятся к исходной подписи карты. Совпадающие объекты показаны один раз.');$partLines.Add('')
                    $physicalLines=[Collections.Generic.List[string]]::new()
                    AddPhysicalSupplyDetails $physicalLines ([pscustomobject]@{category=$part.category;group=[pscustomobject]@{members=$members}})
                    $physicalText=[regex]::Replace(($physicalLines -join "`n"),'(?m)^(#{2,4}) ', '$1## ')
                    $partLines.Add($physicalText)
                }
                $bodies.Add(($partLines -join "`n"))

            }
            $known+=$expansionKnown;$unknown+=$expansionUnknown
            $expansionAmount=if($expansionUnknown -and !$expansionKnown){'неизвестно'}elseif($expansionUnknown){"$(Number $expansionKnown) + неизвестно"}else{Number $expansionKnown}
            $description='Здесь собраны две группы: собственные хранилища дока и соседние хранилища связанных локаций. Вторая группа нужна, чтобы подсветить возможный недочёт размещения: **возможно, часть этих хранилищ забыли переместить в радиус дока, чтобы они тоже пополнялись**. Это гипотеза для проверки в редакторе. Некоторые контейнеры второй группы уже находятся в радиусе; их игровые проверки показаны отдельно.'
            $expansionRow="| [Потенциальное расширение состава дока](#potential-expansion) | $expansionAmount |`n"
            $body=$bodies -join "`n`n"
            $expansionBody=@"

<a id="potential-expansion"></a>
## 2. Потенциальное расширение состава дока

Хранилища связанных локаций, учтённые по уникальным объектам. Принадлежность этой группе не означает обязательного переноса или подтверждённого пополнения.

$body
"@
        }
        $total=if($unknown -and !$known){'неизвестно'}elseif($unknown){"$(Number $known) + неизвестно"}else{Number $known}
        $text=@"
# $name

[Доки — сводка](Summary.md) · [Все категории](../Summary.md)

$description

## Суммаризация припасов

Всего изначально по конфигам: **$total припасов**.

| Группа | Припасов изначально |
| --- | ---: |
| [Состав дока](#dock-storage) | $($dock.amount) |
$expansionRow| **Всего** | **$total** |

Этот итог не означает, что все указанные припасы пополняются доком. В общей сводке хранилища этой страницы учитываются в категории «Доки», каждый объект один раз.

<a id="dock-storage"></a>
## 1. Состав дока — $($dock.group.name)

$dockBody
$expansionBody
"@
        [IO.File]::WriteAllText($newPath,$text.TrimEnd()+"`n",[Text.UTF8Encoding]::new($false))
        $newLeaf=Split-Path $relative -Leaf
        foreach($file in Get-ChildItem $supplies -Recurse -Filter *.md){
            if($file.FullName -cin $sourcePaths){continue}
            $body=[IO.File]::ReadAllText($file.FullName)
            $updated=[regex]::Replace($body,'\]\(([^)]+)\)',[Text.RegularExpressions.MatchEvaluator]{param($match)
                $link=$match.Groups[1].Value
                if($link -match '^(https?:|#)'){return $match.Value}
                $target=[IO.Path]::GetFullPath((Join-Path $file.DirectoryName ($link -split '#')[0]))
                if($target -cnotin $sourcePaths){return $match.Value}
                $anchor=if($target -ceq $oldPath){'dock-storage'}else{'potential-expansion'}
                $newLink=[IO.Path]::GetRelativePath($file.DirectoryName,$newPath).Replace('\','/')
                return "]($newLink#$anchor)"
            })
            if($file.Name -ceq 'Summary.md'){
                $updated=$updated.Replace("[$(Text $dock.label)](","[$(Text $name)](")
                foreach($part in $locations){$updated=$updated.Replace("- [$(Text $part.label)](","- [$(Text $name)](")}
                # Multiple source groups can now lead to one combined page.
                $seenLinks=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
                $updated=(@($updated -split '\r?\n' | Where-Object {if($_ -match '^- \['){$seenLinks.Add($_)}else{$true}}) -join "`n")
            }
            if($updated -cne $body){[IO.File]::WriteAllText($file.FullName,$updated,[Text.UTF8Encoding]::new($false))}
        }
        foreach($path in $sourcePaths){[IO.File]::Delete($path)}
        foreach($part in $locations){$part.file=$relative}
        $dock.file=$relative
    }
}

# Accounting follows consolidated detail pages; the geographic source graph remains provenance.
function UpdateHarborSummaryAccounting($pages,$entries){
    $transfers=[Collections.Generic.List[object]]::new()
    $owners=@{}
    foreach($part in @($pages | Where-Object harborLocationBinding)){
        $dock=@($pages | Where-Object id -ceq $part.harborLocationBinding.dockGroupId)[0]
        $transfers.Add([ordered]@{groupId=$part.id;sourceCategory=$part.category;dockGroupId=$dock.id;path=$dock.file;entryIds=$part.entryIds;binding=$part.harborLocationBinding})
        foreach($id in $part.entryIds){
            if($owners.ContainsKey($id)){Assert ($owners[$id] -ceq $dock.id) 'Storage assigned to multiple docks.'}
            $owners[$id]=$dock.id
        }
        $dock.entryIds=@(@($dock.entryIds)+@($part.entryIds) | Sort-Object -Unique)
        $null=$pages.Remove($part)
    }
    foreach($entry in $entries){
        if($owners.ContainsKey($entry.id)){
            $entry.sourceCategory=$entry.category
            $entry.category='harbors'
            $entry.summaryDockGroupId=$owners[$entry.id]
        }
    }
    foreach($dock in @($pages | Where-Object category -ceq 'harbors')){
        $items=@($entries | Where-Object {$_.id -cin $dock.entryIds})
        $dock.known=0.0;foreach($item in $items){$dock.known+=$item.knownInitialSubtotal}
        $dock.unknown=@($items | Where-Object status -cne 'resolved').Count
        $dock.amount=if($dock.unknown -and !$dock.known){'неизвестно'}elseif($dock.unknown){"$(Number $dock.known) + неизвестно"}else{Number $dock.known}
        $dock.label=[IO.Path]::GetFileNameWithoutExtension($dock.file)
    }
    $summary=Get-Content -LiteralPath (Join-Path $output 'Supplies/Summary.json') -Raw | ConvertFrom-Json
    $summary.entries=@($entries)
    foreach($total in $summary.categories){
        $selected=@($entries | Where-Object category -ceq $total.category)
        $total.knownInitialSupplies=0.0;foreach($item in $selected){$total.knownInitialSupplies+=$item.knownInitialSubtotal}
        $total.unknownEntryCount=@($selected | Where-Object status -cne 'resolved').Count
        $total.uniqueEntryCount=$selected.Count
        $total.status=if($total.unknownEntryCount){'partial'}else{'resolved'}
    }
    Assert (($summary.categories | Measure-Object knownInitialSupplies -Sum).Sum -eq $summary.knownInitialSupplies) 'World supply total changed.'
    $summary | Add-Member -NotePropertyName harborLocationTransfers -NotePropertyValue @($transfers)
    $summary | Add-Member -NotePropertyName classificationRule -NotePropertyValue 'Consolidated harbor pages own their source storage and associated expansion entries; sourceCategory retains the original map classification.'
    $summary.deduplication='Every entry ID counted once globally; associated location groups are unioned per dock; virtual storage excluded.'
    WriteJson 'Supplies/Summary.json' $summary
    $mainPath=Join-Path $output 'Supplies/Summary.md'
    $text=[IO.File]::ReadAllText($mainPath)
    foreach($total in $summary.categories){
        $folder=$folders[$total.category]
        $amount=Number $total.knownInitialSupplies;if($total.unknownEntryCount){$amount+=' + неизвестно'}
        $pattern='(?m)^\| \['+[regex]::Escape($total.name)+'\]\('+[regex]::Escape("$folder/Summary.md")+'\) \| [^|]+ \|$'
        $text=[regex]::Replace($text,$pattern,"| [$($total.name)]($folder/Summary.md) | $amount |")
        $detail=[Collections.Generic.List[string]]::new();$detail.Add("## [$($total.name)]($folder/Summary.md)");$detail.Add('')
        $table=[Collections.Generic.List[string]]::new();$table.Add('| Название | Припасов изначально |');$table.Add('| --- | ---: |')
        foreach($page in @($pages | Where-Object category -ceq $total.category)){$table.Add("| [$(Text $page.label)]($($page.file)) | $($page.amount) |")}
        if($table.Count -eq 2){$table.Add('');$table.Add('Отдельно учитываемых хранилищ в этой категории нет.')}
        foreach($line in $table){$detail.Add($line)};$detail.Add('')
        $section='(?ms)^## \['+[regex]::Escape($total.name)+'\][^\r\n]*\r?\n.*?(?=^## |^Один объект)'
        $text=[regex]::Replace($text,$section,($detail -join "`n")+"`n")
        $categoryPath=Join-Path $output "Supplies/$folder/Summary.md"
        $cat=[IO.File]::ReadAllText($categoryPath)
        $cat=[regex]::Replace($cat,'(?m)^Начальных припасов по конфигам:.*$',"Начальных припасов по конфигам: **$amount**. Итог учитывает каждый объект один раз.")
        $offset=$cat.IndexOf('| Название | Припасов изначально |')
        Assert ($offset -ge 0) 'Missing category summary table.'
        $local=($table -join "`n").Replace("]($folder/",'](')
        $cat=$cat.Substring(0,$offset)+$local+"`n`n[Состав расчёта и источники](../Summary.json).`n"
        if($total.category -ceq 'harbors'){$cat+="`nИтог каждого дока включает собственное хранилище и потенциальное расширение. Это категория справочника, а не подтверждение пополнения всех контейнеров.`n"}
        [IO.File]::WriteAllText($categoryPath,$cat,[Text.UTF8Encoding]::new($false))
    }
    $text=$text.Replace('«Города» включают города, деревни и поселения.','«Доки» включают собственные хранилища и связанные группы потенциального расширения. «Города» включают оставшиеся отдельно учтённые города, деревни и поселения.')
    [IO.File]::WriteAllText($mainPath,$text,[Text.UTF8Encoding]::new($false))
}

# Partition physical stock using measured direct or ancestor-virtual eligibility.
function WriteEligibleHarborGroups($pages,$entries){
    $reports=[Collections.Generic.List[object]]::new()
    foreach($page in @($pages | Where-Object category -ceq 'harbors')){
        $record=$script:harborNeighbors[$page.id]
        $eligible=@($record.containers | Where-Object {$null -ne $_.runtime -and $_.runtime.inRange -eq $true -and $_.runtime.isolated -eq $false -and $_.runtime.allowed -eq $true})
        $slots=[ordered]@{}
        foreach($id in $page.entryIds){
            if($script:detailSlots.ContainsKey($id)){$slots[$id]=$script:detailSlots[$id];continue}
            Assert ($rows.ContainsKey($id)) 'Harbor entry missing source parent.'
            $parent=$rows[$id]
            foreach($slot in $script:detailSlots.Values){if($parent.sourceId -cin $slot.ancestorSourceIds){$slots[$slot.id]=$slot}}
        }
        $parts=[Collections.Generic.List[object]]::new()
        foreach($slot in $slots.Values){
            $evidence=@($eligible | Where-Object {$_.id -ceq $slot.id -or ($_.virtual -and $_.sourceId -cin $slot.ancestorSourceIds)})
            $parts.Add([pscustomobject]@{slot=$slot;group=$(if($evidence.Count){'eligible'}else{'potential_expansion'});evidenceIds=@($evidence | ForEach-Object {$_.id})})
        }
        $sum=0.0;foreach($part in $parts){Assert ($part.slot.configuredInitialStatus -ceq 'resolved') 'Unresolved stock requires explicit presentation.';$sum+=$part.slot.configuredInitialSupplies}
        Assert ($sum -eq $page.known -and $page.unknown -eq 0) 'Harbor partition changed initial supplies.'
        $active=@($parts | Where-Object group -ceq eligible);$rest=@($parts | Where-Object group -ceq potential_expansion)
        $activeSum=0.0;foreach($part in $active){$activeSum+=$part.slot.configuredInitialSupplies};$restSum=$sum-$activeSum
        $path=Join-Path $output "Supplies/$($page.file)"
        $old=[IO.File]::ReadAllText($path)
        $lines=[Collections.Generic.List[string]]::new()
        $lines.Add("# $($page.label)");$lines.Add('');$lines.Add('[Доки — сводка](Summary.md) · [Все категории](../Summary.md)');$lines.Add('')
        $lines.Add('Состав дока определяется игровыми проверками IsInRange=true, IsIsolated=false и CanInteractWith=true из сохранённой сессии. Учитывается физический контейнер либо его виртуальное представление-предок в source-иерархии. Вложенность в сущность дока сама по себе не определяет группу. Виртуальные представления не прибавляются к запасу повторно.');$lines.Add('')
        $lines.Add('Это пригодность к подключению в момент измерения, а не подтверждённый цикл пополнения: IsInteractorLinked показал false. Не прошедшие проверки или не измеренные контейнеры остаются в потенциальном расширении для проверки размещения и подключения.');$lines.Add('')
        $lines.Add('## Суммаризация припасов');$lines.Add('');$lines.Add('| Группа | Припасов изначально по конфигам |');$lines.Add('| --- | ---: |');$lines.Add("| [Состав дока](#dock-storage) | $(Number $activeSum) |");$lines.Add("| [Потенциальное расширение состава дока](#potential-expansion) | $(Number $restSum) |");$lines.Add("| **Всего** | **$(Number $sum)** |");$lines.Add('')
        foreach($key in @('eligible','potential_expansion')){
            $selected=@($parts | Where-Object group -ceq $key)
            if($key -ceq 'eligible'){$lines.Add('<a id="dock-storage"></a>');$lines.Add("## 1. Состав дока — $($page.group.name)")}else{$lines.Add('<a id="potential-expansion"></a>');$lines.Add('## 2. Потенциальное расширение состава дока')};$lines.Add('')
            if($key -ceq 'eligible'){
                $table=[regex]::Match($old,'(?m)^\| Название \|[^\r\n]*\r?\n\|[^\r\n]*\r?\n\|[^\r\n]*').Value
                # Original table describes source-descendant capacity, not eligible capacity.
                if($table){
                    $capacity=0.0;foreach($part in $active){Assert ($part.slot.capacityStatus -ceq 'resolved') 'Unresolved eligible capacity.';$capacity+=$part.slot.capacitySupplies}
                    $composition=@($active | Group-Object {$_.slot.capacitySupplies} | Sort-Object {[double]$_.Name} | ForEach-Object {"$($_.Count) × $(Number ([double]$_.Name))"}) -join ' + '
                    if(!$composition){$composition='—'}
                    $tableLines=$table -split '\r?\n';$cells=$tableLines[2].Split('|');$cells[2]=" $(Number $capacity) ";$cells[3]=" $composition ";$tableLines[2]=$cells -join '|'
                    $lines.Add(($tableLines -join "`n"));$lines.Add('')
                }
                if(!$page.group.physicalDescendantContainers.Count){$lines.Add('> ⚠️ **Требует проверки структуры дока**');$lines.Add('>');$lines.Add('> Вложенных хранилищ не найдено. Отдельно расположенные контейнеры перечислены ниже. Проверьте, нужно ли включить их в иерархию дока. Отсутствие вложенности не означает отсутствия пополнения.');$lines.Add('')}
            }
            if(!$selected.Count){$lines.Add('Контейнеров в этой группе нет.');$lines.Add('');continue}
            $lines.Add('| Контейнер | Вместимость / Изначально | Координаты X Y Z, м | Основание |');$lines.Add('| --- | ---: | --- | --- |')
            foreach($part in @($selected | Sort-Object {$_.slot.sourceId},{$_.slot.id})){
                $slot=$part.slot;$why=if($part.group -ceq 'eligible'){'Игровые условия выполнены'}else{'Нет подтверждения всех условий'}
                $lines.Add("| $(Text $slot.name) | $(Value $slot.capacitySupplies $slot.capacityStatus) / $(Number $slot.configuredInitialSupplies) | $(Position $slot.worldPositionMeters $slot.positionStatus) | $why |")
            };$lines.Add('')
        }
        $lines.Add('## Проверки и происхождение');$lines.Add('')
        $audit=[Collections.Generic.List[string]]::new();AddHarborNeighbors $audit $page $pages
        $lines.Add(($audit -join "`n"));$lines.Add('[Распределение физических контейнеров и основания](../HarborStorageGroups.json).');$lines.Add('');$lines.Add('[Исходные поля и иерархия контейнеров](../ContainerDetails.json).')
        [IO.File]::WriteAllText($path,($lines -join "`n")+"`n",[Text.UTF8Encoding]::new($false))
        $reports.Add([ordered]@{groupId=$page.id;name=$page.group.name;path=$page.file;eligibleInitialSupplies=$activeSum;potentialExpansionInitialSupplies=$restSum;totalInitialSupplies=$sum;physicalSlots=@($parts | ForEach-Object {[ordered]@{id=$_.slot.id;group=$_.group;configuredInitialSupplies=$_.slot.configuredInitialSupplies;eligibilityEvidenceIds=$_.evidenceIds}})})
    }
    WriteHarborSummaryBreakdown (Join-Path $output 'Supplies/Harbors/Summary.md') @($reports) ((Get-Content -LiteralPath (Join-Path $output 'Supplies/Harbors.json') -Raw | ConvertFrom-Json).records)
    WriteMainHarborSummary (Join-Path $output 'Supplies/Summary.md') @($reports) ((Get-Content -LiteralPath (Join-Path $output 'Supplies/Harbors.json') -Raw | ConvertFrom-Json).records)
    $index.sections.supplies.harborStorageGroups='Supplies/HarborStorageGroups.json'
    WriteJson 'Supplies/HarborStorageGroups.json' ([ordered]@{schemaVersion=1;snapshotId=$snapshotId;method='measured_eligible_physical_or_source_ancestor_virtual';runtimeRefillConfirmed=$false;evidence='HarborNeighbors.json';records=@($reports)})
}

function WriteHarborSummaryBreakdown($summaryPath,$records,$harborRecords){
    $text=[IO.File]::ReadAllText($summaryPath)
    foreach($record in $records){
        $leaf=Split-Path $record.path -Leaf
        $pattern='(?m)^(\| \[[^\r\n]+\]\('+[regex]::Escape($leaf)+'\) \| )[^|]+( \|)(?:[^\r\n]*)\r?$'
        Assert ([regex]::Matches($text,$pattern).Count -eq 1) 'Missing or repeated harbor summary row.'
        $value="$(Number $record.totalInitialSupplies) ($(Number $record.eligibleInitialSupplies) + $(Number $record.potentialExpansionInitialSupplies))"
        $source=@($harborRecords | Where-Object name -ceq $record.name)
        Assert ($source.Count -eq 1) 'Missing or repeated harbor refill source.'
        $source=$source[0]
        $income=if($source.valueStatus.supplyIncomePerCycle -ceq 'resolved'){Number $source.supplyIncomePerCycle}else{'неизвестно'}
        $minutes=if($source.valueStatus.arrivalInterval -ceq 'resolved'){Number ($source.arrivalIntervalSeconds / 60.0)}else{'неизвестно'}
        $text=[regex]::Replace($text,$pattern,[Text.RegularExpressions.MatchEvaluator]{param($m) $m.Groups[1].Value+$value+" | $income | $minutes |"})
    }
    $text=[regex]::Replace($text,'(?m)^\| Название \| Припасов изначально \|\r?$','| Название | Припасов изначально | Пополнение за цикл, припасы | Пополнение, мин. |')
    $text=[regex]::Replace($text,'(?m)^\| --- \| ---: \|\r?$','| --- | ---: | ---: | ---: |')
    $refillNote='Пополнение указано по конфигам: количество — m_iRegularSuppliesIncomeBase, интервал — m_iSuppliesArrivalInterval / 60 (секунды переведены в минуты). Источник: [Harbors.json](../Harbors.json). Это настройки, а не измеренный объём фактического пополнения.'
    if(!$text.Contains($refillNote)){$text=$text.Replace('## Начальные припасы по докам',"## Начальные припасы по докам`n`n$refillNote")}
    $legend='В скобках: **состав дока + потенциальное расширение**, припасы изначально по конфигам. Состав определяется измеренными условиями подключения; фактический цикл пополнения не подтверждён.'
    if(!$text.Contains($legend)){$text=$text.Replace('## Начальные припасы по докам',"## Начальные припасы по докам`n`n$legend")}
    $text=[regex]::Replace($text,'(?m)^У StPierre, Lamentin и Meaux «неизвестно»[^\r\n]*\r?\n','')
    [IO.File]::WriteAllText($summaryPath,$text,[Text.UTF8Encoding]::new($false))
}
function WriteMainHarborSummary($path,$records,$sources){
    $text=[IO.File]::ReadAllText($path)
    $pattern='(?ms)^## \[Доки\]\(Harbors/Summary\.md\)\r?\n.*?(?=^## |\z)'
    Assert ([regex]::Matches($text,$pattern).Count -eq 1) 'Missing harbor section in world summary.'
    $lines=[Collections.Generic.List[string]]::new()
    $lines.Add('## [Доки](Harbors/Summary.md)');$lines.Add('')
    $lines.Add('«В составе дока» — начальный запас контейнеров, прошедших измеренные игровые условия подключения. «Потенциальное расширение» — остальные припасы на странице дока; пополнение доком для них не подтверждено. Это не доказательство, что их запас невосполняем при любых условиях. Обе группы входят в общий итог, без повторного подсчёта.');$lines.Add('')
    $lines.Add('Количество за цикл взято из m_iRegularSuppliesIncomeBase, интервал — m_iSuppliesArrivalInterval / 60. Это настройки конфигурации; фактический цикл пополнения пока не измерен.');$lines.Add('')
    $lines.Add('| Название | Всего изначально | В составе дока | Пополнение за цикл, припасы | Пополнение, мин. | Потенциальное расширение, припасы |')
    $lines.Add('| --- | ---: | ---: | ---: | ---: | ---: |')
    foreach($record in $records){
        $source=@($sources | Where-Object name -ceq $record.name);Assert ($source.Count -eq 1) 'Missing harbor refill source.';$source=$source[0]
        $income=if($source.valueStatus.supplyIncomePerCycle -ceq 'resolved'){Number $source.supplyIncomePerCycle}else{'неизвестно'}
        $minutes=if($source.valueStatus.arrivalInterval -ceq 'resolved'){Number ($source.arrivalIntervalSeconds / 60.0)}else{'неизвестно'}
        $name=[IO.Path]::GetFileNameWithoutExtension($record.path)
        $lines.Add("| [$name]($($record.path)) | $(Number $record.totalInitialSupplies) | $(Number $record.eligibleInitialSupplies) | $income | $minutes | $(Number $record.potentialExpansionInitialSupplies) |")
    }
    $lines.Add('');$lines.Add('[Распределение хранилищ](HarborStorageGroups.json) · [Настройки пополнения](Harbors.json).');$lines.Add('');$lines.Add('')
    $replacement=$lines -join "`n"
    $text=[regex]::Replace($text,$pattern,[Text.RegularExpressions.MatchEvaluator]{param($m) $replacement})
    [IO.File]::WriteAllText($path,$text,[Text.UTF8Encoding]::new($false))
}
