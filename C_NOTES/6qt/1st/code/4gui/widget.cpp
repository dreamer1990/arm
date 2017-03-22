#include "widget.h"
#include "ui_widget.h"

//构造函数
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //启动界面
    ui->setupUi(this);
}

//析构函数
Widget::~Widget()
{
    //释放空间
    delete ui;
}
