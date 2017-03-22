#include <stdio.h>

//先执行循环体，然后判断条件，如果条件为真，就执行循环体，否则退出循环.

/*
 *第二种方式
 *do{
 *   语句块 
 *}while(cond1);
 *
 */


int main(void)
{
    //循环计数器
    int i = 1;
    int sum = 0;  //累加和

    do 
    {
        //如果有多条语句 {}不能省略
        printf("hello uplooking...\n");
        ;
    }while(0);

    //求1 + 2 + 3 + ...+ 100
    do {
        sum = sum + i;
        i++;
    }while(i < 101); //如果i < 101则退出循环  后面的;不能省略

    printf("1+2+3+...+100 = %d\n", sum);

    return 0;
}



