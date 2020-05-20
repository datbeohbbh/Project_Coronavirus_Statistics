#!/bin/bash

python3 runtest.py pretest 50
ret=$?

if [ $ret -eq 0 ];
then 
	python3 runtest.py test 50
	ff=$?
	if [ $ff -ne 0 ];
	then 
	  	exit 1
	fi
else
	exit 1
fi

exit 0
