#ifndef __KERNEL_LIST_H__
#define __KERNEL_LIST_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义别名
typedef unsigned long size_t;

typedef void (*op_t)(void *data);

//求结构体成员的偏移量
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)


/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
//根据结构体成员的地址计算出结构体的首地址
#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})


//next是后继指针
//prev是前驱指针
struct list_head {
	struct list_head *next, *prev;
};


//内核链表的尾插
int list_append(struct list_head *h, struct list_head *new);
//内核链表的头插
int list_prepend(struct list_head *h, struct list_head *new);
//内核链表的头插 第二个版本
int list_prepend_v1(struct list_head *h, struct list_head *new);



//内核链表的遍历
int list_traverse(struct list_head *h, op_t my_print);
//链表的销毁
int list_destroy(struct list_head *h, op_t my_destroy);

#endif /*__KERNEL_LIST_H__*/
