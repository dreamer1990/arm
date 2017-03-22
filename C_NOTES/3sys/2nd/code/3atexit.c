#include <stdio.h>
#include <stdlib.h>


//int atexit(void (*function)(void));

void  test1(void)
{
    printf("=====test1==========\n");
}

void  test2(void)
{
    printf("=====test2==========\n");
}

void  test3(void)
{
    printf("=====test3==========\n");
}

int main(void)
{
    //atexit调用注册函数的顺序是与注册的顺序相反 先注册的函数 最后调用
    //atexit 用来登记终止处理函数
    if (atexit(test1) != 0)
    {
        perror("atexit1"); 
    }

    atexit(test2);
    //it is called once for each registration.
    //如果同一个函数被注册多次 那么也会被调用多次
    atexit(test3);
    atexit(test3);

    //while(1);


    return 0;
}
