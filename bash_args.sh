#!/bin/bash
if [ -n "$1" ] && [ -n "$2" ]
then
	file="$2"
	case "$1" in
	-c) 
		if [ -e $file ]
		then
			echo "File $file is already exist"
		else
			echo "File $file created"
			touch $file
		fi
	;;
	-d) 
		if [ -e $file ]
		then
			rm $file
			echo "File $file deleted"
		else
			echo "File $file is not exist"
		fi
	;;
	esac
fi
