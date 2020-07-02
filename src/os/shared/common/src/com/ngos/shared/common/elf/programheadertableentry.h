#ifndef ELF_PROGRAMHEADERTABLEENTRY_H
#define ELF_PROGRAMHEADERTABLEENTRY_H



#include <common/src/com/ngos/shared/common/elf/programflags.h>
#include <common/src/com/ngos/shared/common/elf/programtype.h>



struct ElfProgramHeaderTableEntry
{
    ElfProgramType  type;
    ElfProgramFlags flags;
    u64             offset;
    u64             virtualAddress;
    u64             physicalAddress;
    u64             fileSize;
    u64             memorySize;
    u64             align;
};



#endif // ELF_PROGRAMHEADERTABLEENTRY_H
