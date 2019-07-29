#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTEP_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTEP_H



#include <ngos/status.h>
#include <ngos/types.h>



typedef NgosStatus (*cpu_up_down_action) (u64 cpu);



struct CpuHotplugStep
{
    const char8        *name;
    cpu_up_down_action  upAction;
    cpu_up_down_action  downAction;
    bool                multipleInstances;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_CPU_HOTPLUG_CPUHOTPLUGSTEP_H
