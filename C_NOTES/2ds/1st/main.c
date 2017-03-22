#include "darr.h"

struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	float cn;
	float en;
};

void ls(void *data)
{
	struct cls_t *stu = (struct cls_t *)data;
	
	printf("name : %6s | id : %d | age : %d | sex : %c | cn : %.1f | en : %.1f\n", stu->name, stu->id, stu->age, stu->sex, stu->cn, stu->en);
}
void ls_int(void *data)
{
	printf("%d ", *(int *)data);
}
int cmp_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct cls_t *)d2)->name);
}
int cmp_age(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->age;
}
int cmp_id(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->id;
}
int cmp_sex(void *d1, void *d2)
{
	return *(char *)d1 - ((struct cls_t *)d2)->sex;
}
int cmp_cn(void *d1, void *d2)
{
	float ft;
	#if 0
	 ft = *(float *)d1 - ((struct cls_t *)d2)->cn;
	 if (ft > -0.00001 && ft < 0.000001)
	 {
	 	return 0;
	 }
	 else if (ft > 0.000001)
	 {
	 	return 1;
	 }
	 else
	 {
	 	return -1;
	 }
	#else
		return *(float *)d1 - ((struct cls_t *)d2)->cn;
	#endif
}
int cmp_en(void *d1, void *d2)
{
	return *(float *)d1 - ((struct cls_t *)d2)->en;
}
int sort_id(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->id - ((struct cls_t *)d2)->id;
}
int sort_en(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->en - ((struct cls_t *)d2)->en;
}
int main(int argc, char *argv[])
{
	int i, count = 0;
	DARR *handle = NULL;
	struct cls_t cls, stu  = {"tom", 16010001, 18, 'M', 99, 88};
	struct cls_t *new = NULL, *prev = NULL;
	char name[128];
	char ch = 'M';
	int id;
	int bit;
	//初始化

	if (argc >= 2)
	{
		printf("load data : \n");
		handle = darr_load("./stu.db");
		darr_travel(handle, ls);
	}
	else
	{
		handle = darr_create(sizeof(struct cls_t));
		ERRP(handle == NULL, "darr_create failed", goto ERR1);

		for (i = 0; i < 10; i++)
		{
			snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
			cls.id = 16010000 + rand() % 1000;
			/*cls.id = i + 1;*/
			cls.age = rand() % 3 + 18;
			cls.sex = "MF"[rand() % 2];
			cls.cn = rand() % 20 + 80;
			cls.en = rand() % 30 + 70;
			
			//尾插
			/*darr_append(&cls, handle);*/
			darr_prevend(&cls, handle);
		}
		//遍历
		darr_travel(handle, ls);
		printf("num = %d\n", darr_num(handle));
		printf("================\n");
		darr_sort(handle, sort_en);
		darr_travel(handle, ls);
		darr_store(handle, "./stu.db");
		/*printf("sizeof(struct cls_t) = %d\n", sizeof(struct cls_t));*/
		/*
		 *printf("please input bit : ");
		 *scanf("%d", &bit);
		 *ls(darr_find_index(bit, handle));
		 */
		/*
		 *new = (struct cls_t *)darr_find(&cls.cn, handle, cmp_cn);
		 *if (new == NULL)
		 *{
		 *    printf("no find!\n");
		 *}
		 *else
		 *{
		 *    ls(new);
		 *}
		 */

		/*
		 *printf("please input del name : ");
		 *fgets(name, sizeof(name), stdin);
		 *if (name[strlen(name) - 1] == '\n')
		 *    name[strlen(name) - 1] = '\0';
		 *
		 *ls(darr_find(name, handle, cmp_name));
		 */
		/*
		 *printf("please input bit : ");
		 *scanf("%d", &bit);
		 *darr_del_index(bit, handle);
		 *darr_travel(handle, ls);
		 */
		/*darr_del_all(&ch, handle, cmp_sex);*/
		/*darr_travel(darr_find_all(&ch, handle, cmp_sex), ls);*/
		/*darr_travel(handle, ls);*/
		/*
		 *darr_insert(-1, &stu, handle);
		 *darr_travel(handle, ls);
		 *printf("num = %d\n", darr_num(handle));
		 */
		//销毁
		/*
		 *printf("please input del name : ");
		 *fgets(name, sizeof(name), stdin);
		 *if (name[strlen(name) - 1] == '\n')
		 *    name[strlen(name) - 1] = '\0';
		 */
		/*
		 *printf("please input del id : ");
		 *scanf("%d", &id);
		 *darr_del(&id, handle, cmp_id);
		 *darr_travel(handle, ls);
		 */
	}
	darr_destroy(handle);

	return 0;
ERR1:
	return -1;
}
