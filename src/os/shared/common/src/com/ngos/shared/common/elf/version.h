#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_VERSION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_VERSION_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class ElfVersion: u32
{
    NONE    = 0,
    CURRENT = 1
};



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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfVersion version) // TEST: NO
{
    // COMMON_LT((" | version = %u", version)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%08X (%s)", version, enumToString(version));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_VERSION_H
