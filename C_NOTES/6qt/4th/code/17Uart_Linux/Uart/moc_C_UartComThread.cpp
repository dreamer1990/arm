/****************************************************************************
** Meta object code from reading C++ file 'C_UartComThread.h'
**
** Created: Wed Dec 16 12:51:44 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tools/C_UartComThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'C_UartComThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_C_UartComThreadSlots[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      41,   21,   21,   21, 0x05,
      67,   63,   21,   21, 0x05,
      96,   91,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     144,  126,   21,   21, 0x0a,
     182,   21,   21,   21, 0x0a,
     203,   91,   21,   21, 0x0a,
     229,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_C_UartComThreadSlots[] = {
    "C_UartComThreadSlots\0\0Signal_Connected()\0"
    "Signal_DisConnected()\0msg\0"
    "Signal_PushMsg(QString)\0data\0"
    "Signal_ReciveData(QByteArray)\0"
    "comName,boartRate\0"
    "Slot_ConnectCom(QString,BaudRateType)\0"
    "Slot_DisconnectCom()\0Slot_SendData(QByteArray)\0"
    "Slot_ReciveData()\0"
};

const QMetaObject C_UartComThreadSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_C_UartComThreadSlots,
      qt_meta_data_C_UartComThreadSlots, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &C_UartComThreadSlots::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *C_UartComThreadSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *C_UartComThreadSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_C_UartComThreadSlots))
        return static_cast<void*>(const_cast< C_UartComThreadSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int C_UartComThreadSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Signal_Connected(); break;
        case 1: Signal_DisConnected(); break;
        case 2: Signal_PushMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: Signal_ReciveData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: Slot_ConnectCom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< BaudRateType(*)>(_a[2]))); break;
        case 5: Slot_DisconnectCom(); break;
        case 6: Slot_SendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: Slot_ReciveData(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void C_UartComThreadSlots::Signal_Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void C_UartComThreadSlots::Signal_DisConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void C_UartComThreadSlots::Signal_PushMsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void C_UartComThreadSlots::Signal_ReciveData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
static const uint qt_meta_data_C_UartComThread[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      36,   16,   16,   16, 0x05,
      62,   58,   16,   16, 0x05,
      91,   86,   16,   16, 0x05,
     139,  121,   16,   16, 0x05,
     179,   16,   16,   16, 0x05,
     202,   86,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_C_UartComThread[] = {
    "C_UartComThread\0\0Signal_Connected()\0"
    "Signal_DisConnected()\0msg\0"
    "Signal_PushMsg(QString)\0data\0"
    "Signal_ReciveData(QByteArray)\0"
    "comName,boartRate\0"
    "Signal_ConnectCom(QString,BaudRateType)\0"
    "Signal_DisconnectCom()\0"
    "Signal_SendData(QByteArray)\0"
};

const QMetaObject C_UartComThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_C_UartComThread,
      qt_meta_data_C_UartComThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &C_UartComThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *C_UartComThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *C_UartComThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_C_UartComThread))
        return static_cast<void*>(const_cast< C_UartComThread*>(this));
    return QThread::qt_metacast(_clname);
}

int C_UartComThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Signal_Connected(); break;
        case 1: Signal_DisConnected(); break;
        case 2: Signal_PushMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: Signal_ReciveData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: Signal_ConnectCom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< BaudRateType(*)>(_a[2]))); break;
        case 5: Signal_DisconnectCom(); break;
        case 6: Signal_SendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void C_UartComThread::Signal_Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void C_UartComThread::Signal_DisConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void C_UartComThread::Signal_PushMsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void C_UartComThread::Signal_ReciveData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void C_UartComThread::Signal_ConnectCom(QString _t1, BaudRateType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void C_UartComThread::Signal_DisconnectCom()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void C_UartComThread::Signal_SendData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
