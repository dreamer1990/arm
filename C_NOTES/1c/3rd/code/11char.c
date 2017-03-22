#include <stdio.h>

int main(void)
{
    int i = 0;

    //定义字符数组 
    char a[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    //编译器根据初始化值自动计算数组的维数
    char b[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    char c[10] = {'A', 'B', 'C', 'D', 'E'};

    //sizeof a  计算字符数组a所占的空间
    printf("sizeof(a):  %d  sizeof(b):  %d\n", sizeof a, sizeof b);

    for (i = 0; i < 10; i++)
    {
        printf("%c", a[i]); 
    }
    putchar('\n');

    printf("============================\n");
    for (i = 0; i < 10; i++)
    {
        printf("%c", c[i]); 
    }
    putchar('\n');

    return 0;
}
