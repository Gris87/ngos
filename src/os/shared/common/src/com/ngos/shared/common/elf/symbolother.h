#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOLOTHER_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOLOTHER_H



#include <com/ngos/shared/common/elf/symbolvisibility.h>



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



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOLOTHER_H
