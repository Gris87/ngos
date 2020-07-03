#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_HEADER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_HEADER_H



#include <com/ngos/shared/common/elf/headeridentification.h>
#include <com/ngos/shared/common/elf/machine.h>
#include <com/ngos/shared/common/elf/type.h>
#include <com/ngos/shared/common/elf/version.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_HEADER_H
