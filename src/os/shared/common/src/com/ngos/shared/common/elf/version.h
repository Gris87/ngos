#ifndef ELF_VERSION_H
#define ELF_VERSION_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
#endif



enum class ElfVersion: u32
{
    NONE    = 0,
    CURRENT = 1
};



inline const char8* enumToString(ElfVersion version) // TEST: NO
{
    switch (version)
    {
        case ElfVersion::NONE:    return "NONE";
        case ElfVersion::CURRENT: return "CURRENT";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(ElfVersion version) // TEST: NO
{
    static char8 res[21];

    sprintf(res, "0x%08X (%s)", version, enumToString(version));

    return res;
}



#endif



#endif // ELF_VERSION_H
