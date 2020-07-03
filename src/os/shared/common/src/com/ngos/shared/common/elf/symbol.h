#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_SYMBOL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_SYMBOL_H



#include <common/src/com/ngos/shared/common/elf/symbolbind.h>
#include <common/src/com/ngos/shared/common/elf/symboltype.h>
#include <common/src/com/ngos/shared/common/elf/symbolvisibility.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_SYMBOL_H
