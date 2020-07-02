#ifndef ELF_CLASS_H
#define ELF_CLASS_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
#endif



enum class ElfClass: u8
{
    NONE     = 0,
    CLASS_32 = 1,
    CLASS_64 = 2
};



inline const char8* enumToString(ElfClass elfClass) // TEST: NO
{
    switch (elfClass)
    {
        case ElfClass::NONE:     return "NONE";
        case ElfClass::CLASS_32: return "CLASS_32";
        case ElfClass::CLASS_64: return "CLASS_64";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(ElfClass elfClass) // TEST: NO
{
    static char8 res[16];

    sprintf(res, "0x%02X (%s)", elfClass, enumToString(elfClass));

    return res;
}



#endif



#endif // ELF_CLASS_H
