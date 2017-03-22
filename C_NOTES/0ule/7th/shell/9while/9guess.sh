#!/bin/bash

#猜数

n=$[RANDOM%101]
#echo $n
while true
do
    read -p "please input number:  " num

    if [ $num -eq $n ]
    then
        echo "Congratulation, you guess ok"
        break
    elif [ $num -lt $n ]
    then
        echo "输入的数字偏小, 请重新试试"
    else
        echo "输入的数字偏大,请重新试试"
    fi
done

exit 0
