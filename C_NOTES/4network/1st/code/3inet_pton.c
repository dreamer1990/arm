#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>


#define INET_ADDRSTRLEN 16
#define INET6_ADDRSTRLEN 46

int main(void)
{
    unsigned char a[4] = {0};
    char buf[16] = {0};

    //将点分十进制转为二进制
    inet_pton(AF_INET, "172.16.1.201", a);

    //&a[0]是低地址  &a[4]是高地址
    printf("%d  %d  %d  %d\n", a[0], a[1], a[2], a[3]);

    //将二进制转换为点分十进制
    inet_ntop(AF_INET, a, buf, INET_ADDRSTRLEN); 
    printf("buf: %s\n", buf);

    return 0;
}
