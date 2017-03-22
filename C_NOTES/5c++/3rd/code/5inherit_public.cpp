#include <iostream>
using namespace std;


//人类 基类
class Person
{
public:
    Person();
    Person(int, char);
    void show(void);
private:
    int id;
    char sex;
};

//学生类是从Person类继承
class Student:public Person
{
public:
    Student(); 
    Student(int _id, char _sex, int _score);
    void show(void);
private:
    int score;
};


//构造函数
Person::Person()
{
    id = 0;
    sex = 'M';
    cout << "constructor..." << endl;
}
//构造函数
Person::Person(int _id, char _sex)
{
    id = _id;
    sex = _sex;
    cout << "Person constructor.." << endl;
}

//成员函数的定义
void Person::show(void)
{
    cout << "id: " << id << "  sex:  " << sex << endl;
}

//构造函数
Student::Student():Person()
{
    score = 0; 
    cout << "Student constructor..." << endl;
}

//构造函数
Student::Student(int _id, char _sex, int _score):Person(_id, _sex)
{
    score = _score; 
    cout << "Student constructor" << endl;
}

//成员函数
void Student::show(void)
{
    //对于基类的私有成员 只能调用基类的公有成员函数来访问
    Person::show();
    //‘int Person::id’是私有的
    //cout << id << " " << sex << endl;

    cout << " score = " << score << endl;
}



int main(void)
{
    Student s(1, 'M', 33);
    s.show();

    //‘int Student::score’是私有的 私有成员不能在类外访问
    //cout << s.score << endl;
    cout << "=====================" << endl;
    //派生类中覆盖了子类中的show  如果要调用基类的同名函数 必须指定类
    s.Person::show();

    return 0;
}
