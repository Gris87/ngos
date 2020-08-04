#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIRESETTYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIRESETTYPE_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiResetType: u32
{
    COLD     = 0,
    WARM     = 1,
    SHUTDOWN = 2
};



inline const char8* enumToString(UefiResetType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiResetType::COLD:     return "COLD";
        case UefiResetType::WARM:     return "WARM";
        case UefiResetType::SHUTDOWN: return "SHUTDOWN";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiResetType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[22];

    sprintf(res, "0x%08X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIRESETTYPE_H
