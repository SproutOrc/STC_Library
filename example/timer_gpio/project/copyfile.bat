@echo off
if exist  ..\bin\app.hex (
echo �ļ�bin\app.hex�Ѿ����ڣ��Զ�����**����ԭ�б���**
move  ..\bin\app.hex  "..\bin\app_bak.hex"
)

move projectLib.hex  ..\bin\app.hex
