#include <iostream>
using namespace std;



#if 0
	数据类型	基本类型	整型	短整型(short int)
							        整型(int) 
							        长整型(long int)
						    字符型(char)
						    浮点型	单精度型(float)
							        双精度型(double)
							        长双精度型(long double)

						    布尔型(bool)

				构造类型	枚举类型(enum)
						    数组类型
						    结构体类型(struct)
						    共用体类型(union)
						    类类型(class)
				指针类型
				引用类型
				空类型(void)
#endif

int main(void)
{
    //整型
    cout << "sizeof(short): " << sizeof(short) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;

    //字符型
    cout << "sizeof(char): " << sizeof(char) << endl;

    //浮点型
    cout << "sizeof(float): " << sizeof(float) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(long double): " << sizeof(long double) << endl;

    //布尔型
    cout << "sizeof(bool): " << sizeof(bool) << endl;

    //空类型
    //3sizeof.cpp:46: 警告：‘sizeof’不能用于 void 类型
    //cout << "sizeof(void): " << sizeof(void) << endl;

    return 0;
}




