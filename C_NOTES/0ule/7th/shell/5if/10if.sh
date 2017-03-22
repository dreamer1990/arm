#!/bin/bash

# -a  &&  
# -o  ||
# !   !

#以下三种方式等价
#[ cond1 -a  cond2 ]
#[ cond1 ] && [ cond2 ]
#[[ cond1 && cond2 ]]


# x > 20  && x < 40

read -p "please input a nubmer:  "  n

#if [ $n -gt 20 -a $n -lt 40 ]
#if [ $n -gt 20 ] && [ $n -lt 40 ]
if [[ $n -gt 20 && $n -lt 40 ]]
then
    echo "x > 20 && x < 40"
else
    echo "out of range"
fi


exit 0
