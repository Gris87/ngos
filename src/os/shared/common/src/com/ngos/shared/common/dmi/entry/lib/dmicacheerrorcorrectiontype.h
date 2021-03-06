#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEERRORCORRECTIONTYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEERRORCORRECTIONTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiCacheErrorCorrectionType: u8
{
    NULL       = 0,
    OTHER      = 1,
    UNKNOWN    = 2,
    NONE       = 3,
    PARITY     = 4,
    SINGLE_BIT = 5,
    MULTI_BIT  = 6
};



inline const char8* enumToString(DmiCacheErrorCorrectionType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiCacheErrorCorrectionType::NULL:       return "NULL";
        case DmiCacheErrorCorrectionType::OTHER:      return "OTHER";
        case DmiCacheErrorCorrectionType::UNKNOWN:    return "UNKNOWN";
        case DmiCacheErrorCorrectionType::NONE:       return "NONE";
        case DmiCacheErrorCorrectionType::PARITY:     return "PARITY";
        case DmiCacheErrorCorrectionType::SINGLE_BIT: return "SINGLE_BIT";
        case DmiCacheErrorCorrectionType::MULTI_BIT:  return "MULTI_BIT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCacheErrorCorrectionType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEERRORCORRECTIONTYPE_H
