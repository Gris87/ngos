#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEASSOCIATIVITY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEASSOCIATIVITY_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiCacheAssociativity: u8
{
    NONE          = 0,
    OTHER         = 1,
    UNKNOWN       = 2,
    DIRECT_MAPPED = 3,
    _2_WAY        = 4,
    _4_WAY        = 5,
    FULLY         = 6,
    _8_WAY        = 7,
    _16_WAY       = 8,
    _12_WAY       = 9,
    _24_WAY       = 10,
    _32_WAY       = 11,
    _48_WAY       = 12,
    _64_WAY       = 13,
    _20_WAY       = 14
};



inline const char8* enumToString(DmiCacheAssociativity associativity) // TEST: NO
{
    // COMMON_LT((" | associativity = %u", associativity)); // Commented to avoid bad looking logs



    switch (associativity)
    {
        case DmiCacheAssociativity::NONE:          return "NONE";
        case DmiCacheAssociativity::OTHER:         return "OTHER";
        case DmiCacheAssociativity::UNKNOWN:       return "UNKNOWN";
        case DmiCacheAssociativity::DIRECT_MAPPED: return "DIRECT_MAPPED";
        case DmiCacheAssociativity::_2_WAY:        return "_2_WAY";
        case DmiCacheAssociativity::_4_WAY:        return "_4_WAY";
        case DmiCacheAssociativity::FULLY:         return "FULLY";
        case DmiCacheAssociativity::_8_WAY:        return "_8_WAY";
        case DmiCacheAssociativity::_16_WAY:       return "_16_WAY";
        case DmiCacheAssociativity::_12_WAY:       return "_12_WAY";
        case DmiCacheAssociativity::_24_WAY:       return "_24_WAY";
        case DmiCacheAssociativity::_32_WAY:       return "_32_WAY";
        case DmiCacheAssociativity::_48_WAY:       return "_48_WAY";
        case DmiCacheAssociativity::_64_WAY:       return "_64_WAY";
        case DmiCacheAssociativity::_20_WAY:       return "_20_WAY";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCacheAssociativity associativity) // TEST: NO
{
    // COMMON_LT((" | associativity = %u", associativity)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%02X (%s)", associativity, enumToString(associativity));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEASSOCIATIVITY_H
