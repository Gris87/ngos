#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_PROGRAMHEADERTABLEENTRY_H
