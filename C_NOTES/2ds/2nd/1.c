#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t{
	int data;
	struct node_t *next;
};

//有头 无序 不循环 单向链表
int main(void)
{
	int num;
	struct node_t head = {0, NULL};//有头
	struct node_t *new = NULL;
	struct node_t *tail = NULL;


	while(1)
	{
		printf("please input number : ");
		scanf("%d", &num);

		if (num == -1)
		{
			break;
		}

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (new == NULL)
		{
			return -1;
		}

		new->data = num;
		new->next = NULL;
		
		for (tail = &head; tail->next != NULL; tail = tail->next)
			;
		tail->next = new;

	}

	for (tail = head.next; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");
	for (tail = head.next; tail != NULL; tail = new)
	{
		new = tail->next;
		free(tail);
	}

	return 0;
}
