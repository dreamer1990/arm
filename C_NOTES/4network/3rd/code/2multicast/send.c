#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 10086
#define SIZE 128


//224.0.0.88  D类IP地址 组播地址  
//route add -net 224.0.0.88 netmask 255.255.255.255 eth0

//发送端
int main(void)
{

    int sockfd;
    int i = 0;
    int ret = -1;
    char buf[SIZE];
    struct sockaddr_in addr;


    //a. 创建套接字
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err0;
    }

    //b. 初始化结构体
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    //填入组播地址
    addr.sin_addr.s_addr = inet_addr("224.0.0.88");

    //c. 发送数据
    while(1)
    {
        memset(buf, 0, SIZE);
        sprintf(buf, "hello uplooking :%d", i++); 

        //发送数据
        ret = sendto(sockfd, buf, strlen(buf), 0, (void *)&addr, sizeof(addr));
        if (ret <= 0)
        {
            perror("sendto"); 
            break;
        }

        printf("sendto ret: %d\n", ret);

        sleep(1);
    }

    //关闭套接字
    close(sockfd);
    return 0;
err0:
    return -1;
}
