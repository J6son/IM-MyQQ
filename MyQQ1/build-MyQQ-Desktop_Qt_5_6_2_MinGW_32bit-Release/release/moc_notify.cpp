/****************************************************************************
** Meta object code from reading C++ file 'notify.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyQQ/notify.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notify.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Notify_t {
    QByteArrayData data[16];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Notify_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Notify_t qt_meta_stringdata_Notify = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Notify"
QT_MOC_LITERAL(1, 7, 15), // "SIG_showChatDlg"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "id"
QT_MOC_LITERAL(4, 27, 18), // "on_pb_show_clicked"
QT_MOC_LITERAL(5, 46, 19), // "on_CloseWnd_clicked"
QT_MOC_LITERAL(6, 66, 8), // "showAsQQ"
QT_MOC_LITERAL(7, 75, 6), // "setMsg"
QT_MOC_LITERAL(8, 82, 4), // "name"
QT_MOC_LITERAL(9, 87, 3), // "msg"
QT_MOC_LITERAL(10, 91, 6), // "myMove"
QT_MOC_LITERAL(11, 98, 6), // "myStay"
QT_MOC_LITERAL(12, 105, 7), // "myClose"
QT_MOC_LITERAL(13, 113, 10), // "enterEvent"
QT_MOC_LITERAL(14, 124, 7), // "QEvent*"
QT_MOC_LITERAL(15, 132, 10) // "leaveEvent"

    },
    "Notify\0SIG_showChatDlg\0\0id\0"
    "on_pb_show_clicked\0on_CloseWnd_clicked\0"
    "showAsQQ\0setMsg\0name\0msg\0myMove\0myStay\0"
    "myClose\0enterEvent\0QEvent*\0leaveEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notify[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   67,    2, 0x0a /* Public */,
       5,    0,   68,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    3,   70,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,
      13,    1,   80,    2, 0x0a /* Public */,
      15,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString,    8,    3,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 14,    2,

       0        // eod
};

void Notify::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notify *_t = static_cast<Notify *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_showChatDlg((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->on_pb_show_clicked(); break;
        case 2: _t->on_CloseWnd_clicked(); break;
        case 3: _t->showAsQQ(); break;
        case 4: _t->setMsg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->myMove(); break;
        case 6: _t->myStay(); break;
        case 7: _t->myClose(); break;
        case 8: _t->enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 9: _t->leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Notify::*_t)(quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Notify::SIG_showChatDlg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Notify::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Notify.data,
      qt_meta_data_Notify,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Notify::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notify::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Notify.stringdata0))
        return static_cast<void*>(const_cast< Notify*>(this));
    return QWidget::qt_metacast(_clname);
}

int Notify::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Notify::SIG_showChatDlg(quint32 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
