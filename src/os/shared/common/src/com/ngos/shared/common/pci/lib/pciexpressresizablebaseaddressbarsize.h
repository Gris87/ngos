#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSBARSIZE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSBARSIZE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressResizableBaseAddressBarSize: u8
{
    _1_MB   = 0,
    _2_MB   = 1,
    _4_MB   = 2,
    _8_MB   = 3,
    _16_MB  = 4,
    _32_MB  = 5,
    _64_MB  = 6,
    _128_MB = 7,
    _256_MB = 8,
    _512_MB = 9,
    _1_GB   = 10,
    _2_GB   = 11,
    _4_GB   = 12,
    _8_GB   = 13,
    _16_GB  = 14,
    _32_GB  = 15,
    _64_GB  = 16,
    _128_GB = 17,
    _256_GB = 18,
    _512_GB = 19
};



inline const char8* enumToString(PciExpressResizableBaseAddressBarSize size) // TEST: NO
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid bad looking logs



    switch (size)
    {
        case PciExpressResizableBaseAddressBarSize::_1_MB:   return "1_MB";
        case PciExpressResizableBaseAddressBarSize::_2_MB:   return "2_MB";
        case PciExpressResizableBaseAddressBarSize::_4_MB:   return "4_MB";
        case PciExpressResizableBaseAddressBarSize::_8_MB:   return "8_MB";
        case PciExpressResizableBaseAddressBarSize::_16_MB:  return "16_MB";
        case PciExpressResizableBaseAddressBarSize::_32_MB:  return "32_MB";
        case PciExpressResizableBaseAddressBarSize::_64_MB:  return "64_MB";
        case PciExpressResizableBaseAddressBarSize::_128_MB: return "128_MB";
        case PciExpressResizableBaseAddressBarSize::_256_MB: return "256_MB";
        case PciExpressResizableBaseAddressBarSize::_512_MB: return "512_MB";
        case PciExpressResizableBaseAddressBarSize::_1_GB:   return "1_GB";
        case PciExpressResizableBaseAddressBarSize::_2_GB:   return "2_GB";
        case PciExpressResizableBaseAddressBarSize::_4_GB:   return "4_GB";
        case PciExpressResizableBaseAddressBarSize::_8_GB:   return "8_GB";
        case PciExpressResizableBaseAddressBarSize::_16_GB:  return "16_GB";
        case PciExpressResizableBaseAddressBarSize::_32_GB:  return "32_GB";
        case PciExpressResizableBaseAddressBarSize::_64_GB:  return "64_GB";
        case PciExpressResizableBaseAddressBarSize::_128_GB: return "128_GB";
        case PciExpressResizableBaseAddressBarSize::_256_GB: return "256_GB";
        case PciExpressResizableBaseAddressBarSize::_512_GB: return "512_GB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressResizableBaseAddressBarSize size) // TEST: NO
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)size, enumToString(size));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSBARSIZE_H
