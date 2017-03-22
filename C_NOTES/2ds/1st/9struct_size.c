#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(3)
struct cls_t{
	int age;
	/*short s;*/
	char sex;
};

#pragma pack(0)
struct stu_t{
	int age;
	/*short s;*/
	char sex;
};
int main(void)
{
	printf("sizeof(struct cls_t) = %d\n", sizeof(struct cls_t));
	printf("sizeof(struct stu_t) = %d\n", sizeof(struct stu_t));
	return 0;
}
