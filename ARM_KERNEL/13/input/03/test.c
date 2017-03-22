#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/io-mapping.h>
#include <linux/dma-mapping.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/wait.h>
#include <linux/miscdevice.h>
#include <linux/input.h>

#define DRV_NAME    "test-button"

struct input_dev *dev;
irqreturn_t key_handler(int irq, void *dev_value)
{
    input_report_key(dev, KEY_ESC, !gpio_get_value(EXYNOS4_GPX3(2)));
    input_sync(dev);
    return IRQ_HANDLED;
}

void input_dev_init(struct input_dev *dev)
{
    __set_bit(EV_SYN, dev->evbit);
#if 0
    __set_bit(EV_KEY, dev->evbit);
    __set_bit(KEY_ESC, dev->keybit);
#endif
    input_set_capability(dev, EV_KEY, KEY_ESC);
    
}

int test_init(void)
{
    int ret;
    printk("test init\n");
    
    //设置GPX3_2为中断;
    ret = request_irq(IRQ_EINT(26), key_handler, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING, DRV_NAME, NULL);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_request_irq;
    }

    dev = input_allocate_device();
    if(IS_ERR_OR_NULL(dev))
    {
        ret = -ENOMEM;
        goto ERROR_input_alloc;
    }

    input_dev_init(dev);

    ret = input_register_device(dev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_input_register;
    }

    return 0;
ERROR_input_register:
    input_free_device(dev);
ERROR_input_alloc:
    free_irq(IRQ_EINT(26), NULL);   
ERROR_request_irq:
    return ret;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    input_unregister_device(dev);
    input_free_device(dev);
    free_irq(IRQ_EINT(26), NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



