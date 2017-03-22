#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 10086
#define SIZE 128


//route add -net 224.0.0.88 netmask 255.255.255.255 eth0

#if 0
/* IPv4 multicast request.  */
struct ip_mreq
{
    /* IP multicast address of group.  */
    struct in_addr imr_multiaddr; //相当于QQ群

    /* Local IP address of interface.  */
    struct in_addr imr_interface; //相当于QQ群中成员
};
#endif


//接收端
int main(void)
{

    int sockfd;
    int i = 0;
    int ret = -1;
    char buf[SIZE];
    struct sockaddr_in addr;
    struct sockaddr_in peer;
    struct ip_mreq req;
    socklen_t len = sizeof(peer);


    //a. 创建套接字
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err0;
    }

    //b. 初始化结构体
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    //c. 绑定
    ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)); 
    if (-1 == ret)
    {
        perror("bind"); 
        goto err1;
    }

    //d. 加入组播组
    req.imr_multiaddr.s_addr = inet_addr("224.0.0.88");
    req.imr_interface.s_addr = INADDR_ANY;
    //加入多播组
    ret = setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &req, sizeof(req));
    if (-1 == ret)
    {
        perror("setsockopt"); 
        goto err0;
    }

    //d. 收数据
    while(1)
    {
        memset(buf, 0, SIZE);
        memset(&peer, 0, sizeof(peer));

        //接收数据 默认是阻塞
        ret = recvfrom(sockfd, buf, SIZE, 0, (struct sockaddr*)&peer, &len);
        if (ret <= 0)
        {
            perror("recvfrom"); 
            break;
        }

        buf[ret] = '\0';
        printf("recvfrom %s:%d  ===>%s\n", inet_ntoa(peer.sin_addr), ntohs(peer.sin_port), buf);
        i++;
        //退出循环
        if (20 == i)
            break;

    }

    //退出多播组  IP_DROP_MEMBERSHIP
    ret = setsockopt(sockfd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &req, sizeof(req));
    if (-1 == ret)
    {
        perror("setsockopt"); 
        goto err0;
    }

    //e. 收数据
    while(1)
    {
        memset(buf, 0, SIZE);
        memset(&peer, 0, sizeof(peer));

        //接收数据 默认是阻塞
        ret = recvfrom(sockfd, buf, SIZE, 0, (struct sockaddr*)&peer, &len);
        if (ret <= 0)
        {
            perror("recvfrom"); 
            break;
        }

        buf[ret] = '\0';
        printf("recvfrom %s:%d  ===>%s\n", inet_ntoa(peer.sin_addr), ntohs(peer.sin_port), buf);
        i++;
        //退出循环
        if (20 == i)
            break;

    }



    //关闭套接字
    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
