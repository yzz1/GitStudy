/****************************************************************************
** Meta object code from reading C++ file 'stationeditview.h'
**
** Created: Wed May 4 11:51:57 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/contacts/stationeditview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stationeditview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StationEditView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   16,   96,   16, 0x0a,
     112,   17,   16,   16, 0x0a,
     165,   16,   16,   16, 0x0a,
     187,   16,   16,   16, 0x0a,
     210,   16,   16,   16, 0x0a,
     235,   16,   16,   16, 0x0a,
     253,   16,   16,   16, 0x0a,
     277,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StationEditView[] = {
    "StationEditView\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "bool\0saveData()\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
    "cancelButtonClicked()\0arrowUpButtonClicked()\0"
    "arrowDownButtonClicked()\0homeClickedSlot()\0"
    "individualClickedSlot()\0stationClickedSlot()\0"
};

void StationEditView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StationEditView *_t = static_cast<StationEditView *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: { bool _r = _t->saveData();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 3: _t->cancelButtonClicked(); break;
        case 4: _t->arrowUpButtonClicked(); break;
        case 5: _t->arrowDownButtonClicked(); break;
        case 6: _t->homeClickedSlot(); break;
        case 7: _t->individualClickedSlot(); break;
        case 8: _t->stationClickedSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StationEditView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StationEditView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StationEditView,
      qt_meta_data_StationEditView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StationEditView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StationEditView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StationEditView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StationEditView))
        return static_cast<void*>(const_cast< StationEditView*>(this));
    return QWidget::qt_metacast(_clname);
}

int StationEditView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void StationEditView::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
