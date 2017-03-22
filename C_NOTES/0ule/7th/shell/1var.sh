#!/bin/bash

a=123456

echo $a
echo ${a}


echo "================="

read -n 6 -p "please input a user name:  "  name
#解析$name
echo "name = $name"
#把$name当作字符串处理
echo 'name = $name'

unset name
read -t 6 -p "please input a user name: "  name
echo "name = $name"




exit 0
