#!/bin/bash

i=0
#当循环条件满足的时候，就执行循环体
while [ $i -lt 10 ]
do
    echo "$i"
    #改变循环变量的值
    let i++
done

exit 0
