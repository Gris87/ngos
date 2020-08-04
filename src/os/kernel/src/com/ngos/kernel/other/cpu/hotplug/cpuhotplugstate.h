#ifndef COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTATE_H
#define COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTATE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class CpuHotplugState: u8 // Ignore CppEnumVerifier
{
    OFFLINE,
    BP_PREPARE_DYNAMIC,
    BP_PREPARE_DYNAMIC_END = BP_PREPARE_DYNAMIC + 10,
    AP_ONLINE_DYNAMIC,
    AP_ONLINE_DYNAMIC_END  = AP_ONLINE_DYNAMIC + 10,
    ONLINE,
    MAXIMUM
};



inline const char8* enumToString(CpuHotplugState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[24];



    if (
        (u64)state > (u64)CpuHotplugState::BP_PREPARE_DYNAMIC
        &&
        (u64)state < (u64)CpuHotplugState::BP_PREPARE_DYNAMIC_END
       )
    {
        sprintf(res, "BP_PREPARE_DYNAMIC + %u", (u64)state - (u64)CpuHotplugState::BP_PREPARE_DYNAMIC);

        return res;
    }



    if (
        (u64)state > (u64)CpuHotplugState::AP_ONLINE_DYNAMIC
        &&
        (u64)state < (u64)CpuHotplugState::AP_ONLINE_DYNAMIC_END
       )
    {
        sprintf(res, "AP_ONLINE_DYNAMIC + %u", (u64)state - (u64)CpuHotplugState::AP_ONLINE_DYNAMIC);

        return res;
    }



    switch (state)
    {
        case CpuHotplugState::OFFLINE:                return "OFFLINE";
        case CpuHotplugState::BP_PREPARE_DYNAMIC:     return "BP_PREPARE_DYNAMIC";
        case CpuHotplugState::BP_PREPARE_DYNAMIC_END: return "BP_PREPARE_DYNAMIC_END";
        case CpuHotplugState::AP_ONLINE_DYNAMIC:      return "AP_ONLINE_DYNAMIC";
        case CpuHotplugState::AP_ONLINE_DYNAMIC_END:  return "AP_ONLINE_DYNAMIC_END";
        case CpuHotplugState::ONLINE:                 return "ONLINE";
        case CpuHotplugState::MAXIMUM:                return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(CpuHotplugState type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[31];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTATE_H
