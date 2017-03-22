#!/bin/bash

#break 跳出本层循环
#continue 结束本次循环

#输出1－10  

i=1
while [ $i -le 10 ]
do

    if [ $i -eq 3 ]
    then
        let i++
        continue
    fi

    echo "$i"

    #以下四种方法等价
    let i++
    #i=$[i+1]
    #i=$((i+1))
    #i=`expr $i + 1`
done


exit 0
