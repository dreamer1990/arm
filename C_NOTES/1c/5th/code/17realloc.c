#include <stdio.h>
#include <stdlib.h>


int main(void)
{

    int *p = NULL;
    int *p1 = NULL;

    p = malloc(4 * sizeof(int));
    if (NULL == p)
    {
        printf("malloc failed..\n"); 
        goto err0;
    }

    printf("p = %p\n", p);

    //会free掉p
    p1 = realloc(p, 10 * sizeof(int));
    if (NULL == p)
    {
        printf("realloc failed..\n");
        goto err0;
    }

    printf("p1 = %p\n", p1);


    free(p1);

    return 0;
err0:
    return -1;
}
