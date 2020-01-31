#ifndef ELF_SYMBOL_H
#define ELF_SYMBOL_H



#include <elf/symbolbind.h>
#include <elf/symboltype.h>
#include <elf/symbolvisibility.h>
#include <ngos/types.h>



struct ElfSymbol
{
    u32 nameOffset;

    union
    {
        struct
        {
            u8 bind: 4; // TODO: Use enum ElfSymbolBind
            u8 type: 4; // TODO: Use enum ElfSymbolType
        };

        u8 info;
    };

    union
    {
        struct
        {
            u8 __reserved: 5;
            u8 visibility: 3; // TODO: Use enum ElfSymbolVisibility
        };

        u8 other;
    };

    u16 sectionIndex;
    u64 value;
    u64 size;
};



#endif // ELF_SYMBOL_H
