#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHETYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHETYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiCacheType: u8
{
    NONE        = 0,
    OTHER       = 1,
    UNKNOWN     = 2,
    INSTRUCTION = 3,
    DATA        = 4,
    UNIFIED     = 5
};



inline const char8* enumToString(DmiCacheType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiCacheType::NONE:        return "NONE";
        case DmiCacheType::OTHER:       return "OTHER";
        case DmiCacheType::UNKNOWN:     return "UNKNOWN";
        case DmiCacheType::INSTRUCTION: return "INSTRUCTION";
        case DmiCacheType::DATA:        return "DATA";
        case DmiCacheType::UNIFIED:     return "UNIFIED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCacheType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[19];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHETYPE_H
