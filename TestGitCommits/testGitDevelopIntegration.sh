#!/bin/bash

#testGitDevelopIntegration.sh
#14/04/2020

#This script do the test for the last commits in develop and integrate them.

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
		
		# Run test for commits
		git checkout test
		
		# Get new commits in develop
		numCommits=$(git rev-list --count develop ^test) # Get the number of commits between develop and test
		for ((c=0; c<$numCommits; c++)); do
			id[c]=$(git rev-parse develop~$c) # Get the id of the commit
			author[c]=$(git show -s --format='%ae' $id) # Get the author of the commit
		done
				
		i=$numCommits
		while [ $i -gt 0 ]; do
			
			git cherry-pick ${id[$i-1]} --strategy-option theirs
						
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
			if [ $result = "true" ]; then
				echo "Commit accepted"
				echo "email: '${author[$i-1]}'"
				git commit --amend -m "Test commit ${id[$i-1]} [Ok]"
			else
				echo "Commit rejected"
				echo "email: '${author[$i-1]}'"
				git commit --amend -m "Test commit ${id[$i-1]} [Fail]"
			fi		
			
			i=$((i-1))
			echo
		done
		
		git merge develop --strategy-option theirs -m "Merge tested commits with develop" 

						
    else
		echo "Skipping because it doesn't look like it has a .git folder."
    fi
	
    echo "Done at `date`"
	echo "Number of commits = $numCommits"
    echo
  fi
done

read -p "Press [Enter] key to start backup..."
