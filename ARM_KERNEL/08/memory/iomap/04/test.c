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
#include <linux/ioport.h>

#define DEV_NAME    "test-dev"

#define GPM4CON       0x110002e0

int test_init(void)
{
    u32 *gpm4;
    void *virt;
    u32 phys;
    printk("test init\n");

    virt = kmalloc(4096, GFP_KERNEL);
    if(IS_ERR_OR_NULL(virt))
    {
        return -ENOMEM;
    }

    phys = virt_to_phys(virt);
    printk("phys: %x virt: %p\n", phys, virt);

    gpm4 = ioremap(phys, 8);
    if(IS_ERR_OR_NULL(gpm4))
    {
        release_region(GPM4CON, 8);
        return -EBUSY;
    }

    printk("gpm4: %p virt: %p\n", gpm4, virt);
    
    iounmap(gpm4);
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



