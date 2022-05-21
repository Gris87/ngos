#ifndef COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H
#define COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H



#include <com/ngos/shared/common/elf/class.h>
#include <com/ngos/shared/common/elf/data.h>
#include <com/ngos/shared/common/elf/fileversion.h>
#include <com/ngos/shared/common/elf/osabi.h>



// Verified with ElfSpecVerifier // https://www.uclibc.org/docs/elf-64-gen.pdf
#define ELF_SIGNATURE 0x464C457F // 0x7F + ELF



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
struct ElfHeaderIdentification
{
    u32            signature; // File identification
    ElfClass       fileClass;  // File class
    ElfData        fileData;   // Data encoding
    ElfFileVersion version;    // File version
    ElfOsAbi       osAbi;      // OS/ABI identification
    u8             abiVersion; // ABI version
    u8             __pad[7];   // Start of padding bytes
} __attribute__((packed));
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



#endif // COM_NGOS_SHARED_COMMON_ELF_HEADERIDENTIFICATION_H
