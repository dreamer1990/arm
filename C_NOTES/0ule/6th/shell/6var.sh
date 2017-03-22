#!/bin/bash

#引用命令的输出
# `` 
#$()

var=`ls -l /home`
echo $var

echo "----------"
var=$(pwd)
echo "PWD = $var"


#输出ls -l
echo "ls -l"
#echo " `ls -l`"
#输出结果不会换行
#echo `ls -l`  
#单引号
#echo 'ls -l'  


exit 0
