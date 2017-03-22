#include <stdio.h>


/*
 *5. 100元买100只鸡, 公鸡5元一只, 母鸡3元一只,
 *   小鸡一元3只, 请输出所有的组合.
 */

int main(void)
{
    int cook, hens, chicken;

    //地一种方法
    //公鸡数
    for (cook = 0; cook < 100 / 5; cook++)
    {
        //母鸡数量
        for (hens = 0; hens < 100 / 3; hens++)
        {
            //小鸡数 并且小鸡是3的倍数
            for (chicken = 0; chicken < 100; chicken++)
            {
                // 100只鸡  100元
                if (chicken % 3 == 0 &&cook + hens + chicken == 100 && (cook * 5 + hens * 3 + chicken / 3) == 100) 
            
                printf("cook: %d hens: %d chicken:  %d\n", cook, hens, chicken);
            }
        }
    }

    printf("========================\n");

    //公鸡数
    for (cook = 0; cook < 100 /5; cook++)
    {
        //母鸡数 
        for (hens = 0; hens <= 100 / 3; hens++)
        {
            //小鸡数 100 - cook - hens 
            if ((100 - cook - hens) % 3 == 0 && cook * 5 + hens * 3 + (100 - cook - hens) / 3 == 100)
            {
                printf("cook: %d  hens: %d chicken: %d\n", cook, hens, 100 - cook - hens); 
            }
        }
    }

    return 0;
}

