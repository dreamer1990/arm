#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>    
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 10086
#define SIZE 128

//UDP服务器
int main(void)
{
    int ret = -1;
    int sockfd = -1; 
    int i = 0;
    char buf[SIZE];
    struct sockaddr_in sockaddr;
    socklen_t len = sizeof(struct sockaddr_in);

    //a. 创建套接字
    //PF_INET  AF_INET等价  
    //sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    //SOCK_STREAM  tcp    SOCK_DGRAM udp
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err0;
    }

    //b. 初始化结构体
    //bzero(&sockaddr, sizeof(sockaddr)); 
    //memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "172.16.1.201", &sockaddr.sin_addr); 
    bzero(&sockaddr.sin_zero, 1);

/*
 *    //c. 绑定
 *    ret = bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr));
 *    if (-1 == ret)
 *    {
 *        perror("bind"); 
 *        goto err1;
 *    }
 *
 */

    //d. 收发数据
    while(1)
    {
        memset(buf, 0, SIZE); 
        ret = sprintf(buf, "hello uplooking %d", i++);
        //udp 发送数据只能是sendto  不能是send
        //sendto不是阻塞  
        ret = sendto(sockfd, buf, ret, 0,(struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in));
        if (ret <= 0)
        {
            perror("sendto"); 
            goto err1;
        }
        printf("send ret: %d\n", ret);
        sleep(1);
    }


    //e. 关闭套接字
    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}





