@echo off
setlocal
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0tools\Start-Workbench.ps1" %*
set "dtrExit=%errorlevel%"
if not "%dtrExit%"=="0" pause
exit /b %dtrExit%
