#!/bin/bash

#进程ID号
echo "$$"
#脚本名字
echo "$0"
#$n  代表第n个参数，如果没有，则为空
#第一个参数
echo "$1"
echo "$2"

#输出所有参数 $*与$@等价
echo "$*"
echo "$@"
#输出参数的个数
echo "$#"

echo "====================="

shift

echo $$
echo $0
echo $*
echo $#
echo $0
echo $1
echo $2




exit 0
