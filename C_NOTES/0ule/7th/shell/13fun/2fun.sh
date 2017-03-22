#!/bin/bash

function fun1()
{
    echo $$
    echo $0
    echo $1
    echo $2
    echo $3
    echo $#

    shift
    echo "================"
    echo $$
    echo $0
    echo $1
    echo $2
    echo $3
    echo $#
}

#调用函数的时候 给定参数
fun1 aaa bbb ccc dddd




exit 0
