#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKERRORANDFREQUENCYUNION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKERRORANDFREQUENCYUNION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkerrorflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkfrequency.h>



struct PciHyperTransportLinkErrorAndFrequencyUnion
{
    union
    {
        struct
        {
            u8 frequency: 4; // TODO: Use enum PciHyperTransportLinkFrequency
            u8 error:     4; // TODO: Use flags PciHyperTransportLinkErrorFlags
        };

        u8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKERRORANDFREQUENCYUNION_H
