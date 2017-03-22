#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_random(int *p, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        *(p + i)  = random() % 101;
    }
}

void array_show(int *p, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%2d  ", *(p + i)); 
    }

    putchar('\n');
}

int *test(int size)
{
    int *new = NULL;
    new = malloc(size);
    if (NULL == new)
        goto err0;

    memset(new, 0, size);

    return new;
err0:
    return NULL;
}


int main(void)
{
    int *p = NULL;

    p = test(4 * sizeof(int));
    if (NULL == p)
    {
        printf("test failed...\n"); 
        goto err0;
    }

    array_random(p, 4);
    array_show(p, 4);


    //谁分配谁释放
    free(p);

    return 0;
err0:
    return -1;
}
