#!/bin/bash

#第一种方式
#if  条件判断
#then
#    执行的命令
#fi
#

#第一种方式
#if  条件判断; then
#    执行的命令
#fi
#


a=200
b=100

#test 条件测试的命令
if test $a -gt $b
then
    #如果上述条件为真就执行下面的语句
    echo "a is greater than b"
fi

echo "=================="
if test $a -gt $b;then
    #如果上述条件为真就执行下面的语句
    echo "a is greater than b"
fi


exit 0
