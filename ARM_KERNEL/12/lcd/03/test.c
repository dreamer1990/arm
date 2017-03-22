#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
//#include <linux/vmalloc.h>
//#include <linux/pagemap.h>
#include <linux/io.h>
#include <linux/io-mapping.h>
#include <linux/dma-mapping.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/fb.h>


#include <plat/fb.h>
//#include <plat/regs-fb.h>
#include <plat/regs-fb-v4.h>


#define DRV_NAME    "test-lcd"

struct test_lcd_device{
    struct platform_device *pdev;
    unsigned long reg_phys;
    void __iomem *reg_base;
    int reg_size;

    void *virt;
    unsigned int phys;
    unsigned int mem_len;

    unsigned int w;
    unsigned int h;
    unsigned int bpp;

    struct clk *lcd;
    struct clk *sclk_fimd;

    struct s3c_fb_platdata *platdata;
    struct fb_info *info;
    //struct file_operations fops;
    //struct miscdevice mdev;
};

/*
ssize_t test_write (struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
    int ret;
    struct test_lcd_device *tdev = container_of(filp->f_op, struct test_lcd_device, fops);

    if(*offset >= tdev->mem_len)
        *offset = 0;

    ret = copy_from_user(tdev->virt + *offset, buf, size);
    *offset += size - ret;

    return size - ret;
}
*/

struct fb_ops fb_ops = {
    .owner      = THIS_MODULE,
    .fb_fillrect    = cfb_fillrect,   /* Needed !!! */
    .fb_copyarea    = cfb_copyarea,   /* Needed !!! */
    .fb_imageblit   = cfb_imageblit,  /* Needed !!! */
};

void fb_info_init(struct test_lcd_device *tdev)
{
    struct fb_info *info = tdev->info;

    info->var.xres = tdev->w;
    info->var.yres = tdev->h;
    info->var.bits_per_pixel = tdev->bpp;
    info->var.height = tdev->h;
    info->var.width = tdev->w;

    info->fix.smem_start = tdev->phys;
    info->fix.smem_len = tdev->mem_len;
    info->fix.line_length = tdev->w * tdev->bpp / 8;

    info->fbops = &fb_ops;
    info->screen_base = tdev->virt;
    info->screen_size = tdev->mem_len;
}

void lcd_init(struct test_lcd_device *tdev)
{
    struct fb_videomode *mode = tdev->platdata->vtiming; 
    //struct s3c_fb_pd_win *win = tdev->platdata->win[0];
    struct s3c_fb_platdata* pdata = tdev->platdata;
    unsigned long val;

/*
 *  //测试时钟源是800MHZ;
    unsigned long sclk;
    sclk = clk_get_rate(tdev->sclk_fimd);
    printk("sclk : %lu\n", sclk);
*/
    iowrite32(pdata->vidcon1, tdev->reg_base + VIDCON1);

    val = VIDTCON0_VBPD(mode->upper_margin - 1) | 
            VIDTCON0_VFPD(mode->lower_margin - 1) |
            VIDTCON0_VSPW(mode->vsync_len - 1);
    iowrite32(val, tdev->reg_base + VIDTCON0);

    val = VIDTCON1_HBPD(mode->left_margin - 1) |
            VIDTCON1_HFPD(mode->right_margin - 1) |
            VIDTCON1_HSPW(mode->hsync_len - 1);
    iowrite32(val, tdev->reg_base + VIDTCON1);

    val = VIDTCON2_LINEVAL(mode->yres - 1) | VIDTCON2_HOZVAL(mode->xres - 1);
    iowrite32(val, tdev->reg_base + VIDTCON2);

    val = WINCON0_BPPMODE_24BPP_888 | WINCONx_ENWIN;
    iowrite32(val, tdev->reg_base + WINCON(0));

    val = VIDOSDxA_TOPLEFT_X(0) | VIDOSDxA_TOPLEFT_Y(0);
    iowrite32(val, tdev->reg_base + VIDOSD_BASE); 

    val = VIDOSDxB_BOTRIGHT_X(tdev->w) | VIDOSDxB_BOTRIGHT_Y(tdev->h);
    iowrite32(val, tdev->reg_base + VIDOSD_BASE + 4);

    val = tdev->phys;
    iowrite32(val, tdev->reg_base + VIDW_BUF_START(0));

    val = tdev->phys + tdev->mem_len;
    iowrite32(val, tdev->reg_base + VIDW_BUF_END(0));

    val = VIDW_BUF_SIZE_OFFSET(0) | VIDW_BUF_SIZE_PAGEWIDTH(tdev->w * tdev->bpp / 8);
    iowrite32(val, tdev->reg_base + VIDW_BUF_SIZE(0));

    val = SHADOWCON_CHx_ENABLE(0);
    iowrite32(val, tdev->reg_base + SHADOWCON);

    val = VIDCON0_CLKVAL_F(19) | VIDCON0_ENVID | VIDCON0_ENVID_F;
    iowrite32(val, tdev->reg_base + VIDCON0);
}

int test_probe (struct platform_device *dev)
{
    int ret;
    struct resource *res;
    struct test_lcd_device *tdev;
    struct fb_info *info;
    struct s3c_fb_pd_win *win;
    printk("test drv probe: devname: %s\n", dev->name);
    /*
    tdev = kzalloc(sizeof(struct test_lcd_device), GFP_KERNEL);
    if(IS_ERR_OR_NULL(tdev))
    {
        ret = -ENOMEM;
        goto ERROR_kzalloc;
    }
    */
    info = framebuffer_alloc(sizeof(struct test_lcd_device), &dev->dev);
    if(IS_ERR_OR_NULL(info))
    {
        ret = -ENOMEM;
        goto ERROR_framebuffer_alloc;
    }
    tdev = info->par;
    tdev->info = info;

    tdev->pdev = dev; 
    res = platform_get_resource(dev, IORESOURCE_MEM, 0);
    if(IS_ERR_OR_NULL(res))
    {
        ret = -ENOMEM;
        goto ERROR_get_mem_resource;
    }
    platform_set_drvdata(dev, tdev);

    tdev->reg_size = resource_size(res);
    tdev->reg_phys = res->start;
    if(IS_ERR_OR_NULL(request_mem_region(res->start, tdev->reg_size, DRV_NAME)))
    {
        ret = -EBUSY;
        goto ERROR_request_mem;
    }

    tdev->reg_base = ioremap(res->start, tdev->reg_size); 
    if(IS_ERR_OR_NULL(tdev->reg_base))
    {
        ret = -ENOMEM;
        goto ERROR_ioremap;
    }

    tdev->lcd = clk_get(&dev->dev, "lcd");
    if(IS_ERR(tdev->lcd))
    {
        ret = PTR_ERR(tdev->lcd);
        goto ERROR_clk_get_lcd;
    }

    clk_enable(tdev->lcd);

    tdev->sclk_fimd = clk_get(&dev->dev, "sclk_fimd");
    if(IS_ERR(tdev->sclk_fimd))
    {
        ret = PTR_ERR(tdev->sclk_fimd);
        goto ERROR_clk_get_fimd;
    }

    clk_enable(tdev->sclk_fimd);
    
    tdev->platdata = dev->dev.platform_data;
    tdev->platdata->setup_gpio();

    win = tdev->platdata->win[0];
    tdev->mem_len = win->yres * win->xres * win->max_bpp / 8;
    tdev->w = win->xres;
    tdev->h = win->yres;
    tdev->bpp = win->max_bpp;

    tdev->virt = dma_alloc_coherent(&dev->dev, tdev->mem_len, &tdev->phys, GFP_KERNEL);
    if(IS_ERR_OR_NULL(tdev->virt))
    {
        ret = -ENOMEM;
        goto ERROR_dma_alloc;
    }

    lcd_init(tdev);
    
    /*
    tdev->fops.owner = THIS_MODULE;
    tdev->fops.write = test_write;
    
    tdev->mdev.minor = MISC_DYNAMIC_MINOR;
    tdev->mdev.name = DRV_NAME;
    tdev->mdev.fops = &tdev->fops;

    ret = misc_register(&tdev->mdev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_misc;
    }
    */
    
    fb_info_init(tdev);

    ret = register_framebuffer(info);       ///dev/fb0 /dev/fb1 /dev/fb2
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_register_framebuffer;
    }

    return 0;
//ERROR_misc:
ERROR_register_framebuffer:
    dma_free_coherent(&dev->dev, tdev->mem_len, tdev->virt, tdev->phys);
ERROR_dma_alloc:
    clk_disable(tdev->sclk_fimd);
    clk_put(tdev->sclk_fimd);
ERROR_clk_get_fimd:
    clk_disable(tdev->lcd);
    clk_put(tdev->lcd);
ERROR_clk_get_lcd:
    iounmap(tdev->reg_base);
ERROR_ioremap:
    release_mem_region(tdev->reg_phys, tdev->reg_size); 
ERROR_request_mem:
ERROR_get_mem_resource:
    kfree(tdev);
//ERROR_kzalloc:
ERROR_framebuffer_alloc:
    return ret;
}

int test_remove (struct platform_device *dev)
{
    struct test_lcd_device *tdev = platform_get_drvdata(dev);
    struct fb_info *info = tdev->info;
    printk("test drv remove: devname: %s\n", dev->name);
    
    //misc_deregister(&tdev->mdev);
    unregister_framebuffer(info);
    dma_free_coherent(&dev->dev, tdev->mem_len, tdev->virt, tdev->phys);
    clk_disable(tdev->sclk_fimd);
    clk_put(tdev->sclk_fimd);
    clk_disable(tdev->lcd);
    clk_put(tdev->lcd);
    iounmap(tdev->reg_base);
    release_mem_region(tdev->reg_phys, tdev->reg_size); 
    //kfree(tdev);
    framebuffer_release(info);
    return 0;
}

struct platform_device_id id_table[] = {
    {"exynos4-fb", 0},
    {}
};

struct platform_driver drv = {
    .driver = {
        .name = DRV_NAME,
        .owner = THIS_MODULE,
    },
    .probe = test_probe,
    .remove = test_remove,
    .id_table = id_table,
};

int test_init(void)
{
    printk("test init\n");
    return platform_driver_register(&drv);
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    platform_driver_unregister(&drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



