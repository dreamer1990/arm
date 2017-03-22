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
    int *p;
    int i;
    struct page *page;
    printk("test init\n");
    page = alloc_pages(GFP_KERNEL, get_order(1000));    //4K
    if(IS_ERR_OR_NULL(page))
    {
        return -ENOMEM; 
    }

    p = page_address(page);
    if(IS_ERR_OR_NULL(p))
    {
        __free_pages(page, get_order(1000));
        return -ENOMEM;
    }
    
    for(i = 0; i < 1000; i++)
    {
        p[i] = i;
        printk("p[%d] : %d\n", i, p[i]);
    }

    free_pages((unsigned long)p, get_order(1000));
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



