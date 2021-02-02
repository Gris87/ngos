#ifndef COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
#define COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H



#include <com/ngos/shared/common/elf/programflags.h>
#include <com/ngos/shared/common/elf/programtype.h>



struct ElfProgramHeaderTableEntry
{
    ElfProgramType  type;
    ElfProgramFlags flags;
    bad_uint64             offset;
    bad_uint64             virtualAddress;
    bad_uint64             physicalAddress;
    bad_uint64             fileSize;
    bad_uint64             memorySize;
    bad_uint64             align;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
