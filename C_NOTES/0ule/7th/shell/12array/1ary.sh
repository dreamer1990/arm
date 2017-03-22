#!/bin/bash

#方式一： 定义一个数组
a=(a b c d 111 222 333)
#输出数组所有的元素
#${a[*]}
#${a[@]}
echo ${a[*]}
echo "=============="

#"hello uplooking"
#元素之间以空格分隔
b=("hello world" 111 2222 'M')
echo ${b[@]}
echo "=============="


#方式二: 定义一个数组
c[0]=1111
c[2]=2222
c[4]="hello world"
echo ${c[*]}
echo ${c[1]}
echo ${c[3]}
echo "=============="

#方式三: 定义一个数组
#元素之间用空格分隔
d=([0]="AAAA" [2]="BBBB" [4]="CCCC")
echo ${d[@]}


exit 0
