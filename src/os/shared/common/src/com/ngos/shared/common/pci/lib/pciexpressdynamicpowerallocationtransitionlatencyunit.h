#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONTRANSITIONLATENCYUNIT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONTRANSITIONLATENCYUNIT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressDynamicPowerAllocationTransitionLatencyUnit: u8
{
    _1_MS   = 0,
    _10_MS  = 1,
    _100_MS = 2
};



inline const char8* enumToString(PciExpressDynamicPowerAllocationTransitionLatencyUnit unit) // TEST: NO
{
    // COMMON_LT((" | unit = %u", unit)); // Commented to avoid bad looking logs



    switch (unit)
    {
        case PciExpressDynamicPowerAllocationTransitionLatencyUnit::_1_MS:   return "1_MS";
        case PciExpressDynamicPowerAllocationTransitionLatencyUnit::_10_MS:  return "10_MS";
        case PciExpressDynamicPowerAllocationTransitionLatencyUnit::_100_MS: return "100_MS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressDynamicPowerAllocationTransitionLatencyUnit unit) // TEST: NO
{
    // COMMON_LT((" | unit = %u", unit)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)unit, enumToString(unit));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONTRANSITIONLATENCYUNIT_H
