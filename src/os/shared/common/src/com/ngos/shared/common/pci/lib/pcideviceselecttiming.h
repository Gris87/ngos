#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIDEVICESELECTTIMING_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIDEVICESELECTTIMING_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceSelectTiming: u8
{
    FAST   = 0,
    MEDIUM = 1,
    SLOW   = 2
};



inline const char8* enumToString(PciDeviceSelectTiming timing) // TEST: NO
{
    // COMMON_LT((" | timing = %u", timing)); // Commented to avoid bad looking logs



    switch (timing)
    {
        case PciDeviceSelectTiming::FAST:   return "FAST";
        case PciDeviceSelectTiming::MEDIUM: return "MEDIUM";
        case PciDeviceSelectTiming::SLOW:   return "SLOW";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceSelectTiming timing) // TEST: NO
{
    // COMMON_LT((" | timing = %u", timing)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)timing, enumToString(timing));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIDEVICESELECTTIMING_H
