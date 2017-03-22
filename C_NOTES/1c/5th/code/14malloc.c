#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//随机赋值
void array_random(int *p, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        *(p + i) = random() % 101;
    }
}

//遍历
void array_show(int *p, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("%2d  ", *(p + i)); 
    }

    putchar('\n');
}

int main(void)
{
    int *p = NULL;
    int *p1 = NULL;

    //分配10个int类型的空间  40个字节
    p = malloc(10 * sizeof(int));
    if (NULL == p)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }
    printf("p = %p\n", p);

    memset(p, 0, 10 * sizeof(int));

    srandom(time(NULL));
    array_random(p, 10);
    array_show(p, 10);
    free(p);

    p1 = malloc(10 * sizeof(int));
    if (NULL == p1)
    {
        printf("malloc failed...\n");
        goto err0;
    }

    printf("p1 = %p\n", p1);

    array_show(p1, 10);

    free(p1);




    return 0;
err0:
    return -1;
}
