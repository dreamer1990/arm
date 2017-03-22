#!/bin/bash

#*
#**
#***
#****

read -p "please input a line counts:  "  n

for i in `seq 1 $n`
do
    for j in `seq 1 $i`
    do
        echo -n "*"
    done
    echo 
done


#****
#***
#**
#*

echo "======================="
#n=4
for i in `seq 1 $n`
do
    for j in `seq 1 $[n-i+1]`
    do
        echo -n "*"
    done

    echo
done



exit 0
