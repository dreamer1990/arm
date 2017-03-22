#include "slist.h"


#define my_scanf(op, format, ...)       do{     \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)

typedef struct _stu{
    int id;
    char sex;
    char name[32];
}stu_t;

//自定义的打印学生信息的函数
void  my_print(void *data)
{
    stu_t* stu = (stu_t *)data;
    printf("id:  %d  sex:  %c  name:  %s\n", stu->id, stu->sex, stu->name);
}

//比较学生学号的函数
int cmp_id(void* key, void *data)
{
    return *(int*)key - ((stu_t*)data)->id;
}

//比较学生姓名的函数
int cmp_name(void *key, void *data)
{
    return strcmp(((stu_t*)key)->name, ((stu_t*)data)->name);
}

//保存学生信息到文件中
int my_store_file(void *data, FILE* fp)
{
    int ret = 0;
    //将数据写到文件流中
    ret = fwrite(data, sizeof(stu_t), 1, fp);
    if (ret <= 0)
    {
        printf("fwrite failed....\n"); 
        goto err0;
    }

    return ret;
err0:
    return -1;
}

//从文件中加载学生信息
int my_load_file(void *data, FILE* fp)
{
    int ret = 0;

    //从文件流中读取数据
    ret = fread(data, sizeof(stu_t), 1, fp);
    if (ret <= 0)
    {
        printf("fread failed...\n"); 
        goto err0;
    }

    return ret;
err0:
    return -1;
}


void show_help(void)
{
    printf("============欢迎进入学生管理系统================\n");
    printf("============1. 添加学生信息=====================\n");
    printf("============2. 查看学生信息=====================\n");
    printf("============3. 修改学生信息=====================\n");
    printf("============4. 通过ID删除学生信息===============\n");
    printf("============5. 通过姓名删除学生信息=============\n");
    printf("============6. 通过学号查找学生信息=============\n");
    printf("============9. 退出学生管理系统=================\n");
}



int main(void)
{
    int id = 0;
    int choice = 0;
    int ret = 0;
    slist_t* s = NULL;
    slist_t* s1 = NULL;

    char username[SIZE];
    char passwd[SIZE];

    //学生信息结构体
    stu_t stu;

    id = 3;

    //设置随机种子
    srandom(getpid());

retry2:
    //获取用户和密码
    printf("please input user name:  "); 
    fgets(username, SIZE, stdin);
    printf("please input passwd:    ");
    fgets(passwd, SIZE, stdin);

    printf("=====>  %s   %s\n", username, passwd);
    
    //判断用户和密码
    if (!(0 == strncmp(username, "root", 4) && 0 == strncmp(passwd, "123456", 6)))
    {
        id--;
        printf("登录失败, 请重新试试, 还有%d次机会\n", id); 
        if (0 == id)
        {
            printf("很抱歉,用户已经被锁定...\n");
            goto err0;
        }
        goto retry2;
    }


    //创建头结点
    s = slist_create(sizeof(stu_t), NULL);
    if (NULL == s)
    {
        printf("create slist failed...\n"); 
        goto err0;
    }
   
    s1 = slist_load(s, "./txt", my_load_file); 
    if (NULL == s1)
    {
        printf("加载失败.....\n"); 
    }
    else
    {
        free(s); 
        s = s1;
    }

    while(1)
    {
    retry: 
        //打印相关信息
        show_help(); 
    
        printf("please make a choice[1-5]:    ");
        my_scanf(goto retry, "%d", &choice); 
    
        //退出系统 
        if (9 == choice)
        {
            slist_store(s, "./txt", my_store_file);
            break; 
        }

        switch(choice)    
        {
            case 1:
                //错误：标号只能是语句的一部分，而声明并非语句
                //int a;
                //增加学生信息
                printf("please input student ID:    ");
                my_scanf(,"%d", &id);

                memset(&stu, 0, sizeof(stu));

                //用户输入的学生学号
                stu.id = id;
                //随机获取学生性别
                stu.sex = "MF"[random() % 2];
                //随机获取学生姓名
                sprintf(stu.name, "%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26, 'a' + random() % 26,
                                                    'a' + random() % 26, 'A' + random() % 26, 'a' + random() % 26,
                                                    'a' + random() % 26);
                //尾插  增加学生信息
                slist_append(s, &stu);

                break;
            case 2:
                //打印学生信息
                slist_traverse(s, my_print);
                break;
            case 3:
                //修改学生信息 通过学号修改学生姓名
                memset(&stu, 0, sizeof(stu));
                printf("please input an ID and name:    ");
                my_scanf(,"%d  %c %s", &stu.id, &stu.sex, stu.name);

                slist_modify_by_key(s, &stu.id, &stu, cmp_id);


                break;
            case 4:
                //通过ID删除学生信息
                printf("please input an ID:    ");
                my_scanf(,"%d", &id);
                slist_delete_by_key(s, &id, cmp_id);
                break;

            case 5:
                //通过姓名删除学生信息
                printf("please input a name:   ");
                my_scanf(,"%s", stu.name);
                slist_delete_by_key(s, &stu, cmp_name);
                break;

            case 6:
                //通过学号查找学生信息
                printf("please input an id:    ");
                my_scanf(,"%d", &stu.id);

                id = slist_find_index_by_key(s, &stu.id, cmp_id);
                memset(&stu, 0, sizeof(stu));
                slist_retrieve_by_index(s, &stu, id);

                my_print(&stu);

                break;

            default:
                printf("Bad choice.......\n");
                break;
        
        }
    
    }


    slist_destroy(s);

    return 0;
err0:
    return -1;
}

