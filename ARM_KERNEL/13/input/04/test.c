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
int x = 100;
int y = 200;
irqreturn_t key_handler(int irq, void *dev_value)
{
    int value = gpio_get_value(EXYNOS4_GPX3(2));

    if(value == 0) {
        input_report_abs(dev, ABS_MT_POSITION_X, x);
        input_report_abs(dev, ABS_MT_POSITION_Y, y);
        input_report_abs(dev, ABS_MT_WIDTH_MAJOR, 200);
        input_mt_sync(dev);
    } else {
        //input_report_key(dev, BTN_TOUCH, !value);
        input_report_abs(dev, ABS_MT_WIDTH_MAJOR, 0);
        input_mt_sync(dev);
    }
    input_sync(dev);
    return IRQ_HANDLED;
}

void input_dev_init(struct input_dev *dev)
{
    __set_bit(EV_SYN, dev->evbit);
    input_set_capability(dev, EV_ABS, ABS_MT_POSITION_X);
    input_set_capability(dev, EV_ABS, ABS_MT_POSITION_Y);
    input_set_capability(dev, EV_ABS, ABS_MT_TOUCH_MAJOR);

    input_set_abs_params(dev, ABS_MT_POSITION_X, 0, 800, 0, 0);
    input_set_abs_params(dev, ABS_MT_POSITION_Y, 0, 480, 0, 0);
    input_set_abs_params(dev, ABS_MT_TOUCH_MAJOR, 0, 250, 0, 0);
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



