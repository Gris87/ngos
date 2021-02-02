#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H



#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationpowerallocationscale.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationtransitionlatencyunit.h>



struct PciExpressDynamicPowerAllocationCapabilityRegister
{
    bad_uint8 substateMaximumReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return substateMaximum + 1;
    }



    union
    {
        struct
        {
            bad_uint32 substateMaximum         : 5;
            bad_uint32 __reserved              : 3;
            bad_uint32 transitionLatencyUnit   : 2; // TODO: Use enum PciExpressDynamicPowerAllocationTransitionLatencyUnit
            bad_uint32 __reserved2             : 2;
            bad_uint32 powerAllocationScale    : 2; // TODO: Use enum PciExpressDynamicPowerAllocationPowerAllocationScale
            bad_uint32 __reserved3             : 2;
            bad_uint32 transitionLatencyValue0 : 8;
            bad_uint32 transitionLatencyValue1 : 8;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H
