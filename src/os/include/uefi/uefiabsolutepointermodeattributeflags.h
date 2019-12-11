#ifndef UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H
#define UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 uefi_absolute_pointer_mode_attribute_flags;

enum class UefiAbsolutePointerModeAttributeFlag: uefi_absolute_pointer_mode_attribute_flags
{
    NONE                      = 0,
    SUPPORTS_ALTERNATE_BUTTON = (1ULL << 0),
    SUPPORTS_PRESSURE_AS_Z    = (1ULL << 1)
};

DEFINE_FLAGS(UefiAbsolutePointerModeAttributeFlags, uefi_absolute_pointer_mode_attribute_flags);



inline const char8* flagToString(UefiAbsolutePointerModeAttributeFlag flag) // TEST: NO
{
    switch (flag)
    {
        case UefiAbsolutePointerModeAttributeFlag::NONE:                      return "NONE";
        case UefiAbsolutePointerModeAttributeFlag::SUPPORTS_ALTERNATE_BUTTON: return "SUPPORTS_ALTERNATE_BUTTON";
        case UefiAbsolutePointerModeAttributeFlag::SUPPORTS_PRESSURE_AS_Z:    return "SUPPORTS_PRESSURE_AS_Z";

        default: return "UNKNOWN";
    }
}



inline const char8* flagsToString(const UefiAbsolutePointerModeAttributeFlags &flags) // TEST: NO
{
    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[66];

    FLAGS_TO_STRING(res, flags.flags, flagToString, UefiAbsolutePointerModeAttributeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiAbsolutePointerModeAttributeFlags &flags) // TEST: NO
{
    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[66];

    FLAGS_TO_STRING(res, flags.flags, flagToString, UefiAbsolutePointerModeAttributeFlag);

    return res;
}



#endif // UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H
