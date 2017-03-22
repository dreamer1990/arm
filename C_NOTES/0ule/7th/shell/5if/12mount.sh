#!/bin/bash

IP=172.16.172.41
DIR=/var/ftp/pub/weekend

#1. 能够Ping通共享资料的主机
if ! ping -c 1 -t 1 $IP &>/dev/null 
then
    echo "网络不通"
    exit 1
fi

#2. 查看共享的东西
if ! showmount -e $IP | grep "weekend" &>/dev/null
then
    echo "shwomount error， 可能是主机nfs服务有问题"
    exit 1
fi

#3. umount
umount -l /mnt &>/dev/null


#4. 挂载 
if ! mount -t nfs $IP:$DIR /mnt &>/dev/null
then
    echo "mount error..."
    exit 1
fi

#如果notes目录不存在就创建notes目录
if  [ ! -d ~/notes ]
then
    mkdir ~/notes
fi

#5. 拷贝
if  \/bin/cp /mnt/* ~/notes -rf &>/dev/null
then
    echo "拷贝笔记成功"
fi

sleep 1

#6. 解挂

umount -l /mnt &>/dev/null

exit 0




