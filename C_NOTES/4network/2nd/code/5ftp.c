#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define SIZE 128



int main(void)
{

    int sockfd = 0;
    int ret = -1;
    char buf[SIZE];
    struct sockaddr_in sockaddr;

    //a. 创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err0;
    }
    //b. 初始化结构体
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET; //ipv4
    sockaddr.sin_port = htons(PORT);
    sockaddr.sin_addr.s_addr = inet_addr("172.16.1.201");

    //c. 建立链接
    ret = connect(sockfd, (void *)&sockaddr, sizeof(sockaddr));
    if (-1 == ret)
    {
        perror("connect"); 
        goto err1;
    }
    //表示已经成功链接到服务器 但是还没有认证
    printf("connect ftp:172.16.1.201 successfully....\n");

    //发送用户名
    ret = send(sockfd, "USER root", 9, 0);
    if (ret <= 0)
        goto err1;

    ret = recv(sockfd, buf, SIZE, 0);
    if (ret <= 0)
        goto err1;
    buf[ret] = 0;
    printf("recv: %s\n", buf);

    //发送用户密码
    ret = send(sockfd, "PASS 123456", 11, 0);
    if (ret <= 0)
        goto err1;

    ret = recv(sockfd, buf, SIZE, 0);
    if (ret <= 0)
        goto err1;
    buf[ret] = 0;
    printf("recv: %s\n", buf);


    printf("log ftp successfully..\n");


    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
