#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIVENDOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIVENDOR_H



#include <QMap>
#include <QString>

#include <com/ngos/devtools/code_generator/other/pcidevice.h>



struct PciVendor
{
    QString                  description;
    QMap<quint16, PciDevice> devices;       // PCI Device ID => PCI Device
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCIVENDOR_H
