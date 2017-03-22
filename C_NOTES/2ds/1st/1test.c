#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(void)
{
	static int count = 5;

	if (count == 0)
	{
		return ;
	}
	count--;
	printf("test! count = %p\n", &count);
	test();
}
int main(void)
{
	test();
	return 0;
}
