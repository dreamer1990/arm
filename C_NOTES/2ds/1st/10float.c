#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	float f = 0;
// - 0.000001 0.000001
	if (f > -0.000001 && f < 0.000001)
	{
		printf("hello!\n");
	}
	return 0;
}
