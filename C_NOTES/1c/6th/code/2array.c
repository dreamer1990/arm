#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    //定义一个3行4列的二维数组
    int a[3][4] = {0};
    //在这里相当于列指针
    int *p = NULL;

    p = a[0];

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
    
    p = a[0];
    srandom(time(NULL));
    for (; p - a[0] < 12; p++)
    {
        //随机赋值
        *p = random() % 101; 
    }
    

    //使p指向该二维数组的首地址
    p = a[0];
    for (; p - a[0] < 12; p++)
    {
        if ((p - a[0]) % 4 == 0 && p != a[0])
            putchar('\n');
        printf("%3d  ", *p); 
    }
    putchar('\n');



    return 0;
}
