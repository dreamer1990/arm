#include <iostream>
using namespace std;


/*
 *    关于内置(inline)函数，类的成员函数也可以指定为内置函数。
 *
 *    在类体中定义的成员函数的规模一般都很小，而系统调用函数的过程所花费的时间开销相对是比较大的。
 *    调用一个函数的时间开销远远大于小规模函数体中全部语句的执行时间。为了减少时间开销，如果在类体中定义的成员函数中不包括循环等控制结构，
 *	  C++系统会自动将它们作为内置(inline)函数来处理。也就是说，在程序调用这些成员函数时，并不是真正地执行函数的调用过程(如保留返回地址等处理)，
 *    而是把函数代码嵌入程序的调用点。这样可以大大减少调用成员函数的时间开销。*
 *
 */


//声明类类型
class Time{
    //成员函数
    public:
        //设置时间的成员函数
        inline void setTime(int h, int m, int s);
        //显示时间的成员函数
        inline void showTime(void);
        //数据成员
    private:
        int hour;
        int min;
        int sec;
};

//在类中声明成员函数  在类外定义成员函数
inline void Time::setTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}

inline void Time::showTime(void)
{
    cout << hour << " : "  << min << " : " << sec << endl;
}

int main(void)
{
    //类类型没有占用空间 只有定义对象之后 对象才占空间
    Time t;
    t.setTime(10, 59, 0);
    t.showTime();


    return 0;
}








