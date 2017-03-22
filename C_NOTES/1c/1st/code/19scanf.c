#include <stdio.h>


//int scanf(const char *format, ...);

int main(void)
{
    int n = 0;
    int ret = 0;
    
#if 0
    scanf("%d", &n);
    printf("n = %d\n", n);

    //清空输入缓冲区 
    while(getchar() != '\n')
       ;
    //fflush(NULL);
    //scanf("%d", &n);
    ret = scanf("a = %d", &n);
    if (ret <= 0)
    {
        printf("get a number failed..\n"); 
    }
    printf("n = %d\n", n);
#endif

    while(1)
    {
        printf("please input a number[-1 quit]:  ");
        scanf("%d", &n);
        if (-1 == n)
            break;

        printf("n = %d\n", n);
    }

    return 0;
}
