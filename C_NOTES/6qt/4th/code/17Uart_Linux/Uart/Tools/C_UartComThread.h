#ifndef C_UARTCOMTHREAD_H
#define C_UARTCOMTHREAD_H

#include <QThread>
#include <QTimer>
#include <QTime>
#include "posix_qextserialport.h"

#ifdef SOCKET_WAIT
#undef SOCKET_WAIT
#endif
#define     SOCKET_WAIT     3000    // Socket等待时间
#ifdef THREAD_WAIT
#undef THREAD_WAIT
#endif
#define     THREAD_WAIT     20     // 线程等待时间

class  C_UartComThreadSlots : public QObject /** 线程使用的糟容器,使糟在子线程中执行 **/
{
    Q_OBJECT
public:
    explicit C_UartComThreadSlots(QObject *parent = 0);
    ~C_UartComThreadSlots();

private:
    QTimer m_TimerReadCom;                      // 读取数据定时器
    Posix_QextSerialPort *m_SerialPort;         // 串口通讯对象
    void PushMsg(QString msg);                  // 推送添加来源的信息
    void Exception(QString exceptDisc);         // 异常处理
    bool ConnectCom(QString comName, BaudRateType boartRate, QString &errMsg);  // 连接串口
    void DisconnectCom();                                                       // 断开串口连接
    bool SendData(QByteArray data, QString &errMsg);                            // 通过串口对外发送数据

signals:
    void Signal_Connected();                    // 连接成功发出
    void Signal_DisConnected();                 // 断开连接发出
    void Signal_PushMsg(QString msg);           // 推送信息
    void Signal_ReciveData(QByteArray data);    // 收到数据向外发送,转交业务处理线程处理

public slots:
    void Slot_ConnectCom(QString comName, BaudRateType boartRate);  // 连接串口
    void Slot_DisconnectCom();                                      // 断开串口连接
    void Slot_SendData(QByteArray data);                            // 通过串口对外发送数据

private slots:
    void Slot_ReciveData();                                         // 处理接收到的数据
};

/************************************************
 * 串口通讯管理类
 * 功能:管理与串口通讯的线程
 ************************************************/
class C_UartComThread : public QThread
{
    Q_OBJECT
public:
    explicit C_UartComThread(QObject *parent = 0);
    ~C_UartComThread();
    void StartThread();                                                         // 开启线程
    void StopThread();                                                          // 停止线程
    void ConnectCom(QString comName, BaudRateType boartRate);                   // 连接串口
    void DisconnectCom();                                                       // 断开串口连接
    void SendData(QByteArray data);                                             // 通过串口对外发送数据

private:
    void run();                                 // 线程执行函数

signals://对外信号,外部可用相应的槽接收此信号
    void Signal_Connected();                      // 处理连接成功
    void Signal_DisConnected();                   // 处理连接断开
    void Signal_PushMsg(QString msg);           // 推送信息
    void Signal_ReciveData(QByteArray data);    // 收到数据向外发送,转交业务处理线程处理

signals://对内信号,外部不使用
    void Signal_ConnectCom(QString comName, BaudRateType boartRate);// 连接串口
    void Signal_DisconnectCom();                                    // 断开串口连接
    void Signal_SendData(QByteArray data);                          // 通过串口对外发送数据
};

#endif // C_UARTCOMTHREAD_H
