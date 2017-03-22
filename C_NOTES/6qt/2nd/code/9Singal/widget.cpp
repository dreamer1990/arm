#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //信号与槽的第一种方式   手动关联
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(setLabel()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setLabel(void)
{
    ui->label->setText("Uplooking");
}

void Widget::on_pushButton_2_clicked()
{
    ui->label->clear();;
}


void Widget::setLabel1(void)
{
    ui->label_2->setText("SHENZHEN");
}
