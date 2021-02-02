#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOLINFO_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOLINFO_H



#include <com/ngos/shared/common/elf/symbolbind.h>
#include <com/ngos/shared/common/elf/symboltype.h>



struct ElfSymbolInfo
{
    union
    {
        struct
        {
            bad_uint8 bind: 4; // TODO: Use enum ElfSymbolBind
            bad_uint8 type: 4; // TODO: Use enum ElfSymbolType
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOLINFO_H
