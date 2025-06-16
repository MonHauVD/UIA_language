@echo off
set PATH=%PATH%;%~dp0UiaCompiler
echo Added UiaCompiler to PATH
echo Now you can run commands like: UiaRun test_xu_ly_con_so.uia

REM Add to PowerShell PATH
powershell -Command "$env:Path += ';%~dp0UiaCompiler'"
echo Added UiaCompiler to PowerShell PATH 