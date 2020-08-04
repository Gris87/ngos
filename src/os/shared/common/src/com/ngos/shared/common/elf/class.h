#ifndef COM_NGOS_SHARED_COMMON_ELF_CLASS_H
#define COM_NGOS_SHARED_COMMON_ELF_CLASS_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class ElfClass: u8
{
    NONE     = 0,
    CLASS_32 = 1,
    CLASS_64 = 2
};



inline const char8* enumToString(ElfClass elfClass) // TEST: NO
{
    // COMMON_LT((" | elfClass = %u", elfClass)); // Commented to avoid bad looking logs



    switch (elfClass)
    {
        case ElfClass::NONE:     return "NONE";
        case ElfClass::CLASS_32: return "CLASS_32";
        case ElfClass::CLASS_64: return "CLASS_64";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfClass elfClass) // TEST: NO
{
    // COMMON_LT((" | elfClass = %u", elfClass)); // Commented to avoid bad looking logs



    static char8 res[16];

    sprintf(res, "0x%02X (%s)", elfClass, enumToString(elfClass));

    return res;
}



#endif



#endif // COM_NGOS_SHARED_COMMON_ELF_CLASS_H
