:: Name:     testCommands.cmd
:: Purpose:  Automate Git Commands across repos using a batch script 
:: Date   : 01/04/2020


@ECHO OFF
REM SETLOCAL REPOSITORIES

SET REPOSITORIES=%USERPROFILE%

REM variables
PUSHD "%~dp0" >NUL && SET root=%CD% && POPD >NUL

ECHO %root%
ECHO %TEMP%
ECHO %REPOSITORIES%
ECHO Call script


START directLink.lnk
ECHO Srcript ends

PAUSE


:END
ENDLOCAL
ECHO ON
@EXIT /B 0



