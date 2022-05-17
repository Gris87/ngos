#ifndef COM_NGOS_SHARED_COMMON_ELF_CLASS_H
#define COM_NGOS_SHARED_COMMON_ELF_CLASS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfClass: u8
{
    NONE     = 0,
    CLASS_32 = 1,
    CLASS_64 = 2
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* enumToString(ElfClass elfClass) // TEST: NO
{
    // COMMON_LT((" | elfClass = %u", elfClass)); // Commented to avoid bad looking logs



    switch (elfClass)
    {
        case ElfClass::NONE:     return "NONE";
        case ElfClass::CLASS_32: return "CLASS_32";
        case ElfClass::CLASS_64: return "CLASS_64";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfClass elfClass) // TEST: NO
{
    // COMMON_LT((" | elfClass = %u", elfClass)); // Commented to avoid bad looking logs



    static char8 res[16];

    sprintf(res, "0x%02X (%s)", (u8)elfClass, enumToString(elfClass));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_CLASS_H
