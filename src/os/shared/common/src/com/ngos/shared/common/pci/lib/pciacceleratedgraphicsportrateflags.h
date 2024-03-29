#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTRATEFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTRATEFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 pci_accelerated_graphics_port_rate_flags;

enum class PciAcceleratedGraphicsPortRateFlag: pci_accelerated_graphics_port_rate_flags
{
    NONE = 0,
    _1X  = BIT_0,
    _2X  = BIT_1
};

DEFINE_FLAGS(PciAcceleratedGraphicsPortRateFlags, pci_accelerated_graphics_port_rate_flags); // TEST: NO



inline const char8* flagToString(PciAcceleratedGraphicsPortRateFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciAcceleratedGraphicsPortRateFlag::NONE: return "NONE";
        case PciAcceleratedGraphicsPortRateFlag::_1X:  return "1X";
        case PciAcceleratedGraphicsPortRateFlag::_2X:  return "2X";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciAcceleratedGraphicsPortRateFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (pci_accelerated_graphics_port_rate_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciAcceleratedGraphicsPortRateFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[23];

    FLAGS_TO_STRING(res, flags.flags, PciAcceleratedGraphicsPortRateFlag);

    return res;
}



inline const char8* flagsToFullString(const PciAcceleratedGraphicsPortRateFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[30];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciAcceleratedGraphicsPortRateFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTRATEFLAGS_H
