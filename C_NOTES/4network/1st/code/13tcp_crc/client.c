#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "crc.h"

#define PORT 10086
#define SIZE 128


#define my_gets(buf, size) do{          \
    fgets(buf, SIZE, stdin);            \
    if (buf[strlen(buf) - 1] == '\n')   \
    buf[strlen(buf) - 1] = '\0';    \
    else                                \
    while('\n' != getchar())        \
    ;                           \
}while(0)


/*
 *
 *客户端:
 *    a. 创建一个套接子
 *    b. 初始化结构体
 *    e. 链接服务器
 *    f. 读写操作
 *
 */

int main(void)
{

    int sockfd = 0;
    int newfd = 0;
    int ret = -1;
    unsigned char buf[SIZE];
    struct sockaddr_in sockaddr;
    socklen_t len = sizeof(sockaddr);
    unsigned short crc;

    int fd_max;
    fd_set readfds;
    struct timeval tmo;

    //a. 创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err0;
    }
    //b. 初始化结构体 使用服务器相关信息
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET; //ipv4
    sockaddr.sin_port = htons(PORT);
    sockaddr.sin_addr.s_addr = inet_addr("172.16.1.201");

    //c. 连接服务器
    ret = connect(sockfd, (void*)&sockaddr, len);
    if (-1 == ret)
    {
        perror("connect"); 
        goto err1;
    }

    printf("connect to server successfully....\n");
    fd_max = sockfd > STDIN_FILENO ? sockfd + 1 : STDIN_FILENO + 1;

    //读写操作
    while(1)
    {

        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        FD_SET(STDIN_FILENO, &readfds);

        tmo.tv_sec = 3;
        tmo.tv_usec = 0;

        ret = select(fd_max, &readfds, NULL, NULL, &tmo);
        if (ret < 0)
        {
            perror("select"); 
            goto err0;
        }
        else if (0 == ret)
        {
            printf("timeout 3s\n"); 
        }
        else
        {
            if (FD_ISSET(sockfd, &readfds)) 
            {
                memset(buf, 0, SIZE);         
                //以下几种形式等价
                //ret = read(sockfd, buf, SIZE);
                //ret = recv(sockfd, buf, SIZE, 0);
                ret = recvfrom(sockfd, buf, SIZE, 0, NULL, NULL);
                if (ret <= 0)
                    break;

                len = ret;
                crc = crc16(0x88, buf, len - 2);

                if (crc == (buf[len - 2]  << 8) | buf[len - 1] )
                {
                    buf[ret - 2] = 0;
                    printf("from server: %s\n", buf);
                }
                else
                    printf("校验失败....\n");

            }

            if (FD_ISSET(STDIN_FILENO, &readfds))
            {
                //先写
                memset(buf, 0, SIZE);         
                my_gets(buf, SIZE);
                //以下几种形式等价
                //ret = write(sockfd, buf, strlen(buf)); 
                //ret = send(sockfd, buf, strlen(buf), 0);
                //添加校验
                len = strlen(buf);
                crc = crc16(0x88, buf, strlen(buf));
                printf("===========>len %d  %p  %p\n", len, crc >> 8, crc & 0xff);
                //先发送高位 在发送低位
                buf[len] = (crc >> 8) & 0xff;
                buf[len + 1] = crc & 0xff;
                ret = sendto(sockfd, buf, len + 2, 0, NULL, 0);
                if (ret <= 0)
                    break;
                printf("send  %d bytes\n", ret);


            }
        }

    }

    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
