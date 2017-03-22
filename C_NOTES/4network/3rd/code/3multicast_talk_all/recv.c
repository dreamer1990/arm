#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <poll.h>

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
    struct sockaddr_in addr_to;
    struct ip_mreq req;

    struct pollfd fds[2];

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

    //初始化多播组结构体
    bzero(&addr_to, sizeof(addr_to));
    addr_to.sin_family = AF_INET;
    addr_to.sin_port = htons(PORT);
    addr_to.sin_addr.s_addr = inet_addr("224.0.0.88"); //多播组


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

    //d. 收发数据
    while(1)
    {

        fds[0].fd = STDIN_FILENO; 
        fds[0].events = POLLIN;

        fds[1].fd = sockfd;
        fds[1].events = POLLIN;

        memset(buf, 0, SIZE);
        memset(&peer, 0, sizeof(peer));

        ret = poll(fds, 2, 3000);
        if (-1 == ret)
        {
            perror("poll"); 
            break;
        }
        else if (0 == ret)
        {
            printf("3s time out....\n"); 
            continue;
        }
        else
        {

            if (fds[0].revents & POLLIN)
            {
                my_gets(buf, SIZE);            

                ret = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&addr_to, sizeof(addr_to));
                if (ret < 0)
                {
                    perror("sendto"); 
                    break;
                }

                printf("--------------------->sendto ret: %d\n", ret);
            }
            //表示网络有数据读
            if (fds[1].revents & POLLIN)
            {

                //接收数据 默认是阻塞
                ret = recvfrom(sockfd, buf, SIZE, 0, (struct sockaddr*)&peer, &len);
                if (ret < 0)
                {
                    perror("recvfrom"); 
                    break;
                }
                buf[ret] = '\0';
                printf("recvfrom %s:%d  ===>%s\n", inet_ntoa(peer.sin_addr), ntohs(peer.sin_port), buf);

            }
        }
    }


    //关闭套接字
    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
