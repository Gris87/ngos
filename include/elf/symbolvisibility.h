#ifndef ELF_SYMBOLVISIBILITY_H
#define ELF_SYMBOLVISIBILITY_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
#endif



enum class ElfSymbolVisibility: u8
{
    DEFAULT   = 0,
    INTERNAL  = 1,
    HIDDEN    = 2,
    PROTECTED = 3,
    EXPORTED  = 4,
    SINGLETON = 5,
    ELIMINATE = 6
};



inline const char8* enumToString(ElfSymbolVisibility visibility) // TEST: NO
{
    switch (visibility)
    {
        case ElfSymbolVisibility::DEFAULT:   return "DEFAULT";
        case ElfSymbolVisibility::INTERNAL:  return "INTERNAL";
        case ElfSymbolVisibility::HIDDEN:    return "HIDDEN";
        case ElfSymbolVisibility::PROTECTED: return "PROTECTED";
        case ElfSymbolVisibility::EXPORTED:  return "EXPORTED";
        case ElfSymbolVisibility::SINGLETON: return "SINGLETON";
        case ElfSymbolVisibility::ELIMINATE: return "ELIMINATE";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(ElfSymbolVisibility visibility) // TEST: NO
{
    static char8 res[17];

    sprintf(res, "0x%02X (%s)", visibility, enumToString(visibility));

    return res;
}



#endif



#endif // ELF_SYMBOLVISIBILITY_H
