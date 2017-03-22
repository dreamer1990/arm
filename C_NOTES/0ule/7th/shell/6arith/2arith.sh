#/bin/bash

n=3
echo "n = $n"

#运算 n = n + 4
n=$[n + 4]
echo "n = $n"

#运算 n = n + 7
n=$((n + 7))
echo "n = $n"


exit 0
