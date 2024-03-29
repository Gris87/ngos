#ifndef COM_NGOS_SHARED_COMMON_ELF_DATA_H
#define COM_NGOS_SHARED_COMMON_ELF_DATA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfData: u8
{
    NONE                   = 0,
    LEAST_SIGNIFICANT_BYTE = 1, // Object file data structures are littleendian
    MOST_SIGNIFICANT_BYTE  = 2  // Object file data structures are bigendian
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



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



inline const char8* enumToFullString(ElfData data) // TEST: NO
{
    // COMMON_LT((" | data = %u", data)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", (u8)data, enumToString(data));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_DATA_H
