#ifndef ELF_ELFHEADERIDENTIFICATION_H
#define ELF_ELFHEADERIDENTIFICATION_H



#include "elfclass.h"
#include "elfdata.h"
#include "elffileversion.h"
#include "elfosabi.h"



#define ELF_SIGNATURE 0x464C457F // 0x7F + ELF



struct ElfHeaderIdentification
{
    quint32        signature;
    ElfClass       fileClass;
    ElfData        fileData;
    ElfFileVersion version;
    ElfOsAbi       osAbi;

    quint64        __pad;
} __attribute__((packed));



#endif // ELF_ELFHEADERIDENTIFICATION_H
