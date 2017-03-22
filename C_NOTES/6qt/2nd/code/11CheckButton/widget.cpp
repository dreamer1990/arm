#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//提交按钮的动作
void Widget::on_pushButton_clicked()
{
    QString str;

    if (ui->checkBox->isChecked())
        str += " BeiJing";
    if (ui->checkBox_2->isChecked())
        str += " ShangHai";
    if (ui->checkBox_3->isChecked())
        str += " GuangZhou";
    if (ui->checkBox_4->isChecked())
        str += " ShenZhen";

    ui->label_2->setText(str);
}

void Widget::on_pushButton_2_clicked()
{
    ui->label_2->clear();
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
}














