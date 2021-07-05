#ifndef COM_NGOS_SHARED_COMMON_ELF_REL_H
#define COM_NGOS_SHARED_COMMON_ELF_REL_H



#include <com/ngos/shared/common/elf/relocationtype.h>
#include <com/ngos/shared/common/ngos/types.h>



struct ElfRel
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
};



#endif // COM_NGOS_SHARED_COMMON_ELF_REL_H
