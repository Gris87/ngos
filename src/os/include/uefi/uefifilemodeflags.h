#ifndef UEFI_UEFIFILEMODEFLAGS_H
#define UEFI_UEFIFILEMODEFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
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



inline const char8* uefiFileModeFlagToString(UefiFileModeFlag flag) // TEST: NO
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



inline const char8* uefiFileModeFlagsToString(uefi_file_mode_flags flags) // TEST: NO
{
    if (!flags)
    {
        return "NONE";
    }



    static char8 res[37];

    FLAGS_TO_STRING(res, flags, uefiFileModeFlagToString, UefiFileModeFlag);

    return res;
}



#endif // UEFI_UEFIFILEMODEFLAGS_H
