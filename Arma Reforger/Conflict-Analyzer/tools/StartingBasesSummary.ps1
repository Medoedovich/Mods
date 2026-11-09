function AddStartingBasesSummary($summaryPath,$report){
    $text=[IO.File]::ReadAllText($summaryPath)
    $lines=[Collections.Generic.List[string]]::new()
    $lines.Add('## [Стартовые позиции главных баз](StartingBases/Summary.md)');$lines.Add('')
    $lines.Add('Кандидаты HQ, выбираемые при запуске миссии. Вместимость относится к создаваемому командному пункту, а не ко всей ресурсной сети базы. Данные кандидатов не прибавляются к общему начальному запасу.');$lines.Add('')
    $lines.Add('| Позиция | Вместимость КП, припасы | Базовое пополнение за цикл, припасы | Пополнение, мин. |');$lines.Add('| --- | ---: | ---: | ---: |')
    foreach($record in $report.records){$lines.Add("| [$($record.name)](StartingBases/$($record.name).md) | $($record.commandPostCapacitySupplies) | $($record.incomePerCycle.ToString('0.###',[Globalization.CultureInfo]::InvariantCulture)) | $($record.arrivalIntervalMinutes.ToString('0.###',[Globalization.CultureInfo]::InvariantCulture)) |")};$lines.Add('');$lines.Add('')
    $pattern='(?ms)^## \[Стартовые позиции главных баз\][^\r\n]*\r?\n.*?(?=^## |\z)'
    $text=[regex]::Replace($text,$pattern,'')
    $anchor='## [Контрольные точки](ControlPoints/Summary.md)'
    if(!$text.Contains($anchor)){throw 'Missing control point section for starting-base category.'}
    $text=$text.Replace($anchor,($lines -join "`n")+$anchor)
    [IO.File]::WriteAllText($summaryPath,$text,[Text.UTF8Encoding]::new($false))
}

function MoveStartingBaseAccounting($suppliesDirectory,$report){
    $path=Join-Path $suppliesDirectory 'Summary.json'
    $summary=Get-Content -LiteralPath $path -Raw | ConvertFrom-Json
    $moved=@()
    foreach($record in $report.records){
        if(!$record.physicalSlots.Count){continue}
        $id='other_supply_parent/'+$record.sourceId
        $matches=@($summary.entries | Where-Object id -ceq $id)
        if($matches.Count -ne 1){throw 'HQ storage must have exactly one accounting entry.'}
        $entry=$matches[0]
        if($entry.knownInitialSubtotal -ne $record.staticDescendantInitialSupplies){throw 'HQ storage amount mismatch.'}
        if($entry.category -cnotin @('other','starting_bases')){throw 'Unexpected previous HQ storage category.'}
        $entry | Add-Member -NotePropertyName sourceCategory -NotePropertyValue 'other' -Force
        $entry.category='starting_bases';$entry.unrecognized=$false;$moved+=$entry
        $page=@($summary.detailPages | Where-Object {$id -cin $_.entryIds})
        if($page.Count -ne 1 -or $page[0].entryIds.Count -ne 1){throw 'Unexpected shared HQ detail page.'}
        $page[0].category='starting_bases';$page[0].path="StartingBases/$($record.name).md"
        if($record.name -notmatch '^StartingPos[0-9]+$'){throw 'Unsafe candidate name.'}
        $oldPath=Join-Path $suppliesDirectory "Other/$($record.name).md"
        if(Test-Path -LiteralPath $oldPath){[IO.File]::Delete([IO.Path]::GetFullPath($oldPath))}
    }
    $summary.categories=@($summary.categories | Where-Object category -cne 'starting_bases')+@([pscustomobject]@{category='starting_bases';name='Стартовые позиции главных баз';knownInitialSupplies=0.0;status='resolved';unknownEntryCount=0;uniqueEntryCount=0})
    foreach($category in $summary.categories){
        $items=@($summary.entries | Where-Object category -ceq $category.category)
        $category.knownInitialSupplies=0.0;foreach($item in $items){$category.knownInitialSupplies+=$item.knownInitialSubtotal}
        $category.uniqueEntryCount=$items.Count;$category.unknownEntryCount=@($items | Where-Object status -cne 'resolved').Count
        $category.status=if($category.unknownEntryCount){'partial'}else{'resolved'}
    }
    if(($summary.categories | Measure-Object knownInitialSupplies -Sum).Sum -ne $summary.knownInitialSupplies){throw 'World total changed.'}
    [IO.File]::WriteAllText($path,($summary | ConvertTo-Json -Depth 60)+"`n",[Text.UTF8Encoding]::new($false))
    $other=($summary.categories | Where-Object category -ceq other).knownInitialSupplies
    $hq=($summary.categories | Where-Object category -ceq starting_bases).knownInitialSupplies
    foreach($name in @('Summary.md','Other/Summary.md')){
        $file=Join-Path $suppliesDirectory $name;$text=[IO.File]::ReadAllText($file)
        foreach($entry in $moved){$text=[regex]::Replace($text,'(?m)^\| \['+[regex]::Escape($entry.name)+'\]\((?:Other/)?'+[regex]::Escape($entry.name)+'\.md\) \|[^\r\n]*\r?\n','')}
        if($name -ceq 'Summary.md'){
            $text=[regex]::Replace($text,'(?m)^\| \[Другое\]\(Other/Summary.md\) \|[^\r\n]*',"| [Другое](Other/Summary.md) | $other |")
            $text=[regex]::Replace($text,'(?m)^\| \[Стартовые позиции главных баз\]\(StartingBases/Summary.md\) \|[^\r\n]*\r?\n','')
            $text=$text.Replace('| [Другое](Other/Summary.md)',"| [Стартовые позиции главных баз](StartingBases/Summary.md) | $hq |`n| [Другое](Other/Summary.md)")
        }else{$text=[regex]::Replace($text,'(?m)^Начальных припасов по конфигам:.*$',"Начальных припасов по конфигам: **$other**. Итог учитывает каждый объект один раз.")}
        [IO.File]::WriteAllText($file,$text,[Text.UTF8Encoding]::new($false))
    }
    $note="В категории стартовых позиций учитываются только уже размещённые физические контейнеры: **$hq** припасов изначально. Они перенесены из «Другое» и учтены один раз. Запас будущих динамических HQ не прибавляется за каждого кандидата."
    foreach($file in Get-ChildItem (Join-Path $suppliesDirectory 'StartingBases') -Filter *.md){
        $text=[IO.File]::ReadAllText($file.FullName)
        $text=$text.Replace('Сумма кандидатов не прибавляется к мировому запасу. Уже размещённые контейнеры сохраняют прежний учёт; динамический запас выбранных HQ нельзя умножать на количество кандидатов.',$note)
        $text=$text.Replace('Эти физические слоты уже входят в мировой каталог. Повторно не прибавляются.','Эти физические слоты учтены в категории «Стартовые позиции главных баз»; из «Другое» исключены. Повторно не прибавляются.')
        [IO.File]::WriteAllText($file.FullName,$text,[Text.UTF8Encoding]::new($false))
    }
}
