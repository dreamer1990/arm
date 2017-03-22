#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "cJSON.h"

#define PORT 10086
#define SIZE 256

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

typedef struct _packet_t{
    int type;       //消息类型
    int len;        //消息长度 不包含头部
    char buf[SIZE]; //消息正文
}packet_t;


//创建Json包
int packet_create(int type, packet_t *packet)
{
    cJSON *root, *tmp;
    char *str = NULL;

    if (NULL == packet)
        goto err0;

    memset(packet, 0, sizeof(*packet));

    packet->type = type;

    //创建cJSON对象  分配空间
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "name", cJSON_CreateString("Uplooking ShenZhen"));
    cJSON_AddItemToObject(root, "format", tmp = cJSON_CreateObject());
    cJSON_AddItemToObject(tmp, "type", cJSON_CreateString("rect"));
    cJSON_AddItemToObject(tmp, "width", cJSON_CreateNumber(1920));
    cJSON_AddNumberToObject(tmp, "height", 1080);
    cJSON_AddBoolToObject(tmp, "interlace", 0);
    cJSON_AddNumberToObject(tmp, "frame rate", 24);
    str = cJSON_PrintUnformatted(root);
    //填充消息
    memcpy(packet->buf, str, strlen(str));
    packet->len = strlen(str);
    //销毁cjson对象
    cJSON_Delete(root);
    //释放str空间
    free(str);

    return 0;
err0:
    return -1;
}

int main(void)
{

    int sockfd = 0;
    int newfd = 0;
    int ret = -1;
    struct sockaddr_in sockaddr;
    struct sockaddr_in fromaddr;
    socklen_t len = sizeof(fromaddr);
    packet_t packet;

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
    sockaddr.sin_addr.s_addr = inet_addr("172.16.1.201");

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
        packet_create(0x88, &packet);

        ret = send(newfd, (void*)&packet, sizeof(packet), 0);        
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
