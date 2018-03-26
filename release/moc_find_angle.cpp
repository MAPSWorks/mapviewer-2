/****************************************************************************
** Meta object code from reading C++ file 'find_angle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../find_angle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'find_angle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Find_Angle_t {
    QByteArrayData data[12];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Find_Angle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Find_Angle_t qt_meta_stringdata_Find_Angle = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Find_Angle"
QT_MOC_LITERAL(1, 11, 9), // "send_Line"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "line"
QT_MOC_LITERAL(4, 27, 15), // "send_Coordinate"
QT_MOC_LITERAL(5, 43, 4), // "lati"
QT_MOC_LITERAL(6, 48, 5), // "longi"
QT_MOC_LITERAL(7, 54, 12), // "route_update"
QT_MOC_LITERAL(8, 67, 9), // "Take_Path"
QT_MOC_LITERAL(9, 77, 4), // "path"
QT_MOC_LITERAL(10, 82, 9), // "Take_Line"
QT_MOC_LITERAL(11, 92, 8) // "line_str"

    },
    "Find_Angle\0send_Line\0\0line\0send_Coordinate\0"
    "lati\0longi\0route_update\0Take_Path\0"
    "path\0Take_Line\0line_str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Find_Angle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,
       7,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   48,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void Find_Angle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Find_Angle *_t = static_cast<Find_Angle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_Line((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->send_Coordinate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->route_update(); break;
        case 3: _t->Take_Path((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Take_Line((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Find_Angle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Find_Angle::send_Line)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Find_Angle::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Find_Angle::send_Coordinate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Find_Angle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Find_Angle::route_update)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Find_Angle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Find_Angle.data,
      qt_meta_data_Find_Angle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Find_Angle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Find_Angle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Find_Angle.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Find_Angle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Find_Angle::send_Line(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Find_Angle::send_Coordinate(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Find_Angle::route_update()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
