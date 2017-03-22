#include <QApplication>
#include <QWidget>
#include <QLabel>

//主函数
int main(int argc, char *argv[])
{
    //对象是管理资源
    QApplication a(argc, argv);

    QWidget widget;
    widget.resize(480, 640);

    //定义一个对象
    QLabel label(&widget);
    label.setText("Hello Uplooking");
    label.move(200, 200);
    //显示空间
    widget.show();

//    进入事件主循环
    return a.exec();
//    return 0;
//    while(1);
}
