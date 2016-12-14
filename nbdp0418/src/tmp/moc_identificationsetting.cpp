/****************************************************************************
** Meta object code from reading C++ file 'identificationsetting.h'
**
** Created: Wed May 4 11:52:12 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/system/identificationsetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'identificationsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IdentificationSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      47,   23,   22,   22, 0x05,
     107,  102,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   22,   22,   22, 0x0a,
     142,   22,   22,   22, 0x0a,
     163,   22,   22,   22, 0x0a,
     181,   22,   22,   22, 0x0a,
     200,   22,   22,   22, 0x0a,
     222,   22,   22,   22, 0x0a,
     248,   23,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IdentificationSetting[] = {
    "IdentificationSetting\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "mmsi\0setMMSI(QString)\0homeClickedSlot()\0"
    "settingClickedSlot()\0testClickedSlot()\0"
    "aboutClickedSlot()\0okButtonClickedSlot()\0"
    "cancelButtonClickedSlot()\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
};

void IdentificationSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IdentificationSetting *_t = static_cast<IdentificationSetting *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->setMMSI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->homeClickedSlot(); break;
        case 3: _t->settingClickedSlot(); break;
        case 4: _t->testClickedSlot(); break;
        case 5: _t->aboutClickedSlot(); break;
        case 6: _t->okButtonClickedSlot(); break;
        case 7: _t->cancelButtonClickedSlot(); break;
        case 8: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData IdentificationSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IdentificationSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IdentificationSetting,
      qt_meta_data_IdentificationSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IdentificationSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IdentificationSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IdentificationSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IdentificationSetting))
        return static_cast<void*>(const_cast< IdentificationSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int IdentificationSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void IdentificationSetting::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IdentificationSetting::setMMSI(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
