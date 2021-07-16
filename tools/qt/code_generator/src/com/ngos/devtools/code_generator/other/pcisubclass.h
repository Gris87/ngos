#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCISUBCLASS_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCISUBCLASS_H



#include <QMap>
#include <QString>

#include <com/ngos/devtools/code_generator/other/pciinterface.h>



struct PciSubClass
{
    QString                    description;
    QMap<quint8, PciInterface> interfaces;  // PCI Interface ID => PCI Interface
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCISUBCLASS_H
