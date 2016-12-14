/****************************************************************************
** Meta object code from reading C++ file 'managerfileeditview.h'
**
** Created: Wed May 4 11:52:03 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/manager/managerfileeditview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerfileeditview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManagerFileEditView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      45,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,   20,   20,   20, 0x0a,
     111,   20,   20,   20, 0x0a,
     129,   20,   20,   20, 0x0a,
     149,   20,   20,   20, 0x0a,
     166,   20,   20,   20, 0x0a,
     184,   20,   20,   20, 0x0a,
     200,   20,   20,   20, 0x0a,
     217,   20,   20,   20, 0x0a,
     241,   20,   20,   20, 0x0a,
     259,   20,   20,   20, 0x0a,
     278,   20,   20,   20, 0x0a,
     295,   21,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ManagerFileEditView[] = {
    "ManagerFileEditView\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "saveData()\0homeClickedSlot()\0"
    "cancelClickedSlot()\0copyClicedSlot()\0"
    "pasteClicedSlot()\0cutClicedSlot()\0"
    "undoClicedSlot()\0phrasebookClickedSlot()\0"
    "fileClickedSlot()\0macroClickedSlot()\0"
    "inputCheckSlot()\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
};

void ManagerFileEditView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ManagerFileEditView *_t = static_cast<ManagerFileEditView *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->saveData(); break;
        case 2: _t->homeClickedSlot(); break;
        case 3: _t->cancelClickedSlot(); break;
        case 4: _t->copyClicedSlot(); break;
        case 5: _t->pasteClicedSlot(); break;
        case 6: _t->cutClicedSlot(); break;
        case 7: _t->undoClicedSlot(); break;
        case 8: _t->phrasebookClickedSlot(); break;
        case 9: _t->fileClickedSlot(); break;
        case 10: _t->macroClickedSlot(); break;
        case 11: _t->inputCheckSlot(); break;
        case 12: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ManagerFileEditView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ManagerFileEditView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ManagerFileEditView,
      qt_meta_data_ManagerFileEditView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManagerFileEditView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManagerFileEditView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManagerFileEditView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManagerFileEditView))
        return static_cast<void*>(const_cast< ManagerFileEditView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ManagerFileEditView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ManagerFileEditView::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
