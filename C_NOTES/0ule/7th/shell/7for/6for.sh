#!/bin/bash

read -p "please input a path: "  path


for i in `ls $path`
do
    #切换到path目录中, 否则出现不能判断文件类型
    cd $path
    #echo "$i"
    if [ -d $i ]
    then
        tar -czvf $i.tar.gz $i && rm -rf $i &>/dev/null
    elif [ -f $i ]
    then
        rm -rf $i &>/dev/null
    else
        echo "other"
    fi
done

exit 0
