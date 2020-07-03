#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_RELA_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_RELA_H



#include <common/src/com/ngos/shared/common/elf/relatype.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct ElfRela
{
    u64 offset;

    union
    {
        struct
        {
            ElfRelaType type;
            u32         symbol;
        };

        u64 info;
    };

    i64 addend;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_RELA_H
