#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	float cn;
	float en;
};

void fanbingbing(void)
{
	printf("范冰冰!\n");
}
void xiaoyanzi(void)
{
	printf("小燕子!\n");
}

void *insert(void *prev, void * date, int *count, int size)
{
	void *new = NULL;

	new = (void *)malloc(size * (*count + 1));
	if (NULL == new)
	{
		return NULL;
	}

	memcpy(new, prev, size * (*count));
	free(prev);
	memcpy(new + (*count) * size, date, size);
	(*count)++;

	return new;
}
int main(void)
{
	int i;
	int num;
	char buf[128];
	int count = 0;
	struct cls_t cls = {"tom", 16010001, 18, 'M', 99, 88};
	/*struct cls_t *new = NULL, *prev = NULL;*/
	int *new = NULL, *prev = NULL;



	/*while(1)*/
	for (i = 0; i < 10; i++)
	{
/*
 *        printf("please input %d name : ", count + 1);
 *        fgets(buf, sizeof(buf), stdin);
 *        if (buf[strlen(buf) - 1] == '\n')
 *            buf[strlen(buf) - 1] = '\0';
 *
 *        if (strcmp(buf, "exit") == 0)
 *        {
 *            break;
 *        }
 *
 *        strcpy(cls.name, buf);
 *        cls.id = 16010000 + rand() % 1000;
 *        cls.age = rand() % 3 + 18;
 *        cls.sex = "MF"[rand() % 2];
 *        cls.cn = rand() % 20 + 80;
 *        cls.en = rand() % 30 + 70;
 */
		num = rand() % 100;
		/*new = insert(new, &cls, &count, sizeof(struct cls_t));*/
		new = insert(new, &num, &count, sizeof(int));
	}
	for (i = 0; i < count; i++)
	{
		/*printf("name : %5s | id : %d | age : %d | sex : %c | cn : %.2f | en : %.2f\n", new[i].name, new[i].id, new[i].age, new[i].sex, new[i].cn, new[i].en);*/
		printf("%d ", new[i]);
	}
	printf("\n");
	free(new);
	return 0;
}
