#include <stdio.h>
#include <stdlib.h>

#define SIZE 20


//给数组中的元素随机赋值
void array_random(int *a, int n)
{
    int i = 0;

    //printf("len:  %d\n", sizeof(a) / sizeof(a[0]));

    for (i = 0; i < n; i++)
    {
        a[i] = random() % 100;    
    }

}

//显示数组中所有的元素
void array_show(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%2d  ", a[i]); 
    }
    putchar('\n');
}

//简单的索引  通过关键字查找索引
int find_index_by_key(int *a, int key, int n)
{
    int i = 0;
    //哨兵可以放在最开始的地方或者结尾的地方
    //a[n - 1]设置为哨兵
    a[n - 1] = key;

    //减少了每次都要判断i是否越界
    while(a[i] != key)
        i++;

    if (i == n - 1)
        goto err0;
    

    return i;
err0:
    return -1;
}


int main(void)
{
    int  a[SIZE];

    int n;

    printf("len:  %d\n", sizeof(a) / sizeof(a[0]));
    
        
    //设置随机种子
    srandom(time(NULL));

    array_random(a, SIZE);
    array_show(a, SIZE);

    printf("please input a number you want to search:  ");
    scanf("%d", &n);

    printf("find %d in %d\n", n, find_index_by_key(a, n, SIZE));

    


    return 0;
}
