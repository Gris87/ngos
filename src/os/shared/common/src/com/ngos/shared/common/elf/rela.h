#ifndef COM_NGOS_SHARED_COMMON_ELF_RELA_H
#define COM_NGOS_SHARED_COMMON_ELF_RELA_H



#include <com/ngos/shared/common/elf/relocationtype.h>
#include <com/ngos/shared/common/ngos/types.h>



struct ElfRela
{
    u64 offset;

    union
    {
        struct
        {
            ElfRelocationType type;
            u32               symbol;
        };

        u64 info;
    };

    i64 addend;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_RELA_H
