#!/bin/bash

#等待用户输入
read var
echo "var = $var"

echo "-------------------------"
#-p  输入之前提示信息
read -p "please input a nubmer:   "  var
echo "var = $var"


echo "----------------------"
#-t 指定用户输入超时的时间  单位是秒 
#超时默认变量的值为空
read -p "please input a name:  "  -t 3 name
echo "name  =  $name"

echo "------------------------"
#-s  不回显
read -p "please input a passwd "  -s  passwd
#换行
echo  
echo "passwd = $passwd"

exit 0
