#ifndef COM_NGOS_SHARED_COMMON_ELF_HEADER_H
#define COM_NGOS_SHARED_COMMON_ELF_HEADER_H



#include <com/ngos/shared/common/elf/headerflags.h>
#include <com/ngos/shared/common/elf/headeridentification.h>
#include <com/ngos/shared/common/elf/machine.h>
#include <com/ngos/shared/common/elf/type.h>
#include <com/ngos/shared/common/elf/version.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
struct ElfHeader
{
    ElfHeaderIdentification identification;
    ElfType                 type;
    ElfMachine              machine;
    ElfVersion              version;
    u64                     entryPoint;
    u64                     programHeaderTableOffset;
    u64                     sectionHeaderTableOffset;
    ElfHeaderFlags          flags;
    u16                     headerSize;
    u16                     programHeaderTableEntrySize;
    u16                     programHeaderTableEntryCount;
    u16                     sectionHeaderTableEntrySize;
    u16                     sectionHeaderTableEntryCount;
    u16                     sectionHeaderTableNamesIndex;
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



#endif // COM_NGOS_SHARED_COMMON_ELF_HEADER_H
