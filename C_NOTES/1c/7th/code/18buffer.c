#include <stdio.h>
#include <unistd.h>

int main(void)
{

    printf("hello world...");
    printf("hello world...");
    printf("hello world...");

    //刷新缓冲区
    //fflush(NULL); //刷新所有已经打开的输出流
    fflush(stdout); //刷新标准输出流

    while(1)
     ;

#if 0
    while(1)
    {
        printf("hello world");
        //1ms
        usleep(1000);
    }
#endif


    return 0;
}
