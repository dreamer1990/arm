#ifndef __DARR_H__
#define __DARR_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//容错宏
#define ERRP(con, func, ret) do{		\
					if(con)				\
					{					\
						printf(func);	\
						ret;			\
					}					\
				}while(0)

//定义函数指针
typedef void (darr_op_t)(void *);
typedef int (darr_cmp_t)(void *, void *);

//抽象数据类型
typedef struct darr_t{
	void *data;//数据
	int size;//类型
	int num;//大小
}DARR;

//函数声明
DARR *darr_create(int size);//初始化
int darr_append(void *data, DARR *handle);//尾插
int darr_prevend(void *data, DARR *handle);//头插
int darr_insert(int index, void *data, DARR *handle);//指定位置插入
int darr_num(DARR *handle);//求长度
void darr_del(void *key, DARR *handle, darr_cmp_t *cmp);//按关键子删除
void darr_del_all(void *key, DARR *handle, darr_cmp_t *cmp);//删除所有
void darr_del_index(int index, DARR *handle);//指定位置删除

void *darr_find(void *key, DARR *handle, darr_cmp_t *cmp);//查找匹配信息
DARR *darr_find_all(void *key, DARR *handle, darr_cmp_t *cmp);//查找所有匹配信息
void *darr_find_index(int index, DARR *handle);//指定位置查找

void darr_sort(DARR *handle, darr_cmp_t *cmp);//排序
void darr_store(DARR *handle, const char *path);//存储
DARR *darr_load(const char *path);//加载
void darr_travel(DARR *handle, darr_op_t *op);//遍历
void darr_destroy(DARR *handle);//销毁

#endif /*DARR_H*/
