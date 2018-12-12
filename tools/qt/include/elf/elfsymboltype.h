#ifndef ELF_ELFSYMBOLTYPE_H
#define ELF_ELFSYMBOLTYPE_H



#include <Qt>



enum class ElfSymbolType: quint8
{
    NOTYPE         = 0,
    OBJECT         = 1,
    FUNC           = 2,
    SECTION        = 3,
    FILE           = 4,
    COMMON         = 5,
    TLS            = 6,
    LOOS           = 10,
    HIOS           = 12,
    LOPROC         = 13,
    SPARC_REGISTER = 13,
    HIPROC         = 15
};



#endif // ELF_ELFSYMBOLTYPE_H
