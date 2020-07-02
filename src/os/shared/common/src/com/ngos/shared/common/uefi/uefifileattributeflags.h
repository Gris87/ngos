#ifndef UEFI_UEFIFILEATTRIBUTEFLAGS_H
#define UEFI_UEFIFILEATTRIBUTEFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u64 uefi_file_attribute_flags;

enum class UefiFileAttributeFlag: uefi_file_attribute_flags
{
    NONE      = 0,
    READ_ONLY = (1ULL << 0),
    HIDDEN    = (1ULL << 1),
    SYSTEM    = (1ULL << 2),
    RESERVED  = (1ULL << 3),
    DIRECTORY = (1ULL << 4),
    ARCHIVE   = (1ULL << 5)
};

DEFINE_FLAGS(UefiFileAttributeFlags, uefi_file_attribute_flags); // TEST: NO



inline const char8* flagToString(UefiFileAttributeFlag flag) // TEST: NO
{
    switch (flag)
    {
        case UefiFileAttributeFlag::NONE:      return "NONE";
        case UefiFileAttributeFlag::READ_ONLY: return "READ_ONLY";
        case UefiFileAttributeFlag::HIDDEN:    return "HIDDEN";
        case UefiFileAttributeFlag::SYSTEM:    return "SYSTEM";
        case UefiFileAttributeFlag::RESERVED:  return "RESERVED";
        case UefiFileAttributeFlag::DIRECTORY: return "DIRECTORY";
        case UefiFileAttributeFlag::ARCHIVE:   return "ARCHIVE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(UefiFileAttributeFlag flag) // TEST: NO
{
    static char8 res[31];

    sprintf(res, "0x%016lX (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiFileAttributeFlags &flags) // TEST: NO
{
    static char8 res[76];

    FLAGS_TO_STRING(res, flags.flags, UefiFileAttributeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiFileAttributeFlags &flags) // TEST: NO
{
    static char8 res[97];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiFileAttributeFlag, "0x%016lX");

    return res;
}



#endif // UEFI_UEFIFILEATTRIBUTEFLAGS_H
