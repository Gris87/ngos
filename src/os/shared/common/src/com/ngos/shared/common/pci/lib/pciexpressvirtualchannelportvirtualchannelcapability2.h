#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY2_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelarbitrationcapabilityflags.h>



struct PciExpressVirtualChannelPortVirtualChannelCapability2
{
    union
    {
        struct
        {
            bad_uint32 virtualChannelArbitrationCapability  : 8; // TODO: Use flags PciExpressVirtualChannelArbitrationCapabilityFlags
            bad_uint32 __reserved                           : 16;
            bad_uint32 virtualChannelArbitrationTableOffset : 8;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY2_H
