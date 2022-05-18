/****************************************************************************
** Meta object code from reading C++ file 'customtrip.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../customtrip.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customtrip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_customtrip_t {
    const uint offsetsAndSize[24];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_customtrip_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_customtrip_t qt_meta_stringdata_customtrip = {
    {
QT_MOC_LITERAL(0, 10), // "customtrip"
QT_MOC_LITERAL(11, 32), // "on_pushButton_addCollege_clicked"
QT_MOC_LITERAL(44, 0), // ""
QT_MOC_LITERAL(45, 28), // "on_pushButton_return_clicked"
QT_MOC_LITERAL(74, 32), // "on_pushButton_clearTable_clicked"
QT_MOC_LITERAL(107, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(135, 17), // "fillSouvenirCombo"
QT_MOC_LITERAL(153, 18), // "changeCollegeLabel"
QT_MOC_LITERAL(172, 26), // "on_pushButton_next_clicked"
QT_MOC_LITERAL(199, 29), // "on_pushButton_confirm_clicked"
QT_MOC_LITERAL(229, 14), // "updateDistance"
QT_MOC_LITERAL(244, 28) // "on_pushButton_addAll_clicked"

    },
    "customtrip\0on_pushButton_addCollege_clicked\0"
    "\0on_pushButton_return_clicked\0"
    "on_pushButton_clearTable_clicked\0"
    "on_pushButton_start_clicked\0"
    "fillSouvenirCombo\0changeCollegeLabel\0"
    "on_pushButton_next_clicked\0"
    "on_pushButton_confirm_clicked\0"
    "updateDistance\0on_pushButton_addAll_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customtrip[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void customtrip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<customtrip *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_addCollege_clicked(); break;
        case 1: _t->on_pushButton_return_clicked(); break;
        case 2: _t->on_pushButton_clearTable_clicked(); break;
        case 3: _t->on_pushButton_start_clicked(); break;
        case 4: _t->fillSouvenirCombo(); break;
        case 5: _t->changeCollegeLabel(); break;
        case 6: _t->on_pushButton_next_clicked(); break;
        case 7: _t->on_pushButton_confirm_clicked(); break;
        case 8: _t->updateDistance(); break;
        case 9: _t->on_pushButton_addAll_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject customtrip::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_customtrip.offsetsAndSize,
    qt_meta_data_customtrip,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_customtrip_t
, QtPrivate::TypeAndForceComplete<customtrip, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *customtrip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customtrip::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_customtrip.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int customtrip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
