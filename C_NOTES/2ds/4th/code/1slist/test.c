#include "slist.h"

#define my_scanf(op, format, ...)       do{     \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)

//打印数据的函数  int
void my_print(void *data)
{
    printf("%d ", *(int*)data);
}

//自定义的比较函数
int my_cmp(void *data, void *key)
{
    return *(int *)data - *(int *)key;
}

int store_file(void *data, FILE* fp)
{
    int ret = 0;

    //自己定义的回调函数 int
    ret = fwrite(data, sizeof(int), 1, fp);
    if (ret <= 0)
    {
        printf("fwrite failed...\n"); 
        goto err0;
    }
    
    return 0;
err0:
    return -1;
}

int load_file(void *data, FILE* fp)
{
    int ret = 0;

    ret = fread(data, sizeof(int), 1, fp);
    if (ret <= 0)
        goto err0;

    return ret;
err0:
    return -1;
}


int main(void)
{
    int n = 0;
    int index;

    slist_t *head = NULL;
    slist_t *s1 = NULL;
    //创建头结点
    head =  slist_create(sizeof(int), NULL);
    if (NULL == head)
        goto err0;

    while(1)
    {
    retry:
        printf("please input a number[-1  quit]:    "); 

        my_scanf(goto retry, "%d", &n);

        //结束循环
        if (-1 == n)
            break;
        //slist_prepend(head, &n);
        slist_append(head, &n);
    }

    slist_traverse(head, my_print);
    printf("=======> count:  %d\n", slist_count(head));
    
#if 0
    printf("=========test slist_insert_by_index==================\n");
    printf("please input n and index:    ");
    my_scanf(,"%d %d", &n, &index);
    slist_insert_by_index(head, &n, index);
    slist_traverse(head, my_print);
    printf("=========> count:  %d\n", slist_count(head));
#endif
    
#if 0
    printf("=========test slist_retrieve_by_index===============\n");
    printf("please input an index:   ");
    my_scanf(,"%d", &index);
    slist_retrieve_by_index(head, &n, index);
    printf("=========retrieve:  n---> %d\n", n);
#endif

#if 0
    printf("===========test slist_find_index_by_key===============\n");
    printf("please input a key:   ");
    my_scanf(,"%d", &n);
    index = slist_find_index_by_key(head, &n, my_cmp);
    printf("find key: %d  ---> index: %d\n", n, index);
#endif

#if 0
    printf("=========test slist_find_all_by_key================\n");
    printf("please input a key:   ");
    my_scanf(,"%d", &n);
    s1 = slist_find_all_by_key(head, &n, my_cmp);
    slist_traverse(s1, my_print);
    slist_destroy(s1);
#endif
#if 0
    printf("==========test slist_modify_by_key==============\n");
    printf("please input key and value:   ");
    my_scanf(,"%d  %d", &n, &index);

    slist_modify_by_key(head, &n, &index, my_cmp);
    slist_traverse(head, my_print);
#endif

#if 0
    printf("==========test slist_modify_all_by_key==============\n");
    printf("please input key and value:   ");
    my_scanf(,"%d  %d", &n, &index);

    slist_modify_all_by_key(head, &n, &index, my_cmp);
    slist_traverse(head, my_print);
#endif

#if 0
    printf("=========test slist_modify_by_index==============\n");
    printf("please input a key and index:   ");
    my_scanf(,"%d  %d", &n, &index);
    slist_modify_by_index(head, &n, index);
    slist_traverse(head, my_print);
#endif

#if 0
    printf("=========test slist_delete_by_index==============\n");
    printf("please input an index:   ");
    my_scanf(,"%d", &index);
    slist_delete_by_index(head, index);
    slist_traverse(head, my_print);
#endif
    
#if 0
    printf("==========test slist_delete_by_key================\n");
    while(1)
    {
        printf("please input a key[-1 quit]:   ");
        my_scanf(,"%d", &n);
        if (-1 == n)
            break;
        slist_delete_by_key(head, &n, my_cmp);
    }
    slist_traverse(head, my_print);
#endif
    
#if 0
    printf("============test slist_delete_all_by_key=============\n");
    printf("please input a key:   ");
    my_scanf(,"%d", &n);
    slist_delete_all_by_key(head, &n, my_cmp);
    slist_traverse(head, my_print);
#endif

#if 0
    printf("============test slist_reverse==============\n");
    slist_reverse(head);
    slist_traverse(head, my_print);
#endif

    slist_store(head, "./txt", store_file);

    printf("========================\n");
    s1 = slist_load(head, "./txt", load_file);
    slist_traverse(s1, my_print);
    slist_destroy(s1);


    slist_destroy(head);
    head = NULL;

    return 0;
err0:
    return -1;
}

