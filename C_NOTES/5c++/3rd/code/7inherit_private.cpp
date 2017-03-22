#include <iostream>
using namespace std;


/*
 *7. 私有继承
 *
 *    在声明一个派生类时将基类的继承方式指定为private的，称为私有继承，用私有继承方式建立的派生类称为私有派生类(private derived class) ，其基类称为私有基类(private base class)。
 *
 *    私有基类的公用成员和保护成员在派生类中的访问属性相当于派生类中的私有成员，即派生类的成员函数能访问它们，而在派生类外不能访问它们。私有基类的私有成员在派生类中成为不可访问的成员，只有基类的成员函数可以引用它们。一个基类成员在基类中的访问属性和在派生类中的访问属性可能是不同的。
 *
 *    由于私有派生类限制太多，使用不方便，一般不常使用。
 *
 */

//点类
class Point
{
public:
    Point();
    Point(int , int);
    void show(void);

private:
    int x;
    int y;
};

//圆类 默认是私有成员
class Circle: private Point
{
public:
    Circle();
    Circle(int, int, int);
    void show(void);
    
private:
    int radis;
};


//构造函数
Point::Point()
{
    x = 0;
    y = 0;
    cout << "Point  constructor..." << endl;
}
//构造函数
Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;

    cout << "Point constructor.." << endl;
}

//成员函数
void Point::show(void)
{
    cout << "(" << x << ", " << y << ")" << endl;
}

//圆的构造函数
Circle::Circle():Point()
{
    radis = 0;
    cout << "Circle construtor..." << endl;
}

Circle::Circle(int _x, int _y, int _r):Point(_x, _y)
{
    radis = _r;
    cout << "Circle construtor..." << endl;
}

//成员函数
void Circle::show(void)
{
    Point::show();
    cout << "r = " << radis << endl;
}


int main(void)
{

    Circle c(1, 2, 3);
    c.show();
    
    //私有继承  基类中公有成员都不可以访问  私有继承基类中的公有成员成员派生类的私有成员
    //cout << "base  class show: " << endl;
    //c.Point::show();


    return 0;
}
