#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCISUBDEVICE_H                                                                                                                                            // Colorize: green
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCISUBDEVICE_H                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QMap>                                                                                                                                                                                          // Colorize: green
#include <QString>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct PciSubDevice                                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QString description;                                                                                                                                                                                 // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
typedef QMap<quint32,         PciSubDevice> PciSubDevices;          // PCI Sub Device ID => PCI Sub Device                                                                                                                                      // Colorize: green
typedef QMapIterator<quint32, PciSubDevice> PciSubDevicesIterator;  // PCI Sub Device ID => PCI Sub Device                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_PCISUBDEVICE_H                                                                                                                                          // Colorize: green
