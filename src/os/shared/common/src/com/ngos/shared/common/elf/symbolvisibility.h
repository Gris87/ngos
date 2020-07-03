#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_SYMBOLVISIBILITY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_SYMBOLVISIBILITY_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
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
    // COMMON_LT((" | visibility = %u", visibility)); // Commented to avoid bad looking logs



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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfSymbolVisibility visibility) // TEST: NO
{
    // COMMON_LT((" | visibility = %u", visibility)); // Commented to avoid bad looking logs



    static char8 res[17];

    sprintf(res, "0x%02X (%s)", visibility, enumToString(visibility));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_SYMBOLVISIBILITY_H
