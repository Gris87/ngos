#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASKSTATE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASKSTATE_H



#include <ngos/types.h>



enum class TaskState: i32
{
    UNRUNNABLE = -1,
    RUNNABLE   = 0,
    STOPPED    = 1
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASKSTATE_H
