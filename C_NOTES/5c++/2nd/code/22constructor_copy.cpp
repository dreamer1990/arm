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
    Student(const Student &s);
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

//自定义复制拷贝构造函数
Student::Student(const Student &s)
{
    id = s.id;
    age = s.age;
    sex = s.sex;

    cout << "id: " << id << "  constructor called..." << endl;
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
 *    如果用户自己未定义复制构造函数，则编译系统会自动提供一个默认的复制构造函数，其作用只是简单地复制类中每个数据成员。
 *
 */

int main(void)
{
    Student stu1(1, 2, 'M');
    //自动调用系统提供的一个默认的赋值构造函数
    Student stu2(stu1);
    
    stu1.showStudent();
    stu2.showStudent();
    return 0;
}
