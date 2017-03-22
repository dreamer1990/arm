#include <stdio.h>


//void * 万能型的指针,与任何类型的指针赋值兼容
//void ** 二级指针

int main(void)
{
    int a = 3;
    char ch = 'A';
    double d = 3.1415;
    long int l = 23456L;  //long l = 23456L;
    void *p = NULL;  //定义一个万能型的指针 p本身占用4个字节
    void **p2 = NULL;

    //int类型
    p = &a;
    printf("int *p = %d\n", *(int *)p);

    //char类型
    p = &ch;
    printf("char *p = %c\n", *(char *)p);

    //double类型
    p = &d;
    printf("double *p = %lf\n", *(double *)p);
    
    //long类型
    p = &l;
    printf("long *p = %ld\n", *(long*)p);

    p2 = &p;
    //p2 = (void **)&a;
    printf("int **p2 = %d\n", **(long **)p2);

    return 0;
}
