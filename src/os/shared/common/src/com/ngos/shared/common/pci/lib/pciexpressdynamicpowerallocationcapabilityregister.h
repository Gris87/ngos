#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H



#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationpowerallocationscale.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationtransitionlatencyunit.h>



struct PciExpressDynamicPowerAllocationCapabilityRegister
{
    u8 substateMaximumReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return substateMaximum + 1;
    }



    union
    {
        struct
        {
            u32 substateMaximum         : 5;
            u32 __reserved              : 3;
            u32 transitionLatencyUnit   : 2; // TODO: Use enum PciExpressDynamicPowerAllocationTransitionLatencyUnit
            u32 __reserved2             : 2;
            u32 powerAllocationScale    : 2; // TODO: Use enum PciExpressDynamicPowerAllocationPowerAllocationScale
            u32 __reserved3             : 2;
            u32 transitionLatencyValue0 : 8;
            u32 transitionLatencyValue1 : 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H
