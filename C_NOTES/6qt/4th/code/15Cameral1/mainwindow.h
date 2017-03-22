#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Cameral.h"
#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QFile>

namespace Ui {
    class MainWindow;
}

#define   W   320
#define   H   240

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    Cameral  Cam ;
    QTimer  Timer ;
    unsigned char YUV[W*H*2] ;
    unsigned char RGB[W*H*3+54] ;


private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButtonCapture_clicked();
    void on_pushButtonPause_clicked();
    void on_pushButtonStart_clicked();
    void Timer_Slot(void);
};

#endif // MAINWINDOW_H
