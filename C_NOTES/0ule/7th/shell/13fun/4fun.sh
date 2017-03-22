#!/bin/bash

#检测在线的IP地址

NetWork=172.16.172.

#检测能够ping通的IP地址
function my_ping()
{
    for i in `seq 2 254`
    do
        if ping -c 1 -i 0.1 $NetWork$i &>/dev/null
        then
            echo $NetWork$i >> ip.list
        else
            echo $NetWork$i >> ipno.list
        fi
    done
}

#自动配置IP地址，可以防止IP地址冲突
function config_ip()
{
    for i in $(seq 2 254)
    do
        if ! ping -c 1 -i 0.1 $NetWork$i &>/dev/null
        then
            ifconfig eth0 $NetWork$i netmask 255.255.255.0 &>/dev/null
            break
        fi
    done
}

#删除IP列表文件
function rm_file()
{
    if [ -f ./ip.list ]
    then
        rm -f ip.list >/dev/null
    fi

    if [ -f ./ipno.list ]
    then
        rm -rf ipno.list > /dev/null
    fi

}

#rm_file
#my_ping
config_ip

exit 0
