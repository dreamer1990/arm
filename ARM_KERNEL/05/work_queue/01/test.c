#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/kthread.h>
#include <linux/slab.h>

#define DEV_NAME    "test-dev"

struct test_dev{
    void *data;
    int num;
};

struct completion com;
struct test_dev tdev;

void func(struct work_struct *d)
{
    printk("func:pid: %d cpu: %d comm: %s\n",
                current->pid,
                current_thread_info()->cpu,
                current->comm);
    msleep(1000);
}

void foo(struct work_struct *d)
{
    printk("foo:pid: %d cpu: %d comm: %s\n",
                current->pid,
                current_thread_info()->cpu,
                current->comm);
    msleep(1000);
}


struct task_struct *task;
struct work_struct work1;
irqreturn_t handler1(int irq, void *dev_id)
{
    printk("handler1\n");
    
    schedule_work(&work1);

    return IRQ_HANDLED;
}

struct work_struct work2;
irqreturn_t handler2(int irq, void *dev_id)
{
    printk("handler2\n");

    schedule_work(&work2);

    return IRQ_HANDLED;
}

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = request_irq(IRQ_EINT(26), handler1, 
                IRQF_TRIGGER_FALLING, 
                "test-key1-handler", &tdev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_request_irq;
    }
    ret = request_irq(IRQ_EINT(27), handler2, 
                IRQF_TRIGGER_FALLING, 
                "test-key2-handler", &tdev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_request_irq;
    }

    INIT_WORK(&work1, func);
    INIT_WORK(&work2, foo);


    return 0;
ERROR_request_irq:
    return ret;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    free_irq(IRQ_EINT(26), &tdev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



