#include <iostream>
using namespace std;


/*
 *
 *    注意： 在类体中直接定义函数时，不需要在函数名前面加上类名，因为函数属于哪一个类是不言而喻的。但成员函数在类外定义时，必须在函数名前面加上类名，予以限定(qualifed)，“∷”是作用域限定符(field qualifier)或称作用域运算符，用它声明函数是属于哪个类的。
 *
 */

//:: 两个冒号 作用域限定符


//声明一个类类型
class Time{
//类中私有的数据
private:
    int hour;
    int min;
    int sec;

//类中公有的成员
public:
    void setTime(int _hour, int _min, int _sec);
    void showTime(void);
};


//类函数必须先在类体中作原型声明，然后在类外定义，也就是说类体的位置应在函数定义之前，否则编译时会出错。


//在类外定义成员函数
void Time::setTime(int _hour, int _min, int _sec)
{
    hour = _hour;
    min = _min;
    sec = _sec;
}

//在类外定义成员函数
void Time::showTime(void)
{
    cout << "hour : " << hour << " min : " << min << " sec "  << sec << endl;
}


int main(void)
{
    //定义类对象 并且分配空间
    Time t1;
    Time t2;

    //设置时间
    t1.setTime(12, 9, 13);
    //显示时间
    t1.showTime();

    //如果对象中的数据成员没有初始化  则是随机值 
    t2.showTime();
    

    return 0;
}
