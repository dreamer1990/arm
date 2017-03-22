#include "widget.h"
#include "ui_widget.h"

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

void Widget::on_radioButton_clicked()
{
    ui->label->setText("Male is selected");
}

void Widget::on_radioButton_2_clicked()
{
    ui->label->setText("Female is selected");
}

void Widget::on_pushButton_clicked()
{
    ui->radioButton->setChecked(true);
    ui->label->clear();
    ui->label->setText("Male is selected");
}
