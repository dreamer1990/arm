#!/bin/bash

#test 与 [] 等价

#if 条件判断
#then
#    cmd1    #执行命令1
#else
#    cmd2    #执行命令2
#fi
#

a=1000
b=200

if test $a -lt $b
then
    echo "$a is less than $b"
else
    echo "$a is greater or equal than $b"
fi

echo "======================"

#[] 各有一个空格
#if [ $a -lt $b ];then
if [ $a -lt $b ]
then
    #a < b 执行如下一句话
    echo "$a is less than $b"
else
    # a >= b 情况
    echo "$a is greater or equal than $b"
fi


exit 0
