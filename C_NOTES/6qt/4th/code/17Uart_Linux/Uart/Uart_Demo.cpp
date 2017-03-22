#include "Uart_Demo.h"
#include "ui_Uart_Demo.h"

Uart_Demo::Uart_Demo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Uart_Demo)
{
    ui->setupUi(this);
    connect(&m_UartComThread, SIGNAL(Signal_Connected()), this, SLOT(Slot_Connected()));
    connect(&m_UartComThread, SIGNAL(Signal_DisConnected()), this, SLOT(Slot_DisConnected()));
    connect(&m_UartComThread, SIGNAL(Signal_ReciveData(QByteArray)), this, SLOT(Slot_ReciveData(QByteArray)));
    connect(&m_UartComThread, SIGNAL(Signal_PushMsg(QString)), this, SLOT(Slot_PushMsg(QString)));
    m_UartComThread.StartThread();
}

Uart_Demo::~Uart_Demo()
{
    m_UartComThread.StopThread();
    delete ui;
}

void Uart_Demo::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Uart_Demo::on_pushButton_Clear_clicked()
{
    ui->textBrowser_Log->clear();
}

void Uart_Demo::on_pushButton_Connect_clicked()
{
    QString comName;
//#ifdef __WINDOWS__
    //comName = ui->comboBox_SlectCom->currentText();
//#else
//    comName = QString("/dev/ttyS%1").arg(ui->comboBox_SlectCom->currentIndex());
//    comName = QString("/dev/ttyUSB0");//.arg(ui->comboBox_SlectCom->currentIndex());
//    comName = QString("/dev/ttyS0");//.arg(ui->comboBox_SlectCom->currentIndex());
    comName = QString("/dev/ttyUSB0");//.arg(ui->comboBox_SlectCom->currentIndex());
//#endif
    m_UartComThread.ConnectCom(comName, (BaudRateType)ui->comboBox_BoartRate->currentIndex());
}

void Uart_Demo::on_pushButton_Disconnect_clicked()
{
    m_UartComThread.DisconnectCom();
}

void Uart_Demo::on_pushButton_Send_clicked()
{
    QString Str ;
//    Str = "AT\r\n";
    if(ui->lineEdit_SendContent->text().compare("YES") == 0)
        Str.append("\x1a\r\n"   ) ;
    else
        Str.append(ui->lineEdit_SendContent->text()).append("\r\n") ;
//qDebug() << "Str: " << Str ;
    //    Str.append().append("AAAAA");
//    Str.append("001");
//    QChar ch(0x12);
//    Str.append(ch).append("AAAA");
//    int i = 0 ;
//    for(i = 0 ; i < 10000 ;i++)
//    {
//        QChar ch(0x12);
//        QString Str ;
//        Str.append(ch).append("abc123\r\n");
//    QChar ch ;
//    m_UartComThread.SendData(ui->lineEdit_SendContent->text().toLocal8Bit());
//    qDebug() << "hello" ;
    m_UartComThread.SendData(Str.toLocal8Bit());
//    usleep(1000*1000); m m m 7i
//    }




}


void Uart_Demo::Slot_Connected()                      // 处理连接成功
{
    ui->pushButton_Connect->setEnabled(false);
    ui->pushButton_Disconnect->setEnabled(true);
    ui->lineEdit_SendContent->setEnabled(true);
    ui->pushButton_Send->setEnabled(true);
}


void Uart_Demo::Slot_DisConnected()                   // 处理连接断开
{
    ui->pushButton_Connect->setEnabled(true);
    ui->pushButton_Disconnect->setEnabled(false);
    ui->lineEdit_SendContent->setEnabled(false);
    ui->pushButton_Send->setEnabled(false);
}


void Uart_Demo::Slot_PushMsg(QString msg)           // 推送信息
{
    ui->textBrowser_Log->append(msg);
}


void Uart_Demo::Slot_ReciveData(QByteArray data)    // 收到数据向外发送,转交业务处理线程处理
{
    ui->textBrowser_Log->append(QString(data).prepend("收到数据:"));
}
