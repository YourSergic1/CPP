/****************************************************************************
** Meta object code from reading C++ file 'myopenglwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../3DViewer/headers/myopenglwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myopenglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyOpenGLWidget_t {
    const uint offsetsAndSize[38];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MyOpenGLWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MyOpenGLWidget_t qt_meta_stringdata_MyOpenGLWidget = {
    {
QT_MOC_LITERAL(0, 14), // "MyOpenGLWidget"
QT_MOC_LITERAL(15, 18), // "toggleAutoRotation"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 14), // "toggleDrawMode"
QT_MOC_LITERAL(50, 11), // "openFileObj"
QT_MOC_LITERAL(62, 14), // "openFileDialog"
QT_MOC_LITERAL(77, 14), // "affineRotation"
QT_MOC_LITERAL(92, 9), // "direction"
QT_MOC_LITERAL(102, 4), // "axis"
QT_MOC_LITERAL(107, 17), // "affineTranslation"
QT_MOC_LITERAL(125, 11), // "affineScale"
QT_MOC_LITERAL(137, 19), // "switchisPerspecProj"
QT_MOC_LITERAL(157, 16), // "switchDashedLine"
QT_MOC_LITERAL(174, 17), // "switchDrawVerices"
QT_MOC_LITERAL(192, 17), // "switchRadiusPoint"
QT_MOC_LITERAL(210, 3), // "dir"
QT_MOC_LITERAL(214, 14), // "switchSizeLine"
QT_MOC_LITERAL(229, 19), // "affineRotationMouse"
QT_MOC_LITERAL(249, 9) // "deltaBase"

    },
    "MyOpenGLWidget\0toggleAutoRotation\0\0"
    "toggleDrawMode\0openFileObj\0openFileDialog\0"
    "affineRotation\0direction\0axis\0"
    "affineTranslation\0affineScale\0"
    "switchisPerspecProj\0switchDashedLine\0"
    "switchDrawVerices\0switchRadiusPoint\0"
    "dir\0switchSizeLine\0affineRotationMouse\0"
    "deltaBase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyOpenGLWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x0a,    1 /* Public */,
       3,    0,   87,    2, 0x0a,    2 /* Public */,
       4,    1,   88,    2, 0x0a,    3 /* Public */,
       6,    2,   91,    2, 0x0a,    5 /* Public */,
       9,    2,   96,    2, 0x0a,    8 /* Public */,
      10,    1,  101,    2, 0x0a,   11 /* Public */,
      11,    0,  104,    2, 0x0a,   13 /* Public */,
      12,    0,  105,    2, 0x0a,   14 /* Public */,
      13,    0,  106,    2, 0x0a,   15 /* Public */,
      14,    1,  107,    2, 0x0a,   16 /* Public */,
      16,    1,  110,    2, 0x0a,   18 /* Public */,
      17,    2,  113,    2, 0x0a,   20 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,   18,    8,

       0        // eod
};

void MyOpenGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyOpenGLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->toggleAutoRotation(); break;
        case 1: _t->toggleDrawMode(); break;
        case 2: _t->openFileObj((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->affineRotation((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->affineTranslation((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->affineScale((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->switchisPerspecProj(); break;
        case 7: _t->switchDashedLine(); break;
        case 8: _t->switchDrawVerices(); break;
        case 9: _t->switchRadiusPoint((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->switchSizeLine((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->affineRotationMouse((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MyOpenGLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_MyOpenGLWidget.offsetsAndSize,
    qt_meta_data_MyOpenGLWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MyOpenGLWidget_t
, QtPrivate::TypeAndForceComplete<MyOpenGLWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MyOpenGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyOpenGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyOpenGLWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int MyOpenGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
