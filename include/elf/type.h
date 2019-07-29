#ifndef ELF_TYPE_H
#define ELF_TYPE_H



#include <ngos/types.h>



enum class ElfType: u16
{
    NONE            = 0,
    RELOCATABLE     = 1,
    EXECUTABLE      = 2,
    DYNAMIC_LIBRARY = 3,
    CORE            = 4
};



inline const char8* elfTypeToString(ElfType type) // TEST: NO
{
    switch (type)
    {
        case ElfType::NONE:            return "NONE";
        case ElfType::RELOCATABLE:     return "RELOCATABLE";
        case ElfType::EXECUTABLE:      return "EXECUTABLE";
        case ElfType::DYNAMIC_LIBRARY: return "DYNAMIC_LIBRARY";
        case ElfType::CORE:            return "CORE";

        default: return "UNKNOWN";
    }
}



#endif // ELF_TYPE_H
