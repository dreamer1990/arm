#!/bin/bash


read -p "please input a file:  " file

if [ -e $file ]
then
    echo "$file is exists"

    if [ -f $file ]
    then
        echo "$file 为普通文件"
    elif [ -d  $file ]
    then
        echo "$file 是一个目录"
    elif [ -c $file  ]
    then
        echo "$file 是一个字符设备"
    elif [ -b $file ]
    then
        echo "$file 是一个块设备"
    elif [ -S $file ]
    then
        echo "$file 是一个socket文件"
    elif [ -p $file ]
    then
        echo "$file 是一个管道文件"
    elif [ -h $file ]
    then
        echo "$file 是一个链接文件"
    else 
        echo "$file 是这个系统不能识别的文件"
    fi
else
    echo "$file is not exists"
fi


exit 0 
