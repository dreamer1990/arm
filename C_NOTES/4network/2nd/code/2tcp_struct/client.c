#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "cJSON.h"

#define PORT 10086
#define SIZE 1024

/*
 *
 *客户端:
 *    a. 创建一个套接子
 *    b. 初始化结构体
 *    e. 链接服务器
 *    f. 读写操作
 *
 */


typedef struct _packet_t{
    int type;       //消息类型
    int len;        //消息长度 不包含头部
    char buf[SIZE]; //消息正文
}packet_t;


int packet_parse(void  *buf)
{
    cJSON *root = NULL;
    char *s = NULL;

    if (NULL == buf)
        goto err0;

    packet_t *p = (packet_t*)buf;

    printf("包的类型为: %d  数据的长度为: %d\n", p->type, p->len);

    //解析json
    root = cJSON_Parse(p->buf);
    s = cJSON_Print(root);
    //销毁json对象
    cJSON_Delete(root);
    printf("%s\n", s);

    //释放s的空间
    free(s);
   
    return 0;
err0:
    return -1;
}

int main(void)
{

    int sockfd = 0;
    int newfd = 0;
    int ret = -1;
    char buf[SIZE];
    char *str = NULL;
    struct sockaddr_in sockaddr;
    socklen_t len = sizeof(sockaddr);

    //a. 创建套接子
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

    //读写操作
    while(1)
    {
        memset(buf, 0, SIZE);         
        //ret = read(sockfd, buf, SIZE);
        ret = recv(sockfd, buf, SIZE, 0);
        if (ret <= 0)
            break;

        packet_parse(buf);
    }

    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
