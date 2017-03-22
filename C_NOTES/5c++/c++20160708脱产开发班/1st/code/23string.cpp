#include <iostream>
#include <string>

using namespace std;


#if 0
    和其他类型变量一样，字符串变量必须先定义后使用，定义字符串变量要用类名string。如
    string string1；                    //定义string1为字符串变量
    string string2=″China″;             //定义string2同时对其初始化

    应当注意： 要使用string类的功能时，必须在本文件的开头将C++标准库中的string头文件包含进来，即应加上
    #include <string>                    //注意头文件名不是string.h
    
    20.2 对字符串变量的赋值
    在定义了字符串变量后，可以用赋值语句对它赋予一个字符串常量，如
    string1=″Canada″;

    既可以用字符串常量给字符串变量赋值，也可以用一个字符串变量给另一个字符串变量赋值。如 
    string2=string1;                //假设string2和string1均已定义为字符串变量

    不要求string2和string1长度相同，假如string2原来是″China″，string1原来是″Canada″，赋值后string2也变成″Canada″。在定义字符串变量时不需指定长度，长度随其中的字符串长度而改变。
    可以对字符串变量中某一字符进行操作，如 
    string word=″Then″;           //定义并初始化字符串变量word
    word[2]=′a′; //修改序号为2的字符，修改后word的值为″Than″
#endif
    
    

int main(void)
{
    //默认初始化为空
    string s1;
    //给字符串对象赋值
    string s2 = "hello uplooking";

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "=======================" << endl;

    s1 = "hello uplooking two";
    s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << "=======================" << endl;
    //可以只改变一个字符
    s2[0] = 'H'; 
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;


    return 0;
}
