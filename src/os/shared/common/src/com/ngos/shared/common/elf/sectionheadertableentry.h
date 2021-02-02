#ifndef COM_NGOS_SHARED_COMMON_ELF_SECTIONHEADERTABLEENTRY_H
#define COM_NGOS_SHARED_COMMON_ELF_SECTIONHEADERTABLEENTRY_H



#include <com/ngos/shared/common/elf/sectionflags.h>
#include <com/ngos/shared/common/elf/sectiontype.h>



struct ElfSectionHeaderTableEntry
{
    bad_uint32             nameOffset;
    ElfSectionType  type;
    ElfSectionFlags flags;
    bad_uint64             virtualAddress;
    bad_uint64             offset;
    bad_uint64             size;
    bad_uint32             link;
    bad_uint32             info;
    bad_uint64             align;
    bad_uint64             entrySize;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_SECTIONHEADERTABLEENTRY_H
