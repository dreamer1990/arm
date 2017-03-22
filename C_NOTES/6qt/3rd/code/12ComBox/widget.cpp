#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    int index;

    ui->setupUi(this);
    //设置是否可以编辑
    ui->comboBox->setEditable(true);

    index = ui->comboBox->count();

    //插入一行
    ui->comboBox->insertItem(index, "Wuhan");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_comboBox_activated(QString str)
{
    ui->textEdit->append(str);
}

void Widget::on_pushButton_clicked()
{

    QStringList list;

    ui->textEdit->clear();

    ui->comboBox->clear();

    list.append("aaaa");
    list.append("bbb");
    list.append("ccc");
    //批量插入
    ui->comboBox->insertItems(0, list);
}
