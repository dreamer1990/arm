/*
 * linux/drivers/char/tiny4412_pwm.c
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/fb.h>
#include <linux/backlight.h>
#include <linux/err.h>
#include <linux/pwm.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>
#include <linux/delay.h>

#include <linux/gpio.h>
#include <linux/proc_fs.h>

#include <mach/gpio.h>
#include <plat/gpio-cfg.h>
#include <plat/map-base.h>
#include <plat/regs-timer.h>


#define DEVICE_NAME				"pwm"

#define PWM_IOCTL_SET_FREQ		1
#define PWM_IOCTL_STOP			0

#define NS_IN_1HZ				(1000000000UL)


#define BUZZER_PWM_ID			0
#define BUZZER_PMW_GPIO			EXYNOS4_GPD0(0)

static struct pwm_device *pwm4buzzer;

static struct semaphore lock;

static struct proc_dir_entry *proc_entry;

static void pwm_set_freq(unsigned long freq) {
	int period_ns = NS_IN_1HZ / freq;

	pwm_config(pwm4buzzer, period_ns / 2, period_ns);
	pwm_enable(pwm4buzzer);

	s3c_gpio_cfgpin(BUZZER_PMW_GPIO, S3C_GPIO_SFN(2));
}

static void pwm_stop(void) {
	s3c_gpio_cfgpin(BUZZER_PMW_GPIO, S3C_GPIO_OUTPUT);

	pwm_config(pwm4buzzer, 0, NS_IN_1HZ / 100);
	pwm_disable(pwm4buzzer);
}


static int tiny4412_pwm_open(struct inode *inode, struct file *file) {
	if (!down_trylock(&lock))
		return 0;
	else
		return -EBUSY;
}

static int tiny4412_pwm_close(struct inode *inode, struct file *file) {
	up(&lock);
	return 0;
}

static long tiny4412_pwm_ioctl(struct file *filep, unsigned int cmd,
		unsigned long arg)
{
	switch (cmd) {
		case PWM_IOCTL_SET_FREQ:
			if (arg == 0)
				return -EINVAL;
			pwm_set_freq(arg);
			break;

		case PWM_IOCTL_STOP:
		default:
			pwm_stop();
			break;
	}

	return 0;
}


static struct file_operations tiny4412_pwm_ops = {
	.owner			= THIS_MODULE,
	.open			= tiny4412_pwm_open,
	.release		= tiny4412_pwm_close, 
	.unlocked_ioctl	= tiny4412_pwm_ioctl,
};

static struct miscdevice tiny4412_misc_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &tiny4412_pwm_ops,
};

int count = 0;
int arg = 1;
irqreturn_t timer_handler(int irqnum, void *data)
{
    //printk("irqnum: %d timer out [%d]\n", irqnum, ++count);
    __set_bit(5, S3C64XX_TINT_CSTAT);
    return IRQ_HANDLED;
}

int test_read_proc(char *page, char **start, off_t off,
      int count, int *eof, void *data)
{
    int ret;
    ret = sprintf(page, "pwm timer feq: %dHZ\n", arg);
    return ret;
}


int test_write_proc(struct file *file, const char __user *buffer,
             unsigned long count, void *data)
{
    if(!strncmp(buffer, "on", 2))
    {
        pwm_set_freq(arg);        
    }
    else if(!strncmp(buffer, "off", 3))
    {
        pwm_stop();
    }
    else if(!strncmp(buffer, "add", 3))
    {
        pwm_stop();
        arg *= 2;
        pwm_set_freq(arg);        
    }
    else if(!strncmp(buffer, "sub", 3))
    {
        pwm_stop();
        if(arg > 1)
            arg /= 2;
        pwm_set_freq(arg);        
    }
    return count;
}


static int __init tiny4412_pwm_dev_init(void) {
	int ret;

	ret = gpio_request(BUZZER_PMW_GPIO, DEVICE_NAME);
	if (ret) {
		printk("request GPIO %d for pwm failed\n", BUZZER_PMW_GPIO);
        goto ERROR_gpio;
	}

	gpio_set_value(BUZZER_PMW_GPIO, 0);
	s3c_gpio_cfgpin(BUZZER_PMW_GPIO, S3C_GPIO_OUTPUT);


	pwm4buzzer = pwm_request(BUZZER_PWM_ID, DEVICE_NAME);
	if (IS_ERR(pwm4buzzer)) {
		printk("request pwm %d for %s failed\n", BUZZER_PWM_ID, DEVICE_NAME);
		ret = -ENODEV;
        goto ERROR_pwm;
	}

	pwm_stop();

	sema_init(&lock, 1);
	ret = misc_register(&tiny4412_misc_dev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_misc;
    }

    ret = request_irq(IRQ_TIMER0, timer_handler, IRQF_TRIGGER_NONE, 
                DEVICE_NAME, pwm4buzzer);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_irq;
    }

	printk(DEVICE_NAME "\tinitialized\n");

    proc_entry = create_proc_entry(DEVICE_NAME, 0777, NULL);
    if(IS_ERR(proc_entry))
    {
        ret = PTR_ERR(proc_entry);
        goto ERROR_proc; 
    }
    proc_entry->read_proc = test_read_proc;
    proc_entry->write_proc = test_write_proc;

	return ret;
ERROR_proc:
    free_irq(IRQ_TIMER0, pwm4buzzer);
ERROR_irq:
    misc_deregister(&tiny4412_misc_dev);
ERROR_misc:
    pwm_free(pwm4buzzer);
ERROR_pwm:
    gpio_free(BUZZER_PMW_GPIO);
ERROR_gpio:
    return ret;
}

static void __exit tiny4412_pwm_dev_exit(void) {
	pwm_stop();

    remove_proc_entry(DEVICE_NAME, NULL);
    free_irq(IRQ_TIMER0, pwm4buzzer);
	misc_deregister(&tiny4412_misc_dev);
    pwm_free(pwm4buzzer);
	gpio_free(BUZZER_PMW_GPIO);
}

module_init(tiny4412_pwm_dev_init);
module_exit(tiny4412_pwm_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FriendlyARM Inc.");
MODULE_DESCRIPTION("Exynos4 PWM Driver");

