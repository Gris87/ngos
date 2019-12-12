#ifndef ELF_SYMBOLBIND_H
#define ELF_SYMBOLBIND_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
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
    switch (bind)
    {
        case ElfSymbolBind::LOCAL:  return "LOCAL";
        case ElfSymbolBind::GLOBAL: return "GLOBAL";
        case ElfSymbolBind::WEAK:   return "WEAK";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(ElfSymbolBind bind) // TEST: NO
{
    static char8 res[15];

    sprintf(res, "0x%02X (%s)", bind, enumToString(bind));

    return res;
}



#endif



#endif // ELF_SYMBOLBIND_H
