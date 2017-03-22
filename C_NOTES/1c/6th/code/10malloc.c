#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //五级指针
    int *****p3 = NULL;
    
    p3 = malloc(sizeof(int ****));

    //*p3是int ****类型
    *p3 = malloc(sizeof(int ***));

    //**p3是 int***类型
    **p3 = malloc(sizeof(int**));

    ***p3 = malloc(sizeof(int *));

    ****p3 = malloc(sizeof(int));


    *****p3 = 88;

    printf("***p3 = %d\n", *****p3);

    return 0;
}
