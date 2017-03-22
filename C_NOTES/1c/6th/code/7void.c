#include <stdio.h>

int main(void)
{
    //void *是万能指针
    void *p = NULL;
    int *p1 = NULL;

    char *p2 = (char *)0x10;
    double *p3 = (double*)0x10;

    int a[10];

    //除了void* 之外,所有的都是加sizeof(类型)
    //void *p  p + 1 只加1
    //int  *p1 p1 + 1 加sizoef(int)
    //char *p2  p2 +  1 加sizeof(char)
    //double *p3  p3 + 1 加sizeof(double)

    p = a;
    p1 = a;

    //void *类型
    printf("void* p = %p  p + 1 = %p\n", p, p + 1);
    printf("void* p + 2 = %p  p + 3 = %p\n", p + 2, p + 3);
    //int *类型
    printf("int* p1 = %p  p1 + 1 = %p\n", p1, p1 + 1);
    printf("int* p1 + 2 = %p  p1 + 3 = %p\n", p1 + 2, p1 + 3);

    //char*类型
    printf("char* p2 = %p  p2 + 1 = %p\n", p2, p2 + 1);

    //double*类型
    printf("double*  p3 = %p  p3 + 1 = %p\n", p3, p3 + 1);


    return 0;
}
