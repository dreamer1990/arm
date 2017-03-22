#include <stdio.h>


int main(void)
{
    int choice;
    printf("=========1. 乘飞机去北京=============\n");
    printf("=========2. 乘普通火车去北京=========\n");
    printf("=========3. 乘高铁去北京=============\n");
    printf("=========4. 乘动卧去北京=============\n");
    printf("=========5. 乘汽车去北京=============\n");
    printf("=========6. 没有选择正确的方式=======\n");

    printf("please make your choice...\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("你选择的方式是乘飞机\n");
            break;
        case 2:
            printf("你选择的方式是成普通火车\n");
            break;
        case 3:
            printf("你选择的方式是乘高铁\n");
            break;
        case 4:
            printf("你选择的方式是乘动卧\n");
            break;
        case 5:
            printf("你选择的方式是乘汽车\n");
            break;
        default:
            printf("请选择正确的方式...\n");
    }

    return 0;
}
