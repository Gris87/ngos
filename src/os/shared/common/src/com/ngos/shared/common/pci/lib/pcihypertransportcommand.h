#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTCOMMAND_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTCOMMAND_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportcapabilitytype.h>



struct PciHyperTransportCommand
{
    union
    {
        struct
        {
            u16 __reserved:     13;
            u16 capabilityType: 3; // TODO: Use enum PciHyperTransportCapabilityType
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTCOMMAND_H
