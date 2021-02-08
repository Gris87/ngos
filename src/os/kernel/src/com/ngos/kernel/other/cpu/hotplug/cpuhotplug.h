#ifndef COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUG_H
#define COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUG_H



#include <com/ngos/kernel/other/cpu/hotplug/cpuhotplugstate.h>
#include <com/ngos/kernel/other/cpu/hotplug/cpuhotplugstep.h>
#include <com/ngos/shared/common/ngos/status.h>



class CpuHotplug
{
public:
    static NgosStatus setupState(CpuHotplugState state, const char8 *name, cpu_up_down_action upAction, cpu_up_down_action downAction, bool multipleInstances); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus storeCallbacks(CpuHotplugState state, const char8 *name, cpu_up_down_action upAction, cpu_up_down_action downAction, bool multipleInstances); // TEST: NO
    static NgosStatus allocateDynamicState(CpuHotplugState state, CpuHotplugState *res); // TEST: NO

    static CpuHotplugStep sSteps[(u64)CpuHotplugState::MAXIMUM];
};



#endif // COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUG_H
