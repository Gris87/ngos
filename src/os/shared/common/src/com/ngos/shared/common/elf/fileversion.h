#ifndef COM_NGOS_SHARED_COMMON_ELF_FILEVERSION_H
#define COM_NGOS_SHARED_COMMON_ELF_FILEVERSION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfFileVersion: u8
{
    NONE    = 0,
    CURRENT = 1
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* enumToString(ElfFileVersion version) // TEST: NO
{
    // COMMON_LT((" | version = %u", version)); // Commented to avoid bad looking logs



    switch (version)
    {
        case ElfFileVersion::NONE:    return "NONE";
        case ElfFileVersion::CURRENT: return "CURRENT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfFileVersion version) // TEST: NO
{
    // COMMON_LT((" | version = %u", version)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)version, enumToString(version));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_FILEVERSION_H
