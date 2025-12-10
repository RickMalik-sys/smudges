@ECHO OFF
C:\DOS\SMARTDRV.EXE /X
PROMPT $p$g
PATH C:\DOS
SET TEMP=C:\TEMP\
rem Load CD-Rom Drivers
MSCDEX.EXE /D:banana /L:D
rem End CD-Rom Drivers
