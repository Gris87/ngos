#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKSTATE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKSTATE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiSimpleNetworkState: u32
{
    STOPPED,
    STARTED,
    INITIALIZED,
    MAXIMUM
};



inline const char8* enumToString(UefiSimpleNetworkState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case UefiSimpleNetworkState::STOPPED:     return "STOPPED";
        case UefiSimpleNetworkState::STARTED:     return "STARTED";
        case UefiSimpleNetworkState::INITIALIZED: return "INITIALIZED";
        case UefiSimpleNetworkState::MAXIMUM:     return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiSimpleNetworkState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%08X (%s)", (u32)state, enumToString(state));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKSTATE_H
