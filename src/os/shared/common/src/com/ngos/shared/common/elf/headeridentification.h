#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H



#include <common/src/com/ngos/shared/common/elf/class.h>
#include <common/src/com/ngos/shared/common/elf/data.h>
#include <common/src/com/ngos/shared/common/elf/fileversion.h>
#include <common/src/com/ngos/shared/common/elf/osabi.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H
