#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 uefi_absolute_pointer_mode_attribute_flags;

enum class UefiAbsolutePointerModeAttributeFlag: uefi_absolute_pointer_mode_attribute_flags
{
    NONE                      = 0,
    SUPPORTS_ALTERNATE_BUTTON = (1ULL << 0),
    SUPPORTS_PRESSURE_AS_Z    = (1ULL << 1)
};

DEFINE_FLAGS(UefiAbsolutePointerModeAttributeFlags, uefi_absolute_pointer_mode_attribute_flags); // TEST: NO



inline const char8* flagToString(UefiAbsolutePointerModeAttributeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case UefiAbsolutePointerModeAttributeFlag::NONE:                      return "NONE";
        case UefiAbsolutePointerModeAttributeFlag::SUPPORTS_ALTERNATE_BUTTON: return "SUPPORTS_ALTERNATE_BUTTON";
        case UefiAbsolutePointerModeAttributeFlag::SUPPORTS_PRESSURE_AS_Z:    return "SUPPORTS_PRESSURE_AS_Z";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(UefiAbsolutePointerModeAttributeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[39];

    sprintf(res, "0x%08X (%s)", (uefi_absolute_pointer_mode_attribute_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiAbsolutePointerModeAttributeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[66];

    FLAGS_TO_STRING(res, flags.flags, UefiAbsolutePointerModeAttributeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiAbsolutePointerModeAttributeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[79];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiAbsolutePointerModeAttributeFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H
