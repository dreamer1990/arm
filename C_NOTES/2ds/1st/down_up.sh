#!/bin/bash

IP=2.2.2.162
DIR=/key
WORK=/work

if ! ping 2.2.2.162 -c 1 &> /dev/null
then
	echo "no link"
	exit 0
fi

umount -l /mnt &> /dev/null

if [ $1 = "down" ]
then
	if showmount -e $IP &> /dev/null
	then
		mount $IP:$DIR /mnt
		/bin/cp /mnt/* /test/ -rf
		umount -l /mnt
	else
		echo "nfs failed!"
	fi
elif [ $1 = "up" ]
then
	if showmount -e $IP &> /dev/null
	then
		mount $IP:$WORK /mnt
		/bin/cp /162_张三 /mnt -rf
		umount -l /mnt
	else
		echo "nfs failed!"
	fi
else
	echo "option err!"
fi

