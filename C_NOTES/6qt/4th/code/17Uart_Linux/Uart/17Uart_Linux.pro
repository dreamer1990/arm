#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T16:45:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Uart
TEMPLATE = app

INCLUDEPATH += Tools

SOURCES += main.cpp\
        Uart_Demo.cpp \
    Tools/posix_qextserialport.cpp \
    Tools/qextserialbase.cpp \
    Tools/C_UartComThread.cpp

HEADERS  += Uart_Demo.h \
    Tools/posix_qextserialport.h \
    Tools/qextserialbase.h \
    Tools/C_UartComThread.h

FORMS    += Uart_Demo.ui
