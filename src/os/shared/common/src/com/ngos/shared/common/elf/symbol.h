#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOL_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOL_H



#include <com/ngos/shared/common/elf/symbolinfo.h>
#include <com/ngos/shared/common/elf/symbolother.h>
#include <com/ngos/shared/common/ngos/types.h>



struct ElfSymbol
{
    u32            nameOffset;
    ElfSymbolInfo  info;
    ElfSymbolOther other;
    u16            sectionIndex;
    u64            value;
    u64            size;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOL_H
