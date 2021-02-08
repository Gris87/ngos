#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACECOMMAND_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACECOMMAND_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportcapabilitytype.h>



struct PciHyperTransportSlavePrimaryInterfaceCommand
{
    union
    {
        struct
        {
            u16 baseUnitId:       5;
            u16 unitCount:        5;
            u16 masterHost:       1;
            u16 defaultDirection: 1;
            u16 dropOnUninit:     1;
            u16 capabilityType:   3; // TODO: Use enum PciHyperTransportCapabilityType
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACECOMMAND_H
