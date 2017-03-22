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
#include <linux/io.h>
#include <linux/dma-mapping.h>

#define DEV_NAME    "test-dev"

int test_init(void)
{
    void *virt;
    //int i;
    u32 phys;
    printk("test init\n");
    virt = dma_alloc_coherent(NULL, 4096, &phys, GFP_KERNEL);
    if(IS_ERR_OR_NULL(virt))
    {
        return -ENOMEM;
    }

    printk("phys: %x virt: %p\n", phys, virt);
    //*(u32 *)phys = 0x11223344;

    dma_free_coherent(NULL, 4096, virt, phys);

    virt = kmalloc(4096, GFP_KERNEL);
    if(IS_ERR_OR_NULL(virt))
    {
        return -ENOMEM;
    }

    phys = virt_to_phys(virt);

    printk("phys: %x virt: %p\n", phys, virt);

    kfree(virt);
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



