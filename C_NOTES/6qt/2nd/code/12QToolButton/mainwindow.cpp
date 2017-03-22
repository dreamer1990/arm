#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolButton *btnOpen = new QToolButton;
    //Alt + O 是快捷键
    btnOpen->setText("&Open");

    QToolButton *btnClose = new QToolButton;
    btnClose->setText("&Close");

    QToolButton *btnNew = new QToolButton;
    btnNew->setText("&New");

//    //将工具按钮添加到工具栏中
//    ui->mainToolBar->addWidget(btnOpen);
//    ui->mainToolBar->addWidget(btnNew);
//    ui->mainToolBar->addWidget(btnClose);

    ui->toolBar->addWidget(btnOpen);
    ui->toolBar->addWidget(btnClose);
    ui->toolBar->addWidget(btnNew);


    //手动关联信号与槽
    connect(btnOpen, SIGNAL(clicked()), this, SLOT(btnOpen()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(btnClose()));
    connect(btnNew, SIGNAL(clicked()), this, SLOT(btnNew()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//自定义槽函数的实现
void MainWindow::btnOpen(void)
{
//    ui->textEdit->setText("Open");
    ui->textEdit->append("Open");
}

void MainWindow::btnNew(void)
{
//    ui->textEdit->setText("New");
    ui->textEdit->append("New");
}
void MainWindow::btnClose(void)
{
//    ui->textEdit->setText("Close");
    ui->textEdit->append("Close");
}

void MainWindow::on_toolButton_clicked()
{
    close();
}
