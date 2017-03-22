#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_ether.h>
#include <sys/ioctl.h>
#include <net/if.h>


int main(void)
{
    int sockfd = -1;

    struct ifreq req;

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

    memset(&req, 0, sizeof(req));
    //指定网卡名称
    strncpy(req.ifr_ifrn.ifrn_name, "eth0", 4);
    //获取网络接口
    if (-1 == ioctl(sockfd, SIOCGIFINDEX, &req))
    {
        perror("ioctl"); 
        goto err0;
    }

    req.ifr_ifru.ifru_flags |= IFF_PROMISC;
    if (-1 == ioctl(sockfd, SIOCGIFINDEX, &req))
    {
        perror("ioctl"); 
        goto err0;
    }



    close(sockfd);
    return 0;
err0:
    return -1;
}
