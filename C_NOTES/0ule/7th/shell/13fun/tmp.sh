#!/bin/bash


./cond.sh
if [ $? -eq 0 ]
#if ./cond.sh
then
    echo "condition is true"
else
    echo "condition is false"

fi

exit 0
