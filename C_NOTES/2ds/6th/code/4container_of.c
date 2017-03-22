#include <stdio.h>

typedef unsigned long size_t;
//计算结构体中变量偏移量的宏
#define offset(type,member)  (unsigned long)(&((type*)0)->member)

#define mycontainer_of(ptr, type, member) (type*)(((void*)ptr) - offset(type, member))

//内核的写法
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)


/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })


struct s_t {
    int i;
    int j;
    char c;
    double d;
};

struct s_t1{
    
    int i;
    char c;
    float f;
    double d;
    char name[32];
    int k;
};

int main(void)
{

    struct s_t s;

    //计算偏移量
    printf("offset j:  %lu\n", offset(struct s_t, j));

    printf("offset d:  %lu\n", offset(struct s_t, d));

    printf("offset d:  %lu\n", offset(struct s_t1, d));
    printf("offset name:  %lu\n", offset(struct s_t1, name));
    printf("offset k:  %lu\n", offset(struct s_t1, k));

    //根据结构体成员的地址 求该结构体的首地址
    printf("&s = %p   container_of:  %p\n", &s, mycontainer_of(&s.d, struct s_t, d));

    printf("&s = %p  kernel_container_of:  %p\n", &s, container_of(&s.d, struct s_t, d));

    return 0;
}
