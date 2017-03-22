#!/bin/bash

PS3="please input a choice  "

select os in win7 xp ubuntu redhat mac 
do
    # = 两边不能有空格
    if [ $os="redhat" ]
    then
        echo "Good taste...  your choice is $os"
        break
    else
        echo "Bad taste... try again"
    fi
done

exit 0
