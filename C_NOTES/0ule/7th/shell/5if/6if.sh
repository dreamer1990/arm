#!/bin/bash

read -p "please input a string:   "  str

# -n 与 ! -z 是等价
#if [ -n $str ]
if [ ! -z $str ]
then
    echo "$str 长度不为零"
fi



exit 0
