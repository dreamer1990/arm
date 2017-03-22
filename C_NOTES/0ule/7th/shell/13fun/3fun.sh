#!/bin/bash

#命令搜索
#	1) 搜索shell函数.
#	2) 搜索别名.
#	3) 搜索内部命令.
#	4) 搜索$PATH.

ls

function ls()
{
    echo "=====function ls======"
}

#执行函数ls而不是外部命令ls
ls

#执行函数ls而不是外部命令ls
echo "=================="
ls


exit 0
