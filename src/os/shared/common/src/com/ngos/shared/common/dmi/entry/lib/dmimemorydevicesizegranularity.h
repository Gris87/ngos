#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiMemoryDeviceSizeGranularity: bad_uint8
{
    _1_MEGABYTE = 0,
    _1_KILOBYTE = 1
};



inline const char8* enumToString(DmiMemoryDeviceSizeGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    switch (granularity)
    {
        case DmiMemoryDeviceSizeGranularity::_1_MEGABYTE: return "1_MEGABYTE";
        case DmiMemoryDeviceSizeGranularity::_1_KILOBYTE: return "1_KILOBYTE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiMemoryDeviceSizeGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", (bad_uint8)granularity, enumToString(granularity));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H
