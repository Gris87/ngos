#ifndef COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H
#define COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H



#include <com/ngos/shared/common/elf/class.h>
#include <com/ngos/shared/common/elf/data.h>
#include <com/ngos/shared/common/elf/fileversion.h>
#include <com/ngos/shared/common/elf/osabi.h>



#define ELF_SIGNATURE 0x464C457F // 0x7F + ELF



struct ElfHeaderIdentification
{
    u32            signature;
    ElfClass       fileClass;
    ElfData        fileData;
    ElfFileVersion version;
    ElfOsAbi       osAbi;

    u64            __pad;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H
