#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONPOWERALLOCATIONSCALE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONPOWERALLOCATIONSCALE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressDynamicPowerAllocationPowerAllocationScale: u8
{
    _10_0_X = 0,
    _1_0_X  = 1,
    _0_1_X  = 2,
    _0_01_X = 3
};



inline const char8* enumToString(PciExpressDynamicPowerAllocationPowerAllocationScale scale) // TEST: NO
{
    // COMMON_LT((" | scale = %u", scale)); // Commented to avoid bad looking logs



    switch (scale)
    {
        case PciExpressDynamicPowerAllocationPowerAllocationScale::_10_0_X: return "10_0_X";
        case PciExpressDynamicPowerAllocationPowerAllocationScale::_1_0_X:  return "1_0_X";
        case PciExpressDynamicPowerAllocationPowerAllocationScale::_0_1_X:  return "0_1_X";
        case PciExpressDynamicPowerAllocationPowerAllocationScale::_0_01_X: return "0_01_X";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressDynamicPowerAllocationPowerAllocationScale scale) // TEST: NO
{
    // COMMON_LT((" | scale = %u", scale)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)scale, enumToString(scale));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONPOWERALLOCATIONSCALE_H
