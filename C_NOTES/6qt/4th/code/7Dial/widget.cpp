#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置范围
    ui->dial->setRange(0, 10);
    //设置步长
    ui->dial->setSingleStep(1);

    ui->dial->setNotchTarget(1);
    ui->dial->setNotchesVisible(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_dial_valueChanged(int value)
{
    qDebug() << value;
}
