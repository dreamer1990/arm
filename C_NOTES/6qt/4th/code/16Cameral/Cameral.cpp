#include "Cameral.h"

Cameral::Cameral(QObject *parent) :
    QThread(parent)
{


}


//初始化摄像头
int Cameral::Init_Cameral(int  Width , int Height)
{
        int ret ;

        fd = open("/dev/video0" , O_RDWR);
        if(fd < 0)
        {
                perror("Open Video0 fail");
                return -1 ;
        }


        struct v4l2_format  format  ;
        //1.设置图像格式及图像的码流格式
        format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE ;
        format.fmt.pix.width = Width;
        format.fmt.pix.height = Height;
        format.fmt.pix.pixelformat =  V4L2_PIX_FMT_YUYV ;

        ret = ioctl(fd , VIDIOC_S_FMT , &format);
        if(ret != 0)
        {
                perror("video set format fail");
                return -1 ;
        }

        //2.申请buffer   request buffer  3块且设置mmap形式
        struct v4l2_requestbuffers  requestbuffer ;
        requestbuffer.count = COUNT;
        requestbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE ;
        requestbuffer.memory = V4L2_MEMORY_MMAP ;
        ret = ioctl(fd , VIDIOC_REQBUFS , &requestbuffer);
        if(ret != 0)
        {
                perror("request buffer fail");
                return -2 ;
        }

        //3.申请队列  queryBuffer
        struct v4l2_buffer querybuffer ;

        querybuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE ;
        querybuffer.memory = V4L2_MEMORY_MMAP ;

        int i ;
        for(i = 0 ; i < COUNT; i++)
        {
                querybuffer.index = i ;

                ret = ioctl(fd ,VIDIOC_QUERYBUF , &querybuffer);
                if(ret != 0)
                {
                        perror("querybuffer fail");
                        return -3 ;
                }

                //测试很重要
                //printf("offset:%d  length:%d \n"  , querybuffer.m.offset , querybuffer.length);

                //4.映射
                YUYV[i] = (char *)mmap(0 , querybuffer.length , PROT_READ , MAP_SHARED , fd , querybuffer.m.offset);

                //获取数据长度
                length = querybuffer.length ;

                //5.入队
                ret = ioctl(fd , VIDIOC_QBUF , &querybuffer);
                if(ret != 0)
                {
                        perror("queue Buffer fail");
                        return -4 ;
                }
        }


        return 0 ;
}

//关闭摄像头
int Cameral::Stop_Cameral(void)
{
        //end 关闭摄像头
        int ret ;
        int off = 1 ;
        ret = ioctl(fd , VIDIOC_STREAMOFF, &off);
        if(ret != 0)
        {
                perror("stream off fail");
                return -5 ;
        }

        return 0 ;
}

//开启摄像头
int Cameral::Start_Cameral(void)
{
        //6.开启摄像头
        int on = 1 ;
        int ret ;
        ret = ioctl(fd , VIDIOC_STREAMON , &on);
        if(ret != 0)
        {
                perror("stream on fail");
                return -5 ;
        }

        return 0 ;
}

//关闭摄像头
int Cameral::Exit_Cameral(void)
{
        int i ;
        for(i = 0 ; i < COUNT ; i++)
        {
                munmap(YUYV[i] , length);
        }

        close(fd);
        return 0 ;
}


//获取一张图片
int Cameral::Get_Picture_YUYV(unsigned char *yuyv)
{

        int ret ;

        //拍一张照片
        struct v4l2_buffer dequeuebuffer ;

        dequeuebuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE ;
        dequeuebuffer.memory = V4L2_MEMORY_MMAP ;
        ret = ioctl(fd , VIDIOC_DQBUF , &dequeuebuffer);
        if(ret != 0)
        {
                perror("dequeue fail");
                return -7 ;
        }

        memcpy(yuyv , YUYV[dequeuebuffer.index] , length);

#if 0
        int pic_fd ;
        pic_fd = open("yuyv" , O_RDWR|O_CREAT , 0777);
        if(pic_fd < 0)
        {
                perror("open pic fail");
                return -8 ;
        }

        write(pic_fd , YUYV[dequeuebuffer.index] , dequeuebuffer.length);

        close(pic_fd);
#endif

        ret = ioctl(fd , VIDIOC_QBUF , &dequeuebuffer);
        if(ret != 0)
        {
                perror("queue fail");
                return -9 ;
        }

        return 0 ;
}



void Cameral::set_bmp_header(struct bmp_header_t *header, u32 width, u32 height)
{
    header->magic = 0x4d42;
    header->image_size = width * height * BIT_COUNT/8;
    header->file_size = header->image_size + 54;
    header->RESERVED1 = 0;
    header->offset = 54;

    header->head_num = 40;
    header->width = width;
    header->height = height;
    header->color_planes = 1;
    header->bit_count = BIT_COUNT;
    header->bit_compression = 0;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->color_num = 0;
    header->important_colors = 0;
}

int Cameral::yuyv2rgb24(u8 *yuyv, u8 *rgb, u32 width, u32 height)
{
    u32 i, in, rgb_index = 0;
    u8 y0, u0, y1, v1;
    int r, g, b;
    u32  x, y;

    for(in = 0; in < width * height * 2; in += 4)
    {
        y0 = yuyv[in+0];
        u0 = yuyv[in+1];
        y1 = yuyv[in+2];
        v1 = yuyv[in+3];

        for (i = 0; i < 2; i++)
        {
                if (i)
                        y = y1;
                else
                        y = y0;
                r = y + (140 * (v1-128))/100;  //r
                g = y - (34 * (u0-128))/100 - (71 * (v1-128))/100; //g
                b = y + (177 * (u0-128))/100; //b
                if(r > 255)   r = 255;
                if(g > 255)   g = 255;
                if(b > 255)   b = 255;
                if(r < 0)     r = 0;
                if(g < 0)     g = 0;
                if(b < 0)     b = 0;

                y = height - rgb_index/width -1;
                x = rgb_index%width;
                rgb[(y*width+x)*3+0] = b;
                rgb[(y*width+x)*3+1] = g;
                rgb[(y*width+x)*3+2] = r;
                rgb_index++;
        }
    }
    return 0;
}

