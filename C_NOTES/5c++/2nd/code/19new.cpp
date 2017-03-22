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
    Student(int _id, int _age, char _sex);
    ~Student();
    void showStudent(void);
};

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


int main(void)
{
    //对象指针变量
    Student *p = NULL;

    //分配空间
    p = new Student(1, 28, 'M');
    p->showStudent();
    
    //析构函数是自动调用的 在对象销毁之前调用
    //释放空间
    delete p;

    return 0;
}
