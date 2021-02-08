#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportarbitrationcapabilityflags.h>



struct PciExpressVirtualChannelVirtualChannelResourceCapability
{
    u8 maximumTimeSlotsReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return maximumTimeSlots + 1;
    }



    union
    {
        struct
        {
            u32 portArbitrationCapability:  8; // TODO: Use flags PciExpressVirtualChannelPortArbitrationCapabilityFlags
            u32 __reserved:                 6;
            u32 undefined:                  1;
            u32 rejectSnoopTransactions:    1;
            u32 maximumTimeSlots:           7;
            u32 __reserved2:                1;
            u32 portArbitrationTableOffset: 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H
