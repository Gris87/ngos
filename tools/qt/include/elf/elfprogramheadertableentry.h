#ifndef ELF_ELFPROGRAMHEADERTABLEENTRY_H
#define ELF_ELFPROGRAMHEADERTABLEENTRY_H



#include "elfprogramflags.h"
#include "elfprogramtype.h"



struct ElfProgramHeaderTableEntry
{
    ElfProgramType    type;
    elf_program_flags flags;
    quint64           offset;
    quint64           virtualAddress;
    quint64           physicalAddress;
    quint64           fileSize;
    quint64           memorySize;
    quint64           align;
};



#endif // ELF_ELFPROGRAMHEADERTABLEENTRY_H
