#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY2_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelarbitrationcapabilityflags.h>



struct PciExpressVirtualChannelPortVirtualChannelCapability2
{
    union
    {
        struct
        {
            u32 virtualChannelArbitrationCapability  : 8; // TODO: Use flags PciExpressVirtualChannelArbitrationCapabilityFlags
            u32 __reserved                           : 16;
            u32 virtualChannelArbitrationTableOffset : 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY2_H
