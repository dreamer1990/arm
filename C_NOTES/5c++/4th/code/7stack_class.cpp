#include <iostream>
#include <string>
#include <stack>

using namespace std;


//学生类声明
class Student{
public:
    Student();
    Student(int id, char sex, string name);
    ~Student();
    void show(void);
    void setId(int);

private:
    int id;
    char sex;
    string name;
};

//默认初始化
Student::Student()
{
    id = 0;
    sex = 'M';
    name = "";
    cout << "constructor" << endl;
}

Student::Student(int id, char sex, string name)
{
    //this指针
    this->id = id; 
    this->sex = sex;
    this->name = name;
    cout << "constructor" << endl;
}

Student::~Student()
{
    cout << "destructor" << endl;
}

//成员函数的定义
void Student::show(void)
{
    cout << id << " " << sex << " " << name << endl;
}

//设置ID
void Student::setId(int _x)
{
    id = _x;
}


int main(void)
{
    int i = 0;
    Student stu(11, 'M', "uplooking");

    stack<Student> s;

    for (i = 0; i < 10; i++)
    {

        stu.setId(i + 1); 
        //会调用拷贝构造函数
        s.push(stu); 
    }

    //判断栈是否为空
    cout << "empty: " << s.empty() << endl;

    //返回栈中元素的个数
    cout << "size: " << s.size() << endl;

    stu = s.top();
    stu.show();

    cout << "========================" << endl;
    //整体出栈
    while(!s.empty())
    {
        stu = s.top(); 

        stu.show();

        //移除栈顶元素
        s.pop(); 
    }


    return 0;
}







