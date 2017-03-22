#!/bin/bash

#sed awk
path=/usr/kerberos/sbin:/usr/kerberos/bin:/usr/local/sbin:/usr/local/bin
echo "path=$path"
echo "path=${path}"

#截取usr左边所有字符显示,如果有多个,截取从左到右的最后一个usr前面的所有字符
echo "path=${path%usr*}"
#截取usr左边所有字符显示,如果有多个,截取从左到右的第一个usr前面的所有字符
echo "path=${path%%usr*}"

#截取usr右边所有字符显示,如果有多个,截取从左到右的第一个usr后面的所有字符
echo "path=${path#*usr}"

#截取usr右边所有字符显示,如果有多个,截取从左到右的最后一个usr后面的所有字符
echo "path=${path##*usr}"

#输出从第3个字符开始到最后
echo "path=${path:3}"

#输出从第3个字符开始后的6个字符
echo "path=${path:3:6}"

#输出字符串的长度
echo "path=${#path}"

#替换第一个usr为USR
echo "path=${path/usr/USR}"
#替换所有的usr为USR
echo "path=${path//usr/TOM}"

exit 0
