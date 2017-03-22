#include "slist.h"


#define my_scanf(op, format, ...)       do{     \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)

//自定义数据域
typedef struct _stu{
    int id;     //学生学号
    char sex;   //学生性别
    char *name; //学生姓名
}stu_t;


//自定义的销毁函数
void my_destroy(void *data)
{
    free(((stu_t*)data)->name);    
}

//自定义的输出学生信息的函数
void my_print(void *data)
{
    stu_t* tmp = data;

    printf("id:  %d  sex:  %c  name:  %s\n", tmp->id, tmp->sex, tmp->name);

}

int main(void)
{
    stu_t stu;
    int id = 0;
    int ret = 0;

    slist_t* s = NULL;

    srandom(getpid());

    //创建单链表的头结点
    s = slist_create(sizeof(stu_t), my_destroy);
    if (NULL == s)
    {
        printf("slist_create failed....\n"); 
        goto err0;
    }

    while(1)
    {
    retry:
        printf("please input an id:    "); 
        my_scanf(goto retry, "%d", &id);
        
        //退出循环的条件
        if (-1 == id)
            break;
    
        //清空stu结构体
        memset(&stu, 0, sizeof(stu)); 

        //name分配空间
        stu.name = malloc(SIZE);
        if (NULL == stu.name)
        {
            slist_destroy(s); 
            goto err0;
        }

        //结构体赋值
        stu.id = id;
        stu.sex = "MF"[random() % 2];
        sprintf(stu.name, "%c%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26,
                                              'A' + random() % 26, 'a' + random() % 26,
                                              'a' + random() % 26, 'a' + random() % 26);
        //浅拷贝
        slist_append(s, &stu); 
    }

    //输出所有学生的信息
    slist_traverse(s, my_print);
    //销毁链表
    slist_destroy(s);


    return 0;
err0:
    return -1;
}

