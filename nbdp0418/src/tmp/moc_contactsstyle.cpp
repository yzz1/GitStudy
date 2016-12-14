/****************************************************************************
** Meta object code from reading C++ file 'contactsstyle.h'
**
** Created: Wed May 4 11:51:55 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/contacts/contactsstyle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactsstyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContactsStyle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       5,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      23,   14,   15,   14, 0x02,
      43,   14,   15,   14, 0x02,
      69,   14,   65,   14, 0x02,
      91,   14,   65,   14, 0x02,
     121,   14,  114,   14, 0x02,
     159,  144,   14,   14, 0x02,
     186,  144,   14,   14, 0x02,
     227,  215,   14,   14, 0x02,
     273,  252,   14,   14, 0x02,
     320,  299,   14,   14, 0x02,

 // properties: name, type, flags
     349,   15, 0x0a095103,
     364,   15, 0x0a095103,
     381,   65, 0x02095103,
     398,   65, 0x02095103,
     416,  114, 0x43095103,

       0        // eod
};

static const char qt_meta_stringdata_ContactsStyle[] = {
    "ContactsStyle\0\0QString\0getSelectedPixmap()\0"
    "getNoSelectedPixmap()\0int\0"
    "getSelectedFontSize()\0getPixmapColummIndex()\0"
    "QColor\0getSelectedFontColor()\0"
    "strResourceURL\0setSelectedPixmap(QString)\0"
    "setNoSelectedPixmap(QString)\0intFontSize\0"
    "setSelectedFontSize(int)\0intPixmapColummIndex\0"
    "setPixmapColummIndex(int)\0"
    "strSelectedFontColor\0setSelectedFontColor(QColor)\0"
    "selectedPixmap\0noSelectedPixmap\0"
    "selectedFontSize\0pixmapColummIndex\0"
    "selectedFontColor\0"
};

void ContactsStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ContactsStyle *_t = static_cast<ContactsStyle *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->getSelectedPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->getNoSelectedPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->getSelectedFontSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->getPixmapColummIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { QColor _r = _t->getSelectedFontColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 5: _t->setSelectedPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setNoSelectedPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setSelectedFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setPixmapColummIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setSelectedFontColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ContactsStyle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ContactsStyle::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ContactsStyle,
      qt_meta_data_ContactsStyle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactsStyle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactsStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactsStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsStyle))
        return static_cast<void*>(const_cast< ContactsStyle*>(this));
    return QWidget::qt_metacast(_clname);
}

int ContactsStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getSelectedPixmap(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getNoSelectedPixmap(); break;
        case 2: *reinterpret_cast< int*>(_v) = getSelectedFontSize(); break;
        case 3: *reinterpret_cast< int*>(_v) = getPixmapColummIndex(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = getSelectedFontColor(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setSelectedPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 1: setNoSelectedPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 2: setSelectedFontSize(*reinterpret_cast< int*>(_v)); break;
        case 3: setPixmapColummIndex(*reinterpret_cast< int*>(_v)); break;
        case 4: setSelectedFontColor(*reinterpret_cast< QColor*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
