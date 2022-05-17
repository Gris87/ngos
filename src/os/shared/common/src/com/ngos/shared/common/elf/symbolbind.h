#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOLBIND_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOLBIND_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfSymbolBind: u8
{
    LOCAL  = 0,
    GLOBAL = 1,
    WEAK   = 2
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



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



inline const char8* enumToFullString(ElfSymbolBind bind) // TEST: NO
{
    // COMMON_LT((" | bind = %u", bind)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)bind, enumToString(bind));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOLBIND_H
