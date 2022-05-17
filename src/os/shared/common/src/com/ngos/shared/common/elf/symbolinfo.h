#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOLINFO_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOLINFO_H



#include <com/ngos/shared/common/elf/symbolbind.h>
#include <com/ngos/shared/common/elf/symboltype.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
struct ElfSymbolInfo
{
    union
    {
        struct
        {
            u8 bind: 4; // TODO: Use enum ElfSymbolBind
            u8 type: 4; // TODO: Use enum ElfSymbolType
        };

        u8 value8;
    };
} __attribute__((packed));
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOLINFO_H
