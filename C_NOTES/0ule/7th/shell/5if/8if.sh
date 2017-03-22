#!/bin/bash


# x > 20 && x < 40
# cond1 -a cond2
# -a 条件与  只有当cond1 和cond2都成立的时候才为真 

read -p "please input a number:  "  n

if [ $n -gt 20 -a $n -lt 40  ]
then
    echo " x > 20 && x < 40"
else
    echo "other"
fi

#cond1 -o cond 2
#-o 只要cond1 或者cond2中有一个成立则为真
n=$1
if [ $n -lt 0 -o $n -gt 100 ]
then
    echo "越界"
else
    echo "这个数字在0---100"
fi

# !cond1  如果cond1 为真 则!cond1 为假
#         如果cond1 为假 则!cond1 为真

n=1

if [ ! $n -eq 0 ]
then
    echo "-----> true"
else
    echo "----->false"
fi

exit 0


