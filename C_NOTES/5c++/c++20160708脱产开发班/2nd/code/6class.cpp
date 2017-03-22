#include <iostream>
using namespace std;


/*
 *
 *    类的成员函数(简称类函数)是函数的一种，它的用法和作用和第4章介绍过的函数基本上是一样的，它也有返回值和函数类型，
 *	  它与一般函数的区别只是： 它是属于一个类的成员，出现在类体中。它可以被指定为private(私有的)、public(公用的)或protected(受保护的)。
 *    在使用类函数时，要注意调用它的权限(它能否被调用)以及它的作用域(函数能使用什么范围中的数据和函数)。
 *   例如私有的成员函数只能被本类中的其他成员函数所调用，而不能被类外调用。
 *
 *    成员函数可以访问本类中任何成员(包括私有的和公用的)，可以引用在本作用域中有效的数据。
 *
 */


//声明类类型
class Time{
//成员函数
public:
    //设置时间的成员函数
    void setTime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }
    //显示时间的成员函数
    void showTime(void)
    {
        cout << hour << " : "  << min << " : " << sec << endl;
    }
    //私有的成员函数
private:
    int getHour(void)
    {
        return hour; 
    }

//数据成员
private:
    int hour;
    int min;
    int sec;
};

int main(void)
{
    //类类型没有占用空间 只有定义对象之后 对象才占空间
    Time t;
    t.setTime(10, 59, 0);
    t.showTime();
    //在类外不能访问私有的成员
    //t.getHour();


    return 0;
}








