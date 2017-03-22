#include <iostream>
#include <string>

//使用标准命名空间
using namespace std;

int main(void)
{
    //string类型
    //定义一个字符串变量 如果没有赋初值 就默认为空
    string s1;
    //定义一个字符串变量 并且赋初值
    string s2 = "uplooking";


    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cout << "===================\n";

    //既可以用字符串常量给字符串变量赋值，也可以用一个字符串变量给另一个字符串变量赋值。如 
    s1 = "hello uplooking";
    s2 = s1;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    //可以修改字符串中某一个字符
    //不可以用*s1 = 'H', 但是可以通过下标改变
    s1[0] = 'H';
    cout << "s1: " << s1 << endl;

    //字符串的输入输出 cin遇到空格 制表符 换行符就停止输入 与scanf类似
    cin >> s1;
    cout << "=====> cin s1: " << s1 << endl;


    return 0;
}
