#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_ether.h>


int main(void)
{
    int sockfd = -1;

    //AF_PACKET: Low level packet interface  底层数据包接口
    //SOCK_RAW:  Provides raw network protocol access. 提供原始的网络协议访问
    //ETH_P_ALL:  所有的包类型
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err1;
    }

    printf("sockfd: %d\n", sockfd);

    close(sockfd);
    return 0;
err1:
    return -1;
}
