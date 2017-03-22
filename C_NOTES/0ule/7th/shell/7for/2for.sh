#!/bin/bash

#第二种方式
#for ((i = 0; i < 10; i++))
#do
#  cmd
#done
#

for ((i = 0; i < 10; i++))
do
    echo "i = $i"
done

echo "====================="
for ((i = 10; i > 0; i--))
do
    echo "i = $i"
done




exit 0
