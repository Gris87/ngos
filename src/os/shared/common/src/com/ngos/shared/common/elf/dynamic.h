#ifndef COM_NGOS_SHARED_COMMON_ELF_DYNAMIC_H
#define COM_NGOS_SHARED_COMMON_ELF_DYNAMIC_H



#include <com/ngos/shared/common/elf/dynamictag.h>
#include <com/ngos/shared/common/ngos/types.h>



struct ElfDynamic
{
    ElfDynamicTag tag;

    union
    {
        u64 value;
        u64 address;
    };
};



#endif // COM_NGOS_SHARED_COMMON_ELF_DYNAMIC_H
