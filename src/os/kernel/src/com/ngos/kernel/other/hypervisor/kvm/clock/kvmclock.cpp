#include "kvmclock.h"

#include <com/ngos/kernel/other/cpu/hotplug/cpuhotplug.h>
#include <com/ngos/kernel/other/hypervisor/kvm/kvm.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



MsrRegister KvmClock::sWallClockMsr;
MsrRegister KvmClock::sSystemTimeMsr;



NgosStatus KvmClock::init()
{
    COMMON_LT((""));



    if (KVM::hasFeature(KvmFeature::CLOCKSOURCE2))
    {
        sWallClockMsr  = MsrRegister::KVM_CLOCKSOURCE2_WALL_CLOCK;
        sSystemTimeMsr = MsrRegister::KVM_CLOCKSOURCE2_SYSTEM_TIME;
    }
    else
    if (KVM::hasFeature(KvmFeature::CLOCKSOURCE))
    {
        sWallClockMsr  = MsrRegister::KVM_CLOCKSOURCE_WALL_CLOCK;
        sSystemTimeMsr = MsrRegister::KVM_CLOCKSOURCE_SYSTEM_TIME;
    }
    else
    {
        COMMON_LE(("Failed to init KVM clock"));

        return NgosStatus::FAILED;
    }



    COMMON_ASSERT_EXECUTION(CpuHotplug::setupState(CpuHotplugState::BP_PREPARE_DYNAMIC, "KvmClock::init", nullptr, nullptr, false), NgosStatus::ASSERTION);



    // Validation
    {
        // -----------------------------------------------------------------------------------------------
        // Check CpuHotplug
        // -----------------------------------------------------------------------------------------------



#if NGOS_BUILD_TEST_MODE == OPTION_YES
        {
            COMMON_LVVV(("CpuHotplug::sSteps:"));
            COMMON_LVVV(("-------------------------------------"));

            for (good_I64 i = 0; i < (i64)CpuHotplugState::MAXIMUM; ++i)
            {
                if (CpuHotplug::sSteps[i].name)
                {
                    COMMON_LVVV(("%-23s: %10s | 0x%p | 0x%p | %s", enumToFullString((CpuHotplugState)i), CpuHotplug::sSteps[i].name, CpuHotplug::sSteps[i].upAction, CpuHotplug::sSteps[i].downAction, CpuHotplug::sSteps[i].multipleInstances ? "multiple" : "single"));
                }
            }

            COMMON_LVVV(("-------------------------------------"));
        }
#endif



        COMMON_TEST_ASSERT(CpuHotplug::sSteps[(u64)CpuHotplugState::BP_PREPARE_DYNAMIC].name              != nullptr,     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(CpuHotplug::sSteps[(u64)CpuHotplugState::BP_PREPARE_DYNAMIC].upAction          == nullptr,     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(CpuHotplug::sSteps[(u64)CpuHotplugState::BP_PREPARE_DYNAMIC].downAction        == nullptr,     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(CpuHotplug::sSteps[(u64)CpuHotplugState::BP_PREPARE_DYNAMIC].multipleInstances == false, NgosStatus::ASSERTION);



        // Validation
        {
            COMMON_LVVV(("sWallClockMsr  = %s", enumToFullString(sWallClockMsr)));
            COMMON_LVVV(("sSystemTimeMsr = %s", enumToFullString(sSystemTimeMsr)));

            COMMON_TEST_ASSERT(sWallClockMsr  == MsrRegister::KVM_CLOCKSOURCE2_WALL_CLOCK,  NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(sSystemTimeMsr == MsrRegister::KVM_CLOCKSOURCE2_SYSTEM_TIME, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}
