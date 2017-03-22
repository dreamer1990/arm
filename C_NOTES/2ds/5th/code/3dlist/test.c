#include "dlist.h"

#define my_scanf(op,format,...) do{         \
    int ret = 0;                            \
    ret = scanf(format, __VA_ARGS__);       \
    while('\n' != getchar())                \
    /*do nothing*/;                     \
    if (ret <= 0)                           \
    op;                                 \
}while(0)


//自己定义的输出函数
void my_print(void *data)
{
    printf("%d ", *(int *)data);
}

//自定义的比较函数
int my_cmp(void *key, void *data)
{
    return *(int*)key - *(int *)data;
}

int my_file_store(void *data, FILE *fp)
{
    int ret = 0;

    ret = fwrite(data, sizeof(int), 1, fp);
    printf("====> %d\n", ret);

    return ret;
}

int my_file_load(void *data, FILE *fp)
{
    int ret = 0;

    ret = fread(data, sizeof(int), 1, fp);
    printf("=====> %d\n", ret);

    return ret;
}


int main(void)
{
    int n = 0;
    int index;

    dlist_t *h = NULL;
    dlist_t *d1 = NULL;

    //创建头结点
    h = dlist_create(sizeof(int), NULL);
    if (NULL == h)
        goto err0; 

    while(1)
    {
retry:
        printf("please input a number[-1 quit]:  "); 
        my_scanf(goto retry, "%d", &n);

        if (-1 == n)
            break;

        //尾插  增加新节点
        dlist_append(h, &n);
        //头插
        //dlist_prepend(h, &n);
        //dlist_prepend_v1(h, &n);
    }
    //链表的遍历
    dlist_traverse(h, my_print);

#if 0
    printf("=============test dlist_insert_by_index===============\n");
    printf("please input index and value:    ");
    my_scanf(,"%d  %d", &index, &n);
    dlist_insert_by_index(h, &n, index);
    dlist_traverse(h, my_print);
#endif

#if 0
    printf("===========test dlist_retrieve_by_index===================\n");
    printf("please input an index:   ");
    my_scanf(,"%d", &index);
    dlist_retrieve_by_index(h, &n, index);
    printf("index:  %d ----> %d\n", index, n);
#endif

#if 0
    printf("=============test dlist_find_index_by_key===================\n");
    printf("please input a key:   ");
    my_scanf(,"%d", &n);
    index = dlist_find_index_by_key(h, &n, my_cmp);
    printf("---->  find %d at %d\n", n, index);
#endif


#if 0
    printf("===========test dlist_find_all_index_by_key=====================\n");
    printf("please input a key:   ");
    my_scanf(,"%d", &n);
    d1 = dlist_find_all_index_by_key(h, &n, my_cmp);
    dlist_traverse(d1, my_print);
    dlist_destroy(d1);
#endif

#if 0
    printf("=============test dlist_modify_by_index====================\n");
    printf("please input an index and value:    ");
    my_scanf(,"%d  %d", &index, &n);
    dlist_modify_by_index(h, &n, index);
    dlist_traverse(h, my_print);
#endif 
    
#if 0
    printf("===============test dlist_modify_by_key====================\n");
    printf("please input two numbers key and value:    ");
    my_scanf(, "%d  %d", &index, &n);
    dlist_modify_by_key(h, &index, &n, my_cmp);
    dlist_traverse(h, my_print);
#endif
    
#if 0
    printf("===============test dlist_modify_all_by_key====================\n");
    printf("please input two numbers key and value:    ");
    my_scanf(, "%d  %d", &index, &n);
    dlist_modify_all_by_key(h, &index, &n, my_cmp);
    dlist_traverse(h, my_print);
#endif

#if 0
    printf("===========test dlist_delete_by_index=================\n");
    printf("please input an index:   ");
    my_scanf(,"%d", &index);
    dlist_delete_by_index(h, index);
    dlist_traverse(h, my_print);
#endif 
    
#if 0
    printf("=============test dlist_delete_by_key===================\n");
    printf("please input a key:   ");
    my_scanf(,"%d", &n);
    dlist_delete_by_key(h, &n, my_cmp);
    dlist_traverse(h, my_print);
#endif

#if 0
    printf("=============test dlist_delete_all_by_key===================\n");
    printf("please input a key:   ");
    my_scanf(,"%d", &n);
    dlist_delete_all_by_key(h, &n, my_cmp);
    dlist_traverse(h, my_print);
#endif

#if 0
    printf("=============test dlist_back_traverse====================\n");
    dlist_back_traverse(h, my_print);
#endif
    
    printf("================test dlist_store===========================\n");

    dlist_store(h, "./txt", my_file_store);

    d1 = dlist_create(0, NULL);
    if (NULL == d1)
        goto err0;
    
    dlist_load(d1, "./txt", my_file_load);
    
        
    //遍历链表
    dlist_traverse(d1, my_print);

    dlist_destroy(d1);


    dlist_destroy(h);

    return 0;
err0:
    return -1;
}
