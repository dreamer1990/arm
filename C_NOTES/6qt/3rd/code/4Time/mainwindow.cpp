#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //获取当前时间
    QTime time = QTime::currentTime();

    qDebug() << time;


    //默认的对象 0 0 0 0  调用无参的默认构造函数
    QTime time1;

    qDebug() << "IsNull: " << time1.isNull();
    qDebug() << "IsValid:  " << time1.isValid();
    qDebug() << "time1: " << time1;


    //调用有参的构造函数
//    h must be in the range 0 to 23, m and s must be in the range 0 to 59, and ms must be in the range 0 to 999.
    QTime t3(23, 59, 58);
    qDebug() << t3;


//    QTime n(14, 0, 0);                // n == 14:00:00
//    QTime t;
//    t = n.addSecs(70);                // t == 14:01:10
//    t = n.addSecs(-70);               // t == 13:58:50
//    t = n.addSecs(10 * 60 * 60 + 5);  // t == 00:00:05
//    t = n.addSecs(-15 * 60 * 60);     // t == 23:00:00
    //以下两种情况等价
    qDebug() << t3.addMSecs(2000);
    qDebug() << t3.addSecs(2);
    qDebug() << "Hour: " << t3.hour();
    qDebug() << "Minutes: " << t3.minute();
    qDebug() << "Sec: " << t3.second();
    qDebug() << "Msec: " << t3.msec();

    qDebug() << "=========================";

//    QTime time = QTime::fromString("1mm12car00", "m'mm'hcarss");
    // time is 12:01.00

    qDebug() << QTime::fromString("31mm12ddd00", "m'mm'hdddss");

}

MainWindow::~MainWindow()
{

}
