#include <iostream>
#include <QString>
#include <QChar>
#include <QDebug>
using namespace std;



int main(void)
{

    cout << "Hello world" << endl;
    //定义字符串对象 并且初始化
    QString str = "Hello Uplooking";
    cout << str.toStdString() << endl;
    //调用构造函数
    QString str1("Hello Uplooking2");
    cout << str1.toStdString() << endl;

//    QChar data[6] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46};
    QChar data[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    QString str2(data, 6);
    cout << str2.toStdString() << endl;

    //构造一个字符床对象 然后用10个'X'初始化
    QString str3(10, 'X');
    cout << str3.toStdString() << endl;
    //调用拷贝构造函数
    QString str4(str3);
//    qDebug() << str4;

    cout << "=======================" << endl;
    //append
    str4.append(str4);
    cout << str4.toStdString() << endl;
    str4.append("Uplooking");
    cout << str4.toStdString() << endl;
    str4.append('A');
    cout << str4.toStdString() << endl;

    str4 += " ShenZhen";
    cout << str4.toStdString() << endl;

    ///////////////////////arg////////////////////
    //如果没有足够的arg  那么后面的就原样输出
    str4 = QString("a = %1 b = %2 c = %3 %4 %5").arg(333).arg(444).arg(888);
    cout << str4.toStdString() << endl;

    cout << "====================" << endl;
//    str.arg("%1f", "Hello");
//    str.arg("%1f").arg("Hello");
    str4 = QString("%1 %2").arg("hello", "world");
    cout << str4.toStdString() << endl;

    str4 = "%1 %2 %3 %4 %5";
    str4 = str4.arg("ShenZhen", "GuangZhou", "ShangHai", "HangZhou", "FuJian");
    cout << str4.toStdString() << endl;

    str4 = QString("int = %1 char = %2 long = %3 double = %4").arg(1).arg('A').arg(311111L).arg(3.1415926);
    cout << str4.toStdString() << endl;

    return 0;
}
