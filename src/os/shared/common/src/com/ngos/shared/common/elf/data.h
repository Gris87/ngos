#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_DATA_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_DATA_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class ElfData: u8
{
    NONE                   = 0,
    LEAST_SIGNIFICANT_BYTE = 1,
    MOST_SIGNIFICANT_BYTE  = 2
};



inline const char8* enumToString(ElfData data) // TEST: NO
{
    // COMMON_LT((" | data = %u", data)); // Commented to avoid bad looking logs



    switch (data)
    {
        case ElfData::NONE:                   return "NONE";
        case ElfData::LEAST_SIGNIFICANT_BYTE: return "LEAST_SIGNIFICANT_BYTE";
        case ElfData::MOST_SIGNIFICANT_BYTE:  return "MOST_SIGNIFICANT_BYTE";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfData data) // TEST: NO
{
    // COMMON_LT((" | data = %u", data)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", data, enumToString(data));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_DATA_H