/****************************************************************************
** Meta object code from reading C++ file 'college_list.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../college_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'college_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CollegeList_t {
    const uint offsetsAndSize[20];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CollegeList_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CollegeList_t qt_meta_stringdata_CollegeList = {
    {
QT_MOC_LITERAL(0, 11), // "CollegeList"
QT_MOC_LITERAL(12, 13), // "sumUndergrads"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 35), // "on_sortAlphabeticallyButton_c..."
QT_MOC_LITERAL(63, 28), // "on_sortByStateButton_clicked"
QT_MOC_LITERAL(92, 36), // "on_comboBoxState_currentIndex..."
QT_MOC_LITERAL(129, 5), // "index"
QT_MOC_LITERAL(135, 27), // "on_sortBySaddleback_clicked"
QT_MOC_LITERAL(163, 38), // "on_comboBoxCollege_currentInd..."
QT_MOC_LITERAL(202, 17) // "updateCollegeList"

    },
    "CollegeList\0sumUndergrads\0\0"
    "on_sortAlphabeticallyButton_clicked\0"
    "on_sortByStateButton_clicked\0"
    "on_comboBoxState_currentIndexChanged\0"
    "index\0on_sortBySaddleback_clicked\0"
    "on_comboBoxCollege_currentIndexChanged\0"
    "updateCollegeList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CollegeList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    1,   59,    2, 0x08,    4 /* Private */,
       7,    0,   62,    2, 0x08,    6 /* Private */,
       8,    1,   63,    2, 0x08,    7 /* Private */,
       9,    0,   66,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void CollegeList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CollegeList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sumUndergrads(); break;
        case 1: _t->on_sortAlphabeticallyButton_clicked(); break;
        case 2: _t->on_sortByStateButton_clicked(); break;
        case 3: _t->on_comboBoxState_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_sortBySaddleback_clicked(); break;
        case 5: _t->on_comboBoxCollege_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateCollegeList(); break;
        default: ;
        }
    }
}

const QMetaObject CollegeList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CollegeList.offsetsAndSize,
    qt_meta_data_CollegeList,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CollegeList_t
, QtPrivate::TypeAndForceComplete<CollegeList, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CollegeList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CollegeList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CollegeList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CollegeList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
