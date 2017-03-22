#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


 in_addr_t inet_addr(const char *cp);


int main(void)
{
    unsigned long ip = 0;
    struct in_addr in;

    //将点分十进制格式的地址转换二进制 网络序
    ip = inet_addr("172.16.1.201");

    printf("%d %d %d %d\n", (ip)&0xff, (ip >> 8)&0xff, (ip >> 16)&0xff, (ip >> 24)&0xff);
    
    //int inet_aton(const char *cp, struct in_addr *inp);
    inet_aton("172.16.1.201", &in);
    ip = (unsigned long)in.s_addr; 
    printf("%d %d %d %d\n", (ip)&0xff, (ip >> 8)&0xff, (ip >> 16)&0xff, (ip >> 24)&0xff);
    
    //char *inet_ntoa(struct in_addr in);
    printf("ip: %s\n", inet_ntoa(in));

    return 0;
}
