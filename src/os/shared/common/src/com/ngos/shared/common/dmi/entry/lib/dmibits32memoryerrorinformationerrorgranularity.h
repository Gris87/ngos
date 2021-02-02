#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERRORGRANULARITY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERRORGRANULARITY_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiBits32MemoryErrorInformationErrorGranularity: bad_uint8
{
    NONE                   = 0,
    OTHER                  = 1,
    UNKNOWN                = 2,
    DEVICE_LEVEL           = 3,
    MEMORY_PARTITION_LEVEL = 4
};



inline const char8* enumToString(DmiBits32MemoryErrorInformationErrorGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    switch (granularity)
    {
        case DmiBits32MemoryErrorInformationErrorGranularity::NONE:                   return "NONE";
        case DmiBits32MemoryErrorInformationErrorGranularity::OTHER:                  return "OTHER";
        case DmiBits32MemoryErrorInformationErrorGranularity::UNKNOWN:                return "UNKNOWN";
        case DmiBits32MemoryErrorInformationErrorGranularity::DEVICE_LEVEL:           return "DEVICE_LEVEL";
        case DmiBits32MemoryErrorInformationErrorGranularity::MEMORY_PARTITION_LEVEL: return "MEMORY_PARTITION_LEVEL";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiBits32MemoryErrorInformationErrorGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", (bad_uint8)granularity, enumToString(granularity));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERRORGRANULARITY_H
