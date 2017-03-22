#!/bin/bash


#第一种方式
#for i in list....
#do
#    cmd
#done


#循环列表以空格分隔
#for i in 1 2 3 4 5 hello lucy uplooking A
#如果字符串中有空格，必须用双引号
for i in 1 2 3 4 5 "hello lucy" uplooking A
do 
    echo "i = $i"
done

echo "================="

#输出1到10
for i in $(seq 1 10)
do
    echo "$i"
done

exit 0
