#include <stdio.h>

//argc参数的个数
//argv是指针数组 
//int main(int argc, char **argv)
int main(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++)
    {
        //*(argv + i)和argv[i]等价
        //printf("argv[%d] = %s\n", i, *(argv + i)); 
        printf("argv[%d] = %s\n", i, argv[i]); 
    }

    return 0;
}
