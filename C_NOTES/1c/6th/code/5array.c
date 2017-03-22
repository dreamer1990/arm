#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//int (*p)[4]  p相当于行指针, p是指向一个有4个元素的数组的首地址
//p + 1 就是走一行
void array_random(int(*p)[4], int n)
{
    int i = 0;
    int j = 0;

    //控制行
    for (i = 0; i < n; i++)
    {
        //控制列
        for (j = 0; j < 4; j++) 
        {
            *(*(p + i) + j) = random() % 100; //等价于p[i][j] = random() % 100;
        }
    }
}

// *(*(p + i) + j)
// p是行指针   p + i也是行指针, 指向第i行, 相当于a + i
// *(p + i)是列指针 指向第i行的首地址 相当于a[i]
// *(p + i) + j也是列指针, 指向第i行第j列元素的地址,相等于&a[i][j]
// *(*(p + i) + j)就是0级指针, 就是区第i行第j列的值 相当于p[i][j]
void array_show(int (*p)[4], int n)
{
    int i, j;
    //控制行
    for (i = 0; i < n; i++)
    {
        //控制列
        for (j = 0; j < 4; j++) 
        {
            printf("%2d ", *(*(p + i) + j)); 
        }
        putchar('\n');
    }

}

int main(void)
{
    int a[3][4];

    srandom(time(NULL));

    array_random(a, 3);
    array_show(a, 3);

    return 0;
}
