#ifndef ELF_PROGRAMHEADERTABLEENTRY_H
#define ELF_PROGRAMHEADERTABLEENTRY_H



#include <elf/programflags.h>
#include <elf/programtype.h>



struct ElfProgramHeaderTableEntry
{
    ElfProgramType    type;
    elf_program_flags flags;
    u64               offset;
    u64               virtualAddress;
    u64               physicalAddress;
    u64               fileSize;
    u64               memorySize;
    u64               align;
};



#endif // ELF_PROGRAMHEADERTABLEENTRY_H
