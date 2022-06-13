#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 uefi_absolute_pointer_state_active_button_flags;

enum class UefiAbsolutePointerStateActiveButtonFlag: uefi_absolute_pointer_state_active_button_flags
{
    NONE             = 0,
    TOUCH_ACTIVE     = BIT_0,
    ALTERNATE_ACTIVE = BIT_1
};

DEFINE_FLAGS(UefiAbsolutePointerStateActiveButtonFlags, uefi_absolute_pointer_state_active_button_flags); // TEST: NO



inline const char8* flagToString(UefiAbsolutePointerStateActiveButtonFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case UefiAbsolutePointerStateActiveButtonFlag::NONE:             return "NONE";
        case UefiAbsolutePointerStateActiveButtonFlag::TOUCH_ACTIVE:     return "TOUCH_ACTIVE";
        case UefiAbsolutePointerStateActiveButtonFlag::ALTERNATE_ACTIVE: return "ALTERNATE_ACTIVE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(UefiAbsolutePointerStateActiveButtonFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%08X (%s)", (uefi_absolute_pointer_state_active_button_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiAbsolutePointerStateActiveButtonFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[47];

    FLAGS_TO_STRING(res, flags.flags, UefiAbsolutePointerStateActiveButtonFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiAbsolutePointerStateActiveButtonFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[60];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiAbsolutePointerStateActiveButtonFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H
