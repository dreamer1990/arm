#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char s1[128] = "hello";
	char s2[128];
	int arr[10] = {1,2,3,4,5,44,6,7};

	memset(arr, 0xff, sizeof(arr));

	for (i = 0; i < 10; i++)
	{
		printf("arr[%d] = %#x\n", i, arr[i]);
	}
    /*
	 *printf("s1 = %s\n", s1);
	 *printf("s1 = %s\n", s1);
     */
	/*memcpy(s1 + 3, s1 + 2, strlen(s1 + 2) + 1);*/
	/*memmove(s1 + 3, s1 + 2, strlen(s1 + 2) + 1);*/
	/*memmove(s2, s1, strlen(s1) + 1);*/

	return 0;
}
