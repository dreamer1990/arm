#include <stdio.h>

void dec2bin(int num)
{
    //递归结束的条件
    if (0 == num)
        return;  //空类型  结束该函数

    dec2bin(num / 2);
    //输出每一位的值
    printf("%d", num % 2);
}

int main(void)
{
    int num; 
    printf("please input a number:  \n");
    scanf("%d", &num);

    dec2bin(num);

    putchar('\n');


    return 0;
}
