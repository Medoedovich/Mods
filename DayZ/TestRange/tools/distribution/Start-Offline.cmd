@echo off
setlocal
title DayZ Test Range - Offline
"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0Start-Offline.ps1" %*
set "DTR_EXIT=%ERRORLEVEL%"
if not "%DTR_EXIT%"=="0" pause
exit /b %DTR_EXIT%
