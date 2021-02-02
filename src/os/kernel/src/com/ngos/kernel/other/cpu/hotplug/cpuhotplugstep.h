#ifndef COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTEP_H
#define COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTEP_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



typedef NgosStatus (*cpu_up_down_action) (bad_uint64 cpu);



struct CpuHotplugStep
{
    const char8        *name;
    cpu_up_down_action  upAction;
    cpu_up_down_action  downAction;
    bool                multipleInstances;
};



#endif // COM_NGOS_KERNEL_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTEP_H
