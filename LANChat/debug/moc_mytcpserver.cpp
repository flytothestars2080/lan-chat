/****************************************************************************
** Meta object code from reading C++ file 'mytcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mytcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyTcpServer_t {
    QByteArrayData data[18];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTcpServer_t qt_meta_stringdata_MyTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyTcpServer"
QT_MOC_LITERAL(1, 12, 19), // "newFileSenderCreate"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "FIleSender*"
QT_MOC_LITERAL(4, 45, 13), // "onefileSender"
QT_MOC_LITERAL(5, 59, 6), // "RecyIP"
QT_MOC_LITERAL(6, 66, 15), // "CreateNewSocket"
QT_MOC_LITERAL(7, 82, 7), // "qintptr"
QT_MOC_LITERAL(8, 90, 16), // "socketDescriptor"
QT_MOC_LITERAL(9, 107, 11), // "SenderStart"
QT_MOC_LITERAL(10, 119, 8), // "FileName"
QT_MOC_LITERAL(11, 128, 8), // "FilePath"
QT_MOC_LITERAL(12, 137, 11), // "payloadSize"
QT_MOC_LITERAL(13, 149, 5), // "dlgid"
QT_MOC_LITERAL(14, 155, 18), // "RemoveSenderAtList"
QT_MOC_LITERAL(15, 174, 6), // "sender"
QT_MOC_LITERAL(16, 181, 18), // "RemoveThreadAtList"
QT_MOC_LITERAL(17, 200, 17) // "SenderCreate_Slot"

    },
    "MyTcpServer\0newFileSenderCreate\0\0"
    "FIleSender*\0onefileSender\0RecyIP\0"
    "CreateNewSocket\0qintptr\0socketDescriptor\0"
    "SenderStart\0FileName\0FilePath\0payloadSize\0"
    "dlgid\0RemoveSenderAtList\0sender\0"
    "RemoveThreadAtList\0SenderCreate_Slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTcpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,
       9,    5,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   63,    2, 0x08 /* Private */,
      16,    1,   66,    2, 0x08 /* Private */,
      17,    2,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::Int,    4,   10,   11,   12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,   15,
    QMetaType::Void, QMetaType::QObjectStar,   15,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

       0        // eod
};

void MyTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTcpServer *_t = static_cast<MyTcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newFileSenderCreate((*reinterpret_cast< FIleSender*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->CreateNewSocket((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 2: _t->SenderStart((*reinterpret_cast< FIleSender*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->RemoveSenderAtList((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 4: _t->RemoveThreadAtList((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 5: _t->SenderCreate_Slot((*reinterpret_cast< FIleSender*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FIleSender* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FIleSender* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FIleSender* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTcpServer::*_t)(FIleSender * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::newFileSenderCreate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyTcpServer::*_t)(qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::CreateNewSocket)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyTcpServer::*_t)(FIleSender * , QString , QString , qint64 , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::SenderStart)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MyTcpServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_MyTcpServer.data,
      qt_meta_data_MyTcpServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyTcpServer.stringdata0))
        return static_cast<void*>(const_cast< MyTcpServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int MyTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MyTcpServer::newFileSenderCreate(FIleSender * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTcpServer::CreateNewSocket(qintptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTcpServer::SenderStart(FIleSender * _t1, QString _t2, QString _t3, qint64 _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
