/****************************************************************************
** Meta object code from reading C++ file 'contactsindview.h'
**
** Created: Wed May 4 11:51:58 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/contacts/contactsindview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactsindview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContactsIndView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      96,   16,   16,   16, 0x0a,
     113,   16,   16,   16, 0x0a,
     133,   16,   16,   16, 0x0a,
     151,   16,   16,   16, 0x0a,
     168,   16,   16,   16, 0x0a,
     188,   16,   16,   16, 0x0a,
     206,   16,   16,   16, 0x0a,
     227,   16,   16,   16, 0x0a,
     247,   16,   16,   16, 0x0a,
     267,   16,   16,   16, 0x0a,
     286,   17,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ContactsIndView[] = {
    "ContactsIndView\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "showOptionMenu()\0deleteSelectedRow()\0"
    "editClickedSolt()\0newClickedSolt()\0"
    "cancelClickedSolt()\0homeClickedSlot()\0"
    "stationClickedSlot()\0importClickedSlot()\0"
    "exportClickedSlot()\0printClickedSlot()\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
};

void ContactsIndView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ContactsIndView *_t = static_cast<ContactsIndView *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->showOptionMenu(); break;
        case 2: _t->deleteSelectedRow(); break;
        case 3: _t->editClickedSolt(); break;
        case 4: _t->newClickedSolt(); break;
        case 5: _t->cancelClickedSolt(); break;
        case 6: _t->homeClickedSlot(); break;
        case 7: _t->stationClickedSlot(); break;
        case 8: _t->importClickedSlot(); break;
        case 9: _t->exportClickedSlot(); break;
        case 10: _t->printClickedSlot(); break;
        case 11: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ContactsIndView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ContactsIndView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ContactsIndView,
      qt_meta_data_ContactsIndView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactsIndView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactsIndView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactsIndView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsIndView))
        return static_cast<void*>(const_cast< ContactsIndView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ContactsIndView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ContactsIndView::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
