#!/bin/bash

#获取本机的IP 地址

#ip=$(ifconfig eth0)
ip=`ifconfig eth0`
#echo $ip
#echo "================"

ip=${ip#*"inet addr:"}
#echo $ip

#echo "==============="
ip=${ip%%" Bcast:"*}
echo $ip

exit 0
