#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置后缀
    ui->spinBox->setSuffix("%");

    //设置步长
    ui->spinBox->setSingleStep(5);

    //设置前缀
    ui->spinBox->setPrefix("#");
    //设置范围
    ui->spinBox->setRange(0, 100);

    //设置初始化值
    ui->spinBox->setValue(10);


    //浮点类型
    ui->doubleSpinBox->setDecimals(3);
    //设置步长
    ui->doubleSpinBox->setSingleStep(1.5);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_spinBox_valueChanged(int value)
{
    qDebug() << value;
}



void Widget::on_doubleSpinBox_valueChanged(double value)
{
    qDebug() << value;
}
