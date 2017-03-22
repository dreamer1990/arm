#include <stdio.h>

int main(void)
{
    int i, j;

    int a[3][4] = {0};
    
    int *p = NULL;
    int (*p1)[4] = NULL;
    int **p2 = NULL;


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
    
    //行指针  + 1 相当于加 4 * sizeof(int)
    printf("a     = %p a + 1 = %p\n", a, a + 1);
    printf("a + 2 = %p a + 3 = %p\n", a + 2, a + 3);

    //列指针  + 1相当于加 sizeof(int)
    printf("a[0] + 0 = %p  a[0] + 1 = %p\n", a[0] + 0, a[0] + 1);
    printf("a[0] + 2 = %p  a[0] + 3 = %p\n", a[0] + 2, a[0] + 3);

    //列指针
    p = a[0];
    printf("p   = %p  p + 1 = %p\n", p, p + 1);
    printf("p + 2 = %p p + 3 = %p\n", p + 2, p + 3);

    //行指针
    p1 = a;
    printf("p1 = %p  p1 + 1 = %p\n", p1, p1 + 1);
    printf("p1 + 2 = %p  p1 + 3 = %p\n", p1 + 2, p1 + 3);

    //警告：从不兼容的指针类型赋值
    //p2 = a;
    p2 = (void*)a; //void *与任何指针类型赋值兼容 

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++) 
        {
            //将p2强制转换为数组指针类型
            *(*((int(*)[4])p2 + i) + j) = 100;
        }
    }

    for (p = a[0]; p - a[0] < 12; p++)
    {
        printf("%d  ", *p); 
    }
    putchar('\n');

    


    return 0;
}
