#!/bin/bash

#第三种方式
#if 条件1
#then
#    cmd1
#elif 条件2
#then
#    cmd2
#elif 条件3
#then
#    cmd3
#.....
#else
#    cmdn
#fi

read -p "please input a score:[0-100]  "  score


if [ $score -gt 90 ]
then
    echo "Rank A"
#elif [ $score -gt 80 ]
elif [ $score -gt 80 ]
then
    echo "Rank B"
elif [ $score -gt 70 ]
then
    echo "Rank C"
elif [ $score -gt 60 ]
then
    echo "Rank D"
else
    echo "Please try again...."
fi


exit 0
