#ifndef ELF_HEADERIDENTIFICATION_H
#define ELF_HEADERIDENTIFICATION_H



#include <elf/class.h>
#include <elf/data.h>
#include <elf/fileversion.h>
#include <elf/osabi.h>



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



#endif // ELF_HEADERIDENTIFICATION_H