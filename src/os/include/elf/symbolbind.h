#ifndef ELF_SYMBOLBIND_H
#define ELF_SYMBOLBIND_H



#include <ngos/types.h>



enum class ElfSymbolBind: u8
{
    LOCAL  = 0,
    GLOBAL = 1,
    WEAK   = 2,
    LOOS   = 10,
    HIOS   = 12,
    LOPROC = 13,
    HIPROC = 15
};



#endif // ELF_SYMBOLBIND_H
