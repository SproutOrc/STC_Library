@echo off
if exist  ..\bin\app.hex (
echo 文件bin\app.hex已经存在，自动备份**覆盖原有备份**
move  ..\bin\app.hex  "..\bin\app_bak.hex"
)

move projectLib.hex  ..\bin\app.hex
