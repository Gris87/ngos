#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYHEADER_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYHEADER_H



#include <com/ngos/shared/common/pci/pciextendedcapabilitytype.h>



struct PciExtendedCapabilityHeader
{
    union
    {
        struct
        {
            bad_uint32 capabilityId         : 16; // TODO: Use enum PciExtendedCapabilityType
            bad_uint32 capabilityVersion    : 4;
            bad_uint32 nextCapabilityOffset : 12;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYHEADER_H
