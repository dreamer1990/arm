#include <iostream>
using namespace std;


//三个访问属性
//public: 公有的
//protected: 保护的
//private:私有的


//如果没有指定访问属性 则默认是私有
class Student{
public:
    //成员变量
    int id;
    char sex;
    
    //成员方法
    //函数的定义
    void display(void)
    {
        cout << "id: "  << id << "  sex: " << sex << endl;
    }
};


int main(void)
{
    Student stu;

    stu.id = 33;
    stu.sex = 'M';
    stu.display();

    return 0;
}
