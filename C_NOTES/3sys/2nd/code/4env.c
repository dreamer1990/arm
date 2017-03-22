#include <stdio.h>


//全局变量
extern char **environ;


//int main(void)
int main(int argc, char **argv, char*e[])
{
    int i = 0;

    //环境变量的最后一个以NULL结尾
    while(NULL != environ[i])
    {
        printf("%s\n", environ[i]); 
        i++;
    }

    printf("======================\n");
    i = 0;
    while(NULL != e[i])
    {
        printf("%s\n", e[i]); 
        i++;
    }

    return 0;
}
