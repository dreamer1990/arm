#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

//自定义槽函数
private slots:
    void on_toolButton_clicked();
    void btnOpen(void);
    void btnNew(void);
    void btnClose(void);
};

#endif // MAINWINDOW_H
