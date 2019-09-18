#ifndef UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H
#define UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 uefi_absolute_pointer_mode_attribute_flags;

enum class UefiAbsolutePointerModeAttributeFlag: uefi_absolute_pointer_mode_attribute_flags
{
    NONE                      = 0,
    SUPPORTS_ALTERNATE_BUTTON = (1ULL << 0),
    SUPPORTS_PRESSURE_AS_Z    = (1ULL << 1)
};



inline const char8* uefiAbsolutePointerModeAttributeFlagToString(UefiAbsolutePointerModeAttributeFlag flag) // TEST: NO
{
    switch (flag)
    {
        case UefiAbsolutePointerModeAttributeFlag::NONE:                      return "NONE";
        case UefiAbsolutePointerModeAttributeFlag::SUPPORTS_ALTERNATE_BUTTON: return "SUPPORTS_ALTERNATE_BUTTON";
        case UefiAbsolutePointerModeAttributeFlag::SUPPORTS_PRESSURE_AS_Z:    return "SUPPORTS_PRESSURE_AS_Z";

        default: return "UNKNOWN";
    }
}



inline const char8* uefiAbsolutePointerModeAttributeFlagsToString(uefi_absolute_pointer_mode_attribute_flags flags) // TEST: NO
{
    if (!flags)
    {
        return "NONE";
    }



    static char8 res[66];

    FLAGS_TO_STRING(res, flags, uefiAbsolutePointerModeAttributeFlagToString, UefiAbsolutePointerModeAttributeFlag);

    return res;
}



#endif // UEFI_UEFIABSOLUTEPOINTERMODEATTRIBUTEFLAGS_H
