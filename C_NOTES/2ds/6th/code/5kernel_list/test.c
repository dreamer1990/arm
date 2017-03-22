#include "kernel_list.h"

#define my_scanf(op,format, ...)    do {        \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)


typedef struct _stu_t{
    int id;
    char sex;
    char name[32];

    struct list_head l;
    
}stu_t;

//回调函数实现遍历
void my_print(void *data)
{
    stu_t *tmp = NULL;

    tmp = container_of(data, stu_t, l);
    printf("id:   %d  sex:  %c  name:  %s\n", tmp->id, tmp->sex, tmp->name);
}

void my_destroy(void *data)
{
    stu_t *tmp = NULL;

    tmp = container_of(data, stu_t, l);

    free(tmp);
    tmp = NULL;
}


int main(void)
{
    int n = 0;

    stu_t *s = NULL;

    //头结点初始化 不放任何数据
    struct list_head head = {&head, &head};

    while(1)
    {
    retry:
        printf("please input a number[ -1 quit]:     ");
        my_scanf(goto retry, "%d", &n);

        //结束循环
        if (-1 == n)
            break;

        //分配空间
        s = malloc(sizeof(stu_t));
        if (NULL == s)
        {
            printf("malloc failed...\n");
            goto err0;
        }

        s->id = n;
        s->sex = "MF"[random() % 2];

        //name随机赋值
        sprintf(s->name, "%c%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26,
                                              'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26);

        //尾插
        //list_append(&head, &s->l); 
        //头插
        //list_prepend(&head, &s->l);
        //头插
        list_prepend_v1(&head, &s->l);
    }

    list_traverse(&head, my_print);

    list_destroy(&head, my_destroy);


    return 0;
err0:
    //销毁链表
    return -1;
}
