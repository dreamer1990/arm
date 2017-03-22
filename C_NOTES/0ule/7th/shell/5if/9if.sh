#!/bin/bash


#[]  test

#执行命令成功则为真， 执行命令失败为假
#0 为真  非零为假
if ./cond.sh
then
    echo "the condition is true"
else
    echo "the condition is false"
fi

# 
if la -l /home
then
    echo "ls ok"
else
    echo "ls error"
fi

exit 0
