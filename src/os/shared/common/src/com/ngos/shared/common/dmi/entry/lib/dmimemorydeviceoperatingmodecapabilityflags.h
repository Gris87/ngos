#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEOPERATINGMODECAPABILITYFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEOPERATINGMODECAPABILITYFLAGS_H



#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 dmi_memory_device_operating_mode_capability_flags;

enum class DmiMemoryDeviceOperatingModeCapabilityFlag: dmi_memory_device_operating_mode_capability_flags
{
    NONE                               = 0,
    OTHER                              = (1ULL << 1),
    UNKNOWN                            = (1ULL << 2),
    VOLATILE_MEMORY                    = (1ULL << 3),
    BYTE_ACCESSIBLE_PERSISTENT_MEMORY  = (1ULL << 4),
    BLOCK_ACCESSIBLE_PERSISTENT_MEMORY = (1ULL << 5)
};

DEFINE_FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlags, dmi_memory_device_operating_mode_capability_flags); // TEST: NO



inline const char8* flagToString(DmiMemoryDeviceOperatingModeCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiMemoryDeviceOperatingModeCapabilityFlag::NONE:                               return "NONE";
        case DmiMemoryDeviceOperatingModeCapabilityFlag::OTHER:                              return "OTHER";
        case DmiMemoryDeviceOperatingModeCapabilityFlag::UNKNOWN:                            return "UNKNOWN";
        case DmiMemoryDeviceOperatingModeCapabilityFlag::VOLATILE_MEMORY:                    return "VOLATILE_MEMORY";
        case DmiMemoryDeviceOperatingModeCapabilityFlag::BYTE_ACCESSIBLE_PERSISTENT_MEMORY:  return "BYTE_ACCESSIBLE_PERSISTENT_MEMORY";
        case DmiMemoryDeviceOperatingModeCapabilityFlag::BLOCK_ACCESSIBLE_PERSISTENT_MEMORY: return "BLOCK_ACCESSIBLE_PERSISTENT_MEMORY";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiMemoryDeviceOperatingModeCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[44];

    sprintf(res, "0x%04X (%s)", (dmi_memory_device_operating_mode_capability_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiMemoryDeviceOperatingModeCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[122];

    FLAGS_TO_STRING(res, flags.flags, DmiMemoryDeviceOperatingModeCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiMemoryDeviceOperatingModeCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[131];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiMemoryDeviceOperatingModeCapabilityFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEOPERATINGMODECAPABILITYFLAGS_H
