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

#define DRV_NAME    "test-button"

bool stat;
char drv_buf[20];
int count = 0;
wait_queue_head_t wq;
ssize_t test_read (struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
    int ret;
    
    if(count == 0)
    {
        if(wait_event_interruptible(wq, count))
            return -ERESTARTSYS;
    }

    if(stat)
        sprintf(drv_buf, "up");
    else
        sprintf(drv_buf, "down");
    ret = copy_to_user(buf, drv_buf, 20);
    count = 0;
    return 20 - ret;
}

int test_open (struct inode *inode, struct file *filp)
{
    count = 0;
    stat = false;
    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    return 0;
}


struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = test_open,
    .release = test_close,
    .read = test_read,
};

struct miscdevice misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DRV_NAME, 
    .fops = &fops,
};

irqreturn_t key_handler(int irq, void *dev)
{
    //if(gpio_direction_input(EXYNOS4_GPX3(2)))   //设置成输入, 并且读出结果;
    if(gpio_get_value(EXYNOS4_GPX3(2)))
        stat = true;
    else
        stat = false;
    wake_up(&wq);
    count ++;
    return IRQ_HANDLED;
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

    ret = misc_register(&misc);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_misc;
    }

    init_waitqueue_head(&wq);

    return 0;
ERROR_misc:
    free_irq(IRQ_EINT(26), NULL);   
ERROR_request_irq:
    return ret;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    misc_deregister(&misc);
    free_irq(IRQ_EINT(26), NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



