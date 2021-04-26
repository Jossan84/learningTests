@ECHO OFF
ECHO Calling disMessageFunction() Matlab function

matlab -nosplash -noFigureWindows -r "try; cd('E:\Develop\Workspace_Matlab\library\TestBatchFile'); dispMessageFunction(); catch; end; quit"

PAUSE
