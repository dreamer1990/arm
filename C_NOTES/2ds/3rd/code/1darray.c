#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    //int
    int n;
    int i;
    int *p = NULL;
    int *new = NULL;
    int count = 0;

    while(1)
    {
        // -1退出 
        printf("please input a number[-1 quit]:  \n");
        
        scanf("%d", &n);

        //退出循环的条件
        if (-1 == n)
            break; 

        new = malloc((count + 1) * sizeof(int));
        if (NULL == new)
        {
            printf("malloc failed..\n"); 
            goto err0;
        }

        //将原来的数据拷贝到新的空间中
        memcpy(new, p, count * sizeof(int));
        //free原来的
        if (NULL != p)
            free(p);
        p = new;
        *(p + count) = n;
        count++;
    }

    //遍历
    for (i = 0; i < count; i++)
    {
        printf("%d ", *(p + i)); 
    }
    putchar('\n');

    
    free(p);

    return 0;
err0:
    if (NULL != p)
        free(p);
    return -1;
}
