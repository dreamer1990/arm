#include <linux/module.h>


static int __init test_init(void)
{
    printk("hello kernel\n");

    return 0;
}

static void __exit test_exit(void)
{
    printk("Good bye kernel\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("UPLOOK-aaa");
MODULE_DESCRIPTION("This is a test");
MODULE_LICENSE("GPL");

