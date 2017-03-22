#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/kthread.h>

#define DEV_NAME    "test-dev"

void func(void)
{
    int i;
    for(i = 0; i < 3; i++)
    {
        printk("pid: %d cpu: %d comm: %s\n",
                current->pid,
                current_thread_info()->cpu,
                current->comm);
        //mdelay(1000);
        msleep(1000);
    }

}

int test_thread(void *data)
{
    printk("test thread running \n");

    func();
    return 0;
}

struct task_struct *task;
int test_init(void)
{
    printk("test init\n");
    task = kthread_run(test_thread, NULL, "test-kthread");
    if(IS_ERR(task))
    {
        return PTR_ERR(task);
    }

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



