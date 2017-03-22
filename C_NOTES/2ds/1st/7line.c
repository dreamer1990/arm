#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char buf[128];

	printf("please input string : ");
	/*scanf("%s", buf);*/
	fgets(buf, sizeof(buf), stdin);
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';

	printf("buf = %s\n", buf);
	return 0;
}
