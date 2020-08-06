#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOLBIND_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOLBIND_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



#define ELF_SYMBOL_BIND_OS_LOW         10
#define ELF_SYMBOL_BIND_OS_HIGH        12
#define ELF_SYMBOL_BIND_PROCESSOR_LOW  13
#define ELF_SYMBOL_BIND_PROCESSOR_HIGH 15



enum class ElfSymbolBind: u8
{
    LOCAL  = 0,
    GLOBAL = 1,
    WEAK   = 2
};



inline const char8* enumToString(ElfSymbolBind bind) // TEST: NO
{
    // COMMON_LT((" | bind = %u", bind)); // Commented to avoid bad looking logs



    switch (bind)
    {
        case ElfSymbolBind::LOCAL:  return "LOCAL";
        case ElfSymbolBind::GLOBAL: return "GLOBAL";
        case ElfSymbolBind::WEAK:   return "WEAK";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfSymbolBind bind) // TEST: NO
{
    // COMMON_LT((" | bind = %u", bind)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)bind, enumToString(bind));

    return res;
}



#endif



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOLBIND_H
