#ifndef UART_DEMO_H
#define UART_DEMO_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif
#include "C_UartComThread.h"
#include <QDebug>

#define __LINUX__
//#define __WINDOWS__

namespace Ui {
class Uart_Demo;
}

class Uart_Demo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Uart_Demo(QWidget *parent = 0);
    ~Uart_Demo();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_Clear_clicked();

    void on_pushButton_Connect_clicked();

    void on_pushButton_Disconnect_clicked();

    void on_pushButton_Send_clicked();

    void Slot_Connected();                      // 处理连接成功
    void Slot_DisConnected();                   // 处理连接断开
    void Slot_PushMsg(QString msg);           // 推送信息
    void Slot_ReciveData(QByteArray data);    // 收到数据向外发送,转交业务处理线程处理


private:
    C_UartComThread m_UartComThread;
    Ui::Uart_Demo *ui;
};

#endif // UART_DEMO_H
