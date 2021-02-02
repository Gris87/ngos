#ifndef COM_NGOS_SHARED_COMMON_ELF_TYPE_H
#define COM_NGOS_SHARED_COMMON_ELF_TYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class ElfType: bad_uint16
{
    NONE            = 0,
    RELOCATABLE     = 1,
    EXECUTABLE      = 2,
    DYNAMIC_LIBRARY = 3,
    CORE            = 4
};



inline const char8* enumToString(ElfType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



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



inline const char8* enumToFullString(ElfType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%04X (%s)", (bad_uint16)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_TYPE_H
