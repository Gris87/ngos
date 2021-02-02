#ifndef COM_NGOS_SHARED_COMMON_ELF_RELA_H
#define COM_NGOS_SHARED_COMMON_ELF_RELA_H



#include <com/ngos/shared/common/elf/relatype.h>
#include <com/ngos/shared/common/ngos/types.h>



struct ElfRela
{
    bad_uint64 offset;

    union
    {
        struct
        {
            ElfRelaType type;
            bad_uint32         symbol;
        };

        bad_uint64 info;
    };

    bad_int64 addend;
};



#endif // COM_NGOS_SHARED_COMMON_ELF_RELA_H
