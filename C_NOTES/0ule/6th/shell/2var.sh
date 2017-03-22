#!/bin/bash

#name=value 等号两边不能有空格
#变量是弱类型 
var=111

#取变量的值的方法：  $var   ${var}
echo $var
echo ${var}

echo "-----------------"
var=${var}"hello world"
echo $var

echo "================"
var='M'
echo $var

a=100
b=200
c=$((a+b))
echo "a + b = ${c}"
echo "a + b = ${c}a"


exit 0
