/****************************************************************************
** Meta object code from reading C++ file 'applicationui.hpp'
**
** Created: Thu Oct 24 14:43:27 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/applicationui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x02,
      41,   14,   14,   14, 0x02,
      57,   14,   52,   14, 0x02,
      69,   14,   14,   14, 0x02,
      81,   14,   52,   14, 0x02,
     100,   14,   14,   14, 0x02,
     134,  119,   14,   14, 0x02,
     157,   14,   14,   14, 0x02,
     177,  172,   14,   14, 0x02,
     235,  216,   14,   14, 0x02,
     277,  272,   14,   14, 0x02,
     305,  298,   14,   14, 0x02,
     332,  328,   14,   14, 0x02,
     365,  355,   14,   14, 0x02,
     397,  355,   14,   14, 0x02,
     428,  272,   14,   14, 0x02,
     458,  447,   14,   14, 0x02,
     518,  494,  486,   14, 0x02,
     568,  546,   14,   14, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationUI[] = {
    "ApplicationUI\0\0onSystemLanguageChanged()\0"
    "timedout()\0bool\0LEDStatus()\0toggleLED()\0"
    "flashlightStatus()\0toggleFlashlight()\0"
    "interval,times\0startFlashing(int,int)\0"
    "stopFlashing()\0call\0"
    "onCallUpdated(bb::system::phone::Call)\0"
    "email,subject,body\0"
    "invokeEmail(QString,QString,QString)\0"
    "text\0invokeShare(QString)\0appurl\0"
    "invokeBBWorld(QString)\0url\0"
    "invokeBrowser(QString)\0accountid\0"
    "invokeOpenWithFacebook(QString)\0"
    "invokeOpenWithTwitter(QString)\0"
    "showToast(QString)\0title,text\0"
    "showDialog(QString,QString)\0QString\0"
    "objectName,defaultValue\0"
    "getSetting(QString,QString)\0"
    "objectName,inputValue\0setSetting(QString,QString)\0"
};

void ApplicationUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationUI *_t = static_cast<ApplicationUI *>(_o);
        switch (_id) {
        case 0: _t->onSystemLanguageChanged(); break;
        case 1: _t->timedout(); break;
        case 2: { bool _r = _t->LEDStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->toggleLED(); break;
        case 4: { bool _r = _t->flashlightStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->toggleFlashlight(); break;
        case 6: _t->startFlashing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->stopFlashing(); break;
        case 8: _t->onCallUpdated((*reinterpret_cast< const bb::system::phone::Call(*)>(_a[1]))); break;
        case 9: _t->invokeEmail((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->invokeShare((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->invokeBBWorld((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->invokeBrowser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->invokeOpenWithFacebook((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->invokeOpenWithTwitter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->showToast((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->showDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 17: { QString _r = _t->getSetting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 18: _t->setSetting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ApplicationUI,
      qt_meta_data_ApplicationUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationUI))
        return static_cast<void*>(const_cast< ApplicationUI*>(this));
    return QObject::qt_metacast(_clname);
}

int ApplicationUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
