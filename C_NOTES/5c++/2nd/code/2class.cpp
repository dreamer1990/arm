#include <iostream>
using namespace std;

//声明学生类类型 不占空间  默认是私有的
class Student{
    //数据成员
    int id;
    char sex;
    char name[32];

    //成员函数
    void display(void)
    {
        cout <<  "id: " << id << " sex: " << sex << " name: " << name << endl;
    }
};

int main(void)
{
    //定义类对象
    class Student stu1;

    //以下都是错误的 因为class中所有的成员默认是private的
    #if 0
    stu1.id = 1;
    stu1.sex = 'M';
    strcpy(stu1.name, "uplooking");

    cout << "stu1 id: " << stu1.id << "  sex: " << stu1.sex << " name: " << stu1.name << endl;
    #endif

    return 0;
}

