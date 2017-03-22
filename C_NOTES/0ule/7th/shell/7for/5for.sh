#!/bin/bash

#控制输出多少行
for ((i = 1; i < 10; i++))
do
    #控制一行的输出
    for ((j = 1; j <= i; j++))
    do
        n=`expr $i \* $j`
        echo -n "$j*$i=$n"

        #-n不换行
        #echo -n "$j*$i=$((i*j))"
        #echo -n "$j*$i=$[i*j] "
    done
        #换行
        echo 
done 

echo "==================="

for i in `seq 1 9`
do
    for j in `seq 1 $i`
    do
        echo -n "$j*$i=$((i*j)) "
    done
        echo 

done




exit 0
