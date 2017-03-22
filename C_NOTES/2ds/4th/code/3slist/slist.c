#include "slist.h"

//创建头结点
slist_t* slist_create(int size, op_t destroy)
{
    slist_t *h = NULL;
    
    //分配空间
    h = malloc(sizeof(slist_t));
    if (NULL == h)
    {
        printf("%s  %d malloc failed...\n", __func__, __LINE__); 
        goto err0;
    }

    //初始化
    h->p = NULL;            //链表结点指针
    h->size = size;         //data数据的大小
    h->count = 0;           //链表结点的个数
    h->my_destroy = destroy;//自定义的销毁函数

    return h;
err0:
    return NULL;
}


//返回链表结点的个数
int slist_count(slist_t *s)
{
    return s->count;
}


//分配链表结点中data的空间
static node_t* _alloc_node(slist_t *s, void *data)
{
    node_t* p = NULL;

    p = malloc(sizeof(node_t));
    if (NULL == p)
    {
        printf("%s  %d malloc failed...\n", __func__, __LINE__); 
        goto err1;
    }

    //分配data部分的空间
    p->data = malloc(s->size);
    if (NULL == p->data)
    {
        printf("%s %d malloc failed...\n", __func__, __LINE__); 
        goto err0;
    }

    //清空分配的空间
    memset(p->data, 0, s->size);

    //拷贝数据
    memcpy(p->data, data, s->size);

    p->next = NULL;

    
    return p;

err0:
    if (NULL != p)
        free(p);
err1:
    return NULL;
}

//在链表的最后一个结点插入一个新结点    尾插
int slist_append(slist_t* s, void *data)
{
    //链表结点指针类型
    node_t *new = NULL;
    node_t *tmp = NULL;

    //给新结点分配空间
    new =_alloc_node(s, data);
    if (NULL == new)
    {
        goto err0; 
    }

    tmp = s->p;

    //没有一个结点的情况  
    if (NULL == tmp)
    {
        s->p = new; 
    }
    else
    {
        //使tmp指向链表的最后一个结点
        while(NULL != tmp->next)
            tmp = tmp->next;

        //尾插
        tmp->next = new;    
    }

    //结点的个数加1
    s->count ++;

    return 0;
err0:
    return -1;
}


//在链表的第一个结点前面插入一个结点 头插
int slist_prepend(slist_t* s, void *data)
{
    //链表结点指针类型
    node_t *new = NULL;    

    new = _alloc_node(s, data);
    if (NULL == new)
    {
        goto err0; 
    }

    //头插
    new->next = s->p;
    s->p = new;

    s->count++;

    return 0;
err0:
    return -1;
}


//将新结点插入到index位置上
int slist_insert_by_index(slist_t *s, void *data, int index)
{
    node_t *new = NULL;
    node_t *tmp = NULL;
    int i = 0;

    //检查index出错的情况
    if (index < 0 || index > s->count)
    {
        printf("The index is out of range...\n");
        goto err0;
    }

    //头插
    if (0 == index)
    {
        slist_prepend(s, data); 
    }
    else
    {
        i = 0;
        tmp = s->p; 

        //找到对应的位置
        while(tmp && i < index - 1)
        {
            tmp = tmp->next; 
            i++;
        }

        //创建一个新结点
        new = _alloc_node(s, data);
        if (NULL == new)
            goto err0;
        
        //顺序不能颠倒
        new->next = tmp->next;
        tmp->next = new;
        s->count ++; 
    }

    return 0;
err0:
    return -1;
}

//检索第index个位置结点中的数据域,保存到data中
int slist_retrieve_by_index(slist_t *s, void *data, int index)
{
    node_t *tmp = NULL;
    int i = 0;

    //链表为空的情况
    if (0 == s->count)
    {
        goto err0;
    }
    
    //检查越界的情况
    if (index < 0)
        index = 0;
    if (index > s->count - 1)
        index = s->count - 1;

    tmp = s->p;
    //找到index对应的结点
    while(tmp && i < index)
    {
        tmp = tmp->next; 
        i++;
    }

    //拷贝数据到data中
    memcpy(data, tmp->data, s->size);

    return 0;
err0:
    return -1;
}


//通过关键字找第一个索引
int slist_find_index_by_key(slist_t *s, void *key, cmp_t my_cmp)
{
    int index = 0;

    //tmp指向链表的第一个结点
    node_t *tmp = s->p;

    while(tmp)
    {
        if (0 == my_cmp(tmp->data, key)) 
        {
            //找到了第一个匹配的结点 就结束循环
            break; 
        }
        index ++;
        tmp = tmp->next;
    }

    //没有找到匹配的结点的情况
    if (index >= s->count)
        goto err0;

    return index;
err0:
    return -1;
}
//通过关键字找所有的索引
slist_t *slist_find_all_by_key(slist_t *s, void *key, cmp_t my_cmp)
{
    slist_t *s1 = NULL;
    node_t* tmp = s->p;
    int i = 0;

    //创建链表s1
    s1 = slist_create(sizeof(int), NULL);
    if (NULL == s1)
    {
        goto err0;
    }
    
    //遍历链表 找到匹配的结点
    while(tmp)
    {
        if (0 == my_cmp(tmp->data, key))
        {
            //将找到的索引值插入到链表s1中
            slist_append(s1, &i); 
        }
        i++;
        tmp = tmp->next;
    }
    
    return s1;
err0:
    return NULL;
}


//通过索引值改对应的数据域
int slist_modify_by_index(slist_t *s, void *key, int index)
{
    node_t *tmp = s->p;    
    int i = 0;

    //链表为空的情况
    if (0 == s->count)
    {
        printf("The list is empty...\n"); 
        goto err0;
    }

    //检查越界的情况
    if (index < 0)
        index = 0;
    if (index > s->count - 1)
        index = s->count - 1;

    //找对应的结点
    while(i < index)
    {
        tmp = tmp->next; 
        i++;
    }
    //修改对应结点数据域的值
    memcpy(tmp->data, key, s->size);

    return 0;
err0:
    return -1;
}

//通过关键字改第一个匹配的结点对应的数据域
int slist_modify_by_key(slist_t *s, void *key, void *data, cmp_t my_cmp)
{
    node_t *tmp = s->p;

    //链表为空的情况
    if (NULL == tmp)    
    {
        printf("The list is empty....\n"); 
        goto err0;
    }

    //链表遍历
    while(tmp)
    {
        if (0 == my_cmp(tmp->data, key)) 
        {
            memcpy(tmp->data, data, s->size); 
            //只改第一个匹配的结点
            break;
        }
        tmp = tmp->next;
    }

    return 0;
err0:
    return -1;
}


//通过关键字改所有对应的数据域
int slist_modify_all_by_key(slist_t *s, void *key, void *data, cmp_t my_cmp)
{
    node_t *tmp = s->p; 

    //链表为空的情况
    if (NULL == tmp)
    {
        printf("The list is empty..\n"); 
        goto err0;
    }

    while(tmp)
    {
        if (0 == my_cmp(tmp->data, key)) 
        {
            memcpy(tmp->data, data, s->size); 
        }
        tmp = tmp->next;
    }

    return 0;
err0:
    return -1;
}


//通过索引删除链表的结点
int slist_delete_by_index(slist_t *s, int index)
{
    int i = 0;
    node_t *tmp = s->p;
    node_t *save = NULL;

    //越界检查
    if (index < 0 || index > s->count - 1)
    {
        printf("The index out of range...\n"); 
        goto err0;
    }

    //找对应的结点
    while(i < index - 1)
    {
        tmp = tmp->next;
        i++;
    }

    //第一个结点
    if (0 == index)
    {
        s->p = tmp->next;
        //释放空间
        if (NULL != s->my_destroy)
            s->my_destroy(tmp->data);
        free(tmp->data);
        free(tmp);
        s->count --;
    }
    /*
    else if (index == s->count - 1)
    {
        //最后一个结点的情况
        save = tmp->next; 
        tmp->next = NULL;

        //释放空间
        if (NULL != s->my_destroy)
            s->my_destroy(save->data);
        free(save->data);
        free(save);
        s->count --;
    }
    */
    else
    {
        //保存要删除的结点
        save = tmp->next;    
        tmp->next = save->next;
        //tmp->next = tmp->next->next;

        if (NULL != s->my_destroy)
            s->my_destroy(save->data);
        free(save->data);
        free(save);
        s->count--;

    }
   
    return 0;
err0:
    return -1;
}

//通过关键字删除链表的结点
int slist_delete_by_key(slist_t *s, void *key, cmp_t my_cmp)
{
    int i = 0;
    i = slist_find_index_by_key(s, key, my_cmp);
    return slist_delete_by_index(s, i);
}

//通过关键字删除所有的结点
int slist_delete_all_by_key(slist_t *s,  void *key, cmp_t my_cmp)
{
    node_t *tmp = s->p;
    node_t *save = NULL;
    int i = 0;

    while(tmp)
    {
        save = tmp->next;
        if (0 == my_cmp(tmp->data, key)) 
        {
            slist_delete_by_index(s, i); 
            i--;
        }
        i++;
        tmp = save;
    }

    return 0;
}

//链表的反转
int slist_reverse(slist_t *s)
{
    node_t *tmp = s->p;
    node_t *save = NULL;

    //清空头结点
    s->p = NULL;

    //每一次拿掉一个结点 然后通过头插法插入链表
    while(tmp)
    {
        //保存下一个结点
        save = tmp->next; 
        
        //头插法
        tmp->next = s->p;
        s->p = tmp;
        
        //tmp指向下一个结点
        tmp = save;
    }
    
    return 0;
}


//链表的遍历
int slist_traverse(slist_t* s, op_t my_print)
{
    node_t *tmp = NULL; 

    //如果没有自定义打印函数,则出错返回
    if (NULL == my_print)
    {
        printf("my_print no defined  error....\n"); 
        goto err0;
    }
    //将链表的第一个结点赋值给tmp
    tmp = s->p;

    //遍历链表的结点
    while(tmp)
    {
        my_print(tmp->data); 
        tmp = tmp->next;
    }
    //换行
    putchar('\n');

    return 0;
err0:
    return -1;
}

//链表的销毁
int slist_destroy(slist_t*s)
{
    //保存链表的第一个结点
    node_t *tmp = s->p;
    
    while(tmp)
    {
        //调用自定义的destroy函数
        if (NULL != s->my_destroy) 
            s->my_destroy(tmp->data);

        //保存下一个结点
        s->p = tmp->next;
        //释放数据域
        free(tmp->data);
        //释放链表结点
        free(tmp);
        //将下一个结点赋值给tmp
        tmp = s->p;
    }

    free(s);
}


//将链表数据保存到文件中
int slist_store(slist_t *s, char *path, op_file_t op_file)
{
    int ret = 0;

    //tmp指向第一个节点
    node_t* tmp = s->p;

    FILE *fp = NULL;

    //链表为空的情况
    if (NULL == tmp)
        goto err0;

    //以只读的方式打开文件
    fp = fopen(path, "w");
    if (NULL == fp)
    {
        printf("fopen %s failed...\n", path); 
        goto err0;
    }

    //写魔法数字
    ret = fwrite(MAGIC, sizeof(char), strlen(MAGIC), fp);
    if (ret <= 0)
    {
        printf("fwrite failed...\n"); 
        goto err1;
    }
    

    //依次遍历链表节点 然后保存到文件中
    while(tmp)
    {
        //调用回调函数 保存节点的数据
        op_file(tmp->data, fp); 
        tmp = tmp->next;
    }


    fclose(fp);
    return 0;
err1:
    fclose(fp);
err0:
    return -1;
}

//从文件中加载链表数据
slist_t* slist_load(slist_t *s, char *path, op_file_t op_file)
{
    FILE* fp = NULL;
    void *data = NULL;
    char buf[16];
    int ret = 0;
    slist_t *s1 = NULL;
    node_t *new = NULL;

    //打开文件
    fp = fopen(path, "r");
    if (NULL == fp)
    {
        printf("fopen failed...\n"); 
        goto err0;
    }

    //读取文件头信息  MAGIC
    ret = fread(buf, sizeof(char), strlen(MAGIC), fp);
    buf[ret] = '\0';
    //printf("=====> read from file:   %s\n", buf);
    if (strncmp(buf, MAGIC, 4) != 0)
    {
        printf("load file faild....\n"); 
        goto err1;
    }

    s1 = slist_create(s->size, s->my_destroy);
    if (NULL == s1)
    {
        printf("slist create failed..\n"); 
        goto err1;
    }

    data = malloc(s->size);
    if (NULL == data)
    {
        printf("malloc data failed...\n"); 
        goto err1;
    }
    
    //判断是否读到文件结尾
    while(!feof(fp))
    {
        //从文件中读取一个节点数据 
        ret = op_file(data, fp);
        if (ret <= 0)
        {
            break;
        }
    
        //将读到的数据插入链表中
        slist_append(s1, data);
    }

    
    free(data);
    fclose(fp);

    return s1;

err2:
    slist_destroy(s1);
err1:
    if (NULL != data)
        free(data);
    fclose(fp);
err0:
    return NULL;
}





