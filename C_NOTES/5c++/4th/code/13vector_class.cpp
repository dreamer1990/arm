#include <iostream>
#include <string>
#include <vector>

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

    //定义一个学生队列的对象
    vector<Student> s;

    for (i = 0; i < 10; i++)
    {

        stu.setId(i + 1); 
        //会调用拷贝构造函数
        s.push_back(stu); 
    }

    //判断队列是否为空
    cout << "empty: " << s.empty() << endl;

    //返回队列中元素的个数
    cout << "size: " << s.size() << endl;

    stu = s.front();
    stu.show();

    cout << "========================" << endl;
    //整体出队列
    while(!s.empty())
    {
        stu = s.front(); 

        stu.show();

        //移除队列顶元素
        s.erase(s.begin());
    }


    return 0;
}







