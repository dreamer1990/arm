#include <stdio.h>

/*3. 封装函数递归实现任意进制的输出*/

//n代表一个数  r代表进制
void fun(int n, int r)
{
    if (0 == n) 
    {
        if (2 == r)
            printf("");
        else if (8 == r)
            printf("0");
        else if (16 == r)
            printf("0x");
        else
           /*do nothing*/ ;

        return; //结束函数
    }
    
    //以下两个语句的顺序不能颠倒
    fun(n / r, r);
    if (n % r < 10)
        printf("%d", n % r);
    else
        printf("%c", n % r - 10 + 'A');
}


int main(void)
{

    printf("%#x\n", 255);
    printf("%#o\n", 255);
    fun(255, 16);
    putchar('\n');

    fun(255, 8);
    putchar('\n');
    return 0;
}

