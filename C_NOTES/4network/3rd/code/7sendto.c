#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <sys/ioctl.h>
#include <net/if.h>



int main(void)
{
    int sockfd = -1;
    int ret = -1;
    struct ifreq req;
    struct sockaddr_ll ll;

    //AF_PACKET: Low level packet interface  底层数据包接口
    //SOCK_RAW:  Provides raw network protocol access. 提供原始的网络协议访问
    //ETH_P_ALL:  所有的包类型
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err0;
    }

    printf("sockfd: %d\n", sockfd);
        
    //指定网卡名称  IFNAMSIZ不能写错
    strncpy(req.ifr_ifrn.ifrn_name, "eth0", IFNAMSIZ);
    //获取网络接口
    if (-1 == ioctl(sockfd, SIOCGIFINDEX, &req))
    {
        perror("ioctl"); 
        goto err0;
    }

    //初始化结构体
    memset(&ll, 0, sizeof(ll));
    ll.sll_ifindex = req.ifr_ifru.ifru_ivalue;
    ll.sll_family = AF_PACKET;
    ll.sll_protocol = SOCK_RAW;
    
    //模拟发包
    ret =sendto(sockfd, "hello", 5, 0, (void*)&ll, sizeof(ll));
    if (-1 == ret)
    {
        perror("sendto"); 
        goto err0;
    }
    printf("ret = %d\n", ret);


    close(sockfd);
    return 0;
err0:
    return -1;
}
