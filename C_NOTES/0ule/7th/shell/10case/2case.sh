#!/bin/bash

read -p "please input a character:  "  ch

# uppper 代表所有的大写字母 A－Z
# [A-Z]  同上
# lower  代表所有的小写字母 a-z
# [a-z]  同上
# digit  代表数字
# [0-9]  同上

case $ch in

    [[:upper:]])
        echo "大写字母"
        ;;
    [[:lower:]])
        echo "小写字母"
        ;;
    #[[:digit:]])
    [0-9])
        echo "数字"
        ;;
    *)  
        echo "其它"
        ;;

#代表case语句结束
esac


exit 0
