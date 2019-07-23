#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTATE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTATE_H



#include <ngos/types.h>



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



inline const char* cpuHotplugStateToString(CpuHotplugState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



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



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTATE_H
