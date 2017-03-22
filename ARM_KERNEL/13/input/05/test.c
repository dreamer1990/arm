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
#include <linux/i2c.h>
#include "ft5x06_ts.h"

#include <plat/gpio-cfg.h>
#include <plat/ft5x0x_touch.h>

#define DRV_NAME    "test-button"

int read_i2c_data(struct ft5x0x_ts_data *ts)
{
    struct ft5x0x_event *event = &ts->event;
    u8 buf[32] = { 0 };
    int ret;
    struct i2c_msg msgs[] = {
        {
            .addr   = ts->client->addr,        
            .flags  = 0,
            .len    = 1,                    
            .buf    = buf,
        },
        {
            .addr   = ts->client->addr,
            .flags  = I2C_M_RD,
            .len    = 31,
            .buf    = buf,
        },
    };

    ret = i2c_transfer(ts->client->adapter, msgs, 2);
    if (ret < 0) {
        printk("%s: read touch data failed, %d\n", __func__, ret);
        return ret;
    }

    memset(event, 0, sizeof(struct ft5x0x_event));

    event->touch_point = buf[2] & 0xf;
    if(event->touch_point > 5 || event->touch_point < 0)
    {
        printk("%s: invalid touch data, %d\n", __func__, event->touch_point);
        return -1;
    }

    switch(event->touch_point)
    {
        case 5:
            event->x[4] = (s16)(buf[0x1b] & 0x0F)<<8 | (s16)buf[0x1c];
            event->y[4] = (s16)(buf[0x1d] & 0x0F)<<8 | (s16)buf[0x1e];
        case 4:
            event->x[3] = (s16)(buf[0x15] & 0x0F)<<8 | (s16)buf[0x16];
            event->y[3] = (s16)(buf[0x17] & 0x0F)<<8 | (s16)buf[0x18];
        case 3:
            event->x[2] = (s16)(buf[0x0f] & 0x0F)<<8 | (s16)buf[0x10];
            event->y[2] = (s16)(buf[0x11] & 0x0F)<<8 | (s16)buf[0x12];
        case 2:
            event->x[1] = (s16)(buf[0x09] & 0x0F)<<8 | (s16)buf[0x0a];
            event->y[1] = (s16)(buf[0x0b] & 0x0F)<<8 | (s16)buf[0x0c];
        case 1:
            event->x[0] = (s16)(buf[0x03] & 0x0F)<<8 | (s16)buf[0x04];
            event->y[0] = (s16)(buf[0x05] & 0x0F)<<8 | (s16)buf[0x06];
            break;
        case 0:
            input_mt_sync(ts->input_dev);
            input_sync(ts->input_dev);
            return -1; 
    }

    event->pressure = 200;
    return 0;
}

void report_input_data(struct ft5x0x_ts_data *ts)
{
    struct ft5x0x_event *event = &ts->event;
    int i;
    //printk("report input data\n");
    for(i = 0; i < event->touch_point; i++)
    {
        input_report_abs(ts->input_dev, ABS_MT_POSITION_X, event->x[i]);
        input_report_abs(ts->input_dev, ABS_MT_POSITION_Y, event->y[i]);
        input_report_abs(ts->input_dev, ABS_MT_TOUCH_MAJOR, event->pressure);
        input_report_abs(ts->input_dev, ABS_MT_TRACKING_ID, i);
        input_mt_sync(ts->input_dev);
    }
    input_sync(ts->input_dev);
}

void input_dev_init(struct ft5x0x_ts_data *ts)
{
    struct input_dev *dev = ts->input_dev;

    __set_bit(EV_SYN, dev->evbit);
    input_set_capability(dev, EV_ABS, ABS_MT_POSITION_X);
    input_set_capability(dev, EV_ABS, ABS_MT_POSITION_Y);
    input_set_capability(dev, EV_ABS, ABS_MT_TOUCH_MAJOR);
    input_set_capability(dev, EV_ABS, ABS_MT_TRACKING_ID);

    input_set_abs_params(dev, ABS_MT_POSITION_X, 0, ts->screen_max_x, 0, 0);
    input_set_abs_params(dev, ABS_MT_POSITION_Y, 0, ts->screen_max_y, 0, 0);
    input_set_abs_params(dev, ABS_MT_TOUCH_MAJOR, 0, ts->pressure_max, 0, 0);
    input_set_abs_params(dev, ABS_MT_TRACKING_ID, 0, FT5X0X_PT_MAX, 0, 0);
}

void test_ts_work(struct work_struct *work)
{
    struct ft5x0x_ts_data *ts = container_of(work, struct ft5x0x_ts_data, work);  
    //printk("test ts work\n");
    
    if(!read_i2c_data(ts))
        report_input_data(ts);

    enable_irq(gpio_to_irq(ts->gpio_irq));
}

irqreturn_t test_ts_handler(int irq, void *data)
{
    struct ft5x0x_ts_data *ts = data;

    //printk("test ts handler\n");
    disable_irq_nosync(irq);
    schedule_work(&ts->work);

    return IRQ_HANDLED;
}

int test_ts_probe(struct i2c_client *client, const struct i2c_device_id *id_table)
{
    int ret;
    struct ft5x0x_ts_data *ts;
    struct ft5x0x_i2c_platform_data *pdata = client->dev.platform_data;
    printk("test ts probe\n");

    ts = kzalloc(sizeof(struct ft5x0x_ts_data), GFP_KERNEL);
    if(IS_ERR_OR_NULL(ts))
    {
        ret = -ENOMEM;
        goto ERROR_kzalloc;
    }

    i2c_set_clientdata(client, ts);

    ts->client = client;
    ts->screen_max_x = pdata->screen_max_x;
    ts->screen_max_y = pdata->screen_max_y;
    ts->pressure_max = pdata->pressure_max;
    ts->gpio_irq = pdata->gpio_irq;

    s3c_gpio_cfgpin(ts->gpio_irq, pdata->irq_cfg);
    
    INIT_WORK(&ts->work, test_ts_work);
     
    ret = request_irq(gpio_to_irq(ts->gpio_irq), test_ts_handler, IRQF_TRIGGER_FALLING, 
            FT5X0X_NAME, ts);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_request_irq;
    }

    ts->input_dev = input_allocate_device();   
    if(IS_ERR_OR_NULL(ts->input_dev))
    {
        ret = -ENOMEM;
        goto ERROR_input_alloc;
    }

    input_dev_init(ts);
    
    ret = input_register_device(ts->input_dev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_input_register;
    } 
     
    return 0;
ERROR_input_register:
    input_free_device(ts->input_dev);
ERROR_input_alloc:
    free_irq(gpio_to_irq(ts->gpio_irq), ts);
ERROR_request_irq:
    kfree(ts);
ERROR_kzalloc:
    return ret;
}

int test_ts_remove(struct i2c_client *client)
{
    struct ft5x0x_ts_data *ts = i2c_get_clientdata(client);
    printk("test ts remove\n");

    input_unregister_device(ts->input_dev);
    input_free_device(ts->input_dev);
    free_irq(gpio_to_irq(ts->gpio_irq), ts);
    kfree(ts);
    return 0;
}


struct i2c_device_id id_tables[] = {
    {FT5X0X_NAME, 0},
    {},
};

struct i2c_driver test_ts_driver = {
    .probe = test_ts_probe,
    .remove = test_ts_remove,
    .id_table = id_tables,
    .driver = {
        .name = FT5X0X_NAME,
        .owner = THIS_MODULE,
    },
};

int test_init(void)
{
    printk("test init\n");
    return i2c_add_driver(&test_ts_driver);
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    i2c_del_driver(&test_ts_driver);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



