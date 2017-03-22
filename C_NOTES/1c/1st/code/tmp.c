#include <stdio.h>

int main(void)
{

    // \n  行缓冲:  刷新缓冲区
    //printf("hello world\n");

    //printf("hello world");
    
    //fflush(stdout);
    int n = 0;
    while(1)
    {

        n++;
        printf("hello world n:  %d", n);    
        //sleep(1);
    }

    return 0;
}
