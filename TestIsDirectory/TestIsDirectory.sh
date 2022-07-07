#TestIsDirectory.sh
#07/07/2022

#!/bin/bash

PATH=$1


if [[ -d $PATH ]]; then
	echo "$PATH is a directory"
elif [[ -f $PATH ]]; then
	echo "$PATH is a file"
else
	echo "$PATH is not valid"
	exit 1
fi	


