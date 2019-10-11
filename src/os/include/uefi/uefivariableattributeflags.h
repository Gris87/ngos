#ifndef UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H
#define UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H



#if defined(UEFI_APPLICATION)
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#endif

#include <ngos/linkage.h>
#include <ngos/types.h>



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



inline const char8* uefiVariableAttributeFlagToString(UefiVariableAttributeFlag flag) // TEST: NO
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



#if defined(UEFI_APPLICATION)
inline const char8* uefiVariableAttributeFlagsToString(uefi_variable_attribute_flags flags) // TEST: NO
{
    if (!flags)
    {
        return "NONE";
    }



    static char8 res[76];

    FLAGS_TO_STRING(res, flags, uefiVariableAttributeFlagToString, UefiVariableAttributeFlag);

    return res;
}
#endif



#endif // UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H
