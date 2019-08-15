#ifndef ELF_RELA_H
#define ELF_RELA_H



#include <elf/relatype.h>
#include <ngos/types.h>



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



#endif // ELF_RELA_H
