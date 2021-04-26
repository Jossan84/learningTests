#!/bin/bash

#testLaunchDispMessageScript.sh
#06/04/2020

echo Calling disMessageScript Matlab Script

result=$(matlab -wait -nosplash -noFigureWindows -r "try; run('E:\Develop\Workspace_Matlab\library\TestBatchFile\dispMessageScript.m'); catch; end; quit")

if [ $result ]
then
	echo Script not run
else
	echo Script run
fi


read -p "Press [Enter] key to start backup..."
