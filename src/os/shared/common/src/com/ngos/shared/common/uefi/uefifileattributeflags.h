#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEATTRIBUTEFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEATTRIBUTEFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint64 uefi_file_attribute_flags;

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
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[31];

    sprintf(res, "0x%016llX (%s)", (uefi_file_attribute_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiFileAttributeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[76];

    FLAGS_TO_STRING(res, flags.flags, UefiFileAttributeFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiFileAttributeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[97];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiFileAttributeFlag, "0x%016llX");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEATTRIBUTEFLAGS_H
