#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int i = 0;
    //定义一个3行4列的二维数组
    int a[3][4] = {0};

    //在这种场合下的行指针
    //类型是 int(*)[4]
    //指向的是int[4]
    int (*p)[4] = NULL;

    p = a;

    //行指针
    // a    代表整个数组的首地址
    // a + 1代表第2行的首地址
    // a + 2代表第3行的首地址
    // a + i代表第i + 1行的首地址

    //列指针
    //a[0] + 0  代表a[0][0]的地址
    //a[0] + 1  代表a[0][1]的地址
    //a[0] + 2  代表a[0][2]的地址
    //a[0] + 3  代表a[0][3]的地址
    //a[i] + j  代表a[i][j]的地址
    
    //&a    数值上与a相等
    //&a + 1数值上等于a + sizeof(a) 指向这个数组的最后一个元素的下一个位置

    //p 是行指针  p = a;
    //*p 等价于 a[0] 或者 *a;
    //**p 等价于 a[0][0]  或者**a;
    //*(p + i) 等价于a[i] 或者*(a + i)
    //*(*(p + i) + j) 等价于a[i][j]  或者*(*(a + i) + j)
    
    srandom(time(NULL));
    //控制行
    for (p = a; p - a < 3; p++)
    {
        //控制列
        for (i = 0; i < 4; i++)
        {
            //随机赋值
            *((*p) + i) = random() % 100;
        }
    }
    

    //使p指向该二维数组的首地址
    for (p = a; p - a < 3; p++)
    {
        for (i = 0; i < 4; i++) 
        {
            printf("%2d  ", *((*p) + i)); 
        }
        putchar('\n');
    }



    return 0;
}
