#!/bin/bash

#输出3 + 4的结果
expr 3 + 4
#输出 3 * 4的结果
expr 3 \* 4
#输出 12 / 4的结果
expr 12 / 4
#输出4 - 3的结果
expr 4 - 3

echo "============="
n=$(expr 3 \* 4)
echo "n = $n"

echo "============="
n=`expr 3 \< 4`
echo "3 < 4 :  $n"



exit 0
