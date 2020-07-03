#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiMemoryDeviceSizeGranularity: u8
{
    _1_MEGABYTE = 0,
    _1_KILOBYTE = 1
};



inline const char8* enumToString(DmiMemoryDeviceSizeGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    switch (granularity)
    {
        case DmiMemoryDeviceSizeGranularity::_1_MEGABYTE: return "_1_MEGABYTE";
        case DmiMemoryDeviceSizeGranularity::_1_KILOBYTE: return "_1_KILOBYTE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiMemoryDeviceSizeGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    static char8 res[19];

    sprintf(res, "0x%02X (%s)", granularity, enumToString(granularity));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H
