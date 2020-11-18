#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERSCALE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERSCALE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressPowerScale: u8
{
    _1X     = 0,
    _0_1X   = 1,
    _0_01X  = 2,
    _0_001X = 3
};



inline const char8* enumToString(PciExpressPowerScale scale) // TEST: NO
{
    // COMMON_LT((" | scale = %u", scale)); // Commented to avoid bad looking logs



    switch (scale)
    {
        case PciExpressPowerScale::_1X:     return "1X";
        case PciExpressPowerScale::_0_1X:   return "0_1X";
        case PciExpressPowerScale::_0_01X:  return "0_01X";
        case PciExpressPowerScale::_0_001X: return "0_001X";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressPowerScale scale) // TEST: NO
{
    // COMMON_LT((" | scale = %u", scale)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)scale, enumToString(scale));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERSCALE_H
