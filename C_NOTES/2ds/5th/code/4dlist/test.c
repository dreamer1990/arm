#include "dlist.h"

#define my_scanf(op,format,...) do{         \
    int ret = 0;                            \
    ret = scanf(format, __VA_ARGS__);       \
    while('\n' != getchar())                \
    /*do nothing*/;                     \
    if (ret <= 0)                           \
    op;                                 \
}while(0)

#define SIZE 32


typedef struct _stu {

    int id;     //学生学号
    char sex;   //学生性别
    char *name; //学生姓名
}stu_t;

//自定义的销毁节点的函数
void my_destroy(void *data)
{
    free(((stu_t*)data)->name);
}

//自定义输出函数

void my_print(void *data)
{
    stu_t *p = data;

    printf("id:  %d  sex:  %c  name:  %s\n", p->id, p->sex, p->name);
}



int main(void)
{
    int n;
    
    dlist_t *h = NULL;
    stu_t stu;

    h = dlist_create(sizeof(stu_t), my_destroy);
    if (NULL == h)
    {
        goto err0; 
    }

    //设置随机种子
    srandom(getpid());

    while(1)
    {
    retry:
        printf("please input a number[-1 quit]:   "); 
        my_scanf(goto retry, "%d", &n);
    
        //结束循环
        if (-1 == n)
        {
            break;
        }


        memset(&stu, 0, sizeof(stu));
        stu.id = n;
        stu.sex = "MF"[random()%2];

        //分配内存
        stu.name = malloc(SIZE);
        memset(stu.name, 0, SIZE);

        //name随机赋值
        sprintf(stu.name, "%c%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26,
                                              'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26);

        dlist_append(h, &stu);
    }

        dlist_traverse(h, my_print);


        //释放内存
        dlist_destroy(h);

    return 0;
err0:
    return -1;
}
