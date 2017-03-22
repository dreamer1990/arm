#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#define DEV_NAME    "func-dev"

struct test_dev{
    void *data;
    int num;
};
struct test_dev tdev;

irqreturn_t handler(int irq, void *dev_id)
{
    if(gpio_get_value(EXYNOS4_GPX3(2)) == 0)
    {
        printk("func-key1 down\n");
    }
    else
    {
        printk("func-key1 up\n");
    }
    return IRQ_HANDLED;
}

int func_init(void)
{
    int ret;
    printk("func init\n");
    ret = request_irq(IRQ_EINT(26), handler, 
                IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING | IRQF_SHARED, 
                "func-key-handler", &tdev);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }

    return 0;
}

void func_exit(void)    //模块拔出时的函数;
{
    printk("func exit\n");
    free_irq(IRQ_EINT(26), &tdev);
}

module_init(func_init);
module_exit(func_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



