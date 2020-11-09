#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY1_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY1_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportarbitrationtableentrysize.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelreferenceclock.h>



struct PciExpressVirtualChannelPortVirtualChannelCapability1
{
    union
    {
        struct
        {
            u32 extendedVirtualChannelCount            : 3;
            u32 __reserved                             : 1;
            u32 lowPriorityExtendedVirtualChannelCount : 3;
            u32 __reserved2                            : 1;
            u32 referenceClock                         : 2; // TODO: Use enum PciExpressVirtualChannelReferenceClock
            u32 portArbitrationTableEntrySize          : 2; // TODO: Use enum PciExpressVirtualChannelPortArbitrationTableEntrySize
            u32 __reserved3                            : 20;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY1_H
