#include <stdio.h>

/*
 *4. (5 _ 3) _ 2 = 4
 *    填写符号打印满足的表达式
 *    (+ - * / % ^(幂))
 *
 */

typedef int(*fun_t)(int, int);

struct op_t {
    fun_t f;  // add sub mul div mod my_pow
    char ch;  //+-*/%^
};

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}

int mod(int x, int y)
{
    return x % y;
}

int my_pow(int x, int y)
{
    int sum = 1;
    while(y--)
    {
        sum *= x;
    }

    return sum;
}

 //(5 _ 3) _ 2 = 4
int main(void)
{
    int i, j;
    struct op_t op[6] = {
    {add, '+'},
    {sub, '-'},
    {mul, '*'},
    {div, '/'},
    {mod, '%'},
    {my_pow, '^'},
    };

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++) 
        {
            if (4 == op[j].f(op[i].f(5, 3), 2)) 
            {
                printf("(5 %c 3) %c 2 = 4\n", op[i].ch, op[j].ch); 
            }
        }
    }
    
}
