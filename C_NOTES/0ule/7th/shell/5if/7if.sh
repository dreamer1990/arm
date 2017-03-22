#!/bin/bash

#模拟用户登录系统的操作

read -p "please input username and passwd: " name passwd


# name ---> root

if [ $name = "root" ]
then
    if [ $passwd = "123456" ]
    then
        echo "登录成功"
    else
        echo "密码错误"
    fi
     
else
    echo "用户名不匹配"
fi




exit 0
