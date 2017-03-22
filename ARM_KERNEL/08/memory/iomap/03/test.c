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
    //struct resource *res;
    printk("test init\n");

/*
    res = request_region(GPM4CON, 8, "GPM4");
    if(IS_ERR_OR_NULL(res))
    {
        return -EBUSY;
    }
*/
    gpm4 = ioremap(GPM4CON, 8);
    if(IS_ERR_OR_NULL(gpm4))
    {
        release_region(GPM4CON, 8);
        return -EBUSY;
    }

    printk("GPIO1: %p [%x]\n", gpm4, ioread32(gpm4));
    iowrite32(ioread32(gpm4) &~ 0xf, gpm4);
    printk("GPIO1: %p [%x]\n", gpm4, ioread32(gpm4));
    
    iounmap(gpm4);
/*
    release_region(GPM4CON, 8);
*/
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



