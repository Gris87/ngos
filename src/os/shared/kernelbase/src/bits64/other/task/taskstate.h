#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_TASKSTATE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_TASKSTATE_H



#include <ngos/types.h>



enum class TaskState: u8
{
    UNRUNNABLE,
    RUNNABLE,
    STOPPED
};



inline const char* taskStateToString(TaskState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case TaskState::UNRUNNABLE: return "UNRUNNABLE";
        case TaskState::RUNNABLE:   return "RUNNABLE";
        case TaskState::STOPPED:    return "STOPPED";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_TASKSTATE_H
