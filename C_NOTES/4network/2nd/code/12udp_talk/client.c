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
#define PORT1 10010
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
    inet_pton(AF_INET, "172.16.1.201", &sockaddr.sin_addr); 
    bzero(&sockaddr.sin_zero, 1);



    //初始化本地的sockaddr
    localaddr.sin_family = AF_INET;
    localaddr.sin_port = htons(PORT1);
    localaddr.sin_addr.s_addr = INADDR_ANY;
    bzero(localaddr.sin_zero, 1);


    //c. 绑定
    ret = bind(sockfd, (struct sockaddr*)&localaddr, sizeof(localaddr));
    if (-1 == ret)
    {
        perror("bind"); 
        goto err1;
    }


    //d. 收发数据
    while(1)
    {
        fds[0].fd = STDIN_FILENO;
        //表示有数据读；
        fds[0].events = POLLIN;

        //监听套接字
        fds[1].fd = sockfd;
        fds[1].events = POLLIN;
        //3秒超时 
        ret = poll(fds, 2, 3000);
        if (ret < 0) 
        {
            perror("poll"); 
            break;
        }
        else if (0 == ret)
        {
            printf("3s time out....\n"); 
        }
        else
        {
            //标准输入有数据
            if (fds[0].revents & POLLIN)        
            {
                my_gets(buf, SIZE); 
                if (strncmp(buf, "exit", 4) == 0)
                {
                    //发送空包 然后退出 
                    ret = sendto(sockfd, NULL, 0, 0, (void*)&sockaddr, len);
                    printf("server send:  %d\n", ret);
                    break;
                }
                //发送出去
                ret = sendto(sockfd, buf, strlen(buf), 0, (void*)&sockaddr, len);
                if (ret <= 0)
                {
                    perror("sendto"); 
                    break;
                }
                printf("server send: %d\n", ret);
            }

            //从套接字接收数据
            if (fds[1].revents & POLLIN)
            {

                memset(buf, 0, SIZE); 
                //收数据 默认是阻塞
                ret = recvfrom(sockfd, buf, SIZE, 0, (void *)&sockaddr, &len);
                if (ret < 0)
                {
                    perror("recvfrom"); 
                    goto err1;
                }
                //收到空包  退出循环
                if (ret == 0)
                {
                    printf("recv an empty packet....\n"); 
                    break;
                }
                buf[ret] = '\0';
                printf("peer ip: %s port: %d\n", inet_ntoa(sockaddr.sin_addr), ntohs(sockaddr.sin_port));
                printf("recv ===>ret: %d buf: %s\n", ret, buf);
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





