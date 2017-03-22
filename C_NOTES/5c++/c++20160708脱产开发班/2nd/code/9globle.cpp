#include <iostream>
using namespace std;


int hour = 88;

/*
 *
 *    注意： 在类体中直接定义函数时，不需要在函数名前面加上类名，因为函数属于哪一个类是不言而喻的。但成员函数在类外定义时，必须在函数名前面加上类名，予以限定(qualifed)，“∷”是作用域限定符(field qualifier)或称作用域运算符，用它声明函数是属于哪个类的。
 *
 *    如果在作用域运算符“∷”的前面没有类名，或者函数名前面既无类名又无作用域运算符“∷”，如 
 *    ::display( )       或  display( )
 *    则表示display函数不属于任何类，这个函数不是成员函数，而是全局函数，即非成员函数的一般普通函数。
 *
 *
 *    类函数必须先在类体中作原型声明，然后在类外定义，也就是说类体的位置应在函数定义之前，否则编译时会出错。
 *
 *    虽然函数在类的外部定义，但在调用成员函数时会根据在类中声明的函数原型找到函数的定义（函数代码），从而执行该函数。
 *
 *    在类的内部对成员函数作声明，而在类体外定义成员函数，这是程序设计的一种良好习惯。如果一个函数，其函数体只有2~3行，一般可在声明类时在类体中定义。多于3行的函数，一般在类体内声明，在类外定义。
 *
 */

//声明类类型
class Time{
    //成员函数
    public:
        //设置时间的成员函数
        void setTime(int h, int m, int s);
        //显示时间的成员函数
        void showTime(void);
        //数据成员
    private:
        int hour;
        int min;
        int sec;
};

//在类中声明成员函数  在类外定义成员函数
void Time::setTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}

void Time::showTime(void)
{
    cout << hour << " : "  << min << " : " << sec << endl;
    //在类中如果访问了于数据成员同名的变量 需要用作用域限定符
    cout << ::hour << endl;
}

int main(void)
{
    //类类型没有占用空间 只有定义对象之后 对象才占空间
    Time t;
    t.setTime(10, 59, 0);
    t.showTime();

    cout << "hour: " << hour << endl;


    return 0;
}








