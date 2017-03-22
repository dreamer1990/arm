#include <iostream>
using namespace std;
/*
 *
 *    访问对象中成员的一般形式为
 *    对象名.成员名
 *
 */



/*
 *
 *    有关构造函数的使用，有以下说明： 
 *    (1) 在类对象进入其作用域时调用构造函数。
 *    (2) 构造函数没有返回值，因此也不需要在定义构造函数时声明类型，这是它和一般函数的一个重要的不同之点。
 *    (3) 构造函数不需用户调用，也不能被用户调用。
 *    (4) 在构造函数的函数体中不仅可以对数据成员赋初值，而且可以包含其他语句。但是一般不提倡在构造函数中加入与初始化无关的内容，以保持程序的清晰。
 *    (5) 如果用户自己没有定义构造函数，则C++系统会自动生成一个构造函数，只是这个构造函数的函数体是空的，也没有参数，不执行初始化操作。
 *
 *
 */

//类的声明
class Time{
//私有
private:
    int hour;
    int min;
    int sec;

public:
    void setTime(int _h, int _m, int _s);
    void showTime(void);
    //构造函数
    Time();
    Time(int _h, int _m, int _s);
};

//类的成员函数的定义
void Time::setTime(int _h, int _m, int _s)
{
    hour = _h;
    min = _m;
    sec = _s;
}

//成员函数的定义
void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
}

//不带参数的构造函数
//如果用户已经定义了构造函数 那么不带参数的构造函数系统就不会创建
Time::Time(void)
{
    hour = 0;
    min = 0;
    sec = 0;
}

//带有参数的构造函数
Time::Time(int _h, int _m, int _s)
{
    hour = _h;
    min = _m;
    sec = _s;
}


int main(void)
{
    //不带参数的构造函数
    Time t;
    //带参数的构造函数 定义对象的时候 初始化
    Time t1(1, 2, 3);

    t.showTime();
    t1.showTime();
    

    return 0;
}
