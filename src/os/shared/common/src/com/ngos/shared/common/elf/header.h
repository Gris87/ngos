#ifndef COM_NGOS_SHARED_COMMON_ELF_HEADER_H
#define COM_NGOS_SHARED_COMMON_ELF_HEADER_H



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
    bad_uint64                     entryPoint;
    bad_uint64                     programHeaderTableOffset;
    bad_uint64                     sectionHeaderTableOffset;
    bad_uint32                     flags;
    bad_uint16                     headerSize;
    bad_uint16                     programHeaderTableEntrySize;
    bad_uint16                     programHeaderTableEntryCount;
    bad_uint16                     sectionHeaderTableEntrySize;
    bad_uint16                     sectionHeaderTableEntryCount;
    bad_uint16                     sectionHeaderTableNamesIndex;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_HEADER_H
