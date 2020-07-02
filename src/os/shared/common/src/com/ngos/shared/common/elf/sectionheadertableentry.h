#ifndef ELF_SECTIONHEADERTABLEENTRY_H
#define ELF_SECTIONHEADERTABLEENTRY_H



#include <elf/sectionflags.h>
#include <elf/sectiontype.h>



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



#endif // ELF_SECTIONHEADERTABLEENTRY_H
