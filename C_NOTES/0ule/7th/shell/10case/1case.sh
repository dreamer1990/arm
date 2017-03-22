#!/bin/bash

##格式
#case $n in
#    1)
#        cmd
#        ;;
#    2)
#        cmd
#        ;;
#    *)
#        cmd
#        ;;
#esac

read -p "please input a number: " n

case $n in
    1)
        echo "星期一"
        #两个分号之间不能有空格
        ;;
    2)
        echo "星期二"
        ;;
    3)
        echo "星期三"
        ;;
    *)
        echo "星期四－－星期日"
        ;;
esac

exit 0
