#include <iostream>
using namespace std;

//声明结构体类型
//默认是公有的
struct Student{
    int id;
    char sex;
    char name[32];

    void display(void)
    {
        cout << "id: "  << id << "  sex: " << sex << "  name: " << name << endl;
    }
};

int main(void)
{
    //定义结构体变量
    struct Student stu1 = {1, 'M', "uplooking"}, stu2 = {2, 'F', "uplook"};

    cout << "stu1 id: " << stu1.id << "  sex: " << stu1.sex << " name: " << stu1.name << endl;
    cout << "stu2 id: " << stu2.id << "  sex: " << stu2.sex << " name: " << stu2.name << endl;

    stu1.display();

    return 0;
}

