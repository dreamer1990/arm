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
    char buf[SIZE];
    struct sockaddr_in sockaddr;
    struct sockaddr_in peeraddr;
    socklen_t len = sizeof(struct sockaddr_in);

    //都是16个字节
    printf("sizeof(struct sockaddr): %d sizeof(struct sockaddr_in): %d\n", sizeof(struct sockaddr), sizeof(struct sockaddr_in));

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
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    bzero(&sockaddr.sin_zero, 1);

    //c. 绑定
    ret = bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr));
    if (-1 == ret)
    {
        perror("bind"); 
        goto err1;
    }

    printf("wait for client sending data....\n");

    //d. 收发数据
    while(1)
    {
        memset(buf, 0, SIZE); 
        bzero(&peeraddr, 0);

        //并不是真正提取数据  查看下一个要读取的数据
        ret = recvfrom(sockfd, buf, SIZE, MSG_PEEK, (void *)&peeraddr, &len);
        if (ret <= 0)
        {
            perror("recvfrom"); 
            goto err1;
        }

        buf[ret] = '\0';
        printf("peek===>peer ip: %s port: %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        printf("peek===>recv ===>ret: %d buf: %s\n", ret, buf);


        //收数据 默认是阻塞 如果包的实际长度大于SIZE 则默认截短
        //ret = recvfrom(sockfd, buf, SIZE, MSG_TRUNC, (void *)&peeraddr, &len);
        //非阻塞
        ret = recvfrom(sockfd, buf, SIZE, MSG_DONTWAIT, (void *)&peeraddr, &len);
        if (ret <= 0)
        {
            perror("recvfrom"); 
            goto err1;
        }

        buf[ret] = '\0';
        printf("peer ip: %s port: %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        printf("recv ===>ret: %d buf: %s\n", ret, buf);
    }


    //e. 关闭套接字
    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}





