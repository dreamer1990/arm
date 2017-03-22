#include <iostream>
using namespace std;

//学生类
class Student{
//私有成员
private:
    int id;
    char sex;
    static int age;
//公有成员
public:
    //默认构造函数
    Student();
    Student(int _id, char _sex);
    ~Student();
    void showStudent(void);
    //静态成员函数
    static void hello(void);
    static void setAge(int _age);
    static int getAge(void);
};

//构造函数
Student::Student()
{
    cout << "empty construtor..." << endl;
}

//带参数的构造函数
Student::Student(int _id, char _sex) : id(_id), sex(_sex){
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
    cout << "id: " << id << " sex: " << sex << endl;
}

//静态成员函数
void Student::setAge(int _age) 
{
    age = _age;
}

int Student::getAge(void)
{
    return age;
}

void Student::hello(void)
{
    cout << "hello world" << endl;
}

//init  如果没有初始化 编译出错
int Student::age = 0;

int main(void)
{

/*
 *
 *    (4) 静态数据成员既可以通过对象名引用，也可以通过类名来引用。
 *    	这说明静态数据成员并不是属于对象的，而是属于类的，但类的对象可以引用它。
 *    	如果静态数据成员被定义为私有的，则不能在类外直接引用，而必须通过公用的成员函数引用。
 *
 */

    Student::hello();
    Student::setAge(33);
    cout << "age: " << Student::getAge() << endl;;


    return 0;
}



