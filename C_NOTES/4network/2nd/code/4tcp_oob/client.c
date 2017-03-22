#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <fcntl.h>


#define PORT 10087
#define SIZE 128


int sockfd = 0;

/*
 *
 *客户端:
 *    a. 创建一个套接子
 *    b. 初始化结构体
 *    e. 链接服务器
 *    f. 读写操作
 *
 */
//带外数据只支持一个字符 如果超过一个字符 那么最后一个字符就是紧急数据
void recv_oob(int signu)
{
    int ret = 0;
    char buf[32];
    if (SIGURG != signu) 
        return ;

    //接收带外数据
    ret = recv(sockfd, buf, 32, MSG_OOB);
    buf[ret] = 0;
    printf("recv oob: %s\n", buf);
}

int main(void)
{

    int ret = -1;
    char buf[SIZE];
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

    //设置套接字支持收到紧急信号 SIGURG
    ret = fcntl(sockfd, F_SETOWN, getpid());
    if (-1 == ret)
    {
        perror("fcntl"); 
        goto err1;
    }
    
    signal(SIGURG, recv_oob);
    //读写操作
    while(1)
    {
        memset(buf, 0, SIZE);         
        //ret = read(sockfd, buf, SIZE);
        //recv默认是阻塞的
        //MSG_DONTWAIT 是不阻塞标志
        //MSG_WAITALL 阻塞所有的 收到信号之后才会接收数据
        //ret = recv(sockfd, buf, SIZE, MSG_DONTWAIT);
        //ret = recv(sockfd, buf, SIZE, MSG_WAITALL);
/*
 *        ret = recv(sockfd, buf, SIZE, MSG_PEEK);
 *        if (ret <= 0)
 *            break;
 *
 *        printf("peek server: %s\n", buf);
 *
 */
        ret = recv(sockfd, buf, SIZE, 0);
        buf[ret] = 0;
        printf("from server: %s\n", buf);

    }

    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
