#include <stdio.h>
/*
 *死循环有多种
 *第一种
 *while(1)
 *{
 *}
 *第二种 
 *do{
 *
 *}while(1);
 *第三种
 *for(;;)
 *{
 *}
 */

int main(void)
{
    int n;

        while(1)
        {
            printf("please input a number[-1 quit]:  ");   
            //用户从标准输入获取一个整形数字
            scanf("%d", &n);
            if (-1 == n)
                break;  //结束本层循环

            if (2 == n)
                continue; //结束本次循环 不执行循环中continue以下的语句
            printf("---> %d\n", n);
        }

    return 0;
}
