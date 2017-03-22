#ifndef __SLIST_H__
#define __SLIST_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define MAGIC "slist"
#define SIZE 32

//函数指针
//void fun(void *data);
typedef void(*op_t)(void* data);
typedef int(*cmp_t)(void *data, void *key);
typedef int(*op_file_t)(void *data, FILE* fp);

//链表结点结构体
typedef struct _node_t {
    void *data;             //数据域 万能型指针 
    struct _node_t *next;   //指针域
}node_t;

//单链表的信息结构体
typedef struct _slist {
    node_t *p;          //指针链表的第一个结点
    int size;           //数据域中数据的大小
    int count;          //元素的个数
    op_t my_destroy;    //销毁函数
}slist_t;

//创建头结点
slist_t* slist_create(int size, op_t destroy);

//返回链表结点的个数
int slist_count(slist_t *s);

//在链表的最后一个结点插入一个新结点    尾插
int slist_append(slist_t* s, void *data);
//在链表的第一个结点前面插入一个结点 头插
int slist_prepend(slist_t* s, void *data);
//将新结点插入到index位置上
int slist_insert_by_index(slist_t *s, void *data, int index);

//检索第index个位置结点中的数据域,保存到data中
int slist_retrieve_by_index(slist_t *s, void *data, int index);

//通过关键字找第一个索引
int slist_find_index_by_key(slist_t *s, void *key, cmp_t my_cmp);
//通过关键字找所有的索引
slist_t *slist_find_all_by_key(slist_t *s, void *key, cmp_t my_cmp);


//通过索引值改对应的数据域
int slist_modify_by_index(slist_t *s, void *key, int index);
//通过关键字改第一个匹配的结点的对应的数据域
int slist_modify_by_key(slist_t *s, void *key, void *data, cmp_t my_cmp);
//通过关键字改所有对应的数据域
int slist_modify_all_by_key(slist_t *s, void *key, void *data, cmp_t my_cmp);


//通过索引删除链表的结点
int slist_delete_by_index(slist_t *s, int index);
//通过关键字删除链表的结点
int slist_delete_by_key(slist_t *s, void *key, cmp_t my_cmp);
//通过关键字删除所有的结点
int slist_delete_all_by_key(slist_t *s,  void *key, cmp_t my_cmp);

//链表的反转
int slist_reverse(slist_t *s);


//将链表数据保存到文件中
int slist_store(slist_t *s, char *path, op_file_t op_file);
//从文件中加载链表数据
slist_t* slist_load(slist_t *s, char *path, op_file_t op_file);


//链表的遍历
int slist_traverse(slist_t* s, op_t my_print);

//链表的销毁
int slist_destroy(slist_t*s);



#endif /*__SLIST_H__*/
