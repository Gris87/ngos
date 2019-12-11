#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEOPERATINGMODECAPABILITYFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEOPERATINGMODECAPABILITYFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



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

DEFINE_FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlags, dmi_memory_device_operating_mode_capability_flags);



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



inline const char8* flagsToString(const DmiMemoryDeviceOperatingModeCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags.flags) // flags.flags == 0
    {
        return "NONE";
    }



    static char8 res[122];

    FLAGS_TO_STRING(res, flags.flags, flagToString, DmiMemoryDeviceOperatingModeCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiMemoryDeviceOperatingModeCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags.flags) // flags.flags == 0
    {
        return "NONE";
    }



    static char8 res[122];

    FLAGS_TO_STRING(res, flags.flags, flagToString, DmiMemoryDeviceOperatingModeCapabilityFlag);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEOPERATINGMODECAPABILITYFLAGS_H
