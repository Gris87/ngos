#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTPOWERSTATE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTPOWERSTATE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciPowerManagementPowerState: bad_uint8
{
    D0     = 0,
    D1     = 1,
    D2     = 2,
    D3_HOT = 3
};



inline const char8* enumToString(PciPowerManagementPowerState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case PciPowerManagementPowerState::D0:     return "D0";
        case PciPowerManagementPowerState::D1:     return "D1";
        case PciPowerManagementPowerState::D2:     return "D2";
        case PciPowerManagementPowerState::D3_HOT: return "D3_HOT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciPowerManagementPowerState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (bad_uint8)state, enumToString(state));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTPOWERSTATE_H
