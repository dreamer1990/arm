#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//使能
void MainWindow::on_pushButton_clicked()
{
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
}

//禁止
void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
}

//qt-log
void MainWindow::on_pushButton_3_clicked()
{
    qDebug("Qt logo is clicked");
}

void MainWindow::on_pushButton_4_clicked()
{
    qDebug("PushButton4 is clicked");
}
