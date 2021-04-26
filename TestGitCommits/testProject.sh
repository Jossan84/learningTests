#!/bin/bash

#testProject.sh
#14/04/2020

#This script automates the test of the develop branch for the Project

#### Functions definition ####
getNumberOfCommits (){
	local num=$(git rev-list --count develop ^test)
	
	if [ $? -ne 0 ]; then
		echo "Error getting the number of commits"
		return 1
		exit
	fi
	
	echo $num
	return 0
}

getCommitID (){
	local id=$(git rev-parse develop~$1)

	if [ $? -ne 0 ]; then
		echo "Error getting the ID of a commit"
		return 1
		exit
	fi
	
	echo $id
	return 0
}

getCommitAuthor (){
	local author=$(git show -s --format='%ae' $1)

	if [ $? -ne 0 ]; then
		echo "Error getting the author of a commit"
		return 1
		exit
	fi
	
	echo $author
	return 0
}

runTest (){
	matlab -wait -nosplash -noFigureWindows -r "$1" 

	if [ $? -ne 0 ]; then
		echo "Error with the Matlab run"
		return 1
		exit
	fi
	
	return 0
}

getTestResult (){
	local n=1
	local result="Fail"
	
	# Convert from dos 2 unix input .txt report file		
	sed -i 's/\r$//' $1  
			
	# Find test result into the file
	while read line; do		
		#echo "Line No. $n : $line" # reading each line
						
		if [ "$line" = "Build successful" ]; then
			result="Ok"
		fi	
			
		n=$((n+1))
	done < $1
	
	echo $result	
	return 0
}

renameLastCommit (){
	git commit --amend -m "$1"

	if [ $? -ne 0 ]; then
		echo "Error renaming a commit"
		return 1
		exit
	fi

	return 0
}

matlabCommand (){	
	
	local strDir=$1
	strDir="${strDir:1}" 	  #remove first forward slash	
	strDir="${strDir//\//\\}" #forward to backward slash
	strDir="'$strDir'"
	strDir=${strDir:0:2}:${strDir:2}

	local command="cd($strDir); try; $2; catch; end; quit"
	
	echo $command
}

pickUpAndMergeCommit (){	
	git cherry-pick $1 --strategy-option theirs
	
	if [ $? -ne 0 ]; then
		echo "Error renaming a commit"
		return 1
		exit
	fi

	return 0
}

getCommitBranch (){
	local branch=$(git branch --contains $1)

	if [ $? -ne 0 ]; then
		echo "Error getting branch of a commit"
		return 1
		exit
	fi
	
	echo $branch
	return 0
}

getCommitDescription (){
	local description=$(git log --format=%B -n 1 $1)

	if [ $? -ne 0 ]; then
		echo "Error getting branch of a commit"
		return 1
		exit
	fi
	
	echo $description
	return 0
}

##### Main #####

# Set paths
DIR=`pwd`
REPO="project"
WORK="$DIR/$REPO"
REPORT="$REPO/buildReport.txt"
IFS=$'\n'

if [ -d "$DIR/$REPO/.git" ]; then
	cd "$DIR/$REPO"
	
	git checkout test
			
	# Run test for the commits
	echo "Number of commits = $(getNumberOfCommits)"
	echo
	
	countDevelopCommit=$(($(getNumberOfCommits)-1)) # Counter for walk develop branch
	while [ $countDevelopCommit -ge 0 ]; do
			
		commitID=$(getCommitID $countDevelopCommit)			
		commitAuthor=$(getCommitAuthor $commitID)
		commitBranch=$(getCommitBranch $commitID)
		commitDescription=$(getCommitDescription $commitID)
			
		pickUpAndMergeCommit $commitID 	
									
		runTest $(matlabCommand $WORK "test('$commitID', '$commitAuthor', '$commitBranch', '$commitDescription' )") 
			
		result=$(getTestResult "$DIR/$REPORT")
			
		renameLastCommit "Test commit $commitID [$result]"
			
		echo "Commit $commitID from $commitAuthor test $result"
		echo
			
		countDevelopCommit=$((countDevelopCommit-1))	
	done
		
	git merge develop --strategy-option theirs -m "Merge tested commits with develop" 
						
else
	echo "Skipping because it doesn't look like it has a .git folder."
fi
	
echo "Done at `date`"

read -p "Press [Enter] key to start backup..."

# End of main 