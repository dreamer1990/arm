#include <stdio.h>

typedef int * int_p;

//编译阶段
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long long uint64;

//预处理
#define unsigned int uint32


int main(void)
{

    uint a;

    //p是int *类型   p1是int类型
    int *p, p1;

    //p2和p3都是int *类型
    int_p p2, p3; 


    return 0;
}
