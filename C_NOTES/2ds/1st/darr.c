#include "darr.h"

//初始化
DARR *darr_create(int size)
{
	DARR *handle = NULL;

	handle = (DARR *)malloc(sizeof(DARR));
	if (handle == NULL)
	{
		printf("malloc handle!\n");
		return NULL;
	}
	handle->data = NULL;
	handle->size = size;
	handle->num = 0;

	return handle;
}
//数据添加到结尾
int darr_append(void *data, DARR *handle)
{
	void *new = NULL;

	new = (void *)malloc(handle->size * (handle->num + 1));
	ERRP(NULL == new, "malloc failed", goto ERR1);

	memcpy(new, handle->data, handle->size * handle->num);
	free(handle->data);
	memcpy(new + handle->size * handle->num, data, handle->size);
	handle->data = new;
	handle->num++;

	return 0;
ERR1:
	return -1;
}
//头插
int darr_prevend(void *data, DARR *handle)
{
	void *new = NULL;

	new = (void *)malloc(handle->size * (handle->num + 1));
	ERRP(NULL == new, "malloc failed", goto ERR1);
	
	memcpy(new, data, handle->size);
	memcpy(new + handle->size, handle->data, handle->size * handle->num);
	free(handle->data);
	handle->data = new;
	handle->num++;

	return 0;
ERR1:
	return -1;
}
//指定位置插入
int darr_insert(int index, void *data, DARR *handle)
{
	void *new = NULL;

	ERRP(index < 0 || index >= handle->num, "index failed!", goto ERR1);
	ERRP(data == NULL, "data failed!", goto ERR1);

	new = (void *)malloc(handle->size * (handle->num + 1));
	ERRP(NULL == new, "malloc failed", goto ERR1);

	memcpy(new, handle->data, handle->size * index);
	memcpy(new + handle->size * index, data, handle->size);
	memcpy(new + handle->size * (index + 1), handle->data + handle->size * index, handle->size * (handle->num - index));
	free(handle->data);
	handle->data = new;
	handle->num++;

	return 0;
ERR1:
	return -1;
}
//求长度
int darr_num(DARR *handle)
{
	return handle->num;
}
//按关键字删除
void darr_del(void *key, DARR *handle, darr_cmp_t *cmp)
{
	int i;
	void *new = NULL;

	ERRP(key == NULL, "option err!", goto ERR1);

	for (i = 0; i < handle->num; i++)
	{
		if (cmp(key, handle->data + i * handle->size) == 0)
		{
			new = (void *)malloc(handle->size * (handle->num - 1));
			ERRP(NULL == new, "malloc failed!", goto ERR1);

			memmove(new, handle->data, handle->size * i);
			memmove(new + handle->size * i, handle->data + handle->size * (i + 1), handle->size * (handle->num - i - 1));
			free(handle->data);
			handle->data = new;
			handle->num--;
			return;
		}
	}
	return ;

ERR1:
	return ;
}
//删除所有
void darr_del_all(void *key, DARR *handle, darr_cmp_t *cmp)
{
	int i;
	void *new = NULL;

	for (i = 0; i < handle->num; i++)
	{
		if (cmp(key, handle->data + handle->size * i) == 0)
		{
			new = (void *)malloc(handle->size * (handle->num - 1));
			ERRP(new == NULL, "malloc failed!", goto ERR1);
			
			memmove(new, handle->data, handle->size * i);
			memmove(new + handle->size * i, handle->data + handle->size * (i + 1), handle->size * (handle->num - i - 1));
			free(handle->data);
			handle->data = new;
			handle->num--;
			i--;
		}
	}
	return ;
ERR1:
	return ;
}
//按指定位置删除
void darr_del_index(int index, DARR *handle)
{
	void *new = NULL;

	ERRP(index < 0 || index >= handle->num, "darr_del_index option err!\n", goto ERR1);

	new = (void *)malloc(handle->size * (handle->num - 1));
	ERRP(NULL == new, "malloc", goto ERR1);

	memmove(new, handle->data, handle->size * index);
	memmove(new + handle->size * index, handle->data + handle->size * (index + 1), handle->size * (handle->num - index - 1));
	free(handle->data);
	handle->data = new;
	handle->num--;

	return ;
ERR1:
	return ;
}
//查找第一个匹配　 strchr strrchr
void *darr_find(void *key, DARR *handle, darr_cmp_t *cmp)
{
	int i;

	for (i = 0; i < handle->num; i++)
	{
		if (!cmp(key, handle->data + handle->size * i))
		{
			return handle->data + handle->size * i;
		}
	}

	return 0;
}
//查找所有匹配信息
DARR *darr_find_all(void *key, DARR *handle, darr_cmp_t *cmp)
{
	DARR *ind = NULL;
	int i;

	ind = darr_create(handle->size);
	ERRP(ind == NULL, "darr_create failed!\n", goto ERR1);

	for (i = 0; i< handle->num; i++)
	{
		if (!cmp(key, handle->data + handle->size * i))
		{
			darr_append(handle->data + i * handle->size, ind);
		}
	}
	return ind;
ERR1:
	return NULL;
}
//指定位置查找
void *darr_find_index(int index, DARR *handle)
{
	printf("handle->num = %d\n", handle->num);
	printf("index = %d\n", index);
	if (index < 0)
	{
		return handle->data;
	}
	else if (index >= handle->num)
	{
		return handle->data + handle->size * (handle->num - 1);
	}
	else
	{
		return handle->data + handle->size * index;
	}
}
//排序
void darr_sort(DARR *handle, darr_cmp_t *cmp)
{
	int i, j;
	void *temp = NULL;

	temp = (void *)malloc(handle->size);
	ERRP(temp == NULL, "malloc temp failed!\n", goto ERR1);

	for (i = 0; i < handle->num - 1; i++)
	{
		for (j = i + 1; j < handle->num; j++)
		{
			if (cmp(handle->data + i * handle->size, handle->data + j * handle->size) > 0)
			{
				memmove(temp, handle->data + i * handle->size, handle->size);
				memmove(handle->data + i * handle->size, handle->data + j * handle->size, handle->size);
				memmove(handle->data + j * handle->size,temp, handle->size);
			}
		}
	}
	return ;
ERR1:
	return ;
}
//存储
void darr_store(DARR *handle, const char *path)
{
	FILE *fp = NULL;
	int ret;

	fp = fopen(path, "w");//"w", 'w'
	ERRP(fp == NULL, "fopen failed!\n", goto ERR1);

	// size:
	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	ERRP(ret != 1, "fwrite size failed!\n", goto ERR2);
	//num
	ret = fwrite(&handle->num, sizeof(handle->num), 1, fp);
	ERRP(ret != 1, "fwrite size failed!\n", goto ERR2);

	//fwrite fread

	ret = fwrite(handle->data, handle->size, handle->num, fp);
	ERRP(ret != handle->num, "fwrite failed!\n", goto ERR2);

	fclose(fp);
	return ;
ERR2:
	fclose(fp);
ERR1:
	return ;
}
//加载
DARR *darr_load(const char *path)
{
	DARR *handle = NULL;
	FILE *fp = NULL;
	int size,num;
	int ret;

	fp = fopen(path, "r");
	ERRP(fp == NULL, "fopen failed!\n", goto ERR1);

	//read size
	ret = fread(&size, sizeof(size), 1, fp);
	/*printf("size : ret = %d size = %d\n", ret, size);*/
	ERRP(ret != 1, "fread size failed!\n", goto ERR2);
	
	//read num
	ret = fread(&num, sizeof(num), 1, fp);
	/*printf("num : ret = %d num = %d\n", ret, num);*/
	ERRP(ret != 1, "fread num failed!\n", goto ERR2);

	handle = darr_create(size);
	ERRP(handle == NULL, "darr_create failed!\n", goto ERR2);

	handle->num = num;

	handle->data = (void *)malloc(size * num);
	ERRP(handle->data == NULL, "malloc data failed!\n", goto ERR3);

	ret = fread(handle->data, size, num, fp);
	ERRP(ret != num, "fwrite data failed!\n", goto ERR4);

	fclose(fp);
	return handle;
ERR4:
	free(handle->data);
ERR3:
	free(handle);
ERR2:
	fclose(fp);
ERR1:
	return NULL;
}
//遍历
void darr_travel(DARR *handle, darr_op_t *op)
{
	int i;
	for (i = 0; i < handle->num; i++)
	{
		op(handle->data + i * handle->size);
	}
}
//销毁
void darr_destroy(DARR *handle)
{
	free(handle->data);
	free(handle);
}
