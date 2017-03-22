#include <stdio.h>

int main(void)
{
    int a = 0xAABBCCDD;

    unsigned int u = (unsigned int)&a;

    //小端模式: 高位在高地址  低位在低地址
    //大端模式: 高位在低地址  低位在高地址(网络)
    //我们这个机器是小端模式
    printf("%#x %#x %#x %#x\n", *(char *)u & 0xff, *(char *)(u + 1) & 0xff, *(char *)(u + 2) & 0xff, *(char*)(u + 3) & 0xff);



    return 0;
}
