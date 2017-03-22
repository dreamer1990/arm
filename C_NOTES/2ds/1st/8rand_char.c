#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	/*char buf[] = "abcdefghijklmnopqrstuvwxyz";*/
	while(1)
	{
		putchar("abcdefghijklmnopqrstuvwxyz"[rand() % 26]);
		usleep(100000);
		fflush(NULL);
	}
	return 0;
}
