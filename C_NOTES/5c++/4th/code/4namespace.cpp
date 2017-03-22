#include <iostream>

//使用命名空间中的std中的所有成员
//using namespace std;
//声明使用命名空间中的部分成员
using std::cout;
using std::endl;
//cin cout endl 都是属于标准命名空间std中的成员



int main(void)
{
    //声明已经存在命名空间的别名
    namespace s = std;
    std::cout << "hello world" << std::endl;
    cout << "hello world" << endl;
    //s与std是相同
    s::cout << "hello world" << s::endl;

    return 0;
}
