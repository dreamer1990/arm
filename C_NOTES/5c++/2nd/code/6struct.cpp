#include <iostream>
#include <string.h>
using namespace std;

/*
 *
 *    用struct声明的类，如果对其成员不作private或public的声明，系统将其默认为public。如果想分别指定私有成员和公用成员，则应用private或public作显式声明。而用class定义的类，如果不作private或public声明，系统将其成员默认为private，在需要时也可以自己用显式声明改变。
 *
 *    如果希望成员是公用的，使用struct比较方便，如果希望部分成员是私有的，宜用class。建议尽量使用class来建立类，写出完全体现C++风格的程序。
 *
 */

//C++保留了struct 同时也扩展了它的功能

//声明一个结构体类型
struct Student {
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
    struct Student stu1;
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
