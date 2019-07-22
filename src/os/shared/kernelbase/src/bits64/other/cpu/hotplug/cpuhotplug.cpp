#include "cpuhotplug.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



CpuHotplugStep CpuHotplug::sSteps[(u64)CpuHotplugState::MAXIMUM];



NgosStatus CpuHotplug::setupState(CpuHotplugState state, const char *name, cpu_up_down_action upAction, cpu_up_down_action downAction, bool multipleInstances)
{
    COMMON_LT((" | state = %u, name = 0x%p, upAction = 0x%p, downAction = 0x%p, multipleInstances = %u", state, name, upAction, downAction, multipleInstances));

    COMMON_ASSERT(name, "name is null", NgosStatus::ASSERTION);



    if (state == CpuHotplugState::BP_PREPARE_DYNAMIC || state == CpuHotplugState::AP_ONLINE_DYNAMIC)
    {
        COMMON_ASSERT_EXECUTION(allocateDynamicState(state, &state), NgosStatus::ASSERTION);
    }



    COMMON_ASSERT_EXECUTION(storeCallbacks(state, name, upAction, downAction, multipleInstances), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuHotplug::storeCallbacks(CpuHotplugState state, const char *name, cpu_up_down_action upAction, cpu_up_down_action downAction, bool multipleInstances)
{
    COMMON_LT((" | state = %u, name = 0x%p, upAction = 0x%p, downAction = 0x%p, multipleInstances = %u", state, name, upAction, downAction, multipleInstances));

    COMMON_ASSERT(name, "name is null", NgosStatus::ASSERTION);



    CpuHotplugStep &step = sSteps[(u64)state];

    step.name              = name;
    step.upAction          = upAction;
    step.downAction        = downAction;
    step.multipleInstances = multipleInstances;



    return NgosStatus::OK;
}

NgosStatus CpuHotplug::allocateDynamicState(CpuHotplugState state, CpuHotplugState *res)
{
    COMMON_LT((" | state = %u, res = 0x%p", state, res));

    COMMON_ASSERT(state == CpuHotplugState::BP_PREPARE_DYNAMIC || state == CpuHotplugState::AP_ONLINE_DYNAMIC, "state is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(res, "res is null", NgosStatus::ASSERTION);



    if (state == CpuHotplugState::BP_PREPARE_DYNAMIC)
    {
        for (i64 i = (i64)CpuHotplugState::BP_PREPARE_DYNAMIC; i <= (i64)CpuHotplugState::BP_PREPARE_DYNAMIC_END; ++i)
        {
            if (!sSteps[i].name) // sSteps[i].name == 0
            {
                *res = (CpuHotplugState)i;

                return NgosStatus::OK;
            }
        }
    }
    else
    if (state == CpuHotplugState::AP_ONLINE_DYNAMIC)
    {
        for (i64 i = (i64)CpuHotplugState::AP_ONLINE_DYNAMIC; i <= (i64)CpuHotplugState::AP_ONLINE_DYNAMIC_END; ++i)
        {
            if (!sSteps[i].name) // sSteps[i].name == 0
            {
                *res = (CpuHotplugState)i;

                return NgosStatus::OK;
            }
        }
    }
    else
    {
        return NgosStatus::INVALID_DATA;
    }



    return NgosStatus::FAILED;
}
