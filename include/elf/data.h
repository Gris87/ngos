#ifndef ELF_DATA_H
#define ELF_DATA_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
#endif



enum class ElfData: u8
{
    NONE                   = 0,
    LEAST_SIGNIFICANT_BYTE = 1 ,
    MOST_SIGNIFICANT_BYTE  = 2
};



inline const char8* enumToString(ElfData data) // TEST: NO
{
    switch (data)
    {
        case ElfData::NONE:                   return "NONE";
        case ElfData::LEAST_SIGNIFICANT_BYTE: return "LEAST_SIGNIFICANT_BYTE";
        case ElfData::MOST_SIGNIFICANT_BYTE:  return "MOST_SIGNIFICANT_BYTE";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(ElfData data) // TEST: NO
{
    static char8 res[30];

    sprintf(res, "0x%02X (%s)", data, enumToString(data));

    return res;
}



#endif



#endif // ELF_DATA_H
