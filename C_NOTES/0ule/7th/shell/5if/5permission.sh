#!/bin/bash

#$1
#$0 脚本名字
#$$ 进程ID 号

if [ -r $1 ]
then
    echo "$1 存在并且可以读"
elif test -w $1 
then
    echo "$1存在并且可以写"
elif [ -x $1 ]
then
    echo "$1存在并且可以被执行"
else
    echo "文件不存在或者文件存在没有任何权限"
fi

exit 0
