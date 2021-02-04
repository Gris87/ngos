#ifndef COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
#define COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H



#include <com/ngos/shared/common/elf/programflags.h>
#include <com/ngos/shared/common/elf/programtype.h>



struct ElfProgramHeaderTableEntry
{
    ElfProgramType  type;
    ElfProgramFlags flags;
    u64             offset;
    address_t       virtualAddress;
    address_t       physicalAddress;
    u64             fileSize;
    u64             memorySize;
    u64             align;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
