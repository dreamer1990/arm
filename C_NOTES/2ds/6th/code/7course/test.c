#include "list.h"


#define my_scanf(op,format, ...)    do {        \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)

//过滤换行符或者清空标准输入缓冲区
#define my_fgets(buf, size)  do{                \
    fgets(buf, size, stdin);                    \
    if (buf[strlen(buf) - 1] == '\n')           \
        buf[strlen(buf) - 1] = '\0';            \
    else                                        \
    {                                           \
        while(getchar() != '\n')                \
            /*do nothing*/;                     \
    }                                           \
}while(0)



//学生结构体
typedef struct _stu_t {
    int id;                     //学生学号
    char sex;                   //学生性别
    char name[SIZE];            //学生姓名
    struct list_head s_entry;   //学生节点的指针域
    struct list_head s_i_entry; //学生与item链接的指针域
}stu_t;

//课程结构体
typedef struct _course_t{
    int id;                     //课程ID号
    char name[SIZE];            //课程名字
    struct list_head c_entry;   //课程节点的指针域
    struct list_head c_i_entry; //课程与item链接的指针域
}course_t;

//中间节点结构体
typedef struct _item_t{
    stu_t *i_s;                 //指向学生结构体
    course_t *i_c;              //指向课程结构体

    struct list_head i_s_entry; //与学生结构体中的s_i_entry进行链接
    struct list_head i_c_entry; //与课程结构体中的c_i_entry进行链接
}item_t;

//添加课程
int course_add(struct list_head *c_h)
{
    course_t *new = NULL;
    
    //课程节点为空的情况
    if (NULL == c_h)
    {
        printf("The head of the course is NULL...\n"); 
        goto err0;
    }

    //分配课程节点
    new = malloc(sizeof(course_t));
    if (NULL == new)
    {
        printf("malloc course failed...\n"); 
        goto err0;
    }
    //清空新分配的空间
    memset(new, 0, sizeof(course_t));

    printf("请输出课程名称:   ");
    my_fgets(new->name, SIZE);

    //范围 1 - 100 
    new->id = random() % 100 + 1;

    //item节点指向本身
    new->c_i_entry.prev = &new->c_i_entry;
    new->c_i_entry.next = &new->c_i_entry;

    //尾插法 添加课程节点
    list_add_tail(&new->c_entry, c_h); 

    return 0;
err0:
    return -1;
}

//查看课程
int course_show(struct list_head *c_h)
{
    course_t *c_tmp = NULL;
    struct list_head *h_tmp = NULL;

    //课程链表为空的情况
    if (NULL == c_h)
    {
        printf("The course list is empty....\n"); 
        goto err0;
    }

    //list_for_each是遍历链表的循环宏
    list_for_each(h_tmp, c_h)
    {
        c_tmp = list_entry(h_tmp, course_t, c_entry); 
        printf("课程 id:  %2d  name:  %s\n", c_tmp->id, c_tmp->name); 
    }

    return 0;
err0:
    return -1;
}

//销毁课程链表
int course_destroy(struct list_head *c_h)
{
    course_t *c_tmp = NULL;
    struct list_head *h_tmp1 = NULL;
    struct list_head *h_tmp2= NULL;

    if (NULL == c_h)
    {
        printf("The course list is empty.....\n");
        goto err0;
    }

    //比较安全的方式遍历链表
    list_for_each_safe(h_tmp1, h_tmp2, c_h)
    {
        //list_entry计算结构体的首地址
        c_tmp = list_entry(h_tmp1, course_t, c_entry); 
        free(c_tmp); 
        c_tmp = NULL;
    }

    return 0;
err0:
    return -1;
}

//根据学生节点删除中间的节点
int item_destroy(struct list_head *item)
{
    item_t *i_tmp = NULL;
    
    struct list_head *t1 = NULL, *t2 = NULL;
    list_for_each_safe(t1, t2, item)
    {
        i_tmp = list_entry(t1, item_t, i_s_entry); 
        free(i_tmp);
        i_tmp = NULL;
    }

    return 0;
}

//添加学生
int stu_add(struct list_head *s_h, struct list_head *c_h) 
{
    stu_t *new = NULL;      //学生节点
    course_t *c = NULL;     //课程节点
    item_t *item = NULL;       //中间节点
    struct list_head *t1 = NULL;

    char choice;

    //学生链表头结点没有初始化的情况
    if (NULL == s_h)
    {
        printf("The node of the student list is empty...\n"); 
        goto err0;
    }

    //分配空间
    new = malloc(sizeof(stu_t));
    if (NULL == new)
    {
        printf("student malloc failed....\n"); 
        goto err0;
    }
    //清空新分配的空间
    memset(new, 0, sizeof(stu_t));
    
    //学号初始化
    new->id = random() % 100 + 1;
    //性别初始化
    new->sex = "MF"[random() % 2];

    printf("请输入学生姓名:   ");
    my_fgets(new->name, SIZE);

    //初始化item节点
    new->s_i_entry.prev = &new->s_i_entry;
    new->s_i_entry.next = &new->s_i_entry;

    //课程链表为空的时候
    if (NULL == c_h) 
    {
        printf("选课失败..  学生链表为空\n");
        goto err1;
    }


    for (t1 = c_h->next; t1 != c_h; t1 = t1->next)
    {
        c = list_entry(t1, course_t, c_entry);  
        printf("是否选择 课程:  %s [y/Y]    ", c->name);
        my_scanf(,"%c", &choice);

        if ('y' == choice || 'Y' == choice)
        {
            //分配item的空间
            item = malloc(sizeof(item_t)); 
            if (NULL == item)
            {
                printf("malloc item failed...\n"); 
                goto err1;
            }
            
            //指向当前学生结点
            item->i_s = new;
            //指向当前课程节点
            item->i_c = c;
            
            //将中间节点与学生链表关联
            list_add_tail(&item->i_s_entry, &new->s_i_entry);
            //将中间节点与课程链表关联
            list_add_tail(&item->i_c_entry, &c->c_i_entry);
        }
    }


    //尾插法添加学生
    list_add_tail(&new->s_entry, s_h);

    return 0;
err1:
    free(new);
err0:
    return 0;
}

//显示学生信息
int stu_show(struct list_head *s_h)
{
    stu_t *s_tmp = NULL;
    struct list_head *s_h1 = NULL;

    //链表为空就出错返回
    if (NULL == s_h)
    {
        printf("The list is empty....\n"); 
        goto err0;
    }

    //遍历链表
    list_for_each(s_h1, s_h)
    {
        s_tmp = list_entry(s_h1, stu_t, s_entry); 
        printf("学生 id:  %2d  性别:  %c  姓名: %s\n", s_tmp->id, s_tmp->sex, s_tmp->name); 
    
    }

    return 0;
err0:
    return -1;
}

//销毁学生链表
int stu_destroy(struct list_head *s_h)
{
    stu_t *tmp = NULL;

    struct list_head *s1 = NULL, *s2 = NULL;

    //链表为空的情况
    if (NULL == s_h)
    {
        printf("The student list is empty....\n"); 
        goto err0;
    }

    //s2当作临时保存
    list_for_each_safe(s1, s2, s_h)
    {
        tmp = list_entry(s1, stu_t, s_entry);  

        item_destroy(&tmp->s_i_entry);
        
        free(tmp); 
        tmp = NULL;
    }


    return 0;
err0:
    return -1;
}


//根据课程查询学生
int  query_stu_by_course(struct list_head *c_h)
{
    char buf[SIZE];

    struct list_head *tmp1 = NULL, *tmp2 = NULL;
    course_t *c_tmp = NULL;
    item_t *i_tmp = NULL;

    //课程链表为空的情况
    if (NULL == c_h)
    {
        printf("The course list is empty...\n"); 
        goto err0;
    }

    printf("please input a course name:   ");
    my_fgets(buf, SIZE);

    //遍历课程链表 找到对应课程的节点
    list_for_each(tmp1, c_h)    
    {
        
        //计算课程结构体的首地址
        c_tmp = list_entry(tmp1, course_t, c_entry);
        //比较课程名称
        if (strcmp(buf, c_tmp->name) == 0)
        {
            printf("选择课程: %s的学生有  ", c_tmp->name);
            //遍历链表
            list_for_each(tmp2, &c_tmp->c_i_entry)
            {
                
                i_tmp = list_entry(tmp2, item_t, i_c_entry);     
                printf("%s  ", i_tmp->i_s->name);
            
            }
            putchar('\n');
        }
    }

    return 0;
err0:
    return -1;
}

//根据学生查课程
int query_course_by_stu(struct list_head *s_h)
{
    char name[SIZE];
    struct list_head *tmp1 = NULL, *tmp2 = NULL;
    stu_t *s_tmp = NULL;
    item_t *i_tmp = NULL;


    if (NULL == s_h)
    {
        printf("The Student list is empty....\n"); 
        goto err0;
    }

    printf("请输入学生姓名:   ");
    my_fgets(name, SIZE);

    //遍历学生链表
    list_for_each(tmp1, s_h)
    {
        s_tmp = list_entry(tmp1, stu_t, s_entry); 

        if (strcmp(name, s_tmp->name) == 0)
        {
            printf("学生： %s选的课程有  ");
            list_for_each(tmp2, &s_tmp->s_i_entry) 
            {
                i_tmp = list_entry(tmp2, item_t, i_s_entry); 
                printf("%s  ", i_tmp->i_c->name);
            
            }
            //换行
            putchar('\n');
        
        }
     
    }


    return 0;
err0:
    return -1;
}







int main(void)
{
    int choice;

    //初始化课程链表的头结点
    LIST_HEAD(c_head);
    //初始化学生链表的头结点
    LIST_HEAD(s_head);
    
    //设置随机种子
    srandom(time(NULL));


    printf("***********************************************\n");
    printf("***********欢迎进入学生选课系统****************\n");
    printf("***********************************************\n");

    while(1)
    {
    retry: 
		printf("======> 1. 添加课程       <======\n");	
		printf("======> 2. 添加学生       <======\n");	
		printf("======> 3. 显示课程       <======\n");	
		printf("======> 4. 显示学生       <======\n");	
		printf("======> 5. 根据学生查课表 <======\n");	
		printf("======> 6. 根据课表查学生 <======\n");	
		printf("======> 7. 退出           <======\n");	
		printf(">>> 请选择操作: ");

        my_scanf(goto retry, "%d", &choice);
        //退出循环
        if (7 == choice)
        {
            //销毁课程链表
            course_destroy(&c_head);
            //销毁学生链表
            stu_destroy(&s_head);
            break;
        }

        switch(choice)
        {
            case 1:
                //添加课程
                course_add(&c_head);  
                break;
            case 2:
                //添加学生
                stu_add(&s_head, &c_head);
                break;
            case 3:
                //显示课程
                course_show(&c_head);                
                break;
            case 4:
                //显示学生
                stu_show(&s_head);
                break;
            case 5:
                query_course_by_stu(&s_head);
                break;
            case 6:
                query_stu_by_course(&c_head);
                break;

            default:
                printf("无效的选择,请重新试试\n"); 
        }
    
    }

    return 0;
}




