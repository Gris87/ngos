#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELREFERENCECLOCK_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELREFERENCECLOCK_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressVirtualChannelReferenceClock: u8
{
    _100_NANOSECONDS = 0
};



inline const char8* enumToString(PciExpressVirtualChannelReferenceClock clock) // TEST: NO
{
    // COMMON_LT((" | clock = %u", clock)); // Commented to avoid bad looking logs



    switch (clock)
    {
        case PciExpressVirtualChannelReferenceClock::_100_NANOSECONDS: return "100_NANOSECONDS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressVirtualChannelReferenceClock clock) // TEST: NO
{
    // COMMON_LT((" | clock = %u", clock)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", (u8)clock, enumToString(clock));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELREFERENCECLOCK_H
