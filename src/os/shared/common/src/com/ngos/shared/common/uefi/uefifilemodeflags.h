#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEMODEFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEMODEFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u64 uefi_file_mode_flags;

enum class UefiFileModeFlag: uefi_file_mode_flags
{
    NONE   = 0,
    READ   = BIT_0,
    WRITE  = BIT_1,
    CREATE = BIT_63
};

DEFINE_FLAGS(UefiFileModeFlags, uefi_file_mode_flags); // TEST: NO



inline const char8* flagToString(UefiFileModeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case UefiFileModeFlag::NONE:   return "NONE";
        case UefiFileModeFlag::READ:   return "READ";
        case UefiFileModeFlag::WRITE:  return "WRITE";
        case UefiFileModeFlag::CREATE: return "CREATE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(UefiFileModeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[29];

    sprintf(res, "0x%016llX (%s)", (uefi_file_mode_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiFileModeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[37];

    FLAGS_TO_STRING(res, flags.flags, UefiFileModeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiFileModeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[58];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiFileModeFlag, "0x%016llX");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEMODEFLAGS_H
