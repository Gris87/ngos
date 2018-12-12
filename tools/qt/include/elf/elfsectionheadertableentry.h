#ifndef ELF_ELFSECTIONHEADERTABLEENTRY_H
#define ELF_ELFSECTIONHEADERTABLEENTRY_H



#include "elfsectionflags.h"
#include "elfsectiontype.h"



struct ElfSectionHeaderTableEntry
{
    quint32           nameOffset;
    ElfSectionType    type;
    elf_section_flags flags;
    quint64           virtualAddress;
    quint64           offset;
    quint64           size;
    quint32           link;
    quint32           info;
    quint64           align;
    quint64           entrySize;
};



#endif // ELF_ELFSECTIONHEADERTABLEENTRY_H
