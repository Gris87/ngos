#ifndef COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
#define COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H



#include <com/ngos/shared/common/elf/programflags.h>
#include <com/ngos/shared/common/elf/programtype.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
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
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



#endif // COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
