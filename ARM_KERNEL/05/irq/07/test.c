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

void func(void)
{
    printk("func:pid: %d cpu: %d comm: %s\n",
                current->pid,
                current_thread_info()->cpu,
                current->comm);
    msleep(1000);
}

void foo(void)
{
    printk("foo:pid: %d cpu: %d comm: %s\n",
                current->pid,
                current_thread_info()->cpu,
                current->comm);
    msleep(1000);
}

struct __work {
    void (*do_irq_func)(void);
    struct list_head node;
};
LIST_HEAD(__workq);
int test_kthread(void *data)
{
    struct __work *work;
    while(1)
    {
        wait_for_completion(&com);
    
        if(kthread_should_stop())
            break;

        //func();
        
        work = list_first_entry(&__workq, struct __work, node);   
        list_del_init(&work->node);
        work->do_irq_func();
        kfree(work);
    }
    return 0;
}

struct task_struct *task;
irqreturn_t handler1(int irq, void *dev_id)
{
    struct __work *work1 = kzalloc(sizeof(struct __work), GFP_NOWAIT);
    work1->do_irq_func = func;
    INIT_LIST_HEAD(&work1->node);

    list_add_tail(&work1->node, &__workq);
    complete(&com);
    printk("handler1\n");
    return IRQ_HANDLED;
}

irqreturn_t handler2(int irq, void *dev_id)
{
    struct __work *work2 = kzalloc(sizeof(struct __work), GFP_NOWAIT);
    work2->do_irq_func = foo;
    INIT_LIST_HEAD(&work2->node);

    list_add_tail(&work2->node, &__workq);
    complete(&com);

    printk("handler2\n");
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

    task = kthread_run(test_kthread, NULL, "test-kthread");
    if(IS_ERR(task))
    {
        ret = PTR_ERR(task);
        goto ERROR_kthread_create;
    }

    init_completion(&com);

    printk("NR_IRQS: %d\n", NR_IRQS);

    return 0;
ERROR_kthread_create:
    free_irq(IRQ_EINT(26), &tdev);
ERROR_request_irq:
    return ret;
}

void test_exit(void)    //模块拔出时的函数;
{
    int ret;
    printk("test exit\n");
    free_irq(IRQ_EINT(26), &tdev);
    complete_all(&com);
    ret = kthread_stop(task);
    printk("ret: %d\n", ret);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



