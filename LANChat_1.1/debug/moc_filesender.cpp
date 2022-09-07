/****************************************************************************
** Meta object code from reading C++ file 'filesender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filesender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FIleSender_t {
    QByteArrayData data[25];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FIleSender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FIleSender_t qt_meta_stringdata_FIleSender = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FIleSender"
QT_MOC_LITERAL(1, 11, 15), // "DataBytesChange"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "TotalBytes"
QT_MOC_LITERAL(4, 39, 12), // "bytesWritten"
QT_MOC_LITERAL(5, 52, 12), // "bytesToWrite"
QT_MOC_LITERAL(6, 65, 11), // "payloadSize"
QT_MOC_LITERAL(7, 77, 5), // "speed"
QT_MOC_LITERAL(8, 83, 8), // "usedtime"
QT_MOC_LITERAL(9, 92, 11), // "errorString"
QT_MOC_LITERAL(10, 104, 5), // "error"
QT_MOC_LITERAL(11, 110, 16), // "fileSendComplete"
QT_MOC_LITERAL(12, 127, 12), // "SenderCreate"
QT_MOC_LITERAL(13, 140, 11), // "FIleSender*"
QT_MOC_LITERAL(14, 152, 13), // "onefileSender"
QT_MOC_LITERAL(15, 166, 6), // "RecyIP"
QT_MOC_LITERAL(16, 173, 12), // "CreateSocket"
QT_MOC_LITERAL(17, 186, 7), // "qintptr"
QT_MOC_LITERAL(18, 194, 16), // "socketDescriptor"
QT_MOC_LITERAL(19, 211, 16), // "SenderStart_slot"
QT_MOC_LITERAL(20, 228, 8), // "FileName"
QT_MOC_LITERAL(21, 237, 8), // "FilePath"
QT_MOC_LITERAL(22, 246, 5), // "dlgid"
QT_MOC_LITERAL(23, 252, 17), // "updataSendProgess"
QT_MOC_LITERAL(24, 270, 7) // "ByteNum"

    },
    "FIleSender\0DataBytesChange\0\0TotalBytes\0"
    "bytesWritten\0bytesToWrite\0payloadSize\0"
    "speed\0usedtime\0errorString\0error\0"
    "fileSendComplete\0SenderCreate\0FIleSender*\0"
    "onefileSender\0RecyIP\0CreateSocket\0"
    "qintptr\0socketDescriptor\0SenderStart_slot\0"
    "FileName\0FilePath\0dlgid\0updataSendProgess\0"
    "ByteNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FIleSender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   49,    2, 0x06 /* Public */,
       9,    1,   62,    2, 0x06 /* Public */,
      11,    0,   65,    2, 0x06 /* Public */,
      12,    2,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,   71,    2, 0x08 /* Private */,
      19,    5,   74,    2, 0x08 /* Private */,
      23,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString,   14,   15,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::Int,   14,   20,   21,    6,   22,
    QMetaType::Void, QMetaType::LongLong,   24,

       0        // eod
};

void FIleSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FIleSender *_t = static_cast<FIleSender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataBytesChange((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 1: _t->errorString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fileSendComplete(); break;
        case 3: _t->SenderCreate((*reinterpret_cast< FIleSender*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->CreateSocket((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 5: _t->SenderStart_slot((*reinterpret_cast< FIleSender*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 6: _t->updataSendProgess((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
            typedef void (FIleSender::*_t)(qint64 , qint64 , qint64 , qint64 , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FIleSender::DataBytesChange)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FIleSender::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FIleSender::errorString)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FIleSender::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FIleSender::fileSendComplete)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FIleSender::*_t)(FIleSender * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FIleSender::SenderCreate)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject FIleSender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FIleSender.data,
      qt_meta_data_FIleSender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FIleSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FIleSender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FIleSender.stringdata0))
        return static_cast<void*>(const_cast< FIleSender*>(this));
    return QObject::qt_metacast(_clname);
}

int FIleSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FIleSender::DataBytesChange(qint64 _t1, qint64 _t2, qint64 _t3, qint64 _t4, double _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FIleSender::errorString(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FIleSender::fileSendComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FIleSender::SenderCreate(FIleSender * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
