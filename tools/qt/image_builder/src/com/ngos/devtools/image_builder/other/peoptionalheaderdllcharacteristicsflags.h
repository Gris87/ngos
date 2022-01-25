#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_PEOPTIONALHEADERDLLCHARACTERISTICSFLAGS_H
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_PEOPTIONALHEADERDLLCHARACTERISTICSFLAGS_H



#include <Qt>
#include <stdio.h>
#include <string.h>

#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/devtools/shared/utils/string.h>



typedef quint16 pe_optional_header_dll_characteristics_flags;

enum class PeOptionalHeaderDllCharacteristicsFlag: pe_optional_header_dll_characteristics_flags
{
    NONE                    = 0,
    HIGH_ENTROPY_VA       = (1ULL << 5),  // Image can handle a high entropy 64-bit virtual address space.
    DYNAMIC_BASE          = (1ULL << 6),  // DLL can be relocated at load time.
    FORCE_INTEGRITY       = (1ULL << 7),  // Code Integrity checks are enforced.
    NX_COMPAT             = (1ULL << 8),  // Image is NX compatible.
    NO_ISOLATION          = (1ULL << 9),  // Isolation aware, but do not isolate the image.
    NO_SEH                = (1ULL << 10), // Does not use structured exception (SE) handling. No SE handler may be called in this image.
    NO_BIND               = (1ULL << 11), // Do not bind the image.
    APPCONTAINER          = (1ULL << 12), // Image must execute in an AppContainer.
    WDM_DRIVER            = (1ULL << 13), // A WDM driver.
    GUARD_CF              = (1ULL << 14), // Image supports Control Flow Guard.
    TERMINAL_SERVER_AWARE = (1ULL << 15)  // Terminal Server aware.
};

DEFINE_FLAGS(PeOptionalHeaderDllCharacteristicsFlags, pe_optional_header_dll_characteristics_flags); // TEST: NO



inline const char8* flagToString(PeOptionalHeaderDllCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PeOptionalHeaderDllCharacteristicsFlag::NONE: return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PeOptionalHeaderDllCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%08X (%s)", (pe_optional_header_dll_characteristics_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PeOptionalHeaderDllCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[48];

    FLAGS_TO_STRING(res, flags.flags, PeOptionalHeaderDllCharacteristicsFlag);

    return res;
}



inline const char8* flagsToFullString(const PeOptionalHeaderDllCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[61];

    FLAGS_TO_FULL_STRING(res, flags.flags, PeOptionalHeaderDllCharacteristicsFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_PEOPTIONALHEADERDLLCHARACTERISTICSFLAGS_H
