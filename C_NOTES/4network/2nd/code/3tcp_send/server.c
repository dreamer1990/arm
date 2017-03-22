#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 10087
#define SIZE 128

/*
 *
 *服务端:
 *    a. 创建一个套字
 *    b. 初始化结构体
 *    c. 绑定
 *    d. 监听 设置监听队列的大小
 *    e. 接受客户端的连接
 *    f. 读写操作
 *
 */

int main(void)
{

    int sockfd = 0;
    int newfd = 0;
    int ret = -1;
    int i = 0;
    char buf[SIZE];
    struct sockaddr_in sockaddr;
    struct sockaddr_in fromaddr;
    socklen_t len = sizeof(fromaddr);

    //a. 创建套接子
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
    //sockaddr.sin_addr.s_addr = inet_addr("172.16.1.201");
    //可以绑定系统所有的网络接口
    sockaddr.sin_addr.s_addr = INADDR_ANY;

    //绑定
    ret = bind(sockfd, (void*)&sockaddr, sizeof(sockaddr));
    if (-1 == ret)
    {
        perror("bind"); 
        goto err1;
    }

    //监听
    ret = listen(sockfd, 10);
    if (-1 == ret)
    {
        perror("listen"); 
        goto err1;
    }

    printf("server is waiting the client incomming....\n");

    //阻塞 接受客户端连接
    newfd = accept(sockfd, (void*)&fromaddr, &len);
    if (-1 == newfd)
    {
        perror("accept"); 
        goto err1;
    }
    //客户端的信息
    printf("from client  ip: %s port: %d\n", inet_ntoa(fromaddr.sin_addr), ntohs(fromaddr.sin_port));

    //读写操作
    while(1)
    {
        memset(buf, 0, SIZE);         
        sprintf(buf, "hello world %d", i++);
        //ret = write(newfd, "hello world", 11); 
        ret = send(newfd, buf, strlen(buf),  0);

        if (ret <= 0)
           break;
        printf("send  %d bytes\n", ret);
        sleep(1);
    }

    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
