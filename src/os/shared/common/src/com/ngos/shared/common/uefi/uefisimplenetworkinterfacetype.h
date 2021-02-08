#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERFACETYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERFACETYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiSimpleNetworkInterfaceType: u8
{
    NONE     = 0,
    ETHERNET = 1
};



inline const char8* enumToString(UefiSimpleNetworkInterfaceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiSimpleNetworkInterfaceType::NONE:     return "NONE";
        case UefiSimpleNetworkInterfaceType::ETHERNET: return "ETHERNET";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiSimpleNetworkInterfaceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[16];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERFACETYPE_H
