#!/bin/bash

#break  退出本层循环

while :
do
    read -p "please input a number:    "  n

    if [ $n -eq -1 ]
    then
        echo "exit.."
        break
    else
        echo "$n"
    fi
done


exit 0
