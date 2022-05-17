#ifndef COM_NGOS_SHARED_COMMON_ELF_DYNAMIC_H
#define COM_NGOS_SHARED_COMMON_ELF_DYNAMIC_H



#include <com/ngos/shared/common/elf/dynamictag.h>
#include <com/ngos/shared/common/ngos/types.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
struct ElfDynamic
{
    ElfDynamicTag tag;

    union
    {
        u64 value;
        u64 address;
    };
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



#endif // COM_NGOS_SHARED_COMMON_ELF_DYNAMIC_H
