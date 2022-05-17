#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOLOTHER_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOLOTHER_H



#include <com/ngos/shared/common/elf/symbolvisibility.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
struct ElfSymbolOther
{
    union
    {
        struct
        {
            u8 __reserved: 5;
            u8 visibility: 3; // TODO: Use enum ElfSymbolVisibility
        };

        u8 value8;
    };
} __attribute__((packed));
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOLOTHER_H
