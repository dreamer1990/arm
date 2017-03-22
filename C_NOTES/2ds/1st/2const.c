#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 10, b = 20;
	/*const int *p = &a;*///值不可以修改 地址可以修改
	/*int * const p = &a;//指可以修改 地址不可以修改*/
	const int * const p = &a;//指可以修改 地址不可以修改
	

	/*p = &b;*/
	*p = 30;

	return 0;
}
