#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>    
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <poll.h>
#include <unistd.h>

#define PORT 10086
#define SIZE 128


#define my_gets(buf, size) do{          \
    fgets(buf, size, stdin);            \
    if (buf[strlen(buf) - 1] == '\n')   \
    buf[strlen(buf) - 1] = '\0';    \
    else                                \
    while('\n' != getchar())        \
    /*do nothing*/;             \
}while(0)


//UDP服务器
int main(void)
{
    int ret = -1;
    int sockfd = -1; 
    int i = 0;
    int val = 0;
    char buf[SIZE];
    struct sockaddr_in sockaddr;
    struct sockaddr_in localaddr;
    socklen_t len = sizeof(struct sockaddr_in);

    struct pollfd fds[2];

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
    inet_pton(AF_INET, "2.2.2.255", &sockaddr.sin_addr); 
    bzero(&sockaddr.sin_zero, 1);

    //绑定本地端口
    localaddr.sin_family = AF_INET;
    localaddr.sin_port = htons(PORT);
    localaddr.sin_addr.s_addr = INADDR_ANY;
    bzero(&localaddr.sin_zero, 1);


    //c. 绑定
    ret = bind(sockfd, (struct sockaddr*)&localaddr, sizeof(localaddr));
    if (-1 == ret)
    {
        perror("bind"); 
        goto err1;
    }

    //如果没有以下设置  则出错返回 返回没有权限
    //非零表示使能 0表示禁止
    val = 1; 
    //SOL_SOCKET 基本套接字  SO_BROADCAST 是否允许发送广播 
    ret = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &val, sizeof(val));
    if (-1 == ret)
    {
        perror("setsockopt"); 
        goto err1;
    }


    //d. 收发数据
    while(1)
    {

        fds[0].fd = STDIN_FILENO;
        fds[0].events = POLLIN;

        fds[1].fd = sockfd;
        fds[1].events = POLLIN;
    

        //3秒超时
        ret = poll(fds, 2, 3000);
        if (-1 == ret)
        {
            perror("poll"); 
            break;
        }
        else if (0 == ret)
        {
            printf("3s timeout...\n"); 
        }
        else
        {
            if (fds[0].revents & POLLIN)        
            {
                my_gets(buf, SIZE);            
                //广播
                ret = sendto(sockfd, buf, strlen(buf), 0, (void*)&sockaddr, sizeof(sockaddr));
                if (ret <= 0)
                {
                    perror("sendto"); 
                    break;
                }

                printf("send ret: %d\n", ret);
            }

            if (fds[1].revents & POLLIN)
            {
                ret = recvfrom(sockfd, buf, SIZE, 0, NULL, NULL);        
                if (ret <= 0)
                {
                    perror("recvfrom"); 
                    break;
                }

                buf[ret] = 0;
                printf("buf: %s\n", buf);
            }
        }
    }


    //e. 关闭套接字
    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}





