#ifndef COM_NGOS_KERNEL_OTHER_TASK_TASKSTATE_H
#define COM_NGOS_KERNEL_OTHER_TASK_TASKSTATE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class TaskState: u8
{
    NONE       = 0,
    UNRUNNABLE = 1,
    RUNNABLE   = 2,
    STOPPED    = 3
};



inline const char8* enumToString(TaskState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case TaskState::NONE:       return "NONE";
        case TaskState::UNRUNNABLE: return "UNRUNNABLE";
        case TaskState::RUNNABLE:   return "RUNNABLE";
        case TaskState::STOPPED:    return "STOPPED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(TaskState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", state, enumToString(state));

    return res;
}



#endif // COM_NGOS_KERNEL_OTHER_TASK_TASKSTATE_H
