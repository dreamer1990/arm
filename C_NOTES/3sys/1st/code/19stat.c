
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#if 0
struct stat {
    dev_t     st_dev;     /* ID of device containing file */    
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for file system I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};

//测试是否为普通文件
S_ISREG(m)  is it a regular file?
//测试是否为目录
S_ISDIR(m)  directory?
//测试是否为字符设备
S_ISCHR(m)  character device?
//测试是否为块设备
S_ISBLK(m)  block device?
//测试是否为管道文件
S_ISFIFO(m) FIFO (named pipe)?
//测试是否为链接文件
S_ISLNK(m)  symbolic link? (Not in POSIX.1-1996.)
//测试是否为套接字文件
S_ISSOCK(m) socket? (Not in POSIX.1-1996.)


#endif


int main(void)
{
    //定义结构体变量
    struct stat buf;
    int ret = 0;

    memset(&buf, 0, sizeof(buf));
    ret = stat("txt", &buf);
    if (ret < 0)    
    {
        perror("stat"); 
        goto err0;
    }
    printf("st_dev: %lu\n", buf.st_dev);     //设备ID
    printf("st_ino: %lu\n", buf.st_ino);     //设备inode节点
    printf("st_mode: %lu\n", buf.st_mode);   //模式
    printf("st_nlink: %lu\n", buf.st_nlink); //硬链接数
    printf("st_uid: %u\n", buf.st_uid);      //用户ID
    printf("st_gid: %u\n", buf.st_gid);      //组ID

    //检查文件的类型
    if (S_ISREG(buf.st_mode))
        printf("Is a regular file...\n");
    else if (S_ISDIR(buf.st_mode))
        printf("Is a directory....\n");
    else if (S_ISCHR(buf.st_mode))
        printf("Is a char device...\n");
    else if (S_ISBLK(buf.st_mode))
        printf("Is a block device....\n");
    else
        printf("other....\n");

    return 0;
err0:
    return -1;
}





