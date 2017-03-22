#ifndef __D_LIST_H__
#define __D_LIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义魔法数字
#define MAGIC "DLIST"

//opt_t是函数指针类型
typedef void (*op_t)(void *data);
typedef int(*op_cmp_t)(void *key, void *data);
//操作文件的函数指针类型
typedef int(*op_file_t)(void *data, FILE* fp);

typedef struct _node_t{
    void *data;             //数据域
    struct _node_t *prev;   //前驱指针
    struct _node_t *next;   //后继指针
}node_t;


//信息结构体
typedef struct _dlist_t{
    node_t *p;          //指向链表的第一个节点
    int size;           //每个节点的大小
    int count;          //节点个数
    op_t my_destroy;    //自定义的销毁函数
}dlist_t;

//创建头结点
dlist_t* dlist_create(int size, op_t my_destroy);
//尾插  添加链表节点
int dlist_append(dlist_t* h, void *data);
//头插  添加链表节点
int dlist_prepend(dlist_t* h, void *data);
//头插  添加链表节点  版本二
int dlist_prepend_v1(dlist_t* h, void *data);

//返回节点的个数
int dlist_count(dlist_t* h);

//通过索引插入指定的节点
int dlist_insert_by_index(dlist_t* h, void *data, int index);

//通过索引找对应的数据域 将数据保存到data中
int dlist_retrieve_by_index(dlist_t* h, void *data, int index);

//通过关键字找第一个索引
int dlist_find_index_by_key(dlist_t* h, void *key, op_cmp_t my_cmp);
//通过关键字找到所有的索引
dlist_t* dlist_find_all_index_by_key(dlist_t* h, void *key, op_cmp_t my_cmp);

//通过索引修改对应的数据
int dlist_modify_by_index(dlist_t* h, void *data, int index);
//通过关键字修改第一个数据
int dlist_modify_by_key(dlist_t* h, void *key, void *data, op_cmp_t my_cmp);
//通过关键字修改所有的数据
int dlist_modify_all_by_key(dlist_t* h, void *key, void *data, op_cmp_t my_cmp);

//通过索引删除节点
int dlist_delete_by_index(dlist_t *h, int index);
//通过关键字删除一个节点
int dlist_delete_by_key(dlist_t *h, void *key, op_cmp_t my_cmp);
//通过关键字删除所有的节点
int dlist_delete_all_by_key(dlist_t *h, void *key, op_cmp_t my_cmp);

//将链表数据保存到文件中
int dlist_store(dlist_t *h, char* path, op_file_t op_file);
//从文件中加载链表信息
int dlist_load(dlist_t *h, char *path, op_file_t op_file);



//链表的逆向遍历
int dlist_back_traverse(dlist_t* h, op_t my_print);
//链表的遍历
int dlist_traverse(dlist_t* h, op_t my_print);
//链表的销毁
int dlist_destroy(dlist_t* h);


#endif/*__D_LIST_H__*/
