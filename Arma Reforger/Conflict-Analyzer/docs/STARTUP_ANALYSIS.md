# Запуск анализа вместе с проектом

## Результат проверки — 09.11.2026

**Да, через параметры запуска Workbench.** Существующий `RunCommandline()` у `ME_CA_WorldDiagnosticsPlugin` открывает заданный мир, проверяет его путь и вызывает анализ. Менять код плагина для этого не потребовалось.

Это отдельный способ открытия проекта с анализом. Автоматический анализ при обычном открытии `addon.gproj` или выборе проекта в Launcher без параметров не проверен. World Editor по-прежнему загружается; работа без него — отдельная задача.

## Как запустить

Откройте PowerShell в папке `Arma Reforger/Conflict-Analyzer` и выполните команды ниже. Пути установки Tools и игры при необходимости замените своими.

```powershell
$taskExe = 'D:\SteamLibrary\steamapps\common\Arma Reforger Tools\Workbench\ArmaReforgerWorkbenchSteamDiag.exe'
$taskProject = (Resolve-Path './ME_Conflict_Analyzer/addon.gproj').Path
$taskArguments = '-gproj "' + $taskProject + '" -addonsDir "D:\SteamLibrary\steamapps\common\Arma Reforger\addons" -wbModule=WorldEditor -run -exitAfterInit -plugin=ME_CA_WorldDiagnosticsPlugin -ME_CA_World=worlds/MP/CTI_Campaign_HQC_Eden.ent -ME_CA_LogJson=1'
$taskProcess = Start-Process -FilePath $taskExe -ArgumentList $taskArguments -WorkingDirectory (Split-Path $taskExe) -WindowStyle Hidden -PassThru
$taskProcess.WaitForExit()
```

`-plugin` вызывает командный вход плагина; его параметры стоят после имени плагина. `-exitAfterInit` закрывает Workbench после обработки команд запуска. JSON выводится в журнал, разрешение FileIO игровому скрипту не требуется. Это диагностический экспорт, не запуск всех отчётов или генераторов таблиц.

Выберите `console.log` именно этого запуска в `Documents/My Games/ArmaReforgerWorkbench/logs/`, проверьте завершение процесса и строку `[ME_CA] status=SUCCESS`. Затем извлеките JSON по [инструкции диагностики](SOURCE_DIAGNOSTICS.md). Код завершения процесса сам по себе не подтверждает успешный анализ.

## Проверенный запуск

- Игра / Workbench: **1.9.0.37**.
- Мир: `worlds/MP/CTI_Campaign_HQC_Eden.ent`.
- Процесс: 8172; журнал `logs_2026-11-09_20-45-52/console.log`.
- Загрузка запрошена в 20:45:58, успешное завершение анализа — 20:46:24 (Москва).
- Посещено source: **320940**, записей диагностики: **3153**.
- Число editor entity до / после: **130357 / 130357**.
- Расхождений координат: **0**.
- Журнал содержит полный JSON и `status=SUCCESS`; штатный `Convert-DiagnosticsLog.ps1` успешно проверил и извлёк отчёт.
- SHA-256 журнала: `F79A276CE73BFBFBB27BBE9B1618FB43042D560A7E191E3CA1B1CD3CE3B37FBA`.

Временный JSON сохранён в игнорируемом `exports/Startup_1.9.0.37_Diagnostics.json`. Новый постоянный снимок и игровые таблицы не создавались. Проверка подтверждает этот путь запуска и широкую диагностику; остальные плагины, полнота игровых данных и неизменность каждого свойства мира отдельно не проверялись.

## Источники

- [Bohemia: параметры запуска Workbench](https://community.bistudio.com/wiki/Arma_Reforger:Startup_Parameters).
- [Bohemia: Workbench Plugin и RunCommandline](https://community.bistudio.com/wiki/Arma_Reforger:Workbench_Plugin).
- [Исходный плагин](../ME_Conflict_Analyzer/Scripts/WorkbenchGame/WorldEditor/ME_CA_WorldDiagnosticsPlugin.c).
