#ifndef ELF_ELFSYMBOLBIND_H
#define ELF_ELFSYMBOLBIND_H



#include <Qt>



enum class ElfSymbolBind: quint8
{
    LOCAL  = 0,
    GLOBAL = 1,
    WEAK   = 2,
    LOOS   = 10,
    HIOS   = 12,
    LOPROC = 13,
    HIPROC = 15
};



#endif // ELF_ELFSYMBOLBIND_H
