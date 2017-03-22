#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(void)
{
    unsigned long a = 0x11223344; 
    unsigned short b = 0x1234;

    //以字节为单位
    //主机序转网络序 32位
    printf("htonl(%p): %p\n", a, htonl(a)); 

    //主机序转网络序 16位
    printf("htons(%p): %p\n", b, htons(b));

    //网络序转主机序  32位
    printf("ntohl(0x12345678): %p\n", ntohl(0x12345678));

    //网络序转主机序 16位
    printf("ntohs(0x1234): %p\n", ntohs(0x1234));
    return 0;
}
