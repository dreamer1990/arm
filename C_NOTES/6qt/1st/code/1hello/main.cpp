#include <QApplication>
#include <QWidget>
#include <QLabel>


int main(int argc, char *argv[])
{
    //管理资源
    QApplication a(argc, argv);

    QWidget widget;

    QLabel label(&widget);

    label.setText("Hello uplooling");

    //显示控件
    widget.show();

    //进入事件循环
    return a.exec();
}
