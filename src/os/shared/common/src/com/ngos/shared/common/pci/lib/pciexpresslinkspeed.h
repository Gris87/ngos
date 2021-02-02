#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSPEED_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSPEED_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressLinkSpeed: bad_uint8
{
    NONE                = 0,
    _2_5_GT_PER_SECOND  = 1,
    _5_0_GT_PER_SECOND  = 2,
    _8_0_GT_PER_SECOND  = 3,
    _16_0_GT_PER_SECOND = 4,
    _32_0_GT_PER_SECOND = 5
};



inline const char8* enumToString(PciExpressLinkSpeed speed) // TEST: NO
{
    // COMMON_LT((" | speed = %u", speed)); // Commented to avoid bad looking logs



    switch (speed)
    {
        case PciExpressLinkSpeed::NONE:                return "NONE";
        case PciExpressLinkSpeed::_2_5_GT_PER_SECOND:  return "2_5_GT_PER_SECOND";
        case PciExpressLinkSpeed::_5_0_GT_PER_SECOND:  return "5_0_GT_PER_SECOND";
        case PciExpressLinkSpeed::_8_0_GT_PER_SECOND:  return "8_0_GT_PER_SECOND";
        case PciExpressLinkSpeed::_16_0_GT_PER_SECOND: return "16_0_GT_PER_SECOND";
        case PciExpressLinkSpeed::_32_0_GT_PER_SECOND: return "32_0_GT_PER_SECOND";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressLinkSpeed speed) // TEST: NO
{
    // COMMON_LT((" | speed = %u", speed)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%02X (%s)", (bad_uint8)speed, enumToString(speed));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSPEED_H
