#ifndef ELF_ELFRELA_H
#define ELF_ELFRELA_H



#include <Qt>



#define ELF_RELA_SYMBOL(info)       ((info) >> 32)                              // TEST: NO
#define ELF_RELA_TYPE(info)         ((info) & 0xFFFFFFFF)                       // TEST: NO
#define ELF_RELA_INFO(symbol, type) (((symbol) << 32) + ((type) & 0xFFFFFFFF))  // TEST: NO



struct ElfRela
{
    quint64 offset;
    quint64 info;
    qint64  addend;
};



#endif // ELF_ELFRELA_H
