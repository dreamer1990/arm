#include <stdio.h>

#define DEBUG_V1(format, ...)   printf("file: %s func: %s line: %d "format, \
        __FILE__, __func__, __LINE__, __VA_ARGS__);

 /*
  *条件编译命令的几种形式：
  *(1)#ifdef 标识符
  *       程序段１
  *　#else
  *       程序段２
  *　#endif
  *
  */


  /*
   *(2)#ifndef 标识符
   *       程序段１
   *　#else
   *       程序段２
   *　#endif
   *
   */


 /*
  *(3) #if 表达式
  *        程序段１
  *　　#else
  *        程序段２
  *　　#endif
  *
  */
#define DEBUG 
#define SYSTEM


int main(void)
{

    int a = 3;
    int b = 4;

    //都是预处理的, 如果不满足条件的,预处理之后就直接清除相关代码
    //以下两种方式等价
//    #ifdef DEBUG
    #if defined DEBUG
        DEBUG_V1("a = %d b = %d\n", a,  b);
    #else
        printf("a = %d  b = %d\n", a, b);
    #endif

    #if !defined SYSTEM
   // #ifndef SYSTEM
        printf("The system is 32bit\n");
    #else
        printf("The system is 64bit\n");
    #endif
    
    //如果a > b 满足条件 执行程序段一
    //#if 0  #endif  可以用于注释
    #if a > b
        printf("a > b \n");
    #else
        printf("a <= b\n");
    #endif
     
    

    return 0;
}

