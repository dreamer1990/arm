#include "C_UartComThread.h"

/** <begin> **************************************C_UartComThreadSlots**************************************************/
C_UartComThreadSlots::C_UartComThreadSlots(QObject *parent) :
    QObject(parent)
{
    m_SerialPort = 0;
}


C_UartComThreadSlots::~C_UartComThreadSlots()
{
    DisconnectCom();
}


void C_UartComThreadSlots::PushMsg(QString msg)                  // 推送添加来源的信息
{
    emit Signal_PushMsg(msg.prepend("C_UartComThreadSlots:"));
}


void C_UartComThreadSlots::Exception(QString exceptDisc)         // 异常处理
{
    PushMsg(exceptDisc);
    emit Signal_DisConnected();
}


bool C_UartComThreadSlots::ConnectCom(QString comName, BaudRateType boartRate, QString &errMsg)   // 连接串口
{
    DisconnectCom();
    m_SerialPort = new Posix_QextSerialPort(comName, QextSerialBase::Polling);  // 只能用轮循的方式
    m_SerialPort->setBaudRate(boartRate);
    m_SerialPort->setDataBits(DATA_8);
    m_SerialPort->setParity(PAR_NONE);
    m_SerialPort->setStopBits(STOP_1);
    m_SerialPort->setFlowControl(FLOW_OFF); //设置数据流控制，我们使用无数据流控制的默认设置
    m_SerialPort->setTimeout(1); //设置延时 设置为1时读取才不会有延时问题
    if(!m_SerialPort->open(QIODevice::ReadWrite))
    {
        errMsg = QString("串口打开失败:%1").arg(m_SerialPort->errorString());
        delete m_SerialPort;
        m_SerialPort = 0;
        return false;
    }
    if(!connect(&m_TimerReadCom, SIGNAL(timeout()), this, SLOT(Slot_ReciveData()), Qt::QueuedConnection))
    {
        errMsg = "connect(m_TimerReadCom) failed";
        return false;
    }
    m_TimerReadCom.start(THREAD_WAIT);
    return true;
}


void C_UartComThreadSlots::DisconnectCom()                                                 // 断开串口连接
{
    if(!m_SerialPort)
    { return; }
    disconnect(&m_TimerReadCom, SIGNAL(timeout()), this, SLOT(Slot_ReciveData()));
    m_TimerReadCom.stop();
    m_SerialPort->close();
    delete m_SerialPort;
    m_SerialPort = 0;
}


bool C_UartComThreadSlots::SendData(QByteArray data, QString &errMsg)                      // 通过串口对外发送数据
{
    if(m_SerialPort->write(data) == -1)
    {
        errMsg = m_SerialPort->errorString();
        return false;
    }
    return true;
}


void C_UartComThreadSlots::Slot_ReciveData()                                                // 处理接收到的数据
{
    int bytesAvailable = m_SerialPort->bytesAvailable();
    if(bytesAvailable <= 0)
    { return; }
    emit Signal_ReciveData(m_SerialPort->read(bytesAvailable));
}


void C_UartComThreadSlots::Slot_ConnectCom(QString comName, BaudRateType boartRate)        // 连接串口
{
    QString errMsg;
    if(!ConnectCom(comName, boartRate, errMsg))
    {
        PushMsg(errMsg);
        return;
    }
    emit Signal_Connected();
}


void C_UartComThreadSlots::Slot_DisconnectCom()                              // 断开串口连接
{
    DisconnectCom();
    emit Signal_DisConnected();
}


void C_UartComThreadSlots::Slot_SendData(QByteArray data)                    // 通过串口对外发送数据
{
    QString errMsg;
    if(!SendData(data, errMsg))
    {
        PushMsg(errMsg);
        return;
    }
}
/** <end> **************************************C_UartComThreadSlots**************************************************/




/** <begin> **************************************C_UartComThread**************************************************/
C_UartComThread::C_UartComThread(QObject *parent) :
    QThread(parent)
{
}


C_UartComThread::~C_UartComThread()
{
    StopThread();
}


void C_UartComThread::StartThread()                                                         // 开启线程
{
    StopThread();
    start();
}


void C_UartComThread::StopThread()                                                          // 停止线程
{
    if(!isRunning())
    { return; }
    exit();
    wait(THREAD_WAIT*3);
}


void C_UartComThread::ConnectCom(QString comName, BaudRateType boartRate)  // 连接串口
{
    emit Signal_ConnectCom(comName, boartRate);

}


void C_UartComThread::DisconnectCom()                                                       // 断开串口连接
{
    emit Signal_DisconnectCom();
}


void C_UartComThread::SendData(QByteArray data)                            // 通过串口对外发送数据
{
    emit Signal_SendData(data);
}


void C_UartComThread::run()                                 // 线程执行函数
{
    C_UartComThreadSlots * uartComThreadSlots = 0;
    uartComThreadSlots = new C_UartComThreadSlots(this->parent());
    qRegisterMetaType<BaudRateType>();
    connect(this, SIGNAL(Signal_ConnectCom(QString,BaudRateType)), uartComThreadSlots, SLOT(Slot_ConnectCom(QString,BaudRateType)), Qt::QueuedConnection);
    connect(this, SIGNAL(Signal_DisconnectCom()), uartComThreadSlots, SLOT(Slot_DisconnectCom()), Qt::QueuedConnection);
    connect(this, SIGNAL(Signal_SendData(QByteArray)), uartComThreadSlots, SLOT(Slot_SendData(QByteArray)), Qt::QueuedConnection);
    connect(uartComThreadSlots, SIGNAL(Signal_PushMsg(QString)), this, SIGNAL(Signal_PushMsg(QString)));
    connect(uartComThreadSlots, SIGNAL(Signal_ReciveData(QByteArray)), this, SIGNAL(Signal_ReciveData(QByteArray)));
    connect(uartComThreadSlots, SIGNAL(Signal_Connected()), this, SIGNAL(Signal_Connected()));
    connect(uartComThreadSlots, SIGNAL(Signal_DisConnected()), this, SIGNAL(Signal_DisConnected()));
    exec();
    delete uartComThreadSlots;
}
/** <end> **************************************C_UartComThread**************************************************/
