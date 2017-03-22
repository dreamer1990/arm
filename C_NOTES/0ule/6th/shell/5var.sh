#!/bin/sh

var=100
echo "var = $var"
echo "------------"
var=$var"dddd"
echo "var = $var"

echo "-----------"
var="$var""dddd"
echo "var = $var"

echo "--------------"
var="$var"aaaaaaa
echo "var = $var"

echo "-------------"
#var 被赋值为空  varaaaaaaaaa是没有赋值的  默认为空
var=$varaaaaaaaaa
echo "var = $var"

echo "------------------"
#推荐引用变量的时候 写为${var}
var=${var}"dddddddddddddddd"
echo "var =  $var "


exit 0
