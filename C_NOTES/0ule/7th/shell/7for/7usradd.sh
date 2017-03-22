#!/bin/bash

for i in `cat txt`
do
   # echo "$i"
    if [ -n $i ]
    then
        adduser $i 
        echo $i"123" | passwd $i --stdin
    else
        echo "用户名不能为空"
   fi
done

exit 0
