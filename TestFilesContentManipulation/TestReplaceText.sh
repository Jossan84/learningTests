#!/bin/sh

#TestReplaceText.sh
#22/07/2022

text="Certified information systems auditor:"
pattern="Certified"
word="CERTIFIED"

sed "s+${pattern}+${word}+g" <<<"$text"