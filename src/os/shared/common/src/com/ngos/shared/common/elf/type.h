#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_TYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_TYPE_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class ElfType: u16
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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%04X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_TYPE_H
