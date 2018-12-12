#ifndef ELF_HEADER_H
#define ELF_HEADER_H



#include <elf/headeridentification.h>
#include <elf/machine.h>
#include <elf/type.h>
#include <elf/version.h>



struct ElfHeader
{
    ElfHeaderIdentification identification;
    ElfType                 type;
    ElfMachine              machine;
    ElfVersion              version;
    u64                     entryPoint;
    u64                     programHeaderTableOffset;
    u64                     sectionHeaderTableOffset;
    u32                     flags;
    u16                     headerSize;
    u16                     programHeaderTableEntrySize;
    u16                     programHeaderTableEntryCount;
    u16                     sectionHeaderTableEntrySize;
    u16                     sectionHeaderTableEntryCount;
    u16                     sectionHeaderTableNamesIndex;
};



#endif // ELF_HEADER_H
