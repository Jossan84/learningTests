#!/bin/bash
################################################################################
#                          TestStringSingleQuotes.sh                           #
#                                                                              #
# This script shows how to add a second single quote to a srting that          #
# contain single quotes                                                        #
#                                                                              #
# Change History                                                               #
# 24/02/2021  jossan                                                           #
#                                                                              #
################################################################################
################################################################################
################################################################################
#                                                                              #
#  Copyright (C) 2007, 2019 David Both                                         #
#                                                                              #
#  This program is free software; you can redistribute it and/or modify        #
#  it under the terms of the GNU General Public License as published by        #
#  the Free Software Foundation; either version 2 of the License, or           #
#  (at your option) any later version.                                         #
#                                                                              #
#  This program is distributed in the hope that it will be useful,             #
#  but WITHOUT ANY WARRANTY; without even the implied warranty of              #
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               #
#  GNU General Public License for more details.                                #
#                                                                              #
#  You should have received a copy of the GNU General Public License           #
#  along with this program; if not, write to the Free Software                 #
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA   #
#                                                                              #
################################################################################
################################################################################
################################################################################

isString (){
    #Input String
	local str=$@

    #Change one single quotes for two single quotes
    BASH_COMPAT=4.2 
    str="${str//\'/''}"
    unset BASH_COMPAT

    #Output string
	echo $str
	return 0
}

str1="String with 'single quotes'" 
str2="String without single quotes"
str3="5458645254842389556484218784"
str4="52dsasd/asde\fa~6"

echo $(isString $str1)
echo $(isString $str2)
echo $(isString $str3)
echo $(isString $str4)

read -p "Press [Enter] key to exit"