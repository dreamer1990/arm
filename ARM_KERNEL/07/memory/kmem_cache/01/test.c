#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/pagemap.h>

#define DEV_NAME    "test-dev"

int test_init(void)
{
    int i;
    int *p[10];
    struct kmem_cache *kmem;
    printk("test init\n");
    kmem = kmem_cache_create("test-cache", 32, 0, SLAB_HWCACHE_ALIGN, NULL);
    if(IS_ERR_OR_NULL(kmem))
    {
        return -ENOMEM; 
    }

    for(i = 0; i < 10; i++)
    {
        p[i] = kmem_cache_alloc(kmem, GFP_KERNEL);
        if(IS_ERR_OR_NULL(p[i]))
        {
            kmem_cache_destroy(kmem);
            return -ENOMEM; 
        }

        printk("p[%d] : %p\n", i, p[i]); 
    }

    for(i = 0; i < 10; i++)
        kmem_cache_free(kmem, p[i]);

    kmem_cache_destroy(kmem);
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



