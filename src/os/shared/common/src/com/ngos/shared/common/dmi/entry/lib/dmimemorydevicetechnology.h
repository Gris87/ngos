#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETECHNOLOGY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETECHNOLOGY_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiMemoryDeviceTechnology: u8
{
    NONE                    = 0,
    OTHER                   = 1,
    UNKNOWN                 = 2,
    DRAM                    = 3,
    NVDIMM_N                = 4,
    NVDIMM_F                = 5,
    NVDIMM_P                = 6,
    INTEL_PERSISTENT_MEMORY = 7
};



inline const char8* enumToString(DmiMemoryDeviceTechnology technology) // TEST: NO
{
    // COMMON_LT((" | technology = %u", technology)); // Commented to avoid bad looking logs



    switch (technology)
    {
        case DmiMemoryDeviceTechnology::NONE:                    return "NONE";
        case DmiMemoryDeviceTechnology::OTHER:                   return "OTHER";
        case DmiMemoryDeviceTechnology::UNKNOWN:                 return "UNKNOWN";
        case DmiMemoryDeviceTechnology::DRAM:                    return "DRAM";
        case DmiMemoryDeviceTechnology::NVDIMM_N:                return "NVDIMM_N";
        case DmiMemoryDeviceTechnology::NVDIMM_F:                return "NVDIMM_F";
        case DmiMemoryDeviceTechnology::NVDIMM_P:                return "NVDIMM_P";
        case DmiMemoryDeviceTechnology::INTEL_PERSISTENT_MEMORY: return "INTEL_PERSISTENT_MEMORY";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiMemoryDeviceTechnology technology) // TEST: NO
{
    // COMMON_LT((" | technology = %u", technology)); // Commented to avoid bad looking logs



    static char8 res[31];

    sprintf(res, "0x%02X (%s)", (u8)technology, enumToString(technology));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETECHNOLOGY_H
