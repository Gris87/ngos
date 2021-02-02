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
            bad_uint16 baseUnitId:       5;
            bad_uint16 unitCount:        5;
            bad_uint16 masterHost:       1;
            bad_uint16 defaultDirection: 1;
            bad_uint16 dropOnUninit:     1;
            bad_uint16 capabilityType:   3; // TODO: Use enum PciHyperTransportCapabilityType
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACECOMMAND_H
