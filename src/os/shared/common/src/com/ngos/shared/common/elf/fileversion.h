#ifndef ELF_FILEVERSION_H
#define ELF_FILEVERSION_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class ElfFileVersion: u8
{
    NONE    = 0,
    CURRENT = 1
};



inline const char8* enumToString(ElfFileVersion version) // TEST: NO
{
    switch (version)
    {
        case ElfFileVersion::NONE:    return "NONE";
        case ElfFileVersion::CURRENT: return "CURRENT";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfFileVersion version) // TEST: NO
{
    static char8 res[15];

    sprintf(res, "0x%02X (%s)", version, enumToString(version));

    return res;
}



#endif



#endif // ELF_FILEVERSION_H
