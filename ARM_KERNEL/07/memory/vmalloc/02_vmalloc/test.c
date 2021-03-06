#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

#define DEV_NAME    "test-dev"

int test_init(void)
{
    int *p;
    int i;
    printk("test init\n");
    p = vmalloc(1000);  //开辟空间, 没有足够空间阻塞等待;
    if(IS_ERR_OR_NULL(p))
    {
        return -ENOMEM;
    }

/*
    for(i = 0; i < 250; i++)
    {
        p[i] = i;
        printk("p[%d] : %d\n", i, p[i]);
    }
*/
    printk("p: %p\n", p);
    vfree(p);

    p = vmalloc(1000);  //开辟空间, 没有足够空间阻塞等待;
    if(IS_ERR_OR_NULL(p))
    {
        return -ENOMEM;
    }
    printk("p: %p\n", p);
    vfree(p);

    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



