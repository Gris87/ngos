#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZEGRANULARITY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZEGRANULARITY_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiCacheSizeGranularity: bad_uint8
{
    _1_KILOBYTE   = 0,
    _64_KILOBYTES = 1
};



inline const char8* enumToString(DmiCacheSizeGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    switch (granularity)
    {
        case DmiCacheSizeGranularity::_1_KILOBYTE:   return "1_KILOBYTE";
        case DmiCacheSizeGranularity::_64_KILOBYTES: return "64_KILOBYTES";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCacheSizeGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)granularity, enumToString(granularity));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZEGRANULARITY_H
