#ifndef ELF_SYMBOLBIND_H
#define ELF_SYMBOLBIND_H



#include <ngos/types.h>



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



inline const char* elfSymbolBindToString(ElfSymbolBind bind) // TEST: NO
{
    switch (bind)
    {
        case ElfSymbolBind::LOCAL:  return "LOCAL";
        case ElfSymbolBind::GLOBAL: return "GLOBAL";
        case ElfSymbolBind::WEAK:   return "WEAK";

        default: return "UNKNOWN";
    }
}



#endif // ELF_SYMBOLBIND_H
