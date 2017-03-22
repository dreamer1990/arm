#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    int guess;

    srandom(time(NULL)); //设置随机种子
    guess = random() % 101; //获取随机数
    while(1)
    {
        printf("please input a number:   \n"); 
        scanf("%d", &num);
        if (num == guess)
        {
            printf("恭喜你  你已经猜中了..\n");
            break; //退出本层循环
        }
        else if (num > guess)
        {
            printf("太大了，请重试\n"); 
        }
        else
        {
            printf("太小了，请重试\n"); 
        }
    }

    return 0;
}
