/****************************************************************************
** Meta object code from reading C++ file 'newworld.h'
**
** Created: Thu Jun 12 03:53:14 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newworld.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newworld.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewWorld[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      28,    9,    9,    9, 0x08,
      49,    9,    9,    9, 0x08,
      69,    9,    9,    9, 0x08,
      91,    9,    9,    9, 0x08,
     106,    9,    9,    9, 0x08,
     126,    9,    9,    9, 0x08,
     162,    9,    9,    9, 0x08,
     188,    9,    9,    9, 0x08,
     216,    9,    9,    9, 0x08,
     248,    9,    9,    9, 0x08,
     280,    9,    9,    9, 0x08,
     313,    9,    9,    9, 0x08,
     344,    9,    9,    9, 0x08,
     377,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewWorld[] = {
    "NewWorld\0\0chargerComboAct()\0"
    "chargerComboDesact()\0chargerListeActif()\0"
    "chargerListeInactif()\0chargerCombo()\0"
    "chargerListeRayon()\0"
    "on_pushButtonValidConnect_clicked()\0"
    "on_pushButtonUp_clicked()\0"
    "on_pushButtonDown_clicked()\0"
    "on_pushButtonRayValid_clicked()\0"
    "on_pushButtonRayModif_clicked()\0"
    "on_pushButtonProdValid_clicked()\0"
    "on_comboBoxNewProd_activated()\0"
    "on_pushButtonProdDesac_clicked()\0"
    "on_pushButtonProdReact_clicked()\0"
};

void NewWorld::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewWorld *_t = static_cast<NewWorld *>(_o);
        switch (_id) {
        case 0: _t->chargerComboAct(); break;
        case 1: _t->chargerComboDesact(); break;
        case 2: _t->chargerListeActif(); break;
        case 3: _t->chargerListeInactif(); break;
        case 4: _t->chargerCombo(); break;
        case 5: _t->chargerListeRayon(); break;
        case 6: _t->on_pushButtonValidConnect_clicked(); break;
        case 7: _t->on_pushButtonUp_clicked(); break;
        case 8: _t->on_pushButtonDown_clicked(); break;
        case 9: _t->on_pushButtonRayValid_clicked(); break;
        case 10: _t->on_pushButtonRayModif_clicked(); break;
        case 11: _t->on_pushButtonProdValid_clicked(); break;
        case 12: _t->on_comboBoxNewProd_activated(); break;
        case 13: _t->on_pushButtonProdDesac_clicked(); break;
        case 14: _t->on_pushButtonProdReact_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NewWorld::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewWorld::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NewWorld,
      qt_meta_data_NewWorld, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewWorld::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewWorld::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewWorld::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewWorld))
        return static_cast<void*>(const_cast< NewWorld*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NewWorld::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
