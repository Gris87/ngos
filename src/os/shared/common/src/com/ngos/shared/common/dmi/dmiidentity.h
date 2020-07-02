#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMIIDENTITY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMIIDENTITY_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiIdentity: u8
{
    BIOS_VENDOR,
    BIOS_VERSION,
    BIOS_RELEASE_DATE,
    SYSTEM_MANUFACTURER,
    SYSTEM_PRODUCT_NAME,
    BASEBOARD_MANUFACTURER,
    BASEBOARD_PRODUCT,
    MAXIMUM
};



inline const char8* enumToString(DmiIdentity identity) // TEST: NO
{
    // COMMON_LT((" | identity = %u", identity)); // Commented to avoid bad looking logs



    switch (identity)
    {
        case DmiIdentity::BIOS_VENDOR:            return "BIOS_VENDOR";
        case DmiIdentity::BIOS_VERSION:           return "BIOS_VERSION";
        case DmiIdentity::BIOS_RELEASE_DATE:      return "BIOS_RELEASE_DATE";
        case DmiIdentity::SYSTEM_MANUFACTURER:    return "SYSTEM_MANUFACTURER";
        case DmiIdentity::SYSTEM_PRODUCT_NAME:    return "SYSTEM_PRODUCT_NAME";
        case DmiIdentity::BASEBOARD_MANUFACTURER: return "BASEBOARD_MANUFACTURER";
        case DmiIdentity::BASEBOARD_PRODUCT:      return "BASEBOARD_PRODUCT";
        case DmiIdentity::MAXIMUM:                return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiIdentity identity) // TEST: NO
{
    // COMMON_LT((" | identity = %u", identity)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", identity, enumToString(identity));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMIIDENTITY_H
