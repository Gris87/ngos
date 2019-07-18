#ifndef ELF_SYMBOL_H
#define ELF_SYMBOL_H



#include <elf/symbolbind.h>
#include <elf/symboltype.h>
#include <elf/symbolvisibility.h>
#include <ngos/types.h>



#define ELF_SYMBOL_BIND(info)        ((info) >> 4)
#define ELF_SYMBOL_TYPE(info)        ((info) & 0x0F)
#define ELF_SYMBOL_INFO(bind, type)  (((bind) << 4) + ((type) & 0x0F))

#define ELF_SYMBOL_VISIBILITY(other) ((other) & 0x03)



struct ElfSymbol
{
    u32 nameOffset;
    u8  info;
    u8  other;
    u16 sectionIndex;
    u64 value;
    u64 size;
};



#endif // ELF_SYMBOL_H
