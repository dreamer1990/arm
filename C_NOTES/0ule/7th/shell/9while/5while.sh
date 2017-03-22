#!/bin/bash

i=1

#输出1－10 并且不输出3
while true
do
    if [ $i -eq 3 ]
    then
        let i++
        continue  #结束本次循环
    fi

    if [ $i -eq 11 ]
    then
        break  #结束本层循环
    fi

    echo "$i"
    let i++

done


exit 0
