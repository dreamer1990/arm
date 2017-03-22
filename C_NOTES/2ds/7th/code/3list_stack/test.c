
#include "stack.h"

#define MAX 10

typedef struct _s_t{
    int i;
    int j;
    char name[32];
}s_t;

int main(void)
{
    stack_t *t = NULL;
    int i = 0;
    
    s_t s = {0};


    //设置随机种子
    srandom(time(NULL));

    //创建栈的头信息结构体
    t = stack_create(sizeof(s_t), NULL);
    if (NULL == t)
    {
        goto err0;
    }

    //进栈
    for (i = 0; i < 10; i++)
    {
        s.i = i + 1;
        s.j = random() % 100;
        sprintf(s.name, "%c%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                            'a' + random() % 26, 'a' + random() % 26,
                                            'A' + random() % 26, 'a' + random() % 26,
                                            'a' + random() % 26, 'a' + random() % 26);

        printf("i:  %2d  j: %2d name:  %s\n", s.i, s.j, s.name);
        stack_push(t, &s);
    }

    printf("========================================\n");

    //出栈
    while(!stack_is_empty(t))
    {
        memset(&s, 0, sizeof(s_t)); 
        stack_pop(t, &s); 
        printf("i:  %2d  j:  %2d  name:  %s\n", s.i, s.j, s.name);
    }

    stack_destroy(t);

    return 0;
err0:
    return - 1;
}
