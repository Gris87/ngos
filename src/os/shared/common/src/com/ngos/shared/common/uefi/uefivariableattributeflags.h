#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 uefi_variable_attribute_flags;

enum class UefiVariableAttributeFlag: uefi_variable_attribute_flags
{
    NONE                                  = 0,
    NON_VOLATILE                          = BIT_0,
    BOOTSERVICE_ACCESS                    = BIT_1,
    RUNTIME_ACCESS                        = BIT_2,
    HARDWARE_ERROR_RECORD                 = BIT_3,
    RESERVED                              = BIT_4,
    TIME_BASED_AUTHENTICATED_WRITE_ACCESS = BIT_5,
    APPEND_WRITE                          = BIT_6
};

DEFINE_FLAGS(UefiVariableAttributeFlags, uefi_variable_attribute_flags); // TEST: NO



inline const char8* flagToString(UefiVariableAttributeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



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



inline const char8* flagToFullString(UefiVariableAttributeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[51];

    sprintf(res, "0x%08X (%s)", (uefi_variable_attribute_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiVariableAttributeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[156];

    FLAGS_TO_STRING(res, flags.flags, UefiVariableAttributeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiVariableAttributeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[169];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiVariableAttributeFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIVARIABLEATTRIBUTEFLAGS_H
