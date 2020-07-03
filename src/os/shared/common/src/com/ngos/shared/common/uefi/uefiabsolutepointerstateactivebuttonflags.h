#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H



#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/string/string.h>
#include <common/src/com/ngos/shared/common/ngos/flags.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



typedef u32 uefi_absolute_pointer_state_active_button_flags;

enum class UefiAbsolutePointerStateActiveButtonFlag: uefi_absolute_pointer_state_active_button_flags
{
    NONE             = 0,
    TOUCH_ACTIVE     = (1ULL << 0),
    ALTERNATE_ACTIVE = (1ULL << 1)
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

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATEACTIVEBUTTONFLAGS_H
