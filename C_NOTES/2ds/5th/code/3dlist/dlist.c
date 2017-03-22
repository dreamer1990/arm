#include "dlist.h"


//创建头结点
dlist_t* dlist_create(int size, op_t my_destroy)
{
    dlist_t* d = NULL;

    //分配空间
    d = malloc(sizeof(dlist_t));
    if (NULL == d)
    {
        printf("malloc dlist_t failed...\n"); 
        goto err0;
    }

    memset(d, 0, sizeof(dlist_t));

    //结构提赋值
    d->p = NULL;            //指向链表的第一个节点
    d->size = size;         //节点的大小
    d->count = 0;           //节点的个数
    d->my_destroy = my_destroy; //自定义销毁函数

    return d;
err0:
    return NULL;
}

//分配节点空间
static node_t* _alloc_node(dlist_t* h, void *data)
{
    node_t *new = NULL;

    //分配节点空间
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("malloc node_t failed...\n"); 
        goto err0;
    }
    //清空结构体
    memset(new, 0, sizeof(node_t));

    //分配数据域的空间
    new->data = malloc(h->size);
    if (NULL == new->data)
    {
        printf("malloc data failed...\n"); 
        goto err1;
    }
    //清空data
    memset(new->data, 0, h->size);
    //拷贝数据
    memcpy(new->data, data, h->size);

    return new;
err1:
    free(new);
err0:
    return NULL;
}

//尾插  添加链表节点
int dlist_append(dlist_t* h, void *data)
{
    node_t *new = NULL;

    node_t *tmp = h->p;

    //分配空间
    new = _alloc_node(h, data);
    if (NULL == new)
        goto err0;


    //链表为空的时候
    if (NULL == h->p)
    {
        //new节点的前驱和后继都指向本身
        new->next = new;
        new->prev = new;
        //h->p指向第一个节点
        h->p = new;
    }
    else
    {
        //new的后继指向链表的第一个节点
        new->next = tmp; 
        //new的前驱指向原来链表的最后一个节点
        new->prev = tmp->prev;
        //原来链表的最后一个节点的后继指向new 
        tmp->prev->next = new;
        //链表的第一个节点的前驱指向new
        tmp->prev = new;
    }

    h->count++;
    return 0;
err0:
    return -1;
}
//头插  添加链表节点
int dlist_prepend(dlist_t* h, void *data)
{
    node_t* new = NULL;
    node_t* tmp = h->p;
    //分配节点空间
    new = _alloc_node(h, data);
    if (NULL == new)
        goto err0;

    if (NULL == tmp) 
    {
        new->next = new;
        new->prev = new;
    }
    else
    {
        //新节点的后继为链表的第一个节点
        new->next = tmp;
        //新节点的前驱为链表原来最后一个节点
        new->prev = tmp->prev;
        //链表原来最后一个节点的后继为new
        tmp->prev->next = new;
        //链表原来第一个节点的前驱为new
        tmp->prev = new;
    }

    //new为链表的第一个节点
    h->p = new;

    h->count ++;

    return 0;
err0:
    return -1;
}


//头插  添加链表节点  版本二
int dlist_prepend_v1(dlist_t* h, void *data)
{
    int ret = 0;

    //尾插
    ret = dlist_append(h, data);
    if (ret < 0)
        goto err0;

    //改变h->p的指向
    h->p = h->p->prev;

    return 0;
err0:
    return -1;
}

//返回链表节点的个数
int dlist_count(dlist_t* h)
{
    return h->count;
}


//插入节点到指定的位置 索引从1 --- count
int dlist_insert_by_index(dlist_t* h, void *data, int index)
{
    int i = 1;
    node_t* tmp = h->p;
    node_t* new = NULL;

    //index不在范围之内
    if (index < 1 || index > h->count + 1)
    {
        printf("The index is out of range\n"); 
        goto err0;
    }

    //新结点分配空间
    new = _alloc_node(h, data);
    if (NULL == new)
        goto err0;

    //表示链表开始没有节点
    if (NULL == tmp)
    {
        new->next = new;
        new->prev = new;
        h->p = new;
    }
    else if (1 == index)
    {
        new->next = tmp;
        new->prev = tmp->prev;

        //以下两句顺序不能颠倒
        tmp->prev->next = new;
        tmp->prev = new;

        h->p = new;
    }
    else
    {
        while(i < index) 
        {
            tmp = tmp->next; 
            i++;
        }

        //现在找到位置为后一个节点
        new->next = tmp;
        new->prev = tmp->prev;
        tmp->prev->next = new;
        tmp->prev = new;
    }

    h->count ++;

    return 0;
err0:
    return -1;
}


//通过索引找对应的数据域 将数据保存到data中
int dlist_retrieve_by_index(dlist_t* h, void *data, int index)
{
    int i = 1;
    node_t* tmp = h->p;

    //检查出错的情况
    if (index < 1 || index > h->count)
    {
        printf("The index is out of range....\n"); 
        goto err0;
    }

    //找到对应的节点位置
    while(i < index)
    {
        tmp = tmp->next;
        i++;
    }

    //拷贝数据到data中
    memcpy(data, tmp->data, h->size);

    return 0;
err0:
    return -1;
}

//通过关键字找第一个索引
int dlist_find_index_by_key(dlist_t* h, void *key, op_cmp_t my_cmp)
{
    int index = 1;    

    node_t *tmp = h->p;

    //相当于遍历链表
    do{
        if (0 == my_cmp(key, tmp->data)) 
        {
            break; 
        }
        tmp = tmp->next;
        index ++;

    }while(h->p != tmp);

    //没有找到的情况
    if (1 != index && tmp == h->p)
        goto err0;

    return index;
err0:
    return -1;
}

//通过关键字找到所有的索引
dlist_t* dlist_find_all_index_by_key(dlist_t* h, void *key, op_cmp_t my_cmp)
{
    int index = 1;
    dlist_t *d = NULL;
    node_t *tmp = h->p;

    if (NULL == h->p)
    {
        printf("The list is empty....\n"); 
        goto err0;
    }

    //创建头结点
    d = dlist_create(sizeof(int), NULL);
    if (NULL == d)
    {
        printf("dlist_create failed...\n"); 
        goto err0;
    }

    //遍历
    do{
        if (my_cmp(key, tmp->data) == 0) 
        {
            //将索引添加到链表中
            dlist_append(d, &index); 
        }
        tmp = tmp->next;
        index ++;

    }while(h->p != tmp);


    return d;
err0:
    return NULL;
}



//通过索引修改对应的数据
int dlist_modify_by_index(dlist_t* h, void *data, int index)
{
    int i = 1;
    node_t *tmp = h->p;

    //超出范围
    if (index < 1 || index > h->count)
    {
        printf("out of range....\n"); 
        goto err0;
    }

    while(i < index)
    {
        tmp = tmp->next;
        i++;
    }

    //拷贝数据到节点中
    memcpy(tmp->data, data, h->size);

    return 0;
err0:
    return -1;
}
//通过关键字修改第一个数据
int dlist_modify_by_key(dlist_t* h, void *key, void *data, op_cmp_t my_cmp)
{
    node_t* tmp = h->p; 

    //链表为空的情况
    if (NULL == tmp)
        goto err0;

    do {
        if (0 == my_cmp(key, tmp->data)) 
        {
            //修改对应的数据
            memcpy(tmp->data, data, h->size); 
            break;
        }

        tmp = tmp->next;

    }while(h->p != tmp);


    return 0; 
err0:
    return -1;
}
//通过关键字修改所有的数据
int dlist_modify_all_by_key(dlist_t* h, void *key, void *data, op_cmp_t my_cmp)
{
    node_t* tmp = h->p; 

    //链表为空的情况
    if (NULL == tmp)
        goto err0;

    do {
        if (0 == my_cmp(key, tmp->data)) 
        {
            //修改对应的数据
            memcpy(tmp->data, data, h->size); 
            //break;
        }

        tmp = tmp->next;

    }while(h->p != tmp);


    return 0; 
err0:
    return -1;
}


//通过索引删除节点
int dlist_delete_by_index(dlist_t *h, int index)
{
    int i = 1;

    node_t *tmp = h->p;

    if (index < 1 || index > h->count)
    {
        printf("out of range.....\n"); 
        goto err0;
    }

    //删除第一个节点
    if (1 == index)
    {
        h->p = tmp->next;
    }
    else
    {
        while(i < index)
        {
            tmp = tmp->next;
            i++;
        }

    }

    //tmp的后继的前驱指向tmp的前驱
    tmp->next->prev = tmp->prev;
    //tmp的前驱的后继指向tmp的后继
    tmp->prev->next = tmp->next;

    //释放节点 
    if (NULL != h->my_destroy)
        h->my_destroy(tmp->data);
    free(tmp->data);
    free(tmp);

    h->count --; 

    return 0;
err0:
    return -1;
}
//通过关键字删除一个节点
int dlist_delete_by_key(dlist_t *h, void *key, op_cmp_t my_cmp)
{
    int index = 0;

    //先找到对应的索引
    index = dlist_find_index_by_key(h, key, my_cmp);

    printf("index:   -----------> %d\n", index);
    //通过索引删除节点
    dlist_delete_by_index(h, index);

    return 0;
}
//通过关键字删除所有的节点
int dlist_delete_all_by_key(dlist_t *h, void *key, op_cmp_t my_cmp)
{
    int index = 1;
    int i = 0;
    int tmp1 = h->count;

    node_t *tmp = h->p;
    node_t *save = NULL;

    //空链表的情况
    if (NULL == h->p)
    {
        printf("The list is empty.....\n"); 
        goto err0;
    }

    for (i = 1; i <= tmp1; i++)
    {
        //先保存节点  否则Invalid read of size 8
        save = tmp->next;
        if (0 == my_cmp(key, tmp->data)) 
        {
            dlist_delete_by_index(h, index);  
            index--;
        }

        tmp = save;
        index++;
    
    }


    return 0;
err0:
    return -1;
}

//将链表数据保存到文件中
int dlist_store(dlist_t *h, char* path, op_file_t op_file)
{
    int ret = 0;
    node_t *tmp = h->p;
    FILE* fp = NULL;

    //判断链表为空的情况
    if (NULL == tmp)
    {
        printf("The list is empty...\n"); 
        goto err0;
    }

    if (NULL == op_file)
    {
        printf("op_file is NULL ....\n"); 
        goto err0;
    }

    //以只写的方式打开文件
    fp = fopen(path, "w");
    if (NULL == fp)
    {
       printf("open file failed...\n");  
       goto err0;
    }

    //写魔法数字
    ret = fwrite(MAGIC, sizeof(char), strlen(MAGIC), fp);
    printf("ret = %d\n", ret);
    
    //写h->size到文件中
    ret = fwrite(&h->size, sizeof(int), 1, fp);
    printf("ret = %d\n", ret);

    //写h->count到文件中
    ret = fwrite(&h->count, sizeof(int), 1, fp);
    printf("count:  ret = %d\n", ret);

    do{
        op_file(tmp->data, fp); 
        tmp = tmp->next;
    }while(tmp != h->p); 


    //关闭文件
    fclose(fp);
    return 0;
err0:
    return -1;
}

//从文件中加载链表信息
int dlist_load(dlist_t *h, char *path, op_file_t op_file)
{
    int i = 0;
    int ret = 0;
    char buf[32];    
    FILE *fp = NULL;
    void *data = NULL;

    //判断信息结构体为空的情况
    if (NULL == h)
    {
        printf("The head of the list is empty....\n"); 
        goto err0;
    }

    //判断参数出错的情况
    if (NULL == op_file || NULL == path)
    {
    
        printf("The parameter is empty....\n"); 
        goto err0;
    }

    //打开文件失败的情况
    fp = fopen(path, "r");
    if (NULL == fp)
    {
        printf("open file failed...\n"); 
        goto err0;
    }

    ret = fread(buf, sizeof(char), strlen(MAGIC), fp);
    buf[ret] = '\0';

    //比较魔法数字
    if (strncmp(buf, MAGIC, 5) != 0)
    {
        printf("The MAGIC is error...\n"); 
        goto err1;
    }

    //读取h->size大小
    ret = fread(&h->size, sizeof(int), 1, fp);
    printf("ret = %d   size =  %d\n", ret, h->size);

    //读取链表的长度
    ret = fread(&h->count, sizeof(int), 1, fp);
    printf("ret = %d  count = %d\n", ret, h->count);

    //分配临时变量
    data = malloc(h->size);
    if (NULL == data)
    {
        printf("malloc data failed...\n"); 
        goto err1;
    }

    ret = h->count;

    h->count = 0;

    for (i = 0; i < ret; i++) 
    {
        op_file(data, fp);

        dlist_append(h, data); 
    }


    free(data);
    fclose(fp);
    return 0;
    
err1:
    fclose(fp);
err0:
    return -1;
}


//链表的逆向遍历
int dlist_back_traverse(dlist_t* h, op_t my_print)
{
    node_t* tmp = h->p->prev;

    //链表为空的情况
    if (NULL == h->p)
    {
        printf("The list is emptry....\n"); 
        goto err0;
    }

    
    do{
        my_print(tmp->data); 

        tmp = tmp->prev;
    
    }while(tmp != h->p->prev);

    //换行
    putchar('\n');


    return 0;
err0:
    return -1;
}



//链表的遍历
int dlist_traverse(dlist_t* h, op_t my_print)
{
    node_t* tmp = h->p;

    //链表为空的情况
    if (NULL == h->p)
    {
        printf("The list is empty.....\n");
        goto err0;
    }

    //遍历
    do{
        my_print(tmp->data); 
        tmp = tmp->next;
    }while(tmp != h->p);

    putchar('\n');

    return 0;
err0:
    return -1;
}
//链表的销毁
int dlist_destroy(dlist_t* h)
{
    node_t *tmp = h->p;
    node_t *save = NULL;

    //链表为空的情况
    if (NULL == tmp)
    {
        printf("The list is empty\n"); 
        goto err0;
    }

    do {
        //保存下一个节点
        save = tmp->next; 

        //如果自定义的销毁函数不为空
        if (NULL != h->my_destroy)
        {
            h->my_destroy(tmp->data); 
        }
        //释放掉数据域空间 
        free(tmp->data);
        //释放节点空间
        free(tmp);

        tmp = save;
    }while(h->p != tmp);

    //释放头结点空间
    free(h);

    return 0;
err0:
    return -1;
}




