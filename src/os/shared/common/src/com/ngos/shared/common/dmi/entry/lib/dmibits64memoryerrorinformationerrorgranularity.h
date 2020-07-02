#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBITS64MEMORYERRORINFORMATIONERRORGRANULARITY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBITS64MEMORYERRORINFORMATIONERRORGRANULARITY_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiBits64MemoryErrorInformationErrorGranularity: u8
{
    NONE                   = 0,
    OTHER                  = 1,
    UNKNOWN                = 2,
    DEVICE_LEVEL           = 3,
    MEMORY_PARTITION_LEVEL = 4
};



inline const char8* enumToString(DmiBits64MemoryErrorInformationErrorGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    switch (granularity)
    {
        case DmiBits64MemoryErrorInformationErrorGranularity::NONE:                   return "NONE";
        case DmiBits64MemoryErrorInformationErrorGranularity::OTHER:                  return "OTHER";
        case DmiBits64MemoryErrorInformationErrorGranularity::UNKNOWN:                return "UNKNOWN";
        case DmiBits64MemoryErrorInformationErrorGranularity::DEVICE_LEVEL:           return "DEVICE_LEVEL";
        case DmiBits64MemoryErrorInformationErrorGranularity::MEMORY_PARTITION_LEVEL: return "MEMORY_PARTITION_LEVEL";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiBits64MemoryErrorInformationErrorGranularity granularity) // TEST: NO
{
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", granularity, enumToString(granularity));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBITS64MEMORYERRORINFORMATIONERRORGRANULARITY_H
