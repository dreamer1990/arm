#!/bin/bash

#1
#22
#333
#4444


read -p "please input a number[1-9]:  "  n
i=1
j=1


#控制输出有多少行
while [ $i -le $n ]
do
    #控制每一行的输出

    j=1
    while [ $j -le $i ]
    do
        #-n 不用换行
        echo -n $i         
        let j++
    done
    #换行
    echo 
    let i++

done



exit 0
