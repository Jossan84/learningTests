@ECHO OFF
ECHO Calling disMessageScript Matlab Script

matlab -nosplash -noFigureWindows -r "try; run('E:\Develop\Workspace_Matlab\library\TestBatchFile\disMessageScript.m'); catch; end; quit"

PAUSE
