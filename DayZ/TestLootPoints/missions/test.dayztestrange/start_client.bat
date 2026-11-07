@echo off
set "GAME=D:\SteamLibrary\steamapps\common\DayZ"
set "MODS=D:\DayZModding\MyMods\DayZTestRange\dist\@DayZTestRange"
set "MISSION=%~dp0"
set "MISSION=%MISSION:~0,-1%"

cd /d "%GAME%"
start "" DayZDiag_x64.exe -mod=%MODS% -mission=%MISSION% -profiles=%~dp0logs -window -nosplash -noPause -noBenchmark
exit