@echo off
setlocal
title DayZ Test Range - Stop server
"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0tools\Stop-Server.ps1" %*
set "DTR_EXIT=%ERRORLEVEL%"
echo.
echo Stop exit code: %DTR_EXIT%
pause
exit /b %DTR_EXIT%
