#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>

#define DEV_NAME    "test-dev"

irqreturn_t handler(int irq, void *dev_id)
{
    printk("key1 down\n");
    return IRQ_HANDLED;
}

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = request_irq(IRQ_EINT(26), handler, IRQF_TRIGGER_FALLING, "key-handler", NULL);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }

    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    free_irq(IRQ_EINT(26), NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



