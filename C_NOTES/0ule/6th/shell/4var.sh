#!/bin/bash

#单引号和双引号的区别
# "" 双引号会解析${var}
#'' 单引号会不转义所有的特殊字符 

AAA=100000
echo "AAA =  $AAA"
echo 'AAA = $AAA'


# -e  表示转义 \n \t等等转义字符
echo -e "\t \n hello \n world"
echo -e '\t \n hello \n world'

echo "--------------------"
#单引号和双引号都没有转义
echo "\t \n hello \n world"
echo '\t \n hello \n world'


exit 0
