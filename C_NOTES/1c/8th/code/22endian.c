#include <stdio.h>

//测试机器大小端问题
//小端模式: 数据的高位放在高地址上, 数据的低位放在低地址上 高对高 低对低
//大端模式: 数据的高位放在低地址上, 数据的低位放在高地址上 高对低 低对高
union data_t {
    int a;
    char b;
};

int main(void)
{

    union data_t t;
    t.a = 0xf;
    
    if (t.a == t.b)
    {
        printf("目前的机器是小端模式...\n"); 
    }
    else
    {
        printf("目前的机器是大端模式....\n"); 
    }


    return 0;
}
