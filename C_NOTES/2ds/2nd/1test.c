#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表节点信息
struct node_t{
	int data;//数据域 用来存储用户数据数据
	struct node_t *next;//指针域 ： 用来存储下一个节点地址
};
int main(void)
{
	struct node_t a = {11, NULL}, d = {44, NULL}, b = {22,NULL},  c = {33, NULL};

	a.next = &b;
	b.next = &c;
	printf("a = %d %p \n", a.data, &a);
	printf("b = %d %p\n", a.next->data, &b);
	printf("c = %d %p\n", a.next->next->data, &c);
	return 0;
}
