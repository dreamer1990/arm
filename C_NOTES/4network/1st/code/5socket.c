#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(void)
{
    int sockfd; 

    //AF_INET ipv4
    //SOCK_STREAM  tcp
    //0 默认的协议
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket"); 
        goto err0;
    }
    //使用当前进程中没有使用的最小的文件描述符
    printf("sockfd: %d\n", sockfd);


    //关闭套接子 释放资源
    close(sockfd);
    return 0;
err0:
    return -1;
}
