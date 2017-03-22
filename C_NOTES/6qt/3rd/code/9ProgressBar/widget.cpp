#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->progressBar->setRange(0, 100);
//    ui->progressBar->setFormat("%p%");

    timer = new QTimer(this);
    timer->setInterval(1000);

    //信号与槽
    connect(timer, SIGNAL(timeout()), this, SLOT(updateProgress()));
    connect(ui->progressBar, SIGNAL(valueChanged(int)), this, SLOT(closeProgress(int)));

    timer->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateProgress(void)
{
    int value = ui->progressBar->value();
    qDebug() << value;
    value += 10;

    ui->progressBar->setValue(value);

}

void Widget::closeProgress(int value)
{
    if (value == ui->progressBar->maximum())
    {
        timer->stop();

        ui->progressBar->close();
    }
}
