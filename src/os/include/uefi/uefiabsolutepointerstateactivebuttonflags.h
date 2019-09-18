#ifndef UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H
#define UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 uefi_absolute_pointer_state_active_button_flags;

enum class UefiAbsolutePointerStateActiveButtonFlag: uefi_absolute_pointer_state_active_button_flags
{
    NONE             = 0,
    TOUCH_ACTIVE     = (1ULL << 0),
    ALTERNATE_ACTIVE = (1ULL << 1)
};



inline const char8* uefiAbsolutePointerStateActiveButtonFlagToString(UefiAbsolutePointerStateActiveButtonFlag flag) // TEST: NO
{
    switch (flag)
    {
        case UefiAbsolutePointerStateActiveButtonFlag::NONE:             return "NONE";
        case UefiAbsolutePointerStateActiveButtonFlag::TOUCH_ACTIVE:     return "TOUCH_ACTIVE";
        case UefiAbsolutePointerStateActiveButtonFlag::ALTERNATE_ACTIVE: return "ALTERNATE_ACTIVE";

        default: return "UNKNOWN";
    }
}



inline const char8* uefiAbsolutePointerStateActiveButtonFlagsToString(uefi_absolute_pointer_state_active_button_flags flags) // TEST: NO
{
    if (!flags)
    {
        return "NONE";
    }



    static char8 res[47];

    FLAGS_TO_STRING(res, flags, uefiAbsolutePointerStateActiveButtonFlagToString, UefiAbsolutePointerStateActiveButtonFlag);

    return res;
}



#endif // UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H
