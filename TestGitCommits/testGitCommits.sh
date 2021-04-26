#!/bin/bash

#testGitCommmits.sh
#06/04/2020

#This script extract the ID and the author where the HEAD is pointing
#for all repos into the folder.

# Set paths
REPOSITORIES=`pwd`

TEST="project/test.m"
REPORT="project/buildReport.txt"

testFile="$REPOSITORIES/$TEST"
testFile="${testFile:1}" 	  #remove first forward slash	
testFile="${testFile//\//\\}" #forward to backward slash
testFile="'$testFile'"
testFile=${testFile:0:2}:${testFile:2}

reportFile="$REPOSITORIES/$REPORT"

# Set Matlab command
command="try; run($testFile); catch; end; quit"

IFS=$'\n'

for REPO in `ls "$REPOSITORIES/"`
do
  if [ -d "$REPOSITORIES/$REPO" ]; then
  	echo "Repository: $REPOSITORIES/$REPO at `date`"
	echo
	
    if [ -d "$REPOSITORIES/$REPO/.git" ]; then
		cd "$REPOSITORIES/$REPO"
		git checkout develop
		numCommits=$(git rev-list --count HEAD ^test) # Get the number of commits between develop and test
		echo "Diferent commits between test and develop: $numCommits"
		echo
		for ((c=0; c<$numCommits; c++)); do
			id=$(git rev-parse HEAD~$c) # Get the id of the commit
			author=$(git show -s --format='%ae' $id) # Get the author of the commit
		
			# Run test to commit
			git checkout $id
				
			matlab -wait -nosplash -noFigureWindows -r "$command"  
		
			if [ $? -ne 0 ]; then
				echo "Run error."
				exit
			fi
		
			# Check test result from matlab
			sed -i 's/\r$//' $reportFile # dos2unix conversion of .txt report file
			
			n=1
			result="false"
			while read line; do
			
				#echo "Line No. $n : $line" # reading each line
						
				if [ "$line" = "Build successful" ]; then
					result="true"
				fi	
			
				n=$((n+1))
	
			done < $reportFile
			
			# Do something with the commit			
			echo "**************************************************************"
			echo "Commit: $id"
			echo "Author: $author"
			if [ $result = "true" ]; then
				echo "Commit accepted"
			else
				echo "Commit rejected"
			fi
			echo "**************************************************************"
			echo

			# Checkout to develop
			git checkout develop
			
			# End test for commit
		done

    else
		echo "Skipping because it doesn't look like it has a .git folder."
    fi
	
    echo "Done at `date`"
	echo "Number of commits = $numCommits"
    echo
  fi
done

read -p "Press [Enter] key to start backup..."
