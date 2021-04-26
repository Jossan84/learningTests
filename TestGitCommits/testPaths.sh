#!/bin/bash

#testPaths.sh
#06/04/2020

REPOSITORIES=`pwd`
TEST="project/test.m"
REPORT="project/buildReport.txt"

testPath="$REPOSITORIES/$TEST"
testPath="${testPath:1}" 	  #remove first forward slash	
testPath="${testPath//\//\\}" #forward to backward slash
testPath="'$testPath'"
testPath=${testPath:0:2}:${testPath:2}



reportPath="$REPOSITORIES/$REPORT"
#reportPath="${reportPath:1}" 	  #remove first forward slash
#reportPath="${reportPath//\//\\}" #forward to backward slash
#reportPath="'$reportPath'"
#reportPath=${reportPath:0:2}:${reportPath:2}

echo $reportPath

IFS=$'\n'


read -p "Press [Enter] key to start backup..."
