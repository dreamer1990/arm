#!/bin/bash

#until  当循环条件满足的时候，就结束循环
#until cond
#do
#    cmd #循环体
#done
#

#输出0 － 9的值
i=0
# cond为真的时候  退出循环
until [ $i -gt 9 ]
do
    echo "$i"
    #改变循环变量的值
    let i++  
done

echo "hello ...."


exit 0
