#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int count = 0;
	char num;
	char *new = NULL;
	char *prev = NULL;

	//初始化动态数组
	while(1)
	{
		//接受用户输入
		printf("please input %d number : ", count + 1);
		scanf("%c", &num);

		while (getchar() != '\n')
			;
		//退出条件
		if (num == 'q')
		{
			break;
		}
		//申请空间
		new = (char *)malloc(sizeof(char) * (count + 1));
		if (NULL == new)
		{
			printf("malloc failed!\n");
			return -1;
		}

		memcpy(new, prev, sizeof(char) * count);//拷贝原来数据
		free(prev);
		*(new + count) = num;
		prev = new;
		count++;
	}

	//遍历
	for (i = 0; i < count; i++)
	{
		printf("%c ", new[i]);
	}
	putchar(10);
	//销毁
	free(new);
	return 0;
}
