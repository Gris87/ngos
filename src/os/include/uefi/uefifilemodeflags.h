#ifndef UEFI_UEFIFILEMODEFLAGS_H
#define UEFI_UEFIFILEMODEFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u64 uefi_file_mode_flags;

enum class UefiFileModeFlag: uefi_file_mode_flags
{
    NONE   = 0,
    READ   = (1ULL << 0),
    WRITE  = (1ULL << 1),
    CREATE = (1ULL << 63)
};

DEFINE_FLAGS(UefiFileModeFlags, uefi_file_mode_flags);



inline const char8* flagToString(UefiFileModeFlag flag) // TEST: NO
{
    switch (flag)
    {
        case UefiFileModeFlag::NONE:   return "NONE";
        case UefiFileModeFlag::READ:   return "READ";
        case UefiFileModeFlag::WRITE:  return "WRITE";
        case UefiFileModeFlag::CREATE: return "CREATE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagsToString(const UefiFileModeFlags &flags) // TEST: NO
{
    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[37];

    FLAGS_TO_STRING(res, flags.flags, flagToString, UefiFileModeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiFileModeFlags &flags) // TEST: NO
{
    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[37];

    FLAGS_TO_STRING(res, flags.flags, flagToString, UefiFileModeFlag);

    return res;
}



#endif // UEFI_UEFIFILEMODEFLAGS_H
