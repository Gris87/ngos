#ifndef UEFI_UEFIRESETTYPE_H
#define UEFI_UEFIRESETTYPE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiResetType: u32
{
    COLD     = 0,
    WARM     = 1,
    SHUTDOWN = 2
};



inline const char8* enumToString(UefiResetType type) // TEST: NO
{
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
    static char8 res[22];

    sprintf(res, "0x%08X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // UEFI_UEFIRESETTYPE_H
