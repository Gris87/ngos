#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACECOMMAND_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACECOMMAND_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportcapabilitytype.h>



struct PciHyperTransportHostSecondaryInterfaceCommand
{
    union
    {
        struct
        {
            u16 warmReset:                  1;
            u16 doubleEnded:                1;
            u16 deviceNumber:               5;
            u16 chainSide:                  1;
            u16 hostHide:                   1;
            u16 __reserved:                 1;
            u16 actAsSlave:                 1;
            u16 hostInboundEndOfChainError: 1;
            u16 dropOnUninit:               1;
            u16 capabilityType:             3; // TODO: Use enum PciHyperTransportCapabilityType
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACECOMMAND_H
