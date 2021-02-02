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
            bad_uint32 extendedVirtualChannelCount            : 3;
            bad_uint32 __reserved                             : 1;
            bad_uint32 lowPriorityExtendedVirtualChannelCount : 3;
            bad_uint32 __reserved2                            : 1;
            bad_uint32 referenceClock                         : 2; // TODO: Use enum PciExpressVirtualChannelReferenceClock
            bad_uint32 portArbitrationTableEntrySize          : 2; // TODO: Use enum PciExpressVirtualChannelPortArbitrationTableEntrySize
            bad_uint32 __reserved3                            : 20;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCAPABILITY1_H
