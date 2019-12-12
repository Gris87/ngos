#ifndef UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H
#define UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H



#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#endif



typedef u32 uefi_variable_attribute_flags;

enum class UefiVariableAttributeFlag: uefi_variable_attribute_flags
{
    NONE                                  = 0,
    NON_VOLATILE                          = (1ULL << 0),
    BOOTSERVICE_ACCESS                    = (1ULL << 1),
    RUNTIME_ACCESS                        = (1ULL << 2),
    HARDWARE_ERROR_RECORD                 = (1ULL << 3),
    RESERVED                              = (1ULL << 4),
    TIME_BASED_AUTHENTICATED_WRITE_ACCESS = (1ULL << 5),
    APPEND_WRITE                          = (1ULL << 6)
};

DEFINE_FLAGS(UefiVariableAttributeFlags, uefi_variable_attribute_flags); // TEST: NO



inline const char8* flagToString(UefiVariableAttributeFlag flag) // TEST: NO
{
    switch (flag)
    {
        case UefiVariableAttributeFlag::NONE:                                  return "NONE";
        case UefiVariableAttributeFlag::NON_VOLATILE:                          return "NON_VOLATILE";
        case UefiVariableAttributeFlag::BOOTSERVICE_ACCESS:                    return "BOOTSERVICE_ACCESS";
        case UefiVariableAttributeFlag::RUNTIME_ACCESS:                        return "RUNTIME_ACCESS";
        case UefiVariableAttributeFlag::HARDWARE_ERROR_RECORD:                 return "HARDWARE_ERROR_RECORD";
        case UefiVariableAttributeFlag::RESERVED:                              return "RESERVED";
        case UefiVariableAttributeFlag::TIME_BASED_AUTHENTICATED_WRITE_ACCESS: return "TIME_BASED_AUTHENTICATED_WRITE_ACCESS";
        case UefiVariableAttributeFlag::APPEND_WRITE:                          return "APPEND_WRITE";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* flagToFullString(UefiVariableAttributeFlag flag) // TEST: NO
{
    static char8 res[51];

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiVariableAttributeFlags &flags) // TEST: NO
{
    static char8 res[156];

    FLAGS_TO_STRING(res, flags.flags, UefiVariableAttributeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiVariableAttributeFlags &flags) // TEST: NO
{
    static char8 res[169];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiVariableAttributeFlag, "0x%08X");

    return res;
}



#endif



#endif // UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H
