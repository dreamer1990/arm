#include <iostream>
using namespace std;


/*
 *8. 保护成员和保护继承
 *
 *    由protected声明的成员称为“受保护的成员”，或简称“保护成员”。从类的用户角度来看，保护成员等价于私有成员。但有一点与私有成员不同，保护成员可以被派生类的成员函数引用。
 *
 *    如果基类声明了私有成员，那么任何派生类都是不能访问它们的，若希望在派生类中能访问它们，应当把它们声明为保护成员。如果在一个类中声明了保护成员，就意味着该类可能要用作基类，在它的派生类中会访问这些成员。
 *
 *    在定义一个派生类时将基类的继承方式指定为protected的，称为保护继承，用保护继承方式建立的派生类称为保护派生类(protected derived class)，其基类称为受保护的基类(protected base class)，简称保护基类。
 *
 *    保护继承的特点是: 保护基类的公用成员和保护成员在派生类中都成了保护成员，其私有成员仍为基类私有。也就是把基类原有的公用成员也保护起来，不让类外任意访问。
 *
 */

//点类
class Point
{
public:
    Point();
    Point(int , int);
    void show(void);

protected:
    int x;
    int y;
};

//圆类 保护继承
class Circle: protected Point
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

Circle::Circle(int _x, int _y, int _r):Point(_x, _y), radis(_r)
{
    cout << "Circle construtor..." << endl;
}

//成员函数
void Circle::show(void)
{
    //Point::show();
    cout << "(" << x << ", " << y << ")" << endl;
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
