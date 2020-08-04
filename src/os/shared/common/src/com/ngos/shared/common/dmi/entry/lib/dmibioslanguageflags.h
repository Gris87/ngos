#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSLANGUAGEFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSLANGUAGEFLAGS_H



#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 dmi_bios_language_flags;

enum class DmiBiosLanguageFlag: dmi_bios_language_flags
{
    NONE               = 0,
    ABBREVIATED_FORMAT = (1ULL << 0)
};

DEFINE_FLAGS(DmiBiosLanguageFlags, dmi_bios_language_flags); // TEST: NO



inline const char8* flagToString(DmiBiosLanguageFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiBiosLanguageFlag::NONE:               return "NONE";
        case DmiBiosLanguageFlag::ABBREVIATED_FORMAT: return "ABBREVIATED_FORMAT";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiBiosLanguageFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%02X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiBiosLanguageFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[34];

    FLAGS_TO_STRING(res, flags.flags, DmiBiosLanguageFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiBiosLanguageFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[41];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiBiosLanguageFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSLANGUAGEFLAGS_H
