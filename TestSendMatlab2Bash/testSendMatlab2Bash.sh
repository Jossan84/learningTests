#!/bin/bash

#testSendMatlab2Bash.sh
#08/04/2020

resultFile="log.txt"

# Run script
#matlab -wait -nosplash -noFigureWindows -r "try; run('E:\Develop\Workspace_Matlab\library\TestSendMatlab2Bash\script.m'); catch; end; quit" -logfile $resultFile

# Run function
matlab -wait -nosplash -noFigureWindows -r "cd('E:\Develop\Workspace_Matlab\library\TestSendMatlab2Bash\folder'); try; fun('hola'); catch; end; quit" -logfile $resultFile

# Check test result from matlab
sed -i 's/\r$//' $resultFile # dos2unix conversion of .txt report file

n=1
while read line; do

	# reading each line
	#echo "Line No. $n : $line"
			
	if [ "$line" = "Build successful" ]; then
		echo "Build successful"
	fi
			
	n=$((n+1))
	
done < $resultFile

read -p "Press [Enter] key to start backup..."