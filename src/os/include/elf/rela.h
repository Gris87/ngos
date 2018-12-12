#ifndef ELF_RELA_H
#define ELF_RELA_H



#include <ngos/types.h>



#define ELF_RELA_SYMBOL(info)       ((info) >> 32)                              // TEST: NO
#define ELF_RELA_TYPE(info)         ((info) & 0xFFFFFFFF)                       // TEST: NO
#define ELF_RELA_INFO(symbol, type) (((symbol) << 32) + ((type) & 0xFFFFFFFF))  // TEST: NO



struct ElfRela
{
    u64 offset;
    u64 info;
    i64 addend;
};



#endif // ELF_RELA_H
