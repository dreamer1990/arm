#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/input.h>

/*
 struct input_event {
    struct timeval time;
    __u16 type;             //输入的类型;   EV_SYN 
                            //              EV_KEY  键值;
                            //                              EV_REL  相对值;
                            //                                                  EV_ABS  绝对值;
    __u16 code;             //键值:         KEY_ESC ESC键;           
                            //              BTN_LEFT    鼠标左键
                            //              BTN_RIGHT       右键
                            //              BTN_MIDDLE      中间键
                            //              BTN_JOYSTICK    手柄;
                            //                              REL_X   横向移动
                            //                              REL_Y   纵向移动
                            //                              REL_Z   滚轮滚动
                            //                                                  ABS_X   x坐标
                            //                                                  ABS_Y   y坐标
                            //
    __s32 value;            //状态:         按下1和抬起0;           
                                                            -1-2-3  移动或者滚动的距离
                                                                                400
                                                                                800
 }; 
*/

int main(int argc, char ** argv, char **env)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file\n", argv[0]);
        return -1;
    }
    
    int fd;
    fd = open(argv[1], O_RDONLY);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    struct input_event event;    
    char *str;
    while(1)
    {
        read(fd, &event, sizeof(struct input_event));
        switch(event.type)
        {
            case EV_SYN:
                //printf("同步信号(表示一次提交结束)\n");
                if(event.code == SYN_MT_REPORT)
                    printf("MT SYNC\n");
                else if(event.code == SYN_REPORT)
                    printf("SYNC\n");
                break;
            case EV_KEY:
                printf("code: %d value: %d\n", event.code, event.value);
            /*
                printf("键值事件: %d键 %s\n", event.code, event.value ? "按下" : "抬起");
                if(event.code == KEY_ESC)
                    return 0;
            */
                break;
            case EV_REL:
                switch(event.code)
                {
                    case REL_X:
                        str = "x轴方向";
                        break;
                    case REL_Y:
                        str = "y轴方向";
                        break;
                    case REL_Z:
                        str = "z轴方向";
                        break;
                }
                
                printf("相对值事件: %s 移动了%d\n", str, event.value);
                break;
            case EV_ABS:
                switch(event.code)
                {
                    case ABS_X:
                    case ABS_MT_POSITION_X:
                        printf("x [%d]\n", event.value);
                        break;
                    case ABS_Y:
                    case ABS_MT_POSITION_Y:
                        printf("y [%d]\n", event.value);
                        break;
                    case ABS_MT_TOUCH_MAJOR:
                        printf("major: [%d]\n", event.value);
                        break;
                }
                break;
            default:
                break;
        }
    
    }


    close(fd);
    return 0;
}
