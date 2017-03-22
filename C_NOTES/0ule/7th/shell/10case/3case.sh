#!/bin/bash

# | 或 


read -p "please input a character:  " ch

case  $ch in
    G|g)
        echo "Girl"
        ;;
    B|b)
        echo "Boy"
        ;;
    *)
        echo "other"
        ;;
esac


exit 0
