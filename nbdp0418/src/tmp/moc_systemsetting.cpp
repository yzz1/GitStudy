/****************************************************************************
** Meta object code from reading C++ file 'systemsetting.h'
**
** Created: Wed May 4 11:52:08 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/system/systemsetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SystemSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   15,   14,   14, 0x05,
     111,   94,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     137,   14,   14,   14, 0x0a,
     155,   14,   14,   14, 0x0a,
     176,   14,   14,   14, 0x0a,
     194,   14,   14,   14, 0x0a,
     213,   14,   14,   14, 0x0a,
     248,   15,   14,   14, 0x0a,
     306,  301,   14,   14, 0x0a,
     346,  301,   14,   14, 0x0a,
     387,  301,   14,   14, 0x0a,
     428,  301,   14,   14, 0x0a,
     469,  301,   14,   14, 0x0a,
     510,  301,   14,   14, 0x0a,
     551,  301,   14,   14, 0x0a,
     592,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SystemSetting[] = {
    "SystemSetting\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "realTimePrinting\0realTimePrinting(QString)\0"
    "homeClickedSlot()\0settingClickedSlot()\0"
    "testClickedSlot()\0aboutClickedSlot()\0"
    "identificationSettingClickedSlot()\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
    "item\0listwidgetClickedSlot(QListWidgetItem*)\0"
    "listwidget2ClickedSlot(QListWidgetItem*)\0"
    "listwidget3ClickedSlot(QListWidgetItem*)\0"
    "listwidget4ClickedSlot(QListWidgetItem*)\0"
    "listwidget5ClickedSlot(QListWidgetItem*)\0"
    "listwidget6ClickedSlot(QListWidgetItem*)\0"
    "listwidget7ClickedSlot(QListWidgetItem*)\0"
    "dateTimeButtonClick()\0"
};

void SystemSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SystemSetting *_t = static_cast<SystemSetting *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->realTimePrinting((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->homeClickedSlot(); break;
        case 3: _t->settingClickedSlot(); break;
        case 4: _t->testClickedSlot(); break;
        case 5: _t->aboutClickedSlot(); break;
        case 6: _t->identificationSettingClickedSlot(); break;
        case 7: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 8: _t->listwidgetClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->listwidget2ClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->listwidget3ClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->listwidget4ClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->listwidget5ClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: _t->listwidget6ClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->listwidget7ClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 15: _t->dateTimeButtonClick(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SystemSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SystemSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SystemSetting,
      qt_meta_data_SystemSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SystemSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SystemSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SystemSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SystemSetting))
        return static_cast<void*>(const_cast< SystemSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int SystemSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SystemSetting::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SystemSetting::realTimePrinting(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
