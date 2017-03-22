#include <iostream>
using namespace std;

//学生类
class Student{
//私有成员
private:
    int id;
    int age;
    char sex;
//公有成员
public:
    //默认构造函数
    Student();
    Student(int _id, int _age, char _sex);
    ~Student();
    void showStudent(void);
};

Student::Student()
{
    cout << "empty construtor..." << endl;
}

//带参数的构造函数
Student::Student(int _id, int _age, char _sex) : id(_id), age(_age), sex(_sex){
    cout << "id: " << id << "  constructor...." << endl;
}

//析构函数
Student::~Student()
{
    cout << "id " << id << "  destructor.." << endl;
}

//成员函数
void Student::showStudent(void)
{
    cout << "id: " << id << " age: "  << age << "  sex: " << sex << endl;
}


/*
 *    说明： 
 *    (1) 对象的赋值只对其中的数据成员赋值，而不对成员函数赋值。
 *    (2) 类的数据成员中不能包括动态分配的数据，否则在赋值时可能出现严重后果。
 */

int main(void)
{
    Student stu1(1, 2, 'M');
    Student stu2;
    //没有调用构造函数  只是简简单单赋值
    //对象赋值 一定是相同类型  并且数据中不能包含动态分配的内存 否则出现浅拷贝问题
    stu2 = stu1;
    
    stu1.showStudent();
    stu2.showStudent();
    return 0;
}
