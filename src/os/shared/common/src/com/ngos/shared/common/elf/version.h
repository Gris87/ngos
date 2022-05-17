#ifndef COM_NGOS_SHARED_COMMON_ELF_VERSION_H
#define COM_NGOS_SHARED_COMMON_ELF_VERSION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfVersion: u32
{
    NONE    = 0,
    CURRENT = 1
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* enumToString(ElfVersion version) // TEST: NO
{
    // COMMON_LT((" | version = %u", version)); // Commented to avoid bad looking logs



    switch (version)
    {
        case ElfVersion::NONE:    return "NONE";
        case ElfVersion::CURRENT: return "CURRENT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfVersion version) // TEST: NO
{
    // COMMON_LT((" | version = %u", version)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%08X (%s)", (u32)version, enumToString(version));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_VERSION_H
