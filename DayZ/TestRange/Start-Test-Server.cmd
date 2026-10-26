@echo off
setlocal
title DayZ Test Range - Server launcher
"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0tools\Start-Server.ps1" %*
set "DTR_EXIT=%ERRORLEVEL%"
if not "%DTR_EXIT%"=="0" (
    echo.
    echo Server launcher failed. Exit code: %DTR_EXIT%
    echo Logs: "%~dp0runtime\launch-logs"
    pause
)
exit /b %DTR_EXIT%
