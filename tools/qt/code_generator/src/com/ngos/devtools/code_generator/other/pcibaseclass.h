#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIBASECLASS_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIBASECLASS_H



#include <QMap>
#include <QString>

#include <com/ngos/devtools/code_generator/other/pcisubclass.h>



struct PciBaseClass
{
    QString                   description;
    QMap<quint8, PciSubClass> subClasses;   // PCI Sub Class ID => PCI Sub Class
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIBASECLASS_H
