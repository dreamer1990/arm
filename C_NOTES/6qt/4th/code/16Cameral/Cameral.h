#ifndef CAMERAL_H
#define CAMERAL_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>  //摄像头头文件
#include <QThread>

#define BIT_COUNT   24
#define COUNT  3

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#pragma pack(1)

struct bmp_header_t{
    u16        magic;
    u32       file_size;
    u32       RESERVED1;
    u32       offset;         //54 bytes

    u32       head_num;    //40
    u32       width;
    u32       height;
    u16       color_planes; //1
    u16       bit_count;
    u32       bit_compression; //0
    u32       image_size; //except the size of header
    u32       h_resolution;
    u32       v_resolution;
    u32       color_num;
    u32       important_colors;
};

#pragma pack()




class Cameral : public QThread
{
    Q_OBJECT
public:
    explicit Cameral(QObject *parent = 0);

    //初始化摄像头
    int Init_Cameral(int  Width , int Height);
    //退出使用摄像头
    int Exit_Cameral(void);

    //关闭摄像头
    int Stop_Cameral(void);
    //开启摄像头
    int Start_Cameral(void);


    //获取一张图片
    int Get_Picture_YUYV(unsigned char *yuyv);
    void set_bmp_header(struct bmp_header_t * header, u32 width, u32 height);
    int yuyv2rgb24(u8 *yuyv, u8 *rgb, u32 width, u32 height);

private:

    char *YUYV[3] ;  //映射空间
    int fd ;   //打开摄像头的设备描述符
    int length ;  //图片数据长度

signals:

public slots:

};

#endif // CAMERAL_H
