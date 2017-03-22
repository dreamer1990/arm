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
#define SIZE 256
#define SIZE1 128

typedef struct _packet_t{
    int type;               //消息类型
    int len;                //buf中消息的长度
    unsigned char buf[SIZE1];         //消息缓冲区
    unsigned short crc;     //校验值
}packet_t;

int packet_parse(void *buf)
{
    unsigned short crc;

    packet_t *p = NULL;

    if (NULL == buf)
    {
        printf("The buf is empty...\n"); 
        goto err0;
    }

    p = (packet_t*)buf;

    crc = crc16(0x88, p->buf, p->len);
    if (crc == p->crc)
    {
        printf("消息类型: %d  消息长度: %d\n", p->type, p->len);
        printf("%s\n", p->buf);
    }
    else
        printf("校验失败....\n");

    printf("len: %d crc:%u crc2: %u\n", p->len, crc, p->crc);
    
    return 0;
err0:
    return -1;
}

//UDP服务器
int main(void)
{
    int ret = -1;
    int sockfd = -1; 
    unsigned char buf[SIZE];
    struct sockaddr_in sockaddr;
    struct sockaddr_in peeraddr;
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
       //收数据 默认是阻塞
        ret = recvfrom(sockfd, buf, SIZE, 0, (void *)&peeraddr, &len);
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

        printf("recvfrom ret: %d\n", ret);
        //解析包
        packet_parse(buf);        

    }


    //e. 关闭套接字
    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}





