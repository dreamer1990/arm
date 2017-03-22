#!/bin/bash

#定义a为整形变量
declare -i a
a=100
echo "a = $a"

#echo "=========="
#给变量a赋值 “hello world”    #错误的用法  因为a是整形的类型
#a="hello world"
#echo "a = $a"

echo "----------只读变量--------"
declare -r b=3
echo "b = $b"

#只读变量不能重新赋值
#b=100000
#echo "b = $b"


echo "------------环境变量---------------"
#环境变量影响子进程
declare -x A=33
echo "A  = $A"
#unset A  #释放变量A 
./a.sh #启动一个子进程  执行a.sh这个脚本

exit 0
