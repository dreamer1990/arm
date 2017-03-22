#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>    
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "crc.h"

#define PORT 10086
#define PORT1 10010
#define SIZE 128


typedef struct _packet_t{
    int type;               //消息类型
    int len;                //buf中消息的长度
    char buf[SIZE];         //消息缓冲区
    unsigned short crc;     //校验值
}packet_t;

int packet_create(int type, packet_t *p)
{
    int i = 0;
    int ret = 0;
    char buf[SIZE];
    if (NULL == p)
    {
        printf("The paremet p is NULL\n"); 
        goto err0;
    }

    memset(p, 0, sizeof(packet_t));

    p->type = i + 1;
    ret = sprintf(buf, "hello uplooking %d%d%d%d", random() % 100, random()%100, random() % 100, random() % 100);
    //消息的长度
    p->len = ret;
    //消息 
    memcpy(p->buf, buf, ret);
    p->crc = crc16(0x88, p->buf, p->len);

    printf("len: %d crc: %u\n", p->len, p->crc);
    return 0;
err0:
    return -1;
}

//UDP服务器
int main(void)
{
    int ret = -1;
    int sockfd = -1; 
    int i = 0;
    unsigned char buf[SIZE];
    struct sockaddr_in sockaddr;
    struct sockaddr_in localaddr;
    socklen_t len = sizeof(struct sockaddr_in);

    packet_t packet;

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
        
        packet_create(0, &packet);

        //udp 发送数据只能是sendto  不能是send
        //sendto不是阻塞  
        ret = sendto(sockfd, (void*)&packet, sizeof(packet), 0,(struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in));
        if (ret <= 0)
        {
            perror("sendto"); 
            goto err1;
        }

        printf("send ret: %d\n", ret);

        if (10 == i)
        {
            //发送一个空包  判断结束
            ret = sendto(sockfd, NULL, 0, 0, (void*)&sockaddr, sizeof(struct sockaddr_in));
            printf("send empty:  ret: %d\n", ret);
            break;
        }
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





