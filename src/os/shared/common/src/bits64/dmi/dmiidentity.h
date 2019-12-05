#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMIIDENTITY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMIIDENTITY_H



#include <ngos/types.h>



enum class DmiIdentity: u8
{
    BIOS_VENDOR,
    BIOS_VERSION,
    BIOS_RELEASE_DATE,
    SYSTEM_MANUFACTURER,
    SYSTEM_PRODUCT_NAME,
    SYSTEM_VERSION,
    SYSTEM_SERIAL_NUMBER,
    SYSTEM_SKU_NUMBER,
    SYSTEM_FAMILY,
    BASEBOARD_MANUFACTURER,
    BASEBOARD_PRODUCT,
    BASEBOARD_VERSION,
    BASEBOARD_SERIAL_NUMBER,
    BASEBOARD_ASSET_TAG,
    CHASSIS_MANUFACTURER,
    CHASSIS_VERSION,
    CHASSIS_SERIAL_NUMBER,
    CHASSIS_ASSET_TAG,
    MAXIMUM
};



inline const char8* dmiIdentityToString(DmiIdentity identity) // TEST: NO
{
    // COMMON_LT((" | identity = %u", identity)); // Commented to avoid bad looking logs



    switch (identity)
    {
        case DmiIdentity::BIOS_VENDOR:             return "BIOS_VENDOR";
        case DmiIdentity::BIOS_VERSION:            return "BIOS_VERSION";
        case DmiIdentity::BIOS_RELEASE_DATE:       return "BIOS_RELEASE_DATE";
        case DmiIdentity::SYSTEM_MANUFACTURER:     return "SYSTEM_MANUFACTURER";
        case DmiIdentity::SYSTEM_PRODUCT_NAME:     return "SYSTEM_PRODUCT_NAME";
        case DmiIdentity::SYSTEM_VERSION:          return "SYSTEM_VERSION";
        case DmiIdentity::SYSTEM_SERIAL_NUMBER:    return "SYSTEM_SERIAL_NUMBER";
        case DmiIdentity::SYSTEM_SKU_NUMBER:       return "SYSTEM_SKU_NUMBER";
        case DmiIdentity::SYSTEM_FAMILY:           return "SYSTEM_FAMILY";
        case DmiIdentity::BASEBOARD_MANUFACTURER:  return "BASEBOARD_MANUFACTURER";
        case DmiIdentity::BASEBOARD_PRODUCT:       return "BASEBOARD_PRODUCT";
        case DmiIdentity::BASEBOARD_VERSION:       return "BASEBOARD_VERSION";
        case DmiIdentity::BASEBOARD_SERIAL_NUMBER: return "BASEBOARD_SERIAL_NUMBER";
        case DmiIdentity::BASEBOARD_ASSET_TAG:     return "BASEBOARD_ASSET_TAG";
        case DmiIdentity::CHASSIS_MANUFACTURER:    return "CHASSIS_MANUFACTURER";
        case DmiIdentity::CHASSIS_VERSION:         return "CHASSIS_VERSION";
        case DmiIdentity::CHASSIS_SERIAL_NUMBER:   return "CHASSIS_SERIAL_NUMBER";
        case DmiIdentity::CHASSIS_ASSET_TAG:       return "CHASSIS_ASSET_TAG";
        case DmiIdentity::MAXIMUM:                 return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMIIDENTITY_H