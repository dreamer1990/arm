#include <stdio.h>


/*
 *实际上，在某些情况下，main函数可以有参数，例如：
 *     int main(int argc,char *argv[])
 *   其中，argc和argv就是main函数的形参，它们是程序的“命令行参数”。
 *argv是*char指针数组，数组中每一个元素(其值为指针)指向命令行中的一个字符串。
 *
 */

//不推荐int main()
//int main()
//int main(void)
//int main(int argc, char *argv[]) 
//int main(int argc, char **argv)
int main(int argc, char *argv[], char *env[])
{
    int i = 0;

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]); 
    }

    return 0;
}
