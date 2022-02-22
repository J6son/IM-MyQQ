/****************************************************************************
** Meta object code from reading C++ file 'myqqdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyQQ/myqqdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myqqdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyQQDialog_t {
    QByteArrayData data[19];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQQDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQQDialog_t qt_meta_stringdata_MyQQDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyQQDialog"
QT_MOC_LITERAL(1, 11, 13), // "SIG_addFriend"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "name"
QT_MOC_LITERAL(4, 31, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 53, 14), // "slot_ReadyData"
QT_MOC_LITERAL(6, 68, 5), // "char*"
QT_MOC_LITERAL(7, 74, 3), // "buf"
QT_MOC_LITERAL(8, 78, 4), // "nlen"
QT_MOC_LITERAL(9, 83, 16), // "slot_LoginCommit"
QT_MOC_LITERAL(10, 100, 8), // "password"
QT_MOC_LITERAL(11, 109, 19), // "slot_RegisterCommit"
QT_MOC_LITERAL(12, 129, 15), // "slot_RegisterRs"
QT_MOC_LITERAL(13, 145, 12), // "slot_LoginRs"
QT_MOC_LITERAL(14, 158, 17), // "slot_ForceOffline"
QT_MOC_LITERAL(15, 176, 13), // "slot_dealMenu"
QT_MOC_LITERAL(16, 190, 8), // "QAction*"
QT_MOC_LITERAL(17, 199, 6), // "action"
QT_MOC_LITERAL(18, 206, 18) // "on_pb_menu_clicked"

    },
    "MyQQDialog\0SIG_addFriend\0\0name\0"
    "on_pushButton_clicked\0slot_ReadyData\0"
    "char*\0buf\0nlen\0slot_LoginCommit\0"
    "password\0slot_RegisterCommit\0"
    "slot_RegisterRs\0slot_LoginRs\0"
    "slot_ForceOffline\0slot_dealMenu\0"
    "QAction*\0action\0on_pb_menu_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQQDialog[] = {

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
       4,    0,   67,    2, 0x08 /* Private */,
       5,    2,   68,    2, 0x08 /* Private */,
       9,    2,   73,    2, 0x08 /* Private */,
      11,    2,   78,    2, 0x08 /* Private */,
      12,    2,   83,    2, 0x08 /* Private */,
      13,    2,   88,    2, 0x08 /* Private */,
      14,    2,   93,    2, 0x08 /* Private */,
      15,    1,   98,    2, 0x08 /* Private */,
      18,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   10,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,

       0        // eod
};

void MyQQDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyQQDialog *_t = static_cast<MyQQDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_addFriend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->slot_ReadyData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slot_LoginCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->slot_RegisterCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->slot_RegisterRs((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slot_LoginRs((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slot_ForceOffline((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->slot_dealMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 9: _t->on_pb_menu_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyQQDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyQQDialog::SIG_addFriend)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyQQDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MyQQDialog.data,
      qt_meta_data_MyQQDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyQQDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQQDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyQQDialog.stringdata0))
        return static_cast<void*>(const_cast< MyQQDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MyQQDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MyQQDialog::SIG_addFriend(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
