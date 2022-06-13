#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITYFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITYFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 pci_express_resizable_base_address_capability_flags;

enum class PciExpressResizableBaseAddressCapabilityFlag: pci_express_resizable_base_address_capability_flags
{
    NONE    = 0,
    _1_MB   = BIT_4,
    _2_MB   = BIT_5,
    _4_MB   = BIT_6,
    _8_MB   = BIT_7,
    _16_MB  = BIT_8,
    _32_MB  = BIT_9,
    _64_MB  = BIT_10,
    _128_MB = BIT_11,
    _256_MB = BIT_12,
    _512_MB = BIT_13,
    _1_GB   = BIT_14,
    _2_GB   = BIT_15,
    _4_GB   = BIT_16,
    _8_GB   = BIT_17,
    _16_GB  = BIT_18,
    _32_GB  = BIT_19,
    _64_GB  = BIT_20,
    _128_GB = BIT_21,
    _256_GB = BIT_22,
    _512_GB = BIT_23
};

DEFINE_FLAGS(PciExpressResizableBaseAddressCapabilityFlags, pci_express_resizable_base_address_capability_flags); // TEST: NO



inline const char8* flagToString(PciExpressResizableBaseAddressCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressResizableBaseAddressCapabilityFlag::NONE:    return "NONE";
        case PciExpressResizableBaseAddressCapabilityFlag::_1_MB:   return "1_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_2_MB:   return "2_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_4_MB:   return "4_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_8_MB:   return "8_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_16_MB:  return "16_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_32_MB:  return "32_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_64_MB:  return "64_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_128_MB: return "128_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_256_MB: return "256_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_512_MB: return "512_MB";
        case PciExpressResizableBaseAddressCapabilityFlag::_1_GB:   return "1_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_2_GB:   return "2_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_4_GB:   return "4_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_8_GB:   return "8_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_16_GB:  return "16_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_32_GB:  return "32_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_64_GB:  return "64_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_128_GB: return "128_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_256_GB: return "256_GB";
        case PciExpressResizableBaseAddressCapabilityFlag::_512_GB: return "512_GB";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressResizableBaseAddressCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%08X (%s)", (pci_express_resizable_base_address_capability_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressResizableBaseAddressCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[171];

    FLAGS_TO_STRING(res, flags.flags, PciExpressResizableBaseAddressCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressResizableBaseAddressCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[184];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressResizableBaseAddressCapabilityFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITYFLAGS_H
