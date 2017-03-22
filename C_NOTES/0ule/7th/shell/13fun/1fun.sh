#!/bin/bash

#定义函数的第一种方式
function fun1()
{
    echo "=======fun1====="
}

#定义函数的第二种方式
fun2()
{
    echo "======fun2======"
}


#调用函数fun1
fun1
#调用函数fun2
fun2

fun1


exit 0
