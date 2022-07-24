#!/bin/sh

#TestFindString.sh
#23/07/2022

line=2
file="text.m"

textLine1="$(awk -v var=$line 'NR>=var && NR<=var' "$file")"
textLine2="$(awk -v var=$(( line + 1 )) 'NR>=var && NR<=var' "$file")"
echo $textLine1
echo $textLine2

sed -i "${line} a ${textLine1}" "$file"
sed -i "$(( line + 1 )) a ${textLine2}" "$file"