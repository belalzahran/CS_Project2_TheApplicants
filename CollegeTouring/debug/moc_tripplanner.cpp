/****************************************************************************
** Meta object code from reading C++ file 'tripplanner.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tripplanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tripplanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TripPlanner_t {
    const uint offsetsAndSize[14];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TripPlanner_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TripPlanner_t qt_meta_stringdata_TripPlanner = {
    {
QT_MOC_LITERAL(0, 11), // "TripPlanner"
QT_MOC_LITERAL(12, 24), // "on_MSTpushButton_clicked"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 31), // "on_CustomTrippushButton_clicked"
QT_MOC_LITERAL(70, 24), // "on_DFSpushButton_clicked"
QT_MOC_LITERAL(95, 24), // "on_BFSpushButton_clicked"
QT_MOC_LITERAL(120, 14) // "updateComboBox"

    },
    "TripPlanner\0on_MSTpushButton_clicked\0"
    "\0on_CustomTrippushButton_clicked\0"
    "on_DFSpushButton_clicked\0"
    "on_BFSpushButton_clicked\0updateComboBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TripPlanner[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TripPlanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TripPlanner *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_MSTpushButton_clicked(); break;
        case 1: _t->on_CustomTrippushButton_clicked(); break;
        case 2: _t->on_DFSpushButton_clicked(); break;
        case 3: _t->on_BFSpushButton_clicked(); break;
        case 4: _t->updateComboBox(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TripPlanner::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TripPlanner.offsetsAndSize,
    qt_meta_data_TripPlanner,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TripPlanner_t
, QtPrivate::TypeAndForceComplete<TripPlanner, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TripPlanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TripPlanner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TripPlanner.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TripPlanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
