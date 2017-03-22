#include "queue.h"

#define MY_SCANF(op,format, ...)        do{     \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)


typedef struct _stu_t {
    int id;
    char sex;
    char name[32];
}stu_t;


int main(void)
{
    int id = 0;
    stu_t stu;
    queue_t *q = NULL; 

    //分配空间
    q = queue_create(sizeof(stu_t), 10, NULL);
    if (NULL == q)
        goto err0;

    //设置随机种子
    srandom(time(NULL));

    while(1)
    {
    retry:
        printf("please inputa an id[-1 quit]:   "); 
        MY_SCANF(goto retry, "%d", &id);

        //退出循环
        if (-1 == id)
            break;

        stu.id = id;
        stu.sex = "MF"[random() % 2];
        sprintf(stu.name, "%c%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26,
                                              'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26);
        //入队列 
        queue_en(q, &stu); 
    }

    printf("队列中元素的个数: %d\n", queue_count(q));

    //出队列
    while(!queue_is_empty(q))
    {
        memset(&stu, 0, sizeof(stu)); 
        queue_de(q, &stu); 
        printf("id:  %d  sex:  %c  name:  %s\n", stu.id, stu.sex, stu.name);
    }


    queue_destroy(q);


    return 0;
err0:
    return -1;
}
