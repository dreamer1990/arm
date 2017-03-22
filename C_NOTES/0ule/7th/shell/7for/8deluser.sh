#!/bin/bash

for i in `cat txt`
do
    if [ -n $i ]
    then
        userdel -r $i
    else
        echo "用户名不能为空"
    fi

done


exit 0
