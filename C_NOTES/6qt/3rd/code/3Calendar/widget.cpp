#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置显示的星期
    ui->calendarWidget->setFirstDayOfWeek(Qt::Friday);

    //设置网格是否可见
    ui->calendarWidget->setGridVisible(true);

    //手动关联信号与槽
    connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(calendarShow(QDate)));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::calendarShow(const QDate & date)
{
    qDebug() << date;
}
