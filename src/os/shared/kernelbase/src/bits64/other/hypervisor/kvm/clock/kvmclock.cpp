#include "kvmclock.h"

#include <common/src/bits64/cpu/msr/msrregisters.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <kernelbase/src/bits64/other/cpu/hotplug/cpuhotplug.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/kvm.h>



u32 KvmClock::sWallClockMsr;
u32 KvmClock::sSystemTimeMsr;



NgosStatus KvmClock::init()
{
    COMMON_LT((""));



    if (KVM::hasFeature(KvmFeature::CLOCKSOURCE2))
    {
        sWallClockMsr  = MSR_KVM_CLOCKSOURCE2_WALL_CLOCK;
        sSystemTimeMsr = MSR_KVM_CLOCKSOURCE2_SYSTEM_TIME;
    }
    else
    if (KVM::hasFeature(KvmFeature::CLOCKSOURCE))
    {
        sWallClockMsr  = MSR_KVM_CLOCKSOURCE_WALL_CLOCK;
        sSystemTimeMsr = MSR_KVM_CLOCKSOURCE_SYSTEM_TIME;
    }
    else
    {
        COMMON_LE(("Failed to init KVM clock"));

        return NgosStatus::FAILED;
    }



    COMMON_ASSERT_EXECUTION(CpuHotplug::setupState(CpuHotplugState::BP_PREPARE_DYNAMIC, "KvmClock::init", 0, 0, false), NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("sWallClockMsr  = 0x%08X", sWallClockMsr));
        COMMON_LVVV(("sSystemTimeMsr = 0x%08X", sSystemTimeMsr));



        COMMON_TEST_ASSERT(sWallClockMsr  == 0x4B564D00, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTimeMsr == 0x4B564D01, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
