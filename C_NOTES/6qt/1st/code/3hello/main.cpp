#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a1(argc, argv);

    int a;
    int b;
    cin >> a >> b;

    cout << "a = " << a << " b = " << b << endl;

    return a1.exec();
}
