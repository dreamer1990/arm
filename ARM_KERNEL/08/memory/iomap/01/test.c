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

#include <plat/map-base.h>
#include <plat/map-s5p.h>
#include <mach/map.h>

#define DEV_NAME    "test-dev"

//#define PA_CHIPID
//EXYNOS_PA_CHIPID

int test_init(void)
{
    u32 *chipid;
    printk("test init\n");

    chipid = ioremap(EXYNOS_PA_CHIPID, 8);
    if(IS_ERR_OR_NULL(chipid))
    {
        return -EBUSY;
    }

    printk("CHIPID: %p [%x]\n", chipid, *chipid);
    printk("CHIPID: %x [%x]\n", S5P_VA_CHIPID, *(unsigned int *)S5P_VA_CHIPID);
    
    iounmap(chipid);
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



