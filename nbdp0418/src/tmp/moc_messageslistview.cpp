/****************************************************************************
** Meta object code from reading C++ file 'messageslistview.h'
**
** Created: Wed May 4 11:51:59 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/messages/messageslistview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messageslistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MessagesListView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   18,   17,   17, 0x05,
     107,   97,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     130,   18,   17,   17, 0x0a,
     183,   17,   17,   17, 0x0a,
     201,   17,   17,   17, 0x0a,
     221,   17,   17,   17, 0x0a,
     244,   17,   17,   17, 0x0a,
     264,   17,   17,   17, 0x0a,
     283,   17,   17,   17, 0x0a,
     303,   17,   17,   17, 0x0a,
     321,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MessagesListView[] = {
    "MessagesListView\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "hasUnread\0hasUnreadMessage(bool)\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
    "homeClickedSlot()\0selectClickedSlot()\0"
    "selectAllClickedSlot()\0deleteSelectedRow()\0"
    "inBoxClickedSlot()\0outBoxClickedSlot()\0"
    "openClickedSlot()\0exportClickedSlot()\0"
};

void MessagesListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MessagesListView *_t = static_cast<MessagesListView *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->hasUnreadMessage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 3: _t->homeClickedSlot(); break;
        case 4: _t->selectClickedSlot(); break;
        case 5: _t->selectAllClickedSlot(); break;
        case 6: _t->deleteSelectedRow(); break;
        case 7: _t->inBoxClickedSlot(); break;
        case 8: _t->outBoxClickedSlot(); break;
        case 9: _t->openClickedSlot(); break;
        case 10: _t->exportClickedSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MessagesListView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MessagesListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MessagesListView,
      qt_meta_data_MessagesListView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MessagesListView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MessagesListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MessagesListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessagesListView))
        return static_cast<void*>(const_cast< MessagesListView*>(this));
    return QWidget::qt_metacast(_clname);
}

int MessagesListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MessagesListView::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessagesListView::hasUnreadMessage(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
