#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_2->setText("Uplooking");
    ui->label_3->setNum(1234);
    ui->label_4->setNum(3.1415962);
}

MainWindow::~MainWindow()
{
    delete ui;
}
