#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIDEVICE_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIDEVICE_H



#include <QMap>
#include <QString>

#include <com/ngos/devtools/code_generator/other/pcisubdevice.h>



struct PciDevice
{
    QString                     description;
    QMap<quint32, PciSubDevice> subdevices;     // PCI Sub Device ID => PCI Sub Device
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIDEVICE_H
