#include <iostream>
#include <string.h>
using namespace std;



/*
 *    在C++中，声明了类类型后，定义对象有两种形式。
 *    1） class 类名 对象名 
 *    如 class Student  stud1,stud2;
 *    把class和Student合起来作为一个类名，用来定义对象。
 *
 *    2） 类名 对象名 
 *    如 Student  stud1，stud2;
 *    直接用类名定义对象。这两种方法是等效的。第1种方法是从C语言继承下来的，第2种方法是C++的特色，显然第2种方法更为简捷方便。
 *
 */

#if 0
//三个关键字  成员访问限定符
private: 私有的关键字
public: 公有的
protected: 保护的 
#endif

//声明一个类类型
class Student {
//私有部分
private:
    int id;
    char sex;
    char name[32];
//公有部分
public:
    int stuSetValue(int _id, char _sex, const char *_name) 
    {
        id = _id;
        sex = _sex;
        //name = _name;  //报错
        strcpy(name, _name);
    }

    void showStu(void)
    {
        cout << "id: "  << id << " sex: " << sex << " name: " << name << endl;
    }
};

int main(void)
{
    //定义对象的第一种方法  C语言风格
    class Student stu1;
    //定义对象的第二种方法  C++风格
    Student stu2;
    //错误：‘int Student::id’是私有的 
    //stu1.id = 100;

    cout << "sizeof(stu1): " << sizeof(stu1) << endl;
    
    //通过对象调用成员函数 前提是公有的
    stu1.stuSetValue(1, 'M', "uplooking");
    stu1.showStu();

    //第二个对象
    //通过对象调用成员函数 前提是公有的
    stu2.stuSetValue(2, 'F', "uplook");
    stu2.showStu();


    return 0;
}
