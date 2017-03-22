#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>

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
    //按键按下事件
    void keyPressEvent(QKeyEvent *e);
    //按键释放事件
    void keyReleaseEvent(QKeyEvent *e);
};

#endif // MAINWINDOW_H
