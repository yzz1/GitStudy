/****************************************************************************
** Meta object code from reading C++ file 'baseview.h'
**
** Created: Wed May 4 11:51:47 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/common/baseview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baseview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BaseView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      17,   10,    9,    9, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_BaseView[] = {
    "BaseView\0\0viewId\0forward(int)\0"
};

void BaseView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BaseView *_t = static_cast<BaseView *>(_o);
        switch (_id) {
        case 0: _t->forward((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BaseView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BaseView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BaseView,
      qt_meta_data_BaseView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BaseView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BaseView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BaseView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BaseView))
        return static_cast<void*>(const_cast< BaseView*>(this));
    return QDialog::qt_metacast(_clname);
}

int BaseView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
