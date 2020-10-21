#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYHEADER_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYHEADER_H



#include <com/ngos/shared/common/pci/pciextendedcapabilitytype.h>



struct PciExtendedCapabilityHeader
{
    union
    {
        struct
        {
            u32 capabilityId         : 16; // TODO: Use enum PciExtendedCapabilityType
            u32 capabilityVersion    : 4;
            u32 nextCapabilityOffset : 12;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYHEADER_H
