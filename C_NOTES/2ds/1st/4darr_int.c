#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int num;
	int *new = NULL;
	int count = 0;
	int *prev = NULL;

	//初始化动态数组
	while(1)
	{
		//接受用户输入
		printf("please input %d number : ", count + 1);
		scanf("%d", &num);

		//退出条件
		if (num == -1)
		{
			break;
		}
		//申请空间
		new = (int *)malloc(sizeof(int) * (count + 1));
		if (NULL == new)
		{
			printf("malloc failed!\n");
			return -1;
		}

		memcpy(new, prev, sizeof(int) * count);//拷贝原来数据
		free(prev);
		*(new + count) = num;
		prev = new;
		count++;
	}

	//遍历
	for (i = 0; i < count; i++)
	{
		printf("%d ", new[i]);
	}
	//销毁
	free(new);
	return 0;
}
