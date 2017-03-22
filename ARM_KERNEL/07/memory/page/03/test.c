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
    int *virt;
    struct page *page;
    printk("test init\n");
    page = alloc_pages(GFP_KERNEL, get_order(1000));    //4K
    if(IS_ERR_OR_NULL(page))
    {
        return -ENOMEM; 
    }

    virt = page_address(page);
    printk("virt   : %p\n", virt);
    printk("page   : %p\n", page);
    printk("pfn    : %lx\n", page_to_pfn(page));
    printk("phys   : %x\n", page_to_phys(page));
    printk("phys_to_virt: %p\n", phys_to_virt(page_to_phys(page)));

    //page : 4K     mem_map[pfn]    
    //phys : pfn << PAGE_SHIFT
    //virt : phys + 0x80000000

    free_pages((unsigned long)virt, get_order(1000));
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



