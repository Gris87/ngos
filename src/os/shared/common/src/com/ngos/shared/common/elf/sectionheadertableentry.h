#ifndef COM_NGOS_SHARED_COMMON_ELF_SECTIONHEADERTABLEENTRY_H
#define COM_NGOS_SHARED_COMMON_ELF_SECTIONHEADERTABLEENTRY_H



#include <com/ngos/shared/common/elf/sectionflags.h>
#include <com/ngos/shared/common/elf/sectiontype.h>



struct ElfSectionHeaderTableEntry
{
    u32             nameOffset;
    ElfSectionType  type;
    ElfSectionFlags flags;
    u64             virtualAddress;
    u64             offset;
    u64             size;
    u32             link;
    u32             info;
    u64             align;
    u64             entrySize;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_SECTIONHEADERTABLEENTRY_H
