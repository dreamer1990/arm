#include <iostream>
using namespace std;


//空的结构体占用1个字节
struct S{

};

//没有数据成员 也占用一个字节
class A{
public: 
    void dispaly()
    {
    
    }
};

//没有任何成员 也占用一个字节
class B{

};

//所占的字节数为所有的数据成员的总字节数 考虑对齐问题
class C{
private:
    int a;
    int b;
    char c;
    char name[32];
public:
    void display()
    {
    
    }

    void display2()
    {
    
    }
};

int main(void)
{
    cout << "sizeof(S): " << sizeof(S) << endl;
    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(B): " << sizeof(B) << endl;
    cout << "sizeof(C): " << sizeof(C) << endl;
    return 0;
}
