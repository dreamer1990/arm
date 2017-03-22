#include <stdio.h>

int age(int n, int level)
{
    int tmp = 0;
    int i = 0;

    //输出不同递归层次的制表符
    for (i = 0; i < level; i++)
    {
        printf("\t"); 
    }
    printf("--->age(%d)\n", n);

    if (1 == n)
    {
        tmp = 10;
        return tmp;
    }


    tmp = age(n - 1, level + 1) + 2;

    //输出不同递归层次的制表符
    for (i = 0; i < level; i++)
    {
        printf("\t"); 
    }
    printf("<---age(%d)\n", n);

    
    return tmp; 
}

int main(void)
{

    printf("age(5): %d\n", age(5, 0));  
    return 0;
}
