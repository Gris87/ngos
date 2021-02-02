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
            bad_uint16 warmReset:                  1;
            bad_uint16 doubleEnded:                1;
            bad_uint16 deviceNumber:               5;
            bad_uint16 chainSide:                  1;
            bad_uint16 hostHide:                   1;
            bad_uint16 __reserved:                 1;
            bad_uint16 actAsSlave:                 1;
            bad_uint16 hostInboundEndOfChainError: 1;
            bad_uint16 dropOnUninit:               1;
            bad_uint16 capabilityType:             3; // TODO: Use enum PciHyperTransportCapabilityType
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACECOMMAND_H
