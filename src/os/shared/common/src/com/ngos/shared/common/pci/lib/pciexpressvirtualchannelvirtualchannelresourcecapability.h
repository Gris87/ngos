#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportarbitrationcapabilityflags.h>



struct PciExpressVirtualChannelVirtualChannelResourceCapability
{
    bad_uint8 maximumTimeSlotsReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return maximumTimeSlots + 1;
    }



    union
    {
        struct
        {
            bad_uint32 portArbitrationCapability:  8; // TODO: Use flags PciExpressVirtualChannelPortArbitrationCapabilityFlags
            bad_uint32 __reserved:                 6;
            bad_uint32 undefined:                  1;
            bad_uint32 rejectSnoopTransactions:    1;
            bad_uint32 maximumTimeSlots:           7;
            bad_uint32 __reserved2:                1;
            bad_uint32 portArbitrationTableOffset: 8;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H
